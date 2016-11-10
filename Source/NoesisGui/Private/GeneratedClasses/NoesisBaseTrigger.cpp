////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisBaseTrigger.h"

using namespace Noesis;
using namespace Gui;

UNoesisBaseTrigger::UNoesisBaseTrigger(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisBaseTrigger::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseTrigger* NoesisBaseTrigger = NsDynamicCast<Noesis::Gui::BaseTrigger*>(InNoesisComponent);
	check(NoesisBaseTrigger);
}

class UNoesisTriggerActionCollection* UNoesisBaseTrigger::GetEnterActions()
{
	Noesis::Gui::BaseTrigger* NoesisBaseTrigger = NsDynamicCast<Noesis::Gui::BaseTrigger*>(NoesisComponent.GetPtr());
	check(NoesisBaseTrigger);
	return CastChecked<UNoesisTriggerActionCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisBaseTrigger->GetEnterActions()));
}

class UNoesisTriggerActionCollection* UNoesisBaseTrigger::GetExitActions()
{
	Noesis::Gui::BaseTrigger* NoesisBaseTrigger = NsDynamicCast<Noesis::Gui::BaseTrigger*>(NoesisComponent.GetPtr());
	check(NoesisBaseTrigger);
	return CastChecked<UNoesisTriggerActionCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisBaseTrigger->GetExitActions()));
}

void UNoesisBaseTrigger::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseTrigger* NoesisBaseTrigger = NsDynamicCast<Noesis::Gui::BaseTrigger*>(NoesisComponent.GetPtr());
	check(NoesisBaseTrigger)


}

void UNoesisBaseTrigger::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseTrigger* NoesisBaseTrigger = NsDynamicCast<Noesis::Gui::BaseTrigger*>(NoesisComponent.GetPtr());
	check(NoesisBaseTrigger)


}

