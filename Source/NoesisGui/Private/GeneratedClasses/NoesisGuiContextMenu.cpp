////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiContextMenu.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiContextMenu::UNoesisGuiContextMenu(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiContextMenu::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(InNoesisComponent);
	check(NoesisContextMenu);

	NoesisContextMenu->Closed() += Noesis::MakeDelegate(this, &UNoesisGuiContextMenu::Closed_Private);
	NoesisContextMenu->Opened() += Noesis::MakeDelegate(this, &UNoesisGuiContextMenu::Opened_Private);
}

	void UNoesisGuiContextMenu::Closed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Closed.Broadcast(Sender, Args);
}

	void UNoesisGuiContextMenu::Opened_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Opened.Broadcast(Sender, Args);
}

	void UNoesisGuiContextMenu::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	if (!NoesisContextMenu)
		return;

	NoesisContextMenu->Closed() -= Noesis::MakeDelegate(this, &UNoesisGuiContextMenu::Closed_Private);
	NoesisContextMenu->Opened() -= Noesis::MakeDelegate(this, &UNoesisGuiContextMenu::Opened_Private);
}

