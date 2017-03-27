////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisSplineInt32KeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisSplineInt32KeyFrame::UNoesisSplineInt32KeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::SplineKeyFrame<NsInt32>::StaticGetClassType();
}

void UNoesisSplineInt32KeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SplineKeyFrame<NsInt32>* NoesisSplineInt32KeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsInt32>*>(InNoesisComponent);
	check(NoesisSplineInt32KeyFrame);
}

class UNoesisKeySpline* UNoesisSplineInt32KeyFrame::GetKeySpline()
{
	Noesis::Gui::SplineKeyFrame<NsInt32>* NoesisSplineInt32KeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisSplineInt32KeyFrame);
	return CastChecked<UNoesisKeySpline>(CreateClassFor(NoesisSplineInt32KeyFrame->GetKeySpline(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisSplineInt32KeyFrame::SetKeySpline(class UNoesisKeySpline* InKeySpline)
{
	Noesis::Gui::SplineKeyFrame<NsInt32>* NoesisSplineInt32KeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisSplineInt32KeyFrame);
	NoesisSplineInt32KeyFrame->SetKeySpline(NsDynamicCast<KeySpline*>(InKeySpline->NoesisComponent.GetPtr()));
}

void UNoesisSplineInt32KeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::SplineKeyFrame<NsInt32>* NoesisSplineInt32KeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisSplineInt32KeyFrame);


}

void UNoesisSplineInt32KeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::SplineKeyFrame<NsInt32>* NoesisSplineInt32KeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisSplineInt32KeyFrame);


}

