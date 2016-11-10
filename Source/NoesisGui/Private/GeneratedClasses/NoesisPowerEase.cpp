////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisPowerEase.h"

using namespace Noesis;
using namespace Gui;

UNoesisPowerEase::UNoesisPowerEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisPowerEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::PowerEase* NoesisPowerEase = NsDynamicCast<Noesis::Gui::PowerEase*>(InNoesisComponent);
	check(NoesisPowerEase);
}

float UNoesisPowerEase::GetPower()
{
	Noesis::Gui::PowerEase* NoesisPowerEase = NsDynamicCast<Noesis::Gui::PowerEase*>(NoesisComponent.GetPtr());
	check(NoesisPowerEase);
	return (float)NoesisPowerEase->GetPower();
}

void UNoesisPowerEase::SetPower(float InPower)
{
	Noesis::Gui::PowerEase* NoesisPowerEase = NsDynamicCast<Noesis::Gui::PowerEase*>(NoesisComponent.GetPtr());
	check(NoesisPowerEase);
	NoesisPowerEase->SetPower(InPower);
}

void UNoesisPowerEase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::PowerEase* NoesisPowerEase = NsDynamicCast<Noesis::Gui::PowerEase*>(NoesisComponent.GetPtr());
	check(NoesisPowerEase)


}

void UNoesisPowerEase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::PowerEase* NoesisPowerEase = NsDynamicCast<Noesis::Gui::PowerEase*>(NoesisComponent.GetPtr());
	check(NoesisPowerEase)


}

