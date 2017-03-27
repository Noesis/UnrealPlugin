////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisColumnDefinitionCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisColumnDefinitionCollection::UNoesisColumnDefinitionCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TypedCollection<Noesis::Gui::ColumnDefinition>::StaticGetClassType();
}

void UNoesisColumnDefinitionCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::ColumnDefinition>* NoesisColumnDefinitionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::ColumnDefinition>*>(InNoesisComponent);
	check(NoesisColumnDefinitionCollection);
}

void UNoesisColumnDefinitionCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::ColumnDefinition>* NoesisColumnDefinitionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::ColumnDefinition>*>(NoesisComponent.GetPtr());
	check(NoesisColumnDefinitionCollection);


}

void UNoesisColumnDefinitionCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::ColumnDefinition>* NoesisColumnDefinitionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::ColumnDefinition>*>(NoesisComponent.GetPtr());
	check(NoesisColumnDefinitionCollection);


}

