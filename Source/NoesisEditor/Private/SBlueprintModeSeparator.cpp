////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "SBlueprintModeSeparator.h"

// Core includes
#include "CoreMinimal.h"
#include "Misc/EngineVersionComparison.h"

// EditorStyle includes
#include "EditorStyleSet.h"

void SBlueprintModeSeparator::Construct(const FArguments& InArg)
{
	SBorder::Construct(
		SBorder::FArguments()
#if UE_VERSION_OLDER_THAN(5, 1, 0)
		.BorderImage(FEditorStyle::GetBrush("BlueprintEditor.PipelineSeparator"))
#else
		.BorderImage(FAppStyle::GetBrush("BlueprintEditor.PipelineSeparator"))
#endif
		.Padding(0.0f)
	);
}

FVector2D SBlueprintModeSeparator::ComputeDesiredSize(float) const
{
	const float Height = 20.0f;
	const float Thickness = 16.0f;
	return FVector2D(Thickness, Height);
}
