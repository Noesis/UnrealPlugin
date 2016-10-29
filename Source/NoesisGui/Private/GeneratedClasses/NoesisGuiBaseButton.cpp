////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseButton.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseButton::UNoesisGuiBaseButton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseButton::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(InNoesisComponent);
	check(NoesisBaseButton);
}

void UNoesisGuiBaseButton::Click_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Click.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Click.Broadcast(Sender, Args);
}

void UNoesisGuiBaseButton::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton)

	Click_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiBaseButton::Click_Private);
	if (Click.IsBound())
	{
		NoesisBaseButton->Click() += Click_Delegate;
	}

}

void UNoesisGuiBaseButton::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	check(NoesisBaseButton)

	if (Click.IsBound())
	{
		NoesisBaseButton->Click() -= Click_Delegate;
	}

}

