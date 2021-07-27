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

void FNoesisXamlProvider::OnXamlChanged(UNoesisXaml* Xaml)
{
#if WITH_EDITOR
	if (FString* Name = NameMap.Find(Xaml))
	{
		RaiseXamlChanged(TCHAR_TO_UTF8(**Name));
	}
#endif
}

Noesis::Ptr<Noesis::Stream> FNoesisXamlProvider::LoadXaml(const Noesis::Uri& Uri)
{
	Noesis::String Path;
	Uri.GetPath(Path);
	FString XamlPath = NsProviderPathToAssetPath(Path.Str());
	UNoesisXaml* Xaml = LoadObject<UNoesisXaml>(nullptr, *(FString("/Game/") + XamlPath), nullptr, LOAD_NoWarn);
	if (Xaml)
	{
		// Need to register the XAML's dependencies before returning.
		Xaml->RegisterDependencies();

#if WITH_EDITOR
		NameMap.Add(Xaml, Path.Str());
#endif

		return Noesis::Ptr<Noesis::Stream>(*new Noesis::MemoryStream(Xaml->XamlText.GetData(), (uint32)Xaml->XamlText.Num()));
	}

	return Noesis::Ptr<Noesis::Stream>();
};

void FNoesisTextureProvider::OnTextureChanged(UTexture2D* Texture)
{
#if WITH_EDITOR
	if (FString* Name = NameMap.Find(Texture))
	{
		RaiseTextureChanged(TCHAR_TO_UTF8(**Name));
	}
#endif
}

Noesis::TextureInfo FNoesisTextureProvider::GetTextureInfo(const Noesis::Uri& Uri)
{
	Noesis::String Path;
	Uri.GetPath(Path);
	FString TexturePath = NsProviderPathToAssetPath(Path.Str());
	UTexture2D* Texture = LoadObject<UTexture2D>(nullptr, *(FString("/Game/") + TexturePath), nullptr, LOAD_NoWarn);
	if (Texture)
	{
#if WITH_EDITOR
		NameMap.Add(Texture, Path.Str());
#endif
		return Noesis::TextureInfo { (uint32)Texture->GetSizeX(), (uint32)Texture->GetSizeY() };
	}

	return Noesis::TextureInfo {};
}

Noesis::Ptr<Noesis::Texture> FNoesisTextureProvider::LoadTexture(const Noesis::Uri& Uri, Noesis::RenderDevice* RenderDevice)
{
	Noesis::String Path;
	Uri.GetPath(Path);
	FString TexturePath = NsProviderPathToAssetPath(Path.Str());
	FString TextureObjectPath = TexturePath + TEXT(".") + FPackageName::GetShortName(TexturePath);
	UTexture2D* Texture = FindObject<UTexture2D>(nullptr, *(FString("/Game/") + TextureObjectPath));
	if (Texture)
	{
		return NoesisCreateTexture(Texture);
	}

	return nullptr;
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

Noesis::FontSource FNoesisFontProvider::MatchFont(const Noesis::Uri& BaseUri, const char* FamilyName, Noesis::FontWeight& Weight,
	Noesis::FontStretch& Stretch, Noesis::FontStyle& Style)
{
	Noesis::String Path;
	BaseUri.GetPath(Path);
	FString PackagePath = NsProviderPathToAssetPath(Path.Str());

	Noesis::Uri Uri(TCHAR_TO_UTF8(*PackagePath));
	return Noesis::CachedFontProvider::MatchFont(Uri, FamilyName, Weight, Stretch, Style);
}

bool FNoesisFontProvider::FamilyExists(const Noesis::Uri& BaseUri, const char* FamilyName)
{
	Noesis::String Path;
	BaseUri.GetPath(Path);
	FString PackagePath = NsProviderPathToAssetPath(Path.Str());

	Noesis::Uri Uri(TCHAR_TO_UTF8(*PackagePath));
	return Noesis::CachedFontProvider::FamilyExists(Uri, FamilyName);
}

void FNoesisFontProvider::ScanFolder(const Noesis::Uri& InFolder)
{
}

Noesis::Ptr<Noesis::Stream> FNoesisFontProvider::OpenFont(const Noesis::Uri& InFolder, const char* InFilename) const
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
