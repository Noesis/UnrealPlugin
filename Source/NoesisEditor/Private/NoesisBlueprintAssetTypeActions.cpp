////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisBlueprintAssetTypeActions.h"

#define LOCTEXT_NAMESPACE "NoesisEditorModule"

FNoesisBlueprintAssetTypeActions::FNoesisBlueprintAssetTypeActions(EAssetTypeCategories::Type InCategories)
	: Categories(InCategories)
{
};

FText FNoesisBlueprintAssetTypeActions::GetName() const
{
	return LOCTEXT("NoesisBlueprintAssetTypeActions_Name", "Noesis View");
}

UClass* FNoesisBlueprintAssetTypeActions::GetSupportedClass() const
{
	return UNoesisBlueprint::StaticClass();
}

FColor FNoesisBlueprintAssetTypeActions::GetTypeColor() const
{
	return FColor(42, 166, 226);
}

void FNoesisBlueprintAssetTypeActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto Blueprint = Cast<UBlueprint>(*ObjIt);
		if (Blueprint && Blueprint->SkeletonGeneratedClass && Blueprint->GeneratedClass)
		{
			FBlueprintEditorModule& BlueprintEditorModule = FModuleManager::LoadModuleChecked<FBlueprintEditorModule>("Kismet");
			TSharedRef< IBlueprintEditor > NewKismetEditor = BlueprintEditorModule.CreateBlueprintEditor(Mode, EditWithinLevelEditor, Blueprint, false);
		}
		else
		{
			FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("FailedToLoadBlueprint", "Blueprint could not be loaded because it derives from an invalid class.  Check to make sure the parent class for this blueprint hasn't been removed!"));
		}
	}
}

uint32 FNoesisBlueprintAssetTypeActions::GetCategories()
{
	return Categories;
}

#undef LOCTEXT_NAMESPACE
