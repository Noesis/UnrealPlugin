////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisRadioButton.h"

using namespace Noesis;
using namespace Gui;

UNoesisRadioButton::UNoesisRadioButton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisRadioButton::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RadioButton* NoesisRadioButton = NsDynamicCast<Noesis::Gui::RadioButton*>(InNoesisComponent);
	check(NoesisRadioButton);
}

FString UNoesisRadioButton::GetGroupName()
{
	Noesis::Gui::RadioButton* NoesisRadioButton = NsDynamicCast<Noesis::Gui::RadioButton*>(NoesisComponent.GetPtr());
	check(NoesisRadioButton);
	return NsStringToFString(NoesisRadioButton->GetGroupName());
}

void UNoesisRadioButton::SetGroupName(FString InGroupName)
{
	Noesis::Gui::RadioButton* NoesisRadioButton = NsDynamicCast<Noesis::Gui::RadioButton*>(NoesisComponent.GetPtr());
	check(NoesisRadioButton);
	NoesisRadioButton->SetGroupName(StringCast<NsChar>(*InGroupName).Get());
}

void UNoesisRadioButton::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::RadioButton* NoesisRadioButton = NsDynamicCast<Noesis::Gui::RadioButton*>(NoesisComponent.GetPtr());
	check(NoesisRadioButton)


}

void UNoesisRadioButton::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::RadioButton* NoesisRadioButton = NsDynamicCast<Noesis::Gui::RadioButton*>(NoesisComponent.GetPtr());
	check(NoesisRadioButton)


}

