////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisBlueprintApplicationModes.h"

#define LOCTEXT_NAMESPACE "NoesisEditorModule"

const FName FNoesisBlueprintApplicationModes::PreviewMode("PreviewName");
const FName FNoesisBlueprintApplicationModes::GraphMode("GraphName");

FText FNoesisBlueprintApplicationModes::GetLocalizedMode(const FName InMode)
{
	static TMap< FName, FText > LocModes;

	if (LocModes.Num() == 0)
	{
		LocModes.Add(PreviewMode, LOCTEXT("PreviewName", "Preview"));
		LocModes.Add(GraphMode, LOCTEXT("GraphName", "Graph"));
	}

	check(InMode != NAME_None);
	const FText* OutDesc = LocModes.Find(InMode);
	check(OutDesc);

	return *OutDesc;
}

#undef LOCTEXT_NAMESPACE
