////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisParallelTimeline.h"

using namespace Noesis;
using namespace Gui;

UNoesisParallelTimeline::UNoesisParallelTimeline(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ParallelTimeline::StaticGetClassType();
}

void UNoesisParallelTimeline::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ParallelTimeline* NoesisParallelTimeline = NsDynamicCast<Noesis::Gui::ParallelTimeline*>(InNoesisComponent);
	check(NoesisParallelTimeline);
}

ENoesisSlipBehavior UNoesisParallelTimeline::GetSlipBehavior()
{
	Noesis::Gui::ParallelTimeline* NoesisParallelTimeline = NsDynamicCast<Noesis::Gui::ParallelTimeline*>(NoesisComponent.GetPtr());
	check(NoesisParallelTimeline);
	return (ENoesisSlipBehavior)NoesisParallelTimeline->GetSlipBehavior();
}

void UNoesisParallelTimeline::SetSlipBehavior(ENoesisSlipBehavior InSlipBehavior)
{
	Noesis::Gui::ParallelTimeline* NoesisParallelTimeline = NsDynamicCast<Noesis::Gui::ParallelTimeline*>(NoesisComponent.GetPtr());
	check(NoesisParallelTimeline);
	NoesisParallelTimeline->SetSlipBehavior((Noesis::Gui::SlipBehavior)InSlipBehavior);
}

FNoesisDuration UNoesisParallelTimeline::GetNaturalDuration(class UNoesisClock* InClock)
{
	Noesis::Gui::ParallelTimeline* NoesisParallelTimeline = NsDynamicCast<Noesis::Gui::ParallelTimeline*>(NoesisComponent.GetPtr());
	check(NoesisParallelTimeline);
	Clock* NoesisInClock = NsDynamicCast<Clock*>(InClock->NoesisComponent.GetPtr());
	return FNoesisDuration(NoesisParallelTimeline->GetNaturalDuration(NoesisInClock));
}

void UNoesisParallelTimeline::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ParallelTimeline* NoesisParallelTimeline = NsDynamicCast<Noesis::Gui::ParallelTimeline*>(NoesisComponent.GetPtr());
	check(NoesisParallelTimeline);


}

void UNoesisParallelTimeline::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ParallelTimeline* NoesisParallelTimeline = NsDynamicCast<Noesis::Gui::ParallelTimeline*>(NoesisComponent.GetPtr());
	check(NoesisParallelTimeline);


}

