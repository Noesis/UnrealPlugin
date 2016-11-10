////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisTreeViewItem.h"

using namespace Noesis;
using namespace Gui;

UNoesisTreeViewItem::UNoesisTreeViewItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisTreeViewItem::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TreeViewItem* NoesisTreeViewItem = NsDynamicCast<Noesis::Gui::TreeViewItem*>(InNoesisComponent);
	check(NoesisTreeViewItem);
}

bool UNoesisTreeViewItem::GetIsExpanded()
{
	Noesis::Gui::TreeViewItem* NoesisTreeViewItem = NsDynamicCast<Noesis::Gui::TreeViewItem*>(NoesisComponent.GetPtr());
	check(NoesisTreeViewItem);
	return NoesisTreeViewItem->GetIsExpanded();
}

void UNoesisTreeViewItem::SetIsExpanded(bool InIsExpanded)
{
	Noesis::Gui::TreeViewItem* NoesisTreeViewItem = NsDynamicCast<Noesis::Gui::TreeViewItem*>(NoesisComponent.GetPtr());
	check(NoesisTreeViewItem);
	NoesisTreeViewItem->SetIsExpanded(InIsExpanded);
}

bool UNoesisTreeViewItem::GetIsSelected()
{
	Noesis::Gui::TreeViewItem* NoesisTreeViewItem = NsDynamicCast<Noesis::Gui::TreeViewItem*>(NoesisComponent.GetPtr());
	check(NoesisTreeViewItem);
	return NoesisTreeViewItem->GetIsSelected();
}

void UNoesisTreeViewItem::SetIsSelected(bool InIsSelected)
{
	Noesis::Gui::TreeViewItem* NoesisTreeViewItem = NsDynamicCast<Noesis::Gui::TreeViewItem*>(NoesisComponent.GetPtr());
	check(NoesisTreeViewItem);
	NoesisTreeViewItem->SetIsSelected(InIsSelected);
}

bool UNoesisTreeViewItem::GetIsSelectionActive()
{
	Noesis::Gui::TreeViewItem* NoesisTreeViewItem = NsDynamicCast<Noesis::Gui::TreeViewItem*>(NoesisComponent.GetPtr());
	check(NoesisTreeViewItem);
	return NoesisTreeViewItem->GetIsSelectionActive();
}

void UNoesisTreeViewItem::SetIsSelectionActive(bool InIsSelectionActive)
{
	Noesis::Gui::TreeViewItem* NoesisTreeViewItem = NsDynamicCast<Noesis::Gui::TreeViewItem*>(NoesisComponent.GetPtr());
	check(NoesisTreeViewItem);
	NoesisTreeViewItem->SetIsSelectionActive(InIsSelectionActive);
}

void UNoesisTreeViewItem::Collapsed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Collapsed.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	Collapsed.Broadcast(Sender, Args);
}

void UNoesisTreeViewItem::Expanded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Expanded.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	Expanded.Broadcast(Sender, Args);
}

void UNoesisTreeViewItem::Selected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Selected.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	Selected.Broadcast(Sender, Args);
}

void UNoesisTreeViewItem::Unselected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Unselected.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	Unselected.Broadcast(Sender, Args);
}

void UNoesisTreeViewItem::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TreeViewItem* NoesisTreeViewItem = NsDynamicCast<Noesis::Gui::TreeViewItem*>(NoesisComponent.GetPtr());
	check(NoesisTreeViewItem)

	Collapsed_Delegate = Noesis::MakeDelegate(this, &UNoesisTreeViewItem::Collapsed_Private);
	if (Collapsed.IsBound())
	{
		NoesisTreeViewItem->Collapsed() += Collapsed_Delegate;
	}
	Expanded_Delegate = Noesis::MakeDelegate(this, &UNoesisTreeViewItem::Expanded_Private);
	if (Expanded.IsBound())
	{
		NoesisTreeViewItem->Expanded() += Expanded_Delegate;
	}
	Selected_Delegate = Noesis::MakeDelegate(this, &UNoesisTreeViewItem::Selected_Private);
	if (Selected.IsBound())
	{
		NoesisTreeViewItem->Selected() += Selected_Delegate;
	}
	Unselected_Delegate = Noesis::MakeDelegate(this, &UNoesisTreeViewItem::Unselected_Private);
	if (Unselected.IsBound())
	{
		NoesisTreeViewItem->Unselected() += Unselected_Delegate;
	}

}

void UNoesisTreeViewItem::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TreeViewItem* NoesisTreeViewItem = NsDynamicCast<Noesis::Gui::TreeViewItem*>(NoesisComponent.GetPtr());
	check(NoesisTreeViewItem)

	if (Collapsed.IsBound())
	{
		NoesisTreeViewItem->Collapsed() -= Collapsed_Delegate;
	}
	if (Expanded.IsBound())
	{
		NoesisTreeViewItem->Expanded() -= Expanded_Delegate;
	}
	if (Selected.IsBound())
	{
		NoesisTreeViewItem->Selected() -= Selected_Delegate;
	}
	if (Unselected.IsBound())
	{
		NoesisTreeViewItem->Unselected() -= Unselected_Delegate;
	}

}

