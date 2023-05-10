////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisRiveAssetTypeActions.h"

// Core includes
#include "CoreMinimal.h"

// Engine includes
#include "EditorFramework/AssetImportData.h"

// UnrealEd includes
#include "ObjectTools.h"
#include "UnrealEdGlobals.h"
#include "Editor/UnrealEdEngine.h"

// NoesisRuntime includes
#include "NoesisRive.h"

#define LOCTEXT_NAMESPACE "NoesisEditorModule"

FNoesisRiveAssetTypeActions::FNoesisRiveAssetTypeActions(EAssetTypeCategories::Type InCategories)
{
}

UClass* FNoesisRiveAssetTypeActions::GetSupportedClass() const
{
    return UNoesisRive::StaticClass();
}

FText FNoesisRiveAssetTypeActions::GetName() const
{
	return LOCTEXT("NoesisRiveAssetTypeActions_Name", "NoesisGUI");
}

FColor FNoesisRiveAssetTypeActions::GetTypeColor() const
{
	return FColor(239, 84, 134);
}

uint32 FNoesisRiveAssetTypeActions::GetCategories()
{
	return Categories;
}

bool FNoesisRiveAssetTypeActions::IsImportedAsset() const
{
    return true;
}

void FNoesisRiveAssetTypeActions::GetResolvedSourceFilePaths(const TArray<UObject*>& TypeAssets, TArray<FString>& OutSourceFilePaths) const
{
	for (auto& Asset : TypeAssets)
	{
		UNoesisRive* Rive = CastChecked<UNoesisRive>(Asset);
		Rive->AssetImportData->ExtractFilenames(OutSourceFilePaths);
	}
}

#undef LOCTEXT_NAMESPACE
