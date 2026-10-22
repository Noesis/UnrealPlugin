////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisXamlFactory.h"

// AssetRegistry includes
#include "AssetRegistry/AssetRegistryModule.h"

// AssetTools includes
#include "AssetToolsModule.h"

// Core includes
#include "CoreMinimal.h"
#include "Misc/EngineVersionComparison.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "HAL/PlatformFileManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

// Engine includes
#include "EditorFramework/AssetImportData.h"
#include "Engine/FontFace.h"
#include "Engine/Texture2D.h"
#include "Sound/SoundWave.h"
#include "Materials/MaterialInterface.h"

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
#include "NoesisSupport.h"
#include "NoesisXaml.h"
#include "NoesisRive.h"
#include "NoesisAssetDependency.h"
#include "Extensions/LocTableExtension.h"
#include "Extensions/LocTextExtension.h"

// NoesisEditor includes
#include "NoesisEditorModule.h"

// Projects includes
#include "Interfaces/IPluginManager.h"

UNoesisXamlFactory::UNoesisXamlFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bEditorImport = true;
	bEditAfterNew = true;
	SupportedClass = UNoesisXaml::StaticClass();
	Formats.Add(TEXT("xaml;NoesisGUI XAML"));
}

TArray<UFontFace*> ImportFontFamily(FString PackagePath, FString FamilyName, FString Directory)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	class ScanFolderForFonts : public IPlatformFile::FDirectoryVisitor
	{
	public:
		FString FontPackagePath;
		FString FamilyName;
		TArray<UFontFace*> Fonts;

		ScanFolderForFonts(FString InFontPackagePath, FString InFamilyName)
			: FontPackagePath(InFontPackagePath), FamilyName(InFamilyName)
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
				if (Extension == TEXT("ttf") || Extension == TEXT("otf") || Extension == TEXT("ttc"))
				{
					TArray<uint8> FileData;
					if (FFileHelper::LoadFileToArray(FileData, FilenameOrDirectory))
					{
						Noesis::MemoryStream Stream(FileData.GetData(), FileData.Num());
						Noesis::Fonts::GetTypefaces(&Stream, [&](const Noesis::Typeface& typeface)
						{
							if (Noesis::StrCaseStartsWith((ANSICHAR*)StringCast<UTF8CHAR>(*FamilyName).Get(), typeface.familyName))
							{
								FString FontFaceName = ObjectTools::SanitizeObjectName(FPaths::GetBaseFilename(FPaths::GetBaseFilename(FilenameOrDirectory)));

								UPackage* FontFacePackage = NULL;

								FString FontFaceObjectPath = FontPackagePath / FontFaceName + TEXT(".") + FontFaceName;
								UFontFace* ExistingFontFace = LoadObject<UFontFace>(NULL, *FontFaceObjectPath);

								if (ExistingFontFace)
								{
									Fonts.AddUnique(ExistingFontFace);
									return;
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
						});
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
		return FText::ChangeKey(StringCast<TCHAR>((UTF8CHAR*)ns).Get(), StringCast<TCHAR>((UTF8CHAR*)GetKey()).Get(), FText::FromString(StringCast<TCHAR>((UTF8CHAR*)GetSource()).Get()));
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

		return FText::FromStringTable(StringCast<TCHAR>((UTF8CHAR*)id).Get(), StringCast<TCHAR>((UTF8CHAR*)GetKey()).Get(), EStringTableLoadingPolicy::FindOrLoad);
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

FString GetDependencyPath(const Noesis::Uri& Uri)
{
	FString Dependency;

	Noesis::String Assembly;
	Uri.GetAssembly(Assembly);
	if (!Assembly.Empty())
	{
		Dependency += TEXT("/");
		Dependency += GetAssetRoot(Assembly).Str();
		Dependency += TEXT("/");
	}

	Noesis::FixedString<512> Path;
	Uri.GetPath(Path);
	Dependency += Path.Str();

	return Dependency;
}

FString GetDependencyExtension(const Noesis::Uri& Uri)
{
	Noesis::FixedString<512> Path;
	Uri.GetPath(Path);
	int32 Extension = Noesis::StrFindLast(Path.Str(), ".");
	if (Extension != INDEX_NONE)
	{
		return (UTF8CHAR*)Path.Begin() + Extension;
	}

	return "";
}

void ConfigureFilter(FARFilter& Filter, UClass* Class, bool RecursiveClasses)
{
	Filter.bRecursiveClasses = RecursiveClasses;
#if UE_VERSION_OLDER_THAN(5, 1, 0)
	Filter.ClassNames.Add(Class->GetFName());
#else
	Filter.ClassPaths.Add(Class->GetClassPathName());
#endif

	Filter.bRecursivePaths = true;
	Filter.PackagePaths.Add(TEXT("/Game"));

	TArray<TSharedRef<IPlugin>> Plugins = IPluginManager::Get().GetEnabledPluginsWithContent();
	for (auto Plugin : Plugins)
	{
		FString PluginPath = TEXT("/") + Plugin->GetName();
		Filter.PackagePaths.Add(*PluginPath);
	}
}

static FString RelativizeImportFilename(const FString& InPath, const FString& PackagePath)
{
	if (!PackagePath.IsEmpty())
	{
		const bool		bIncludeDot = true;
		const FName		MountPoint = FPackageName::GetPackageMountPoint(PackagePath);
		const FString	PackageFilename = FPackageName::LongPackageNameToFilename(PackagePath, FPaths::GetExtension(InPath, bIncludeDot));
		const FString	AbsolutePath = FPaths::ConvertRelativePathToFull(InPath);
		auto Plugin = IPluginManager::Get().FindPlugin(*MountPoint.ToString());

		if ((MountPoint == FName("Engine") && AbsolutePath.StartsWith(FPaths::ConvertRelativePathToFull(FPaths::EngineContentDir()))) ||
			(MountPoint == FName("Game") && AbsolutePath.StartsWith(FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()))) ||
			(Plugin && AbsolutePath.StartsWith(FPaths::ConvertRelativePathToFull(Plugin->GetBaseDir()))))
		{
			FString RelativePath = InPath;
			FPaths::MakePathRelativeTo(RelativePath, *PackageFilename);
			return RelativePath;
		}
	}

	return InPath;
}

static UObject* EnsureDependency(UNoesisXaml* NoesisXaml, FString AssetPath, FString FilePath)
{
	if (UE::String::FindFirstChar(AssetPath, TEXT('.')) == INDEX_NONE)
	{
		AssetPath += TEXT(".") + FPackageName::GetShortName(AssetPath);
	}

	UObject* Asset = LoadObject<UObject>(nullptr, *AssetPath, nullptr, LOAD_NoWarn | LOAD_Quiet);

	if (!Asset)
	{
		// Dependency may not be imported yet, try to do a manual import now
		IFileManager& FileManager = IFileManager::Get();
		if (FileManager.FileExists(*FilePath))
		{
			UAutomatedAssetImportData* AutomatedAssetImportData = NewObject<UAutomatedAssetImportData>();
			AutomatedAssetImportData->bReplaceExisting = true;
			AutomatedAssetImportData->Filenames.Empty(1);
			AutomatedAssetImportData->Filenames.Add(FilePath);
			AutomatedAssetImportData->DestinationPath = FPaths::GetPath(AssetPath);
			FAssetToolsModule& AssetToolsModule = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>("AssetTools");
			AssetToolsModule.Get().ImportAssetsAutomated(AutomatedAssetImportData);
			Asset = LoadObject<UObject>(nullptr, *AssetPath, nullptr, LOAD_NoWarn | LOAD_Quiet);
		}
	}

	if (Asset)
	{
		NoesisXaml->Dependencies.Add(Asset);
	}

	return Asset;
}

UObject* UNoesisXamlFactory::FactoryCreateBinary(UClass* Class, UObject* Parent, FName Name, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const uint8*& Buffer, const uint8* BufferEnd, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	// This needs to go first, before we invoke other factories, since they're stored in UFactory statics.
	FString FullFilePath = GetCurrentFilename();
	FMD5Hash CurrentFileHash = FileHash;
	if (!CurrentFileHash.IsValid())
	{
		CurrentFileHash = FMD5Hash::HashFile(*FullFilePath);
	}

	if (FullFilePath.Contains("/.noesis/"))
	{
		// Do not import XAML files which are contained within a .noesis folder
		bOutOperationCanceled = true;
		return nullptr;
	}

	bOutOperationCanceled = false;

	// This function is invoked for first time imports as well as for reimports.
	// Reimports can be caused by a change in content, via auto-reimport, or manually by the user.
	// When the XAML is first imported, or when the content has changed, we need to reparse it for dependencies.
	// We want to do that for reimports, even if the content hasn't changed, to fix dependencies that were broken when first imported.
	// We also want to make sure the ApplicationResources are up to date, so we don't get false errors during the LoadXaml at the end.
	// But we don't want to reparse all the dependent XAMLs. So we use this static variable that ensures that:
	// The first level XAML that is imported gets it's dependencies checked, even if it's a reimport and the contents haven't changed.
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
		FString PackageRoot, PackagePath, PackageName;
		FPackageName::SplitLongPackageName(Parent->GetPathName(), PackageRoot, PackagePath, PackageName, false);

		FString XamlUri = PackageRoot.LeftChop(1) + TEXT(";component/") + PackagePath + PackageName + TEXT(".xaml");

		TArray<FString> ProjectAssetPathRootComponents;
		SplitPath(PackagePath, ProjectAssetPathRootComponents);
		TArray<FString> ProjectURIRootComponents;
		SplitPath(FPaths::GetPath(FullFilePath) + TEXT("/"), ProjectURIRootComponents);

		while (!ProjectAssetPathRootComponents.IsEmpty() && ProjectAssetPathRootComponents.Last() == ProjectURIRootComponents.Last())
		{
			ProjectAssetPathRootComponents.Pop();
			ProjectURIRootComponents.Pop();
		}

		FString ProjectAssetPathRoot = PackageRoot;
		JoinPath(ProjectAssetPathRootComponents, ProjectAssetPathRoot);
		FString ProjectURIRoot;
		JoinPath(ProjectURIRootComponents, ProjectURIRoot);

		NoesisXaml = NewObject<UNoesisXaml>(Parent, Class, Name, Flags);

		FString XamlText = StringCast<TCHAR>((UTF8CHAR*)(const char*)Buffer).Get();
		Noesis::String Text = (ANSICHAR*)StringCast<UTF8CHAR>(*XamlText).Get();
		Noesis::MemoryStream XamlStream(Text.Str(), Text.Size());

		INoesisRuntimeModuleInterface& NoesisRuntime = INoesisRuntimeModuleInterface::Get();
		FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));

		TArray<FAssetData> Xamls;
		TArray<FAssetData> Materials;
		bool XamlsEnumerated = false;
		bool MaterialsEnumerated = false;

		auto DependencyCallback = [&](const Noesis::Uri& Uri, Noesis::XamlDependencyType Type)
		{
			if (Type == Noesis::XamlDependencyType_Root) return;

			// If the URI is invalid, ImportAssetsAutomated will try to reimport the whole directory
			// causing infinite recursion.
			if (!Uri.IsValid()) return;
			
			FString Dependency = GetDependencyPath(Uri);

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
					FString AssetPath = Path / ObjectTools::SanitizeInvalidChars(Filename, INVALID_LONGPACKAGE_CHARACTERS);
					FString FilePath = PackagePath.Replace(*ProjectAssetPathRoot, *ProjectURIRoot);
					if (!FPackageName::IsValidLongPackageName(AssetPath / "_Font"))
					{
						PackagePath = TEXT("/Game/") + PackagePath;
						FilePath = PackagePath.Replace(*ProjectAssetPathRoot, *ProjectURIRoot);
					}

					TArray<UFontFace*> FontFaces = ImportFontFamily(PackagePath, FamilyName, FilePath);

					if (FontFaces.Num())
					{
						NoesisXaml->Dependencies.Append(FontFaces);
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
			else if (Type == Noesis::XamlDependencyType_Class)
			{
				Noesis::Symbol TypeId(Uri.Str());
				const Noesis::Type* NoesisType = Noesis::Reflection::GetType(TypeId);
				const Noesis::TypeMeta* NoesisTypeClass = Noesis::DynamicCast<const Noesis::TypeMeta*>(NoesisType);
				if (NoesisTypeClass)
				{
					Noesis::ArrayRef<Noesis::TypeMetaData*> Metas = NoesisTypeClass->GetMeta();
					for (Noesis::TypeMetaData* Meta : Metas)
					{
						Noesis::AssetDependency* AssetDependency = Noesis::DynamicCast<Noesis::AssetDependency*>(Meta);
						if (AssetDependency)
						{
							FString AssetPath = NsProviderUriToAssetPath(AssetDependency->AssetPath());
							FString AssetFile = AssetPath.Replace(*ProjectAssetPathRoot, *ProjectURIRoot) + GetDependencyExtension(AssetDependency->AssetPath());
							UObject* Asset = EnsureDependency(NoesisXaml, AssetPath, AssetFile);
							if (!Asset)
							{
								UE_LOG(LogNoesisEditor, Warning, TEXT("Failed to find dependency %s referenced from XAML %s"), StringCast<TCHAR>((UTF8CHAR*)Uri.Str()).Get(), *XamlUri);
							}
						}
					}
				}
			}
			else if (Type == Noesis::XamlDependencyType_Filename)
			{
				FString AssetPath = NsProviderUriToAssetPath(Uri);
				FString AssetFile = AssetPath.Replace(*ProjectAssetPathRoot, *ProjectURIRoot) + GetDependencyExtension(Uri);
				UObject* Asset = EnsureDependency(NoesisXaml, AssetPath, AssetFile);
				if (!Asset)
				{
					UE_LOG(LogNoesisEditor, Warning, TEXT("Failed to find dependency %s referenced from XAML %s"), StringCast<TCHAR>((UTF8CHAR*)Uri.Str()).Get(), *XamlUri);
				}
			}
		};
		auto DependencyCallbackAdaptor = [](void* UserData, const Noesis::Uri& Uri, Noesis::XamlDependencyType Type)
		{
			auto Callback = (decltype(DependencyCallback)*)UserData;
			return (*Callback)(Uri, Type);
		};
		Noesis::GUI::GetXamlDependencies(&XamlStream, (ANSICHAR*)StringCast<UTF8CHAR>(*XamlUri).Get(), &DependencyCallback, DependencyCallbackAdaptor);

		NoesisXaml->XamlText.Insert((uint8*)Text.Str(), Text.Size(), 0);

		NoesisXaml->AssetImportData->Update(FullFilePath, CurrentFileHash);
		NoesisXaml->AssetImportData->UpdateFilenameOnly(RelativizeImportFilename(FullFilePath, NoesisXaml->GetOutermost()->GetPathName()));
	}
	else
	{
		NoesisXaml = ExistingXaml;
	}

	for (auto Dependency : NoesisXaml->Dependencies)
	{
		if (auto Xaml = Cast<UNoesisXaml>(Dependency))
		{
			FReimportManager::Instance()->Reimport(Xaml);
		}
	}

	// Make sure textures have alpha premultiplied if the user needs them, or are cleaned if they already are
	for (auto Dependency : NoesisXaml->Dependencies)
	{
		if (auto Texture = Cast<UTexture2D>(Dependency))
		{
			INoesisEditorModuleInterface::Get().EnsurePremultiplyAlpha(Texture);
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

	if (GetDefault<UNoesisSettings>()->ApplicationResources == FSoftObjectPath(NoesisXaml))
	{
		GetDefault<UNoesisSettings>()->SetApplicationResources();
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
