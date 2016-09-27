////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiControl.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiControl::UNoesisGuiControl(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiControl::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(InNoesisComponent);
	check(NoesisControl);

	NoesisControl->MouseDoubleClick() += Noesis::MakeDelegate(this, &UNoesisGuiControl::MouseDoubleClick_Private);
	NoesisControl->PreviewMouseDoubleClick() += Noesis::MakeDelegate(this, &UNoesisGuiControl::PreviewMouseDoubleClick_Private);
}

	void UNoesisGuiControl::MouseDoubleClick_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
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
	MouseDoubleClick.Broadcast(Sender, Args);
}

	void UNoesisGuiControl::PreviewMouseDoubleClick_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
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
	PreviewMouseDoubleClick.Broadcast(Sender, Args);
}

	void UNoesisGuiControl::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	if (!NoesisControl)
		return;

	NoesisControl->MouseDoubleClick() -= Noesis::MakeDelegate(this, &UNoesisGuiControl::MouseDoubleClick_Private);
	NoesisControl->PreviewMouseDoubleClick() -= Noesis::MakeDelegate(this, &UNoesisGuiControl::PreviewMouseDoubleClick_Private);
}

