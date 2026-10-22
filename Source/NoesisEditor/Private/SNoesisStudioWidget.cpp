////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "SNoesisStudioWidget.h"

// NoesisEditor includes
#include "NoesisBlueprintEditor.h"

// NoesisRuntime includes
#include "NoesisBlueprint.h"
#include "NoesisStudioInstance.h"

SNoesisStudioWidget::SNoesisStudioWidget(): StudioInstance(nullptr)
{
}

SNoesisStudioWidget::~SNoesisStudioWidget()
{
}

void SNoesisStudioWidget::Construct(const FArguments& InArg)
{
	ChildSlot
	[
		SNew(SBorder)
		.Padding(FMargin(0))
		[
			SAssignNew(ViewBox, SBox)
		]
	];

	StudioOptions Options = InArg._Options.Get();
	StudioInstance = NewObject<UNoesisStudioInstance>(GetTransientPackage(), NAME_None);
	StudioInstance->SetOptions(Options);
	TSharedRef<SWidget> NewPreviewSlateWidget = StudioInstance->TakeWidget();
	NewPreviewSlateWidget->SlatePrepass(ViewBox->GetCachedGeometry().Scale);

	ViewSlateWidget = NewPreviewSlateWidget;

	ViewBox->SetContent(NewPreviewSlateWidget);
}

void SNoesisStudioWidget::SaveAllChanges()
{
	if (StudioInstance != nullptr)
	{
		StudioInstance->SaveAllChanges();
	}
}

void SNoesisStudioWidget::DiscardAllChanges()
{
	if (StudioInstance != nullptr)
	{
		StudioInstance->DiscardAllChanges();
	}
}

void SNoesisStudioWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);

	if (ViewSlateWidget.IsValid() && InDeltaTime < 1.0f)
	{
		ViewSlateWidget.Pin()->Tick(AllottedGeometry, InCurrentTime, InDeltaTime);
	}
}

FNavigationReply SNoesisStudioWidget::OnNavigation(const FGeometry& MyGeometry, const FNavigationEvent& InNavigationEvent)
{
	EUINavigation NavType = InNavigationEvent.GetNavigationType();

	// Loop Tab/Shift-Tab focus within this widget
	if (NavType == EUINavigation::Next || NavType == EUINavigation::Previous)
	{
		return FNavigationReply::Wrap();
	}

	// Stop Arrow Key focus from escaping
	return FNavigationReply::Stop();
}
