////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisListBoxItem.h"

using namespace Noesis;
using namespace Gui;

UNoesisListBoxItem::UNoesisListBoxItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ListBoxItem::StaticGetClassType();
}

void UNoesisListBoxItem::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ListBoxItem* NoesisListBoxItem = NsDynamicCast<Noesis::Gui::ListBoxItem*>(InNoesisComponent);
	check(NoesisListBoxItem);
}

bool UNoesisListBoxItem::GetIsSelected()
{
	Noesis::Gui::ListBoxItem* NoesisListBoxItem = NsDynamicCast<Noesis::Gui::ListBoxItem*>(NoesisComponent.GetPtr());
	check(NoesisListBoxItem);
	return NoesisListBoxItem->GetIsSelected();
}

void UNoesisListBoxItem::SetIsSelected(bool InIsSelected)
{
	Noesis::Gui::ListBoxItem* NoesisListBoxItem = NsDynamicCast<Noesis::Gui::ListBoxItem*>(NoesisComponent.GetPtr());
	check(NoesisListBoxItem);
	NoesisListBoxItem->SetIsSelected(InIsSelected);
}

void UNoesisListBoxItem::Selected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Selected.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Selected.Broadcast(Sender, Args);
}

void UNoesisListBoxItem::Unselected_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Unselected.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Unselected.Broadcast(Sender, Args);
}

void UNoesisListBoxItem::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ListBoxItem* NoesisListBoxItem = NsDynamicCast<Noesis::Gui::ListBoxItem*>(NoesisComponent.GetPtr());
	check(NoesisListBoxItem);

	Selected_Delegate = Noesis::MakeDelegate(this, &UNoesisListBoxItem::Selected_Private);
	NoesisListBoxItem->Selected() += Selected_Delegate;
	Unselected_Delegate = Noesis::MakeDelegate(this, &UNoesisListBoxItem::Unselected_Private);
	NoesisListBoxItem->Unselected() += Unselected_Delegate;

}

void UNoesisListBoxItem::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ListBoxItem* NoesisListBoxItem = NsDynamicCast<Noesis::Gui::ListBoxItem*>(NoesisComponent.GetPtr());
	check(NoesisListBoxItem);

	NoesisListBoxItem->Selected() -= Selected_Delegate;
	NoesisListBoxItem->Unselected() -= Unselected_Delegate;

}

