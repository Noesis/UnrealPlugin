////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiGridViewColumnCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiGridViewColumnCollection::UNoesisGuiGridViewColumnCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiGridViewColumnCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::GridViewColumn>* NoesisGridViewColumnCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::GridViewColumn>*>(InNoesisComponent);
	check(NoesisGridViewColumnCollection);

}

	void UNoesisGuiGridViewColumnCollection::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::TypedCollection<Noesis::Gui::GridViewColumn>* NoesisGridViewColumnCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::GridViewColumn>*>(NoesisComponent.GetPtr());
	if (!NoesisGridViewColumnCollection)
		return;

}

