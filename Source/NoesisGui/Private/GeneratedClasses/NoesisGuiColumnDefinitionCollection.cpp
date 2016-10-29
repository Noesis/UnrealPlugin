////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiColumnDefinitionCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiColumnDefinitionCollection::UNoesisGuiColumnDefinitionCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiColumnDefinitionCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::ColumnDefinition>* NoesisColumnDefinitionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::ColumnDefinition>*>(InNoesisComponent);
	check(NoesisColumnDefinitionCollection);
}

void UNoesisGuiColumnDefinitionCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::ColumnDefinition>* NoesisColumnDefinitionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::ColumnDefinition>*>(NoesisComponent.GetPtr());
	check(NoesisColumnDefinitionCollection)


}

void UNoesisGuiColumnDefinitionCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::ColumnDefinition>* NoesisColumnDefinitionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::ColumnDefinition>*>(NoesisComponent.GetPtr());
	check(NoesisColumnDefinitionCollection)


}

