////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisTimelineCollection.h"

using namespace Noesis;
using namespace Gui;

UNoesisTimelineCollection::UNoesisTimelineCollection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisTimelineCollection::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::Timeline>* NoesisTimelineCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::Timeline>*>(InNoesisComponent);
	check(NoesisTimelineCollection);
}

void UNoesisTimelineCollection::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::Timeline>* NoesisTimelineCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::Timeline>*>(NoesisComponent.GetPtr());
	check(NoesisTimelineCollection)


}

void UNoesisTimelineCollection::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TypedFreezableCollection<Noesis::Gui::Timeline>* NoesisTimelineCollection = NsDynamicCast<Noesis::Gui::TypedFreezableCollection<Noesis::Gui::Timeline>*>(NoesisComponent.GetPtr());
	check(NoesisTimelineCollection)


}

