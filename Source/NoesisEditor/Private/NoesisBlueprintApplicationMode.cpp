////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisBlueprintApplicationMode.h"

// NoesisEditor includes
#include "NoesisBlueprintEditor.h"
#include "NoesisBlueprintApplicationModes.h"

FNoesisBlueprintApplicationMode::FNoesisBlueprintApplicationMode(TSharedPtr<class FNoesisBlueprintEditor> InNoesisBlueprintEditor, FName InModeName)
	: FBlueprintEditorApplicationMode(InNoesisBlueprintEditor, InModeName, FNoesisBlueprintApplicationModes::GetLocalizedMode, false, false)
	, NoesisBlueprintEditor(InNoesisBlueprintEditor)
{
}
