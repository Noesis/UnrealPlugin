////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiInputGestureCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiInputGestureCollection::UNoesisGuiInputGestureCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiInputGestureCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::InputGesture>* NoesisInputGestureCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::InputGesture>*>(InNoesisComponent);
	check(NoesisInputGestureCollection);

}

	void UNoesisGuiInputGestureCollection::BeginDestroy()
{
	Noesis::Gui::TypedCollection<Noesis::Gui::InputGesture>* NoesisInputGestureCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::InputGesture>*>(NoesisComponent.GetPtr());
	if (!NoesisInputGestureCollection)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

