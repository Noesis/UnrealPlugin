////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisXamlFactory.h"

// AssetRegistry includes
#include "AssetRegistryModule.h"

// AssetTools includes
#include "AssetToolsModule.h"

// Core includes
#include "CoreMinimal.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "HAL/PlatformFilemanager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

// Engine includes
#include "EditorFramework/AssetImportData.h"
#include "Engine/FontFace.h"
#include "Engine/Texture2D.h"
#include "Sound/SoundWave.h"

// FreeType2 includes
THIRD_PARTY_INCLUDES_START
#include "ft2build.h"
#include FT_FREETYPE_H
THIRD_PARTY_INCLUDES_END

// MediaAssets includes
#include "MediaSource.h"

// UnrealEd includes
#include "Editor.h"
#include "ObjectTools.h"
#include "Factories/FontFileImportFactory.h"
#include "Settings/EditorLoadingSavingSettings.h"
#include "Subsystems/ImportSubsystem.h"

// NoesisRuntime includes
#include "NoesisRuntimeModule.h"
#include "NoesisSettings.h"
#include "NoesisXaml.h"
#include "Extensions/LocTableExtension.h"
#include "Extensions/LocTextExtension.h"

// NoesisEditor includes
#include "NoesisEditorModule.h"

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

TArray<UFontFace*> ImportFontFamily(FString PackagePath, FString FamilyName, FString Directory)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	class ScanFolderForFonts : public IPlatformFile::FDirectoryVisitor
	{
	public:
		FString FontPackagePath;
		FString FamilyName;
		TArray<UFontFace*> Fonts;
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

										if (ExistingFontFace)
										{
											Fonts.AddUnique(ExistingFontFace);
											FT_Done_Face(SubFace);
											continue;
										}
										FontFacePackage = CreatePackage(*(FontPackagePath / FontFaceName));

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

										// Add a default typeface referencing the newly created font face
										Fonts.AddUnique(FontFace);
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
	return Visitor.Fonts;
}

static void SplitPath(FString Path, TArray<FString>& Components)
{
	FString Left, Right;
	while (Path.Split(TEXT("/"), &Left, &Right))
	{
		Components.Push(MoveTemp(Left));
		Path = MoveTemp(Right);
	}
}

static void JoinPath(TArray<FString> Components, FString & Path)
{
	for (auto Component : Components)
	{
		Path += Component;
		Path += TEXT("/");
	}
}

TMap<void*, TArray<FText>> UnrealTexts;
class LocTextExtensionEditor : public LocTextExtension
{
	FText GetText()
	{
		const char* ns = GetNamespace();
		if (strlen(ns) == 0)
		{
			Noesis::IUITreeNode* node = Noesis::DynamicCast<Noesis::IUITreeNode*>(this);
			while (node != nullptr)
			{
				Noesis::DependencyObject* object = Noesis::DynamicCast<Noesis::DependencyObject*>(node);
				if (object != nullptr)
				{
					ns = object->GetValue<Noesis::String>(NamespaceProperty).Str();
					if (strlen(ns) > 0)
						break;
				}
				node = node->GetNodeParent();
			}
		}
		return FText::ChangeKey(UTF8_TO_TCHAR(ns), UTF8_TO_TCHAR(GetKey()), FText::FromString(UTF8_TO_TCHAR(GetSource())));
	}

	/// From MarkupExtension
	//@{
	Noesis::Ptr<Noesis::BaseComponent> ProvideValue(const Noesis::ValueTargetProvider* provider) override
	{
		Noesis::IUITreeNode* TextNode = Noesis::DynamicCast<Noesis::IUITreeNode*>(this);
		void* Ptr = Noesis::GetNodeRoot(TextNode);
		UnrealTexts.FindOrAdd(Ptr).Add(GetText());
		return nullptr;
	}
	//@}

};

static Noesis::BaseComponent* CreateLocText(Noesis::Symbol)
{
	return new LocTextExtensionEditor();
};

class LocTableExtensionEditor : public LocTableExtension
{
	FText GetText()
	{
		const char* id = GetId();
		if (strlen(id) == 0)
		{
			Noesis::IUITreeNode* node = Noesis::DynamicCast<Noesis::IUITreeNode*>(this);
			while (node != nullptr)
			{
				Noesis::DependencyObject* object = Noesis::DynamicCast<Noesis::DependencyObject*>(node);
				if (object != nullptr)
				{
					id = object->GetValue<Noesis::String>(IdProperty).Str();
					if (strlen(id) > 0)
						break;
				}
				node = node->GetNodeParent();
			}
		}

		return FText::FromStringTable(UTF8_TO_TCHAR(id), UTF8_TO_TCHAR(GetKey()), EStringTableLoadingPolicy::FindOrLoad);
	}

	/// From MarkupExtension
	//@{
	Noesis::Ptr<Noesis::BaseComponent> ProvideValue(const Noesis::ValueTargetProvider* provider) override
	{
		Noesis::IUITreeNode* TextNode = Noesis::DynamicCast<Noesis::IUITreeNode*>(this);
		void* Ptr = Noesis::GetNodeRoot(TextNode);
		UnrealTexts.FindOrAdd(Ptr).Add(GetText());
		return nullptr;
	}
	//@}

};

static Noesis::BaseComponent* CreateLocTable(Noesis::Symbol)
{
	return new LocTableExtensionEditor();
};

UObject* UNoesisXamlFactory::FactoryCreateBinary(UClass* Class, UObject* Parent, FName Name, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const uint8*& Buffer, const uint8* BufferEnd, FFeedbackContext* Warn)
{
	// This needs to go first, before we invoke other factories, since they're stored in UFactory statics.
	FString FullFilePath = GetCurrentFilename();
	FMD5Hash CurrentFileHash = FileHash;

	// This function is invoked for first time imports as well as for reimports.
	// Reimports can be caused by a change in content, via auto-reimport, or manually by the user.
	// When the XAML is first imported, or when the content has changed, we need to reparse it for dependencies.
	// We want to do that for reimports, even if the content hasn't changed, to fix dependencies that were broken when first imported.
	// We also want to make sure the ApplicationResources are up to date, so we don't get false errors during the LoadXaml at the end.
	// But we don't want to reparse all the dependent XAMLs. So we use this static variable that ensures that:
	// The first level XAML that is imported gets it's dependecies checked, even if it's a reimport and the contents haven't changed.
	// The first level XAML also makes sure the ApplicationResources are up to date.
	// The rest of the dependent XAMLs are traversed recursively, but only updated if the contents have changed.
	// We use this static variable to achieve that. We store it in a local variable to use inside the function and restore it at the end.
	// It's going to be false only for the first level XAML, false for all the rest.
	// Note: This still means that if multiple XAMLs are reimported the ApplicationResources will be checked for all of them,
	// but not for their dependencies, which is still a win.
	static bool StaticRecursive = false;
	bool Recursive = StaticRecursive;
	StaticRecursive = true;

	if (!Recursive)
	{
		UNoesisXaml* ApplicationResources = Cast<UNoesisXaml>(GetDefault<UNoesisSettings>()->ApplicationResources.TryLoad());
		if (ApplicationResources)
		{
			FReimportManager::Instance()->Reimport(ApplicationResources);
		}
	}

	UNoesisXaml* ExistingXaml = LoadObject<UNoesisXaml>(Parent, *Name.ToString());
	bool HasChanged = true;
	
	if (ExistingXaml != nullptr && ExistingXaml->AssetImportData != nullptr)
	{
		const FAssetImportInfo& ImportInfo = ExistingXaml->AssetImportData->GetSourceData();
		if (ImportInfo.SourceFiles.Num() > 0 && ImportInfo.SourceFiles[0].FileHash == CurrentFileHash)
		{
			HasChanged = false;
		}
	}

	UNoesisXaml* NoesisXaml = nullptr;
	if (!Recursive || HasChanged)
	{
		FString PackageRoot;
		FString PackagePath;
		FString PackageName;
		FPackageName::SplitLongPackageName(Parent->GetPathName(), PackageRoot, PackagePath, PackageName, false);
		TArray<FString> ProjectAssetPathRootComponents;
		SplitPath(PackageRoot + PackagePath, ProjectAssetPathRootComponents);
		TArray<FString> ProjectURIRootComponents;
		SplitPath(FPaths::GetPath(FullFilePath) + TEXT("/"), ProjectURIRootComponents);
		while (ProjectAssetPathRootComponents.Last() == ProjectURIRootComponents.Last())
		{
			ProjectAssetPathRootComponents.Pop();
			ProjectURIRootComponents.Pop();
		}
		FString ProjectAssetPathRoot;
		JoinPath(ProjectAssetPathRootComponents, ProjectAssetPathRoot);
		FString ProjectURIRoot;
		JoinPath(ProjectURIRootComponents, ProjectURIRoot);

		NoesisXaml = NewObject<UNoesisXaml>(Parent, Class, Name, Flags);

		FString XamlText = UTF8_TO_TCHAR((const char*)Buffer);
		Noesis::String Text = TCHAR_TO_UTF8(*XamlText);
		Noesis::MemoryStream XamlStream(Text.Str(), Text.Size());

		INoesisRuntimeModuleInterface& NoesisRuntime = INoesisRuntimeModuleInterface::Get();
		FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
		FAssetToolsModule& AssetToolsModule = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>("AssetTools");
		UAutomatedAssetImportData* AutomatedAssetImportData = NewObject<UAutomatedAssetImportData>();
		AutomatedAssetImportData->bReplaceExisting = true;
		IFileManager& FileManager = IFileManager::Get();
		auto DependencyCallback = [&](void* UserData, const Noesis::Uri& Uri, Noesis::XamlDependencyType Type)
		{
			if (Type == Noesis::XamlDependencyType_Root) return;

			// If the URI is invalid, ImportAssetsAutomated will try to reimport the whole directory
			// causing infinite recursion.
			if (!Uri.IsValid()) return;
			
			Noesis::String UriPath;
			Uri.GetPath(UriPath);
			FString Dependency = Uri.IsAbsolute() && UriPath.StartsWith("Game/") ? "/" : "";
			Dependency += UTF8_TO_TCHAR(UriPath.Str());

			if (Type == Noesis::XamlDependencyType_Font)
			{
				int32 HashPos = INDEX_NONE;
				Dependency.FindChar(TEXT('#'), HashPos);
				if (HashPos != INDEX_NONE) // only local fonts are set as dependencies, system fonts are ignored here
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

					TArray<UFontFace*> FontFaces = ImportFontFamily(PackagePath, FamilyName, FilePath);

					if (FontFaces.Num())
					{
						NoesisXaml->FontFaces.Append(FontFaces);
						for (auto FontFace : FontFaces)
						{
							NoesisRuntime.RegisterFont(FontFace);
						}
					}
					else
					{
						UE_LOG(LogNoesisEditor, Error, TEXT("Failed to import font family %s from %s"), *FamilyName, *FilePath);
					}
				}
			}
			else
			{
				bool IsUserControl = Type == Noesis::XamlDependencyType_UserControl;
				if (IsUserControl)
				{
					FString PackagePath = FPaths::GetPath(Parent->GetPathName());
					Dependency = PackagePath / Dependency + TEXT(".xaml");
				}

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
				TArray<FAssetData> FoundAssets;
				AssetRegistryModule.Get().GetAssetsByPackageName(*AssetPath, FoundAssets);
				if (FoundAssets.Num() > 0 && FoundAssets[0].GetClass() != UNoesisXaml::StaticClass())
				{
					for (auto FoundAsset : FoundAssets)
					{
						UObject* Asset = FoundAsset.GetAsset();
						if (UTexture2D* Texture = Cast<UTexture2D>(Asset))
						{
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
						else if (UMediaSource* Video = Cast<UMediaSource>(Asset))
						{
							NoesisXaml->Videos.Add(Video);
						}
						else if (UMaterialInterface* Material = Cast<UMaterialInterface>(Asset))
						{
							NoesisXaml->Materials.Add(Material);
						}
					}
					return;
				}
				TArray<UObject*> Assets;
				if (FoundAssets.Num() == 0)
				{
					if (!IsUserControl || FileManager.FileExists(*FilePath))
					{
						AutomatedAssetImportData->Filenames.Empty(1);
						AutomatedAssetImportData->Filenames.Add(FilePath);
						AutomatedAssetImportData->DestinationPath = Path;
						Assets = AssetToolsModule.Get().ImportAssetsAutomated(AutomatedAssetImportData);
					}
				}
				else
				{
					for (auto FoundAsset : FoundAssets)
					{
						UNoesisXaml* Asset = Cast<UNoesisXaml>(FoundAsset.GetAsset());
						if (Asset != nullptr)
						{
							FReimportManager::Instance()->Reimport(Asset);
						}
						Assets.Add(Asset);
					}
				}

				if (!IsUserControl && Assets.Num() == 0)
				{
					UE_LOG(LogNoesisEditor, Error, TEXT("Failed to import %s"), *FilePath);
				}

				for (auto Asset : Assets)
				{
					if (UTexture2D* Texture = Cast<UTexture2D>(Asset))
					{
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
					else if (UMediaSource* Video = Cast<UMediaSource>(Asset))
					{
						NoesisXaml->Videos.Add(Video);
					}
					else if (UMaterialInterface* Material = Cast<UMaterialInterface>(Asset))
					{
						NoesisXaml->Materials.Add(Material);
					}
				}
			}
		};
		auto DependencyCallbackAdaptor = [](void* UserData, const Noesis::Uri& Uri, Noesis::XamlDependencyType Type)
		{
			auto Callback = (decltype(DependencyCallback)*)UserData;
			return (*Callback)(nullptr, Uri, Type);
		};
		Noesis::Uri Uri(TCHAR_TO_UTF8(*NoesisXaml->GetPathName()));
		Noesis::GUI::GetXamlDependencies(&XamlStream, Uri, &DependencyCallback, DependencyCallbackAdaptor);

		NoesisXaml->XamlText.Insert((uint8*)Text.Str(), Text.Size(), 0);

		NoesisXaml->AssetImportData->Update(FullFilePath);
	}
	else
	{
		NoesisXaml = ExistingXaml;

		for (auto Xaml : NoesisXaml->Xamls)
		{
			if (Xaml != nullptr)
			{
				FReimportManager::Instance()->Reimport(Xaml);
			}
		}
	}

	// Make sure textures have alpha premultiplied if the user needs them, or are cleaned if they already are
	for (auto Texture : NoesisXaml->Textures)
	{
		if (Texture->LODGroup != TEXTUREGROUP_UI ||
			Texture->SRGB)
		{
			Texture->LODGroup = TEXTUREGROUP_UI;
			Texture->SRGB = false;

			// We notify the change in one of the two properties, so that the callback in NoesisEditorModule
			// triggers a reimport and premultiplies the alpha, if needed.
			FPropertyChangedEvent ChangeEvent(UTexture::StaticClass()->FindPropertyByName("LODGroup"));
			FCoreUObjectDelegates::OnObjectPropertyChanged.Broadcast(Texture, ChangeEvent);
		}
	}

	if (!Recursive)
	{
		UnrealTexts.Empty();
		Noesis::UnregisterComponent<LocTextExtension>();
		const Noesis::Type* LocTextType = Noesis::TypeOf<LocTextExtension>();
		Noesis::Factory::RegisterComponent(LocTextType->GetTypeId(), Noesis::Symbol::Null(), CreateLocText);
		Noesis::UnregisterComponent<LocTableExtension>();
		const Noesis::Type* LocTableType = Noesis::TypeOf<LocTableExtension>();
		Noesis::Factory::RegisterComponent(LocTableType->GetTypeId(), Noesis::Symbol::Null(), CreateLocTable);

		// Show parsing errors in the console
		Noesis::Ptr<Noesis::IUITreeNode> Root = Noesis::DynamicPtrCast<Noesis::IUITreeNode>(NoesisXaml->LoadXaml());

		NoesisXaml->Texts.Empty();
		for (auto Text : UnrealTexts.FindOrAdd(Root))
		{
			NoesisXaml->Texts.Add(Text);
		}

		Noesis::UnregisterComponent<LocTextExtension>();
		Noesis::RegisterComponent<LocTextExtension>();
		Noesis::UnregisterComponent<LocTableExtension>();
		Noesis::RegisterComponent<LocTableExtension>();
	}

	StaticRecursive = Recursive;

	// If this is not the first level XAML and nothing has changed we return null here so that the
	// dependent XAMLs are not marked dirty.
	if (!Recursive || HasChanged)
	{
		// We need this so our own callback is called for hot reloading, but it's alo something all
		// factories do.
		GEditor->GetEditorSubsystem<UImportSubsystem>()->BroadcastAssetPostImport(this, NoesisXaml);

		return NoesisXaml;
	}

	return nullptr;
}
