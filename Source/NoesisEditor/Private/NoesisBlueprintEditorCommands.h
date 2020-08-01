////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

class FNoesisBlueprintEditorCommands : public TCommands<FNoesisBlueprintEditorCommands>
{
public:
	FNoesisBlueprintEditorCommands();

	TSharedPtr<FUICommandInfo> RestartPreview;

	virtual void RegisterCommands() override;
};
