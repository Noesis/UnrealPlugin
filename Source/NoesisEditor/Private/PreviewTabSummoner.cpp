////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "PreviewTabSummoner.h"

// NoesisEditor includes
#include "NoesisBlueprintEditor.h"
#include "NoesisStyle.h"
#include "SPreviewWidget.h"

#define LOCTEXT_NAMESPACE "NoesisEditorModule"

const FName FPreviewTabSummoner::TabID(TEXT("NoesisPreview"));

FPreviewTabSummoner::FPreviewTabSummoner(TSharedPtr<FNoesisBlueprintEditor> InBlueprintEditor)
	: FWorkflowTabFactory(TabID, InBlueprintEditor)
	, BlueprintEditor(InBlueprintEditor)
{
	TabLabel = LOCTEXT("PreviewTabLabel", "Preview");
	TabIcon = FSlateIcon(FNoesisStyle::GetStyleSetName(), "Designer.TabIcon");

	bIsSingleton = true;

	ViewMenuDescription = LOCTEXT("NoesisPreview_ViewMenu_Desc", "Preview");
	ViewMenuTooltip = LOCTEXT("NoesisPreview_ViewMenu_ToolTip", "Show the Preview");
}

TSharedRef<SWidget> FPreviewTabSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	return SNew(SPreviewWidget, BlueprintEditor.Pin())
		.AddMetaData<FTagMetaData>(FTagMetaData(TEXT("Designer")));
}

#undef LOCTEXT_NAMESPACE
