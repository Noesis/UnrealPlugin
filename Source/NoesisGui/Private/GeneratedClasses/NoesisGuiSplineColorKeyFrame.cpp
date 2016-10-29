////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSplineColorKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSplineColorKeyFrame::UNoesisGuiSplineColorKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSplineColorKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Color>* NoesisSplineColorKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Color>*>(InNoesisComponent);
	check(NoesisSplineColorKeyFrame);
}

void UNoesisGuiSplineColorKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Color>* NoesisSplineColorKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	check(NoesisSplineColorKeyFrame)


}

void UNoesisGuiSplineColorKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Color>* NoesisSplineColorKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	check(NoesisSplineColorKeyFrame)


}

