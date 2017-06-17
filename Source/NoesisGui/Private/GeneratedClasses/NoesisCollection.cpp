////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisCollection.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisCollection::UNoesisCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Collection::StaticGetClassType();
}

void UNoesisCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Collection* NoesisCollection = NsDynamicCast<Noesis::Gui::Collection*>(InNoesisComponent);
	check(NoesisCollection);
}

void UNoesisCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Collection* NoesisCollection = NsDynamicCast<Noesis::Gui::Collection*>(NoesisComponent.GetPtr());
	check(NoesisCollection);


}

void UNoesisCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Collection* NoesisCollection = NsDynamicCast<Noesis::Gui::Collection*>(NoesisComponent.GetPtr());
	check(NoesisCollection);


}

