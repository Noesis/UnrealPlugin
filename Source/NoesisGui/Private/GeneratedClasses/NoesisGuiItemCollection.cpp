////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiItemCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiItemCollection::UNoesisGuiItemCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiItemCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ItemCollection* NoesisItemCollection = NsDynamicCast<Noesis::Gui::ItemCollection*>(InNoesisComponent);
	check(NoesisItemCollection);

}

	void UNoesisGuiItemCollection::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::ItemCollection* NoesisItemCollection = NsDynamicCast<Noesis::Gui::ItemCollection*>(NoesisComponent.GetPtr());
	if (!NoesisItemCollection)
		return;

}

