////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisToggleButton.h"

using namespace Noesis;
using namespace Gui;

UNoesisToggleButton::UNoesisToggleButton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisToggleButton::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ToggleButton* NoesisToggleButton = NsDynamicCast<Noesis::Gui::ToggleButton*>(InNoesisComponent);
	check(NoesisToggleButton);
}

bool UNoesisToggleButton::GetIsThreeState()
{
	Noesis::Gui::ToggleButton* NoesisToggleButton = NsDynamicCast<Noesis::Gui::ToggleButton*>(NoesisComponent.GetPtr());
	check(NoesisToggleButton);
	return NoesisToggleButton->GetIsThreeState();
}

void UNoesisToggleButton::SetIsThreeState(bool InIsThreeState)
{
	Noesis::Gui::ToggleButton* NoesisToggleButton = NsDynamicCast<Noesis::Gui::ToggleButton*>(NoesisComponent.GetPtr());
	check(NoesisToggleButton);
	NoesisToggleButton->SetIsThreeState(InIsThreeState);
}

void UNoesisToggleButton::Checked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Checked.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	Checked.Broadcast(Sender, Args);
}

void UNoesisToggleButton::Indeterminate_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Indeterminate.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	Indeterminate.Broadcast(Sender, Args);
}

void UNoesisToggleButton::Unchecked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Unchecked.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	Unchecked.Broadcast(Sender, Args);
}

void UNoesisToggleButton::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ToggleButton* NoesisToggleButton = NsDynamicCast<Noesis::Gui::ToggleButton*>(NoesisComponent.GetPtr());
	check(NoesisToggleButton)

	Checked_Delegate = Noesis::MakeDelegate(this, &UNoesisToggleButton::Checked_Private);
	if (Checked.IsBound())
	{
		NoesisToggleButton->Checked() += Checked_Delegate;
	}
	Indeterminate_Delegate = Noesis::MakeDelegate(this, &UNoesisToggleButton::Indeterminate_Private);
	if (Indeterminate.IsBound())
	{
		NoesisToggleButton->Indeterminate() += Indeterminate_Delegate;
	}
	Unchecked_Delegate = Noesis::MakeDelegate(this, &UNoesisToggleButton::Unchecked_Private);
	if (Unchecked.IsBound())
	{
		NoesisToggleButton->Unchecked() += Unchecked_Delegate;
	}

}

void UNoesisToggleButton::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ToggleButton* NoesisToggleButton = NsDynamicCast<Noesis::Gui::ToggleButton*>(NoesisComponent.GetPtr());
	check(NoesisToggleButton)

	if (Checked.IsBound())
	{
		NoesisToggleButton->Checked() -= Checked_Delegate;
	}
	if (Indeterminate.IsBound())
	{
		NoesisToggleButton->Indeterminate() -= Indeterminate_Delegate;
	}
	if (Unchecked.IsBound())
	{
		NoesisToggleButton->Unchecked() -= Unchecked_Delegate;
	}

}

