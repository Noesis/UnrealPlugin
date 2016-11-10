////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisVisual.h"
#include "NoesisUIElement.generated.h"

UCLASS()
class NOESISGUI_API UNoesisUIElement : public UNoesisVisual
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property AllowDrop
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetAllowDrop();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetAllowDrop(bool InAllowDrop);

	// Property Clip
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGeometry* GetClip();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetClip(class UNoesisGeometry* InClip);

	// Property ClipToBounds
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetClipToBounds();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetClipToBounds(bool InClipToBounds);

	// Property CommandBindings
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisCommandBindingCollection* GetCommandBindings();

	// Property DesiredSize
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingSize GetDesiredSize();

	// Property Focusable
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetFocusable();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetFocusable(bool InFocusable);

	// Property InputBindings
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisInputBindingCollection* GetInputBindings();

	// Property IsEnabled
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsEnabled();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsEnabled(bool InIsEnabled);

	// Property IsFocused
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsFocused();

	// Property IsHitTestVisible
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsHitTestVisible();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsHitTestVisible(bool InIsHitTestVisible);

	// Property IsKeyboardFocusWithin
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsKeyboardFocusWithin();

	// Property IsKeyboardFocused
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsKeyboardFocused();

	// Property IsManipulationEnabled
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsManipulationEnabled();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsManipulationEnabled(bool InIsManipulationEnabled);

	// Property IsMouseCaptureWithin
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsMouseCaptureWithin();

	// Property IsMouseCaptured
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsMouseCaptured();

	// Property IsMouseDirectlyOver
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsMouseDirectlyOver();

	// Property IsMouseOver
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsMouseOver();

	// Property IsVisible
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsVisible();

	// Property Opacity
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetOpacity();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetOpacity(float InOpacity);

	// Property OpacityMask
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBrush* GetOpacityMask();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetOpacityMask(class UNoesisBrush* InOpacityMask);

	// Property Projection
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisProjection* GetProjection();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetProjection(class UNoesisProjection* InProjection);

	// Property RenderSize
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingSize GetRenderSize();

	// Property RenderTransform
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisTransform* GetRenderTransform();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetRenderTransform(class UNoesisTransform* InRenderTransform);

	// Property RenderTransformOrigin
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisDrawingPoint GetRenderTransformOrigin();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetRenderTransformOrigin(FNoesisDrawingPoint InRenderTransformOrigin);

	// Property Visibility
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisVisibility GetVisibility();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetVisibility(ENoesisVisibility InVisibility);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Arrange(FNoesisDrawingRect FinalRect);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool CaptureMouse();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool CaptureTouch(int32 TouchDevice);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool Focus();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisKeyboard* GetKeyboard();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisMouse* GetMouse();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisUIElement* GetUIParent();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisIView* GetUIView();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void InvalidateArrange();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void InvalidateMeasure();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void InvalidateVisual();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsArrangeValid();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsMeasureValid();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Measure(FNoesisDrawingSize AvailableSize);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ReleaseAllTouchCaptures();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ReleaseMouseCapture();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool ReleaseTouchCapture(int32 TouchDevice);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void UpdateLayout();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisDependencyPropertyChangedEventHandler FocusableChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler GotFocus;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisKeyboardFocusChangedEventHandler GotKeyboardFocus;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseEventHandler GotMouseCapture;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisTouchEventHandler GotTouchCapture;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisDependencyPropertyChangedEventHandler IsEnabledChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisDependencyPropertyChangedEventHandler IsHitTestVisibleChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisDependencyPropertyChangedEventHandler IsKeyboardFocusWithinChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisDependencyPropertyChangedEventHandler IsKeyboardFocusedChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisDependencyPropertyChangedEventHandler IsMouseCaptureWithinChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisDependencyPropertyChangedEventHandler IsMouseCapturedChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisDependencyPropertyChangedEventHandler IsMouseDirectlyOverChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisDependencyPropertyChangedEventHandler IsVisibleChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisKeyEventHandler KeyDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisKeyEventHandler KeyUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler LostFocus;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisKeyboardFocusChangedEventHandler LostKeyboardFocus;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseEventHandler LostMouseCapture;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisTouchEventHandler LostTouchCapture;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisManipulationCompletedEventHandler ManipulationCompleted;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisManipulationDeltaEventHandler ManipulationDelta;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisManipulationInertiaStartingEventHandler ManipulationInertiaStarting;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisManipulationStartedEventHandler ManipulationStarted;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisManipulationStartingEventHandler ManipulationStarting;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseButtonEventHandler MouseDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseEventHandler MouseEnter;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseEventHandler MouseLeave;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseButtonEventHandler MouseLeftButtonDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseButtonEventHandler MouseLeftButtonUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseEventHandler MouseMove;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseButtonEventHandler MouseRightButtonDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseButtonEventHandler MouseRightButtonUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseButtonEventHandler MouseUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseWheelEventHandler MouseWheel;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisKeyboardFocusChangedEventHandler PreviewGotKeyboardFocus;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisKeyEventHandler PreviewKeyDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisKeyEventHandler PreviewKeyUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisKeyboardFocusChangedEventHandler PreviewLostKeyboardFocus;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseButtonEventHandler PreviewMouseDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseButtonEventHandler PreviewMouseLeftButtonDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseButtonEventHandler PreviewMouseLeftButtonUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseEventHandler PreviewMouseMove;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseButtonEventHandler PreviewMouseRightButtonDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseButtonEventHandler PreviewMouseRightButtonUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseButtonEventHandler PreviewMouseUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisMouseWheelEventHandler PreviewMouseWheel;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisTextCompositionEventHandler PreviewTextInput;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisTouchEventHandler PreviewTouchDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisTouchEventHandler PreviewTouchMove;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisTouchEventHandler PreviewTouchUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisTextCompositionEventHandler TextInput;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisTouchEventHandler TouchDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisTouchEventHandler TouchEnter;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisTouchEventHandler TouchLeave;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisTouchEventHandler TouchMove;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisTouchEventHandler TouchUp;

	void FocusableChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs);

	void GotFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void GotKeyboardFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyboardFocusChangedEventArgs& InArgs);

	void GotMouseCapture_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs);

	void GotTouchCapture_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs);

	void IsEnabledChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs);

	void IsHitTestVisibleChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs);

	void IsKeyboardFocusWithinChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs);

	void IsKeyboardFocusedChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs);

	void IsMouseCaptureWithinChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs);

	void IsMouseCapturedChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs);

	void IsMouseDirectlyOverChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs);

	void IsVisibleChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs);

	void KeyDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyEventArgs& InArgs);

	void KeyUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyEventArgs& InArgs);

	void LostFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void LostKeyboardFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyboardFocusChangedEventArgs& InArgs);

	void LostMouseCapture_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs);

	void LostTouchCapture_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs);

	void ManipulationCompleted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationCompletedEventArgs& InArgs);

	void ManipulationDelta_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationDeltaEventArgs& InArgs);

	void ManipulationInertiaStarting_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationInertiaStartingEventArgs& InArgs);

	void ManipulationStarted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationStartedEventArgs& InArgs);

	void ManipulationStarting_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationStartingEventArgs& InArgs);

	void MouseDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void MouseEnter_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs);

	void MouseLeave_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs);

	void MouseLeftButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void MouseLeftButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void MouseMove_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs);

	void MouseRightButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void MouseRightButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void MouseUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void MouseWheel_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseWheelEventArgs& InArgs);

	void PreviewGotKeyboardFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyboardFocusChangedEventArgs& InArgs);

	void PreviewKeyDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyEventArgs& InArgs);

	void PreviewKeyUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyEventArgs& InArgs);

	void PreviewLostKeyboardFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyboardFocusChangedEventArgs& InArgs);

	void PreviewMouseDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void PreviewMouseLeftButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void PreviewMouseLeftButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void PreviewMouseMove_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs);

	void PreviewMouseRightButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void PreviewMouseRightButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void PreviewMouseUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void PreviewMouseWheel_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseWheelEventArgs& InArgs);

	void PreviewTextInput_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TextCompositionEventArgs& InArgs);

	void PreviewTouchDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs);

	void PreviewTouchMove_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs);

	void PreviewTouchUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs);

	void TextInput_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TextCompositionEventArgs& InArgs);

	void TouchDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs);

	void TouchEnter_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs);

	void TouchLeave_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs);

	void TouchMove_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs);

	void TouchUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)> FocusableChanged_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> GotFocus_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::KeyboardFocusChangedEventArgs& InArgs)> GotKeyboardFocus_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs)> GotMouseCapture_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)> GotTouchCapture_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)> IsEnabledChanged_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)> IsHitTestVisibleChanged_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)> IsKeyboardFocusWithinChanged_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)> IsKeyboardFocusedChanged_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)> IsMouseCaptureWithinChanged_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)> IsMouseCapturedChanged_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)> IsMouseDirectlyOverChanged_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)> IsVisibleChanged_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::KeyEventArgs& InArgs)> KeyDown_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::KeyEventArgs& InArgs)> KeyUp_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> LostFocus_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::KeyboardFocusChangedEventArgs& InArgs)> LostKeyboardFocus_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs)> LostMouseCapture_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)> LostTouchCapture_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationCompletedEventArgs& InArgs)> ManipulationCompleted_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationDeltaEventArgs& InArgs)> ManipulationDelta_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationInertiaStartingEventArgs& InArgs)> ManipulationInertiaStarting_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationStartedEventArgs& InArgs)> ManipulationStarted_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationStartingEventArgs& InArgs)> ManipulationStarting_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)> MouseDown_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs)> MouseEnter_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs)> MouseLeave_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)> MouseLeftButtonDown_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)> MouseLeftButtonUp_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs)> MouseMove_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)> MouseRightButtonDown_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)> MouseRightButtonUp_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)> MouseUp_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseWheelEventArgs& InArgs)> MouseWheel_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::KeyboardFocusChangedEventArgs& InArgs)> PreviewGotKeyboardFocus_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::KeyEventArgs& InArgs)> PreviewKeyDown_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::KeyEventArgs& InArgs)> PreviewKeyUp_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::KeyboardFocusChangedEventArgs& InArgs)> PreviewLostKeyboardFocus_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)> PreviewMouseDown_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)> PreviewMouseLeftButtonDown_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)> PreviewMouseLeftButtonUp_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs)> PreviewMouseMove_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)> PreviewMouseRightButtonDown_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)> PreviewMouseRightButtonUp_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)> PreviewMouseUp_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseWheelEventArgs& InArgs)> PreviewMouseWheel_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::TextCompositionEventArgs& InArgs)> PreviewTextInput_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)> PreviewTouchDown_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)> PreviewTouchMove_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)> PreviewTouchUp_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::TextCompositionEventArgs& InArgs)> TextInput_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)> TouchDown_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)> TouchEnter_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)> TouchLeave_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)> TouchMove_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)> TouchUp_Delegate;

};

