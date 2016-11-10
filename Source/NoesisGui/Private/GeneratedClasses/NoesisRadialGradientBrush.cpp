////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisRadialGradientBrush.h"

using namespace Noesis;
using namespace Gui;

UNoesisRadialGradientBrush::UNoesisRadialGradientBrush(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisRadialGradientBrush::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RadialGradientBrush* NoesisRadialGradientBrush = NsDynamicCast<Noesis::Gui::RadialGradientBrush*>(InNoesisComponent);
	check(NoesisRadialGradientBrush);
}

FNoesisDrawingPoint UNoesisRadialGradientBrush::GetCenter()
{
	Noesis::Gui::RadialGradientBrush* NoesisRadialGradientBrush = NsDynamicCast<Noesis::Gui::RadialGradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisRadialGradientBrush);
	return FNoesisDrawingPoint(NoesisRadialGradientBrush->GetCenter());
}

void UNoesisRadialGradientBrush::SetCenter(FNoesisDrawingPoint InCenter)
{
	Noesis::Gui::RadialGradientBrush* NoesisRadialGradientBrush = NsDynamicCast<Noesis::Gui::RadialGradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisRadialGradientBrush);
	NoesisRadialGradientBrush->SetCenter(InCenter.ToNoesis());
}

FNoesisDrawingPoint UNoesisRadialGradientBrush::GetGradientOrigin()
{
	Noesis::Gui::RadialGradientBrush* NoesisRadialGradientBrush = NsDynamicCast<Noesis::Gui::RadialGradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisRadialGradientBrush);
	return FNoesisDrawingPoint(NoesisRadialGradientBrush->GetGradientOrigin());
}

void UNoesisRadialGradientBrush::SetGradientOrigin(FNoesisDrawingPoint InGradientOrigin)
{
	Noesis::Gui::RadialGradientBrush* NoesisRadialGradientBrush = NsDynamicCast<Noesis::Gui::RadialGradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisRadialGradientBrush);
	NoesisRadialGradientBrush->SetGradientOrigin(InGradientOrigin.ToNoesis());
}

float UNoesisRadialGradientBrush::GetRadiusX()
{
	Noesis::Gui::RadialGradientBrush* NoesisRadialGradientBrush = NsDynamicCast<Noesis::Gui::RadialGradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisRadialGradientBrush);
	return (float)NoesisRadialGradientBrush->GetRadiusX();
}

void UNoesisRadialGradientBrush::SetRadiusX(float InRadiusX)
{
	Noesis::Gui::RadialGradientBrush* NoesisRadialGradientBrush = NsDynamicCast<Noesis::Gui::RadialGradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisRadialGradientBrush);
	NoesisRadialGradientBrush->SetRadiusX(InRadiusX);
}

float UNoesisRadialGradientBrush::GetRadiusY()
{
	Noesis::Gui::RadialGradientBrush* NoesisRadialGradientBrush = NsDynamicCast<Noesis::Gui::RadialGradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisRadialGradientBrush);
	return (float)NoesisRadialGradientBrush->GetRadiusY();
}

void UNoesisRadialGradientBrush::SetRadiusY(float InRadiusY)
{
	Noesis::Gui::RadialGradientBrush* NoesisRadialGradientBrush = NsDynamicCast<Noesis::Gui::RadialGradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisRadialGradientBrush);
	NoesisRadialGradientBrush->SetRadiusY(InRadiusY);
}

void UNoesisRadialGradientBrush::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::RadialGradientBrush* NoesisRadialGradientBrush = NsDynamicCast<Noesis::Gui::RadialGradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisRadialGradientBrush)


}

void UNoesisRadialGradientBrush::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::RadialGradientBrush* NoesisRadialGradientBrush = NsDynamicCast<Noesis::Gui::RadialGradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisRadialGradientBrush)


}

