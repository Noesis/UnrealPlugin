////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseTrigger.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseTrigger::UNoesisGuiBaseTrigger(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseTrigger::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseTrigger* NoesisBaseTrigger = NsDynamicCast<Noesis::Gui::BaseTrigger*>(InNoesisComponent);
	check(NoesisBaseTrigger);
}

class UNoesisGuiTriggerActionCollection* UNoesisGuiBaseTrigger::GetEnterActions()
{
	Noesis::Gui::BaseTrigger* NoesisBaseTrigger = NsDynamicCast<Noesis::Gui::BaseTrigger*>(NoesisComponent.GetPtr());
	check(NoesisBaseTrigger);
	return CastChecked<UNoesisGuiTriggerActionCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisBaseTrigger->GetEnterActions()));
}

class UNoesisGuiTriggerActionCollection* UNoesisGuiBaseTrigger::GetExitActions()
{
	Noesis::Gui::BaseTrigger* NoesisBaseTrigger = NsDynamicCast<Noesis::Gui::BaseTrigger*>(NoesisComponent.GetPtr());
	check(NoesisBaseTrigger);
	return CastChecked<UNoesisGuiTriggerActionCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisBaseTrigger->GetExitActions()));
}

void UNoesisGuiBaseTrigger::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseTrigger* NoesisBaseTrigger = NsDynamicCast<Noesis::Gui::BaseTrigger*>(NoesisComponent.GetPtr());
	check(NoesisBaseTrigger)


}

void UNoesisGuiBaseTrigger::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseTrigger* NoesisBaseTrigger = NsDynamicCast<Noesis::Gui::BaseTrigger*>(NoesisComponent.GetPtr());
	check(NoesisBaseTrigger)


}

