////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisEventTrigger.h"

using namespace Noesis;
using namespace Gui;

UNoesisEventTrigger::UNoesisEventTrigger(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisEventTrigger::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EventTrigger* NoesisEventTrigger = NsDynamicCast<Noesis::Gui::EventTrigger*>(InNoesisComponent);
	check(NoesisEventTrigger);
}

class UNoesisTriggerActionCollection* UNoesisEventTrigger::GetActions()
{
	Noesis::Gui::EventTrigger* NoesisEventTrigger = NsDynamicCast<Noesis::Gui::EventTrigger*>(NoesisComponent.GetPtr());
	check(NoesisEventTrigger);
	return CastChecked<UNoesisTriggerActionCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisEventTrigger->GetActions()));
}

class UNoesisRoutedEvent* UNoesisEventTrigger::GetRoutedEvent()
{
	Noesis::Gui::EventTrigger* NoesisEventTrigger = NsDynamicCast<Noesis::Gui::EventTrigger*>(NoesisComponent.GetPtr());
	check(NoesisEventTrigger);
	return CastChecked<UNoesisRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(NoesisEventTrigger->GetRoutedEvent()));
}

void UNoesisEventTrigger::SetRoutedEvent(class UNoesisRoutedEvent* InRoutedEvent)
{
	Noesis::Gui::EventTrigger* NoesisEventTrigger = NsDynamicCast<Noesis::Gui::EventTrigger*>(NoesisComponent.GetPtr());
	check(NoesisEventTrigger);
	NoesisEventTrigger->SetRoutedEvent(NsDynamicCast<const RoutedEvent*>(InRoutedEvent->NoesisComponent.GetPtr()));
}

FString UNoesisEventTrigger::GetSourceName()
{
	Noesis::Gui::EventTrigger* NoesisEventTrigger = NsDynamicCast<Noesis::Gui::EventTrigger*>(NoesisComponent.GetPtr());
	check(NoesisEventTrigger);
	return NsStringToFString(NoesisEventTrigger->GetSourceName());
}

void UNoesisEventTrigger::SetSourceName(FString InSourceName)
{
	Noesis::Gui::EventTrigger* NoesisEventTrigger = NsDynamicCast<Noesis::Gui::EventTrigger*>(NoesisComponent.GetPtr());
	check(NoesisEventTrigger);
	NoesisEventTrigger->SetSourceName(StringCast<NsChar>(*InSourceName).Get());
}

void UNoesisEventTrigger::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::EventTrigger* NoesisEventTrigger = NsDynamicCast<Noesis::Gui::EventTrigger*>(NoesisComponent.GetPtr());
	check(NoesisEventTrigger)


}

void UNoesisEventTrigger::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::EventTrigger* NoesisEventTrigger = NsDynamicCast<Noesis::Gui::EventTrigger*>(NoesisComponent.GetPtr());
	check(NoesisEventTrigger)


}

