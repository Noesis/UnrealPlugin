////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiAnimationClock.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiAnimationClock::UNoesisGuiAnimationClock(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiAnimationClock::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AnimationClock* NoesisAnimationClock = NsDynamicCast<Noesis::Gui::AnimationClock*>(InNoesisComponent);
	check(NoesisAnimationClock);

}

	void UNoesisGuiAnimationClock::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::AnimationClock* NoesisAnimationClock = NsDynamicCast<Noesis::Gui::AnimationClock*>(NoesisComponent.GetPtr());
	if (!NoesisAnimationClock)
		return;

}

