////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiStringAnimationUsingKeyFrames.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiStringAnimationUsingKeyFrames::UNoesisGuiStringAnimationUsingKeyFrames(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiStringAnimationUsingKeyFrames::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AnimationUsingKeyFrames<NsString>* NoesisStringAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<NsString>*>(InNoesisComponent);
	check(NoesisStringAnimationUsingKeyFrames);

}

	void UNoesisGuiStringAnimationUsingKeyFrames::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::AnimationUsingKeyFrames<NsString>* NoesisStringAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<NsString>*>(NoesisComponent.GetPtr());
	if (!NoesisStringAnimationUsingKeyFrames)
		return;

}

