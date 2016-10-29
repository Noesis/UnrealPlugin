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
}

UNoesisGuiPopup* UNoesisGuiContextMenu::GetPopup()
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	return CastChecked<UNoesisGuiPopup>(Instance->FindUnrealComponentForNoesisComponent(NoesisContextMenu->GetPopup()));
}

void UNoesisGuiContextMenu::Closed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Closed.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Closed.Broadcast(Sender, Args);
}

void UNoesisGuiContextMenu::Opened_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Opened.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Opened.Broadcast(Sender, Args);
}

void UNoesisGuiContextMenu::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu)

	Closed_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiContextMenu::Closed_Private);
	if (Closed.IsBound())
	{
		NoesisContextMenu->Closed() += Closed_Delegate;
	}
	Opened_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiContextMenu::Opened_Private);
	if (Opened.IsBound())
	{
		NoesisContextMenu->Opened() += Opened_Delegate;
	}

}

void UNoesisGuiContextMenu::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu)

	if (Closed.IsBound())
	{
		NoesisContextMenu->Closed() -= Closed_Delegate;
	}
	if (Opened.IsBound())
	{
		NoesisContextMenu->Opened() -= Opened_Delegate;
	}

}

