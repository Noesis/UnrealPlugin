////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisVisualTransitionCollection.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisVisualTransitionCollection::UNoesisVisualTransitionCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TypedCollection<Noesis::Gui::VisualTransition>::StaticGetClassType();
}

void UNoesisVisualTransitionCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::VisualTransition>* NoesisVisualTransitionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::VisualTransition>*>(InNoesisComponent);
	check(NoesisVisualTransitionCollection);
}

void UNoesisVisualTransitionCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::VisualTransition>* NoesisVisualTransitionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::VisualTransition>*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransitionCollection);


}

void UNoesisVisualTransitionCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::VisualTransition>* NoesisVisualTransitionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::VisualTransition>*>(NoesisComponent.GetPtr());
	check(NoesisVisualTransitionCollection);


}

