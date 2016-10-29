////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiThicknessAnimationUsingKeyFrames.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiThicknessAnimationUsingKeyFrames::UNoesisGuiThicknessAnimationUsingKeyFrames(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiThicknessAnimationUsingKeyFrames::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Thickness>* NoesisThicknessAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Thickness>*>(InNoesisComponent);
	check(NoesisThicknessAnimationUsingKeyFrames);
}

void UNoesisGuiThicknessAnimationUsingKeyFrames::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Thickness>* NoesisThicknessAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	check(NoesisThicknessAnimationUsingKeyFrames)


}

void UNoesisGuiThicknessAnimationUsingKeyFrames::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Thickness>* NoesisThicknessAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	check(NoesisThicknessAnimationUsingKeyFrames)


}

