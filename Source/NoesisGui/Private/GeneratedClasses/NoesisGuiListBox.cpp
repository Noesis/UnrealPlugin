////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiListBox.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiListBox::UNoesisGuiListBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiListBox::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(InNoesisComponent);
	check(NoesisListBox);

}

class UNoesisGuiPanel* UNoesisGuiListBox::GetDefaultItemsPanel()
{
	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(NoesisComponent.GetPtr());
	check(NoesisListBox);
	return CastChecked<UNoesisGuiPanel>(Instance->FindUnrealComponentForNoesisComponent(NoesisListBox->GetDefaultItemsPanel()));
}

void UNoesisGuiListBox::ScrollIntoView(class UNoesisGuiBaseComponent* InItem)
{
	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(NoesisComponent.GetPtr());
	check(NoesisListBox);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return NoesisListBox->ScrollIntoView(NoesisInItem);
}

void UNoesisGuiListBox::SelectAll()
{
	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(NoesisComponent.GetPtr());
	check(NoesisListBox);
	return NoesisListBox->SelectAll();
}

void UNoesisGuiListBox::UnselectAll()
{
	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(NoesisComponent.GetPtr());
	check(NoesisListBox);
	return NoesisListBox->UnselectAll();
}

	void UNoesisGuiListBox::BeginDestroy()
{
	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(NoesisComponent.GetPtr());
	if (!NoesisListBox)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

