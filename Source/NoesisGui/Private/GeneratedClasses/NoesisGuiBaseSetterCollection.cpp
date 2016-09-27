////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseSetterCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseSetterCollection::UNoesisGuiBaseSetterCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseSetterCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::BaseSetter>* NoesisBaseSetterCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::BaseSetter>*>(InNoesisComponent);
	check(NoesisBaseSetterCollection);

}

	void UNoesisGuiBaseSetterCollection::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::TypedCollection<Noesis::Gui::BaseSetter>* NoesisBaseSetterCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::BaseSetter>*>(NoesisComponent.GetPtr());
	if (!NoesisBaseSetterCollection)
		return;

}

