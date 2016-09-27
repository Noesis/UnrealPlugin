////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiCollection::UNoesisGuiCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Collection* NoesisCollection = NsDynamicCast<Noesis::Gui::Collection*>(InNoesisComponent);
	check(NoesisCollection);

}

	void UNoesisGuiCollection::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Collection* NoesisCollection = NsDynamicCast<Noesis::Gui::Collection*>(NoesisComponent.GetPtr());
	if (!NoesisCollection)
		return;

}

