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

	Completed_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiClock::Completed_Private);
	NoesisClock->Completed() += Completed_Delegate;
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

ENoesisGuiClockState UNoesisGuiClock::GetCurrentState()
{
	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	check(NoesisClock);
	return (ENoesisGuiClockState)NoesisClock->GetCurrentState();
}

bool UNoesisGuiClock::HasControllableRoot()
{
	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	check(NoesisClock);
	return NoesisClock->HasControllableRoot();
}

	void UNoesisGuiClock::Completed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::EventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiEventArgs Args(Instance, InArgs);
	Completed.Broadcast(Sender, Args);
}

	void UNoesisGuiClock::BeginDestroy()
{
	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	if (!NoesisClock)
		return Super::BeginDestroy();

	NoesisClock->Completed() -= Completed_Delegate;

	Super::BeginDestroy();
}

#pragma pop_macro("GetCurrentTime")

