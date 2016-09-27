////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiUIElement.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiUIElement::UNoesisGuiUIElement(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiUIElement::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(InNoesisComponent);
	check(NoesisUIElement);

	NoesisUIElement->GotFocus() += Noesis::MakeDelegate(this, &UNoesisGuiUIElement::GotFocus_Private);
	NoesisUIElement->LostFocus() += Noesis::MakeDelegate(this, &UNoesisGuiUIElement::LostFocus_Private);
	NoesisUIElement->MouseDown() += Noesis::MakeDelegate(this, &UNoesisGuiUIElement::MouseDown_Private);
	NoesisUIElement->MouseLeftButtonDown() += Noesis::MakeDelegate(this, &UNoesisGuiUIElement::MouseLeftButtonDown_Private);
	NoesisUIElement->MouseLeftButtonUp() += Noesis::MakeDelegate(this, &UNoesisGuiUIElement::MouseLeftButtonUp_Private);
	NoesisUIElement->MouseRightButtonDown() += Noesis::MakeDelegate(this, &UNoesisGuiUIElement::MouseRightButtonDown_Private);
	NoesisUIElement->MouseRightButtonUp() += Noesis::MakeDelegate(this, &UNoesisGuiUIElement::MouseRightButtonUp_Private);
	NoesisUIElement->MouseUp() += Noesis::MakeDelegate(this, &UNoesisGuiUIElement::MouseUp_Private);
	NoesisUIElement->PreviewMouseDown() += Noesis::MakeDelegate(this, &UNoesisGuiUIElement::PreviewMouseDown_Private);
	NoesisUIElement->PreviewMouseLeftButtonDown() += Noesis::MakeDelegate(this, &UNoesisGuiUIElement::PreviewMouseLeftButtonDown_Private);
	NoesisUIElement->PreviewMouseLeftButtonUp() += Noesis::MakeDelegate(this, &UNoesisGuiUIElement::PreviewMouseLeftButtonUp_Private);
	NoesisUIElement->PreviewMouseRightButtonDown() += Noesis::MakeDelegate(this, &UNoesisGuiUIElement::PreviewMouseRightButtonDown_Private);
	NoesisUIElement->PreviewMouseRightButtonUp() += Noesis::MakeDelegate(this, &UNoesisGuiUIElement::PreviewMouseRightButtonUp_Private);
	NoesisUIElement->PreviewMouseUp() += Noesis::MakeDelegate(this, &UNoesisGuiUIElement::PreviewMouseUp_Private);
}

class UNoesisGuiCommandBindingCollection* UNoesisGuiUIElement::GetCommandBindings()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return CastChecked<UNoesisGuiCommandBindingCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisUIElement->GetCommandBindings()));
}

FNoesisGuiDrawingSize UNoesisGuiUIElement::GetDesiredSize()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return FNoesisGuiDrawingSize(NoesisUIElement->GetDesiredSize().width, NoesisUIElement->GetDesiredSize().height);
}

class UNoesisGuiInputBindingCollection* UNoesisGuiUIElement::GetInputBindings()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return CastChecked<UNoesisGuiInputBindingCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisUIElement->GetInputBindings()));
}

FNoesisGuiDrawingSize UNoesisGuiUIElement::GetRenderSize()
{
	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	check(NoesisUIElement);
	return FNoesisGuiDrawingSize(NoesisUIElement->GetRenderSize().width, NoesisUIElement->GetRenderSize().height);
}

	void UNoesisGuiUIElement::GotFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	GotFocus.Broadcast(Sender, Args);
}

	void UNoesisGuiUIElement::LostFocus_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	LostFocus.Broadcast(Sender, Args);
}

	void UNoesisGuiUIElement::MouseDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiMouseButtonEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Args.Position = FNoesisGuiDrawingPoint(InArgs.position.x, InArgs.position.y);
	Args.LeftButton = (ENoesisGuiMouseButtonState)InArgs.leftButton;
	Args.MiddleButton = (ENoesisGuiMouseButtonState)InArgs.middleButton;
	Args.RightButton = (ENoesisGuiMouseButtonState)InArgs.rightButton;
	Args.XButton1Button = (ENoesisGuiMouseButtonState)InArgs.xButton1Button;
	Args.XButton2Button = (ENoesisGuiMouseButtonState)InArgs.xButton2Button;
	Args.ChangedButton = (ENoesisGuiMouseButton)InArgs.changedButton;
	Args.ButtonState = (ENoesisGuiMouseButtonState)InArgs.buttonState;
	Args.ButtonClicks = (int32)InArgs.buttonClicks;
	MouseDown.Broadcast(Sender, Args);
}

	void UNoesisGuiUIElement::MouseLeftButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiMouseButtonEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Args.Position = FNoesisGuiDrawingPoint(InArgs.position.x, InArgs.position.y);
	Args.LeftButton = (ENoesisGuiMouseButtonState)InArgs.leftButton;
	Args.MiddleButton = (ENoesisGuiMouseButtonState)InArgs.middleButton;
	Args.RightButton = (ENoesisGuiMouseButtonState)InArgs.rightButton;
	Args.XButton1Button = (ENoesisGuiMouseButtonState)InArgs.xButton1Button;
	Args.XButton2Button = (ENoesisGuiMouseButtonState)InArgs.xButton2Button;
	Args.ChangedButton = (ENoesisGuiMouseButton)InArgs.changedButton;
	Args.ButtonState = (ENoesisGuiMouseButtonState)InArgs.buttonState;
	Args.ButtonClicks = (int32)InArgs.buttonClicks;
	MouseLeftButtonDown.Broadcast(Sender, Args);
}

	void UNoesisGuiUIElement::MouseLeftButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiMouseButtonEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Args.Position = FNoesisGuiDrawingPoint(InArgs.position.x, InArgs.position.y);
	Args.LeftButton = (ENoesisGuiMouseButtonState)InArgs.leftButton;
	Args.MiddleButton = (ENoesisGuiMouseButtonState)InArgs.middleButton;
	Args.RightButton = (ENoesisGuiMouseButtonState)InArgs.rightButton;
	Args.XButton1Button = (ENoesisGuiMouseButtonState)InArgs.xButton1Button;
	Args.XButton2Button = (ENoesisGuiMouseButtonState)InArgs.xButton2Button;
	Args.ChangedButton = (ENoesisGuiMouseButton)InArgs.changedButton;
	Args.ButtonState = (ENoesisGuiMouseButtonState)InArgs.buttonState;
	Args.ButtonClicks = (int32)InArgs.buttonClicks;
	MouseLeftButtonUp.Broadcast(Sender, Args);
}

	void UNoesisGuiUIElement::MouseRightButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiMouseButtonEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Args.Position = FNoesisGuiDrawingPoint(InArgs.position.x, InArgs.position.y);
	Args.LeftButton = (ENoesisGuiMouseButtonState)InArgs.leftButton;
	Args.MiddleButton = (ENoesisGuiMouseButtonState)InArgs.middleButton;
	Args.RightButton = (ENoesisGuiMouseButtonState)InArgs.rightButton;
	Args.XButton1Button = (ENoesisGuiMouseButtonState)InArgs.xButton1Button;
	Args.XButton2Button = (ENoesisGuiMouseButtonState)InArgs.xButton2Button;
	Args.ChangedButton = (ENoesisGuiMouseButton)InArgs.changedButton;
	Args.ButtonState = (ENoesisGuiMouseButtonState)InArgs.buttonState;
	Args.ButtonClicks = (int32)InArgs.buttonClicks;
	MouseRightButtonDown.Broadcast(Sender, Args);
}

	void UNoesisGuiUIElement::MouseRightButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiMouseButtonEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Args.Position = FNoesisGuiDrawingPoint(InArgs.position.x, InArgs.position.y);
	Args.LeftButton = (ENoesisGuiMouseButtonState)InArgs.leftButton;
	Args.MiddleButton = (ENoesisGuiMouseButtonState)InArgs.middleButton;
	Args.RightButton = (ENoesisGuiMouseButtonState)InArgs.rightButton;
	Args.XButton1Button = (ENoesisGuiMouseButtonState)InArgs.xButton1Button;
	Args.XButton2Button = (ENoesisGuiMouseButtonState)InArgs.xButton2Button;
	Args.ChangedButton = (ENoesisGuiMouseButton)InArgs.changedButton;
	Args.ButtonState = (ENoesisGuiMouseButtonState)InArgs.buttonState;
	Args.ButtonClicks = (int32)InArgs.buttonClicks;
	MouseRightButtonUp.Broadcast(Sender, Args);
}

	void UNoesisGuiUIElement::MouseUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiMouseButtonEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Args.Position = FNoesisGuiDrawingPoint(InArgs.position.x, InArgs.position.y);
	Args.LeftButton = (ENoesisGuiMouseButtonState)InArgs.leftButton;
	Args.MiddleButton = (ENoesisGuiMouseButtonState)InArgs.middleButton;
	Args.RightButton = (ENoesisGuiMouseButtonState)InArgs.rightButton;
	Args.XButton1Button = (ENoesisGuiMouseButtonState)InArgs.xButton1Button;
	Args.XButton2Button = (ENoesisGuiMouseButtonState)InArgs.xButton2Button;
	Args.ChangedButton = (ENoesisGuiMouseButton)InArgs.changedButton;
	Args.ButtonState = (ENoesisGuiMouseButtonState)InArgs.buttonState;
	Args.ButtonClicks = (int32)InArgs.buttonClicks;
	MouseUp.Broadcast(Sender, Args);
}

	void UNoesisGuiUIElement::PreviewMouseDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiMouseButtonEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Args.Position = FNoesisGuiDrawingPoint(InArgs.position.x, InArgs.position.y);
	Args.LeftButton = (ENoesisGuiMouseButtonState)InArgs.leftButton;
	Args.MiddleButton = (ENoesisGuiMouseButtonState)InArgs.middleButton;
	Args.RightButton = (ENoesisGuiMouseButtonState)InArgs.rightButton;
	Args.XButton1Button = (ENoesisGuiMouseButtonState)InArgs.xButton1Button;
	Args.XButton2Button = (ENoesisGuiMouseButtonState)InArgs.xButton2Button;
	Args.ChangedButton = (ENoesisGuiMouseButton)InArgs.changedButton;
	Args.ButtonState = (ENoesisGuiMouseButtonState)InArgs.buttonState;
	Args.ButtonClicks = (int32)InArgs.buttonClicks;
	PreviewMouseDown.Broadcast(Sender, Args);
}

	void UNoesisGuiUIElement::PreviewMouseLeftButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiMouseButtonEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Args.Position = FNoesisGuiDrawingPoint(InArgs.position.x, InArgs.position.y);
	Args.LeftButton = (ENoesisGuiMouseButtonState)InArgs.leftButton;
	Args.MiddleButton = (ENoesisGuiMouseButtonState)InArgs.middleButton;
	Args.RightButton = (ENoesisGuiMouseButtonState)InArgs.rightButton;
	Args.XButton1Button = (ENoesisGuiMouseButtonState)InArgs.xButton1Button;
	Args.XButton2Button = (ENoesisGuiMouseButtonState)InArgs.xButton2Button;
	Args.ChangedButton = (ENoesisGuiMouseButton)InArgs.changedButton;
	Args.ButtonState = (ENoesisGuiMouseButtonState)InArgs.buttonState;
	Args.ButtonClicks = (int32)InArgs.buttonClicks;
	PreviewMouseLeftButtonDown.Broadcast(Sender, Args);
}

	void UNoesisGuiUIElement::PreviewMouseLeftButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiMouseButtonEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Args.Position = FNoesisGuiDrawingPoint(InArgs.position.x, InArgs.position.y);
	Args.LeftButton = (ENoesisGuiMouseButtonState)InArgs.leftButton;
	Args.MiddleButton = (ENoesisGuiMouseButtonState)InArgs.middleButton;
	Args.RightButton = (ENoesisGuiMouseButtonState)InArgs.rightButton;
	Args.XButton1Button = (ENoesisGuiMouseButtonState)InArgs.xButton1Button;
	Args.XButton2Button = (ENoesisGuiMouseButtonState)InArgs.xButton2Button;
	Args.ChangedButton = (ENoesisGuiMouseButton)InArgs.changedButton;
	Args.ButtonState = (ENoesisGuiMouseButtonState)InArgs.buttonState;
	Args.ButtonClicks = (int32)InArgs.buttonClicks;
	PreviewMouseLeftButtonUp.Broadcast(Sender, Args);
}

	void UNoesisGuiUIElement::PreviewMouseRightButtonDown_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiMouseButtonEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Args.Position = FNoesisGuiDrawingPoint(InArgs.position.x, InArgs.position.y);
	Args.LeftButton = (ENoesisGuiMouseButtonState)InArgs.leftButton;
	Args.MiddleButton = (ENoesisGuiMouseButtonState)InArgs.middleButton;
	Args.RightButton = (ENoesisGuiMouseButtonState)InArgs.rightButton;
	Args.XButton1Button = (ENoesisGuiMouseButtonState)InArgs.xButton1Button;
	Args.XButton2Button = (ENoesisGuiMouseButtonState)InArgs.xButton2Button;
	Args.ChangedButton = (ENoesisGuiMouseButton)InArgs.changedButton;
	Args.ButtonState = (ENoesisGuiMouseButtonState)InArgs.buttonState;
	Args.ButtonClicks = (int32)InArgs.buttonClicks;
	PreviewMouseRightButtonDown.Broadcast(Sender, Args);
}

	void UNoesisGuiUIElement::PreviewMouseRightButtonUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiMouseButtonEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Args.Position = FNoesisGuiDrawingPoint(InArgs.position.x, InArgs.position.y);
	Args.LeftButton = (ENoesisGuiMouseButtonState)InArgs.leftButton;
	Args.MiddleButton = (ENoesisGuiMouseButtonState)InArgs.middleButton;
	Args.RightButton = (ENoesisGuiMouseButtonState)InArgs.rightButton;
	Args.XButton1Button = (ENoesisGuiMouseButtonState)InArgs.xButton1Button;
	Args.XButton2Button = (ENoesisGuiMouseButtonState)InArgs.xButton2Button;
	Args.ChangedButton = (ENoesisGuiMouseButton)InArgs.changedButton;
	Args.ButtonState = (ENoesisGuiMouseButtonState)InArgs.buttonState;
	Args.ButtonClicks = (int32)InArgs.buttonClicks;
	PreviewMouseRightButtonUp.Broadcast(Sender, Args);
}

	void UNoesisGuiUIElement::PreviewMouseUp_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiMouseButtonEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Args.Position = FNoesisGuiDrawingPoint(InArgs.position.x, InArgs.position.y);
	Args.LeftButton = (ENoesisGuiMouseButtonState)InArgs.leftButton;
	Args.MiddleButton = (ENoesisGuiMouseButtonState)InArgs.middleButton;
	Args.RightButton = (ENoesisGuiMouseButtonState)InArgs.rightButton;
	Args.XButton1Button = (ENoesisGuiMouseButtonState)InArgs.xButton1Button;
	Args.XButton2Button = (ENoesisGuiMouseButtonState)InArgs.xButton2Button;
	Args.ChangedButton = (ENoesisGuiMouseButton)InArgs.changedButton;
	Args.ButtonState = (ENoesisGuiMouseButtonState)InArgs.buttonState;
	Args.ButtonClicks = (int32)InArgs.buttonClicks;
	PreviewMouseUp.Broadcast(Sender, Args);
}

	void UNoesisGuiUIElement::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::UIElement* NoesisUIElement = NsDynamicCast<Noesis::Gui::UIElement*>(NoesisComponent.GetPtr());
	if (!NoesisUIElement)
		return;

	NoesisUIElement->GotFocus() -= Noesis::MakeDelegate(this, &UNoesisGuiUIElement::GotFocus_Private);
	NoesisUIElement->LostFocus() -= Noesis::MakeDelegate(this, &UNoesisGuiUIElement::LostFocus_Private);
	NoesisUIElement->MouseDown() -= Noesis::MakeDelegate(this, &UNoesisGuiUIElement::MouseDown_Private);
	NoesisUIElement->MouseLeftButtonDown() -= Noesis::MakeDelegate(this, &UNoesisGuiUIElement::MouseLeftButtonDown_Private);
	NoesisUIElement->MouseLeftButtonUp() -= Noesis::MakeDelegate(this, &UNoesisGuiUIElement::MouseLeftButtonUp_Private);
	NoesisUIElement->MouseRightButtonDown() -= Noesis::MakeDelegate(this, &UNoesisGuiUIElement::MouseRightButtonDown_Private);
	NoesisUIElement->MouseRightButtonUp() -= Noesis::MakeDelegate(this, &UNoesisGuiUIElement::MouseRightButtonUp_Private);
	NoesisUIElement->MouseUp() -= Noesis::MakeDelegate(this, &UNoesisGuiUIElement::MouseUp_Private);
	NoesisUIElement->PreviewMouseDown() -= Noesis::MakeDelegate(this, &UNoesisGuiUIElement::PreviewMouseDown_Private);
	NoesisUIElement->PreviewMouseLeftButtonDown() -= Noesis::MakeDelegate(this, &UNoesisGuiUIElement::PreviewMouseLeftButtonDown_Private);
	NoesisUIElement->PreviewMouseLeftButtonUp() -= Noesis::MakeDelegate(this, &UNoesisGuiUIElement::PreviewMouseLeftButtonUp_Private);
	NoesisUIElement->PreviewMouseRightButtonDown() -= Noesis::MakeDelegate(this, &UNoesisGuiUIElement::PreviewMouseRightButtonDown_Private);
	NoesisUIElement->PreviewMouseRightButtonUp() -= Noesis::MakeDelegate(this, &UNoesisGuiUIElement::PreviewMouseRightButtonUp_Private);
	NoesisUIElement->PreviewMouseUp() -= Noesis::MakeDelegate(this, &UNoesisGuiUIElement::PreviewMouseUp_Private);
}

