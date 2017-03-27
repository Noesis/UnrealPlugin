////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisComboBox.h"

using namespace Noesis;
using namespace Gui;

UNoesisComboBox::UNoesisComboBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ComboBox::StaticGetClassType();
}

void UNoesisComboBox::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(InNoesisComponent);
	check(NoesisComboBox);
}

bool UNoesisComboBox::GetIsDropDownOpen()
{
	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(NoesisComponent.GetPtr());
	check(NoesisComboBox);
	return NoesisComboBox->GetIsDropDownOpen();
}

void UNoesisComboBox::SetIsDropDownOpen(bool InIsDropDownOpen)
{
	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(NoesisComponent.GetPtr());
	check(NoesisComboBox);
	NoesisComboBox->SetIsDropDownOpen(InIsDropDownOpen);
}

bool UNoesisComboBox::GetIsEditable()
{
	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(NoesisComponent.GetPtr());
	check(NoesisComboBox);
	return NoesisComboBox->GetIsEditable();
}

void UNoesisComboBox::SetIsEditable(bool InIsEditable)
{
	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(NoesisComponent.GetPtr());
	check(NoesisComboBox);
	NoesisComboBox->SetIsEditable(InIsEditable);
}

bool UNoesisComboBox::GetIsReadOnly()
{
	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(NoesisComponent.GetPtr());
	check(NoesisComboBox);
	return NoesisComboBox->GetIsReadOnly();
}

void UNoesisComboBox::SetIsReadOnly(bool InIsReadOnly)
{
	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(NoesisComponent.GetPtr());
	check(NoesisComboBox);
	NoesisComboBox->SetIsReadOnly(InIsReadOnly);
}

float UNoesisComboBox::GetMaxDropDownHeight()
{
	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(NoesisComponent.GetPtr());
	check(NoesisComboBox);
	return (float)NoesisComboBox->GetMaxDropDownHeight();
}

void UNoesisComboBox::SetMaxDropDownHeight(float InMaxDropDownHeight)
{
	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(NoesisComponent.GetPtr());
	check(NoesisComboBox);
	NoesisComboBox->SetMaxDropDownHeight(InMaxDropDownHeight);
}

class UNoesisBaseComponent* UNoesisComboBox::GetSelectionBoxItem()
{
	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(NoesisComponent.GetPtr());
	check(NoesisComboBox);
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisComboBox->GetSelectionBoxItem(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisDataTemplate* UNoesisComboBox::GetSelectionBoxItemTemplate()
{
	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(NoesisComponent.GetPtr());
	check(NoesisComboBox);
	return CastChecked<UNoesisDataTemplate>(CreateClassFor(NoesisComboBox->GetSelectionBoxItemTemplate(), nullptr), ECastCheckedType::NullAllowed);
}

bool UNoesisComboBox::GetStaysOpenOnEdit()
{
	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(NoesisComponent.GetPtr());
	check(NoesisComboBox);
	return NoesisComboBox->GetStaysOpenOnEdit();
}

void UNoesisComboBox::SetStaysOpenOnEdit(bool InStaysOpenOnEdit)
{
	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(NoesisComponent.GetPtr());
	check(NoesisComboBox);
	NoesisComboBox->SetStaysOpenOnEdit(InStaysOpenOnEdit);
}

FString UNoesisComboBox::GetText()
{
	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(NoesisComponent.GetPtr());
	check(NoesisComboBox);
	return NsStringToFString(NoesisComboBox->GetText());
}

void UNoesisComboBox::SetText(FString InText)
{
	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(NoesisComponent.GetPtr());
	check(NoesisComboBox);
	NoesisComboBox->SetText(StringCast<NsChar>(*InText).Get());
}

void UNoesisComboBox::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(NoesisComponent.GetPtr());
	check(NoesisComboBox);


}

void UNoesisComboBox::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ComboBox* NoesisComboBox = NsDynamicCast<Noesis::Gui::ComboBox*>(NoesisComponent.GetPtr());
	check(NoesisComboBox);


}

