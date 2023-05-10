////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisBlueprintEditor.h"

// NoesisEditor includes
#include "NoesisBlueprintEditorToolbar.h"
#include "NoesisBlueprintApplicationModes.h"
#include "NoesisBlueprintPreviewApplicationMode.h"
#include "NoesisBlueprintGraphApplicationMode.h"
#include "NoesisBlueprintEditorCommands.h"

void FNoesisBlueprintEditor::InitNoesisBlueprintEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, const TArray<UBlueprint*>& InBlueprints, bool bShouldOpenInDefaultsMode)
{
	TSharedPtr<FNoesisBlueprintEditor> ThisPtr(SharedThis(this));

	NoesisToolbar = MakeShareable(new FNoesisBlueprintEditorToolbar(ThisPtr));

	InitBlueprintEditor(Mode, InitToolkitHost, InBlueprints, bShouldOpenInDefaultsMode);

	FNoesisBlueprintEditorCommands::Register();

	ToolkitCommands->MapAction(
		FNoesisBlueprintEditorCommands::Get().RestartPreview,
		FExecuteAction::CreateSP(this, &FNoesisBlueprintEditor::RestartPreview),
		FCanExecuteAction());
}

void FNoesisBlueprintEditor::RegisterApplicationModes(const TArray<UBlueprint*>& InBlueprints, bool bShouldOpenInDefaultsMode, bool bNewlyCreated)
{
	TSharedPtr<FNoesisBlueprintEditor> ThisPtr(SharedThis(this));

	TSharedRef<FNoesisBlueprintApplicationMode> PreviewMode = MakeShareable(new FNoesisBlueprintPreviewApplicationMode(ThisPtr));
	AddApplicationMode(PreviewMode->GetModeName(), PreviewMode);
	TSharedRef<FNoesisBlueprintApplicationMode> GraphMode = MakeShareable(new FNoesisBlueprintGraphApplicationMode(ThisPtr));
	AddApplicationMode(GraphMode->GetModeName(), GraphMode);

	SetCurrentMode(FNoesisBlueprintApplicationModes::GraphMode);
}

void FNoesisBlueprintEditor::SelectClassSettings()
{
	EditGlobalOptions_Clicked();
}

void FNoesisBlueprintEditor::RestartPreview()
{
	OnBlueprintPreviewUpdated.Broadcast();
}
