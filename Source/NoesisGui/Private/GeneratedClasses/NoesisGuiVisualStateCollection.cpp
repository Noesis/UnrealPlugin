////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiVisualStateCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiVisualStateCollection::UNoesisGuiVisualStateCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiVisualStateCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedCollection<Noesis::Gui::VisualState>* NoesisVisualStateCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::VisualState>*>(InNoesisComponent);
	check(NoesisVisualStateCollection);

}

	void UNoesisGuiVisualStateCollection::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::TypedCollection<Noesis::Gui::VisualState>* NoesisVisualStateCollection = NsDynamicCast<Noesis::Gui::TypedCollection<Noesis::Gui::VisualState>*>(NoesisComponent.GetPtr());
	if (!NoesisVisualStateCollection)
		return;

}

