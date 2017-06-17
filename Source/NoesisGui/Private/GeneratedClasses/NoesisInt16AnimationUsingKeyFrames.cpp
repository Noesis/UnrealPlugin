////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisInt16AnimationUsingKeyFrames.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisInt16AnimationUsingKeyFrames::UNoesisInt16AnimationUsingKeyFrames(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::AnimationUsingKeyFrames<NsInt16>::StaticGetClassType();
}

void UNoesisInt16AnimationUsingKeyFrames::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AnimationUsingKeyFrames<NsInt16>* NoesisInt16AnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<NsInt16>*>(InNoesisComponent);
	check(NoesisInt16AnimationUsingKeyFrames);
}

void UNoesisInt16AnimationUsingKeyFrames::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::AnimationUsingKeyFrames<NsInt16>* NoesisInt16AnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisInt16AnimationUsingKeyFrames);


}

void UNoesisInt16AnimationUsingKeyFrames::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::AnimationUsingKeyFrames<NsInt16>* NoesisInt16AnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisInt16AnimationUsingKeyFrames);


}

