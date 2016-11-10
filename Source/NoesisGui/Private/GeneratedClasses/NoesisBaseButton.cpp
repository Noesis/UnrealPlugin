////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisBaseButton.h"

using namespace Noesis;
using namespace Gui;

UNoesisBaseButton::UNoesisBaseButton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisBaseButton::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(InNoesisComponent);
	check(NoesisBaseButton);
}

ENoesisClickMode UNoesisBaseButton::GetClickMode()
{
	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);
	return (ENoesisClickMode)NoesisBaseButton->GetClickMode();
}

void UNoesisBaseButton::SetClickMode(ENoesisClickMode InClickMode)
{
	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);
	NoesisBaseButton->SetClickMode((Noesis::Gui::ClickMode)InClickMode);
}

class UNoesisICommand* UNoesisBaseButton::GetCommand()
{
	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);
	return CastChecked<UNoesisICommand>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisBaseButton->GetCommand()));
}

void UNoesisBaseButton::SetCommand(class UNoesisICommand* InCommand)
{
	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);
	NoesisBaseButton->SetCommand(NsDynamicCast<ICommand*>(InCommand->NoesisInterface.GetPtr()));
}

class UNoesisBaseComponent* UNoesisBaseButton::GetCommandParameter()
{
	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisBaseButton->GetCommandParameter()));
}

void UNoesisBaseButton::SetCommandParameter(class UNoesisBaseComponent* InCommandParameter)
{
	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);
	NoesisBaseButton->SetCommandParameter(NsDynamicCast<Core::BaseComponent*>(InCommandParameter->NoesisComponent.GetPtr()));
}

class UNoesisUIElement* UNoesisBaseButton::GetCommandTarget()
{
	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);
	return CastChecked<UNoesisUIElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisBaseButton->GetCommandTarget()));
}

void UNoesisBaseButton::SetCommandTarget(class UNoesisUIElement* InCommandTarget)
{
	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);
	NoesisBaseButton->SetCommandTarget(NsDynamicCast<UIElement*>(InCommandTarget->NoesisComponent.GetPtr()));
}

bool UNoesisBaseButton::GetIsPressed()
{
	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton);
	return NoesisBaseButton->GetIsPressed();
}

void UNoesisBaseButton::Click_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Click.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	Click.Broadcast(Sender, Args);
}

void UNoesisBaseButton::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton)

	Click_Delegate = Noesis::MakeDelegate(this, &UNoesisBaseButton::Click_Private);
	if (Click.IsBound())
	{
		NoesisBaseButton->Click() += Click_Delegate;
	}

}

void UNoesisBaseButton::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton)

	if (Click.IsBound())
	{
		NoesisBaseButton->Click() -= Click_Delegate;
	}

}

