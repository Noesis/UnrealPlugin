////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiKeySpline.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiKeySpline::UNoesisGuiKeySpline(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiKeySpline::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(InNoesisComponent);
	check(NoesisKeySpline);

}

FNoesisGuiDrawingPoint UNoesisGuiKeySpline::GetControlPoint1()
{
	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(NoesisComponent.GetPtr());
	check(NoesisKeySpline);
	return FNoesisGuiDrawingPoint(NoesisKeySpline->GetControlPoint1());
}

void UNoesisGuiKeySpline::SetControlPoint1(FNoesisGuiDrawingPoint InControlPoint1)
{
	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(NoesisComponent.GetPtr());
	check(NoesisKeySpline);
	NoesisKeySpline->SetControlPoint1(InControlPoint1.ToNoesis());
}

FNoesisGuiDrawingPoint UNoesisGuiKeySpline::GetControlPoint2()
{
	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(NoesisComponent.GetPtr());
	check(NoesisKeySpline);
	return FNoesisGuiDrawingPoint(NoesisKeySpline->GetControlPoint2());
}

void UNoesisGuiKeySpline::SetControlPoint2(FNoesisGuiDrawingPoint InControlPoint2)
{
	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(NoesisComponent.GetPtr());
	check(NoesisKeySpline);
	NoesisKeySpline->SetControlPoint2(InControlPoint2.ToNoesis());
}

float UNoesisGuiKeySpline::GetSplineProgress(float InLinearProgress)
{
	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(NoesisComponent.GetPtr());
	check(NoesisKeySpline);
	NsFloat32 NoesisInLinearProgress = InLinearProgress;
	return (float)NoesisKeySpline->GetSplineProgress(NoesisInLinearProgress);
}

	void UNoesisGuiKeySpline::BeginDestroy()
{
	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(NoesisComponent.GetPtr());
	if (!NoesisKeySpline)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

