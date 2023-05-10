////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisBlueprintGraphApplicationMode.h"

// Kismet includes
#include "BlueprintEditorTabs.h"
#include "SBlueprintEditorToolbar.h"

// NoesisEditor includes
#include "NoesisBlueprintEditor.h"
#include "NoesisBlueprintApplicationModes.h"
#include "NoesisBlueprintEditorToolbar.h"

FNoesisBlueprintGraphApplicationMode::FNoesisBlueprintGraphApplicationMode(TSharedPtr<class FNoesisBlueprintEditor> InNoesisBlueprintEditor)
	: FNoesisBlueprintApplicationMode(InNoesisBlueprintEditor, FNoesisBlueprintApplicationModes::GraphMode)
{
	TabLayout = FTabManager::NewLayout("NoesisBlueprintEditor_Graph_Layout_v2")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewSplitter()->SetOrientation(Orient_Horizontal)
				->Split
				(
					FTabManager::NewSplitter()->SetOrientation(Orient_Vertical)
					->SetSizeCoefficient(0.15f)
					->Split
					(
						FTabManager::NewStack()->SetSizeCoefficient(0.5f)
						->AddTab(FBlueprintEditorTabs::MyBlueprintID, ETabState::OpenedTab)
					)
				)
				->Split
				(
					FTabManager::NewSplitter()->SetOrientation(Orient_Vertical)
					->SetSizeCoefficient(0.70f)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.80f)
						->AddTab("Document", ETabState::ClosedTab)
					)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.20f)
						->AddTab(FBlueprintEditorTabs::CompilerResultsID, ETabState::ClosedTab)
						->AddTab(FBlueprintEditorTabs::FindResultsID, ETabState::ClosedTab)
					)
				)
				->Split
				(
					FTabManager::NewStack()->SetSizeCoefficient(0.3f)
					->AddTab(FBlueprintEditorTabs::DetailsID, ETabState::OpenedTab)
				)
			)
		);

	ToolbarExtender = MakeShareable(new FExtender);
	InNoesisBlueprintEditor->GetNoesisToolbarBuilder()->AddNoesisBlueprintEditorModesToolbar(ToolbarExtender);

	if (UToolMenu* Toolbar = InNoesisBlueprintEditor->RegisterModeToolbarIfUnregistered(GetModeName()))
	{
		InNoesisBlueprintEditor->GetToolbarBuilder()->AddCompileToolbar(Toolbar);
		InNoesisBlueprintEditor->GetToolbarBuilder()->AddScriptingToolbar(Toolbar);
		InNoesisBlueprintEditor->GetToolbarBuilder()->AddBlueprintGlobalOptionsToolbar(Toolbar);
		InNoesisBlueprintEditor->GetToolbarBuilder()->AddDebuggingToolbar(Toolbar);
	}
}

void FNoesisBlueprintGraphApplicationMode::PreDeactivateMode()
{
	FNoesisBlueprintApplicationMode::PreDeactivateMode();
}

void FNoesisBlueprintGraphApplicationMode::PostActivateMode()
{
	FNoesisBlueprintApplicationMode::PostActivateMode();

	// Select the Class Settings properties when the mode is entered
	NoesisBlueprintEditor.Pin()->SelectClassSettings();
}
