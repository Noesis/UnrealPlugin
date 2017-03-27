////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisConditionCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisConditionCollection::UNoesisConditionCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TypedCollection<Noesis::Gui::Condition>::StaticGetClassType();
}

void UNoesisConditionCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::Condition>* NoesisConditionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::Condition>*>(InNoesisComponent);
	check(NoesisConditionCollection);
}

void UNoesisConditionCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::Condition>* NoesisConditionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::Condition>*>(NoesisComponent.GetPtr());
	check(NoesisConditionCollection);


}

void UNoesisConditionCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::Condition>* NoesisConditionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::Condition>*>(NoesisComponent.GetPtr());
	check(NoesisConditionCollection);


}

