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
	UNoesisXaml* Xaml;
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

void ImportXamls(FString BasePackageName, FString Path, TArray<FXamlDescriptor>& XamlDescriptors)
{
	auto XamlFact = NewObject<UNoesisXamlFactory>();
	XamlFact->AddToRoot();

	for (auto& XamlDescriptor : XamlDescriptors)
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

		XamlDescriptor.Xaml = Xaml;
	}

	XamlFact->RemoveFromRoot();
}

struct FFontDescriptor
{
	FString Family;
	UFont* Font;
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

void ImportFonts(FString BasePackageName, FString Path, TArray<FFontDescriptor>& FontDescriptors)
{
	TSet<FString> UniqueFontFamilies;
	for (auto FontDescriptor : FontDescriptors)
	{
		UniqueFontFamilies.Add(FontDescriptor.Family);
	}

	FontDescriptors.Empty();

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
			UFont* Font;
			FT_Library FTLibrary;

			ScanFolderForFonts(FString InBasePackageName, FString InPath, FString InBaseUri, FString InFamilyName)
				: BasePackageName(InBasePackageName), Path(InPath), BaseUri(InBaseUri), FamilyName(InFamilyName), Font(nullptr)
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
							FString FontFaceName = ObjectTools::SanitizeObjectName(FPaths::GetBaseFilename(FPaths::GetBaseFilename(FilenameOrDirectory)));

							UPackage* FontFacePackage = NULL;

							FString FontFaceObjectPath = BasePackageName / BaseUri / FontFaceName + TEXT(".") + FontFaceName;
							UFontFace* ExistingFontFace = LoadObject<UFontFace>(NULL, *FontFaceObjectPath);

							if (!ExistingFontFace)
							{
								const FString Suffix(TEXT(""));

								FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
								FString FinalPackageName;
								AssetToolsModule.Get().CreateUniqueAssetName(BasePackageName / BaseUri / FontFaceName, Suffix, FinalPackageName, FontFaceName);

								FontFacePackage = CreatePackage(NULL, *FinalPackageName);
							}
							else
							{
								FontFacePackage = ExistingFontFace->GetOutermost();
							}

							auto FontFaceFactory = NewObject<UFontFileImportFactory>();
							FontFaceFactory->AddToRoot();

							UAutomatedAssetImportData* AutomatedAssetImportData = NewObject<UAutomatedAssetImportData>();
							FontFaceFactory->SetAutomatedAssetImportData(AutomatedAssetImportData);

							bool Cancelled = false;
							UFontFace* FontFace = (UFontFace*)FontFaceFactory->ImportObject(UFontFace::StaticClass(), FontFacePackage, *FontFaceName, RF_Standalone | RF_Public, FilenameOrDirectory, TEXT(""), Cancelled);

							if (FontFace != NULL)
							{
								// Notify the asset registry
								FAssetRegistryModule::AssetCreated(FontFace);

								// Set the dirty flag so this package will get saved later
								FontFacePackage->SetDirtyFlag(true);
							}

							FontFaceFactory->RemoveFromRoot();

							UPackage* FontPackage = NULL;

							FString FontName = FontFaceName + TEXT("_Font");
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

							UFontFactory* FontFactory = NewObject<UFontFactory>();
							FontFactory->bEditAfterNew = false;

							Font = Cast<UFont>(FontFactory->FactoryCreateNew(UFont::StaticClass(), FontPackage, *FontName, RF_Standalone | RF_Public, nullptr, nullptr));
							if (Font)
							{
								Font->FontCacheType = EFontCacheType::Runtime;

								// Add a default typeface referencing the newly created font face
								FTypefaceEntry& DefaultTypefaceEntry = Font->CompositeFont.DefaultTypeface.Fonts[Font->CompositeFont.DefaultTypeface.Fonts.AddDefaulted()];
								DefaultTypefaceEntry.Name = "Default";
								DefaultTypefaceEntry.Font = FFontData(FontFace);

								FAssetRegistryModule::AssetCreated(Font);
								FontPackage->MarkPackageDirty();
							}

							return false;
						}
					}
				}

				return true;
			}
		};

		ScanFolderForFonts Visitor(BasePackageName, Path, BaseUri, FamilyName);
		PlatformFile.IterateDirectory(*(Path / BaseUri), Visitor);

		if (Visitor.Font)
		{
			FFontDescriptor& FontDescriptor = *new(FontDescriptors)FFontDescriptor;
			FontDescriptor.Family = Family;
			FontDescriptor.Font = Visitor.Font;
		}
	}
}

struct FImageDescriptor
{
	FString Path;
	UTexture2D* Texture;
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

void ImportImages(FString BasePackageName, FString Path, TArray<FImageDescriptor>& ImageDescriptors)
{
	auto TextureFact = NewObject<UTextureFactory>();
	TextureFact->AddToRoot();

	TSet<FString> UniqueImagePaths;
	for (auto ImageDescriptor : ImageDescriptors)
	{
		UniqueImagePaths.Add(ImageDescriptor.Path);
	}

	ImageDescriptors.Empty();

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

		FImageDescriptor& ImageDescriptor = *new(ImageDescriptors)FImageDescriptor;
		ImageDescriptor.Path = ImagePath;
		ImageDescriptor.Texture = Texture;
	}

	TextureFact->RemoveFromRoot();
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
	ImportXamls(BasePackageName, FPaths::GetPath(Filename), XamlDescriptors);

	TArray<FFontDescriptor> FontDescriptors = ParseForFonts(XamlText);
	ImportFonts(BasePackageName, FPaths::GetPath(Filename), FontDescriptors);

	TArray<FImageDescriptor> ImageDescriptors = ParseForImages(XamlText);
	ImportImages(BasePackageName, FPaths::GetPath(Filename), ImageDescriptors);

	UNoesisXaml* NoesisXaml = NewObject<UNoesisXaml>(Parent, Class, Name, Flags);

	NoesisXaml->XamlText.Insert(Buffer, BufferEnd - Buffer, 0);
	NoesisXaml->XamlMap.Add(NoesisXaml->GetName() + TEXT(".xaml"), NoesisXaml);

	for (auto XamlDescriptor : XamlDescriptors)
	{
		FString RelativePath, XamlName;
		XamlDescriptor.Path.Split(TEXT("/"), &RelativePath, &XamlName, ESearchCase::IgnoreCase, ESearchDir::FromEnd);

		UNoesisXaml* ReferencedXaml = XamlDescriptor.Xaml;
		NoesisXaml->XamlMap.Add(XamlDescriptor.Path, ReferencedXaml);

		for (auto Xaml : ReferencedXaml->XamlMap)
		{
			NoesisXaml->XamlMap.Add(RelativePath.IsEmpty() ? Xaml.Key : RelativePath / Xaml.Key, Xaml.Value);
		}

		for (auto Font : ReferencedXaml->FontMap)
		{
			NoesisXaml->FontMap.Add(RelativePath.IsEmpty() ? Font.Key : RelativePath / Font.Key, Font.Value);
		}

		for (auto Texture : ReferencedXaml->TextureMap)
		{
			NoesisXaml->TextureMap.Add(RelativePath.IsEmpty() ? Texture.Key : RelativePath / Texture.Key, Texture.Value);
		}
	}

	for (auto FontDescriptor : FontDescriptors)
	{
		NoesisXaml->FontMap.Add(FontDescriptor.Family, FontDescriptor.Font);
	}

	for (auto ImageDescriptor : ImageDescriptors)
	{
		NoesisXaml->TextureMap.Add(ImageDescriptor.Path, ImageDescriptor.Texture);
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
