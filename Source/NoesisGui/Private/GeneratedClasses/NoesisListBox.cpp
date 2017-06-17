////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisListBox.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisListBox::UNoesisListBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ListBox::StaticGetClassType();
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
	return CastChecked<UNoesisIList>(CreateInterfaceFor(NoesisListBox->GetSelectedItems(), nullptr), ECastCheckedType::NullAllowed);
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
	return CastChecked<UNoesisPanel>(CreateClassFor(NoesisListBox->GetDefaultItemsPanel(), nullptr), ECastCheckedType::NullAllowed);
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
	check(NoesisListBox);


}

void UNoesisListBox::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ListBox* NoesisListBox = NsDynamicCast<Noesis::Gui::ListBox*>(NoesisComponent.GetPtr());
	check(NoesisListBox);


}

