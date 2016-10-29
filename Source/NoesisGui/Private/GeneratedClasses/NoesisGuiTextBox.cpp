////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTextBox.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTextBox::UNoesisGuiTextBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTextBox::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(InNoesisComponent);
	check(NoesisTextBox);
}

FString UNoesisGuiTextBox::GetSelectedText()
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	return NsStringToFString(NoesisTextBox->GetSelectedText());
}

void UNoesisGuiTextBox::SetSelectedText(FString InSelectedText)
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	NoesisTextBox->SetSelectedText(StringCast<NsChar>(*InSelectedText).Get());
}

int32 UNoesisGuiTextBox::GetSelectionLength()
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	return NoesisTextBox->GetSelectionLength();
}

void UNoesisGuiTextBox::SetSelectionLength(int32 InSelectionLength)
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	NoesisTextBox->SetSelectionLength(InSelectionLength);
}

int32 UNoesisGuiTextBox::GetSelectionStart()
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	return NoesisTextBox->GetSelectionStart();
}

void UNoesisGuiTextBox::SetSelectionStart(int32 InSelectionStart)
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	NoesisTextBox->SetSelectionStart(InSelectionStart);
}

int32 UNoesisGuiTextBox::GetCaretIndex()
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	return NoesisTextBox->GetCaretIndex();
}

void UNoesisGuiTextBox::SelectAll()
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	return NoesisTextBox->SelectAll();
}

void UNoesisGuiTextBox::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox)


}

void UNoesisGuiTextBox::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox)


}

