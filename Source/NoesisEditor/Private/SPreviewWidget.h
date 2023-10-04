////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// SlateCore includes
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"

class SPreviewWidget : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SPreviewWidget) {}
	SLATE_END_ARGS()

	virtual ~SPreviewWidget();

	void Construct(const FArguments& InArg, TSharedPtr<class FNoesisBlueprintEditor> InBlueprintEditor);

	// SWidget interface
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	// End of SWidget interface

	void UpdatePreviewWidget(float CurrentTime);
	void InvalidatePreviewWidget();

	TWeakPtr<class FNoesisBlueprintEditor> BlueprintEditor;
	TSharedPtr<class SBox> PreviewBox;
	class UNoesisBlueprint* PreviewBlueprint;
	class UNoesisInstance* PreviewInstance;
	TWeakPtr<class SWidget> PreviewSlateWidget;
	FDelegateHandle InvalidatePreviewDelegateHandle;
};
