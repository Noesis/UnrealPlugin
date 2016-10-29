////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTreeViewItem.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTreeViewItem::UNoesisGuiTreeViewItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTreeViewItem::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TreeViewItem* NoesisTreeViewItem = NsDynamicCast<Noesis::Gui::TreeViewItem*>(InNoesisComponent);
	check(NoesisTreeViewItem);
}

void UNoesisGuiTreeViewItem::Collapsed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Collapsed.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Collapsed.Broadcast(Sender, Args);
}

void UNoesisGuiTreeViewItem::Expanded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Expanded.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Expanded.Broadcast(Sender, Args);
}

void UNoesisGuiTreeViewItem::Selected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Selected.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Selected.Broadcast(Sender, Args);
}

void UNoesisGuiTreeViewItem::Unselected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Unselected.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Unselected.Broadcast(Sender, Args);
}

void UNoesisGuiTreeViewItem::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TreeViewItem* NoesisTreeViewItem = NsDynamicCast<Noesis::Gui::TreeViewItem*>(NoesisComponent.GetPtr());
	check(NoesisTreeViewItem)

	Collapsed_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiTreeViewItem::Collapsed_Private);
	if (Collapsed.IsBound())
	{
		NoesisTreeViewItem->Collapsed() += Collapsed_Delegate;
	}
	Expanded_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiTreeViewItem::Expanded_Private);
	if (Expanded.IsBound())
	{
		NoesisTreeViewItem->Expanded() += Expanded_Delegate;
	}
	Selected_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiTreeViewItem::Selected_Private);
	if (Selected.IsBound())
	{
		NoesisTreeViewItem->Selected() += Selected_Delegate;
	}
	Unselected_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiTreeViewItem::Unselected_Private);
	if (Unselected.IsBound())
	{
		NoesisTreeViewItem->Unselected() += Unselected_Delegate;
	}

}

void UNoesisGuiTreeViewItem::UnbindEvents()
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

