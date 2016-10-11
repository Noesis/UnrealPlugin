////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTriggerActionCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTriggerActionCollection::UNoesisGuiTriggerActionCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTriggerActionCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::TriggerAction>* NoesisTriggerActionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::TriggerAction>*>(InNoesisComponent);
	check(NoesisTriggerActionCollection);

}

	void UNoesisGuiTriggerActionCollection::BeginDestroy()
{
	Noesis::Gui::TypedCollection<Noesis::Gui::TriggerAction>* NoesisTriggerActionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::TriggerAction>*>(NoesisComponent.GetPtr());
	if (!NoesisTriggerActionCollection)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

