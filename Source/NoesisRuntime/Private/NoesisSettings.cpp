////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisSettings.h"

// FreeType2 includes
THIRD_PARTY_INCLUDES_START
#include "ft2build.h"
#include FT_FREETYPE_H
THIRD_PARTY_INCLUDES_END

// Noesis includes
#include "NoesisSDK.h"

UNoesisSettings::UNoesisSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	OffscreenTextureSampleCount = ENoesisOffscreenSampleCount::One;
	GlyphTextureSize = ENoesisGlyphCacheDimensions::x1024;
	ApplicationResources = FSoftObjectPath("/Game/Theme/NoesisTheme_DarkBlue.NoesisTheme_DarkBlue");
	DefaultFonts.Add(FSoftObjectPath("/Game/Theme/Fonts/PT_Root_UI_Regular.PT_Root_UI_Regular"));
	DefaultFonts.Add(FSoftObjectPath("/Game/Theme/Fonts/PT_Root_UI_Bold.PT_Root_UI_Bold"));
	DefaultFontSize = 15.f;
	DefaultFontWeight = ENoesisFontWeight::Normal;
	DefaultFontStretch = ENoesisFontStretch::Normal;
	DefaultFontStyle = ENoesisFontStyle::Normal;
	RestoreUITexturePNGPremultipliedAlpha = true;
	PremultiplyAlpha = true;
}

void UNoesisSettings::SetLicense() const
{
	Noesis::GUI::SetLicense(TCHAR_TO_UTF8(*LicenseName), TCHAR_TO_UTF8(*LicenseKey));
}

static uint32 ApplicationResourcesHash;
void UNoesisSettings::SetApplicationResources() const
{
	UNoesisXaml* Resources = LoadObject<UNoesisXaml>(nullptr, *ApplicationResources.GetAssetPathString(), nullptr, LOAD_NoWarn);
	if (Resources)
	{
		uint32 Hash = Resources->GetContentHash();
		if (ApplicationResourcesHash != Hash)
		{
			ApplicationResourcesHash = Hash;
			Noesis::Ptr<Noesis::ResourceDictionary> Dictionary = Noesis::MakePtr<Noesis::ResourceDictionary>();
			Noesis::GUI::SetApplicationResources(Dictionary);
			Resources->LoadComponent(Dictionary);
		}
	}
	else
	{
		if (ApplicationResourcesHash != 0)
		{
			ApplicationResourcesHash = 0;
			Noesis::GUI::SetApplicationResources(nullptr);
		}
	}
}

static unsigned long StreamRead(FT_Stream Stream, unsigned long Offset, unsigned char* Buffer, unsigned long Count)
{
	FMemory::Memcpy(Buffer, (uint8*)Stream->descriptor.pointer + Offset, Count);
	return Count;
}

static void StreamClose(FT_Stream) {}

static TArray<FString> GetFamilyNames(FT_Library Library, const TArray<uint8>& FontData)
{
	TArray<FString> FamilyNames;

	FT_StreamRec Stream;
	FMemory::Memset(&Stream, 0, sizeof(Stream));
	Stream.descriptor.pointer = (void*)FontData.GetData();
	Stream.size = FontData.Num();
	Stream.read = &StreamRead;
	Stream.close = &StreamClose;

	FT_Open_Args Args;
	FMemory::Memset(&Args, 0, sizeof(Args));
	Args.flags = FT_OPEN_STREAM;
	Args.stream = &Stream;

	FT_Face Face;
	FT_Error Error = FT_Open_Face(Library, &Args, -1, &Face);
	if (Error == 0)
	{
		for (FT_Long FaceIndex = 0; FaceIndex < Face->num_faces; FaceIndex++)
		{
			FT_Face SubFace;
			Error = FT_Open_Face(Library, &Args, FaceIndex, &SubFace);
			if (Error == 0)
			{
				FamilyNames.AddUnique(SubFace->family_name);
				FT_Done_Face(SubFace);
			}
		}
		FT_Done_Face(Face);
	}

	return FamilyNames;
}

void UNoesisSettings::SetFontFallbacks() const
{
	INoesisRuntimeModuleInterface& NoesisRuntime = INoesisRuntimeModuleInterface::Get();
	FT_Library Library;
	FT_Error Error = FT_Init_FreeType(&Library);
	if (Error == 0)
	{
		TArray<Noesis::String> FamilyNamesStr;
		for (auto& FontFallback : DefaultFonts)
		{
			UFontFace* FontFace = Cast<UFontFace>(FontFallback.TryLoad());
			if (FontFace)
			{
				NoesisRuntime.RegisterFont(FontFace);

#if !WITH_EDITORONLY_DATA
				if (FontFace->GetLoadingPolicy() != EFontLoadingPolicy::Inline)
				{
					TArray<uint8> FileData;
					FFileHelper::LoadFileToArray(FileData, *FontFace->GetFontFilename());

					TArray<FString> Names = GetFamilyNames(Library, FileData);
					for (auto& Name : Names)
					{
						FString FontPackagePath = FPackageName::GetLongPackagePath(FontFace->GetPathName());
						UPackage* Package = FontFace->GetOutermost();
						FString PackageRoot;
						FString PackagePath;
						FString PackageName;
						FPackageName::SplitLongPackageName(Package->GetPathName(), PackageRoot, PackagePath, PackageName, false);
						FamilyNamesStr.AddUnique(TCHARToNsString(*(PackagePath / "#" + Name)));
					}
				}
				else
#endif
				{
					const FFontFaceDataRef FontFaceDataRef = FontFace->FontFaceData;
					const FFontFaceData& FontFaceData = FontFaceDataRef.Get();
					const TArray<uint8>& FontFaceDataArray = FontFaceData.GetData();

					TArray<FString> Names = GetFamilyNames(Library, FontFaceDataArray);
					for (auto& Name : Names)
					{
						FString FontPackagePath = FPackageName::GetLongPackagePath(FontFace->GetPathName());
						UPackage* Package = FontFace->GetOutermost();
						FString PackageRoot;
						FString PackagePath;
						FString PackageName;
						FPackageName::SplitLongPackageName(Package->GetPathName(), PackageRoot, PackagePath, PackageName, false);
						FamilyNamesStr.AddUnique(TCHARToNsString(*(PackagePath / "#" + Name)));
					}
				}
			}
		}
		TArray<const ANSICHAR*> FamilyNames;
		for (auto& Name : FamilyNamesStr)
		{
			FamilyNames.Add(Name.Str());
		}
		Noesis::GUI::SetFontFallbacks(FamilyNames.GetData(), FamilyNames.Num());
		FT_Done_FreeType(Library);
	}
}

void UNoesisSettings::SetFontDefaultProperties() const
{
	float Size = DefaultFontSize;
	ENoesisFontWeight Weight = DefaultFontWeight;
	ENoesisFontStretch Stretch = DefaultFontStretch;
	ENoesisFontStyle Style = DefaultFontStyle;
	Noesis::GUI::SetFontDefaultProperties(Size, (Noesis::FontWeight)Weight, (Noesis::FontStretch)Stretch, (Noesis::FontStyle)Style);
}

#if WITH_EDITOR
void UNoesisSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property != NULL)
	{
		FName MemberPropName = PropertyChangedEvent.MemberProperty->GetFName();
		if (MemberPropName == GET_MEMBER_NAME_CHECKED(UNoesisSettings, LicenseName)
			|| MemberPropName == GET_MEMBER_NAME_CHECKED(UNoesisSettings, LicenseKey))
		{
			SetLicense();
		}
		else if (MemberPropName == GET_MEMBER_NAME_CHECKED(UNoesisSettings, ApplicationResources))
		{
			SetApplicationResources();
		}
		else if (MemberPropName == GET_MEMBER_NAME_CHECKED(UNoesisSettings, DefaultFonts))
		{
			SetFontFallbacks();
		}
		else if (MemberPropName == GET_MEMBER_NAME_CHECKED(UNoesisSettings, DefaultFontSize)
			|| MemberPropName == GET_MEMBER_NAME_CHECKED(UNoesisSettings, DefaultFontWeight)
			|| MemberPropName == GET_MEMBER_NAME_CHECKED(UNoesisSettings, DefaultFontStretch)
			|| MemberPropName == GET_MEMBER_NAME_CHECKED(UNoesisSettings, DefaultFontStyle))
		{
			SetFontDefaultProperties();
		}
	}
}
#endif
