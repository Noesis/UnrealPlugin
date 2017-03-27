////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisKeySpline.h"

using namespace Noesis;
using namespace Gui;

UNoesisKeySpline::UNoesisKeySpline(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::KeySpline::StaticGetClassType();
}

void UNoesisKeySpline::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(InNoesisComponent);
	check(NoesisKeySpline);
}

FNoesisDrawingPoint UNoesisKeySpline::GetControlPoint1()
{
	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(NoesisComponent.GetPtr());
	check(NoesisKeySpline);
	return FNoesisDrawingPoint(NoesisKeySpline->GetControlPoint1());
}

void UNoesisKeySpline::SetControlPoint1(FNoesisDrawingPoint InControlPoint1)
{
	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(NoesisComponent.GetPtr());
	check(NoesisKeySpline);
	NoesisKeySpline->SetControlPoint1(InControlPoint1.ToNoesis());
}

FNoesisDrawingPoint UNoesisKeySpline::GetControlPoint2()
{
	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(NoesisComponent.GetPtr());
	check(NoesisKeySpline);
	return FNoesisDrawingPoint(NoesisKeySpline->GetControlPoint2());
}

void UNoesisKeySpline::SetControlPoint2(FNoesisDrawingPoint InControlPoint2)
{
	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(NoesisComponent.GetPtr());
	check(NoesisKeySpline);
	NoesisKeySpline->SetControlPoint2(InControlPoint2.ToNoesis());
}

float UNoesisKeySpline::GetSplineProgress(float InLinearProgress)
{
	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(NoesisComponent.GetPtr());
	check(NoesisKeySpline);
	NsFloat32 NoesisInLinearProgress = InLinearProgress;
	return (float)NoesisKeySpline->GetSplineProgress(NoesisInLinearProgress);
}

void UNoesisKeySpline::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(NoesisComponent.GetPtr());
	check(NoesisKeySpline);


}

void UNoesisKeySpline::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(NoesisComponent.GetPtr());
	check(NoesisKeySpline);


}

