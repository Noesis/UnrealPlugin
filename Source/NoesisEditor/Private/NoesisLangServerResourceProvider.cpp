////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisLangServerResourceProvider.h"

// Core includes
#include "CoreMinimal.h"
#include "Misc/FileHelper.h"
#include "Misc/EngineVersionComparison.h"

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

#if defined(NS_PLATFORM_WINDOWS)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h>
// The UpdateResource macro conflicts with a Texture::UpdateResource
#undef UpdateResource
#elif defined(NS_PLATFORM_OSX) || defined(NS_PLATFORM_LINUX)
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#endif

namespace
{
    struct FontFindData
    {
        char filename[512];
        char extension[16];
        void* handle;
    };

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

static void FontFindClose(FontFindData& findData)
{
#if defined(NS_PLATFORM_WINDOWS)
    int r = ::FindClose(findData.handle);
    NS_ASSERT(r != 0);
#else
    DIR* dir = (DIR*)findData.handle;
    int r = closedir(dir);
    NS_ASSERT(r == 0);
#endif
}

static bool FontFindNext(FontFindData& findData)
{
#if defined(NS_PLATFORM_WINDOWS)
    WIN32_FIND_DATAW fd;
    int res = FindNextFileW(findData.handle, &fd);

    if (res)
    {
        const int MaxFilename = sizeof(findData.filename);
        uint32_t n = Noesis::UTF8::UTF16To8((uint16_t*)fd.cFileName, findData.filename, MaxFilename);
        NS_ASSERT(n <= MaxFilename);
        return true;
    }

    return false;

#else
    DIR* dir = (DIR*)findData.handle;

    while (true)
    {
        dirent* entry = readdir(dir);

        if (entry != 0)
        {
            if (Noesis::StrCaseEndsWith(entry->d_name, findData.extension))
            {
                Noesis::StrCopy(findData.filename, sizeof(findData.filename), entry->d_name);
                return true;
            }
        }
        else
        {
            return false;
        }
    }
#endif
}

static bool FontFindFirst(const char* directory, const char* extension, FontFindData& findData)
{
#if defined(NS_PLATFORM_WINDOWS)
    char fullPath[sizeof(findData.filename)];
    Noesis::StrCopy(fullPath, sizeof(fullPath), directory);
    Noesis::StrAppend(fullPath, sizeof(fullPath), "/*");
    Noesis::StrAppend(fullPath, sizeof(fullPath), extension);

    uint16_t u16str[sizeof(fullPath)];
    uint32_t numChars = Noesis::UTF8::UTF8To16(fullPath, u16str, sizeof(fullPath));
    NS_ASSERT(numChars <= sizeof(fullPath));

    WIN32_FIND_DATAW fd;
    HANDLE h = FindFirstFileExW((LPCWSTR)u16str, FindExInfoBasic, &fd, FindExSearchNameMatch, 0, 0);
    if (h != INVALID_HANDLE_VALUE)
    {
        numChars = Noesis::UTF8::UTF16To8((uint16_t*)fd.cFileName, findData.filename, sizeof(fullPath));
        NS_ASSERT(numChars <= sizeof(fullPath));
        Noesis::StrCopy(findData.extension, sizeof(findData.extension), extension);
        findData.handle = h;
        return true;
    }

    return false;

#else
    DIR* dir = opendir(directory);

    if (dir != 0)
    {
        Noesis::StrCopy(findData.extension, sizeof(findData.extension), extension);
        findData.handle = dir;

        if (FontFindNext(findData))
        {
            return true;
        }
        else
        {
            FontFindClose(findData);
            return false;
        }
    }

    return false;
#endif
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

void FNoesisLangServerFontProvider::ScanFolder(const Noesis::Uri& folder)
{
    Noesis::FixedString<512> path;
    folder.GetPath(path);

    ScanFolder(path.Str(), folder, ".ttf");
    ScanFolder(path.Str(), folder, ".otf");
    ScanFolder(path.Str(), folder, ".ttc");
}

void FNoesisLangServerFontProvider::ScanFolder(const char* path, const  Noesis::Uri& folder, const char* ext)
{
    FontFindData findData;

    if (FontFindFirst(path, ext, findData))
    {
        do
        {
            RegisterFont(folder, findData.filename);
        } while (FontFindNext(findData));

        FontFindClose(findData);
    }
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