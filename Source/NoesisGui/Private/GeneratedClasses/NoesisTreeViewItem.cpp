////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisTreeViewItem.h"

using namespace Noesis;
using namespace Gui;

UNoesisTreeViewItem::UNoesisTreeViewItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TreeViewItem::StaticGetClassType();
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
	if (!Collapsed.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Collapsed.Broadcast(Sender, Args);
}

void UNoesisTreeViewItem::Expanded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Expanded.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Expanded.Broadcast(Sender, Args);
}

void UNoesisTreeViewItem::Selected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Selected.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Selected.Broadcast(Sender, Args);
}

void UNoesisTreeViewItem::Unselected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Unselected.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Unselected.Broadcast(Sender, Args);
}

void UNoesisTreeViewItem::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TreeViewItem* NoesisTreeViewItem = NsDynamicCast<Noesis::Gui::TreeViewItem*>(NoesisComponent.GetPtr());
	check(NoesisTreeViewItem);

	Collapsed_Delegate = Noesis::MakeDelegate(this, &UNoesisTreeViewItem::Collapsed_Private);
	NoesisTreeViewItem->Collapsed() += Collapsed_Delegate;
	Expanded_Delegate = Noesis::MakeDelegate(this, &UNoesisTreeViewItem::Expanded_Private);
	NoesisTreeViewItem->Expanded() += Expanded_Delegate;
	Selected_Delegate = Noesis::MakeDelegate(this, &UNoesisTreeViewItem::Selected_Private);
	NoesisTreeViewItem->Selected() += Selected_Delegate;
	Unselected_Delegate = Noesis::MakeDelegate(this, &UNoesisTreeViewItem::Unselected_Private);
	NoesisTreeViewItem->Unselected() += Unselected_Delegate;

}

void UNoesisTreeViewItem::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TreeViewItem* NoesisTreeViewItem = NsDynamicCast<Noesis::Gui::TreeViewItem*>(NoesisComponent.GetPtr());
	check(NoesisTreeViewItem);

	NoesisTreeViewItem->Collapsed() -= Collapsed_Delegate;
	NoesisTreeViewItem->Expanded() -= Expanded_Delegate;
	NoesisTreeViewItem->Selected() -= Selected_Delegate;
	NoesisTreeViewItem->Unselected() -= Unselected_Delegate;

}

