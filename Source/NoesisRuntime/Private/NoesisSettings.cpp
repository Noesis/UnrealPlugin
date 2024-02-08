////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisSettings.h"

// Core includes
#include "Misc/FileHelper.h"
#include "Misc/App.h"

// CoreUObject includes
#include "Misc/PackageName.h"
#include "UObject/Package.h"

// Engine includes
#include "Engine/FontFace.h"

// Noesis includes
#include "NoesisSDK.h"

// NoesisRuntime includes
#include "NoesisRuntimeModule.h"
#include "NoesisXaml.h"

UNoesisSettings::UNoesisSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	OffscreenTextureSampleCount = ENoesisOffscreenSampleCount::One;
	GlyphTextureSize = ENoesisGlyphCacheDimensions::x1024;
	ApplicationResources = FSoftObjectPath("/NoesisGUI/Theme/NoesisTheme_DarkBlue.NoesisTheme_DarkBlue");
	DefaultFonts.Add(FSoftObjectPath("/NoesisGUI/Theme/Fonts/PT_Root_UI_Regular.PT_Root_UI_Regular"));
	DefaultFonts.Add(FSoftObjectPath("/NoesisGUI/Theme/Fonts/PT_Root_UI_Bold.PT_Root_UI_Bold"));
	LoadPlatformFonts = true;
	DefaultFontSize = 15.f;
	DefaultFontWeight = ENoesisFontWeight::Normal;
	DefaultFontStretch = ENoesisFontStretch::Normal;
	DefaultFontStyle = ENoesisFontStyle::Normal;
	GeneralLogLevel = ENoesisLoggingSettings::Warning;
	BindingLogLevel = ENoesisLoggingSettings::Warning;
	ReloadEnabled = true;
	PremultiplyAlpha = true;
}

void UNoesisSettings::SetLicense() const
{
	Noesis::GUI::SetLicense(TCHAR_TO_UTF8(*LicenseName), TCHAR_TO_UTF8(*LicenseKey));
}

static uint32 ApplicationResourcesHash;
static UNoesisXaml* ApplicationResourcesRef;
void UNoesisSettings::SetApplicationResources() const
{
	// To prevent ApplicationResources and all its dependencies from being deleted
	// during garbage collection we have to manually add it to the root object
	if (ApplicationResourcesRef != nullptr)
	{
		ApplicationResourcesRef->RemoveFromRoot();
	}
	ApplicationResourcesRef = LoadObject<UNoesisXaml>(nullptr, *ApplicationResources.GetAssetPathString(), nullptr, LOAD_NoWarn);

	// Avoid loading XAMLs if the application cannot render
	if (!FApp::CanEverRender())
		return;

	if (ApplicationResourcesRef)
	{
		ApplicationResourcesRef->AddToRoot();
		uint32 Hash = ApplicationResourcesRef->GetContentHash();
		if (ApplicationResourcesHash != Hash)
		{
			ApplicationResourcesHash = Hash;
			Noesis::Ptr<Noesis::ResourceDictionary> Dictionary = Noesis::MakePtr<Noesis::ResourceDictionary>();
			Noesis::GUI::SetApplicationResources(Dictionary);
			ApplicationResourcesRef->LoadComponent(Dictionary);
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

static void GetFamilyNames(const TArray<uint8>& FontData, TArray<Noesis::FixedString<128>>& FamilyNames,
	const Noesis::String& Path)
{
	Noesis::MemoryStream Stream(FontData.GetData(), FontData.Num());
	Noesis::Fonts::GetTypefaces(&Stream, [&FamilyNames, &Path](const Noesis::Typeface& Typeface)
	{
		Noesis::FixedString<512> PathFamilyName(Path.Str());
		PathFamilyName.Append(Typeface.familyName);
		FamilyNames.AddUnique(PathFamilyName.Str());
	});
}

static TArray<UFontFace*> DefaultFontRefs;
void UNoesisSettings::SetFontFallbacks() const
{
	INoesisRuntimeModuleInterface& NoesisRuntime = INoesisRuntimeModuleInterface::Get();

	for (UFontFace* FontFace : DefaultFontRefs)
	{
		FontFace->RemoveFromRoot();
	}

	DefaultFontRefs.Empty(DefaultFonts.Num());

	FString PackageRoot, PackagePath, PackageName;
	Noesis::String PathStr;

	TArray<Noesis::FixedString<128>> FamilyNamesStr;
	for (auto& FontFallback : DefaultFonts)
	{
		UFontFace* FontFace = Cast<UFontFace>(FontFallback.TryLoad());
		if (FontFace)
		{
			FontFace->AddToRoot();
			DefaultFontRefs.Add(FontFace);
			NoesisRuntime.RegisterFont(FontFace);

			UPackage* Package = FontFace->GetOutermost();
			FPackageName::SplitLongPackageName(Package->GetPathName(), PackageRoot, PackagePath, PackageName, false);
			PathStr = TCHAR_TO_UTF8(*(PackageRoot.LeftChop(1) + ";component" / PackagePath / "#"));

#if !WITH_EDITORONLY_DATA
			if (FontFace->GetLoadingPolicy() != EFontLoadingPolicy::Inline)
			{
				TArray<uint8> FileData;
				FFileHelper::LoadFileToArray(FileData, *FontFace->GetFontFilename());

				GetFamilyNames(FileData, FamilyNamesStr, PathStr);
			}
			else
#endif
			{
				const FFontFaceDataRef FontFaceDataRef = FontFace->FontFaceData;
				const FFontFaceData& FontFaceData = FontFaceDataRef.Get();
				const TArray<uint8>& FontFaceDataArray = FontFaceData.GetData();

				GetFamilyNames(FontFaceDataArray, FamilyNamesStr, PathStr);
			}
		}
	}

	// Add user font fallbacks
	TArray<const ANSICHAR*> FamilyNames;
	for (auto& Name : FamilyNamesStr)
	{
		FamilyNames.Add(Name.Str());
	}

	// Add platform specific font fallbacks
	if (LoadPlatformFonts)
	{
#if PLATFORM_WINDOWS
		FamilyNames.Add("Arial");
		FamilyNames.Add("Segoe UI Emoji");			// Windows 10 Emojis
		FamilyNames.Add("Arial Unicode MS");		// Almost everything (but part of MS Office, not Windows)
		FamilyNames.Add("Microsoft Sans Serif");	// Unicode scripts excluding Asian scripts
		FamilyNames.Add("Microsoft YaHei");			// Chinese
		FamilyNames.Add("Gulim");					// Korean
		FamilyNames.Add("MS Gothic");				// Japanese
#elif PLATFORM_MAC
		FamilyNames.Add("Arial");
		FamilyNames.Add("Arial Unicode MS");		// MacOS 10.5+
#elif PLATFORM_IOS
		FamilyNames.Add("PingFang SC");				// Simplified Chinese (iOS 9+)
		FamilyNames.Add("Apple SD Gothic Neo");		// Korean (iOS 7+)
		FamilyNames.Add("Hiragino Sans");			// Japanese (iOS 9+)
#elif PLATFORM_ANDROID
		FamilyNames.Add("Noto Sans CJK SC");		// Simplified Chinese
		FamilyNames.Add("Noto Sans CJK KR");		// Korean
		FamilyNames.Add("Noto Sans CJK JP");		// Japanese
#elif PLATFORM_LINUX
		FamilyNames.Add("Noto Sans CJK SC");		// Simplified Chinese
		FamilyNames.Add("Noto Sans CJK KR");		// Korean
		FamilyNames.Add("Noto Sans CJK JP");		// Japanese
#endif
	}

	Noesis::GUI::SetFontFallbacks(FamilyNames.GetData(), FamilyNames.Num());
}

void UNoesisSettings::SetFontDefaultProperties() const
{
	float Size = DefaultFontSize;
	Noesis::FontWeight Weight = (Noesis::FontWeight)((int)DefaultFontWeight * 10);
	Noesis::FontStretch Stretch = (Noesis::FontStretch)DefaultFontStretch;
	Noesis::FontStyle Style = (Noesis::FontStyle)DefaultFontStyle;
	Noesis::GUI::SetFontDefaultProperties(Size, Weight, Stretch, Style);
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
