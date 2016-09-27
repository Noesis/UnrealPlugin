////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// SlateCore includes
#include "SLeafWidget.h"

class FNoesisGuiSlateOffscreenElement : public ICustomSlateElement
{
public:
	FNoesisGuiSlateOffscreenElement(class UNoesisGuiInstance* InNoesisGuiInstance);

	// ICustomSlateElement interface
	virtual void DrawRenderThread(FRHICommandListImmediate& RHICmdList, const void* InWindowBackBuffer) override;
	// End of ICustomSlateElement interface

	class UNoesisGuiInstance* NoesisGuiInstance;
};

class FNoesisGuiSlateElement : public ICustomSlateElement
{
public:
	FNoesisGuiSlateElement(class UNoesisGuiInstance* InNoesisGuiInstance);

	// ICustomSlateElement interface
	virtual void DrawRenderThread(FRHICommandListImmediate& RHICmdList, const void* InWindowBackBuffer) override;
	// End of ICustomSlateElement interface

	class UNoesisGuiInstance* NoesisGuiInstance;
};

typedef TSharedPtr<class FNoesisGuiSlateOffscreenElement, ESPMode::ThreadSafe> FNoesisGuiSlateOffscreenElementPtr;
typedef TSharedPtr<class FNoesisGuiSlateElement, ESPMode::ThreadSafe> FNoesisGuiSlateElementPtr;

class NOESISGUI_API SNoesisGuiWidget : public SLeafWidget
{
	SLATE_BEGIN_ARGS(SNoesisGuiWidget)
	{
	}
		SLATE_ARGUMENT(class UNoesisGuiInstance*, NoesisGuiInstance)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	// SWidget interface
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyClippingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	virtual FVector2D ComputeDesiredSize(float LayoutScaleMultiplier) const override;
	virtual FReply OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& CharacterEvent) override;
	virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent) override;
	virtual FReply OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent) override;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FCursorReply OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const override;
	virtual FReply OnMouseButtonDoubleClick(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	// End of SWidget interface

private:
	FNoesisGuiSlateOffscreenElementPtr NoesisGuiSlateOffscreenElement;
	FNoesisGuiSlateElementPtr NoesisGuiSlateElement;
	class UNoesisGuiInstance* NoesisGuiInstance;
};
