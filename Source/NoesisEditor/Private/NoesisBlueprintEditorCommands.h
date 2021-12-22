////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Slate includes
#include "Framework/Commands/Commands.h"

class FNoesisBlueprintEditorCommands : public TCommands<FNoesisBlueprintEditorCommands>
{
public:
	FNoesisBlueprintEditorCommands();

	TSharedPtr<FUICommandInfo> RestartPreview;

	virtual void RegisterCommands() override;
};
