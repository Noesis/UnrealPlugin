////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisSplineDoubleKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisSplineDoubleKeyFrame::UNoesisSplineDoubleKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisSplineDoubleKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SplineKeyFrame<NsFloat32>* NoesisSplineDoubleKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsFloat32>*>(InNoesisComponent);
	check(NoesisSplineDoubleKeyFrame);
}

class UNoesisKeySpline* UNoesisSplineDoubleKeyFrame::GetKeySpline()
{
	Noesis::Gui::SplineKeyFrame<NsFloat32>* NoesisSplineDoubleKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisSplineDoubleKeyFrame);
	return CastChecked<UNoesisKeySpline>(Instance->FindUnrealComponentForNoesisComponent(NoesisSplineDoubleKeyFrame->GetKeySpline()));
}

void UNoesisSplineDoubleKeyFrame::SetKeySpline(class UNoesisKeySpline* InKeySpline)
{
	Noesis::Gui::SplineKeyFrame<NsFloat32>* NoesisSplineDoubleKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisSplineDoubleKeyFrame);
	NoesisSplineDoubleKeyFrame->SetKeySpline(NsDynamicCast<KeySpline*>(InKeySpline->NoesisComponent.GetPtr()));
}

void UNoesisSplineDoubleKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::SplineKeyFrame<NsFloat32>* NoesisSplineDoubleKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisSplineDoubleKeyFrame)


}

void UNoesisSplineDoubleKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::SplineKeyFrame<NsFloat32>* NoesisSplineDoubleKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisSplineDoubleKeyFrame)


}

