////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiEventTrigger.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiEventTrigger::UNoesisGuiEventTrigger(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiEventTrigger::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EventTrigger* NoesisEventTrigger = NsDynamicCast<Noesis::Gui::EventTrigger*>(InNoesisComponent);
	check(NoesisEventTrigger);
}

class UNoesisGuiTriggerActionCollection* UNoesisGuiEventTrigger::GetActions()
{
	Noesis::Gui::EventTrigger* NoesisEventTrigger = NsDynamicCast<Noesis::Gui::EventTrigger*>(NoesisComponent.GetPtr());
	check(NoesisEventTrigger);
	return CastChecked<UNoesisGuiTriggerActionCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisEventTrigger->GetActions()));
}

class UNoesisGuiRoutedEvent* UNoesisGuiEventTrigger::GetRoutedEvent()
{
	Noesis::Gui::EventTrigger* NoesisEventTrigger = NsDynamicCast<Noesis::Gui::EventTrigger*>(NoesisComponent.GetPtr());
	check(NoesisEventTrigger);
	return CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(NoesisEventTrigger->GetRoutedEvent()));
}

void UNoesisGuiEventTrigger::SetRoutedEvent(class UNoesisGuiRoutedEvent* InRoutedEvent)
{
	Noesis::Gui::EventTrigger* NoesisEventTrigger = NsDynamicCast<Noesis::Gui::EventTrigger*>(NoesisComponent.GetPtr());
	check(NoesisEventTrigger);
	NoesisEventTrigger->SetRoutedEvent(NsDynamicCast<const RoutedEvent*>(InRoutedEvent->NoesisComponent.GetPtr()));
}

FString UNoesisGuiEventTrigger::GetSourceName()
{
	Noesis::Gui::EventTrigger* NoesisEventTrigger = NsDynamicCast<Noesis::Gui::EventTrigger*>(NoesisComponent.GetPtr());
	check(NoesisEventTrigger);
	return NsStringToFString(NoesisEventTrigger->GetSourceName());
}

void UNoesisGuiEventTrigger::SetSourceName(FString InSourceName)
{
	Noesis::Gui::EventTrigger* NoesisEventTrigger = NsDynamicCast<Noesis::Gui::EventTrigger*>(NoesisComponent.GetPtr());
	check(NoesisEventTrigger);
	NoesisEventTrigger->SetSourceName(StringCast<NsChar>(*InSourceName).Get());
}

void UNoesisGuiEventTrigger::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::EventTrigger* NoesisEventTrigger = NsDynamicCast<Noesis::Gui::EventTrigger*>(NoesisComponent.GetPtr());
	check(NoesisEventTrigger)


}

void UNoesisGuiEventTrigger::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::EventTrigger* NoesisEventTrigger = NsDynamicCast<Noesis::Gui::EventTrigger*>(NoesisComponent.GetPtr());
	check(NoesisEventTrigger)


}

