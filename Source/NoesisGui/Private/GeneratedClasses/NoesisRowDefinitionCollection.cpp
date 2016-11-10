////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisRowDefinitionCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisRowDefinitionCollection::UNoesisRowDefinitionCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
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
	check(NoesisRowDefinitionCollection)


}

void UNoesisRowDefinitionCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::RowDefinition>* NoesisRowDefinitionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::RowDefinition>*>(NoesisComponent.GetPtr());
	check(NoesisRowDefinitionCollection)


}

