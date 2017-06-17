////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisSplineRectKeyFrame.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisSplineRectKeyFrame::UNoesisSplineRectKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Rect>::StaticGetClassType();
}

void UNoesisSplineRectKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Rect>* NoesisSplineRectKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Rect>*>(InNoesisComponent);
	check(NoesisSplineRectKeyFrame);
}

class UNoesisKeySpline* UNoesisSplineRectKeyFrame::GetKeySpline()
{
	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Rect>* NoesisSplineRectKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	check(NoesisSplineRectKeyFrame);
	return CastChecked<UNoesisKeySpline>(CreateClassFor(NoesisSplineRectKeyFrame->GetKeySpline(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisSplineRectKeyFrame::SetKeySpline(class UNoesisKeySpline* InKeySpline)
{
	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Rect>* NoesisSplineRectKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	check(NoesisSplineRectKeyFrame);
	NoesisSplineRectKeyFrame->SetKeySpline(NsDynamicCast<KeySpline*>(InKeySpline->NoesisComponent.GetPtr()));
}

void UNoesisSplineRectKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Rect>* NoesisSplineRectKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	check(NoesisSplineRectKeyFrame);


}

void UNoesisSplineRectKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Rect>* NoesisSplineRectKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	check(NoesisSplineRectKeyFrame);


}

