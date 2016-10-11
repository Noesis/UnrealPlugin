////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTimeline.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTimeline::UNoesisGuiTimeline(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTimeline::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(InNoesisComponent);
	check(NoesisTimeline);

	Completed_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiTimeline::Completed_Private);
	NoesisTimeline->Completed() += Completed_Delegate;
}

void UNoesisGuiTimeline::CalculateEffectiveDurations()
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	return NoesisTimeline->CalculateEffectiveDurations();
}

FNoesisGuiDuration UNoesisGuiTimeline::GetNaturalDuration(class UNoesisGuiClock* InClock)
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	check(NoesisTimeline);
	Clock* NoesisInClock = NsDynamicCast<Clock*>(InClock->NoesisComponent.GetPtr());
	return FNoesisGuiDuration(NoesisTimeline->GetNaturalDuration(NoesisInClock));
}

	void UNoesisGuiTimeline::Completed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::TimelineEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiTimelineEventArgs Args(Instance, InArgs);
	Completed.Broadcast(Sender, Args);
}

	void UNoesisGuiTimeline::BeginDestroy()
{
	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	if (!NoesisTimeline)
		return Super::BeginDestroy();

	NoesisTimeline->Completed() -= Completed_Delegate;

	Super::BeginDestroy();
}

