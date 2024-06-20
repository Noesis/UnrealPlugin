////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisLangServerResourceProvider.h"

// Core includes
#include "CoreMinimal.h"
#include "HAL/PlatformFileManager.h"
#include "Misc/FileHelper.h"
#include "Misc/EngineVersionComparison.h"
#include "GenericPlatform/GenericPlatformFile.h"

// CoreUObject includes
#include "UObject/UObjectGlobals.h"
#include "UObject/Package.h"

// Engine includes
#include "Engine/Texture.h"
#include "Engine/Texture2D.h"
#include "Engine/Font.h"
#include "Engine/FontFace.h"

// Other includes
#include "ImageUtils.h"
#include "TextureResource.h"

// NoesisRuntime includes
#include "NoesisXaml.h"
#include "NoesisSupport.h"

// NoesisEditor includes
#include "NoesisEditorModule.h"

namespace
{
	struct TextureData
	{
		Noesis::FixedString<512> filename;
		Noesis::Ptr<Noesis::Texture> texture;

		TextureData(const char* _filename, Noesis::Texture* _texture)
		{
			filename = _filename;
			texture.Reset(_texture);
		}
	};

	Noesis::Vector<TextureData> gCachedTextures;
}

static void TexturePremultiplyAlpha(UTexture2D* Texture, const Noesis::Uri& Uri)
{
	//	update data
	Texture->UpdateResource();

	int32 Row = Texture->GetSizeY();
	int32 Column = Texture->GetSizeX();
	auto& Mips = Texture->GetPlatformData()->Mips;
	uint8_t* MipData = static_cast<uint8_t*>(Mips[0].BulkData.Lock(LOCK_READ_WRITE));

	EPixelFormat format = Texture->GetPixelFormat(0);

	switch (format)
	{
		case PF_B8G8R8A8:
		{
			for (int i = 0; i < Row * Column; i++)
			{
				uint32_t Alpha = MipData[i * 4 + 3];
				MipData[i * 4] = MipData[i * 4] * Alpha / 255;
				MipData[i * 4 + 1] = MipData[i * 4 + 1] * Alpha / 255;
				MipData[i * 4 + 2] = MipData[i * 4 + 2] * Alpha / 255;
			}
			break;
		}
		case PF_R8G8B8A8:
		{
			for (int i = 0; i < Row * Column; i++)
			{
				uint32_t Alpha = MipData[i * 4 + 3];
				MipData[i * 4] = MipData[i * 4 + 2] * Alpha / 255;
				MipData[i * 4 + 1] = MipData[i * 4 + 1] * Alpha / 255;
				MipData[i * 4 + 2] = MipData[i * 4] * Alpha / 255;
			}
			break;
		}
		default:
		{
			UE_LOG(LogNoesisEditor, Warning, TEXT("LangServer: Texture %hs format invalid"), Uri.Str());
			break;
		}
	}

	Mips[0].BulkData.Unlock();

	//	update data
	Texture->UpdateResource();
}

Noesis::Ptr<Noesis::Stream> FNoesisLangServerXamlProvider::LoadXaml(const Noesis::Uri& Uri)
{
	Noesis::FixedString<512> Path;
	Uri.GetPath(Path);
	if (FPaths::FileExists(Path.Str()))
	{
		return Noesis::OpenFileStream(Path.Str());
	}

	return nullptr;
}

Noesis::TextureInfo FNoesisLangServerTextureProvider::GetTextureInfo(const Noesis::Uri& Uri)
{
	Noesis::FixedString<512> Path;
	Uri.GetPath(Path);
	if (FPaths::FileExists(Path.Str()))
	{
		UTexture2D* Texture = FImageUtils::ImportFileAsTexture2D(Path.Str());
		if (Texture)
		{
			TexturePremultiplyAlpha(Texture, Uri);
			gCachedTextures.EmplaceBack(Path.Str(), NoesisCreateTexture(Texture));
			return Noesis::TextureInfo{ (uint32)Texture->GetSizeX(), (uint32)Texture->GetSizeY() };
		}
	}

	return Noesis::TextureInfo{};
}

Noesis::Ptr<Noesis::Texture> FNoesisLangServerTextureProvider::LoadTexture(const Noesis::Uri& Uri, Noesis::RenderDevice* RenderDevice)
{
	Noesis::FixedString<512> Path;
	Uri.GetPath(Path);

	for (auto textureData : gCachedTextures)
	{
		if (Path == textureData.filename)
		{
			return textureData.texture;
		}
	}
	return nullptr;
}

void FNoesisLangServerTextureProvider::ClearShrinkTextures()
{
	gCachedTextures.ClearShrink();
}

void FNoesisLangServerFontProvider::ScanFolder(const Noesis::Uri& Folder)
{
	Noesis::FixedString<512> Path;
	Folder.GetPath(Path);

	class ScanFolderForFonts : public IPlatformFile::FDirectoryVisitor
	{
	public:
		ScanFolderForFonts(const Noesis::Uri& InFolder, FNoesisLangServerFontProvider* InProvider)
			: Folder(InFolder), Provider(InProvider)
		{
		}

		~ScanFolderForFonts()
		{
		}

		virtual bool Visit(const TCHAR* FilenameOrDirectory, bool IsDirectory) override
		{
			if (!IsDirectory)
			{
				FString Extension = FPaths::GetExtension(FilenameOrDirectory).ToLower();
				FString Filename = FPaths::GetCleanFilename(FilenameOrDirectory);
				if (Extension == TEXT("ttf") || Extension == TEXT("otf") || Extension == TEXT("ttc"))
				{
					Provider->RegisterFont(Folder, TCHAR_TO_UTF8(*Filename));
				}
			}

			return true;
		}

	private:
		Noesis::Uri Folder;
		FNoesisLangServerFontProvider* Provider;
	};

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	ScanFolderForFonts Visitor(Folder, this);
	PlatformFile.IterateDirectory(UTF8_TO_TCHAR(Path.Str()), Visitor);
}

Noesis::Ptr<Noesis::Stream> FNoesisLangServerFontProvider::OpenFont(const  Noesis::Uri& folder, const char* filename) const
{
	char uri[512] = "";

	Noesis::FixedString<512> path;
	folder.GetPath(path);

	Noesis::StrAppend(uri, sizeof(uri), path.Str());
	Noesis::StrAppend(uri, sizeof(uri), "/");
	Noesis::StrAppend(uri, sizeof(uri), filename);

	return  Noesis::OpenFileStream(uri);
}
