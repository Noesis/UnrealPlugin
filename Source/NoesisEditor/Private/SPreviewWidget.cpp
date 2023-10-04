////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "SPreviewWidget.h"

// NoesisEditor includes
#include "NoesisBlueprintEditor.h"

// NoesisRuntime includes
#include "NoesisBlueprint.h"
#include "NoesisInstance.h"

SPreviewWidget::~SPreviewWidget()
{
	auto PinnedBlueprintEditor = BlueprintEditor.Pin();
	if (PinnedBlueprintEditor.IsValid())
	{
		PinnedBlueprintEditor->OnBlueprintPreviewUpdated.Remove(InvalidatePreviewDelegateHandle);
	}
}

void SPreviewWidget::Construct(const FArguments& InArg, TSharedPtr<class FNoesisBlueprintEditor> InBlueprintEditor)
{
	BlueprintEditor = InBlueprintEditor;
	PreviewInstance = nullptr;

	ChildSlot
	[
		SNew(SBorder)
		.Padding(FMargin(0))
		[
			SAssignNew(PreviewBox, SBox)
		]
	];

	InvalidatePreviewDelegateHandle = BlueprintEditor.Pin()->OnBlueprintPreviewUpdated.AddRaw(this, &SPreviewWidget::InvalidatePreviewWidget);
}

void SPreviewWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);

	UpdatePreviewWidget(InCurrentTime);

	if (PreviewSlateWidget.IsValid())
	{
		PreviewSlateWidget.Pin()->Tick(AllottedGeometry, InCurrentTime, InDeltaTime);
	}
}

void SPreviewWidget::UpdatePreviewWidget(float CurrentTime)
{
	UNoesisBlueprint* LatestPreviewBlueprint = Cast<UNoesisBlueprint>(BlueprintEditor.Pin()->GetBlueprintObj());

	if (PreviewBlueprint != LatestPreviewBlueprint)
	{
		PreviewBlueprint = LatestPreviewBlueprint;
		if (PreviewBlueprint != nullptr)
		{
			PreviewInstance = NewObject<UNoesisInstance>(GetTransientPackage(), PreviewBlueprint->GeneratedClass);
			TSharedRef<SWidget> NewPreviewSlateWidget = PreviewInstance->TakeWidget();
			NewPreviewSlateWidget->SlatePrepass(PreviewBox->GetCachedGeometry().Scale);

			PreviewSlateWidget = NewPreviewSlateWidget;

			PreviewBox->SetContent(NewPreviewSlateWidget);
		}
		else
		{
			PreviewInstance = nullptr;
			PreviewSlateWidget = nullptr;
		}
	}
}

void SPreviewWidget::InvalidatePreviewWidget()
{
	PreviewBlueprint = nullptr;
	PreviewInstance = nullptr;
	PreviewSlateWidget = nullptr;
}
