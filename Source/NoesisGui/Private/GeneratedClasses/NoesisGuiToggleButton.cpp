////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiToggleButton.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiToggleButton::UNoesisGuiToggleButton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiToggleButton::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ToggleButton* NoesisToggleButton = NsDynamicCast<Noesis::Gui::ToggleButton*>(InNoesisComponent);
	check(NoesisToggleButton);
}

void UNoesisGuiToggleButton::Checked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Checked.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Checked.Broadcast(Sender, Args);
}

void UNoesisGuiToggleButton::Indeterminate_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Indeterminate.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Indeterminate.Broadcast(Sender, Args);
}

void UNoesisGuiToggleButton::Unchecked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Unchecked.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Unchecked.Broadcast(Sender, Args);
}

void UNoesisGuiToggleButton::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ToggleButton* NoesisToggleButton = NsDynamicCast<Noesis::Gui::ToggleButton*>(NoesisComponent.GetPtr());
	check(NoesisToggleButton)

	Checked_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiToggleButton::Checked_Private);
	if (Checked.IsBound())
	{
		NoesisToggleButton->Checked() += Checked_Delegate;
	}
	Indeterminate_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiToggleButton::Indeterminate_Private);
	if (Indeterminate.IsBound())
	{
		NoesisToggleButton->Indeterminate() += Indeterminate_Delegate;
	}
	Unchecked_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiToggleButton::Unchecked_Private);
	if (Unchecked.IsBound())
	{
		NoesisToggleButton->Unchecked() += Unchecked_Delegate;
	}

}

void UNoesisGuiToggleButton::UnbindEvents()
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

