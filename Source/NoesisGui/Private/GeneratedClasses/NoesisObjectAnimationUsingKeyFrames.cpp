////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisObjectAnimationUsingKeyFrames.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisObjectAnimationUsingKeyFrames::UNoesisObjectAnimationUsingKeyFrames(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::AnimationUsingKeyFrames<Noesis::Ptr<Noesis::Core::BaseComponent>>::StaticGetClassType();
}

void UNoesisObjectAnimationUsingKeyFrames::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AnimationUsingKeyFrames<Noesis::Ptr<Noesis::Core::BaseComponent>>* NoesisObjectAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<Noesis::Ptr<Noesis::Core::BaseComponent>>*>(InNoesisComponent);
	check(NoesisObjectAnimationUsingKeyFrames);
}

void UNoesisObjectAnimationUsingKeyFrames::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::AnimationUsingKeyFrames<Noesis::Ptr<Noesis::Core::BaseComponent>>* NoesisObjectAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<Noesis::Ptr<Noesis::Core::BaseComponent>>*>(NoesisComponent.GetPtr());
	check(NoesisObjectAnimationUsingKeyFrames);


}

void UNoesisObjectAnimationUsingKeyFrames::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::AnimationUsingKeyFrames<Noesis::Ptr<Noesis::Core::BaseComponent>>* NoesisObjectAnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<Noesis::Ptr<Noesis::Core::BaseComponent>>*>(NoesisComponent.GetPtr());
	check(NoesisObjectAnimationUsingKeyFrames);


}

