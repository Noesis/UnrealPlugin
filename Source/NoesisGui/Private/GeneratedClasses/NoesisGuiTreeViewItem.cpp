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

	Collapsed_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiTreeViewItem::Collapsed_Private);
	NoesisTreeViewItem->Collapsed() += Collapsed_Delegate;
	Expanded_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiTreeViewItem::Expanded_Private);
	NoesisTreeViewItem->Expanded() += Expanded_Delegate;
	Selected_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiTreeViewItem::Selected_Private);
	NoesisTreeViewItem->Selected() += Selected_Delegate;
	Unselected_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiTreeViewItem::Unselected_Private);
	NoesisTreeViewItem->Unselected() += Unselected_Delegate;
}

	void UNoesisGuiTreeViewItem::Collapsed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Collapsed.Broadcast(Sender, Args);
}

	void UNoesisGuiTreeViewItem::Expanded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Expanded.Broadcast(Sender, Args);
}

	void UNoesisGuiTreeViewItem::Selected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Selected.Broadcast(Sender, Args);
}

	void UNoesisGuiTreeViewItem::Unselected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Unselected.Broadcast(Sender, Args);
}

	void UNoesisGuiTreeViewItem::BeginDestroy()
{
	Noesis::Gui::TreeViewItem* NoesisTreeViewItem = NsDynamicCast<Noesis::Gui::TreeViewItem*>(NoesisComponent.GetPtr());
	if (!NoesisTreeViewItem)
		return Super::BeginDestroy();

	NoesisTreeViewItem->Collapsed() -= Collapsed_Delegate;
	NoesisTreeViewItem->Expanded() -= Expanded_Delegate;
	NoesisTreeViewItem->Selected() -= Selected_Delegate;
	NoesisTreeViewItem->Unselected() -= Unselected_Delegate;

	Super::BeginDestroy();
}

