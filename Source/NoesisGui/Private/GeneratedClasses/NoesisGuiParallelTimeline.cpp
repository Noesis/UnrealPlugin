////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiParallelTimeline.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiParallelTimeline::UNoesisGuiParallelTimeline(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiParallelTimeline::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ParallelTimeline* NoesisParallelTimeline = NsDynamicCast<Noesis::Gui::ParallelTimeline*>(InNoesisComponent);
	check(NoesisParallelTimeline);
}

FNoesisGuiDuration UNoesisGuiParallelTimeline::GetNaturalDuration(class UNoesisGuiClock* InClock)
{
	Noesis::Gui::ParallelTimeline* NoesisParallelTimeline = NsDynamicCast<Noesis::Gui::ParallelTimeline*>(NoesisComponent.GetPtr());
	check(NoesisParallelTimeline);
	Clock* NoesisInClock = NsDynamicCast<Clock*>(InClock->NoesisComponent.GetPtr());
	return FNoesisGuiDuration(NoesisParallelTimeline->GetNaturalDuration(NoesisInClock));
}

void UNoesisGuiParallelTimeline::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ParallelTimeline* NoesisParallelTimeline = NsDynamicCast<Noesis::Gui::ParallelTimeline*>(NoesisComponent.GetPtr());
	check(NoesisParallelTimeline)


}

void UNoesisGuiParallelTimeline::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ParallelTimeline* NoesisParallelTimeline = NsDynamicCast<Noesis::Gui::ParallelTimeline*>(NoesisComponent.GetPtr());
	check(NoesisParallelTimeline)


}

