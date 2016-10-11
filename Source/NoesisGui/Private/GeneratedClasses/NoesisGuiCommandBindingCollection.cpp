////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiCommandBindingCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiCommandBindingCollection::UNoesisGuiCommandBindingCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiCommandBindingCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::CommandBinding>* NoesisCommandBindingCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::CommandBinding>*>(InNoesisComponent);
	check(NoesisCommandBindingCollection);

}

	void UNoesisGuiCommandBindingCollection::BeginDestroy()
{
	Noesis::Gui::TypedCollection<Noesis::Gui::CommandBinding>* NoesisCommandBindingCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::CommandBinding>*>(NoesisComponent.GetPtr());
	if (!NoesisCommandBindingCollection)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

