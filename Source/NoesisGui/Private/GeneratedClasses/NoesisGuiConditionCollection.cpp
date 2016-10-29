////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiConditionCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiConditionCollection::UNoesisGuiConditionCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiConditionCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::Condition>* NoesisConditionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::Condition>*>(InNoesisComponent);
	check(NoesisConditionCollection);
}

void UNoesisGuiConditionCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::Condition>* NoesisConditionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::Condition>*>(NoesisComponent.GetPtr());
	check(NoesisConditionCollection)


}

void UNoesisGuiConditionCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::Condition>* NoesisConditionCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::Condition>*>(NoesisComponent.GetPtr());
	check(NoesisConditionCollection)


}

