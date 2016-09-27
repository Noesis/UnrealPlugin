////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSplineThicknessKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSplineThicknessKeyFrame::UNoesisGuiSplineThicknessKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSplineThicknessKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Thickness>* NoesisSplineThicknessKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Thickness>*>(InNoesisComponent);
	check(NoesisSplineThicknessKeyFrame);

}

	void UNoesisGuiSplineThicknessKeyFrame::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Thickness>* NoesisSplineThicknessKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	if (!NoesisSplineThicknessKeyFrame)
		return;

}

