////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisTextBox.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisTextBox::UNoesisTextBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TextBox::StaticGetClassType();
}

void UNoesisTextBox::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(InNoesisComponent);
	check(NoesisTextBox);
}

int32 UNoesisTextBox::GetMaxLength()
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	return NoesisTextBox->GetMaxLength();
}

void UNoesisTextBox::SetMaxLength(int32 InMaxLength)
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	NoesisTextBox->SetMaxLength(InMaxLength);
}

int32 UNoesisTextBox::GetMaxLines()
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	return NoesisTextBox->GetMaxLines();
}

void UNoesisTextBox::SetMaxLines(int32 InMaxLines)
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	NoesisTextBox->SetMaxLines(InMaxLines);
}

int32 UNoesisTextBox::GetMinLines()
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	return NoesisTextBox->GetMinLines();
}

void UNoesisTextBox::SetMinLines(int32 InMinLines)
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	NoesisTextBox->SetMinLines(InMinLines);
}

FString UNoesisTextBox::GetSelectedText()
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	return NsStringToFString(NoesisTextBox->GetSelectedText());
}

void UNoesisTextBox::SetSelectedText(FString InSelectedText)
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	NoesisTextBox->SetSelectedText(StringCast<NsChar>(*InSelectedText).Get());
}

int32 UNoesisTextBox::GetSelectionLength()
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	return NoesisTextBox->GetSelectionLength();
}

void UNoesisTextBox::SetSelectionLength(int32 InSelectionLength)
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	NoesisTextBox->SetSelectionLength(InSelectionLength);
}

int32 UNoesisTextBox::GetSelectionStart()
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	return NoesisTextBox->GetSelectionStart();
}

void UNoesisTextBox::SetSelectionStart(int32 InSelectionStart)
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	NoesisTextBox->SetSelectionStart(InSelectionStart);
}

FString UNoesisTextBox::GetText()
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	return NsStringToFString(NoesisTextBox->GetText());
}

void UNoesisTextBox::SetText(FString InText)
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	NoesisTextBox->SetText(StringCast<NsChar>(*InText).Get());
}

ENoesisTextAlignment UNoesisTextBox::GetTextAlignment()
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	return (ENoesisTextAlignment)NoesisTextBox->GetTextAlignment();
}

void UNoesisTextBox::SetTextAlignment(ENoesisTextAlignment InTextAlignment)
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	NoesisTextBox->SetTextAlignment((Noesis::Gui::TextAlignment)InTextAlignment);
}

ENoesisTextWrapping UNoesisTextBox::GetTextWrapping()
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	return (ENoesisTextWrapping)NoesisTextBox->GetTextWrapping();
}

void UNoesisTextBox::SetTextWrapping(ENoesisTextWrapping InTextWrapping)
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	NoesisTextBox->SetTextWrapping((Noesis::Gui::TextWrapping)InTextWrapping);
}

int32 UNoesisTextBox::GetCaretIndex()
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	return NoesisTextBox->GetCaretIndex();
}

void UNoesisTextBox::SelectAll()
{
	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);
	return NoesisTextBox->SelectAll();
}

void UNoesisTextBox::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);


}

void UNoesisTextBox::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TextBox* NoesisTextBox = NsDynamicCast<Noesis::Gui::TextBox*>(NoesisComponent.GetPtr());
	check(NoesisTextBox);


}

