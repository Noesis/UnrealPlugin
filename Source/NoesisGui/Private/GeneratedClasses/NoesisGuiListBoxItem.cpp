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

	NoesisListBoxItem->Selected() += Noesis::MakeDelegate(this, &UNoesisGuiListBoxItem::Selected_Private);
	NoesisListBoxItem->Unselected() += Noesis::MakeDelegate(this, &UNoesisGuiListBoxItem::Unselected_Private);
}

	void UNoesisGuiListBoxItem::Selected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Selected.Broadcast(Sender, Args);
}

	void UNoesisGuiListBoxItem::Unselected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Unselected.Broadcast(Sender, Args);
}

	void UNoesisGuiListBoxItem::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::ListBoxItem* NoesisListBoxItem = NsDynamicCast<Noesis::Gui::ListBoxItem*>(NoesisComponent.GetPtr());
	if (!NoesisListBoxItem)
		return;

	NoesisListBoxItem->Selected() -= Noesis::MakeDelegate(this, &UNoesisGuiListBoxItem::Selected_Private);
	NoesisListBoxItem->Unselected() -= Noesis::MakeDelegate(this, &UNoesisGuiListBoxItem::Unselected_Private);
}

