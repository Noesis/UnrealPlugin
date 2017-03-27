////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisSplineThicknessKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisSplineThicknessKeyFrame::UNoesisSplineThicknessKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Thickness>::StaticGetClassType();
}

void UNoesisSplineThicknessKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Thickness>* NoesisSplineThicknessKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Thickness>*>(InNoesisComponent);
	check(NoesisSplineThicknessKeyFrame);
}

class UNoesisKeySpline* UNoesisSplineThicknessKeyFrame::GetKeySpline()
{
	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Thickness>* NoesisSplineThicknessKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	check(NoesisSplineThicknessKeyFrame);
	return CastChecked<UNoesisKeySpline>(CreateClassFor(NoesisSplineThicknessKeyFrame->GetKeySpline(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisSplineThicknessKeyFrame::SetKeySpline(class UNoesisKeySpline* InKeySpline)
{
	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Thickness>* NoesisSplineThicknessKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	check(NoesisSplineThicknessKeyFrame);
	NoesisSplineThicknessKeyFrame->SetKeySpline(NsDynamicCast<KeySpline*>(InKeySpline->NoesisComponent.GetPtr()));
}

void UNoesisSplineThicknessKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Thickness>* NoesisSplineThicknessKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	check(NoesisSplineThicknessKeyFrame);


}

void UNoesisSplineThicknessKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Thickness>* NoesisSplineThicknessKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	check(NoesisSplineThicknessKeyFrame);


}

