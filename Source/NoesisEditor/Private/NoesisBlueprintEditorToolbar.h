////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// Slate includes
#include "Framework/MultiBox/MultiBoxExtender.h"

class FNoesisBlueprintEditorToolbar : public TSharedFromThis<FNoesisBlueprintEditorToolbar>
{

public:
	FNoesisBlueprintEditorToolbar(TSharedPtr<class FNoesisBlueprintEditor>& InBlueprintEditor);

	void AddNoesisBlueprintEditorModesToolbar(TSharedPtr<FExtender> Extender);

	void AddNoesisControls(class UToolMenu* InMenu);

public:
	/**  */
	void FillNoesisBlueprintEditorModesToolbar(FToolBarBuilder& ToolbarBuilder);

	TWeakPtr<class FNoesisBlueprintEditor> BlueprintEditor;
};
