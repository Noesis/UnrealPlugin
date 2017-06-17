////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisEllipseGeometry.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisEllipseGeometry::UNoesisEllipseGeometry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::EllipseGeometry::StaticGetClassType();
}

void UNoesisEllipseGeometry::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EllipseGeometry* NoesisEllipseGeometry = NsDynamicCast<Noesis::Gui::EllipseGeometry*>(InNoesisComponent);
	check(NoesisEllipseGeometry);
}

FNoesisDrawingPoint UNoesisEllipseGeometry::GetCenter()
{
	Noesis::Gui::EllipseGeometry* NoesisEllipseGeometry = NsDynamicCast<Noesis::Gui::EllipseGeometry*>(NoesisComponent.GetPtr());
	check(NoesisEllipseGeometry);
	return FNoesisDrawingPoint(NoesisEllipseGeometry->GetCenter());
}

void UNoesisEllipseGeometry::SetCenter(FNoesisDrawingPoint InCenter)
{
	Noesis::Gui::EllipseGeometry* NoesisEllipseGeometry = NsDynamicCast<Noesis::Gui::EllipseGeometry*>(NoesisComponent.GetPtr());
	check(NoesisEllipseGeometry);
	NoesisEllipseGeometry->SetCenter(InCenter.ToNoesis());
}

float UNoesisEllipseGeometry::GetRadiusX()
{
	Noesis::Gui::EllipseGeometry* NoesisEllipseGeometry = NsDynamicCast<Noesis::Gui::EllipseGeometry*>(NoesisComponent.GetPtr());
	check(NoesisEllipseGeometry);
	return (float)NoesisEllipseGeometry->GetRadiusX();
}

void UNoesisEllipseGeometry::SetRadiusX(float InRadiusX)
{
	Noesis::Gui::EllipseGeometry* NoesisEllipseGeometry = NsDynamicCast<Noesis::Gui::EllipseGeometry*>(NoesisComponent.GetPtr());
	check(NoesisEllipseGeometry);
	NoesisEllipseGeometry->SetRadiusX(InRadiusX);
}

float UNoesisEllipseGeometry::GetRadiusY()
{
	Noesis::Gui::EllipseGeometry* NoesisEllipseGeometry = NsDynamicCast<Noesis::Gui::EllipseGeometry*>(NoesisComponent.GetPtr());
	check(NoesisEllipseGeometry);
	return (float)NoesisEllipseGeometry->GetRadiusY();
}

void UNoesisEllipseGeometry::SetRadiusY(float InRadiusY)
{
	Noesis::Gui::EllipseGeometry* NoesisEllipseGeometry = NsDynamicCast<Noesis::Gui::EllipseGeometry*>(NoesisComponent.GetPtr());
	check(NoesisEllipseGeometry);
	NoesisEllipseGeometry->SetRadiusY(InRadiusY);
}

void UNoesisEllipseGeometry::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::EllipseGeometry* NoesisEllipseGeometry = NsDynamicCast<Noesis::Gui::EllipseGeometry*>(NoesisComponent.GetPtr());
	check(NoesisEllipseGeometry);


}

void UNoesisEllipseGeometry::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::EllipseGeometry* NoesisEllipseGeometry = NsDynamicCast<Noesis::Gui::EllipseGeometry*>(NoesisComponent.GetPtr());
	check(NoesisEllipseGeometry);


}

