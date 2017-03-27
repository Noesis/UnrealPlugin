////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisSplineColorKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisSplineColorKeyFrame::UNoesisSplineColorKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Color>::StaticGetClassType();
}

void UNoesisSplineColorKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Color>* NoesisSplineColorKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Color>*>(InNoesisComponent);
	check(NoesisSplineColorKeyFrame);
}

class UNoesisKeySpline* UNoesisSplineColorKeyFrame::GetKeySpline()
{
	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Color>* NoesisSplineColorKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	check(NoesisSplineColorKeyFrame);
	return CastChecked<UNoesisKeySpline>(CreateClassFor(NoesisSplineColorKeyFrame->GetKeySpline(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisSplineColorKeyFrame::SetKeySpline(class UNoesisKeySpline* InKeySpline)
{
	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Color>* NoesisSplineColorKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	check(NoesisSplineColorKeyFrame);
	NoesisSplineColorKeyFrame->SetKeySpline(NsDynamicCast<KeySpline*>(InKeySpline->NoesisComponent.GetPtr()));
}

void UNoesisSplineColorKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Color>* NoesisSplineColorKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	check(NoesisSplineColorKeyFrame);


}

void UNoesisSplineColorKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Color>* NoesisSplineColorKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	check(NoesisSplineColorKeyFrame);


}

