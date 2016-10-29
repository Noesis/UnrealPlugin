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

void UNoesisGuiClockGroup::Add(class UNoesisGuiClock* InClock)
{
	Noesis::Gui::ClockGroup* NoesisClockGroup = NsDynamicCast<Noesis::Gui::ClockGroup*>(NoesisComponent.GetPtr());
	check(NoesisClockGroup);
	Clock* NoesisInClock = NsDynamicCast<Clock*>(InClock->NoesisComponent.GetPtr());
	return NoesisClockGroup->Add(NoesisInClock);
}

class UNoesisGuiClock* UNoesisGuiClockGroup::GetChild(int32 InIndex)
{
	Noesis::Gui::ClockGroup* NoesisClockGroup = NsDynamicCast<Noesis::Gui::ClockGroup*>(NoesisComponent.GetPtr());
	check(NoesisClockGroup);
	NsSize NoesisInIndex = InIndex;
	return CastChecked<UNoesisGuiClock>(Instance->FindUnrealComponentForNoesisComponent(NoesisClockGroup->GetChild(NoesisInIndex)));
}

int32 UNoesisGuiClockGroup::GetChildrenCount()
{
	Noesis::Gui::ClockGroup* NoesisClockGroup = NsDynamicCast<Noesis::Gui::ClockGroup*>(NoesisComponent.GetPtr());
	check(NoesisClockGroup);
	return (int32)NoesisClockGroup->GetChildrenCount();
}

void UNoesisGuiClockGroup::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ClockGroup* NoesisClockGroup = NsDynamicCast<Noesis::Gui::ClockGroup*>(NoesisComponent.GetPtr());
	check(NoesisClockGroup)


}

void UNoesisGuiClockGroup::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ClockGroup* NoesisClockGroup = NsDynamicCast<Noesis::Gui::ClockGroup*>(NoesisComponent.GetPtr());
	check(NoesisClockGroup)


}

