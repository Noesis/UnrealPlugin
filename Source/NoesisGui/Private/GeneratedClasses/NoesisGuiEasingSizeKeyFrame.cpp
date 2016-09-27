////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiEasingSizeKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiEasingSizeKeyFrame::UNoesisGuiEasingSizeKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiEasingSizeKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Size>* NoesisEasingSizeKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Size>*>(InNoesisComponent);
	check(NoesisEasingSizeKeyFrame);

}

	void UNoesisGuiEasingSizeKeyFrame::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Size>* NoesisEasingSizeKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	if (!NoesisEasingSizeKeyFrame)
		return;

}

