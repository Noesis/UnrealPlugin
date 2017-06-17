////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisTriggerActionCollection.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisTriggerActionCollection::UNoesisTriggerActionCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TypedCollection<Noesis::Gui::TriggerAction>::StaticGetClassType();
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
	check(NoesisTriggerActionCollection);


}

void UNoesisTriggerActionCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::TriggerAction>* NoesisTriggerActionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::TriggerAction>*>(NoesisComponent.GetPtr());
	check(NoesisTriggerActionCollection);


}

