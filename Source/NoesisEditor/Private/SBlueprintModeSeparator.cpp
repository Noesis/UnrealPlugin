////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "SBlueprintModeSeparator.h"

void SBlueprintModeSeparator::Construct(const FArguments& InArg)
{
	SBorder::Construct(
		SBorder::FArguments()
		.BorderImage(FEditorStyle::GetBrush("BlueprintEditor.PipelineSeparator"))
		.Padding(0.0f)
	);
}

FVector2D SBlueprintModeSeparator::ComputeDesiredSize(float) const
{
	const float Height = 20.0f;
	const float Thickness = 16.0f;
	return FVector2D(Thickness, Height);
}
