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

unsigned long StreamRead(FT_Stream Stream, unsigned long Offset, unsigned char* Buffer, unsigned long Count)
{
	FMemory::Memcpy(Buffer, (uint8*)Stream->descriptor.pointer + Offset, Count);
	return Count;
}

void StreamClose(FT_Stream) {}

UFont* ImportFontFamily(FString Path, FString Family, FString BasePackageName, FString ProjectURIRoot)
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

			return Font;
		}
	}

	return nullptr;
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
		ProjectURIRoot = FPaths::ProjectContentDir();
		BasePackageName = TEXT("/Game/");
	}
	FPaths::MakePathRelativeTo(Directory, *ProjectURIRoot);

	FString XamlText = NsStringToFString((const char*)Buffer);

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

	NsString Text = TCHARToNsString(*XamlText);

	Noesis::MemoryStream XamlStream(Text.c_str(), Text.length());
	TArray<NsString> Dependencies;
	auto DependencyCallback = [](void* UserData, const char* URI)
	{
		TArray<NsString>& Dependencies = *(TArray<NsString>*)UserData;
		Dependencies.AddUnique(URI);
	};
	Noesis::GUI::GetXamlDependencies(&XamlStream, &Dependencies, DependencyCallback);

	FAssetToolsModule& AssetToolsModule = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>("AssetTools");
	UAutomatedAssetImportData* AutomatedAssetImportData = NewObject<UAutomatedAssetImportData>();
	AutomatedAssetImportData->bReplaceExisting = true;
	for (auto& Dependency : Dependencies)
	{
		NsString::size_type hashPos = Dependency.find('#');
		if (hashPos != NsString::npos)
		{
			FString Family = NsStringToFString(Dependency.c_str());
			UFont* Font = ImportFontFamily(Directory, Family, BasePackageName, ProjectURIRoot);

			if (Font)
			{
				FString FontPath = Font->GetPathName();
				XamlText = XamlText.Replace(*Family, *(FontPath / TEXT("#") + NsStringToFString(Dependency.c_str() + hashPos + 1)));
				NoesisXaml->Fonts.Add(Font);
			}
		}
		else
		{
			FString DependencyPath;
			FString FileName;
			FString PackagePath;
			FString DependencyName;
			ExtractPaths(Dependency.c_str(), Directory, BasePackageName, ProjectURIRoot, DependencyPath, FileName, PackagePath, DependencyName);

			AutomatedAssetImportData->Filenames.Empty(1);
			AutomatedAssetImportData->Filenames.Add(DependencyPath / FileName);
			AutomatedAssetImportData->DestinationPath = PackagePath;
			TArray<UObject*> Assets = AssetToolsModule.Get().ImportAssetsAutomated(AutomatedAssetImportData);


			for (auto Asset : Assets)
			{
				if (UTexture2D* Texture = Cast<UTexture2D>(Asset))
				{
					Texture->LODGroup = TEXTUREGROUP_UI;
					Texture->SRGB = false;
					void FixPremultipliedPNGTexture(UTexture2D*);
					FixPremultipliedPNGTexture(Texture);

					FString ImagePath = Texture->GetPathName();
					XamlText = XamlText.Replace(*NsStringToFString(Dependency.c_str()), *ImagePath);
					NoesisXaml->Textures.Add(Texture);
				}
				else if (UNoesisXaml* Xaml = Cast<UNoesisXaml>(Asset))
				{
					FString XamlPath = Xaml->GetPathName();
					XamlText = XamlText.Replace(*NsStringToFString(Dependency.c_str()), *XamlPath);
					NoesisXaml->Xamls.Add(Xaml);
				}
				else if (USoundWave* Sound = Cast<USoundWave>(Asset))
				{
					FString SoundPath = Sound->GetPathName();
					XamlText = XamlText.Replace(*NsStringToFString(Dependency.c_str()), *SoundPath);
					NoesisXaml->Sounds.Add(Sound);
				}
			}
		}
	}

	NsString AmmendedXamlText = TCHARToNsString(*XamlText);
	NoesisXaml->XamlText.Insert((uint8*)AmmendedXamlText.c_str(), AmmendedXamlText.length(), 0);
	NoesisXaml->Xamls.Add(NoesisXaml);

	NoesisXaml->LoadXaml();

	NoesisXaml->AssetImportData->Update(FullFilename);

	return NoesisXaml;
}
