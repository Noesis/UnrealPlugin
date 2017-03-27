////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisCommandBindingCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisCommandBindingCollection::UNoesisCommandBindingCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TypedCollection<Noesis::Gui::CommandBinding>::StaticGetClassType();
}

void UNoesisCommandBindingCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::CommandBinding>* NoesisCommandBindingCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::CommandBinding>*>(InNoesisComponent);
	check(NoesisCommandBindingCollection);
}

void UNoesisCommandBindingCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::CommandBinding>* NoesisCommandBindingCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::CommandBinding>*>(NoesisComponent.GetPtr());
	check(NoesisCommandBindingCollection);


}

void UNoesisCommandBindingCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::CommandBinding>* NoesisCommandBindingCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::CommandBinding>*>(NoesisComponent.GetPtr());
	check(NoesisCommandBindingCollection);


}

