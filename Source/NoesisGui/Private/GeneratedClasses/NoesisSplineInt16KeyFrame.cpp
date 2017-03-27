////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisSplineInt16KeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisSplineInt16KeyFrame::UNoesisSplineInt16KeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::SplineKeyFrame<NsInt16>::StaticGetClassType();
}

void UNoesisSplineInt16KeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SplineKeyFrame<NsInt16>* NoesisSplineInt16KeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsInt16>*>(InNoesisComponent);
	check(NoesisSplineInt16KeyFrame);
}

class UNoesisKeySpline* UNoesisSplineInt16KeyFrame::GetKeySpline()
{
	Noesis::Gui::SplineKeyFrame<NsInt16>* NoesisSplineInt16KeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisSplineInt16KeyFrame);
	return CastChecked<UNoesisKeySpline>(CreateClassFor(NoesisSplineInt16KeyFrame->GetKeySpline(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisSplineInt16KeyFrame::SetKeySpline(class UNoesisKeySpline* InKeySpline)
{
	Noesis::Gui::SplineKeyFrame<NsInt16>* NoesisSplineInt16KeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisSplineInt16KeyFrame);
	NoesisSplineInt16KeyFrame->SetKeySpline(NsDynamicCast<KeySpline*>(InKeySpline->NoesisComponent.GetPtr()));
}

void UNoesisSplineInt16KeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::SplineKeyFrame<NsInt16>* NoesisSplineInt16KeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisSplineInt16KeyFrame);


}

void UNoesisSplineInt16KeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::SplineKeyFrame<NsInt16>* NoesisSplineInt16KeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisSplineInt16KeyFrame);


}

