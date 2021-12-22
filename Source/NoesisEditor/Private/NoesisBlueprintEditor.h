////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Kismet includes
#include "BlueprintEditor.h"

class FNoesisBlueprintEditor : public FBlueprintEditor
{
public:
	DECLARE_MULTICAST_DELEGATE(FOnBlueprintPreviewUpdated)

	void InitNoesisBlueprintEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, const TArray<UBlueprint*>& InBlueprints, bool bShouldOpenInDefaultsMode);

	void RegisterApplicationModes(const TArray<UBlueprint*>& InBlueprints, bool bShouldOpenInDefaultsMode, bool bNewlyCreated = false) override;

	void SelectClassSettings();

	void RestartPreview();

	TSharedPtr<class FNoesisBlueprintEditorToolbar> GetNoesisToolbarBuilder() { return NoesisToolbar; }

	TSharedPtr<class FNoesisBlueprintEditorToolbar> NoesisToolbar;

	FOnBlueprintPreviewUpdated OnBlueprintPreviewUpdated;
};
