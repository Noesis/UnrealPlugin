////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiEditorPrivatePCH.h"
#include "NoesisBlueprintAssetTypeActions.h"

// Kismet includes
#include "BlueprintEditorModule.h"

// NoesisGui includes
#include "NoesisBlueprint.h"

#define LOCTEXT_NAMESPACE "NoesisBlueprintAssetTypeActions"

FNoesisBlueprintAssetTypeActions::FNoesisBlueprintAssetTypeActions()
{
};

FText FNoesisBlueprintAssetTypeActions::GetName() const
{
	return LOCTEXT("AssetTypeActions", "NoesisGui Blueprint Class");
}

UClass* FNoesisBlueprintAssetTypeActions::GetSupportedClass() const
{
	return UNoesisBlueprint::StaticClass();
}

FColor FNoesisBlueprintAssetTypeActions::GetTypeColor() const
{
	return FColor(126, 63, 255);
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
	return EAssetTypeCategories::Misc;
}

#undef LOCTEXT_NAMESPACE
