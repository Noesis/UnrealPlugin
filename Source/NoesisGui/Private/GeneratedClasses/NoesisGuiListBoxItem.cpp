////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiListBoxItem.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiListBoxItem::UNoesisGuiListBoxItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiListBoxItem::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ListBoxItem* NoesisListBoxItem = NsDynamicCast<Noesis::Gui::ListBoxItem*>(InNoesisComponent);
	check(NoesisListBoxItem);
}

void UNoesisGuiListBoxItem::Selected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Selected.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Selected.Broadcast(Sender, Args);
}

void UNoesisGuiListBoxItem::Unselected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Unselected.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Unselected.Broadcast(Sender, Args);
}

void UNoesisGuiListBoxItem::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ListBoxItem* NoesisListBoxItem = NsDynamicCast<Noesis::Gui::ListBoxItem*>(NoesisComponent.GetPtr());
	check(NoesisListBoxItem)

	Selected_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiListBoxItem::Selected_Private);
	if (Selected.IsBound())
	{
		NoesisListBoxItem->Selected() += Selected_Delegate;
	}
	Unselected_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiListBoxItem::Unselected_Private);
	if (Unselected.IsBound())
	{
		NoesisListBoxItem->Unselected() += Unselected_Delegate;
	}

}

void UNoesisGuiListBoxItem::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ListBoxItem* NoesisListBoxItem = NsDynamicCast<Noesis::Gui::ListBoxItem*>(NoesisComponent.GetPtr());
	check(NoesisListBoxItem)

	if (Selected.IsBound())
	{
		NoesisListBoxItem->Selected() -= Selected_Delegate;
	}
	if (Unselected.IsBound())
	{
		NoesisListBoxItem->Unselected() -= Unselected_Delegate;
	}

}

