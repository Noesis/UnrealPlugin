////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisButton.h"

using namespace Noesis;
using namespace Gui;

UNoesisButton::UNoesisButton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisButton::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Button* NoesisButton = NsDynamicCast<Noesis::Gui::Button*>(InNoesisComponent);
	check(NoesisButton);
}

bool UNoesisButton::GetIsCancel()
{
	Noesis::Gui::Button* NoesisButton = NsDynamicCast<Noesis::Gui::Button*>(NoesisComponent.GetPtr());
	check(NoesisButton);
	return NoesisButton->GetIsCancel();
}

void UNoesisButton::SetIsCancel(bool InIsCancel)
{
	Noesis::Gui::Button* NoesisButton = NsDynamicCast<Noesis::Gui::Button*>(NoesisComponent.GetPtr());
	check(NoesisButton);
	NoesisButton->SetIsCancel(InIsCancel);
}

bool UNoesisButton::GetIsDefault()
{
	Noesis::Gui::Button* NoesisButton = NsDynamicCast<Noesis::Gui::Button*>(NoesisComponent.GetPtr());
	check(NoesisButton);
	return NoesisButton->GetIsDefault();
}

void UNoesisButton::SetIsDefault(bool InIsDefault)
{
	Noesis::Gui::Button* NoesisButton = NsDynamicCast<Noesis::Gui::Button*>(NoesisComponent.GetPtr());
	check(NoesisButton);
	NoesisButton->SetIsDefault(InIsDefault);
}

bool UNoesisButton::GetIsDefaulted()
{
	Noesis::Gui::Button* NoesisButton = NsDynamicCast<Noesis::Gui::Button*>(NoesisComponent.GetPtr());
	check(NoesisButton);
	return NoesisButton->GetIsDefaulted();
}

void UNoesisButton::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Button* NoesisButton = NsDynamicCast<Noesis::Gui::Button*>(NoesisComponent.GetPtr());
	check(NoesisButton)


}

void UNoesisButton::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Button* NoesisButton = NsDynamicCast<Noesis::Gui::Button*>(NoesisComponent.GetPtr());
	check(NoesisButton)


}

