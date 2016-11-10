////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisBooleanAnimationUsingKeyFrames.h"

using namespace Noesis;
using namespace Gui;

UNoesisBooleanAnimationUsingKeyFrames::UNoesisBooleanAnimationUsingKeyFrames(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisBooleanAnimationUsingKeyFrames::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AnimationUsingKeyFrames<NsBool>* NoesisBooleanAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<NsBool>*>(InNoesisComponent);
	check(NoesisBooleanAnimationUsingKeyFrames);
}

void UNoesisBooleanAnimationUsingKeyFrames::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::AnimationUsingKeyFrames<NsBool>* NoesisBooleanAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<NsBool>*>(NoesisComponent.GetPtr());
	check(NoesisBooleanAnimationUsingKeyFrames)


}

void UNoesisBooleanAnimationUsingKeyFrames::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::AnimationUsingKeyFrames<NsBool>* NoesisBooleanAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<NsBool>*>(NoesisComponent.GetPtr());
	check(NoesisBooleanAnimationUsingKeyFrames)


}

