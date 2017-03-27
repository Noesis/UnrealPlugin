////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisLineGeometry.h"

using namespace Noesis;
using namespace Gui;

UNoesisLineGeometry::UNoesisLineGeometry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::LineGeometry::StaticGetClassType();
}

void UNoesisLineGeometry::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::LineGeometry* NoesisLineGeometry = NsDynamicCast<Noesis::Gui::LineGeometry*>(InNoesisComponent);
	check(NoesisLineGeometry);
}

FNoesisDrawingPoint UNoesisLineGeometry::GetEndPoint()
{
	Noesis::Gui::LineGeometry* NoesisLineGeometry = NsDynamicCast<Noesis::Gui::LineGeometry*>(NoesisComponent.GetPtr());
	check(NoesisLineGeometry);
	return FNoesisDrawingPoint(NoesisLineGeometry->GetEndPoint());
}

void UNoesisLineGeometry::SetEndPoint(FNoesisDrawingPoint InEndPoint)
{
	Noesis::Gui::LineGeometry* NoesisLineGeometry = NsDynamicCast<Noesis::Gui::LineGeometry*>(NoesisComponent.GetPtr());
	check(NoesisLineGeometry);
	NoesisLineGeometry->SetEndPoint(InEndPoint.ToNoesis());
}

FNoesisDrawingPoint UNoesisLineGeometry::GetStartPoint()
{
	Noesis::Gui::LineGeometry* NoesisLineGeometry = NsDynamicCast<Noesis::Gui::LineGeometry*>(NoesisComponent.GetPtr());
	check(NoesisLineGeometry);
	return FNoesisDrawingPoint(NoesisLineGeometry->GetStartPoint());
}

void UNoesisLineGeometry::SetStartPoint(FNoesisDrawingPoint InStartPoint)
{
	Noesis::Gui::LineGeometry* NoesisLineGeometry = NsDynamicCast<Noesis::Gui::LineGeometry*>(NoesisComponent.GetPtr());
	check(NoesisLineGeometry);
	NoesisLineGeometry->SetStartPoint(InStartPoint.ToNoesis());
}

void UNoesisLineGeometry::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::LineGeometry* NoesisLineGeometry = NsDynamicCast<Noesis::Gui::LineGeometry*>(NoesisComponent.GetPtr());
	check(NoesisLineGeometry);


}

void UNoesisLineGeometry::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::LineGeometry* NoesisLineGeometry = NsDynamicCast<Noesis::Gui::LineGeometry*>(NoesisComponent.GetPtr());
	check(NoesisLineGeometry);


}

