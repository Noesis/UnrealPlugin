////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisClockGroup.h"

using namespace Noesis;
using namespace Gui;

UNoesisClockGroup::UNoesisClockGroup(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ClockGroup::StaticGetClassType();
}

void UNoesisClockGroup::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ClockGroup* NoesisClockGroup = NsDynamicCast<Noesis::Gui::ClockGroup*>(InNoesisComponent);
	check(NoesisClockGroup);
}

void UNoesisClockGroup::Add(class UNoesisClock* InClock)
{
	Noesis::Gui::ClockGroup* NoesisClockGroup = NsDynamicCast<Noesis::Gui::ClockGroup*>(NoesisComponent.GetPtr());
	check(NoesisClockGroup);
	Clock* NoesisInClock = NsDynamicCast<Clock*>(InClock->NoesisComponent.GetPtr());
	return NoesisClockGroup->Add(NoesisInClock);
}

class UNoesisClock* UNoesisClockGroup::GetChild(int32 InIndex)
{
	Noesis::Gui::ClockGroup* NoesisClockGroup = NsDynamicCast<Noesis::Gui::ClockGroup*>(NoesisComponent.GetPtr());
	check(NoesisClockGroup);
	NsSize NoesisInIndex = (NsSize)InIndex;
	return CastChecked<UNoesisClock>(CreateClassFor(NoesisClockGroup->GetChild(NoesisInIndex), nullptr), ECastCheckedType::NullAllowed);
}

int32 UNoesisClockGroup::GetChildrenCount()
{
	Noesis::Gui::ClockGroup* NoesisClockGroup = NsDynamicCast<Noesis::Gui::ClockGroup*>(NoesisComponent.GetPtr());
	check(NoesisClockGroup);
	return (int32)NoesisClockGroup->GetChildrenCount();
}

void UNoesisClockGroup::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ClockGroup* NoesisClockGroup = NsDynamicCast<Noesis::Gui::ClockGroup*>(NoesisComponent.GetPtr());
	check(NoesisClockGroup);


}

void UNoesisClockGroup::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ClockGroup* NoesisClockGroup = NsDynamicCast<Noesis::Gui::ClockGroup*>(NoesisComponent.GetPtr());
	check(NoesisClockGroup);


}

