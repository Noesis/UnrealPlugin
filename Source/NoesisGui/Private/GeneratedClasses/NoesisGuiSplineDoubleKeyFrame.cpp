////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSplineDoubleKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSplineDoubleKeyFrame::UNoesisGuiSplineDoubleKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSplineDoubleKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SplineKeyFrame<NsFloat32>* NoesisSplineDoubleKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsFloat32>*>(InNoesisComponent);
	check(NoesisSplineDoubleKeyFrame);
}

void UNoesisGuiSplineDoubleKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::SplineKeyFrame<NsFloat32>* NoesisSplineDoubleKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisSplineDoubleKeyFrame)


}

void UNoesisGuiSplineDoubleKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::SplineKeyFrame<NsFloat32>* NoesisSplineDoubleKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisSplineDoubleKeyFrame)


}

