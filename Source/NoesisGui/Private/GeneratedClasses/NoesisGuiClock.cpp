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
	if (!Completed.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiEventArgs Args(Instance, InArgs);
	Completed.Broadcast(Sender, Args);
}

void UNoesisGuiClock::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	check(NoesisClock)

	Completed_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiClock::Completed_Private);
	if (Completed.IsBound())
	{
		NoesisClock->Completed() += Completed_Delegate;
	}

}

void UNoesisGuiClock::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	check(NoesisClock)

	if (Completed.IsBound())
	{
		NoesisClock->Completed() -= Completed_Delegate;
	}

}

#pragma pop_macro("GetCurrentTime")

