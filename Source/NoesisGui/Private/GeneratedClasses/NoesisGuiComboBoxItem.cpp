////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiComboBoxItem.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiComboBoxItem::UNoesisGuiComboBoxItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiComboBoxItem::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ComboBoxItem* NoesisComboBoxItem = NsDynamicCast<Noesis::Gui::ComboBoxItem*>(InNoesisComponent);
	check(NoesisComboBoxItem);

}

	void UNoesisGuiComboBoxItem::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::ComboBoxItem* NoesisComboBoxItem = NsDynamicCast<Noesis::Gui::ComboBoxItem*>(NoesisComponent.GetPtr());
	if (!NoesisComboBoxItem)
		return;

}

