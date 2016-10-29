////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSplineInt32KeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSplineInt32KeyFrame::UNoesisGuiSplineInt32KeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSplineInt32KeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SplineKeyFrame<NsInt32>* NoesisSplineInt32KeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsInt32>*>(InNoesisComponent);
	check(NoesisSplineInt32KeyFrame);
}

void UNoesisGuiSplineInt32KeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::SplineKeyFrame<NsInt32>* NoesisSplineInt32KeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisSplineInt32KeyFrame)


}

void UNoesisGuiSplineInt32KeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::SplineKeyFrame<NsInt32>* NoesisSplineInt32KeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisSplineInt32KeyFrame)


}

