////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisPen.h"

using namespace Noesis;
using namespace Gui;

UNoesisPen::UNoesisPen(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisPen::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(InNoesisComponent);
	check(NoesisPen);
}

class UNoesisBrush* UNoesisPen::GetBrush()
{
	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen);
	return CastChecked<UNoesisBrush>(Instance->FindUnrealComponentForNoesisComponent(NoesisPen->GetBrush()));
}

void UNoesisPen::SetBrush(class UNoesisBrush* InBrush)
{
	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen);
	NoesisPen->SetBrush(NsDynamicCast<Brush*>(InBrush->NoesisComponent.GetPtr()));
}

ENoesisPenLineCap UNoesisPen::GetDashCap()
{
	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen);
	return (ENoesisPenLineCap)NoesisPen->GetDashCap();
}

void UNoesisPen::SetDashCap(ENoesisPenLineCap InDashCap)
{
	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen);
	NoesisPen->SetDashCap((Noesis::Gui::PenLineCap)InDashCap);
}

class UNoesisDashStyle* UNoesisPen::GetDashStyle()
{
	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen);
	return CastChecked<UNoesisDashStyle>(Instance->FindUnrealComponentForNoesisComponent(NoesisPen->GetDashStyle()));
}

void UNoesisPen::SetDashStyle(class UNoesisDashStyle* InDashStyle)
{
	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen);
	NoesisPen->SetDashStyle(NsDynamicCast<DashStyle*>(InDashStyle->NoesisComponent.GetPtr()));
}

ENoesisPenLineCap UNoesisPen::GetEndLineCap()
{
	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen);
	return (ENoesisPenLineCap)NoesisPen->GetEndLineCap();
}

void UNoesisPen::SetEndLineCap(ENoesisPenLineCap InEndLineCap)
{
	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen);
	NoesisPen->SetEndLineCap((Noesis::Gui::PenLineCap)InEndLineCap);
}

ENoesisPenLineJoin UNoesisPen::GetLineJoin()
{
	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen);
	return (ENoesisPenLineJoin)NoesisPen->GetLineJoin();
}

void UNoesisPen::SetLineJoin(ENoesisPenLineJoin InLineJoin)
{
	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen);
	NoesisPen->SetLineJoin((Noesis::Gui::PenLineJoin)InLineJoin);
}

float UNoesisPen::GetMiterLimit()
{
	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen);
	return (float)NoesisPen->GetMiterLimit();
}

void UNoesisPen::SetMiterLimit(float InMiterLimit)
{
	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen);
	NoesisPen->SetMiterLimit(InMiterLimit);
}

ENoesisPenLineCap UNoesisPen::GetStartLineCap()
{
	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen);
	return (ENoesisPenLineCap)NoesisPen->GetStartLineCap();
}

void UNoesisPen::SetStartLineCap(ENoesisPenLineCap InStartLineCap)
{
	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen);
	NoesisPen->SetStartLineCap((Noesis::Gui::PenLineCap)InStartLineCap);
}

float UNoesisPen::GetThickness()
{
	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen);
	return (float)NoesisPen->GetThickness();
}

void UNoesisPen::SetThickness(float InThickness)
{
	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen);
	NoesisPen->SetThickness(InThickness);
}

bool UNoesisPen::IsRenderable()
{
	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen);
	return NoesisPen->IsRenderable();
}

void UNoesisPen::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen)


}

void UNoesisPen::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Pen* NoesisPen = NsDynamicCast<Noesis::Gui::Pen*>(NoesisComponent.GetPtr());
	check(NoesisPen)


}

