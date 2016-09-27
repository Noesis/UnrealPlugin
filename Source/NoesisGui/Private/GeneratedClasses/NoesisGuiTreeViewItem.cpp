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

	NoesisTreeViewItem->Collapsed() += Noesis::MakeDelegate(this, &UNoesisGuiTreeViewItem::Collapsed_Private);
	NoesisTreeViewItem->Expanded() += Noesis::MakeDelegate(this, &UNoesisGuiTreeViewItem::Expanded_Private);
	NoesisTreeViewItem->Selected() += Noesis::MakeDelegate(this, &UNoesisGuiTreeViewItem::Selected_Private);
	NoesisTreeViewItem->Unselected() += Noesis::MakeDelegate(this, &UNoesisGuiTreeViewItem::Unselected_Private);
}

	void UNoesisGuiTreeViewItem::Collapsed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Collapsed.Broadcast(Sender, Args);
}

	void UNoesisGuiTreeViewItem::Expanded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Expanded.Broadcast(Sender, Args);
}

	void UNoesisGuiTreeViewItem::Selected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Selected.Broadcast(Sender, Args);
}

	void UNoesisGuiTreeViewItem::Unselected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Unselected.Broadcast(Sender, Args);
}

	void UNoesisGuiTreeViewItem::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::TreeViewItem* NoesisTreeViewItem = NsDynamicCast<Noesis::Gui::TreeViewItem*>(NoesisComponent.GetPtr());
	if (!NoesisTreeViewItem)
		return;

	NoesisTreeViewItem->Collapsed() -= Noesis::MakeDelegate(this, &UNoesisGuiTreeViewItem::Collapsed_Private);
	NoesisTreeViewItem->Expanded() -= Noesis::MakeDelegate(this, &UNoesisGuiTreeViewItem::Expanded_Private);
	NoesisTreeViewItem->Selected() -= Noesis::MakeDelegate(this, &UNoesisGuiTreeViewItem::Selected_Private);
	NoesisTreeViewItem->Unselected() -= Noesis::MakeDelegate(this, &UNoesisGuiTreeViewItem::Unselected_Private);
}

