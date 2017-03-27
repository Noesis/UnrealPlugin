////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisContentControl.h"
#include "NoesisScrollViewer.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisScrollViewer : public UNoesisContentControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property CanContentScroll
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetCanContentScroll();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCanContentScroll(bool InCanContentScroll);

	// Property ComputedHorizontalScrollBarVisibility
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisVisibility GetComputedHorizontalScrollBarVisibility();

	// Property ComputedVerticalScrollBarVisibility
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisVisibility GetComputedVerticalScrollBarVisibility();

	// Property ExtentHeight
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetExtentHeight();

	// Property ExtentWidth
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetExtentWidth();

	// Property HorizontalOffset
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetHorizontalOffset();

	// Property HorizontalScrollBarVisibility
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisScrollBarVisibility GetHorizontalScrollBarVisibility();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetHorizontalScrollBarVisibility(ENoesisScrollBarVisibility InHorizontalScrollBarVisibility);

	// Property IsDeferredScrollingEnabled
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsDeferredScrollingEnabled();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsDeferredScrollingEnabled(bool InIsDeferredScrollingEnabled);

	// Property PanningDeceleration
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetPanningDeceleration();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetPanningDeceleration(float InPanningDeceleration);

	// Property PanningMode
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisPanningMode GetPanningMode();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetPanningMode(ENoesisPanningMode InPanningMode);

	// Property PanningRatio
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetPanningRatio();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetPanningRatio(float InPanningRatio);

	// Property ScrollableHeight
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetScrollableHeight();

	// Property ScrollableWidth
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetScrollableWidth();

	// Property VerticalOffset
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetVerticalOffset();

	// Property VerticalScrollBarVisibility
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisScrollBarVisibility GetVerticalScrollBarVisibility();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetVerticalScrollBarVisibility(ENoesisScrollBarVisibility InVerticalScrollBarVisibility);

	// Property ViewportHeight
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetViewportHeight();

	// Property ViewportWidth
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetViewportWidth();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void InvalidateScrollInfo();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void LineDown();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void LineLeft();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void LineRight();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void LineUp();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void PageDown();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void PageLeft();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void PageRight();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void PageUp();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void ScrollToBottom();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void ScrollToEnd();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void ScrollToHome();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void ScrollToHorizontalOffset(float Offset);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void ScrollToLeftEnd();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void ScrollToRightEnd();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void ScrollToTop();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void ScrollToVerticalOffset(float Offset);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisScrollChangedEventHandler ScrollChanged;

	void ScrollChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ScrollChangedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ScrollChangedEventArgs& InArgs)> ScrollChanged_Delegate;

};

