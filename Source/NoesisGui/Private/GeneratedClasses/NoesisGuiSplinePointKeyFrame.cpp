////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSplinePointKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSplinePointKeyFrame::UNoesisGuiSplinePointKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSplinePointKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Point>* NoesisSplinePointKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Point>*>(InNoesisComponent);
	check(NoesisSplinePointKeyFrame);

}

	void UNoesisGuiSplinePointKeyFrame::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Point>* NoesisSplinePointKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Point>*>(NoesisComponent.GetPtr());
	if (!NoesisSplinePointKeyFrame)
		return;

}

