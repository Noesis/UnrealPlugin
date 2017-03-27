////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisAnimationTimeline.h"

using namespace Noesis;
using namespace Gui;

UNoesisAnimationTimeline::UNoesisAnimationTimeline(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::AnimationTimeline::StaticGetClassType();
}

void UNoesisAnimationTimeline::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AnimationTimeline* NoesisAnimationTimeline = NsDynamicCast<Noesis::Gui::AnimationTimeline*>(InNoesisComponent);
	check(NoesisAnimationTimeline);
}

bool UNoesisAnimationTimeline::GetIsAdditive()
{
	Noesis::Gui::AnimationTimeline* NoesisAnimationTimeline = NsDynamicCast<Noesis::Gui::AnimationTimeline*>(NoesisComponent.GetPtr());
	check(NoesisAnimationTimeline);
	return NoesisAnimationTimeline->GetIsAdditive();
}

void UNoesisAnimationTimeline::SetIsAdditive(bool InIsAdditive)
{
	Noesis::Gui::AnimationTimeline* NoesisAnimationTimeline = NsDynamicCast<Noesis::Gui::AnimationTimeline*>(NoesisComponent.GetPtr());
	check(NoesisAnimationTimeline);
	NoesisAnimationTimeline->SetIsAdditive(InIsAdditive);
}

bool UNoesisAnimationTimeline::GetIsCumulative()
{
	Noesis::Gui::AnimationTimeline* NoesisAnimationTimeline = NsDynamicCast<Noesis::Gui::AnimationTimeline*>(NoesisComponent.GetPtr());
	check(NoesisAnimationTimeline);
	return NoesisAnimationTimeline->GetIsCumulative();
}

void UNoesisAnimationTimeline::SetIsCumulative(bool InIsCumulative)
{
	Noesis::Gui::AnimationTimeline* NoesisAnimationTimeline = NsDynamicCast<Noesis::Gui::AnimationTimeline*>(NoesisComponent.GetPtr());
	check(NoesisAnimationTimeline);
	NoesisAnimationTimeline->SetIsCumulative(InIsCumulative);
}

class UNoesisAnimationTimeline* UNoesisAnimationTimeline::CreateTransitionFrom()
{
	Noesis::Gui::AnimationTimeline* NoesisAnimationTimeline = NsDynamicCast<Noesis::Gui::AnimationTimeline*>(NoesisComponent.GetPtr());
	check(NoesisAnimationTimeline);
	return CastChecked<UNoesisAnimationTimeline>(CreateClassFor(NoesisAnimationTimeline->CreateTransitionFrom(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisBaseComponent* UNoesisAnimationTimeline::GetAnimatedValue(class UNoesisBaseComponent* InDefaultOrigin, class UNoesisBaseComponent* InDefaultDestination, class UNoesisAnimationClock* InClock)
{
	Noesis::Gui::AnimationTimeline* NoesisAnimationTimeline = NsDynamicCast<Noesis::Gui::AnimationTimeline*>(NoesisComponent.GetPtr());
	check(NoesisAnimationTimeline);
	BaseComponent* NoesisInDefaultOrigin = NsDynamicCast<BaseComponent*>(InDefaultOrigin->NoesisComponent.GetPtr());
	BaseComponent* NoesisInDefaultDestination = NsDynamicCast<BaseComponent*>(InDefaultDestination->NoesisComponent.GetPtr());
	AnimationClock* NoesisInClock = NsDynamicCast<AnimationClock*>(InClock->NoesisComponent.GetPtr());
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisAnimationTimeline->GetAnimatedValue(NoesisInDefaultOrigin, NoesisInDefaultDestination, NoesisInClock), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisAnimationTimeline::Start(class UNoesisDependencyObject* InTarget, const class UNoesisDependencyProperty* InDp, class UNoesisITimeManager* InTimeManager, ENoesisHandoffBehavior InHandoff)
{
	Noesis::Gui::AnimationTimeline* NoesisAnimationTimeline = NsDynamicCast<Noesis::Gui::AnimationTimeline*>(NoesisComponent.GetPtr());
	check(NoesisAnimationTimeline);
	DependencyObject* NoesisInTarget = NsDynamicCast<DependencyObject*>(InTarget->NoesisComponent.GetPtr());
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	ITimeManager* NoesisInTimeManager = NsDynamicCast<ITimeManager*>(InTimeManager->NoesisInterface.GetPtr());
	HandoffBehavior NoesisInHandoff = (Noesis::Gui::HandoffBehavior)InHandoff;
	return NoesisAnimationTimeline->Start(NoesisInTarget, NoesisInDp, NoesisInTimeManager, NoesisInHandoff);
}

void UNoesisAnimationTimeline::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::AnimationTimeline* NoesisAnimationTimeline = NsDynamicCast<Noesis::Gui::AnimationTimeline*>(NoesisComponent.GetPtr());
	check(NoesisAnimationTimeline);


}

void UNoesisAnimationTimeline::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::AnimationTimeline* NoesisAnimationTimeline = NsDynamicCast<Noesis::Gui::AnimationTimeline*>(NoesisComponent.GetPtr());
	check(NoesisAnimationTimeline);


}

