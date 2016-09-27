////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSplineSizeKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSplineSizeKeyFrame::UNoesisGuiSplineSizeKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSplineSizeKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Size>* NoesisSplineSizeKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Size>*>(InNoesisComponent);
	check(NoesisSplineSizeKeyFrame);

}

	void UNoesisGuiSplineSizeKeyFrame::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Size>* NoesisSplineSizeKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	if (!NoesisSplineSizeKeyFrame)
		return;

}

