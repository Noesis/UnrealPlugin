////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisBlueprintApplicationMode.h"

class FNoesisBlueprintGraphApplicationMode : public FNoesisBlueprintApplicationMode
{
public:
	FNoesisBlueprintGraphApplicationMode(TSharedPtr<class FNoesisBlueprintEditor> InNoesisBlueprintEditor);

	// FApplicationMode interface
	void PreDeactivateMode() override;
	void PostActivateMode() override;
	// End of FApplicationMode interface
};
