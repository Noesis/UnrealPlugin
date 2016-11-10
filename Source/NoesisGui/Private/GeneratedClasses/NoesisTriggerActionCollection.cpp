////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisTriggerActionCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisTriggerActionCollection::UNoesisTriggerActionCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisTriggerActionCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::TriggerAction>* NoesisTriggerActionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::TriggerAction>*>(InNoesisComponent);
	check(NoesisTriggerActionCollection);
}

void UNoesisTriggerActionCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::TriggerAction>* NoesisTriggerActionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::TriggerAction>*>(NoesisComponent.GetPtr());
	check(NoesisTriggerActionCollection)


}

void UNoesisTriggerActionCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::TriggerAction>* NoesisTriggerActionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::TriggerAction>*>(NoesisComponent.GetPtr());
	check(NoesisTriggerActionCollection)


}

