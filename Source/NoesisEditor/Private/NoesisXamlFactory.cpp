////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisXamlFactory.h"

// UnrealEd includes
#include "Settings/EditorLoadingSavingSettings.h"

// NoesisEditor includes
#include "NoesisEditorModule.h"
#include "NoesisEditorUserSettings.h"

UNoesisXamlFactory::UNoesisXamlFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bEditorImport = true;
	bEditAfterNew = true;
	SupportedClass = UNoesisXaml::StaticClass();
	Formats.Add(TEXT("xaml;NoesisGUI XAML"));
}

void ExtractPaths(FString FileUri, FString BaseFilePath, FString BasePackage, FString ProjectURIRoot, FString& FilePath, FString& FileName, FString& PackagePath, FString& PackageName)
{
	FilePath = FileUri;
	FString PackUri = TEXT("pack://application:,,,");
	int32 PackUriIndex = FilePath.Find(PackUri);
	if (PackUriIndex != INDEX_NONE)
	{
		FilePath = FilePath.RightChop(PackUriIndex + PackUri.Len());
	}

	FString ComponentUri = TEXT(";component");
	int32 ComponentUriIndex = FilePath.Find(ComponentUri);
	if (ComponentUriIndex != INDEX_NONE)
	{
		FilePath = FilePath.RightChop(ComponentUriIndex + ComponentUri.Len());
	}

	if (FPaths::IsRelative(FilePath))
	{
		FilePath = BaseFilePath / FilePath;
	}
	else
	{
		FilePath = FilePath;
	}

	FPaths::RemoveDuplicateSlashes(FilePath);
	FPaths::NormalizeFilename(FilePath);
	FPaths::CollapseRelativeDirectories(FilePath);

	FileName = FPaths::GetCleanFilename(FilePath);
	FilePath = FPaths::GetPath(FilePath);

	PackagePath = FString(TEXT("/")) + BasePackage / FilePath;
	PackagePath = PackageTools::SanitizePackageName(PackagePath);
	PackageName = ObjectTools::SanitizeObjectName(FPaths::GetBaseFilename(FileName));

	FilePath = ProjectURIRoot / FilePath;
	FPaths::RemoveDuplicateSlashes(FilePath);
	FPaths::NormalizeFilename(FilePath);
	FPaths::CollapseRelativeDirectories(FilePath);
}

TArray<FString> ScanKeyword(FString Text, FString Keyword)
{
	TArray<FString> Strings;

	int32 TextLen = Text.Len();
	int32 KeywordIndex = INDEX_NONE;
	while ((KeywordIndex = Text.Find(Keyword, ESearchCase::IgnoreCase, ESearchDir::FromStart, KeywordIndex)) != INDEX_NONE)
	{
		int32 StartIndex = KeywordIndex;
		while (StartIndex >= 0 && Text[StartIndex] != TEXT('\"') && Text[StartIndex] != TEXT('\'') && Text[StartIndex] != TEXT('>'))
		{
			--StartIndex;
		}

		int32 EndIndex = KeywordIndex;
		while (EndIndex < TextLen && Text[EndIndex] != TEXT('\"') && Text[EndIndex] != TEXT('\'') && Text[EndIndex] != TEXT('<'))
		{
			++EndIndex;
		}

		if (StartIndex >= 0 && EndIndex < TextLen)
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

void ImportXamls(FString BasePackageName, FString ProjectURIRoot, FString Path, TArray<FXamlDescriptor>& XamlDescriptors)
{
	auto XamlFact = NewObject<UNoesisXamlFactory>();
	XamlFact->AddToRoot();

	for (auto& XamlDescriptor : XamlDescriptors)
	{
		FString XamlPath;
		FString FileName;
		FString PackagePath;
		FString XamlName;
		ExtractPaths(XamlDescriptor.Path, Path, BasePackageName, ProjectURIRoot, XamlPath, FileName, PackagePath, XamlName);


		UPackage* XamlPackage = NULL;

		FString XamlObjectPath = PackagePath / XamlName + TEXT(".") + XamlName;
		UNoesisXaml* ExistingXaml = LoadObject<UNoesisXaml>(NULL, *XamlObjectPath);

		if (!ExistingXaml)
		{
			const FString Suffix(TEXT(""));

			XamlPackage = CreatePackage(NULL, *(PackagePath / XamlName));
		}
		else
		{
			XamlPackage = ExistingXaml->GetOutermost();
			XamlPackage->FullyLoad();
			ExistingXaml->DestroyThumbnailRenderData();
		}

		FString FullFilename = XamlPath / FileName;
		FPaths::MakeStandardFilename(FullFilename);
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

void ImportFonts(FString BasePackageName, FString ProjectURIRoot, FString Path, TArray<FFontDescriptor>& FontDescriptors)
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
			FString FontPackagePath;
			FString FamilyName;
			TArray<FTypefaceEntry> Fonts;
			FT_Library FTLibrary;

			ScanFolderForFonts(FString InFontPackagePath, FString InFamilyName)
				: FontPackagePath(InFontPackagePath), FamilyName(InFamilyName)
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
								for (FT_Long FaceIndex = 0; FaceIndex < Face->num_faces; FaceIndex++)
								{
									FT_Face SubFace;
									Error = FT_Open_Face(FTLibrary, &Args, FaceIndex, &SubFace);
									if (Error == 0)
									{
										if (SubFace->family_name && FCStringAnsi::Strcmp(SubFace->family_name, StringCast<ANSICHAR>(*FamilyName).Get()) == 0)
										{
											FString FontFaceName = ObjectTools::SanitizeObjectName(FPaths::GetBaseFilename(FPaths::GetBaseFilename(FilenameOrDirectory)));

											UPackage* FontFacePackage = NULL;

											FString FontFaceObjectPath = FontPackagePath / FontFaceName + TEXT(".") + FontFaceName;
											UFontFace* ExistingFontFace = LoadObject<UFontFace>(NULL, *FontFaceObjectPath);

											if (!ExistingFontFace)
											{
												const FString Suffix(TEXT(""));

												FontFacePackage = CreatePackage(NULL, *(FontPackagePath / FontFaceName));
											}
											else
											{
												FontFacePackage = ExistingFontFace->GetOutermost();
												FontFacePackage->FullyLoad();
											}

											auto FontFaceFactory = NewObject<UFontFileImportFactory>();
											FontFaceFactory->AddToRoot();

											UAutomatedAssetImportData* AutomatedAssetImportData = NewObject<UAutomatedAssetImportData>();
											FontFaceFactory->SetAutomatedAssetImportData(AutomatedAssetImportData);

											bool Cancelled = false;
											UFontFace* FontFace = (UFontFace*)FontFaceFactory->ImportObject(UFontFace::StaticClass(), FontFacePackage, *FontFaceName, RF_Standalone | RF_Public, FilenameOrDirectory, TEXT(""), Cancelled);

											if (FontFace != NULL)
											{
												FontFace->LoadingPolicy = EFontLoadingPolicy::Inline;

												// Notify the asset registry
												FAssetRegistryModule::AssetCreated(FontFace);

												// Set the dirty flag so this package will get saved later
												FontFacePackage->SetDirtyFlag(true);
											}

											FontFaceFactory->RemoveFromRoot();

											// Add a default typeface referencing the newly created font face
											FTypefaceEntry& DefaultTypefaceEntry = Fonts[Fonts.AddDefaulted()];
											DefaultTypefaceEntry.Name = SubFace->style_name;
											DefaultTypefaceEntry.Font = FFontData(FontFace);

										}

										FT_Done_Face(SubFace);
									}
								}

								FT_Done_Face(Face);
							}
						}
					}
				}

				return true;
			}
		};

		FString FontFilePath;
		FString FontFileName;
		FString FontPackagePath;
		FString FontPackageName;
		ExtractPaths(BaseUri, Path, BasePackageName, ProjectURIRoot, FontFilePath, FontFileName, FontPackagePath, FontPackageName);

		ScanFolderForFonts Visitor(FontPackagePath, FamilyName);
		PlatformFile.IterateDirectory(*FontFilePath, Visitor);

		if (Visitor.Fonts.Num())
		{
			UPackage* FontPackage = NULL;

			FString FontName = ObjectTools::SanitizeObjectName(FamilyName + TEXT("_Font"));
			FString FontObjectPath = FontPackagePath / FontName + TEXT(".") + FontName;
			UFont* ExistingFont = LoadObject<UFont>(NULL, *FontObjectPath);

			if (!ExistingFont)
			{
				const FString Suffix(TEXT(""));

				FontPackage = CreatePackage(NULL, *(FontPackagePath / FontName));
			}
			else
			{
				FontPackage = ExistingFont->GetOutermost();
				FontPackage->FullyLoad();
			}

			UFontFactory* FontFactory = NewObject<UFontFactory>();
			FontFactory->bEditAfterNew = false;

			UFont* Font = Cast<UFont>(FontFactory->FactoryCreateNew(UFont::StaticClass(), FontPackage, *FontName, RF_Standalone | RF_Public, nullptr, nullptr));
			if (Font)
			{
				Font->FontCacheType = EFontCacheType::Runtime;

				FAssetRegistryModule::AssetCreated(Font);
				FontPackage->MarkPackageDirty();

				Font->CompositeFont.DefaultTypeface.Fonts = Visitor.Fonts;

				FFontDescriptor& FontDescriptor = *new(FontDescriptors)FFontDescriptor;
				FontDescriptor.Family = Family;
				FontDescriptor.Font = Font;
			}
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

	TArray<FString> Strings;
	auto TextureFact = NewObject<UTextureFactory>();
	for (auto Format : TextureFact->Formats)
	{
		int32 Index;
		Format.FindChar(TEXT(';'), Index);
		Strings += ScanKeyword(XamlText, FString(TEXT(".")) + Format.Left(Index));
	}

	for (auto String : Strings)
	{
		FImageDescriptor& ImageDescriptor = *new(ImageDescriptors)FImageDescriptor;
		ImageDescriptor.Path = String;
	}

	return ImageDescriptors;
}

void ImportImages(FString BasePackageName, FString ProjectURIRoot, FString Path, TArray<FImageDescriptor>& ImageDescriptors)
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
		FString TexturePath;
		FString FileName;
		FString PackagePath;
		FString TextureName;
		ExtractPaths(ImagePath, Path, BasePackageName, ProjectURIRoot, TexturePath, FileName, PackagePath, TextureName);

		UPackage* TexturePackage = NULL;

		FString TextureObjectPath = PackagePath / TextureName + TEXT(".") + TextureName;
		UTexture2D* ExistingTexture = LoadObject<UTexture2D>(NULL, *TextureObjectPath);

		if (!ExistingTexture)
		{
			const FString Suffix(TEXT(""));

			TexturePackage = CreatePackage(NULL, *(PackagePath / TextureName));
		}
		else
		{
			TexturePackage = ExistingTexture->GetOutermost();
			TexturePackage->FullyLoad();
		}

		TextureFact->SuppressImportOverwriteDialog();

		FString FullFilename = TexturePath / FileName;
		bool Cancelled = false;
		UTexture2D* Texture = (UTexture2D*)TextureFact->ImportObject(UTexture2D::StaticClass(), TexturePackage, *TextureName, RF_Standalone | RF_Public, FullFilename, nullptr, Cancelled);

		if (Texture != NULL)
		{
			Texture->LODGroup = TEXTUREGROUP_UI;
			Texture->SRGB = false;
			void FixPremultipliedPNGTexture(UTexture2D*);
			FixPremultipliedPNGTexture(Texture);

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
	FString FullFilename = GetCurrentFilename();
	FString Filename = FullFilename;
	FString Directory = FPaths::GetPath(Filename);
	Filename = FPaths::GetCleanFilename(Filename);
	FString ProjectURIRoot;
	FString BasePackageName;
	for (const auto& Setting : GetDefault<UEditorLoadingSavingSettings>()->AutoReimportDirectorySettings)
	{
		FString RelativeFilename = FullFilename;
		FString SourceDirectory = Setting.SourceDirectory + TEXT("/");
		if (FPaths::MakePathRelativeTo(RelativeFilename, *SourceDirectory))
		{
			FPaths::CollapseRelativeDirectories(RelativeFilename);
			FPaths::NormalizeFilename(RelativeFilename);
			if (!RelativeFilename.StartsWith(TEXT("..")))
			{
				ProjectURIRoot = SourceDirectory;
				BasePackageName = Setting.MountPoint + TEXT("/");
				break;
			}
		}
	}
	if (ProjectURIRoot.IsEmpty())
	{
		ProjectURIRoot = GetDefault<UNoesisEditorUserSettings>()->GetProjectURIRoot();
		BasePackageName = TEXT("/Game/");
	}
	FPaths::MakePathRelativeTo(Directory, *ProjectURIRoot);

	FString XamlText = NsStringToFString((const char*)Buffer);

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
	ImportXamls(BasePackageName, ProjectURIRoot, Directory, XamlDescriptors);
	for (auto XamlDescriptor : XamlDescriptors)
	{
		if (!XamlDescriptor.Xaml)
		{
			UE_LOG(LogNoesisEditor, Log, TEXT("Error importing XAML file %s: Referenced XAML file %s not found."), *GetCurrentFilename(), *XamlDescriptor.Path);
		}
	}

	TArray<FFontDescriptor> FontDescriptors = ParseForFonts(XamlText);
	ImportFonts(BasePackageName, ProjectURIRoot, Directory, FontDescriptors);
	for (auto FontDescriptor : FontDescriptors)
	{
		if (!FontDescriptor.Font)
		{
			UE_LOG(LogNoesisEditor, Log, TEXT("Error importing XAML file %s: Referenced font family %s not found."), *GetCurrentFilename(), *FontDescriptor.Family);
		}
	}

	TArray<FImageDescriptor> ImageDescriptors = ParseForImages(XamlText);
	ImportImages(BasePackageName, ProjectURIRoot, Directory, ImageDescriptors);
	for (auto ImageDescriptor : ImageDescriptors)
	{
		if (!ImageDescriptor.Texture)
		{
			UE_LOG(LogNoesisEditor, Log, TEXT("Error importing XAML file %s: Referenced image file %s not found."), *GetCurrentFilename(), *ImageDescriptor.Path);
		}
	}

	UNoesisXaml* NoesisXaml = nullptr;

	{
		FString XamlPath;
		FString FileName;
		FString PackagePath;
		FString XamlName;
		ExtractPaths(Filename, Directory, BasePackageName, ProjectURIRoot, XamlPath, FileName, PackagePath, XamlName);

		UPackage* XamlPackage = NULL;

		FString XamlObjectPath = PackagePath / XamlName + TEXT(".") + XamlName;
		UNoesisXaml* ExistingXaml = LoadObject<UNoesisXaml>(NULL, *XamlObjectPath);

		if (!ExistingXaml)
		{
			const FString Suffix(TEXT(""));

			XamlPackage = CreatePackage(NULL, *(PackagePath / XamlName));
			NoesisXaml = NewObject<UNoesisXaml>(XamlPackage, Class, Name, Flags);
		}
		else
		{
			XamlPackage = ExistingXaml->GetOutermost();
			XamlPackage->FullyLoad();
			ExistingXaml->DestroyThumbnailRenderData();
			NoesisXaml = ExistingXaml;
			NoesisXaml->XamlText.Empty();
			NoesisXaml->Xamls.Empty();
			NoesisXaml->Textures.Empty();
			NoesisXaml->Fonts.Empty();
		}
	}

	for (auto XamlDescriptor : XamlDescriptors)
	{
		if (XamlDescriptor.Xaml)
		{
			FString XamlPath = XamlDescriptor.Xaml->GetPathName();
			XamlText = XamlText.Replace(*XamlDescriptor.Path, *XamlPath);
			NoesisXaml->Xamls.Add(XamlDescriptor.Xaml);
		}
	}

	for (auto FontDescriptor : FontDescriptors)
	{
		if (FontDescriptor.Font)
		{
			FString FontPath = FontDescriptor.Font->GetPathName();
			FString Uri, Family;
			ensure(FontDescriptor.Family.Split(TEXT("#"), &Uri, &Family));
			XamlText = XamlText.Replace(*FontDescriptor.Family, *(FontPath / TEXT("#") + Family));
			NoesisXaml->Fonts.Add(FontDescriptor.Font);
		}
	}

	for (auto ImageDescriptor : ImageDescriptors)
	{
		if (ImageDescriptor.Texture)
		{
			FString ImagePath = ImageDescriptor.Texture->GetPathName();
			XamlText = XamlText.Replace(*ImageDescriptor.Path, *ImagePath);
			NoesisXaml->Textures.Add(ImageDescriptor.Texture);
		}
	}

	NsString AmmendedXamlText = TCHARToNsString(*XamlText);
	NoesisXaml->XamlText.Insert((uint8*)AmmendedXamlText.c_str(), AmmendedXamlText.length(), 0);
	NoesisXaml->Xamls.Add(NoesisXaml);

	NoesisXaml->LoadXaml();

	NoesisXaml->AssetImportData->Update(FullFilename);

	return NoesisXaml;
}
