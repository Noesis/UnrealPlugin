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

	Closed_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiContextMenu::Closed_Private);
	NoesisContextMenu->Closed() += Closed_Delegate;
	Opened_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiContextMenu::Opened_Private);
	NoesisContextMenu->Opened() += Opened_Delegate;
}

UNoesisGuiPopup* UNoesisGuiContextMenu::GetPopup()
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	return CastChecked<UNoesisGuiPopup>(Instance->FindUnrealComponentForNoesisComponent(NoesisContextMenu->GetPopup()));
}

	void UNoesisGuiContextMenu::Closed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Closed.Broadcast(Sender, Args);
}

	void UNoesisGuiContextMenu::Opened_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Opened.Broadcast(Sender, Args);
}

	void UNoesisGuiContextMenu::BeginDestroy()
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	if (!NoesisContextMenu)
		return Super::BeginDestroy();

	NoesisContextMenu->Closed() -= Closed_Delegate;
	NoesisContextMenu->Opened() -= Opened_Delegate;

	Super::BeginDestroy();
}

