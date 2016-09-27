////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTimelineGroup.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTimelineGroup::UNoesisGuiTimelineGroup(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTimelineGroup::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TimelineGroup* NoesisTimelineGroup = NsDynamicCast<Noesis::Gui::TimelineGroup*>(InNoesisComponent);
	check(NoesisTimelineGroup);

}

	void UNoesisGuiTimelineGroup::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::TimelineGroup* NoesisTimelineGroup = NsDynamicCast<Noesis::Gui::TimelineGroup*>(NoesisComponent.GetPtr());
	if (!NoesisTimelineGroup)
		return;

}

