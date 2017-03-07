////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiEditorPrivatePCH.h"
#include "NoesisXamlFactory.h"

// Core includes
#include "Misc/Paths.h"
#include "Internationalization/Regex.h"

// UnrealEd includes
#include "Kismet2/KismetEditorUtilities.h"

// BlueprintGraph includes
#include "EdGraphSchema_K2.h"

// NoesisGui includes
#include "NoesisGuiSupport.h"
#include "NoesisBlueprintGeneratedClass.h"
#include "NoesisBlueprint.h"
#include "NoesisGeneratedClasses.h"
#include "NoesisCreateClass.h"

// FreeType2 includes
#include "ft2build.h"
#include FT_FREETYPE_H

// NoesisGuiEditor includes
#include "NoesisGuiEditorModule.h"

#define LOCTEXT_NAMESPACE "UNoesisXamlFactory"

UNoesisXamlFactory::UNoesisXamlFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bEditorImport = true;
	bEditAfterNew = true;
	SupportedClass = UNoesisXaml::StaticClass();
	Formats.Add(TEXT("xaml;NoesisGui Xaml"));
}

TArray<FString> ScanKeyword(FString Text, FString Keyword)
{
	TArray<FString> Strings;

	int32 KeywordIndex = INDEX_NONE;
	while ((KeywordIndex = Text.Find(Keyword, ESearchCase::IgnoreCase, ESearchDir::FromStart, KeywordIndex)) != INDEX_NONE)
	{
		int32 StartIndex = Text.Find(TEXT("\""), ESearchCase::IgnoreCase, ESearchDir::FromEnd, KeywordIndex);
		int32 EndIndex = Text.Find(TEXT("\""), ESearchCase::IgnoreCase, ESearchDir::FromStart, KeywordIndex);

		if (StartIndex != INDEX_NONE && EndIndex != INDEX_NONE)
		{
			Strings.Add(Text.Left(EndIndex).RightChop(StartIndex + 1));
		}

		KeywordIndex = EndIndex + 1;
	}

	return Strings;
}

struct FXamlDescriptor
{
	FString Path;
};

TArray<FXamlDescriptor> ParseForXamls(FString XamlText)
{
	TArray<FXamlDescriptor> XamlDescriptors;

	TArray<FString> Strings = ScanKeyword(XamlText, TEXT(".xaml"));
	for (auto String : Strings)
	{
		FXamlDescriptor& XamlDescriptor = *new(XamlDescriptors)FXamlDescriptor;
		XamlDescriptor.Path = String;
	}

	return XamlDescriptors;
}

TArray<UNoesisXaml*> ImportXamls(FString BasePackageName, FString Path, TArray<FXamlDescriptor> XamlDescriptors)
{
	TArray<UNoesisXaml*> Xamls;

	auto XamlFact = NewObject<UNoesisXamlFactory>();
	XamlFact->AddToRoot();

	for (auto XamlDescriptor : XamlDescriptors)
	{
		FString XamlPath = FPaths::GetPath(XamlDescriptor.Path);
		FString XamlName = ObjectTools::SanitizeObjectName(FPaths::GetBaseFilename(XamlDescriptor.Path));

		UPackage* XamlPackage = NULL;

		FString XamlObjectPath = BasePackageName / XamlPath / XamlName + TEXT(".") + XamlName;
		UNoesisXaml* ExistingXaml = LoadObject<UNoesisXaml>(NULL, *XamlObjectPath);

		if (!ExistingXaml)
		{
			const FString Suffix(TEXT(""));

			FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
			FString FinalPackageName;
			AssetToolsModule.Get().CreateUniqueAssetName(BasePackageName / XamlPath / XamlName, Suffix, FinalPackageName, XamlName);

			XamlPackage = CreatePackage(NULL, *FinalPackageName);
		}
		else
		{
			XamlPackage = ExistingXaml->GetOutermost();
		}

		FString FullFilename = Path / XamlDescriptor.Path;
		bool Cancelled = false;
		UNoesisXaml* Xaml = (UNoesisXaml*)XamlFact->ImportObject(UNoesisXaml::StaticClass(), XamlPackage, *XamlName, RF_Standalone | RF_Public, FullFilename, nullptr, Cancelled);

		if (Xaml != NULL)
		{
			// Notify the asset registry
			FAssetRegistryModule::AssetCreated(Xaml);

			// Set the dirty flag so this package will get saved later
			XamlPackage->SetDirtyFlag(true);
		}

		Xamls.Add(Xaml);
	}

	XamlFact->RemoveFromRoot();

	return Xamls;
}

struct FFontDescriptor
{
	FString Family;
};

TArray<FFontDescriptor> ParseForFonts(FString XamlText)
{
	TArray<FFontDescriptor> FontDescriptors;

	TArray<FString> Strings = ScanKeyword(XamlText, TEXT("#"));
	for (auto String : Strings)
	{
		FFontDescriptor& FontDescriptor = *new(FontDescriptors)FFontDescriptor;
		FontDescriptor.Family = String;
	}

	return FontDescriptors;
}

unsigned long StreamRead(FT_Stream Stream, unsigned long Offset, unsigned char* Buffer, unsigned long Count)
{
	FMemory::Memcpy(Buffer, (uint8*)Stream->descriptor.pointer + Offset, Count);
	return Count;
}

void StreamClose(FT_Stream) {}

TArray<UFont*> ImportFonts(FString BasePackageName, FString Path, TArray<FFontDescriptor> FontDescriptors)
{
	TArray<UFont*> Fonts;

	TSet<FString> UniqueFontFamilies;
	for (auto FontDescriptor : FontDescriptors)
	{
		UniqueFontFamilies.Add(FontDescriptor.Family);
	}

	for (auto Family : UniqueFontFamilies)
	{
		FString BaseUri, FamilyName;
		Family.Split(TEXT("#"), &BaseUri, &FamilyName);

		IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

		class ScanFolderForFonts : public IPlatformFile::FDirectoryVisitor
		{
		public:
			FString BasePackageName;
			FString Path;
			FString BaseUri;
			FString FamilyName;
			TArray<UFont*> Fonts;
			FT_Library FTLibrary;

			ScanFolderForFonts(FString InBasePackageName, FString InPath, FString InBaseUri, FString InFamilyName)
				: BasePackageName(InBasePackageName), Path(InPath), BaseUri(InBaseUri), FamilyName(InFamilyName)
			{
				int32 Error = FT_Init_FreeType(&FTLibrary);
				checkf(Error == 0, TEXT("Could not init Freetype"));
			}

			~ScanFolderForFonts()
			{
				FT_Done_FreeType(FTLibrary);
			}

			virtual bool Visit(const TCHAR* FilenameOrDirectory, bool IsDirectory) override
			{
				if (!IsDirectory)
				{
					FString Extension = FPaths::GetExtension(FilenameOrDirectory).ToLower();
					if (Extension == TEXT("ttf") || Extension == TEXT("otf"))
					{
						bool HasFamily = false;
						TArray<uint8> FileData;
						if (FFileHelper::LoadFileToArray(FileData, FilenameOrDirectory))
						{
							FT_StreamRec Stream;
							FMemory::Memset(&Stream, 0, sizeof(Stream));
							Stream.descriptor.pointer = FileData.GetData();
							Stream.size = FileData.Num();
							Stream.read = &StreamRead;
							Stream.close = &StreamClose;

							FT_Open_Args Args;
							FMemory::Memset(&Args, 0, sizeof(Args));
							Args.flags = FT_OPEN_STREAM;
							Args.stream = &Stream;

							FT_Face Face;
							FT_Error Error = FT_Open_Face(FTLibrary, &Args, -1, &Face);
							if (Error == 0)
							{
								for (FT_Long FaceIndex = 0; !HasFamily && FaceIndex < Face->num_faces; FaceIndex++)
								{
									FT_Face SubFace;
									Error = FT_Open_Face(FTLibrary, &Args, FaceIndex, &SubFace);
									if (Error == 0)
									{
										if (SubFace->family_name && FCStringAnsi::Strcmp(SubFace->family_name, StringCast<ANSICHAR>(*FamilyName).Get()) == 0)
										{
											HasFamily = true;
										}

										FT_Done_Face(SubFace);
									}
								}

								FT_Done_Face(Face);
							}
						}

						if (HasFamily)
						{
							FString FontName = ObjectTools::SanitizeObjectName(FPaths::GetBaseFilename(FPaths::GetBaseFilename(FilenameOrDirectory)));

							UPackage* FontPackage = NULL;

							FString FontObjectPath = BasePackageName / BaseUri / FontName + TEXT(".") + FontName;
							UFont* ExistingFont = LoadObject<UFont>(NULL, *FontObjectPath);

							if (!ExistingFont)
							{
								const FString Suffix(TEXT(""));

								FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
								FString FinalPackageName;
								AssetToolsModule.Get().CreateUniqueAssetName(BasePackageName / BaseUri / FontName, Suffix, FinalPackageName, FontName);

								FontPackage = CreatePackage(NULL, *FinalPackageName);
							}
							else
							{
								FontPackage = ExistingFont->GetOutermost();
							}

							auto FontFactory = NewObject<UFontFileImportFactory>();
							FontFactory->AddToRoot();

							bool Cancelled = false;
							UFont* Font = (UFont*)FontFactory->ImportObject(UFont::StaticClass(), FontPackage, *FontName, RF_Standalone | RF_Public, FilenameOrDirectory, TEXT(""), Cancelled);

							if (Font != NULL)
							{
								// Notify the asset registry
								FAssetRegistryModule::AssetCreated(Font);

								// Set the dirty flag so this package will get saved later
								FontPackage->SetDirtyFlag(true);
							}

							FontFactory->RemoveFromRoot();

							Fonts.Add(Font);
						}
					}
				}

				return true;
			}
		};

		ScanFolderForFonts Visitor(BasePackageName, Path, BaseUri, FamilyName);
		PlatformFile.IterateDirectory(*(Path / BaseUri), Visitor);

		Fonts += Visitor.Fonts;
	}

	return Fonts;
}

struct FImageDescriptor
{
	FString Path;
};

TArray<FImageDescriptor> ParseForImages(FString XamlText)
{
	TArray<FImageDescriptor> ImageDescriptors;

	TArray<FString> Strings = ScanKeyword(XamlText, TEXT(".jpg"));
	Strings += ScanKeyword(XamlText, TEXT(".tga"));
	Strings += ScanKeyword(XamlText, TEXT(".png"));
	Strings += ScanKeyword(XamlText, TEXT(".gif"));
	Strings += ScanKeyword(XamlText, TEXT(".bmp"));

	for (auto String : Strings)
	{
		FImageDescriptor& ImageDescriptor = *new(ImageDescriptors)FImageDescriptor;
		ImageDescriptor.Path = String;
	}

	return ImageDescriptors;
}

TArray<UTexture2D*> ImportImages(FString BasePackageName, FString Path, TArray<FImageDescriptor> ImageDescriptors)
{
	TArray<UTexture2D*> Textures;

	auto TextureFact = NewObject<UTextureFactory>();
	TextureFact->AddToRoot();

	TSet<FString> UniqueImagePaths;
	for (auto ImageDescriptor : ImageDescriptors)
	{
		UniqueImagePaths.Add(ImageDescriptor.Path);
	}

	for (auto ImagePath : UniqueImagePaths)
	{
		FString TexturePath = FPaths::GetPath(ImagePath);
		FString TextureName = ObjectTools::SanitizeObjectName(FPaths::GetBaseFilename(ImagePath));

		UPackage* TexturePackage = NULL;

		FString TextureObjectPath = BasePackageName / TexturePath / TextureName + TEXT(".") + TextureName;
		UTexture2D* ExistingTexture = LoadObject<UTexture2D>(NULL, *TextureObjectPath);

		if (!ExistingTexture)
		{
			const FString Suffix(TEXT(""));

			FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
			FString FinalPackageName;
			AssetToolsModule.Get().CreateUniqueAssetName(BasePackageName / TexturePath / TextureName, Suffix, FinalPackageName, TextureName);

			TexturePackage = CreatePackage(NULL, *FinalPackageName);
		}
		else
		{
			TexturePackage = ExistingTexture->GetOutermost();
		}

		TextureFact->SuppressImportOverwriteDialog();

		FString FullFilename = Path / ImagePath;
		bool Cancelled = false;
		UTexture2D* Texture = (UTexture2D*)TextureFact->ImportObject(UTexture2D::StaticClass(), TexturePackage, *TextureName, RF_Standalone | RF_Public, FullFilename, nullptr, Cancelled);

		if (Texture != NULL)
		{
			// Notify the asset registry
			FAssetRegistryModule::AssetCreated(Texture);

			// Set the dirty flag so this package will get saved later
			TexturePackage->SetDirtyFlag(true);
		}

		Textures.Add(Texture);
	}

	TextureFact->RemoveFromRoot();

	return Textures;
}

UObject* UNoesisXamlFactory::FactoryCreateBinary(UClass* Class, UObject* Parent, FName Name, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const uint8*& Buffer, const uint8* BufferEnd, FFeedbackContext* Warn)
{
	FString Filename = FPaths::ConvertRelativePathToFull(GetCurrentFilename());
	FString BasePackageName = FPackageName::GetLongPackagePath(Parent->GetPathName());

	FString XamlText(UTF8_TO_TCHAR(Buffer));

	TArray<FString> Comments;
	FRegexPattern CommentPattern(TEXT("<!--.*-->"));
	FRegexMatcher CommentMatcher(CommentPattern, XamlText);

	while (CommentMatcher.FindNext())
	{
		Comments.Add(XamlText.Left(CommentMatcher.GetMatchEnding()).RightChop(CommentMatcher.GetMatchBeginning()));
	}

	for (auto Comment : Comments)
	{
		XamlText = XamlText.Replace(*Comment, TEXT(""));
	}

	TArray<FXamlDescriptor> XamlDescriptors = ParseForXamls(XamlText);
	TArray<UNoesisXaml*> Xamls = ImportXamls(BasePackageName, FPaths::GetPath(Filename), XamlDescriptors);

	TArray<FFontDescriptor> FontDescriptors = ParseForFonts(XamlText);
	TArray<UFont*> Fonts = ImportFonts(BasePackageName, FPaths::GetPath(Filename), FontDescriptors);

	TArray<FImageDescriptor> ImageDescriptors = ParseForImages(XamlText);
	TArray<UTexture2D*> Textures = ImportImages(BasePackageName, FPaths::GetPath(Filename), ImageDescriptors);

	UNoesisXaml* NoesisXaml = NewObject<UNoesisXaml>(Parent, Class, Name, Flags);

	NoesisXaml->XamlText.Insert(Buffer, BufferEnd - Buffer, 0);
	NoesisXaml->XamlMap.Add(NoesisXaml->GetName() + TEXT(".xaml"), NoesisXaml);

	for (int32 XamlIndex = 0; XamlIndex != XamlDescriptors.Num(); ++XamlIndex)
	{
		UNoesisXaml* ReferencedXaml = Xamls[XamlIndex];
		NoesisXaml->XamlMap.Add(XamlDescriptors[XamlIndex].Path, ReferencedXaml);

		for (auto Xaml : ReferencedXaml->XamlMap)
		{
			NoesisXaml->XamlMap.Add(Xaml.Key, Xaml.Value);
		}

		for (auto Font : ReferencedXaml->FontMap)
		{
			NoesisXaml->FontMap.Add(Font.Key, Font.Value);
		}

		for (auto Texture : ReferencedXaml->TextureMap)
		{
			NoesisXaml->TextureMap.Add(Texture.Key, Texture.Value);
		}
	}

	for (auto Font : Fonts)
	{
		NoesisXaml->FontMap.Add(Font->GetPathName(), Font);
	}

	for (int32 ImageIndex = 0; ImageIndex != ImageDescriptors.Num(); ++ImageIndex)
	{
		NoesisXaml->TextureMap.Add(ImageDescriptors[ImageIndex].Path, Textures[ImageIndex]);
	}

	Noesis::Ptr<Noesis::Core::BaseComponent> Xaml = Noesis::GUI::LoadXaml<Noesis::Core::BaseComponent>(StringCast<NsChar>(*(FString::FromInt(NoesisXaml->GetUniqueID()) / NoesisXaml->GetName() + TEXT(".xaml"))).Get());
	Noesis::Ptr<Noesis::FrameworkElement> FrameworkElement = NsDynamicCast<Noesis::Ptr<Noesis::FrameworkElement>>(Xaml);
	Noesis::Ptr<Noesis::ResourceDictionary> ResourceDictionary = NsDynamicCast<Noesis::Ptr<Noesis::ResourceDictionary>>(Xaml);
	TArray<Noesis::FrameworkElement*> Elements;
	if (FrameworkElement)
	{
		CollectElements(FrameworkElement.GetPtr(), Elements);
		for (auto Element : Elements)
		{
			const NsChar* ElementName = Element->GetName();
			UNoesisBaseComponent* NoesisGuiComponent = CreateClassFor(Element, NoesisXaml);
			NoesisGuiComponent->ElementName = ElementName ? NsStringToFName(ElementName) : NAME_None;
			NoesisXaml->Components.Add(NoesisGuiComponent);
		}
	}

	NoesisXaml->AssetImportData->Update(Filename);

	return NoesisXaml;
}

#undef LOCTEXT_NAMESPACE
