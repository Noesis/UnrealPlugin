////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisStudioResourceProvider.h"

// Core includes
#include "CoreMinimal.h"
#include "HAL/PlatformFileManager.h"
#include "GenericPlatform/GenericPlatformFile.h"

// CoreUObject includes
#include "UObject/UObjectGlobals.h"

// Engine includes
#include "Engine/Texture.h"
#include "Engine/Texture2D.h"
#include "Engine/FontFace.h"

// Other includes
#include "ImageUtils.h"
#include "TextureResource.h"
#include "TextureCompiler.h"

// NoesisRuntime includes
#include "NoesisXaml.h"
#include "NoesisSupport.h"

namespace
{
	FNoesisStudioTextureProvider* gTextureProvider = nullptr;
}

static Noesis::Ptr<Noesis::Stream> LoadFont(const UFontFace* FontFace)
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
		return *new FontArrayMemoryStream(MoveTemp(FileData));
	}
	else
#endif
	{
		const FFontFaceDataRef FontFaceDataRef = FontFace->FontFaceData;
		const FFontFaceData& FontFaceData = FontFaceDataRef.Get();
		const TArray<uint8>& FontFaceDataArray = FontFaceData.GetData();
		return *new FontArrayMemoryStream(CopyTemp(FontFaceDataArray));
	}
}

static void StudioTexturePremultiplyAlpha(UTexture2D* Texture, const Noesis::Uri& Uri)
{
#ifdef _WIN32
// UpdateResource is defined by winbase.h
#undef UpdateResource
#endif

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
			break;
		}
	}

	Mips[0].BulkData.Unlock();

	//	update data
	Texture->UpdateResource();
}

struct NoesisTextureData
{
	Noesis::FixedString<512> Filename;
	UTexture2D* UnrealTexture;
	Noesis::Ptr<Noesis::Texture> Texture;

	NoesisTextureData(const Noesis::Uri& _uri, const char* _filename, UTexture2D* _unrealTexture)
	{
		Filename = _filename;
		UnrealTexture = _unrealTexture;

		UnrealTexture->AddToRoot();
		StudioTexturePremultiplyAlpha(UnrealTexture, _uri);
		Texture.Reset(NoesisCreateTexture(UnrealTexture));
	}

	void Release()
	{
		UnrealTexture->RemoveFromRoot();
	}
};

FNoesisStudioXamlProvider::FNoesisStudioXamlProvider(const char* rootPath): mRootPath(rootPath)
{
}

Noesis::Ptr<Noesis::Stream> FNoesisStudioXamlProvider::LoadXaml(const Noesis::Uri& Uri)
{
	Noesis::FixedString<512> Path;
	Uri.GetPath(Path);

	if (!mRootPath.Empty())
	{
		Path.Insert(0, "/");
		Path.Insert(0, mRootPath.Str());
	}

	if (FPaths::FileExists(Path.Str()))
	{
		return Noesis::OpenFileStream(Path.Str());
	}

	return nullptr;
}

FNoesisStudioTextureProvider::FNoesisStudioTextureProvider(const char* rootPath) : mRootPath(rootPath)
{
	gTextureProvider = this;
}

FNoesisStudioTextureProvider::~FNoesisStudioTextureProvider()
{
	if (gTextureProvider == this)
	{
		gTextureProvider = nullptr;
	}
}

void FNoesisStudioTextureProvider::TextureChanged(class UTexture2D* Texture)
{
	if (gTextureProvider != nullptr)
	{
		gTextureProvider->OnTextureChanged(Texture);
	}
}

void FNoesisStudioTextureProvider::OnTextureChanged(UTexture2D* Texture)
{
	if (FString* Name = NameMap.Find(Texture))
	{
		RaiseTextureChanged(TCHAR_TO_UTF8(**Name));
	}
}

Noesis::TextureInfo FNoesisStudioTextureProvider::GetTextureInfo(const Noesis::Uri& Uri)
{
	Noesis::FixedString<512> Path;
	Uri.GetPath(Path);

	if (!mRootPath.Empty())
	{
		Path.Insert(0, "/");
		Path.Insert(0, mRootPath.Str());
	}

	FString TexturePath = NsProviderUriToAssetPath(Uri);
	UTexture2D* Texture = LoadObject<UTexture2D>(nullptr, *TexturePath, nullptr, LOAD_NoWarn);

	if (Texture)
	{
		for (uint32_t i = 0; i < mCachedTextures.Size(); i++)
		{
			if (Path == mCachedTextures[i].Filename)
			{
				mCachedTextures[i].Release();
				mCachedTextures.Erase(&mCachedTextures[i]);
				break;
			}
		}
#if WITH_EDITOR
		if (Texture->IsDefaultTexture())
		{
			FTextureCompilingManager::Get().FinishCompilation({ Texture });
		}
#endif
		NameMap.Add(Texture, Uri.Str());
		return Noesis::TextureInfo{ (uint32)Texture->GetSizeX(), (uint32)Texture->GetSizeY() };
	}

	for (auto TextureData : mCachedTextures)
	{
		if (Path == TextureData.Filename)
		{
			return Noesis::TextureInfo{ (uint32)TextureData.Texture->GetWidth(), (uint32)TextureData.Texture->GetHeight() };
		}
	}

	if (FPaths::FileExists(Path.Str()))
	{
		Texture = FImageUtils::ImportFileAsTexture2D(Path.Str());
		if (Texture)
		{
			mCachedTextures.EmplaceBack(Uri, Path.Str(), Texture);
			return Noesis::TextureInfo{ (uint32)Texture->GetSizeX(), (uint32)Texture->GetSizeY() };
		}
	}

	return Noesis::TextureInfo{};
}

Noesis::Ptr<Noesis::Texture> FNoesisStudioTextureProvider::LoadTexture(const Noesis::Uri& Uri, Noesis::RenderDevice* RenderDevice)
{
	Noesis::FixedString<512> Path;
	Uri.GetPath(Path);

	if (!mRootPath.Empty())
	{
		Path.Insert(0, "/");
		Path.Insert(0, mRootPath.Str());
	}

	for (auto TextureData : mCachedTextures)
	{
		if (Path == TextureData.Filename)
		{
			return TextureData.Texture;
		}
	}

	FString TexturePath = NsProviderUriToAssetPath(Uri);
	FString TextureObjectPath = TexturePath + TEXT(".") + FPackageName::GetShortName(TexturePath);
#if UE_VERSION_OLDER_THAN(5, 1, 0)
	UTexture2D* Texture = FindObject<UTexture2D>(nullptr, *TextureObjectPath);
#else
	UTexture2D* Texture = FindFirstObject<UTexture2D>(*TextureObjectPath);
#endif

	if (Texture)
	{
		return NoesisCreateTexture(Texture);
	}

	return nullptr;
}

FNoesisStudioFontProvider::FNoesisStudioFontProvider(const char* rootPath): mRootPath(rootPath)
{
}

void FNoesisStudioFontProvider::ScanFolder(const Noesis::Uri& Folder)
{
	Noesis::FixedString<512> Path;
	Folder.GetPath(Path);

	if (!mRootPath.Empty())
	{
		Path.Insert(0, "/");
		Path.Insert(0, mRootPath.Str());
	}

	class ScanFolderForFonts : public IPlatformFile::FDirectoryVisitor
	{
	public:
		ScanFolderForFonts(const Noesis::Uri& InFolder, FNoesisStudioFontProvider* InProvider)
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
		FNoesisStudioFontProvider* Provider;
	};

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	ScanFolderForFonts Visitor(Folder, this);
	PlatformFile.IterateDirectory(UTF8_TO_TCHAR(Path.Str()), Visitor);
}

Noesis::Ptr<Noesis::Stream> FNoesisStudioFontProvider::OpenFont(const  Noesis::Uri& Folder, const char* Filename) const
{
	Noesis::FixedString<512> UriString = Folder.Str();
	UriString += "/";
	UriString += Filename;
	const Noesis::Uri Uri(UriString.Str());

	FString FontPath = NsProviderUriToAssetPath(Uri);
	const UFontFace* FontFace = LoadObject<UFontFace>(nullptr, *FontPath, nullptr, LOAD_NoWarn);

	if (FontFace != nullptr)
	{
		return LoadFont(FontFace);
	}

	Noesis::FixedString<512> Path;
	Uri.GetPath(Path);

	if (!mRootPath.Empty())
	{
		Path.Insert(0, "/");
		Path.Insert(0, mRootPath.Str());
	}

	return Noesis::OpenFileStream(Path.Str());
}
