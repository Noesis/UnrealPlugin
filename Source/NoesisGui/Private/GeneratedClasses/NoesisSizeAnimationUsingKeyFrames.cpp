////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisSizeAnimationUsingKeyFrames.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisSizeAnimationUsingKeyFrames::UNoesisSizeAnimationUsingKeyFrames(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Size>::StaticGetClassType();
}

void UNoesisSizeAnimationUsingKeyFrames::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Size>* NoesisSizeAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Size>*>(InNoesisComponent);
	check(NoesisSizeAnimationUsingKeyFrames);
}

void UNoesisSizeAnimationUsingKeyFrames::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Size>* NoesisSizeAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisSizeAnimationUsingKeyFrames);


}

void UNoesisSizeAnimationUsingKeyFrames::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Size>* NoesisSizeAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisSizeAnimationUsingKeyFrames);


}

