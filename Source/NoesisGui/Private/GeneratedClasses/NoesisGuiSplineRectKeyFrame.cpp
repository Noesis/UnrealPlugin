////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSplineRectKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSplineRectKeyFrame::UNoesisGuiSplineRectKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSplineRectKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Rect>* NoesisSplineRectKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Rect>*>(InNoesisComponent);
	check(NoesisSplineRectKeyFrame);

}

	void UNoesisGuiSplineRectKeyFrame::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Rect>* NoesisSplineRectKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	if (!NoesisSplineRectKeyFrame)
		return;

}

