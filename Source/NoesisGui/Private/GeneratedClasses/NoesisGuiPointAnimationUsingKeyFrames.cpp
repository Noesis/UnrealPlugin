////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiPointAnimationUsingKeyFrames.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiPointAnimationUsingKeyFrames::UNoesisGuiPointAnimationUsingKeyFrames(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiPointAnimationUsingKeyFrames::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Point>* NoesisPointAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Point>*>(InNoesisComponent);
	check(NoesisPointAnimationUsingKeyFrames);

}

	void UNoesisGuiPointAnimationUsingKeyFrames::BeginDestroy()
{
	Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Point>* NoesisPointAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Point>*>(NoesisComponent.GetPtr());
	if (!NoesisPointAnimationUsingKeyFrames)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

