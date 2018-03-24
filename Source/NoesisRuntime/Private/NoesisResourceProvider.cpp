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
	return LoadObject<UNoesisXaml>(nullptr, XamlPath[0] == TEXT('/') ? *XamlPath : *(FString(TEXT("/")) + XamlPath));
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
	return LoadObject<UTexture2D>(nullptr, TexturePath[0] == TEXT('/') ? *TexturePath : *(FString(TEXT("/")) + TexturePath));
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
	UFont* Font = LoadObject<UFont>(nullptr, InFolder[0] == '/' ? *NsStringToFString(InFolder) : *(FString(TEXT("/")) + NsStringToFString(InFolder)));
	if (Font)
	{
		for (auto TypefaceEntry : Font->CompositeFont.DefaultTypeface.Fonts)
		{
			RegisterFont(InFolder, TypefaceEntry.Name.GetPlainANSIString());
		}
	}
}

Noesis::Ptr<Noesis::Stream> FNoesisResourceProvider::OpenFont(const char* InFolder, const char* InFilename) const
{
	UFont* Font = LoadObject<UFont>(nullptr, InFolder[0] == '/' ? *NsStringToFString(InFolder) : *(FString(TEXT("/")) + NsStringToFString(InFolder)));
	if (Font)
	{
		for (auto TypefaceEntry : Font->CompositeFont.DefaultTypeface.Fonts)
		{
			if (FCStringAnsi::Strcmp(TypefaceEntry.Name.GetPlainANSIString(), InFilename) == 0)
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
