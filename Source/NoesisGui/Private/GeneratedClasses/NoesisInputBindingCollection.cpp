////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisInputBindingCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisInputBindingCollection::UNoesisInputBindingCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TypedCollection<Noesis::Gui::InputBinding>::StaticGetClassType();
}

void UNoesisInputBindingCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::InputBinding>* NoesisInputBindingCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::InputBinding>*>(InNoesisComponent);
	check(NoesisInputBindingCollection);
}

void UNoesisInputBindingCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::InputBinding>* NoesisInputBindingCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::InputBinding>*>(NoesisComponent.GetPtr());
	check(NoesisInputBindingCollection);


}

void UNoesisInputBindingCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::InputBinding>* NoesisInputBindingCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::InputBinding>*>(NoesisComponent.GetPtr());
	check(NoesisInputBindingCollection);


}

