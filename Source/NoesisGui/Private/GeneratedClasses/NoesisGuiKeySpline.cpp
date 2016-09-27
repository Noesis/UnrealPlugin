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
	return FNoesisGuiDrawingPoint(NoesisKeySpline->GetControlPoint1().x, NoesisKeySpline->GetControlPoint1().y);
}

void UNoesisGuiKeySpline::SetControlPoint1(FNoesisGuiDrawingPoint InControlPoint1)
{
	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(NoesisComponent.GetPtr());
	check(NoesisKeySpline);
	NoesisKeySpline->SetControlPoint1(Drawing::Point(InControlPoint1.X, InControlPoint1.Y));
}

FNoesisGuiDrawingPoint UNoesisGuiKeySpline::GetControlPoint2()
{
	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(NoesisComponent.GetPtr());
	check(NoesisKeySpline);
	return FNoesisGuiDrawingPoint(NoesisKeySpline->GetControlPoint2().x, NoesisKeySpline->GetControlPoint2().y);
}

void UNoesisGuiKeySpline::SetControlPoint2(FNoesisGuiDrawingPoint InControlPoint2)
{
	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(NoesisComponent.GetPtr());
	check(NoesisKeySpline);
	NoesisKeySpline->SetControlPoint2(Drawing::Point(InControlPoint2.X, InControlPoint2.Y));
}

	void UNoesisGuiKeySpline::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::KeySpline* NoesisKeySpline = NsDynamicCast<Noesis::Gui::KeySpline*>(NoesisComponent.GetPtr());
	if (!NoesisKeySpline)
		return;

}

