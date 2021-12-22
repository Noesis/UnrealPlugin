////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Slate includes
#include "Widgets/Layout/SBorder.h"

// SlateCore includes
#include "Widgets/DeclarativeSyntaxSupport.h"

class SBlueprintModeSeparator : public SBorder
{
public:
	SLATE_BEGIN_ARGS(SBlueprintModeSeparator) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArg);

	// SWidget interface
	virtual FVector2D ComputeDesiredSize(float) const override;
	// End of SWidget interface
};
