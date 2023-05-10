////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisBlueprintPreviewApplicationMode.h"

// Kismet includes
#include "SBlueprintEditorToolbar.h"

// NoesisEditor includes
#include "NoesisBlueprintEditor.h"
#include "NoesisBlueprintApplicationModes.h"
#include "NoesisBlueprintEditorToolbar.h"
#include "PreviewTabSummoner.h"

void FNoesisBlueprintPreviewApplicationMode::PreDeactivateMode()
{
	// We need this empty to avoid callint the base class and resetting the blueprint graph editor when switching modes
}

void FNoesisBlueprintPreviewApplicationMode::PostActivateMode()
{
	// We need this empty to avoid callint the base class and resetting the blueprint graph editor when switching modes
}

FNoesisBlueprintPreviewApplicationMode::FNoesisBlueprintPreviewApplicationMode(TSharedPtr<class FNoesisBlueprintEditor> InNoesisBlueprintEditor)
	: FNoesisBlueprintApplicationMode(InNoesisBlueprintEditor, FNoesisBlueprintApplicationModes::PreviewMode)
{
	TabLayout = FTabManager::NewLayout("NoesisBlueprintEditor_Preview_Layout_v2")
		->AddArea
		(
			FTabManager::NewPrimaryArea()
			->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.7f)
				->SetHideTabWell(true)
				->AddTab(FPreviewTabSummoner::TabID, ETabState::OpenedTab)

			)
		);

	// Add Tab Spawners
	TabFactories.RegisterFactory(MakeShareable(new FPreviewTabSummoner(InNoesisBlueprintEditor)));

	ToolbarExtender = MakeShareable(new FExtender);
	InNoesisBlueprintEditor->GetNoesisToolbarBuilder()->AddNoesisBlueprintEditorModesToolbar(ToolbarExtender);

	if (UToolMenu* Toolbar = InNoesisBlueprintEditor->RegisterModeToolbarIfUnregistered(GetModeName()))
	{
		InNoesisBlueprintEditor->GetToolbarBuilder()->AddCompileToolbar(Toolbar);
		InNoesisBlueprintEditor->GetNoesisToolbarBuilder()->AddNoesisControls(Toolbar);
	}
}

void FNoesisBlueprintPreviewApplicationMode::RegisterTabFactories(TSharedPtr<FTabManager> InTabManager)
{
	TSharedPtr<FNoesisBlueprintEditor> BP = NoesisBlueprintEditor.Pin();

	BP->RegisterToolbarTab(InTabManager.ToSharedRef());
	BP->PushTabFactories(TabFactories);
}
