////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisRectangleGeometry.h"

using namespace Noesis;
using namespace Gui;

UNoesisRectangleGeometry::UNoesisRectangleGeometry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::RectangleGeometry::StaticGetClassType();
}

void UNoesisRectangleGeometry::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RectangleGeometry* NoesisRectangleGeometry = NsDynamicCast<Noesis::Gui::RectangleGeometry*>(InNoesisComponent);
	check(NoesisRectangleGeometry);
}

float UNoesisRectangleGeometry::GetRadiusX()
{
	Noesis::Gui::RectangleGeometry* NoesisRectangleGeometry = NsDynamicCast<Noesis::Gui::RectangleGeometry*>(NoesisComponent.GetPtr());
	check(NoesisRectangleGeometry);
	return (float)NoesisRectangleGeometry->GetRadiusX();
}

void UNoesisRectangleGeometry::SetRadiusX(float InRadiusX)
{
	Noesis::Gui::RectangleGeometry* NoesisRectangleGeometry = NsDynamicCast<Noesis::Gui::RectangleGeometry*>(NoesisComponent.GetPtr());
	check(NoesisRectangleGeometry);
	NoesisRectangleGeometry->SetRadiusX(InRadiusX);
}

float UNoesisRectangleGeometry::GetRadiusY()
{
	Noesis::Gui::RectangleGeometry* NoesisRectangleGeometry = NsDynamicCast<Noesis::Gui::RectangleGeometry*>(NoesisComponent.GetPtr());
	check(NoesisRectangleGeometry);
	return (float)NoesisRectangleGeometry->GetRadiusY();
}

void UNoesisRectangleGeometry::SetRadiusY(float InRadiusY)
{
	Noesis::Gui::RectangleGeometry* NoesisRectangleGeometry = NsDynamicCast<Noesis::Gui::RectangleGeometry*>(NoesisComponent.GetPtr());
	check(NoesisRectangleGeometry);
	NoesisRectangleGeometry->SetRadiusY(InRadiusY);
}

FNoesisDrawingRect UNoesisRectangleGeometry::GetRect()
{
	Noesis::Gui::RectangleGeometry* NoesisRectangleGeometry = NsDynamicCast<Noesis::Gui::RectangleGeometry*>(NoesisComponent.GetPtr());
	check(NoesisRectangleGeometry);
	return FNoesisDrawingRect(NoesisRectangleGeometry->GetRect());
}

void UNoesisRectangleGeometry::SetRect(FNoesisDrawingRect InRect)
{
	Noesis::Gui::RectangleGeometry* NoesisRectangleGeometry = NsDynamicCast<Noesis::Gui::RectangleGeometry*>(NoesisComponent.GetPtr());
	check(NoesisRectangleGeometry);
	NoesisRectangleGeometry->SetRect(InRect.ToNoesis());
}

void UNoesisRectangleGeometry::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::RectangleGeometry* NoesisRectangleGeometry = NsDynamicCast<Noesis::Gui::RectangleGeometry*>(NoesisComponent.GetPtr());
	check(NoesisRectangleGeometry);


}

void UNoesisRectangleGeometry::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::RectangleGeometry* NoesisRectangleGeometry = NsDynamicCast<Noesis::Gui::RectangleGeometry*>(NoesisComponent.GetPtr());
	check(NoesisRectangleGeometry);


}

