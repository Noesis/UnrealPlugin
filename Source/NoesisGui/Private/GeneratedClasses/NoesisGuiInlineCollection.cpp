////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiInlineCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiInlineCollection::UNoesisGuiInlineCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiInlineCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::Inline>* NoesisInlineCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::Inline>*>(InNoesisComponent);
	check(NoesisInlineCollection);
}

void UNoesisGuiInlineCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::Inline>* NoesisInlineCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::Inline>*>(NoesisComponent.GetPtr());
	check(NoesisInlineCollection)


}

void UNoesisGuiInlineCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::Inline>* NoesisInlineCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::Inline>*>(NoesisComponent.GetPtr());
	check(NoesisInlineCollection)


}

