////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiGeometry.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiGeometry::UNoesisGuiGeometry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiGeometry::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(InNoesisComponent);
	check(NoesisGeometry);
}

FNoesisGuiDrawingRect UNoesisGuiGeometry::GetBounds()
{
	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(NoesisComponent.GetPtr());
	check(NoesisGeometry);
	return FNoesisGuiDrawingRect(NoesisGeometry->GetBounds());
}

bool UNoesisGuiGeometry::FillContains(FNoesisGuiDrawingPoint InPoint)
{
	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(NoesisComponent.GetPtr());
	check(NoesisGeometry);
	const Drawing::Point NoesisInPoint = InPoint.ToNoesis();
	return NoesisGeometry->FillContains(NoesisInPoint);
}

FNoesisGuiDrawingRect UNoesisGuiGeometry::GetRenderBounds(class UNoesisGuiPen* InPen)
{
	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(NoesisComponent.GetPtr());
	check(NoesisGeometry);
	Pen* NoesisInPen = NsDynamicCast<Pen*>(InPen->NoesisComponent.GetPtr());
	return FNoesisGuiDrawingRect(NoesisGeometry->GetRenderBounds(NoesisInPen));
}

bool UNoesisGuiGeometry::IsEmpty()
{
	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(NoesisComponent.GetPtr());
	check(NoesisGeometry);
	return NoesisGeometry->IsEmpty();
}

bool UNoesisGuiGeometry::StrokeContains(class UNoesisGuiPen* InPen, FNoesisGuiDrawingPoint InPoint)
{
	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(NoesisComponent.GetPtr());
	check(NoesisGeometry);
	Pen* NoesisInPen = NsDynamicCast<Pen*>(InPen->NoesisComponent.GetPtr());
	const Drawing::Point NoesisInPoint = InPoint.ToNoesis();
	return NoesisGeometry->StrokeContains(NoesisInPen, NoesisInPoint);
}

void UNoesisGuiGeometry::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(NoesisComponent.GetPtr());
	check(NoesisGeometry)


}

void UNoesisGuiGeometry::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(NoesisComponent.GetPtr());
	check(NoesisGeometry)


}

