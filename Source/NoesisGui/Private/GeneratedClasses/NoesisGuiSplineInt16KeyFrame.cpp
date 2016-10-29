////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSplineInt16KeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSplineInt16KeyFrame::UNoesisGuiSplineInt16KeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSplineInt16KeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SplineKeyFrame<NsInt16>* NoesisSplineInt16KeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsInt16>*>(InNoesisComponent);
	check(NoesisSplineInt16KeyFrame);
}

void UNoesisGuiSplineInt16KeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::SplineKeyFrame<NsInt16>* NoesisSplineInt16KeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisSplineInt16KeyFrame)


}

void UNoesisGuiSplineInt16KeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::SplineKeyFrame<NsInt16>* NoesisSplineInt16KeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisSplineInt16KeyFrame)


}

