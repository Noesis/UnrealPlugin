////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGeometry.h"

using namespace Noesis;
using namespace Gui;

UNoesisGeometry::UNoesisGeometry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGeometry::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(InNoesisComponent);
	check(NoesisGeometry);
}

FNoesisDrawingRect UNoesisGeometry::GetBounds()
{
	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(NoesisComponent.GetPtr());
	check(NoesisGeometry);
	return FNoesisDrawingRect(NoesisGeometry->GetBounds());
}

class UNoesisTransform* UNoesisGeometry::GetTransform()
{
	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(NoesisComponent.GetPtr());
	check(NoesisGeometry);
	return CastChecked<UNoesisTransform>(Instance->FindUnrealComponentForNoesisComponent(NoesisGeometry->GetTransform()));
}

void UNoesisGeometry::SetTransform(class UNoesisTransform* InTransform)
{
	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(NoesisComponent.GetPtr());
	check(NoesisGeometry);
	NoesisGeometry->SetTransform(NsDynamicCast<Transform*>(InTransform->NoesisComponent.GetPtr()));
}

bool UNoesisGeometry::FillContains(FNoesisDrawingPoint InPoint)
{
	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(NoesisComponent.GetPtr());
	check(NoesisGeometry);
	const Drawing::Point NoesisInPoint = InPoint.ToNoesis();
	return NoesisGeometry->FillContains(NoesisInPoint);
}

FNoesisDrawingRect UNoesisGeometry::GetRenderBounds(class UNoesisPen* InPen)
{
	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(NoesisComponent.GetPtr());
	check(NoesisGeometry);
	Pen* NoesisInPen = NsDynamicCast<Pen*>(InPen->NoesisComponent.GetPtr());
	return FNoesisDrawingRect(NoesisGeometry->GetRenderBounds(NoesisInPen));
}

bool UNoesisGeometry::IsEmpty()
{
	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(NoesisComponent.GetPtr());
	check(NoesisGeometry);
	return NoesisGeometry->IsEmpty();
}

bool UNoesisGeometry::StrokeContains(class UNoesisPen* InPen, FNoesisDrawingPoint InPoint)
{
	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(NoesisComponent.GetPtr());
	check(NoesisGeometry);
	Pen* NoesisInPen = NsDynamicCast<Pen*>(InPen->NoesisComponent.GetPtr());
	const Drawing::Point NoesisInPoint = InPoint.ToNoesis();
	return NoesisGeometry->StrokeContains(NoesisInPen, NoesisInPoint);
}

void UNoesisGeometry::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(NoesisComponent.GetPtr());
	check(NoesisGeometry)


}

void UNoesisGeometry::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Geometry* NoesisGeometry = NsDynamicCast<Noesis::Gui::Geometry*>(NoesisComponent.GetPtr());
	check(NoesisGeometry)


}

