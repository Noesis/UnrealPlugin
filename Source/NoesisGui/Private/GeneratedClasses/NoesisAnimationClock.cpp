////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisAnimationClock.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisAnimationClock::UNoesisAnimationClock(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::AnimationClock::StaticGetClassType();
}

void UNoesisAnimationClock::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AnimationClock* NoesisAnimationClock = NsDynamicCast<Noesis::Gui::AnimationClock*>(InNoesisComponent);
	check(NoesisAnimationClock);
}

void UNoesisAnimationClock::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::AnimationClock* NoesisAnimationClock = NsDynamicCast<Noesis::Gui::AnimationClock*>(NoesisComponent.GetPtr());
	check(NoesisAnimationClock);


}

void UNoesisAnimationClock::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::AnimationClock* NoesisAnimationClock = NsDynamicCast<Noesis::Gui::AnimationClock*>(NoesisComponent.GetPtr());
	check(NoesisAnimationClock);


}

