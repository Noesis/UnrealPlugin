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

UNoesisXaml* FNoesisResourceProvider::GetXaml(FString XamlPath)
{
	return LoadObject<UNoesisXaml>(nullptr, *ProcessPath(TCHAR_TO_ANSI(*XamlPath), EResourceType::RT_Xaml));
}

Noesis::Ptr<Noesis::Stream> FNoesisResourceProvider::LoadXaml(const char* Path)
{
	UNoesisXaml* Xaml = GetXaml(Path);
	if (Xaml)
	{
		return Noesis::Ptr<Noesis::Stream>(*new Noesis::MemoryStream(Xaml->XamlText.GetData(), (uint32)Xaml->XamlText.Num()));
	}

	return Noesis::Ptr<Noesis::Stream>();
};

UTexture2D* FNoesisResourceProvider::GetTexture(FString TexturePath)
{
	return LoadObject<UTexture2D>(nullptr, *ProcessPath(TCHAR_TO_ANSI(*TexturePath), EResourceType::RT_Texture));
}

Noesis::TextureInfo FNoesisResourceProvider::GetTextureInfo(const char* Path)
{
	UTexture* Texture = GetTexture(Path);
	if (Texture)
	{
		UTexture2D* Texture2D = CastChecked<UTexture2D>(Texture);
		return Noesis::TextureInfo{ (uint32)Texture2D->GetSizeX(), (uint32)Texture2D->GetSizeY() };
	}

	return Noesis::TextureInfo{};
}

Noesis::Ptr<Noesis::Texture> FNoesisResourceProvider::LoadTexture(const char* Path, Noesis::RenderDevice* RenderDevice)
{
	return NoesisCreateTexture(GetTexture(Path));
};

void FNoesisResourceProvider::ScanFolder(const char* InFolder)
{
	UFont* Font = LoadObject<UFont>(nullptr, *ProcessPath(InFolder, EResourceType::RT_Font));
	if (Font)
	{
		for (auto TypefaceEntry : Font->CompositeFont.DefaultTypeface.Fonts)
		{
			ANSICHAR TypefaceName[NAME_SIZE];
			TypefaceEntry.Name.GetPlainANSIString(TypefaceName);
			RegisterFont(InFolder, TypefaceName);
		}
	}
}

Noesis::Ptr<Noesis::Stream> FNoesisResourceProvider::OpenFont(const char* InFolder, const char* InFilename) const
{
	UFont* Font = LoadObject<UFont>(nullptr, *ProcessPath(InFolder, EResourceType::RT_Font));
	if (Font)
	{
		for (auto TypefaceEntry : Font->CompositeFont.DefaultTypeface.Fonts)
		{
			ANSICHAR TypefaceName[NAME_SIZE];
			TypefaceEntry.Name.GetPlainANSIString(TypefaceName);
			if (FCStringAnsi::Strcmp(TypefaceName, InFilename) == 0)
			{
				const FFontData* FontData = &TypefaceEntry.Font;
				const UFontFace* FontFace = Cast<UFontFace>(FontData->GetFontFaceAsset());
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
		}
	}
	return Noesis::Ptr<Noesis::Stream>();
}

FString FNoesisResourceProvider::ProcessPath(const char* Path, EResourceType ResourceType)
{
	FString Result = NsStringToFString(Path);

	auto BasePath = FPaths::GetPath(Result);
	BasePath = BasePath[0] == '/' ? BasePath : "/" + BasePath;
	BasePath += "/";

	auto FileName = FPaths::GetBaseFilename(Result);
	Result = BasePath + FileName + "." + FileName;

	/* NOTE: This is surely sub-optimal */
	auto LoadedObject = LoadObject<UObject>(nullptr, *Result);
	if (LoadedObject == nullptr)
	{
		if (ResourceType == EResourceType::RT_FontFace)
			FileName = "FF_" + FileName;
		else if (ResourceType == EResourceType::RT_Font)
			FileName = "F_" + FileName;
		else if (ResourceType == EResourceType::RT_Texture)
			FileName = "T_" + FileName;
		else if (ResourceType == EResourceType::RT_Xaml)
			FileName = "XAML_" + FileName;

		Result = BasePath + FileName + "." + FileName;
	}

	return Result;
}

FString FNoesisResourceProvider::ProcessPath(const FString& Path, EResourceType ResourceType /*= EResourceType::RT_Unknown*/)
{
	return ProcessPath(TCHAR_TO_ANSI(*Path), ResourceType);
}
