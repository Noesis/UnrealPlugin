////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisInputGestureCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisInputGestureCollection::UNoesisInputGestureCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TypedCollection<Noesis::Gui::InputGesture>::StaticGetClassType();
}

void UNoesisInputGestureCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::InputGesture>* NoesisInputGestureCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::InputGesture>*>(InNoesisComponent);
	check(NoesisInputGestureCollection);
}

void UNoesisInputGestureCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::InputGesture>* NoesisInputGestureCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::InputGesture>*>(NoesisComponent.GetPtr());
	check(NoesisInputGestureCollection);


}

void UNoesisInputGestureCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::InputGesture>* NoesisInputGestureCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::InputGesture>*>(NoesisComponent.GetPtr());
	check(NoesisInputGestureCollection);


}

