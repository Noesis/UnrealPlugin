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

	void UNoesisGuiParallelTimeline::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::ParallelTimeline* NoesisParallelTimeline = NsDynamicCast<Noesis::Gui::ParallelTimeline*>(NoesisComponent.GetPtr());
	if (!NoesisParallelTimeline)
		return;

}

