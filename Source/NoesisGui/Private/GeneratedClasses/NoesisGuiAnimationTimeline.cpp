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

class UNoesisGuiAnimationTimeline* UNoesisGuiAnimationTimeline::CreateTransitionFrom()
{
	Noesis::Gui::AnimationTimeline* NoesisAnimationTimeline = NsDynamicCast<Noesis::Gui::AnimationTimeline*>(NoesisComponent.GetPtr());
	check(NoesisAnimationTimeline);
	return CastChecked<UNoesisGuiAnimationTimeline>(Instance->FindUnrealComponentForNoesisComponent(NoesisAnimationTimeline->CreateTransitionFrom()));
}

class UNoesisGuiBaseComponent* UNoesisGuiAnimationTimeline::GetAnimatedValue(class UNoesisGuiBaseComponent* InDefaultOrigin, class UNoesisGuiBaseComponent* InDefaultDestination, class UNoesisGuiAnimationClock* InClock)
{
	Noesis::Gui::AnimationTimeline* NoesisAnimationTimeline = NsDynamicCast<Noesis::Gui::AnimationTimeline*>(NoesisComponent.GetPtr());
	check(NoesisAnimationTimeline);
	BaseComponent* NoesisInDefaultOrigin = NsDynamicCast<BaseComponent*>(InDefaultOrigin->NoesisComponent.GetPtr());
	BaseComponent* NoesisInDefaultDestination = NsDynamicCast<BaseComponent*>(InDefaultDestination->NoesisComponent.GetPtr());
	AnimationClock* NoesisInClock = NsDynamicCast<AnimationClock*>(InClock->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisAnimationTimeline->GetAnimatedValue(NoesisInDefaultOrigin, NoesisInDefaultDestination, NoesisInClock)));
}

void UNoesisGuiAnimationTimeline::Start(class UNoesisGuiDependencyObject* InTarget, const class UNoesisGuiDependencyProperty* InDp, class UNoesisGuiITimeManager* InTimeManager, ENoesisGuiHandoffBehavior InHandoff)
{
	Noesis::Gui::AnimationTimeline* NoesisAnimationTimeline = NsDynamicCast<Noesis::Gui::AnimationTimeline*>(NoesisComponent.GetPtr());
	check(NoesisAnimationTimeline);
	DependencyObject* NoesisInTarget = NsDynamicCast<DependencyObject*>(InTarget->NoesisComponent.GetPtr());
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	ITimeManager* NoesisInTimeManager = NsDynamicCast<ITimeManager*>(InTimeManager->NoesisInterface.GetPtr());
	HandoffBehavior NoesisInHandoff = (HandoffBehavior)InHandoff;
	return NoesisAnimationTimeline->Start(NoesisInTarget, NoesisInDp, NoesisInTimeManager, NoesisInHandoff);
}

void UNoesisGuiAnimationTimeline::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::AnimationTimeline* NoesisAnimationTimeline = NsDynamicCast<Noesis::Gui::AnimationTimeline*>(NoesisComponent.GetPtr());
	check(NoesisAnimationTimeline)


}

void UNoesisGuiAnimationTimeline::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::AnimationTimeline* NoesisAnimationTimeline = NsDynamicCast<Noesis::Gui::AnimationTimeline*>(NoesisComponent.GetPtr());
	check(NoesisAnimationTimeline)


}

