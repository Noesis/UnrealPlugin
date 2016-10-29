////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiVisual.h"
#include "NoesisGuiUIElement.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiUIElement : public UNoesisGuiVisual
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property CommandBindings
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiCommandBindingCollection* GetCommandBindings();

	// Property DesiredSize
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisGuiDrawingSize GetDesiredSize();

	// Property InputBindings
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiInputBindingCollection* GetInputBindings();

	// Property RenderSize
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FNoesisGuiDrawingSize GetRenderSize();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Arrange(FNoesisGuiDrawingRect FinalRect);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool CaptureMouse();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool CaptureTouch(int32 TouchDevice);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool Focus();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiKeyboard* GetKeyboard();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiMouse* GetMouse();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiUIElement* GetUIParent();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiIView* GetUIView();

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
void Measure(FNoesisGuiDrawingSize AvailableSize);

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
	FNoesisGuiDependencyPropertyChangedEventHandler FocusableChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiRoutedEventHandler GotFocus;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiKeyboardFocusChangedEventHandler GotKeyboardFocus;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseEventHandler GotMouseCapture;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiTouchEventHandler GotTouchCapture;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiDependencyPropertyChangedEventHandler IsEnabledChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiDependencyPropertyChangedEventHandler IsHitTestVisibleChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiDependencyPropertyChangedEventHandler IsKeyboardFocusWithinChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiDependencyPropertyChangedEventHandler IsKeyboardFocusedChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiDependencyPropertyChangedEventHandler IsMouseCaptureWithinChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiDependencyPropertyChangedEventHandler IsMouseCapturedChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiDependencyPropertyChangedEventHandler IsMouseDirectlyOverChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiDependencyPropertyChangedEventHandler IsVisibleChanged;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiKeyEventHandler KeyDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiKeyEventHandler KeyUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiRoutedEventHandler LostFocus;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiKeyboardFocusChangedEventHandler LostKeyboardFocus;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseEventHandler LostMouseCapture;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiTouchEventHandler LostTouchCapture;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiManipulationCompletedEventHandler ManipulationCompleted;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiManipulationDeltaEventHandler ManipulationDelta;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiManipulationInertiaStartingEventHandler ManipulationInertiaStarting;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiManipulationStartedEventHandler ManipulationStarted;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiManipulationStartingEventHandler ManipulationStarting;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler MouseDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseEventHandler MouseEnter;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseEventHandler MouseLeave;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler MouseLeftButtonDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler MouseLeftButtonUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseEventHandler MouseMove;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler MouseRightButtonDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler MouseRightButtonUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler MouseUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseWheelEventHandler MouseWheel;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiKeyboardFocusChangedEventHandler PreviewGotKeyboardFocus;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiKeyEventHandler PreviewKeyDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiKeyEventHandler PreviewKeyUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiKeyboardFocusChangedEventHandler PreviewLostKeyboardFocus;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler PreviewMouseDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler PreviewMouseLeftButtonDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler PreviewMouseLeftButtonUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseEventHandler PreviewMouseMove;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler PreviewMouseRightButtonDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler PreviewMouseRightButtonUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler PreviewMouseUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseWheelEventHandler PreviewMouseWheel;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiTextCompositionEventHandler PreviewTextInput;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiTouchEventHandler PreviewTouchDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiTouchEventHandler PreviewTouchMove;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiTouchEventHandler PreviewTouchUp;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiTextCompositionEventHandler TextInput;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiTouchEventHandler TouchDown;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiTouchEventHandler TouchEnter;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiTouchEventHandler TouchLeave;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiTouchEventHandler TouchMove;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiTouchEventHandler TouchUp;

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

