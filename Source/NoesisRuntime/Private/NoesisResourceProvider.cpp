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

UNoesisXaml* FNoesisXamlProvider::GetXaml(FString XamlProviderPath) const
{
	FString XamlPath = NsProviderPathToAssetPath(XamlProviderPath);
	return LoadObject<UNoesisXaml>(nullptr, *XamlPath);
}

Noesis::Ptr<Noesis::Stream> FNoesisXamlProvider::LoadXaml(const char* Path)
{
	UNoesisXaml* Xaml = GetXaml(Path);
	if (Xaml)
	{
		return Noesis::Ptr<Noesis::Stream>(*new Noesis::MemoryStream(Xaml->XamlText.GetData(), (uint32)Xaml->XamlText.Num()));
	}

	return Noesis::Ptr<Noesis::Stream>();
};

UTexture2D* FNoesisTextureProvider::GetTexture(FString TextureProviderPath) const
{
	FString TexturePath = NsProviderPathToAssetPath(TextureProviderPath);
	return LoadObject<UTexture2D>(nullptr, *TexturePath);
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

void FNoesisFontProvider::RegisterFont(class UFont* Font)
{
	FString FontPackagePath = FPackageName::GetLongPackagePath(Font->GetPathName());
	if (Font)
	{
		for (auto TypefaceEntry : Font->CompositeFont.DefaultTypeface.Fonts)
		{
			const FFontData* FontData = &TypefaceEntry.Font;
			const UFontFace* FontFace = Cast<UFontFace>(FontData->GetFontFaceAsset());
			FString FontFacePath = FontFace->GetPathName();
			Noesis::CachedFontProvider::RegisterFont(TCHARToNsString(*FontPackagePath).Str(), TCHARToNsString(*FontFacePath).Str());
		}
	}
}

Noesis::FontSource FNoesisFontProvider::MatchFont(const char* BaseUri, const char* FamilyName, Noesis::FontWeight& Weight,
	Noesis::FontStretch& Stretch, Noesis::FontStyle& Style)
{
	FString AssetPath = NsStringToFString(BaseUri);
	if (!FPackageName::IsValidLongPackageName(AssetPath / "_Font"))
	{
		Noesis::String AbsoluteBaseUri = Noesis::String("/Game/") + BaseUri;
		return Noesis::CachedFontProvider::MatchFont(AbsoluteBaseUri.Str(), FamilyName, Weight, Stretch, Style);
	}

	return Noesis::CachedFontProvider::MatchFont(BaseUri, FamilyName, Weight, Stretch, Style);
}

bool FNoesisFontProvider::FamilyExists(const char* BaseUri, const char* FamilyName)
{
	FString AssetPath = NsStringToFString(BaseUri);
	if (!FPackageName::IsValidLongPackageName(AssetPath / "_Font"))
	{
		Noesis::String AbsoluteBaseUri = Noesis::String("/Game/") + BaseUri;
		return Noesis::CachedFontProvider::FamilyExists(AbsoluteBaseUri.Str(), FamilyName);
	}

	return Noesis::CachedFontProvider::FamilyExists(BaseUri, FamilyName);
}

void FNoesisFontProvider::ScanFolder(const char* InFolder)
{
}

Noesis::Ptr<Noesis::Stream> FNoesisFontProvider::OpenFont(const char* InFolder, const char* InFilename) const
{
	const UFontFace* FontFace = LoadObject<UFontFace>(nullptr, *NsStringToFString(InFilename));
	if (FontFace)
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
		if (FontFace->GetLoadingPolicy() == EFontLoadingPolicy::Inline)
		{
			const FFontFaceDataRef FontFaceDataRef = FontFace->FontFaceData;
			const FFontFaceData& FontFaceData = FontFaceDataRef.Get();
			const TArray<uint8>& FontFaceDataArray = FontFaceData.GetData();
			return Noesis::Ptr<Noesis::Stream>(*new FontArrayMemoryStream(CopyTemp(FontFaceDataArray)));
		}
		else
		{
			TArray<uint8> FileData;
			FFileHelper::LoadFileToArray(FileData, *FontFace->GetFontFilename());
			return Noesis::Ptr<Noesis::Stream>(*new FontArrayMemoryStream(MoveTemp(FileData)));
		}
	}
	return Noesis::Ptr<Noesis::Stream>();
}
