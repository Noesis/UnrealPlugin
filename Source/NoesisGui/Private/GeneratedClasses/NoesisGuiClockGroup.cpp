////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiClockGroup.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiClockGroup::UNoesisGuiClockGroup(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiClockGroup::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ClockGroup* NoesisClockGroup = NsDynamicCast<Noesis::Gui::ClockGroup*>(InNoesisComponent);
	check(NoesisClockGroup);

}

	void UNoesisGuiClockGroup::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::ClockGroup* NoesisClockGroup = NsDynamicCast<Noesis::Gui::ClockGroup*>(NoesisComponent.GetPtr());
	if (!NoesisClockGroup)
		return;

}

