////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisRiveFactory.h"

// Core includes
#include "CoreMinimal.h"
#include "Misc/Paths.h"

// AssetRegistry includes
#include "AssetRegistry/AssetRegistryModule.h"

// AssetTools includes
#include "AssetToolsModule.h"

// Engine includes
#include "EditorFramework/AssetImportData.h"
#include "Engine/FontFace.h"
#include "Engine/Texture2D.h"

// UnrealEd includes
#include "ObjectTools.h"

// NoesisRuntime includes
#include "NoesisRive.h"

// NoesisGUI includes
#include "NsApp/RiveControl.h"

static UObject* GetDependency(const FString& FilePath, const FString& AssetPath)
{
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
	FAssetToolsModule& AssetToolsModule = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>("AssetTools");

	TArray<FAssetData> FoundAssets;
	AssetRegistryModule.Get().GetAssetsByPackageName(*AssetPath, FoundAssets);
	if (FoundAssets.Num() > 0)
	{
		return FoundAssets[0].GetAsset();
	}
	else
	{
		// Dependency may not be imported yet, try to do a manual import now
		TArray<UObject*> Assets;
		UAutomatedAssetImportData* AutomatedAssetImportData = NewObject<UAutomatedAssetImportData>();
		AutomatedAssetImportData->bReplaceExisting = true;
		AutomatedAssetImportData->Filenames.Add(FilePath);
		AutomatedAssetImportData->DestinationPath = FPaths::GetPath(AssetPath);
		Assets = AssetToolsModule.Get().ImportAssetsAutomated(AutomatedAssetImportData);

		if (Assets.Num() > 0)
		{
			return Assets[0];
		}
	}

	return nullptr;
}

UNoesisRiveFactory::UNoesisRiveFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bEditorImport = true;
	bEditAfterNew = true;
	SupportedClass = UNoesisRive::StaticClass();
	Formats.Add(TEXT("riv;Rive"));
}

UObject* UNoesisRiveFactory::FactoryCreateBinary(UClass* Class, UObject* Parent, FName Name,
	EObjectFlags Flags, UObject* Context, const TCHAR* Type, const uint8*& Buffer, const uint8* BufferEnd,
	FFeedbackContext* Warn)
{
	FString FullFilePath = GetCurrentFilename();
	FString FileDirectory = FPaths::GetPath(FullFilePath);

	auto BufferLength = (int32)(BufferEnd - Buffer);
	UNoesisRive* Rive = NewObject<UNoesisRive>(Parent, Class, Name, Flags);
	Rive->Content.Insert(Buffer, BufferLength, 0);
	Rive->AssetImportData->Update(FullFilePath);

	FString PackageRoot, PackagePath, PackageName;
	FPackageName::SplitLongPackageName(Parent->GetPathName(), PackageRoot, PackagePath, PackageName, false);

	FString Uri = PackageRoot.LeftChop(1) + TEXT(";component/") + PackagePath + PackageName + TEXT(".riv");
	Noesis::MemoryStream RiveStream(Buffer, BufferLength);
	Noesis::Vector<Noesis::Uri> ImageDependencies;
	Noesis::Vector<Noesis::Uri> FontDependencies;
	NoesisApp::GetRiveDependencies(&RiveStream, TCHAR_TO_UTF8(*Uri), ImageDependencies, FontDependencies);

	for (const auto& Dependency : ImageDependencies)
	{
		Noesis::String DependencyPath;
		Dependency.GetPath(DependencyPath);
		FString FilePath = FileDirectory / FPaths::GetCleanFilename(UTF8_TO_TCHAR(DependencyPath.Str()));
		FString AssetPath = PackageRoot / PackagePath / ObjectTools::SanitizeInvalidChars(FPaths::GetBaseFilename(UTF8_TO_TCHAR(DependencyPath.Str())), INVALID_LONGPACKAGE_CHARACTERS);

		UObject* Asset = GetDependency(FilePath, AssetPath);
		if (Asset != nullptr && Asset->IsA<UTexture2D>())
		{
			Rive->Textures.Add((UTexture2D*)Asset);
		}
	}

	for (const auto& Dependency : FontDependencies)
	{
		Noesis::String DependencyPath;
		Dependency.GetPath(DependencyPath);
		FString FilePath = FileDirectory / FPaths::GetCleanFilename(UTF8_TO_TCHAR(DependencyPath.Str()));
		FString AssetPath = PackageRoot / PackagePath / ObjectTools::SanitizeInvalidChars(FPaths::GetBaseFilename(UTF8_TO_TCHAR(DependencyPath.Str())), INVALID_LONGPACKAGE_CHARACTERS);

		UObject* Asset = GetDependency(FilePath, AssetPath);
		if (Asset != nullptr && Asset->IsA<UFontFace>())
		{
			Rive->FontFaces.Add((UFontFace*)Asset);
		}
	}

	return Rive;
}
