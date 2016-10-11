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

	Checked_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::Checked_Private);
	NoesisMenuItem->Checked() += Checked_Delegate;
	Click_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::Click_Private);
	NoesisMenuItem->Click() += Click_Delegate;
	SubmenuClosed_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::SubmenuClosed_Private);
	NoesisMenuItem->SubmenuClosed() += SubmenuClosed_Delegate;
	SubmenuOpened_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::SubmenuOpened_Private);
	NoesisMenuItem->SubmenuOpened() += SubmenuOpened_Delegate;
	Unchecked_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::Unchecked_Private);
	NoesisMenuItem->Unchecked() += Unchecked_Delegate;
}

	void UNoesisGuiMenuItem::Checked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Checked.Broadcast(Sender, Args);
}

	void UNoesisGuiMenuItem::Click_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Click.Broadcast(Sender, Args);
}

	void UNoesisGuiMenuItem::SubmenuClosed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	SubmenuClosed.Broadcast(Sender, Args);
}

	void UNoesisGuiMenuItem::SubmenuOpened_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	SubmenuOpened.Broadcast(Sender, Args);
}

	void UNoesisGuiMenuItem::Unchecked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Unchecked.Broadcast(Sender, Args);
}

	void UNoesisGuiMenuItem::BeginDestroy()
{
	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	if (!NoesisMenuItem)
		return Super::BeginDestroy();

	NoesisMenuItem->Checked() -= Checked_Delegate;
	NoesisMenuItem->Click() -= Click_Delegate;
	NoesisMenuItem->SubmenuClosed() -= SubmenuClosed_Delegate;
	NoesisMenuItem->SubmenuOpened() -= SubmenuOpened_Delegate;
	NoesisMenuItem->Unchecked() -= Unchecked_Delegate;

	Super::BeginDestroy();
}

