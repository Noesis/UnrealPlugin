////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiAnimationTimeline.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiAnimationTimeline::UNoesisGuiAnimationTimeline(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiAnimationTimeline::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AnimationTimeline* NoesisAnimationTimeline = NsDynamicCast<Noesis::Gui::AnimationTimeline*>(InNoesisComponent);
	check(NoesisAnimationTimeline);

}

	void UNoesisGuiAnimationTimeline::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::AnimationTimeline* NoesisAnimationTimeline = NsDynamicCast<Noesis::Gui::AnimationTimeline*>(NoesisComponent.GetPtr());
	if (!NoesisAnimationTimeline)
		return;

}

