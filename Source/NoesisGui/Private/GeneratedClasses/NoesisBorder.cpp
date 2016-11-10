////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisBorder.h"

using namespace Noesis;
using namespace Gui;

UNoesisBorder::UNoesisBorder(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisBorder::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Border* NoesisBorder = NsDynamicCast<Noesis::Gui::Border*>(InNoesisComponent);
	check(NoesisBorder);
}

class UNoesisBrush* UNoesisBorder::GetBackground()
{
	Noesis::Gui::Border* NoesisBorder = NsDynamicCast<Noesis::Gui::Border*>(NoesisComponent.GetPtr());
	check(NoesisBorder);
	return CastChecked<UNoesisBrush>(Instance->FindUnrealComponentForNoesisComponent(NoesisBorder->GetBackground()));
}

void UNoesisBorder::SetBackground(class UNoesisBrush* InBackground)
{
	Noesis::Gui::Border* NoesisBorder = NsDynamicCast<Noesis::Gui::Border*>(NoesisComponent.GetPtr());
	check(NoesisBorder);
	NoesisBorder->SetBackground(NsDynamicCast<Brush*>(InBackground->NoesisComponent.GetPtr()));
}

class UNoesisBrush* UNoesisBorder::GetBorderBrush()
{
	Noesis::Gui::Border* NoesisBorder = NsDynamicCast<Noesis::Gui::Border*>(NoesisComponent.GetPtr());
	check(NoesisBorder);
	return CastChecked<UNoesisBrush>(Instance->FindUnrealComponentForNoesisComponent(NoesisBorder->GetBorderBrush()));
}

void UNoesisBorder::SetBorderBrush(class UNoesisBrush* InBorderBrush)
{
	Noesis::Gui::Border* NoesisBorder = NsDynamicCast<Noesis::Gui::Border*>(NoesisComponent.GetPtr());
	check(NoesisBorder);
	NoesisBorder->SetBorderBrush(NsDynamicCast<Brush*>(InBorderBrush->NoesisComponent.GetPtr()));
}

FNoesisDrawingThickness UNoesisBorder::GetBorderThickness()
{
	Noesis::Gui::Border* NoesisBorder = NsDynamicCast<Noesis::Gui::Border*>(NoesisComponent.GetPtr());
	check(NoesisBorder);
	return FNoesisDrawingThickness(NoesisBorder->GetBorderThickness());
}

void UNoesisBorder::SetBorderThickness(FNoesisDrawingThickness InBorderThickness)
{
	Noesis::Gui::Border* NoesisBorder = NsDynamicCast<Noesis::Gui::Border*>(NoesisComponent.GetPtr());
	check(NoesisBorder);
	NoesisBorder->SetBorderThickness(InBorderThickness.ToNoesis());
}

FNoesisDrawingCornerRadius UNoesisBorder::GetCornerRadius()
{
	Noesis::Gui::Border* NoesisBorder = NsDynamicCast<Noesis::Gui::Border*>(NoesisComponent.GetPtr());
	check(NoesisBorder);
	return FNoesisDrawingCornerRadius(NoesisBorder->GetCornerRadius());
}

void UNoesisBorder::SetCornerRadius(FNoesisDrawingCornerRadius InCornerRadius)
{
	Noesis::Gui::Border* NoesisBorder = NsDynamicCast<Noesis::Gui::Border*>(NoesisComponent.GetPtr());
	check(NoesisBorder);
	NoesisBorder->SetCornerRadius(InCornerRadius.ToNoesis());
}

FNoesisDrawingThickness UNoesisBorder::GetPadding()
{
	Noesis::Gui::Border* NoesisBorder = NsDynamicCast<Noesis::Gui::Border*>(NoesisComponent.GetPtr());
	check(NoesisBorder);
	return FNoesisDrawingThickness(NoesisBorder->GetPadding());
}

void UNoesisBorder::SetPadding(FNoesisDrawingThickness InPadding)
{
	Noesis::Gui::Border* NoesisBorder = NsDynamicCast<Noesis::Gui::Border*>(NoesisComponent.GetPtr());
	check(NoesisBorder);
	NoesisBorder->SetPadding(InPadding.ToNoesis());
}

void UNoesisBorder::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Border* NoesisBorder = NsDynamicCast<Noesis::Gui::Border*>(NoesisComponent.GetPtr());
	check(NoesisBorder)


}

void UNoesisBorder::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Border* NoesisBorder = NsDynamicCast<Noesis::Gui::Border*>(NoesisComponent.GetPtr());
	check(NoesisBorder)


}

