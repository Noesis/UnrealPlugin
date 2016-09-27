////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSizeAnimationUsingKeyFrames.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSizeAnimationUsingKeyFrames::UNoesisGuiSizeAnimationUsingKeyFrames(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSizeAnimationUsingKeyFrames::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Size>* NoesisSizeAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Size>*>(InNoesisComponent);
	check(NoesisSizeAnimationUsingKeyFrames);

}

	void UNoesisGuiSizeAnimationUsingKeyFrames::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Size>* NoesisSizeAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	if (!NoesisSizeAnimationUsingKeyFrames)
		return;

}

