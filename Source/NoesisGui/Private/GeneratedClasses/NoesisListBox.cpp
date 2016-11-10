////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisListBox.h"

using namespace Noesis;
using namespace Gui;

UNoesisListBox::UNoesisListBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisListBox::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(InNoesisComponent);
	check(NoesisListBox);
}

class UNoesisIList* UNoesisListBox::GetSelectedItems()
{
	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(NoesisComponent.GetPtr());
	check(NoesisListBox);
	return CastChecked<UNoesisIList>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisListBox->GetSelectedItems()));
}

ENoesisSelectionMode UNoesisListBox::GetSelectionMode()
{
	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(NoesisComponent.GetPtr());
	check(NoesisListBox);
	return (ENoesisSelectionMode)NoesisListBox->GetSelectionMode();
}

void UNoesisListBox::SetSelectionMode(ENoesisSelectionMode InSelectionMode)
{
	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(NoesisComponent.GetPtr());
	check(NoesisListBox);
	NoesisListBox->SetSelectionMode((Noesis::Gui::SelectionMode)InSelectionMode);
}

class UNoesisPanel* UNoesisListBox::GetDefaultItemsPanel()
{
	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(NoesisComponent.GetPtr());
	check(NoesisListBox);
	return CastChecked<UNoesisPanel>(Instance->FindUnrealComponentForNoesisComponent(NoesisListBox->GetDefaultItemsPanel()));
}

void UNoesisListBox::ScrollIntoView(class UNoesisBaseComponent* InItem)
{
	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(NoesisComponent.GetPtr());
	check(NoesisListBox);
	Core::BaseComponent* NoesisInItem = NsDynamicCast<Core::BaseComponent*>(InItem->NoesisComponent.GetPtr());
	return NoesisListBox->ScrollIntoView(NoesisInItem);
}

void UNoesisListBox::SelectAll()
{
	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(NoesisComponent.GetPtr());
	check(NoesisListBox);
	return NoesisListBox->SelectAll();
}

void UNoesisListBox::UnselectAll()
{
	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(NoesisComponent.GetPtr());
	check(NoesisListBox);
	return NoesisListBox->UnselectAll();
}

void UNoesisListBox::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(NoesisComponent.GetPtr());
	check(NoesisListBox)


}

void UNoesisListBox::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(NoesisComponent.GetPtr());
	check(NoesisListBox)


}

