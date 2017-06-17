////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisSplineSizeKeyFrame.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisSplineSizeKeyFrame::UNoesisSplineSizeKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Size>::StaticGetClassType();
}

void UNoesisSplineSizeKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Size>* NoesisSplineSizeKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Size>*>(InNoesisComponent);
	check(NoesisSplineSizeKeyFrame);
}

class UNoesisKeySpline* UNoesisSplineSizeKeyFrame::GetKeySpline()
{
	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Size>* NoesisSplineSizeKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisSplineSizeKeyFrame);
	return CastChecked<UNoesisKeySpline>(CreateClassFor(NoesisSplineSizeKeyFrame->GetKeySpline(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisSplineSizeKeyFrame::SetKeySpline(class UNoesisKeySpline* InKeySpline)
{
	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Size>* NoesisSplineSizeKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisSplineSizeKeyFrame);
	NoesisSplineSizeKeyFrame->SetKeySpline(NsDynamicCast<KeySpline*>(InKeySpline->NoesisComponent.GetPtr()));
}

void UNoesisSplineSizeKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Size>* NoesisSplineSizeKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisSplineSizeKeyFrame);


}

void UNoesisSplineSizeKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Size>* NoesisSplineSizeKeyFrame = NsDynamicCast<Noesis::Gui::SplineKeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisSplineSizeKeyFrame);


}

