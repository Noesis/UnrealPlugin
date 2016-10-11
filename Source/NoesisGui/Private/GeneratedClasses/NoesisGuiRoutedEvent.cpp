////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiRoutedEvent.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiRoutedEvent::UNoesisGuiRoutedEvent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiRoutedEvent::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RoutedEvent* NoesisRoutedEvent = NsDynamicCast<Noesis::Gui::RoutedEvent*>(InNoesisComponent);
	check(NoesisRoutedEvent);

}

FName UNoesisGuiRoutedEvent::GetName()
{
	Noesis::Gui::RoutedEvent* NoesisRoutedEvent = NsDynamicCast<Noesis::Gui::RoutedEvent*>(NoesisComponent.GetPtr());
	check(NoesisRoutedEvent);
	return FName(NoesisRoutedEvent->GetName().GetStr());
}

ENoesisGuiRoutingStrategy UNoesisGuiRoutedEvent::GetRoutingStrategy()
{
	Noesis::Gui::RoutedEvent* NoesisRoutedEvent = NsDynamicCast<Noesis::Gui::RoutedEvent*>(NoesisComponent.GetPtr());
	check(NoesisRoutedEvent);
	return (ENoesisGuiRoutingStrategy)NoesisRoutedEvent->GetRoutingStrategy();
}

void UNoesisGuiRoutedEvent::SetRoutingStrategy(ENoesisGuiRoutingStrategy InRoutingStrategy)
{
	Noesis::Gui::RoutedEvent* NoesisRoutedEvent = NsDynamicCast<Noesis::Gui::RoutedEvent*>(NoesisComponent.GetPtr());
	check(NoesisRoutedEvent);
	NoesisRoutedEvent->SetRoutingStrategy((RoutingStrategy)InRoutingStrategy);
}

	void UNoesisGuiRoutedEvent::BeginDestroy()
{
	Noesis::Gui::RoutedEvent* NoesisRoutedEvent = NsDynamicCast<Noesis::Gui::RoutedEvent*>(NoesisComponent.GetPtr());
	if (!NoesisRoutedEvent)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

