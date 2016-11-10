////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisLinearGradientBrush.h"

using namespace Noesis;
using namespace Gui;

UNoesisLinearGradientBrush::UNoesisLinearGradientBrush(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisLinearGradientBrush::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::LinearGradientBrush* NoesisLinearGradientBrush = NsDynamicCast<Noesis::Gui::LinearGradientBrush*>(InNoesisComponent);
	check(NoesisLinearGradientBrush);
}

FNoesisDrawingPoint UNoesisLinearGradientBrush::GetEndPoint()
{
	Noesis::Gui::LinearGradientBrush* NoesisLinearGradientBrush = NsDynamicCast<Noesis::Gui::LinearGradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisLinearGradientBrush);
	return FNoesisDrawingPoint(NoesisLinearGradientBrush->GetEndPoint());
}

void UNoesisLinearGradientBrush::SetEndPoint(FNoesisDrawingPoint InEndPoint)
{
	Noesis::Gui::LinearGradientBrush* NoesisLinearGradientBrush = NsDynamicCast<Noesis::Gui::LinearGradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisLinearGradientBrush);
	NoesisLinearGradientBrush->SetEndPoint(InEndPoint.ToNoesis());
}

FNoesisDrawingPoint UNoesisLinearGradientBrush::GetStartPoint()
{
	Noesis::Gui::LinearGradientBrush* NoesisLinearGradientBrush = NsDynamicCast<Noesis::Gui::LinearGradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisLinearGradientBrush);
	return FNoesisDrawingPoint(NoesisLinearGradientBrush->GetStartPoint());
}

void UNoesisLinearGradientBrush::SetStartPoint(FNoesisDrawingPoint InStartPoint)
{
	Noesis::Gui::LinearGradientBrush* NoesisLinearGradientBrush = NsDynamicCast<Noesis::Gui::LinearGradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisLinearGradientBrush);
	NoesisLinearGradientBrush->SetStartPoint(InStartPoint.ToNoesis());
}

void UNoesisLinearGradientBrush::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::LinearGradientBrush* NoesisLinearGradientBrush = NsDynamicCast<Noesis::Gui::LinearGradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisLinearGradientBrush)


}

void UNoesisLinearGradientBrush::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::LinearGradientBrush* NoesisLinearGradientBrush = NsDynamicCast<Noesis::Gui::LinearGradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisLinearGradientBrush)


}

