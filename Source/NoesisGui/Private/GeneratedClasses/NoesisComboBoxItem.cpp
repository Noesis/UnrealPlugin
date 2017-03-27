////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisComboBoxItem.h"

using namespace Noesis;
using namespace Gui;

UNoesisComboBoxItem::UNoesisComboBoxItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ComboBoxItem::StaticGetClassType();
}

void UNoesisComboBoxItem::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ComboBoxItem* NoesisComboBoxItem = NsDynamicCast<Noesis::Gui::ComboBoxItem*>(InNoesisComponent);
	check(NoesisComboBoxItem);
}

bool UNoesisComboBoxItem::GetIsHighlighted()
{
	Noesis::Gui::ComboBoxItem* NoesisComboBoxItem = NsDynamicCast<Noesis::Gui::ComboBoxItem*>(NoesisComponent.GetPtr());
	check(NoesisComboBoxItem);
	return NoesisComboBoxItem->GetIsHighlighted();
}

void UNoesisComboBoxItem::SetHighlighted(bool InValue)
{
	Noesis::Gui::ComboBoxItem* NoesisComboBoxItem = NsDynamicCast<Noesis::Gui::ComboBoxItem*>(NoesisComponent.GetPtr());
	check(NoesisComboBoxItem);
	NsBool NoesisInValue = InValue;
	return NoesisComboBoxItem->SetHighlighted(NoesisInValue);
}

void UNoesisComboBoxItem::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ComboBoxItem* NoesisComboBoxItem = NsDynamicCast<Noesis::Gui::ComboBoxItem*>(NoesisComponent.GetPtr());
	check(NoesisComboBoxItem);


}

void UNoesisComboBoxItem::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ComboBoxItem* NoesisComboBoxItem = NsDynamicCast<Noesis::Gui::ComboBoxItem*>(NoesisComponent.GetPtr());
	check(NoesisComboBoxItem);


}

