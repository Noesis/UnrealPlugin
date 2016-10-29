////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiRowDefinitionCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiRowDefinitionCollection::UNoesisGuiRowDefinitionCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiRowDefinitionCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::RowDefinition>* NoesisRowDefinitionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::RowDefinition>*>(InNoesisComponent);
	check(NoesisRowDefinitionCollection);
}

void UNoesisGuiRowDefinitionCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::RowDefinition>* NoesisRowDefinitionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::RowDefinition>*>(NoesisComponent.GetPtr());
	check(NoesisRowDefinitionCollection)


}

void UNoesisGuiRowDefinitionCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::RowDefinition>* NoesisRowDefinitionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::RowDefinition>*>(NoesisComponent.GetPtr());
	check(NoesisRowDefinitionCollection)


}

