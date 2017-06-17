////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisRepeatButton.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisRepeatButton::UNoesisRepeatButton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::RepeatButton::StaticGetClassType();
}

void UNoesisRepeatButton::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RepeatButton* NoesisRepeatButton = NsDynamicCast<Noesis::Gui::RepeatButton*>(InNoesisComponent);
	check(NoesisRepeatButton);
}

int32 UNoesisRepeatButton::GetDelay()
{
	Noesis::Gui::RepeatButton* NoesisRepeatButton = NsDynamicCast<Noesis::Gui::RepeatButton*>(NoesisComponent.GetPtr());
	check(NoesisRepeatButton);
	return NoesisRepeatButton->GetDelay();
}

void UNoesisRepeatButton::SetDelay(int32 InDelay)
{
	Noesis::Gui::RepeatButton* NoesisRepeatButton = NsDynamicCast<Noesis::Gui::RepeatButton*>(NoesisComponent.GetPtr());
	check(NoesisRepeatButton);
	NoesisRepeatButton->SetDelay(InDelay);
}

int32 UNoesisRepeatButton::GetInterval()
{
	Noesis::Gui::RepeatButton* NoesisRepeatButton = NsDynamicCast<Noesis::Gui::RepeatButton*>(NoesisComponent.GetPtr());
	check(NoesisRepeatButton);
	return NoesisRepeatButton->GetInterval();
}

void UNoesisRepeatButton::SetInterval(int32 InInterval)
{
	Noesis::Gui::RepeatButton* NoesisRepeatButton = NsDynamicCast<Noesis::Gui::RepeatButton*>(NoesisComponent.GetPtr());
	check(NoesisRepeatButton);
	NoesisRepeatButton->SetInterval(InInterval);
}

void UNoesisRepeatButton::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::RepeatButton* NoesisRepeatButton = NsDynamicCast<Noesis::Gui::RepeatButton*>(NoesisComponent.GetPtr());
	check(NoesisRepeatButton);


}

void UNoesisRepeatButton::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::RepeatButton* NoesisRepeatButton = NsDynamicCast<Noesis::Gui::RepeatButton*>(NoesisComponent.GetPtr());
	check(NoesisRepeatButton);


}

