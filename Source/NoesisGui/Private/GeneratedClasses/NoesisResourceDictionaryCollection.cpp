////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisResourceDictionaryCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisResourceDictionaryCollection::UNoesisResourceDictionaryCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisResourceDictionaryCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::ResourceDictionary>* NoesisResourceDictionaryCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::ResourceDictionary>*>(InNoesisComponent);
	check(NoesisResourceDictionaryCollection);
}

void UNoesisResourceDictionaryCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::ResourceDictionary>* NoesisResourceDictionaryCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::ResourceDictionary>*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionaryCollection)


}

void UNoesisResourceDictionaryCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::ResourceDictionary>* NoesisResourceDictionaryCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::ResourceDictionary>*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionaryCollection)


}

