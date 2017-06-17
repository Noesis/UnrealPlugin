////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisRowDefinitionCollection.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisRowDefinitionCollection::UNoesisRowDefinitionCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TypedCollection<Noesis::Gui::RowDefinition>::StaticGetClassType();
}

void UNoesisRowDefinitionCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::RowDefinition>* NoesisRowDefinitionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::RowDefinition>*>(InNoesisComponent);
	check(NoesisRowDefinitionCollection);
}

void UNoesisRowDefinitionCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::RowDefinition>* NoesisRowDefinitionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::RowDefinition>*>(NoesisComponent.GetPtr());
	check(NoesisRowDefinitionCollection);


}

void UNoesisRowDefinitionCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::RowDefinition>* NoesisRowDefinitionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::RowDefinition>*>(NoesisComponent.GetPtr());
	check(NoesisRowDefinitionCollection);


}

