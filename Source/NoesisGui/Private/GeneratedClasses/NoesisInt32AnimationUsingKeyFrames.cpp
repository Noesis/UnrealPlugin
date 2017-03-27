////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisInt32AnimationUsingKeyFrames.h"

using namespace Noesis;
using namespace Gui;

UNoesisInt32AnimationUsingKeyFrames::UNoesisInt32AnimationUsingKeyFrames(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::AnimationUsingKeyFrames<NsInt32>::StaticGetClassType();
}

void UNoesisInt32AnimationUsingKeyFrames::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::AnimationUsingKeyFrames<NsInt32>* NoesisInt32AnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<NsInt32>*>(InNoesisComponent);
	check(NoesisInt32AnimationUsingKeyFrames);
}

void UNoesisInt32AnimationUsingKeyFrames::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::AnimationUsingKeyFrames<NsInt32>* NoesisInt32AnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisInt32AnimationUsingKeyFrames);


}

void UNoesisInt32AnimationUsingKeyFrames::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::AnimationUsingKeyFrames<NsInt32>* NoesisInt32AnimationUsingKeyFrames = NsDynamicCast<Noesis::Gui::AnimationUsingKeyFrames<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisInt32AnimationUsingKeyFrames);


}

