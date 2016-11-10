////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGradientStop.h"

using namespace Noesis;
using namespace Gui;

UNoesisGradientStop::UNoesisGradientStop(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGradientStop::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::GradientStop* NoesisGradientStop = NsDynamicCast<Noesis::Gui::GradientStop*>(InNoesisComponent);
	check(NoesisGradientStop);
}

FNoesisDrawingColor UNoesisGradientStop::GetColor()
{
	Noesis::Gui::GradientStop* NoesisGradientStop = NsDynamicCast<Noesis::Gui::GradientStop*>(NoesisComponent.GetPtr());
	check(NoesisGradientStop);
	return FNoesisDrawingColor(NoesisGradientStop->GetColor());
}

void UNoesisGradientStop::SetColor(FNoesisDrawingColor InColor)
{
	Noesis::Gui::GradientStop* NoesisGradientStop = NsDynamicCast<Noesis::Gui::GradientStop*>(NoesisComponent.GetPtr());
	check(NoesisGradientStop);
	NoesisGradientStop->SetColor(InColor.ToNoesis());
}

float UNoesisGradientStop::GetOffset()
{
	Noesis::Gui::GradientStop* NoesisGradientStop = NsDynamicCast<Noesis::Gui::GradientStop*>(NoesisComponent.GetPtr());
	check(NoesisGradientStop);
	return (float)NoesisGradientStop->GetOffset();
}

void UNoesisGradientStop::SetOffset(float InOffset)
{
	Noesis::Gui::GradientStop* NoesisGradientStop = NsDynamicCast<Noesis::Gui::GradientStop*>(NoesisComponent.GetPtr());
	check(NoesisGradientStop);
	NoesisGradientStop->SetOffset(InOffset);
}

void UNoesisGradientStop::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::GradientStop* NoesisGradientStop = NsDynamicCast<Noesis::Gui::GradientStop*>(NoesisComponent.GetPtr());
	check(NoesisGradientStop)


}

void UNoesisGradientStop::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::GradientStop* NoesisGradientStop = NsDynamicCast<Noesis::Gui::GradientStop*>(NoesisComponent.GetPtr());
	check(NoesisGradientStop)


}

