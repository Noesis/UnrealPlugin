////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

class FNoesisBlueprintApplicationMode : public FBlueprintEditorApplicationMode
{
public:
	FNoesisBlueprintApplicationMode(TSharedPtr<class FNoesisBlueprintEditor> InNoesisBlueprintEditor, FName InModeName);

	TWeakPtr<class FNoesisBlueprintEditor> NoesisBlueprintEditor;

	FWorkflowAllowedTabSet TabFactories;
};
