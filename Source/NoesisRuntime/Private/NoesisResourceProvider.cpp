////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisResourceProvider.h"

// Core includes
#include "Misc/FileHelper.h"

// Engine includes
#include "Engine/Texture.h"
#include "Engine/Texture2D.h"
#include "Engine/Font.h"
#include "Engine/FontFace.h"

// NoesisRuntime includes
#include "NoesisXaml.h"
#include "NoesisSupport.h"

Noesis::Ptr<Noesis::Stream> FNoesisXamlProvider::LoadXaml(const char* Path)
{
	FString XamlPath = NsProviderPathToAssetPath(Path);
	UNoesisXaml* Xaml = LoadObject<UNoesisXaml>(nullptr, *(FString("/Game/") + XamlPath), nullptr, LOAD_NoWarn);
	if (Xaml)
	{
		// Need to register the XAML's dependencies before returning.
		Xaml->RegisterDependencies();

		return Noesis::Ptr<Noesis::Stream>(*new Noesis::MemoryStream(Xaml->XamlText.GetData(), (uint32)Xaml->XamlText.Num()));
	}

	return Noesis::Ptr<Noesis::Stream>();
};

UTexture2D* FNoesisTextureProvider::GetTexture(FString TextureProviderPath) const
{
	FString TexturePath = NsProviderPathToAssetPath(TextureProviderPath);
	UTexture2D* Texture = LoadObject<UTexture2D>(nullptr, *(FString("/Game/") + TexturePath), nullptr, LOAD_NoWarn);
	return Texture;
}

Noesis::TextureInfo FNoesisTextureProvider::GetTextureInfo(const char* Path)
{
	UTexture* Texture = GetTexture(Path);
	if (Texture)
	{
		UTexture2D* Texture2D = CastChecked<UTexture2D>(Texture);
		return Noesis::TextureInfo{ (uint32)Texture2D->GetSizeX(), (uint32)Texture2D->GetSizeY() };
	}

	return Noesis::TextureInfo{};
}

Noesis::Ptr<Noesis::Texture> FNoesisTextureProvider::LoadTexture(const char* Path, Noesis::RenderDevice* RenderDevice)
{
	return NoesisCreateTexture(GetTexture(Path));
};

void FNoesisFontProvider::RegisterFont(const UFontFace* FontFace)
{
	if (FontFace != nullptr)
	{
		FString FontFacePath = FontFace->GetPathName();
		FString FontPackagePath = FPackageName::GetLongPackagePath(FontFacePath);
		UObject* Package = FontFace->GetOutermost();
		FString PackageRoot;
		FString PackagePath;
		FString PackageName;
		FPackageName::SplitLongPackageName(Package->GetPathName(), PackageRoot, PackagePath, PackageName, false);
		Noesis::CachedFontProvider::RegisterFont(TCHARToNsString(*PackagePath).Str(), TCHARToNsString(*(PackagePath + PackageName + TEXT(".") + FontFace->GetName())).Str());
	}
}

Noesis::FontSource FNoesisFontProvider::MatchFont(const char* BaseUri, const char* FamilyName, Noesis::FontWeight& Weight,
	Noesis::FontStretch& Stretch, Noesis::FontStyle& Style)
{
	FString PackagePath = NsProviderPathToAssetPath(BaseUri);

	return Noesis::CachedFontProvider::MatchFont(TCHAR_TO_UTF8(*PackagePath), FamilyName, Weight, Stretch, Style);
}

bool FNoesisFontProvider::FamilyExists(const char* BaseUri, const char* FamilyName)
{
	FString PackagePath = NsProviderPathToAssetPath(BaseUri);

	return Noesis::CachedFontProvider::FamilyExists(TCHAR_TO_UTF8(*PackagePath), FamilyName);
}

void FNoesisFontProvider::ScanFolder(const char* InFolder)
{
}

Noesis::Ptr<Noesis::Stream> FNoesisFontProvider::OpenFont(const char* InFolder, const char* InFilename) const
{
	FString Filename = NsStringToFString(InFilename);
	const UFontFace* FontFace = LoadObject<UFontFace>(nullptr, *(FString("/Game/") + Filename), nullptr, LOAD_NoWarn);
	if (FontFace != nullptr)
	{
		class FontArrayMemoryStream : public Noesis::MemoryStream
		{
		public:
			FontArrayMemoryStream(TArray<uint8>&& InFileData)
				: Noesis::MemoryStream(InFileData.GetData(), (uint32)InFileData.Num()),
				FileData(MoveTemp(InFileData))
			{
			}

		private:
			TArray<uint8> FileData;
		};
#if !WITH_EDITORONLY_DATA
		if (FontFace->GetLoadingPolicy() != EFontLoadingPolicy::Inline)
		{
			TArray<uint8> FileData;
			FFileHelper::LoadFileToArray(FileData, *FontFace->GetFontFilename());
			return Noesis::Ptr<Noesis::Stream>(*new FontArrayMemoryStream(MoveTemp(FileData)));
		}
		else
#endif
		{
			const FFontFaceDataRef FontFaceDataRef = FontFace->FontFaceData;
			const FFontFaceData& FontFaceData = FontFaceDataRef.Get();
			const TArray<uint8>& FontFaceDataArray = FontFaceData.GetData();
			return Noesis::Ptr<Noesis::Stream>(*new FontArrayMemoryStream(CopyTemp(FontFaceDataArray)));
		}
	}
	return Noesis::Ptr<Noesis::Stream>();
}
