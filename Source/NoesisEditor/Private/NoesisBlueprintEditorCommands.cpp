////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisBlueprintEditorCommands.h"

// NoesisEditor includes
#include "NoesisStyle.h"

#define LOCTEXT_NAMESPACE "NoesisEditorModule"

FNoesisBlueprintEditorCommands::FNoesisBlueprintEditorCommands()
	: TCommands<FNoesisBlueprintEditorCommands>("NoesisBlueprintEditor", LOCTEXT("NoesisBlueprintEditor", "Noesis Blueprint Editor"), NAME_None, FNoesisStyle::GetStyleSetName())
{
}

void FNoesisBlueprintEditorCommands::RegisterCommands()
{
	UI_COMMAND(RestartPreview, "RestartPreview", "Restart the preview", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
