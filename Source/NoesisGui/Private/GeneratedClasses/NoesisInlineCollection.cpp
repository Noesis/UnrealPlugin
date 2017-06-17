////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisInlineCollection.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisInlineCollection::UNoesisInlineCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TypedCollection<Noesis::Gui::Inline>::StaticGetClassType();
}

void UNoesisInlineCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::Inline>* NoesisInlineCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::Inline>*>(InNoesisComponent);
	check(NoesisInlineCollection);
}

void UNoesisInlineCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::Inline>* NoesisInlineCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::Inline>*>(NoesisComponent.GetPtr());
	check(NoesisInlineCollection);


}

void UNoesisInlineCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::Inline>* NoesisInlineCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::Inline>*>(NoesisComponent.GetPtr());
	check(NoesisInlineCollection);


}

