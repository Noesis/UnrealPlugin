////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisTileBrush.h"

using namespace Noesis;
using namespace Gui;

UNoesisTileBrush::UNoesisTileBrush(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisTileBrush::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(InNoesisComponent);
	check(NoesisTileBrush);
}

ENoesisAlignmentX UNoesisTileBrush::GetAlignmentX()
{
	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	check(NoesisTileBrush);
	return (ENoesisAlignmentX)NoesisTileBrush->GetAlignmentX();
}

void UNoesisTileBrush::SetAlignmentX(ENoesisAlignmentX InAlignmentX)
{
	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	check(NoesisTileBrush);
	NoesisTileBrush->SetAlignmentX((Noesis::Gui::AlignmentX)InAlignmentX);
}

ENoesisAlignmentY UNoesisTileBrush::GetAlignmentY()
{
	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	check(NoesisTileBrush);
	return (ENoesisAlignmentY)NoesisTileBrush->GetAlignmentY();
}

void UNoesisTileBrush::SetAlignmentY(ENoesisAlignmentY InAlignmentY)
{
	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	check(NoesisTileBrush);
	NoesisTileBrush->SetAlignmentY((Noesis::Gui::AlignmentY)InAlignmentY);
}

ENoesisStretch UNoesisTileBrush::GetStretch()
{
	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	check(NoesisTileBrush);
	return (ENoesisStretch)NoesisTileBrush->GetStretch();
}

void UNoesisTileBrush::SetStretch(ENoesisStretch InStretch)
{
	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	check(NoesisTileBrush);
	NoesisTileBrush->SetStretch((Noesis::Gui::Stretch)InStretch);
}

ENoesisTileMode UNoesisTileBrush::GetTileMode()
{
	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	check(NoesisTileBrush);
	return (ENoesisTileMode)NoesisTileBrush->GetTileMode();
}

void UNoesisTileBrush::SetTileMode(ENoesisTileMode InTileMode)
{
	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	check(NoesisTileBrush);
	NoesisTileBrush->SetTileMode((Noesis::Gui::TileMode)InTileMode);
}

FNoesisDrawingRect UNoesisTileBrush::GetViewbox()
{
	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	check(NoesisTileBrush);
	return FNoesisDrawingRect(NoesisTileBrush->GetViewbox());
}

void UNoesisTileBrush::SetViewbox(FNoesisDrawingRect InViewbox)
{
	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	check(NoesisTileBrush);
	NoesisTileBrush->SetViewbox(InViewbox.ToNoesis());
}

ENoesisBrushMappingMode UNoesisTileBrush::GetViewboxUnits()
{
	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	check(NoesisTileBrush);
	return (ENoesisBrushMappingMode)NoesisTileBrush->GetViewboxUnits();
}

void UNoesisTileBrush::SetViewboxUnits(ENoesisBrushMappingMode InViewboxUnits)
{
	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	check(NoesisTileBrush);
	NoesisTileBrush->SetViewboxUnits((Noesis::Gui::BrushMappingMode)InViewboxUnits);
}

FNoesisDrawingRect UNoesisTileBrush::GetViewport()
{
	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	check(NoesisTileBrush);
	return FNoesisDrawingRect(NoesisTileBrush->GetViewport());
}

void UNoesisTileBrush::SetViewport(FNoesisDrawingRect InViewport)
{
	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	check(NoesisTileBrush);
	NoesisTileBrush->SetViewport(InViewport.ToNoesis());
}

ENoesisBrushMappingMode UNoesisTileBrush::GetViewportUnits()
{
	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	check(NoesisTileBrush);
	return (ENoesisBrushMappingMode)NoesisTileBrush->GetViewportUnits();
}

void UNoesisTileBrush::SetViewportUnits(ENoesisBrushMappingMode InViewportUnits)
{
	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	check(NoesisTileBrush);
	NoesisTileBrush->SetViewportUnits((Noesis::Gui::BrushMappingMode)InViewportUnits);
}

void UNoesisTileBrush::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	check(NoesisTileBrush)


}

void UNoesisTileBrush::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	check(NoesisTileBrush)


}

