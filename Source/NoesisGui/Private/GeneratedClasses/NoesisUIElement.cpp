////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisUIElement.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisUIElement::UNoesisUIElement(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::UIElement::StaticGetClassType();
}

void UNoesisUIElement::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(InNoesisComponent);
	check(NoesisUIElement);
}

bool UNoesisUIElement::GetAllowDrop()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->GetAllowDrop();
}

void UNoesisUIElement::SetAllowDrop(bool InAllowDrop)
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	NoesisUIElement->SetAllowDrop(InAllowDrop);
}

class UNoesisGeometry* UNoesisUIElement::GetClip()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return CastChecked<UNoesisGeometry>(CreateClassFor(NoesisUIElement->GetClip(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisUIElement::SetClip(class UNoesisGeometry* InClip)
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	NoesisUIElement->SetClip(NsDynamicCast<Geometry*>(InClip->NoesisComponent.GetPtr()));
}

bool UNoesisUIElement::GetClipToBounds()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->GetClipToBounds();
}

void UNoesisUIElement::SetClipToBounds(bool InClipToBounds)
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	NoesisUIElement->SetClipToBounds(InClipToBounds);
}

class UNoesisCommandBindingCollection* UNoesisUIElement::GetCommandBindings()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return CastChecked<UNoesisCommandBindingCollection>(CreateClassFor(NoesisUIElement->GetCommandBindings(), nullptr), ECastCheckedType::NullAllowed);
}

FNoesisDrawingSize UNoesisUIElement::GetDesiredSize()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return FNoesisDrawingSize(NoesisUIElement->GetDesiredSize());
}

bool UNoesisUIElement::GetFocusable()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->GetFocusable();
}

void UNoesisUIElement::SetFocusable(bool InFocusable)
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	NoesisUIElement->SetFocusable(InFocusable);
}

class UNoesisInputBindingCollection* UNoesisUIElement::GetInputBindings()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return CastChecked<UNoesisInputBindingCollection>(CreateClassFor(NoesisUIElement->GetInputBindings(), nullptr), ECastCheckedType::NullAllowed);
}

bool UNoesisUIElement::GetIsEnabled()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->GetIsEnabled();
}

void UNoesisUIElement::SetIsEnabled(bool InIsEnabled)
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	NoesisUIElement->SetIsEnabled(InIsEnabled);
}

bool UNoesisUIElement::GetIsFocused()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->GetIsFocused();
}

bool UNoesisUIElement::GetIsHitTestVisible()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->GetIsHitTestVisible();
}

void UNoesisUIElement::SetIsHitTestVisible(bool InIsHitTestVisible)
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	NoesisUIElement->SetIsHitTestVisible(InIsHitTestVisible);
}

bool UNoesisUIElement::GetIsKeyboardFocusWithin()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->GetIsKeyboardFocusWithin();
}

bool UNoesisUIElement::GetIsKeyboardFocused()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->GetIsKeyboardFocused();
}

bool UNoesisUIElement::GetIsManipulationEnabled()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->GetIsManipulationEnabled();
}

void UNoesisUIElement::SetIsManipulationEnabled(bool InIsManipulationEnabled)
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	NoesisUIElement->SetIsManipulationEnabled(InIsManipulationEnabled);
}

bool UNoesisUIElement::GetIsMouseCaptureWithin()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->GetIsMouseCaptureWithin();
}

bool UNoesisUIElement::GetIsMouseCaptured()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->GetIsMouseCaptured();
}

bool UNoesisUIElement::GetIsMouseDirectlyOver()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->GetIsMouseDirectlyOver();
}

bool UNoesisUIElement::GetIsMouseOver()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->GetIsMouseOver();
}

bool UNoesisUIElement::GetIsVisible()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->GetIsVisible();
}

float UNoesisUIElement::GetOpacity()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return (float)NoesisUIElement->GetOpacity();
}

void UNoesisUIElement::SetOpacity(float InOpacity)
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	NoesisUIElement->SetOpacity(InOpacity);
}

class UNoesisBrush* UNoesisUIElement::GetOpacityMask()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return CastChecked<UNoesisBrush>(CreateClassFor(NoesisUIElement->GetOpacityMask(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisUIElement::SetOpacityMask(class UNoesisBrush* InOpacityMask)
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	NoesisUIElement->SetOpacityMask(NsDynamicCast<Brush*>(InOpacityMask->NoesisComponent.GetPtr()));
}

class UNoesisProjection* UNoesisUIElement::GetProjection()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return CastChecked<UNoesisProjection>(CreateClassFor(NoesisUIElement->GetProjection(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisUIElement::SetProjection(class UNoesisProjection* InProjection)
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	NoesisUIElement->SetProjection(NsDynamicCast<Projection*>(InProjection->NoesisComponent.GetPtr()));
}

FNoesisDrawingSize UNoesisUIElement::GetRenderSize()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return FNoesisDrawingSize(NoesisUIElement->GetRenderSize());
}

class UNoesisTransform* UNoesisUIElement::GetRenderTransform()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return CastChecked<UNoesisTransform>(CreateClassFor(NoesisUIElement->GetRenderTransform(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisUIElement::SetRenderTransform(class UNoesisTransform* InRenderTransform)
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	NoesisUIElement->SetRenderTransform(NsDynamicCast<Transform*>(InRenderTransform->NoesisComponent.GetPtr()));
}

FNoesisDrawingPoint UNoesisUIElement::GetRenderTransformOrigin()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return FNoesisDrawingPoint(NoesisUIElement->GetRenderTransformOrigin());
}

void UNoesisUIElement::SetRenderTransformOrigin(FNoesisDrawingPoint InRenderTransformOrigin)
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	NoesisUIElement->SetRenderTransformOrigin(InRenderTransformOrigin.ToNoesis());
}

ENoesisVisibility UNoesisUIElement::GetVisibility()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return (ENoesisVisibility)NoesisUIElement->GetVisibility();
}

void UNoesisUIElement::SetVisibility(ENoesisVisibility InVisibility)
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	NoesisUIElement->SetVisibility((Noesis::Gui::Visibility)InVisibility);
}

void UNoesisUIElement::Arrange(FNoesisDrawingRect InFinalRect)
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	const Drawing::Rect NoesisInFinalRect = InFinalRect.ToNoesis();
	return NoesisUIElement->Arrange(NoesisInFinalRect);
}

bool UNoesisUIElement::CaptureMouse()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->CaptureMouse();
}

bool UNoesisUIElement::CaptureTouch(int32 InTouchDevice)
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	NsUInt32 NoesisInTouchDevice = InTouchDevice;
	return NoesisUIElement->CaptureTouch(NoesisInTouchDevice);
}

bool UNoesisUIElement::Focus()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->Focus();
}

class UNoesisKeyboard* UNoesisUIElement::GetKeyboard()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return CastChecked<UNoesisKeyboard>(CreateClassFor(NoesisUIElement->GetKeyboard(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisMouse* UNoesisUIElement::GetMouse()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return CastChecked<UNoesisMouse>(CreateClassFor(NoesisUIElement->GetMouse(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisUIElement* UNoesisUIElement::GetUIParent()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return CastChecked<UNoesisUIElement>(CreateClassFor(NoesisUIElement->GetUIParent(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisIView* UNoesisUIElement::GetUIView()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return CastChecked<UNoesisIView>(CreateInterfaceFor(NoesisUIElement->GetUIView(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisUIElement::InvalidateArrange()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->InvalidateArrange();
}

void UNoesisUIElement::InvalidateMeasure()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->InvalidateMeasure();
}

void UNoesisUIElement::InvalidateVisual()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->InvalidateVisual();
}

bool UNoesisUIElement::IsArrangeValid()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->IsArrangeValid();
}

bool UNoesisUIElement::IsMeasureValid()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->IsMeasureValid();
}

void UNoesisUIElement::Measure(FNoesisDrawingSize InAvailableSize)
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	const Drawing::Size NoesisInAvailableSize = InAvailableSize.ToNoesis();
	return NoesisUIElement->Measure(NoesisInAvailableSize);
}

void UNoesisUIElement::ReleaseAllTouchCaptures()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->ReleaseAllTouchCaptures();
}

void UNoesisUIElement::ReleaseMouseCapture()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->ReleaseMouseCapture();
}

bool UNoesisUIElement::ReleaseTouchCapture(int32 InTouchDevice)
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	NsUInt32 NoesisInTouchDevice = InTouchDevice;
	return NoesisUIElement->ReleaseTouchCapture(NoesisInTouchDevice);
}

void UNoesisUIElement::UpdateLayout()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return NoesisUIElement->UpdateLayout();
}

void UNoesisUIElement::FocusableChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!FocusableChanged.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisDependencyPropertyChangedEventArgs Args(InArgs);
	FocusableChanged.Broadcast(Sender, Args);
}

void UNoesisUIElement::GotFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!GotFocus.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	GotFocus.Broadcast(Sender, Args);
}

void UNoesisUIElement::GotKeyboardFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyboardFocusChangedEventArgs& InArgs)
{
	if (!GotKeyboardFocus.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisKeyboardFocusChangedEventArgs Args(InArgs);
	GotKeyboardFocus.Broadcast(Sender, Args);
}

void UNoesisUIElement::GotMouseCapture_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs)
{
	if (!GotMouseCapture.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseEventArgs Args(InArgs);
	GotMouseCapture.Broadcast(Sender, Args);
}

void UNoesisUIElement::GotTouchCapture_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!GotTouchCapture.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisTouchEventArgs Args(InArgs);
	GotTouchCapture.Broadcast(Sender, Args);
}

void UNoesisUIElement::IsEnabledChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!IsEnabledChanged.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisDependencyPropertyChangedEventArgs Args(InArgs);
	IsEnabledChanged.Broadcast(Sender, Args);
}

void UNoesisUIElement::IsHitTestVisibleChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!IsHitTestVisibleChanged.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisDependencyPropertyChangedEventArgs Args(InArgs);
	IsHitTestVisibleChanged.Broadcast(Sender, Args);
}

void UNoesisUIElement::IsKeyboardFocusWithinChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!IsKeyboardFocusWithinChanged.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisDependencyPropertyChangedEventArgs Args(InArgs);
	IsKeyboardFocusWithinChanged.Broadcast(Sender, Args);
}

void UNoesisUIElement::IsKeyboardFocusedChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!IsKeyboardFocusedChanged.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisDependencyPropertyChangedEventArgs Args(InArgs);
	IsKeyboardFocusedChanged.Broadcast(Sender, Args);
}

void UNoesisUIElement::IsMouseCaptureWithinChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!IsMouseCaptureWithinChanged.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisDependencyPropertyChangedEventArgs Args(InArgs);
	IsMouseCaptureWithinChanged.Broadcast(Sender, Args);
}

void UNoesisUIElement::IsMouseCapturedChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!IsMouseCapturedChanged.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisDependencyPropertyChangedEventArgs Args(InArgs);
	IsMouseCapturedChanged.Broadcast(Sender, Args);
}

void UNoesisUIElement::IsMouseDirectlyOverChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!IsMouseDirectlyOverChanged.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisDependencyPropertyChangedEventArgs Args(InArgs);
	IsMouseDirectlyOverChanged.Broadcast(Sender, Args);
}

void UNoesisUIElement::IsVisibleChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!IsVisibleChanged.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisDependencyPropertyChangedEventArgs Args(InArgs);
	IsVisibleChanged.Broadcast(Sender, Args);
}

void UNoesisUIElement::KeyDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyEventArgs& InArgs)
{
	if (!KeyDown.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisKeyEventArgs Args(InArgs);
	KeyDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::KeyUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyEventArgs& InArgs)
{
	if (!KeyUp.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisKeyEventArgs Args(InArgs);
	KeyUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::LostFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!LostFocus.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	LostFocus.Broadcast(Sender, Args);
}

void UNoesisUIElement::LostKeyboardFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyboardFocusChangedEventArgs& InArgs)
{
	if (!LostKeyboardFocus.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisKeyboardFocusChangedEventArgs Args(InArgs);
	LostKeyboardFocus.Broadcast(Sender, Args);
}

void UNoesisUIElement::LostMouseCapture_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs)
{
	if (!LostMouseCapture.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseEventArgs Args(InArgs);
	LostMouseCapture.Broadcast(Sender, Args);
}

void UNoesisUIElement::LostTouchCapture_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!LostTouchCapture.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisTouchEventArgs Args(InArgs);
	LostTouchCapture.Broadcast(Sender, Args);
}

void UNoesisUIElement::ManipulationCompleted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationCompletedEventArgs& InArgs)
{
	if (!ManipulationCompleted.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisManipulationCompletedEventArgs Args(InArgs);
	ManipulationCompleted.Broadcast(Sender, Args);
	Args.ToNoesis(InArgs);
}

void UNoesisUIElement::ManipulationDelta_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationDeltaEventArgs& InArgs)
{
	if (!ManipulationDelta.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisManipulationDeltaEventArgs Args(InArgs);
	ManipulationDelta.Broadcast(Sender, Args);
	Args.ToNoesis(InArgs);
}

void UNoesisUIElement::ManipulationInertiaStarting_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationInertiaStartingEventArgs& InArgs)
{
	if (!ManipulationInertiaStarting.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisManipulationInertiaStartingEventArgs Args(InArgs);
	ManipulationInertiaStarting.Broadcast(Sender, Args);
	Args.ToNoesis(InArgs);
}

void UNoesisUIElement::ManipulationStarted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationStartedEventArgs& InArgs)
{
	if (!ManipulationStarted.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisManipulationStartedEventArgs Args(InArgs);
	ManipulationStarted.Broadcast(Sender, Args);
	Args.ToNoesis(InArgs);
}

void UNoesisUIElement::ManipulationStarting_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationStartingEventArgs& InArgs)
{
	if (!ManipulationStarting.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisManipulationStartingEventArgs Args(InArgs);
	ManipulationStarting.Broadcast(Sender, Args);
	Args.ToNoesis(InArgs);
}

void UNoesisUIElement::MouseDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!MouseDown.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseButtonEventArgs Args(InArgs);
	MouseDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::MouseEnter_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs)
{
	if (!MouseEnter.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseEventArgs Args(InArgs);
	MouseEnter.Broadcast(Sender, Args);
}

void UNoesisUIElement::MouseLeave_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs)
{
	if (!MouseLeave.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseEventArgs Args(InArgs);
	MouseLeave.Broadcast(Sender, Args);
}

void UNoesisUIElement::MouseLeftButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!MouseLeftButtonDown.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseButtonEventArgs Args(InArgs);
	MouseLeftButtonDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::MouseLeftButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!MouseLeftButtonUp.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseButtonEventArgs Args(InArgs);
	MouseLeftButtonUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::MouseMove_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs)
{
	if (!MouseMove.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseEventArgs Args(InArgs);
	MouseMove.Broadcast(Sender, Args);
}

void UNoesisUIElement::MouseRightButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!MouseRightButtonDown.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseButtonEventArgs Args(InArgs);
	MouseRightButtonDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::MouseRightButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!MouseRightButtonUp.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseButtonEventArgs Args(InArgs);
	MouseRightButtonUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::MouseUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!MouseUp.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseButtonEventArgs Args(InArgs);
	MouseUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::MouseWheel_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseWheelEventArgs& InArgs)
{
	if (!MouseWheel.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseWheelEventArgs Args(InArgs);
	MouseWheel.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewGotKeyboardFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyboardFocusChangedEventArgs& InArgs)
{
	if (!PreviewGotKeyboardFocus.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisKeyboardFocusChangedEventArgs Args(InArgs);
	PreviewGotKeyboardFocus.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewKeyDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyEventArgs& InArgs)
{
	if (!PreviewKeyDown.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisKeyEventArgs Args(InArgs);
	PreviewKeyDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewKeyUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyEventArgs& InArgs)
{
	if (!PreviewKeyUp.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisKeyEventArgs Args(InArgs);
	PreviewKeyUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewLostKeyboardFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyboardFocusChangedEventArgs& InArgs)
{
	if (!PreviewLostKeyboardFocus.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisKeyboardFocusChangedEventArgs Args(InArgs);
	PreviewLostKeyboardFocus.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewMouseDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!PreviewMouseDown.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseButtonEventArgs Args(InArgs);
	PreviewMouseDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewMouseLeftButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!PreviewMouseLeftButtonDown.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseButtonEventArgs Args(InArgs);
	PreviewMouseLeftButtonDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewMouseLeftButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!PreviewMouseLeftButtonUp.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseButtonEventArgs Args(InArgs);
	PreviewMouseLeftButtonUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewMouseMove_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs)
{
	if (!PreviewMouseMove.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseEventArgs Args(InArgs);
	PreviewMouseMove.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewMouseRightButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!PreviewMouseRightButtonDown.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseButtonEventArgs Args(InArgs);
	PreviewMouseRightButtonDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewMouseRightButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!PreviewMouseRightButtonUp.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseButtonEventArgs Args(InArgs);
	PreviewMouseRightButtonUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewMouseUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!PreviewMouseUp.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseButtonEventArgs Args(InArgs);
	PreviewMouseUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewMouseWheel_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseWheelEventArgs& InArgs)
{
	if (!PreviewMouseWheel.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisMouseWheelEventArgs Args(InArgs);
	PreviewMouseWheel.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewTextInput_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TextCompositionEventArgs& InArgs)
{
	if (!PreviewTextInput.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisTextCompositionEventArgs Args(InArgs);
	PreviewTextInput.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewTouchDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!PreviewTouchDown.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisTouchEventArgs Args(InArgs);
	PreviewTouchDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewTouchMove_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!PreviewTouchMove.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisTouchEventArgs Args(InArgs);
	PreviewTouchMove.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewTouchUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!PreviewTouchUp.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisTouchEventArgs Args(InArgs);
	PreviewTouchUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::TextInput_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TextCompositionEventArgs& InArgs)
{
	if (!TextInput.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisTextCompositionEventArgs Args(InArgs);
	TextInput.Broadcast(Sender, Args);
}

void UNoesisUIElement::TouchDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!TouchDown.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisTouchEventArgs Args(InArgs);
	TouchDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::TouchEnter_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!TouchEnter.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisTouchEventArgs Args(InArgs);
	TouchEnter.Broadcast(Sender, Args);
}

void UNoesisUIElement::TouchLeave_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!TouchLeave.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisTouchEventArgs Args(InArgs);
	TouchLeave.Broadcast(Sender, Args);
}

void UNoesisUIElement::TouchMove_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!TouchMove.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisTouchEventArgs Args(InArgs);
	TouchMove.Broadcast(Sender, Args);
}

void UNoesisUIElement::TouchUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!TouchUp.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisTouchEventArgs Args(InArgs);
	TouchUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);

	FocusableChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::FocusableChanged_Private);
	NoesisUIElement->FocusableChanged() += FocusableChanged_Delegate;
	GotFocus_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::GotFocus_Private);
	NoesisUIElement->GotFocus() += GotFocus_Delegate;
	GotKeyboardFocus_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::GotKeyboardFocus_Private);
	NoesisUIElement->GotKeyboardFocus() += GotKeyboardFocus_Delegate;
	GotMouseCapture_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::GotMouseCapture_Private);
	NoesisUIElement->GotMouseCapture() += GotMouseCapture_Delegate;
	GotTouchCapture_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::GotTouchCapture_Private);
	NoesisUIElement->GotTouchCapture() += GotTouchCapture_Delegate;
	IsEnabledChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::IsEnabledChanged_Private);
	NoesisUIElement->IsEnabledChanged() += IsEnabledChanged_Delegate;
	IsHitTestVisibleChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::IsHitTestVisibleChanged_Private);
	NoesisUIElement->IsHitTestVisibleChanged() += IsHitTestVisibleChanged_Delegate;
	IsKeyboardFocusWithinChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::IsKeyboardFocusWithinChanged_Private);
	NoesisUIElement->IsKeyboardFocusWithinChanged() += IsKeyboardFocusWithinChanged_Delegate;
	IsKeyboardFocusedChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::IsKeyboardFocusedChanged_Private);
	NoesisUIElement->IsKeyboardFocusedChanged() += IsKeyboardFocusedChanged_Delegate;
	IsMouseCaptureWithinChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::IsMouseCaptureWithinChanged_Private);
	NoesisUIElement->IsMouseCaptureWithinChanged() += IsMouseCaptureWithinChanged_Delegate;
	IsMouseCapturedChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::IsMouseCapturedChanged_Private);
	NoesisUIElement->IsMouseCapturedChanged() += IsMouseCapturedChanged_Delegate;
	IsMouseDirectlyOverChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::IsMouseDirectlyOverChanged_Private);
	NoesisUIElement->IsMouseDirectlyOverChanged() += IsMouseDirectlyOverChanged_Delegate;
	IsVisibleChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::IsVisibleChanged_Private);
	NoesisUIElement->IsVisibleChanged() += IsVisibleChanged_Delegate;
	KeyDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::KeyDown_Private);
	NoesisUIElement->KeyDown() += KeyDown_Delegate;
	KeyUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::KeyUp_Private);
	NoesisUIElement->KeyUp() += KeyUp_Delegate;
	LostFocus_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::LostFocus_Private);
	NoesisUIElement->LostFocus() += LostFocus_Delegate;
	LostKeyboardFocus_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::LostKeyboardFocus_Private);
	NoesisUIElement->LostKeyboardFocus() += LostKeyboardFocus_Delegate;
	LostMouseCapture_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::LostMouseCapture_Private);
	NoesisUIElement->LostMouseCapture() += LostMouseCapture_Delegate;
	LostTouchCapture_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::LostTouchCapture_Private);
	NoesisUIElement->LostTouchCapture() += LostTouchCapture_Delegate;
	ManipulationCompleted_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::ManipulationCompleted_Private);
	NoesisUIElement->ManipulationCompleted() += ManipulationCompleted_Delegate;
	ManipulationDelta_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::ManipulationDelta_Private);
	NoesisUIElement->ManipulationDelta() += ManipulationDelta_Delegate;
	ManipulationInertiaStarting_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::ManipulationInertiaStarting_Private);
	NoesisUIElement->ManipulationInertiaStarting() += ManipulationInertiaStarting_Delegate;
	ManipulationStarted_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::ManipulationStarted_Private);
	NoesisUIElement->ManipulationStarted() += ManipulationStarted_Delegate;
	ManipulationStarting_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::ManipulationStarting_Private);
	NoesisUIElement->ManipulationStarting() += ManipulationStarting_Delegate;
	MouseDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseDown_Private);
	NoesisUIElement->MouseDown() += MouseDown_Delegate;
	MouseEnter_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseEnter_Private);
	NoesisUIElement->MouseEnter() += MouseEnter_Delegate;
	MouseLeave_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseLeave_Private);
	NoesisUIElement->MouseLeave() += MouseLeave_Delegate;
	MouseLeftButtonDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseLeftButtonDown_Private);
	NoesisUIElement->MouseLeftButtonDown() += MouseLeftButtonDown_Delegate;
	MouseLeftButtonUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseLeftButtonUp_Private);
	NoesisUIElement->MouseLeftButtonUp() += MouseLeftButtonUp_Delegate;
	MouseMove_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseMove_Private);
	NoesisUIElement->MouseMove() += MouseMove_Delegate;
	MouseRightButtonDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseRightButtonDown_Private);
	NoesisUIElement->MouseRightButtonDown() += MouseRightButtonDown_Delegate;
	MouseRightButtonUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseRightButtonUp_Private);
	NoesisUIElement->MouseRightButtonUp() += MouseRightButtonUp_Delegate;
	MouseUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseUp_Private);
	NoesisUIElement->MouseUp() += MouseUp_Delegate;
	MouseWheel_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseWheel_Private);
	NoesisUIElement->MouseWheel() += MouseWheel_Delegate;
	PreviewGotKeyboardFocus_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewGotKeyboardFocus_Private);
	NoesisUIElement->PreviewGotKeyboardFocus() += PreviewGotKeyboardFocus_Delegate;
	PreviewKeyDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewKeyDown_Private);
	NoesisUIElement->PreviewKeyDown() += PreviewKeyDown_Delegate;
	PreviewKeyUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewKeyUp_Private);
	NoesisUIElement->PreviewKeyUp() += PreviewKeyUp_Delegate;
	PreviewLostKeyboardFocus_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewLostKeyboardFocus_Private);
	NoesisUIElement->PreviewLostKeyboardFocus() += PreviewLostKeyboardFocus_Delegate;
	PreviewMouseDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewMouseDown_Private);
	NoesisUIElement->PreviewMouseDown() += PreviewMouseDown_Delegate;
	PreviewMouseLeftButtonDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewMouseLeftButtonDown_Private);
	NoesisUIElement->PreviewMouseLeftButtonDown() += PreviewMouseLeftButtonDown_Delegate;
	PreviewMouseLeftButtonUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewMouseLeftButtonUp_Private);
	NoesisUIElement->PreviewMouseLeftButtonUp() += PreviewMouseLeftButtonUp_Delegate;
	PreviewMouseMove_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewMouseMove_Private);
	NoesisUIElement->PreviewMouseMove() += PreviewMouseMove_Delegate;
	PreviewMouseRightButtonDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewMouseRightButtonDown_Private);
	NoesisUIElement->PreviewMouseRightButtonDown() += PreviewMouseRightButtonDown_Delegate;
	PreviewMouseRightButtonUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewMouseRightButtonUp_Private);
	NoesisUIElement->PreviewMouseRightButtonUp() += PreviewMouseRightButtonUp_Delegate;
	PreviewMouseUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewMouseUp_Private);
	NoesisUIElement->PreviewMouseUp() += PreviewMouseUp_Delegate;
	PreviewMouseWheel_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewMouseWheel_Private);
	NoesisUIElement->PreviewMouseWheel() += PreviewMouseWheel_Delegate;
	PreviewTextInput_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewTextInput_Private);
	NoesisUIElement->PreviewTextInput() += PreviewTextInput_Delegate;
	PreviewTouchDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewTouchDown_Private);
	NoesisUIElement->PreviewTouchDown() += PreviewTouchDown_Delegate;
	PreviewTouchMove_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewTouchMove_Private);
	NoesisUIElement->PreviewTouchMove() += PreviewTouchMove_Delegate;
	PreviewTouchUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewTouchUp_Private);
	NoesisUIElement->PreviewTouchUp() += PreviewTouchUp_Delegate;
	TextInput_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::TextInput_Private);
	NoesisUIElement->TextInput() += TextInput_Delegate;
	TouchDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::TouchDown_Private);
	NoesisUIElement->TouchDown() += TouchDown_Delegate;
	TouchEnter_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::TouchEnter_Private);
	NoesisUIElement->TouchEnter() += TouchEnter_Delegate;
	TouchLeave_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::TouchLeave_Private);
	NoesisUIElement->TouchLeave() += TouchLeave_Delegate;
	TouchMove_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::TouchMove_Private);
	NoesisUIElement->TouchMove() += TouchMove_Delegate;
	TouchUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::TouchUp_Private);
	NoesisUIElement->TouchUp() += TouchUp_Delegate;

}

void UNoesisUIElement::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);

	NoesisUIElement->FocusableChanged() -= FocusableChanged_Delegate;
	NoesisUIElement->GotFocus() -= GotFocus_Delegate;
	NoesisUIElement->GotKeyboardFocus() -= GotKeyboardFocus_Delegate;
	NoesisUIElement->GotMouseCapture() -= GotMouseCapture_Delegate;
	NoesisUIElement->GotTouchCapture() -= GotTouchCapture_Delegate;
	NoesisUIElement->IsEnabledChanged() -= IsEnabledChanged_Delegate;
	NoesisUIElement->IsHitTestVisibleChanged() -= IsHitTestVisibleChanged_Delegate;
	NoesisUIElement->IsKeyboardFocusWithinChanged() -= IsKeyboardFocusWithinChanged_Delegate;
	NoesisUIElement->IsKeyboardFocusedChanged() -= IsKeyboardFocusedChanged_Delegate;
	NoesisUIElement->IsMouseCaptureWithinChanged() -= IsMouseCaptureWithinChanged_Delegate;
	NoesisUIElement->IsMouseCapturedChanged() -= IsMouseCapturedChanged_Delegate;
	NoesisUIElement->IsMouseDirectlyOverChanged() -= IsMouseDirectlyOverChanged_Delegate;
	NoesisUIElement->IsVisibleChanged() -= IsVisibleChanged_Delegate;
	NoesisUIElement->KeyDown() -= KeyDown_Delegate;
	NoesisUIElement->KeyUp() -= KeyUp_Delegate;
	NoesisUIElement->LostFocus() -= LostFocus_Delegate;
	NoesisUIElement->LostKeyboardFocus() -= LostKeyboardFocus_Delegate;
	NoesisUIElement->LostMouseCapture() -= LostMouseCapture_Delegate;
	NoesisUIElement->LostTouchCapture() -= LostTouchCapture_Delegate;
	NoesisUIElement->ManipulationCompleted() -= ManipulationCompleted_Delegate;
	NoesisUIElement->ManipulationDelta() -= ManipulationDelta_Delegate;
	NoesisUIElement->ManipulationInertiaStarting() -= ManipulationInertiaStarting_Delegate;
	NoesisUIElement->ManipulationStarted() -= ManipulationStarted_Delegate;
	NoesisUIElement->ManipulationStarting() -= ManipulationStarting_Delegate;
	NoesisUIElement->MouseDown() -= MouseDown_Delegate;
	NoesisUIElement->MouseEnter() -= MouseEnter_Delegate;
	NoesisUIElement->MouseLeave() -= MouseLeave_Delegate;
	NoesisUIElement->MouseLeftButtonDown() -= MouseLeftButtonDown_Delegate;
	NoesisUIElement->MouseLeftButtonUp() -= MouseLeftButtonUp_Delegate;
	NoesisUIElement->MouseMove() -= MouseMove_Delegate;
	NoesisUIElement->MouseRightButtonDown() -= MouseRightButtonDown_Delegate;
	NoesisUIElement->MouseRightButtonUp() -= MouseRightButtonUp_Delegate;
	NoesisUIElement->MouseUp() -= MouseUp_Delegate;
	NoesisUIElement->MouseWheel() -= MouseWheel_Delegate;
	NoesisUIElement->PreviewGotKeyboardFocus() -= PreviewGotKeyboardFocus_Delegate;
	NoesisUIElement->PreviewKeyDown() -= PreviewKeyDown_Delegate;
	NoesisUIElement->PreviewKeyUp() -= PreviewKeyUp_Delegate;
	NoesisUIElement->PreviewLostKeyboardFocus() -= PreviewLostKeyboardFocus_Delegate;
	NoesisUIElement->PreviewMouseDown() -= PreviewMouseDown_Delegate;
	NoesisUIElement->PreviewMouseLeftButtonDown() -= PreviewMouseLeftButtonDown_Delegate;
	NoesisUIElement->PreviewMouseLeftButtonUp() -= PreviewMouseLeftButtonUp_Delegate;
	NoesisUIElement->PreviewMouseMove() -= PreviewMouseMove_Delegate;
	NoesisUIElement->PreviewMouseRightButtonDown() -= PreviewMouseRightButtonDown_Delegate;
	NoesisUIElement->PreviewMouseRightButtonUp() -= PreviewMouseRightButtonUp_Delegate;
	NoesisUIElement->PreviewMouseUp() -= PreviewMouseUp_Delegate;
	NoesisUIElement->PreviewMouseWheel() -= PreviewMouseWheel_Delegate;
	NoesisUIElement->PreviewTextInput() -= PreviewTextInput_Delegate;
	NoesisUIElement->PreviewTouchDown() -= PreviewTouchDown_Delegate;
	NoesisUIElement->PreviewTouchMove() -= PreviewTouchMove_Delegate;
	NoesisUIElement->PreviewTouchUp() -= PreviewTouchUp_Delegate;
	NoesisUIElement->TextInput() -= TextInput_Delegate;
	NoesisUIElement->TouchDown() -= TouchDown_Delegate;
	NoesisUIElement->TouchEnter() -= TouchEnter_Delegate;
	NoesisUIElement->TouchLeave() -= TouchLeave_Delegate;
	NoesisUIElement->TouchMove() -= TouchMove_Delegate;
	NoesisUIElement->TouchUp() -= TouchUp_Delegate;

}

