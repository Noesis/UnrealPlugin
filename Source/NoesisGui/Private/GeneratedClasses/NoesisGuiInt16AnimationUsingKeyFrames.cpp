////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiInt16AnimationUsingKeyFrames.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiInt16AnimationUsingKeyFrames::UNoesisGuiInt16AnimationUsingKeyFrames(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiInt16AnimationUsingKeyFrames::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AnimationUsingKeyFrames<NsInt16>* NoesisInt16AnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<NsInt16>*>(InNoesisComponent);
	check(NoesisInt16AnimationUsingKeyFrames);

}

	void UNoesisGuiInt16AnimationUsingKeyFrames::BeginDestroy()
{
	Noesis::Gui::AnimationUsingKeyFrames<NsInt16>* NoesisInt16AnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<NsInt16>*>(NoesisComponent.GetPtr());
	if (!NoesisInt16AnimationUsingKeyFrames)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

