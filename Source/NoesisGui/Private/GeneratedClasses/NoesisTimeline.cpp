////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisTimeline.h"

using namespace Noesis;
using namespace Gui;

UNoesisTimeline::UNoesisTimeline(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisTimeline::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(InNoesisComponent);
	check(NoesisTimeline);
}

float UNoesisTimeline::GetAccelerationRatio()
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	return (float)NoesisTimeline->GetAccelerationRatio();
}

void UNoesisTimeline::SetAccelerationRatio(float InAccelerationRatio)
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	NoesisTimeline->SetAccelerationRatio(InAccelerationRatio);
}

bool UNoesisTimeline::GetAutoReverse()
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	return NoesisTimeline->GetAutoReverse();
}

void UNoesisTimeline::SetAutoReverse(bool InAutoReverse)
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	NoesisTimeline->SetAutoReverse(InAutoReverse);
}

float UNoesisTimeline::GetDecelerationRatio()
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	return (float)NoesisTimeline->GetDecelerationRatio();
}

void UNoesisTimeline::SetDecelerationRatio(float InDecelerationRatio)
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	NoesisTimeline->SetDecelerationRatio(InDecelerationRatio);
}

FNoesisDuration UNoesisTimeline::GetDuration()
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	return FNoesisDuration(NoesisTimeline->GetDuration());
}

void UNoesisTimeline::SetDuration(FNoesisDuration InDuration)
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	NoesisTimeline->SetDuration(InDuration.ToNoesis());
}

ENoesisFillBehavior UNoesisTimeline::GetFillBehavior()
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	return (ENoesisFillBehavior)NoesisTimeline->GetFillBehavior();
}

void UNoesisTimeline::SetFillBehavior(ENoesisFillBehavior InFillBehavior)
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	NoesisTimeline->SetFillBehavior((Noesis::Gui::FillBehavior)InFillBehavior);
}

FString UNoesisTimeline::GetName()
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	return NsStringToFString(NoesisTimeline->GetName());
}

void UNoesisTimeline::SetName(FString InName)
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	NoesisTimeline->SetName(StringCast<NsChar>(*InName).Get());
}

FNoesisRepeatBehavior UNoesisTimeline::GetRepeatBehavior()
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	return FNoesisRepeatBehavior(NoesisTimeline->GetRepeatBehavior());
}

void UNoesisTimeline::SetRepeatBehavior(FNoesisRepeatBehavior InRepeatBehavior)
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	NoesisTimeline->SetRepeatBehavior(InRepeatBehavior.ToNoesis());
}

float UNoesisTimeline::GetSpeedRatio()
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	return (float)NoesisTimeline->GetSpeedRatio();
}

void UNoesisTimeline::SetSpeedRatio(float InSpeedRatio)
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	NoesisTimeline->SetSpeedRatio(InSpeedRatio);
}

void UNoesisTimeline::CalculateEffectiveDurations()
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	return NoesisTimeline->CalculateEffectiveDurations();
}

FNoesisDuration UNoesisTimeline::GetNaturalDuration(class UNoesisClock* InClock)
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	Clock* NoesisInClock = NsDynamicCast<Clock*>(InClock->NoesisComponent.GetPtr());
	return FNoesisDuration(NoesisTimeline->GetNaturalDuration(NoesisInClock));
}

void UNoesisTimeline::Completed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TimelineEventArgs& InArgs)
{
	if (!Completed.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisTimelineEventArgs Args(Instance, InArgs);
	Completed.Broadcast(Sender, Args);
}

void UNoesisTimeline::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline)

	Completed_Delegate = Noesis::MakeDelegate(this, &UNoesisTimeline::Completed_Private);
	if (Completed.IsBound())
	{
		NoesisTimeline->Completed() += Completed_Delegate;
	}

}

void UNoesisTimeline::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline)

	if (Completed.IsBound())
	{
		NoesisTimeline->Completed() -= Completed_Delegate;
	}

}

