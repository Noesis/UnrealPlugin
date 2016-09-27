////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma push_macro("GetCurrentTime")
#undef GetCurrentTime

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiClock.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiClock::UNoesisGuiClock(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiClock::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(InNoesisComponent);
	check(NoesisClock);

}

int32 UNoesisGuiClock::GetCurrentIteration()
{
	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	check(NoesisClock);
	return NoesisClock->GetCurrentIteration();
}

float UNoesisGuiClock::GetCurrentProgress()
{
	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	check(NoesisClock);
	return (float)NoesisClock->GetCurrentProgress();
}

float UNoesisGuiClock::GetCurrentTime()
{
	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	check(NoesisClock);
	return (float)NoesisClock->GetCurrentTime();
}

class UNoesisGuiClockGroup* UNoesisGuiClock::GetParent()
{
	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	check(NoesisClock);
	return CastChecked<UNoesisGuiClockGroup>(Instance->FindUnrealComponentForNoesisComponent(NoesisClock->GetParent()));
}

class UNoesisGuiTimeline* UNoesisGuiClock::GetTimeline()
{
	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	check(NoesisClock);
	return CastChecked<UNoesisGuiTimeline>(Instance->FindUnrealComponentForNoesisComponent(NoesisClock->GetTimeline()));
}

	void UNoesisGuiClock::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	if (!NoesisClock)
		return;

}

#pragma pop_macro("GetCurrentTime")

