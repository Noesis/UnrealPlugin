////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiInt32AnimationUsingKeyFrames.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiInt32AnimationUsingKeyFrames::UNoesisGuiInt32AnimationUsingKeyFrames(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiInt32AnimationUsingKeyFrames::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AnimationUsingKeyFrames<NsInt32>* NoesisInt32AnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<NsInt32>*>(InNoesisComponent);
	check(NoesisInt32AnimationUsingKeyFrames);

}

	void UNoesisGuiInt32AnimationUsingKeyFrames::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::AnimationUsingKeyFrames<NsInt32>* NoesisInt32AnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<NsInt32>*>(NoesisComponent.GetPtr());
	if (!NoesisInt32AnimationUsingKeyFrames)
		return;

}

