////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisRoutedEvent.h"

using namespace Noesis;
using namespace Gui;

UNoesisRoutedEvent::UNoesisRoutedEvent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisRoutedEvent::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RoutedEvent* NoesisRoutedEvent = NsDynamicCast<Noesis::Gui::RoutedEvent*>(InNoesisComponent);
	check(NoesisRoutedEvent);
}

FName UNoesisRoutedEvent::GetName()
{
	Noesis::Gui::RoutedEvent* NoesisRoutedEvent = NsDynamicCast<Noesis::Gui::RoutedEvent*>(NoesisComponent.GetPtr());
	check(NoesisRoutedEvent);
	return FName(NoesisRoutedEvent->GetName().GetStr());
}

ENoesisRoutingStrategy UNoesisRoutedEvent::GetRoutingStrategy()
{
	Noesis::Gui::RoutedEvent* NoesisRoutedEvent = NsDynamicCast<Noesis::Gui::RoutedEvent*>(NoesisComponent.GetPtr());
	check(NoesisRoutedEvent);
	return (ENoesisRoutingStrategy)NoesisRoutedEvent->GetRoutingStrategy();
}

void UNoesisRoutedEvent::SetRoutingStrategy(ENoesisRoutingStrategy InRoutingStrategy)
{
	Noesis::Gui::RoutedEvent* NoesisRoutedEvent = NsDynamicCast<Noesis::Gui::RoutedEvent*>(NoesisComponent.GetPtr());
	check(NoesisRoutedEvent);
	NoesisRoutedEvent->SetRoutingStrategy((Noesis::Gui::RoutingStrategy)InRoutingStrategy);
}

void UNoesisRoutedEvent::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::RoutedEvent* NoesisRoutedEvent = NsDynamicCast<Noesis::Gui::RoutedEvent*>(NoesisComponent.GetPtr());
	check(NoesisRoutedEvent)


}

void UNoesisRoutedEvent::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::RoutedEvent* NoesisRoutedEvent = NsDynamicCast<Noesis::Gui::RoutedEvent*>(NoesisComponent.GetPtr());
	check(NoesisRoutedEvent)


}

