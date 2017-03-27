////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisVisualStateCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisVisualStateCollection::UNoesisVisualStateCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TypedCollection<Noesis::Gui::VisualState>::StaticGetClassType();
}

void UNoesisVisualStateCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::VisualState>* NoesisVisualStateCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::VisualState>*>(InNoesisComponent);
	check(NoesisVisualStateCollection);
}

void UNoesisVisualStateCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::VisualState>* NoesisVisualStateCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::VisualState>*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateCollection);


}

void UNoesisVisualStateCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedCollection<Noesis::Gui::VisualState>* NoesisVisualStateCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::VisualState>*>(NoesisComponent.GetPtr());
	check(NoesisVisualStateCollection);


}

