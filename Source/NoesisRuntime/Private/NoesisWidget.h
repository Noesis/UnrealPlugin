////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

class FNoesisSlateOffscreenElement : public ICustomSlateElement
{
public:
	FNoesisSlateOffscreenElement(class UNoesisInstance* InNoesisInstance);

	// ICustomSlateElement interface
	virtual void DrawRenderThread(FRHICommandListImmediate& RHICmdList, const void* InWindowBackBuffer) override;
	// End of ICustomSlateElement interface

	class UNoesisInstance* NoesisInstance;
};

class FNoesisSlateElement : public ICustomSlateElement
{
public:
	FNoesisSlateElement(class UNoesisInstance* InNoesisInstance);

	// ICustomSlateElement interface
	virtual void DrawRenderThread(FRHICommandListImmediate& RHICmdList, const void* InWindowBackBuffer) override;
	// End of ICustomSlateElement interface

	class UNoesisInstance* NoesisInstance;
};

typedef TSharedPtr<class FNoesisSlateOffscreenElement, ESPMode::ThreadSafe> FNoesisSlateOffscreenElementPtr;
typedef TSharedPtr<class FNoesisSlateElement, ESPMode::ThreadSafe> FNoesisSlateElementPtr;

class NOESISRUNTIME_API SNoesisWidget : public SLeafWidget
{
	SLATE_BEGIN_ARGS(SNoesisWidget)
	{
	}
		SLATE_ARGUMENT(class UNoesisInstance*, NoesisInstance)
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
	virtual bool SupportsKeyboardFocus() const override;
	// End of SWidget interface

private:
	FNoesisSlateOffscreenElementPtr NoesisSlateOffscreenElement;
	FNoesisSlateElementPtr NoesisSlateElement;
	class UNoesisInstance* NoesisInstance;
};
