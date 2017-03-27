////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisGridViewColumnCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGridViewColumnCollection::UNoesisGridViewColumnCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TypedCollection<Noesis::Gui::GridViewColumn>::StaticGetClassType();
}

void UNoesisGridViewColumnCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::GridViewColumn>* NoesisGridViewColumnCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::GridViewColumn>*>(InNoesisComponent);
	check(NoesisGridViewColumnCollection);
}

void UNoesisGridViewColumnCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::GridViewColumn>* NoesisGridViewColumnCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::GridViewColumn>*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumnCollection);


}

void UNoesisGridViewColumnCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::GridViewColumn>* NoesisGridViewColumnCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::GridViewColumn>*>(NoesisComponent.GetPtr());
	check(NoesisGridViewColumnCollection);


}

