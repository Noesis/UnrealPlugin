////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiObjectAnimationUsingKeyFrames.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiObjectAnimationUsingKeyFrames::UNoesisGuiObjectAnimationUsingKeyFrames(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiObjectAnimationUsingKeyFrames::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AnimationUsingKeyFrames<Noesis::Ptr<Noesis::Core::BaseComponent>>* NoesisObjectAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<Noesis::Ptr<Noesis::Core::BaseComponent>>*>(InNoesisComponent);
	check(NoesisObjectAnimationUsingKeyFrames);

}

	void UNoesisGuiObjectAnimationUsingKeyFrames::BeginDestroy()
{
	Noesis::Gui::AnimationUsingKeyFrames<Noesis::Ptr<Noesis::Core::BaseComponent>>* NoesisObjectAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<Noesis::Ptr<Noesis::Core::BaseComponent>>*>(NoesisComponent.GetPtr());
	if (!NoesisObjectAnimationUsingKeyFrames)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

