////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisRectAnimationUsingKeyFrames.h"

using namespace Noesis;
using namespace Gui;

UNoesisRectAnimationUsingKeyFrames::UNoesisRectAnimationUsingKeyFrames(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Rect>::StaticGetClassType();
}

void UNoesisRectAnimationUsingKeyFrames::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Rect>* NoesisRectAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Rect>*>(InNoesisComponent);
	check(NoesisRectAnimationUsingKeyFrames);
}

void UNoesisRectAnimationUsingKeyFrames::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Rect>* NoesisRectAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	check(NoesisRectAnimationUsingKeyFrames);


}

void UNoesisRectAnimationUsingKeyFrames::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Rect>* NoesisRectAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	check(NoesisRectAnimationUsingKeyFrames);


}

