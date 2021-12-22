////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisBlueprintApplicationMode.h"

// Core includes
#include "CoreMinimal.h"

class FNoesisBlueprintPreviewApplicationMode : public FNoesisBlueprintApplicationMode
{
public:
	FNoesisBlueprintPreviewApplicationMode(TSharedPtr<class FNoesisBlueprintEditor> InNoesisBlueprintEditor);

	// FApplicationMode interface
	virtual void RegisterTabFactories(TSharedPtr<FTabManager> InTabManager) override;
	void PreDeactivateMode() override;
	void PostActivateMode() override;
	// End of FApplicationMode interface
};
