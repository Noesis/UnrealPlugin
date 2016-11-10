////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisUIElement.h"

using namespace Noesis;
using namespace Gui;

UNoesisUIElement::UNoesisUIElement(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
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
	return CastChecked<UNoesisGeometry>(Instance->FindUnrealComponentForNoesisComponent(NoesisUIElement->GetClip()));
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
	return CastChecked<UNoesisCommandBindingCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisUIElement->GetCommandBindings()));
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
	return CastChecked<UNoesisInputBindingCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisUIElement->GetInputBindings()));
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
	return CastChecked<UNoesisBrush>(Instance->FindUnrealComponentForNoesisComponent(NoesisUIElement->GetOpacityMask()));
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
	return CastChecked<UNoesisProjection>(Instance->FindUnrealComponentForNoesisComponent(NoesisUIElement->GetProjection()));
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
	return CastChecked<UNoesisTransform>(Instance->FindUnrealComponentForNoesisComponent(NoesisUIElement->GetRenderTransform()));
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
	return CastChecked<UNoesisKeyboard>(Instance->FindUnrealComponentForNoesisComponent(NoesisUIElement->GetKeyboard()));
}

class UNoesisMouse* UNoesisUIElement::GetMouse()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return CastChecked<UNoesisMouse>(Instance->FindUnrealComponentForNoesisComponent(NoesisUIElement->GetMouse()));
}

class UNoesisUIElement* UNoesisUIElement::GetUIParent()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return CastChecked<UNoesisUIElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisUIElement->GetUIParent()));
}

class UNoesisIView* UNoesisUIElement::GetUIView()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return CastChecked<UNoesisIView>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisUIElement->GetUIView()));
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
	if (!FocusableChanged.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisDependencyPropertyChangedEventArgs Args(Instance, InArgs);
	FocusableChanged.Broadcast(Sender, Args);
}

void UNoesisUIElement::GotFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!GotFocus.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	GotFocus.Broadcast(Sender, Args);
}

void UNoesisUIElement::GotKeyboardFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyboardFocusChangedEventArgs& InArgs)
{
	if (!GotKeyboardFocus.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisKeyboardFocusChangedEventArgs Args(Instance, InArgs);
	GotKeyboardFocus.Broadcast(Sender, Args);
}

void UNoesisUIElement::GotMouseCapture_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs)
{
	if (!GotMouseCapture.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseEventArgs Args(Instance, InArgs);
	GotMouseCapture.Broadcast(Sender, Args);
}

void UNoesisUIElement::GotTouchCapture_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!GotTouchCapture.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisTouchEventArgs Args(Instance, InArgs);
	GotTouchCapture.Broadcast(Sender, Args);
}

void UNoesisUIElement::IsEnabledChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!IsEnabledChanged.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisDependencyPropertyChangedEventArgs Args(Instance, InArgs);
	IsEnabledChanged.Broadcast(Sender, Args);
}

void UNoesisUIElement::IsHitTestVisibleChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!IsHitTestVisibleChanged.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisDependencyPropertyChangedEventArgs Args(Instance, InArgs);
	IsHitTestVisibleChanged.Broadcast(Sender, Args);
}

void UNoesisUIElement::IsKeyboardFocusWithinChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!IsKeyboardFocusWithinChanged.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisDependencyPropertyChangedEventArgs Args(Instance, InArgs);
	IsKeyboardFocusWithinChanged.Broadcast(Sender, Args);
}

void UNoesisUIElement::IsKeyboardFocusedChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!IsKeyboardFocusedChanged.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisDependencyPropertyChangedEventArgs Args(Instance, InArgs);
	IsKeyboardFocusedChanged.Broadcast(Sender, Args);
}

void UNoesisUIElement::IsMouseCaptureWithinChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!IsMouseCaptureWithinChanged.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisDependencyPropertyChangedEventArgs Args(Instance, InArgs);
	IsMouseCaptureWithinChanged.Broadcast(Sender, Args);
}

void UNoesisUIElement::IsMouseCapturedChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!IsMouseCapturedChanged.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisDependencyPropertyChangedEventArgs Args(Instance, InArgs);
	IsMouseCapturedChanged.Broadcast(Sender, Args);
}

void UNoesisUIElement::IsMouseDirectlyOverChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!IsMouseDirectlyOverChanged.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisDependencyPropertyChangedEventArgs Args(Instance, InArgs);
	IsMouseDirectlyOverChanged.Broadcast(Sender, Args);
}

void UNoesisUIElement::IsVisibleChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!IsVisibleChanged.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisDependencyPropertyChangedEventArgs Args(Instance, InArgs);
	IsVisibleChanged.Broadcast(Sender, Args);
}

void UNoesisUIElement::KeyDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyEventArgs& InArgs)
{
	if (!KeyDown.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisKeyEventArgs Args(Instance, InArgs);
	KeyDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::KeyUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyEventArgs& InArgs)
{
	if (!KeyUp.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisKeyEventArgs Args(Instance, InArgs);
	KeyUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::LostFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!LostFocus.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	LostFocus.Broadcast(Sender, Args);
}

void UNoesisUIElement::LostKeyboardFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyboardFocusChangedEventArgs& InArgs)
{
	if (!LostKeyboardFocus.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisKeyboardFocusChangedEventArgs Args(Instance, InArgs);
	LostKeyboardFocus.Broadcast(Sender, Args);
}

void UNoesisUIElement::LostMouseCapture_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs)
{
	if (!LostMouseCapture.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseEventArgs Args(Instance, InArgs);
	LostMouseCapture.Broadcast(Sender, Args);
}

void UNoesisUIElement::LostTouchCapture_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!LostTouchCapture.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisTouchEventArgs Args(Instance, InArgs);
	LostTouchCapture.Broadcast(Sender, Args);
}

void UNoesisUIElement::ManipulationCompleted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationCompletedEventArgs& InArgs)
{
	if (!ManipulationCompleted.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisManipulationCompletedEventArgs Args(Instance, InArgs);
	ManipulationCompleted.Broadcast(Sender, Args);
	Args.ToNoesis(InArgs);
}

void UNoesisUIElement::ManipulationDelta_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationDeltaEventArgs& InArgs)
{
	if (!ManipulationDelta.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisManipulationDeltaEventArgs Args(Instance, InArgs);
	ManipulationDelta.Broadcast(Sender, Args);
	Args.ToNoesis(InArgs);
}

void UNoesisUIElement::ManipulationInertiaStarting_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationInertiaStartingEventArgs& InArgs)
{
	if (!ManipulationInertiaStarting.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisManipulationInertiaStartingEventArgs Args(Instance, InArgs);
	ManipulationInertiaStarting.Broadcast(Sender, Args);
	Args.ToNoesis(InArgs);
}

void UNoesisUIElement::ManipulationStarted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationStartedEventArgs& InArgs)
{
	if (!ManipulationStarted.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisManipulationStartedEventArgs Args(Instance, InArgs);
	ManipulationStarted.Broadcast(Sender, Args);
	Args.ToNoesis(InArgs);
}

void UNoesisUIElement::ManipulationStarting_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ManipulationStartingEventArgs& InArgs)
{
	if (!ManipulationStarting.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisManipulationStartingEventArgs Args(Instance, InArgs);
	ManipulationStarting.Broadcast(Sender, Args);
	Args.ToNoesis(InArgs);
}

void UNoesisUIElement::MouseDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!MouseDown.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseButtonEventArgs Args(Instance, InArgs);
	MouseDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::MouseEnter_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs)
{
	if (!MouseEnter.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseEventArgs Args(Instance, InArgs);
	MouseEnter.Broadcast(Sender, Args);
}

void UNoesisUIElement::MouseLeave_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs)
{
	if (!MouseLeave.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseEventArgs Args(Instance, InArgs);
	MouseLeave.Broadcast(Sender, Args);
}

void UNoesisUIElement::MouseLeftButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!MouseLeftButtonDown.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseButtonEventArgs Args(Instance, InArgs);
	MouseLeftButtonDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::MouseLeftButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!MouseLeftButtonUp.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseButtonEventArgs Args(Instance, InArgs);
	MouseLeftButtonUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::MouseMove_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs)
{
	if (!MouseMove.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseEventArgs Args(Instance, InArgs);
	MouseMove.Broadcast(Sender, Args);
}

void UNoesisUIElement::MouseRightButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!MouseRightButtonDown.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseButtonEventArgs Args(Instance, InArgs);
	MouseRightButtonDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::MouseRightButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!MouseRightButtonUp.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseButtonEventArgs Args(Instance, InArgs);
	MouseRightButtonUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::MouseUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!MouseUp.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseButtonEventArgs Args(Instance, InArgs);
	MouseUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::MouseWheel_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseWheelEventArgs& InArgs)
{
	if (!MouseWheel.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseWheelEventArgs Args(Instance, InArgs);
	MouseWheel.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewGotKeyboardFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyboardFocusChangedEventArgs& InArgs)
{
	if (!PreviewGotKeyboardFocus.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisKeyboardFocusChangedEventArgs Args(Instance, InArgs);
	PreviewGotKeyboardFocus.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewKeyDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyEventArgs& InArgs)
{
	if (!PreviewKeyDown.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisKeyEventArgs Args(Instance, InArgs);
	PreviewKeyDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewKeyUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyEventArgs& InArgs)
{
	if (!PreviewKeyUp.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisKeyEventArgs Args(Instance, InArgs);
	PreviewKeyUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewLostKeyboardFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::KeyboardFocusChangedEventArgs& InArgs)
{
	if (!PreviewLostKeyboardFocus.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisKeyboardFocusChangedEventArgs Args(Instance, InArgs);
	PreviewLostKeyboardFocus.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewMouseDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!PreviewMouseDown.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseButtonEventArgs Args(Instance, InArgs);
	PreviewMouseDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewMouseLeftButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!PreviewMouseLeftButtonDown.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseButtonEventArgs Args(Instance, InArgs);
	PreviewMouseLeftButtonDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewMouseLeftButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!PreviewMouseLeftButtonUp.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseButtonEventArgs Args(Instance, InArgs);
	PreviewMouseLeftButtonUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewMouseMove_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseEventArgs& InArgs)
{
	if (!PreviewMouseMove.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseEventArgs Args(Instance, InArgs);
	PreviewMouseMove.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewMouseRightButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!PreviewMouseRightButtonDown.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseButtonEventArgs Args(Instance, InArgs);
	PreviewMouseRightButtonDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewMouseRightButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!PreviewMouseRightButtonUp.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseButtonEventArgs Args(Instance, InArgs);
	PreviewMouseRightButtonUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewMouseUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!PreviewMouseUp.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseButtonEventArgs Args(Instance, InArgs);
	PreviewMouseUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewMouseWheel_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseWheelEventArgs& InArgs)
{
	if (!PreviewMouseWheel.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisMouseWheelEventArgs Args(Instance, InArgs);
	PreviewMouseWheel.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewTextInput_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TextCompositionEventArgs& InArgs)
{
	if (!PreviewTextInput.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisTextCompositionEventArgs Args(Instance, InArgs);
	PreviewTextInput.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewTouchDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!PreviewTouchDown.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisTouchEventArgs Args(Instance, InArgs);
	PreviewTouchDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewTouchMove_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!PreviewTouchMove.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisTouchEventArgs Args(Instance, InArgs);
	PreviewTouchMove.Broadcast(Sender, Args);
}

void UNoesisUIElement::PreviewTouchUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!PreviewTouchUp.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisTouchEventArgs Args(Instance, InArgs);
	PreviewTouchUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::TextInput_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TextCompositionEventArgs& InArgs)
{
	if (!TextInput.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisTextCompositionEventArgs Args(Instance, InArgs);
	TextInput.Broadcast(Sender, Args);
}

void UNoesisUIElement::TouchDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!TouchDown.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisTouchEventArgs Args(Instance, InArgs);
	TouchDown.Broadcast(Sender, Args);
}

void UNoesisUIElement::TouchEnter_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!TouchEnter.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisTouchEventArgs Args(Instance, InArgs);
	TouchEnter.Broadcast(Sender, Args);
}

void UNoesisUIElement::TouchLeave_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!TouchLeave.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisTouchEventArgs Args(Instance, InArgs);
	TouchLeave.Broadcast(Sender, Args);
}

void UNoesisUIElement::TouchMove_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!TouchMove.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisTouchEventArgs Args(Instance, InArgs);
	TouchMove.Broadcast(Sender, Args);
}

void UNoesisUIElement::TouchUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TouchEventArgs& InArgs)
{
	if (!TouchUp.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisTouchEventArgs Args(Instance, InArgs);
	TouchUp.Broadcast(Sender, Args);
}

void UNoesisUIElement::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement)

	FocusableChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::FocusableChanged_Private);
	if (FocusableChanged.IsBound())
	{
		NoesisUIElement->FocusableChanged() += FocusableChanged_Delegate;
	}
	GotFocus_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::GotFocus_Private);
	if (GotFocus.IsBound())
	{
		NoesisUIElement->GotFocus() += GotFocus_Delegate;
	}
	GotKeyboardFocus_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::GotKeyboardFocus_Private);
	if (GotKeyboardFocus.IsBound())
	{
		NoesisUIElement->GotKeyboardFocus() += GotKeyboardFocus_Delegate;
	}
	GotMouseCapture_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::GotMouseCapture_Private);
	if (GotMouseCapture.IsBound())
	{
		NoesisUIElement->GotMouseCapture() += GotMouseCapture_Delegate;
	}
	GotTouchCapture_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::GotTouchCapture_Private);
	if (GotTouchCapture.IsBound())
	{
		NoesisUIElement->GotTouchCapture() += GotTouchCapture_Delegate;
	}
	IsEnabledChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::IsEnabledChanged_Private);
	if (IsEnabledChanged.IsBound())
	{
		NoesisUIElement->IsEnabledChanged() += IsEnabledChanged_Delegate;
	}
	IsHitTestVisibleChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::IsHitTestVisibleChanged_Private);
	if (IsHitTestVisibleChanged.IsBound())
	{
		NoesisUIElement->IsHitTestVisibleChanged() += IsHitTestVisibleChanged_Delegate;
	}
	IsKeyboardFocusWithinChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::IsKeyboardFocusWithinChanged_Private);
	if (IsKeyboardFocusWithinChanged.IsBound())
	{
		NoesisUIElement->IsKeyboardFocusWithinChanged() += IsKeyboardFocusWithinChanged_Delegate;
	}
	IsKeyboardFocusedChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::IsKeyboardFocusedChanged_Private);
	if (IsKeyboardFocusedChanged.IsBound())
	{
		NoesisUIElement->IsKeyboardFocusedChanged() += IsKeyboardFocusedChanged_Delegate;
	}
	IsMouseCaptureWithinChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::IsMouseCaptureWithinChanged_Private);
	if (IsMouseCaptureWithinChanged.IsBound())
	{
		NoesisUIElement->IsMouseCaptureWithinChanged() += IsMouseCaptureWithinChanged_Delegate;
	}
	IsMouseCapturedChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::IsMouseCapturedChanged_Private);
	if (IsMouseCapturedChanged.IsBound())
	{
		NoesisUIElement->IsMouseCapturedChanged() += IsMouseCapturedChanged_Delegate;
	}
	IsMouseDirectlyOverChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::IsMouseDirectlyOverChanged_Private);
	if (IsMouseDirectlyOverChanged.IsBound())
	{
		NoesisUIElement->IsMouseDirectlyOverChanged() += IsMouseDirectlyOverChanged_Delegate;
	}
	IsVisibleChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::IsVisibleChanged_Private);
	if (IsVisibleChanged.IsBound())
	{
		NoesisUIElement->IsVisibleChanged() += IsVisibleChanged_Delegate;
	}
	KeyDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::KeyDown_Private);
	if (KeyDown.IsBound())
	{
		NoesisUIElement->KeyDown() += KeyDown_Delegate;
	}
	KeyUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::KeyUp_Private);
	if (KeyUp.IsBound())
	{
		NoesisUIElement->KeyUp() += KeyUp_Delegate;
	}
	LostFocus_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::LostFocus_Private);
	if (LostFocus.IsBound())
	{
		NoesisUIElement->LostFocus() += LostFocus_Delegate;
	}
	LostKeyboardFocus_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::LostKeyboardFocus_Private);
	if (LostKeyboardFocus.IsBound())
	{
		NoesisUIElement->LostKeyboardFocus() += LostKeyboardFocus_Delegate;
	}
	LostMouseCapture_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::LostMouseCapture_Private);
	if (LostMouseCapture.IsBound())
	{
		NoesisUIElement->LostMouseCapture() += LostMouseCapture_Delegate;
	}
	LostTouchCapture_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::LostTouchCapture_Private);
	if (LostTouchCapture.IsBound())
	{
		NoesisUIElement->LostTouchCapture() += LostTouchCapture_Delegate;
	}
	ManipulationCompleted_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::ManipulationCompleted_Private);
	if (ManipulationCompleted.IsBound())
	{
		NoesisUIElement->ManipulationCompleted() += ManipulationCompleted_Delegate;
	}
	ManipulationDelta_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::ManipulationDelta_Private);
	if (ManipulationDelta.IsBound())
	{
		NoesisUIElement->ManipulationDelta() += ManipulationDelta_Delegate;
	}
	ManipulationInertiaStarting_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::ManipulationInertiaStarting_Private);
	if (ManipulationInertiaStarting.IsBound())
	{
		NoesisUIElement->ManipulationInertiaStarting() += ManipulationInertiaStarting_Delegate;
	}
	ManipulationStarted_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::ManipulationStarted_Private);
	if (ManipulationStarted.IsBound())
	{
		NoesisUIElement->ManipulationStarted() += ManipulationStarted_Delegate;
	}
	ManipulationStarting_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::ManipulationStarting_Private);
	if (ManipulationStarting.IsBound())
	{
		NoesisUIElement->ManipulationStarting() += ManipulationStarting_Delegate;
	}
	MouseDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseDown_Private);
	if (MouseDown.IsBound())
	{
		NoesisUIElement->MouseDown() += MouseDown_Delegate;
	}
	MouseEnter_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseEnter_Private);
	if (MouseEnter.IsBound())
	{
		NoesisUIElement->MouseEnter() += MouseEnter_Delegate;
	}
	MouseLeave_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseLeave_Private);
	if (MouseLeave.IsBound())
	{
		NoesisUIElement->MouseLeave() += MouseLeave_Delegate;
	}
	MouseLeftButtonDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseLeftButtonDown_Private);
	if (MouseLeftButtonDown.IsBound())
	{
		NoesisUIElement->MouseLeftButtonDown() += MouseLeftButtonDown_Delegate;
	}
	MouseLeftButtonUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseLeftButtonUp_Private);
	if (MouseLeftButtonUp.IsBound())
	{
		NoesisUIElement->MouseLeftButtonUp() += MouseLeftButtonUp_Delegate;
	}
	MouseMove_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseMove_Private);
	if (MouseMove.IsBound())
	{
		NoesisUIElement->MouseMove() += MouseMove_Delegate;
	}
	MouseRightButtonDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseRightButtonDown_Private);
	if (MouseRightButtonDown.IsBound())
	{
		NoesisUIElement->MouseRightButtonDown() += MouseRightButtonDown_Delegate;
	}
	MouseRightButtonUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseRightButtonUp_Private);
	if (MouseRightButtonUp.IsBound())
	{
		NoesisUIElement->MouseRightButtonUp() += MouseRightButtonUp_Delegate;
	}
	MouseUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseUp_Private);
	if (MouseUp.IsBound())
	{
		NoesisUIElement->MouseUp() += MouseUp_Delegate;
	}
	MouseWheel_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::MouseWheel_Private);
	if (MouseWheel.IsBound())
	{
		NoesisUIElement->MouseWheel() += MouseWheel_Delegate;
	}
	PreviewGotKeyboardFocus_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewGotKeyboardFocus_Private);
	if (PreviewGotKeyboardFocus.IsBound())
	{
		NoesisUIElement->PreviewGotKeyboardFocus() += PreviewGotKeyboardFocus_Delegate;
	}
	PreviewKeyDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewKeyDown_Private);
	if (PreviewKeyDown.IsBound())
	{
		NoesisUIElement->PreviewKeyDown() += PreviewKeyDown_Delegate;
	}
	PreviewKeyUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewKeyUp_Private);
	if (PreviewKeyUp.IsBound())
	{
		NoesisUIElement->PreviewKeyUp() += PreviewKeyUp_Delegate;
	}
	PreviewLostKeyboardFocus_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewLostKeyboardFocus_Private);
	if (PreviewLostKeyboardFocus.IsBound())
	{
		NoesisUIElement->PreviewLostKeyboardFocus() += PreviewLostKeyboardFocus_Delegate;
	}
	PreviewMouseDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewMouseDown_Private);
	if (PreviewMouseDown.IsBound())
	{
		NoesisUIElement->PreviewMouseDown() += PreviewMouseDown_Delegate;
	}
	PreviewMouseLeftButtonDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewMouseLeftButtonDown_Private);
	if (PreviewMouseLeftButtonDown.IsBound())
	{
		NoesisUIElement->PreviewMouseLeftButtonDown() += PreviewMouseLeftButtonDown_Delegate;
	}
	PreviewMouseLeftButtonUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewMouseLeftButtonUp_Private);
	if (PreviewMouseLeftButtonUp.IsBound())
	{
		NoesisUIElement->PreviewMouseLeftButtonUp() += PreviewMouseLeftButtonUp_Delegate;
	}
	PreviewMouseMove_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewMouseMove_Private);
	if (PreviewMouseMove.IsBound())
	{
		NoesisUIElement->PreviewMouseMove() += PreviewMouseMove_Delegate;
	}
	PreviewMouseRightButtonDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewMouseRightButtonDown_Private);
	if (PreviewMouseRightButtonDown.IsBound())
	{
		NoesisUIElement->PreviewMouseRightButtonDown() += PreviewMouseRightButtonDown_Delegate;
	}
	PreviewMouseRightButtonUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewMouseRightButtonUp_Private);
	if (PreviewMouseRightButtonUp.IsBound())
	{
		NoesisUIElement->PreviewMouseRightButtonUp() += PreviewMouseRightButtonUp_Delegate;
	}
	PreviewMouseUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewMouseUp_Private);
	if (PreviewMouseUp.IsBound())
	{
		NoesisUIElement->PreviewMouseUp() += PreviewMouseUp_Delegate;
	}
	PreviewMouseWheel_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewMouseWheel_Private);
	if (PreviewMouseWheel.IsBound())
	{
		NoesisUIElement->PreviewMouseWheel() += PreviewMouseWheel_Delegate;
	}
	PreviewTextInput_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewTextInput_Private);
	if (PreviewTextInput.IsBound())
	{
		NoesisUIElement->PreviewTextInput() += PreviewTextInput_Delegate;
	}
	PreviewTouchDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewTouchDown_Private);
	if (PreviewTouchDown.IsBound())
	{
		NoesisUIElement->PreviewTouchDown() += PreviewTouchDown_Delegate;
	}
	PreviewTouchMove_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewTouchMove_Private);
	if (PreviewTouchMove.IsBound())
	{
		NoesisUIElement->PreviewTouchMove() += PreviewTouchMove_Delegate;
	}
	PreviewTouchUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::PreviewTouchUp_Private);
	if (PreviewTouchUp.IsBound())
	{
		NoesisUIElement->PreviewTouchUp() += PreviewTouchUp_Delegate;
	}
	TextInput_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::TextInput_Private);
	if (TextInput.IsBound())
	{
		NoesisUIElement->TextInput() += TextInput_Delegate;
	}
	TouchDown_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::TouchDown_Private);
	if (TouchDown.IsBound())
	{
		NoesisUIElement->TouchDown() += TouchDown_Delegate;
	}
	TouchEnter_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::TouchEnter_Private);
	if (TouchEnter.IsBound())
	{
		NoesisUIElement->TouchEnter() += TouchEnter_Delegate;
	}
	TouchLeave_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::TouchLeave_Private);
	if (TouchLeave.IsBound())
	{
		NoesisUIElement->TouchLeave() += TouchLeave_Delegate;
	}
	TouchMove_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::TouchMove_Private);
	if (TouchMove.IsBound())
	{
		NoesisUIElement->TouchMove() += TouchMove_Delegate;
	}
	TouchUp_Delegate = Noesis::MakeDelegate(this, &UNoesisUIElement::TouchUp_Private);
	if (TouchUp.IsBound())
	{
		NoesisUIElement->TouchUp() += TouchUp_Delegate;
	}

}

void UNoesisUIElement::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement)

	if (FocusableChanged.IsBound())
	{
		NoesisUIElement->FocusableChanged() -= FocusableChanged_Delegate;
	}
	if (GotFocus.IsBound())
	{
		NoesisUIElement->GotFocus() -= GotFocus_Delegate;
	}
	if (GotKeyboardFocus.IsBound())
	{
		NoesisUIElement->GotKeyboardFocus() -= GotKeyboardFocus_Delegate;
	}
	if (GotMouseCapture.IsBound())
	{
		NoesisUIElement->GotMouseCapture() -= GotMouseCapture_Delegate;
	}
	if (GotTouchCapture.IsBound())
	{
		NoesisUIElement->GotTouchCapture() -= GotTouchCapture_Delegate;
	}
	if (IsEnabledChanged.IsBound())
	{
		NoesisUIElement->IsEnabledChanged() -= IsEnabledChanged_Delegate;
	}
	if (IsHitTestVisibleChanged.IsBound())
	{
		NoesisUIElement->IsHitTestVisibleChanged() -= IsHitTestVisibleChanged_Delegate;
	}
	if (IsKeyboardFocusWithinChanged.IsBound())
	{
		NoesisUIElement->IsKeyboardFocusWithinChanged() -= IsKeyboardFocusWithinChanged_Delegate;
	}
	if (IsKeyboardFocusedChanged.IsBound())
	{
		NoesisUIElement->IsKeyboardFocusedChanged() -= IsKeyboardFocusedChanged_Delegate;
	}
	if (IsMouseCaptureWithinChanged.IsBound())
	{
		NoesisUIElement->IsMouseCaptureWithinChanged() -= IsMouseCaptureWithinChanged_Delegate;
	}
	if (IsMouseCapturedChanged.IsBound())
	{
		NoesisUIElement->IsMouseCapturedChanged() -= IsMouseCapturedChanged_Delegate;
	}
	if (IsMouseDirectlyOverChanged.IsBound())
	{
		NoesisUIElement->IsMouseDirectlyOverChanged() -= IsMouseDirectlyOverChanged_Delegate;
	}
	if (IsVisibleChanged.IsBound())
	{
		NoesisUIElement->IsVisibleChanged() -= IsVisibleChanged_Delegate;
	}
	if (KeyDown.IsBound())
	{
		NoesisUIElement->KeyDown() -= KeyDown_Delegate;
	}
	if (KeyUp.IsBound())
	{
		NoesisUIElement->KeyUp() -= KeyUp_Delegate;
	}
	if (LostFocus.IsBound())
	{
		NoesisUIElement->LostFocus() -= LostFocus_Delegate;
	}
	if (LostKeyboardFocus.IsBound())
	{
		NoesisUIElement->LostKeyboardFocus() -= LostKeyboardFocus_Delegate;
	}
	if (LostMouseCapture.IsBound())
	{
		NoesisUIElement->LostMouseCapture() -= LostMouseCapture_Delegate;
	}
	if (LostTouchCapture.IsBound())
	{
		NoesisUIElement->LostTouchCapture() -= LostTouchCapture_Delegate;
	}
	if (ManipulationCompleted.IsBound())
	{
		NoesisUIElement->ManipulationCompleted() -= ManipulationCompleted_Delegate;
	}
	if (ManipulationDelta.IsBound())
	{
		NoesisUIElement->ManipulationDelta() -= ManipulationDelta_Delegate;
	}
	if (ManipulationInertiaStarting.IsBound())
	{
		NoesisUIElement->ManipulationInertiaStarting() -= ManipulationInertiaStarting_Delegate;
	}
	if (ManipulationStarted.IsBound())
	{
		NoesisUIElement->ManipulationStarted() -= ManipulationStarted_Delegate;
	}
	if (ManipulationStarting.IsBound())
	{
		NoesisUIElement->ManipulationStarting() -= ManipulationStarting_Delegate;
	}
	if (MouseDown.IsBound())
	{
		NoesisUIElement->MouseDown() -= MouseDown_Delegate;
	}
	if (MouseEnter.IsBound())
	{
		NoesisUIElement->MouseEnter() -= MouseEnter_Delegate;
	}
	if (MouseLeave.IsBound())
	{
		NoesisUIElement->MouseLeave() -= MouseLeave_Delegate;
	}
	if (MouseLeftButtonDown.IsBound())
	{
		NoesisUIElement->MouseLeftButtonDown() -= MouseLeftButtonDown_Delegate;
	}
	if (MouseLeftButtonUp.IsBound())
	{
		NoesisUIElement->MouseLeftButtonUp() -= MouseLeftButtonUp_Delegate;
	}
	if (MouseMove.IsBound())
	{
		NoesisUIElement->MouseMove() -= MouseMove_Delegate;
	}
	if (MouseRightButtonDown.IsBound())
	{
		NoesisUIElement->MouseRightButtonDown() -= MouseRightButtonDown_Delegate;
	}
	if (MouseRightButtonUp.IsBound())
	{
		NoesisUIElement->MouseRightButtonUp() -= MouseRightButtonUp_Delegate;
	}
	if (MouseUp.IsBound())
	{
		NoesisUIElement->MouseUp() -= MouseUp_Delegate;
	}
	if (MouseWheel.IsBound())
	{
		NoesisUIElement->MouseWheel() -= MouseWheel_Delegate;
	}
	if (PreviewGotKeyboardFocus.IsBound())
	{
		NoesisUIElement->PreviewGotKeyboardFocus() -= PreviewGotKeyboardFocus_Delegate;
	}
	if (PreviewKeyDown.IsBound())
	{
		NoesisUIElement->PreviewKeyDown() -= PreviewKeyDown_Delegate;
	}
	if (PreviewKeyUp.IsBound())
	{
		NoesisUIElement->PreviewKeyUp() -= PreviewKeyUp_Delegate;
	}
	if (PreviewLostKeyboardFocus.IsBound())
	{
		NoesisUIElement->PreviewLostKeyboardFocus() -= PreviewLostKeyboardFocus_Delegate;
	}
	if (PreviewMouseDown.IsBound())
	{
		NoesisUIElement->PreviewMouseDown() -= PreviewMouseDown_Delegate;
	}
	if (PreviewMouseLeftButtonDown.IsBound())
	{
		NoesisUIElement->PreviewMouseLeftButtonDown() -= PreviewMouseLeftButtonDown_Delegate;
	}
	if (PreviewMouseLeftButtonUp.IsBound())
	{
		NoesisUIElement->PreviewMouseLeftButtonUp() -= PreviewMouseLeftButtonUp_Delegate;
	}
	if (PreviewMouseMove.IsBound())
	{
		NoesisUIElement->PreviewMouseMove() -= PreviewMouseMove_Delegate;
	}
	if (PreviewMouseRightButtonDown.IsBound())
	{
		NoesisUIElement->PreviewMouseRightButtonDown() -= PreviewMouseRightButtonDown_Delegate;
	}
	if (PreviewMouseRightButtonUp.IsBound())
	{
		NoesisUIElement->PreviewMouseRightButtonUp() -= PreviewMouseRightButtonUp_Delegate;
	}
	if (PreviewMouseUp.IsBound())
	{
		NoesisUIElement->PreviewMouseUp() -= PreviewMouseUp_Delegate;
	}
	if (PreviewMouseWheel.IsBound())
	{
		NoesisUIElement->PreviewMouseWheel() -= PreviewMouseWheel_Delegate;
	}
	if (PreviewTextInput.IsBound())
	{
		NoesisUIElement->PreviewTextInput() -= PreviewTextInput_Delegate;
	}
	if (PreviewTouchDown.IsBound())
	{
		NoesisUIElement->PreviewTouchDown() -= PreviewTouchDown_Delegate;
	}
	if (PreviewTouchMove.IsBound())
	{
		NoesisUIElement->PreviewTouchMove() -= PreviewTouchMove_Delegate;
	}
	if (PreviewTouchUp.IsBound())
	{
		NoesisUIElement->PreviewTouchUp() -= PreviewTouchUp_Delegate;
	}
	if (TextInput.IsBound())
	{
		NoesisUIElement->TextInput() -= TextInput_Delegate;
	}
	if (TouchDown.IsBound())
	{
		NoesisUIElement->TouchDown() -= TouchDown_Delegate;
	}
	if (TouchEnter.IsBound())
	{
		NoesisUIElement->TouchEnter() -= TouchEnter_Delegate;
	}
	if (TouchLeave.IsBound())
	{
		NoesisUIElement->TouchLeave() -= TouchLeave_Delegate;
	}
	if (TouchMove.IsBound())
	{
		NoesisUIElement->TouchMove() -= TouchMove_Delegate;
	}
	if (TouchUp.IsBound())
	{
		NoesisUIElement->TouchUp() -= TouchUp_Delegate;
	}

}

