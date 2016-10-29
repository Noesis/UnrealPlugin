////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBooleanAnimationUsingKeyFrames.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBooleanAnimationUsingKeyFrames::UNoesisGuiBooleanAnimationUsingKeyFrames(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBooleanAnimationUsingKeyFrames::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AnimationUsingKeyFrames<NsBool>* NoesisBooleanAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<NsBool>*>(InNoesisComponent);
	check(NoesisBooleanAnimationUsingKeyFrames);
}

void UNoesisGuiBooleanAnimationUsingKeyFrames::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::AnimationUsingKeyFrames<NsBool>* NoesisBooleanAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<NsBool>*>(NoesisComponent.GetPtr());
	check(NoesisBooleanAnimationUsingKeyFrames)


}

void UNoesisGuiBooleanAnimationUsingKeyFrames::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::AnimationUsingKeyFrames<NsBool>* NoesisBooleanAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<NsBool>*>(NoesisComponent.GetPtr());
	check(NoesisBooleanAnimationUsingKeyFrames)


}

