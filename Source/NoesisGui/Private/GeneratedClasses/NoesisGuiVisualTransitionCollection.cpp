////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiVisualTransitionCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiVisualTransitionCollection::UNoesisGuiVisualTransitionCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiVisualTransitionCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::VisualTransition>* NoesisVisualTransitionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::VisualTransition>*>(InNoesisComponent);
	check(NoesisVisualTransitionCollection);

}

	void UNoesisGuiVisualTransitionCollection::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::TypedCollection<Noesis::Gui::VisualTransition>* NoesisVisualTransitionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::VisualTransition>*>(NoesisComponent.GetPtr());
	if (!NoesisVisualTransitionCollection)
		return;

}

