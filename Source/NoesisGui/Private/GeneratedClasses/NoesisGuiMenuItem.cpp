////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiMenuItem.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiMenuItem::UNoesisGuiMenuItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiMenuItem::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(InNoesisComponent);
	check(NoesisMenuItem);
}

void UNoesisGuiMenuItem::Checked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Checked.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Checked.Broadcast(Sender, Args);
}

void UNoesisGuiMenuItem::Click_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Click.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Click.Broadcast(Sender, Args);
}

void UNoesisGuiMenuItem::SubmenuClosed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!SubmenuClosed.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	SubmenuClosed.Broadcast(Sender, Args);
}

void UNoesisGuiMenuItem::SubmenuOpened_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!SubmenuOpened.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	SubmenuOpened.Broadcast(Sender, Args);
}

void UNoesisGuiMenuItem::Unchecked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Unchecked.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Unchecked.Broadcast(Sender, Args);
}

void UNoesisGuiMenuItem::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem)

	Checked_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::Checked_Private);
	if (Checked.IsBound())
	{
		NoesisMenuItem->Checked() += Checked_Delegate;
	}
	Click_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::Click_Private);
	if (Click.IsBound())
	{
		NoesisMenuItem->Click() += Click_Delegate;
	}
	SubmenuClosed_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::SubmenuClosed_Private);
	if (SubmenuClosed.IsBound())
	{
		NoesisMenuItem->SubmenuClosed() += SubmenuClosed_Delegate;
	}
	SubmenuOpened_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::SubmenuOpened_Private);
	if (SubmenuOpened.IsBound())
	{
		NoesisMenuItem->SubmenuOpened() += SubmenuOpened_Delegate;
	}
	Unchecked_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::Unchecked_Private);
	if (Unchecked.IsBound())
	{
		NoesisMenuItem->Unchecked() += Unchecked_Delegate;
	}

}

void UNoesisGuiMenuItem::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	check(NoesisMenuItem)

	if (Checked.IsBound())
	{
		NoesisMenuItem->Checked() -= Checked_Delegate;
	}
	if (Click.IsBound())
	{
		NoesisMenuItem->Click() -= Click_Delegate;
	}
	if (SubmenuClosed.IsBound())
	{
		NoesisMenuItem->SubmenuClosed() -= SubmenuClosed_Delegate;
	}
	if (SubmenuOpened.IsBound())
	{
		NoesisMenuItem->SubmenuOpened() -= SubmenuOpened_Delegate;
	}
	if (Unchecked.IsBound())
	{
		NoesisMenuItem->Unchecked() -= Unchecked_Delegate;
	}

}

