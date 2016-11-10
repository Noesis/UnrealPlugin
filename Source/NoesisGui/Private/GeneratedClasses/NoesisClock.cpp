////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma push_macro("GetCurrentTime")
#undef GetCurrentTime

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisClock.h"

using namespace Noesis;
using namespace Gui;

UNoesisClock::UNoesisClock(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisClock::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(InNoesisComponent);
	check(NoesisClock);
}

int32 UNoesisClock::GetCurrentIteration()
{
	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	check(NoesisClock);
	return NoesisClock->GetCurrentIteration();
}

float UNoesisClock::GetCurrentProgress()
{
	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	check(NoesisClock);
	return (float)NoesisClock->GetCurrentProgress();
}

float UNoesisClock::GetCurrentTime()
{
	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	check(NoesisClock);
	return (float)NoesisClock->GetCurrentTime();
}

class UNoesisClockGroup* UNoesisClock::GetParent()
{
	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	check(NoesisClock);
	return CastChecked<UNoesisClockGroup>(Instance->FindUnrealComponentForNoesisComponent(NoesisClock->GetParent()));
}

class UNoesisTimeline* UNoesisClock::GetTimeline()
{
	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	check(NoesisClock);
	return CastChecked<UNoesisTimeline>(Instance->FindUnrealComponentForNoesisComponent(NoesisClock->GetTimeline()));
}

ENoesisClockState UNoesisClock::GetCurrentState()
{
	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	check(NoesisClock);
	return (ENoesisClockState)NoesisClock->GetCurrentState();
}

bool UNoesisClock::HasControllableRoot()
{
	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	check(NoesisClock);
	return NoesisClock->HasControllableRoot();
}

void UNoesisClock::Completed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::EventArgs& InArgs)
{
	if (!Completed.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisEventArgs Args(Instance, InArgs);
	Completed.Broadcast(Sender, Args);
}

void UNoesisClock::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Clock* NoesisClock = NsDynamicCast<Noesis::Gui::Clock*>(NoesisComponent.GetPtr());
	check(NoesisClock)

	Completed_Delegate = Noesis::MakeDelegate(this, &UNoesisClock::Completed_Private);
	if (Completed.IsBound())
	{
		NoesisClock->Completed() += Completed_Delegate;
	}

}

void UNoesisClock::UnbindEvents()
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

