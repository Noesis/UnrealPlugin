////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisBaseSetterCollection.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisBaseSetterCollection::UNoesisBaseSetterCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TypedCollection<Noesis::Gui::BaseSetter>::StaticGetClassType();
}

void UNoesisBaseSetterCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::BaseSetter>* NoesisBaseSetterCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::BaseSetter>*>(InNoesisComponent);
	check(NoesisBaseSetterCollection);
}

void UNoesisBaseSetterCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::BaseSetter>* NoesisBaseSetterCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::BaseSetter>*>(NoesisComponent.GetPtr());
	check(NoesisBaseSetterCollection);


}

void UNoesisBaseSetterCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::BaseSetter>* NoesisBaseSetterCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::BaseSetter>*>(NoesisComponent.GetPtr());
	check(NoesisBaseSetterCollection);


}

