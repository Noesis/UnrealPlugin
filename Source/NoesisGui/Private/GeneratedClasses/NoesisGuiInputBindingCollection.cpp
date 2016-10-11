////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiInputBindingCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiInputBindingCollection::UNoesisGuiInputBindingCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiInputBindingCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::InputBinding>* NoesisInputBindingCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::InputBinding>*>(InNoesisComponent);
	check(NoesisInputBindingCollection);

}

	void UNoesisGuiInputBindingCollection::BeginDestroy()
{
	Noesis::Gui::TypedCollection<Noesis::Gui::InputBinding>* NoesisInputBindingCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::InputBinding>*>(NoesisComponent.GetPtr());
	if (!NoesisInputBindingCollection)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

