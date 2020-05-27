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

unsigned long StreamRead(FT_Stream Stream, unsigned long Offset, unsigned char* Buffer, unsigned long Count)
{
	FMemory::Memcpy(Buffer, (uint8*)Stream->descriptor.pointer + Offset, Count);
	return Count;
}

void StreamClose(FT_Stream) {}

UFont* ImportFontFamily(FString PackagePath, FString FamilyName, FString Directory)
{
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
				if (Extension == TEXT("ttf") || Extension == TEXT("otf") || Extension == TEXT("ttc"))
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
									FString FaceFamilyName = SubFace->family_name;
									FaceFamilyName.TrimStartAndEndInline();
									if (FaceFamilyName == FamilyName)
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

	ScanFolderForFonts Visitor(PackagePath, FamilyName);
	PlatformFile.IterateDirectory(*Directory, Visitor);

	if (Visitor.Fonts.Num())
	{
		UPackage* FontPackage = NULL;

		FString FontName = ObjectTools::SanitizeObjectName(FamilyName + TEXT("_Font"));
		FString FontObjectPath = PackagePath / FontName + TEXT(".") + FontName;
		UFont* ExistingFont = LoadObject<UFont>(NULL, *FontObjectPath);

		if (!ExistingFont)
		{
			const FString Suffix(TEXT(""));

			FontPackage = CreatePackage(NULL, *(PackagePath / FontName));
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
	FString FullFilePath = GetCurrentFilename();
	FString ProjectURIRoot;
	FString ProjectAssetPathRoot;
	for (const auto& Setting : GetDefault<UEditorLoadingSavingSettings>()->AutoReimportDirectorySettings)
	{
		FString RelativeFilename = FullFilePath;
		FString SourceDirectory = Setting.SourceDirectory + TEXT("/");
		if (FPaths::MakePathRelativeTo(RelativeFilename, *SourceDirectory))
		{
			FPaths::CollapseRelativeDirectories(RelativeFilename);
			FPaths::NormalizeFilename(RelativeFilename);
			if (!RelativeFilename.StartsWith(TEXT("..")))
			{
				ProjectURIRoot = SourceDirectory;
				ProjectAssetPathRoot = Setting.MountPoint + TEXT("/");
				break;
			}
		}
	}
	if (ProjectURIRoot.IsEmpty())
	{
		FString PackageRoot;
		FString PackagePath;
		FString PackageName;
		FPackageName::SplitLongPackageName(Parent->GetPathName(), PackageRoot, PackagePath, PackageName, false);
		ProjectAssetPathRoot = PackageRoot;
		FPackageName::TryConvertLongPackageNameToFilename(PackageRoot, ProjectURIRoot);
	}

	UNoesisXaml* NoesisXaml = NewObject<UNoesisXaml>(Parent, Class, Name, Flags);
	/*NoesisXaml->DestroyThumbnailRenderData();
	NoesisXaml->XamlText.Empty();
	NoesisXaml->Xamls.Empty();
	NoesisXaml->Textures.Empty();
	NoesisXaml->Fonts.Empty();*/

	FString XamlText = NsStringToFString((const char*)Buffer);
	Noesis::String Text = TCHARToNsString(*XamlText);
	Noesis::MemoryStream XamlStream(Text.Str(), Text.Size());
	auto DependencyCallback = [](void* UserData, const char* URI, Noesis::XamlDependencyType Type)
	{
		TArray<FString>& Dependencies = *(TArray<FString>*)UserData;
		FString Dependency = NsStringToFString(URI);
		if (Type == Noesis::XamlDependencyType_Filename || Type == Noesis::XamlDependencyType_Font)
		{
			Dependencies.AddUnique(Dependency);
		}
	};
	TArray<FString> Dependencies;
	FString XamlPackagePath = FPackageName::GetLongPackagePath(NoesisXaml->GetPathName());
	Noesis::GUI::GetXamlDependencies(&XamlStream, TCHARToNsString(*XamlPackagePath).Str(), &Dependencies, DependencyCallback);

	INoesisRuntimeModuleInterface& NoesisRuntime = INoesisRuntimeModuleInterface::Get();
	FAssetToolsModule& AssetToolsModule = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>("AssetTools");
	UAutomatedAssetImportData* AutomatedAssetImportData = NewObject<UAutomatedAssetImportData>();
	AutomatedAssetImportData->bReplaceExisting = true;
	for (auto& Dependency : Dependencies)
	{
		int32 HashPos = INDEX_NONE;
		Dependency.FindChar(TEXT('#'), HashPos);
		if (HashPos != INDEX_NONE)
		{
			FString PackagePath, FamilyName;
			Dependency.Split(TEXT("#"), &PackagePath, &FamilyName);

			FString Path = FPaths::GetPath(PackagePath);
			FString Filename = FPaths::GetBaseFilename(PackagePath);
			FString Extension = FPaths::GetExtension(PackagePath);
			FString AssetPath = Path / ObjectTools::SanitizeInvalidChars(Filename, INVALID_LONGPACKAGE_CHARACTERS);
			FString FilePath = PackagePath.Replace(*ProjectAssetPathRoot, *ProjectURIRoot);
			if (!FPackageName::IsValidLongPackageName(AssetPath / "_Font"))
			{
				AssetPath = FString("/Game/") + AssetPath;
				PackagePath = FString("/Game/") + PackagePath;
				FilePath = PackagePath.Replace(*ProjectAssetPathRoot, *ProjectURIRoot);
				Path = FString("/Game/") + Path;
			}

			UFont* Font = ImportFontFamily(PackagePath, FamilyName, FilePath);

			if (Font)
			{
				NoesisXaml->Fonts.Add(Font);
				NoesisRuntime.RegisterFont(Font);
			}
			else
			{
				UE_LOG(LogNoesisEditor, Error, TEXT("Failed to import font family %s from %s"), *FamilyName, *FilePath);
			}
		}
		else
		{
			FString Path = FPaths::GetPath(Dependency);
			FString Filename = FPaths::GetBaseFilename(Dependency);
			FString Extension = FPaths::GetExtension(Dependency);
			FString AssetPath = Path / ObjectTools::SanitizeInvalidChars(Filename, INVALID_LONGPACKAGE_CHARACTERS);
			FString FilePath = Dependency.Replace(*ProjectAssetPathRoot, *ProjectURIRoot);
			if (!FPackageName::IsValidLongPackageName(AssetPath))
			{
				AssetPath = FString("/Game/") + AssetPath;
				Dependency = FString("/Game/") + Dependency;
				FilePath = Dependency.Replace(*ProjectAssetPathRoot, *ProjectURIRoot);
				Path = FString("/Game/") + Path;
			}
			AutomatedAssetImportData->Filenames.Empty(1);
			AutomatedAssetImportData->Filenames.Add(FilePath);
			AutomatedAssetImportData->DestinationPath = Path;
			TArray<UObject*> Assets = AssetToolsModule.Get().ImportAssetsAutomated(AutomatedAssetImportData);

			if (Assets.Num() == 0)
			{
				UE_LOG(LogNoesisEditor, Error, TEXT("Failed to import %s"), *FilePath);
			}

			for (auto Asset : Assets)
			{
				if (UTexture2D* Texture = Cast<UTexture2D>(Asset))
				{
					Texture->LODGroup = TEXTUREGROUP_UI;
					Texture->SRGB = false;
					void FixPremultipliedPNGTexture(UTexture2D*);
					FixPremultipliedPNGTexture(Texture);

					NoesisXaml->Textures.Add(Texture);
				}
				else if (UNoesisXaml* Xaml = Cast<UNoesisXaml>(Asset))
				{
					NoesisXaml->Xamls.Add(Xaml);
				}
				else if (USoundWave* Sound = Cast<USoundWave>(Asset))
				{
					NoesisXaml->Sounds.Add(Sound);
				}
			}
		}
	}

	NoesisXaml->XamlText.Insert((uint8*)Text.Str(), Text.Size(), 0);

	NoesisXaml->LoadXaml();

	NoesisXaml->AssetImportData->Update(FullFilePath);

	return NoesisXaml;
}
