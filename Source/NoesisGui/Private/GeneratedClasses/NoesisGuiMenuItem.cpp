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

	NoesisMenuItem->Checked() += Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::Checked_Private);
	NoesisMenuItem->Click() += Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::Click_Private);
	NoesisMenuItem->SubmenuClosed() += Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::SubmenuClosed_Private);
	NoesisMenuItem->SubmenuOpened() += Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::SubmenuOpened_Private);
	NoesisMenuItem->Unchecked() += Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::Unchecked_Private);
}

	void UNoesisGuiMenuItem::Checked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Checked.Broadcast(Sender, Args);
}

	void UNoesisGuiMenuItem::Click_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Click.Broadcast(Sender, Args);
}

	void UNoesisGuiMenuItem::SubmenuClosed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	SubmenuClosed.Broadcast(Sender, Args);
}

	void UNoesisGuiMenuItem::SubmenuOpened_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	SubmenuOpened.Broadcast(Sender, Args);
}

	void UNoesisGuiMenuItem::Unchecked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Unchecked.Broadcast(Sender, Args);
}

	void UNoesisGuiMenuItem::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::MenuItem* NoesisMenuItem = NsDynamicCast<Noesis::Gui::MenuItem*>(NoesisComponent.GetPtr());
	if (!NoesisMenuItem)
		return;

	NoesisMenuItem->Checked() -= Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::Checked_Private);
	NoesisMenuItem->Click() -= Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::Click_Private);
	NoesisMenuItem->SubmenuClosed() -= Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::SubmenuClosed_Private);
	NoesisMenuItem->SubmenuOpened() -= Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::SubmenuOpened_Private);
	NoesisMenuItem->Unchecked() -= Noesis::MakeDelegate(this, &UNoesisGuiMenuItem::Unchecked_Private);
}

