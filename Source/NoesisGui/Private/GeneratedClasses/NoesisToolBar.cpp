////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisToolBar.h"

using namespace Noesis;
using namespace Gui;

UNoesisToolBar::UNoesisToolBar(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisToolBar::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ToolBar* NoesisToolBar = NsDynamicCast<Noesis::Gui::ToolBar*>(InNoesisComponent);
	check(NoesisToolBar);
}

int32 UNoesisToolBar::GetBand()
{
	Noesis::Gui::ToolBar* NoesisToolBar = NsDynamicCast<Noesis::Gui::ToolBar*>(NoesisComponent.GetPtr());
	check(NoesisToolBar);
	return NoesisToolBar->GetBand();
}

void UNoesisToolBar::SetBand(int32 InBand)
{
	Noesis::Gui::ToolBar* NoesisToolBar = NsDynamicCast<Noesis::Gui::ToolBar*>(NoesisComponent.GetPtr());
	check(NoesisToolBar);
	NoesisToolBar->SetBand(InBand);
}

int32 UNoesisToolBar::GetBandIndex()
{
	Noesis::Gui::ToolBar* NoesisToolBar = NsDynamicCast<Noesis::Gui::ToolBar*>(NoesisComponent.GetPtr());
	check(NoesisToolBar);
	return NoesisToolBar->GetBandIndex();
}

void UNoesisToolBar::SetBandIndex(int32 InBandIndex)
{
	Noesis::Gui::ToolBar* NoesisToolBar = NsDynamicCast<Noesis::Gui::ToolBar*>(NoesisComponent.GetPtr());
	check(NoesisToolBar);
	NoesisToolBar->SetBandIndex(InBandIndex);
}

bool UNoesisToolBar::GetHasOverflowItems()
{
	Noesis::Gui::ToolBar* NoesisToolBar = NsDynamicCast<Noesis::Gui::ToolBar*>(NoesisComponent.GetPtr());
	check(NoesisToolBar);
	return NoesisToolBar->GetHasOverflowItems();
}

bool UNoesisToolBar::GetIsOverflowOpen()
{
	Noesis::Gui::ToolBar* NoesisToolBar = NsDynamicCast<Noesis::Gui::ToolBar*>(NoesisComponent.GetPtr());
	check(NoesisToolBar);
	return NoesisToolBar->GetIsOverflowOpen();
}

void UNoesisToolBar::SetIsOverflowOpen(bool InIsOverflowOpen)
{
	Noesis::Gui::ToolBar* NoesisToolBar = NsDynamicCast<Noesis::Gui::ToolBar*>(NoesisComponent.GetPtr());
	check(NoesisToolBar);
	NoesisToolBar->SetIsOverflowOpen(InIsOverflowOpen);
}

ENoesisOrientation UNoesisToolBar::GetOrientation()
{
	Noesis::Gui::ToolBar* NoesisToolBar = NsDynamicCast<Noesis::Gui::ToolBar*>(NoesisComponent.GetPtr());
	check(NoesisToolBar);
	return (ENoesisOrientation)NoesisToolBar->GetOrientation();
}

void UNoesisToolBar::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ToolBar* NoesisToolBar = NsDynamicCast<Noesis::Gui::ToolBar*>(NoesisComponent.GetPtr());
	check(NoesisToolBar)


}

void UNoesisToolBar::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ToolBar* NoesisToolBar = NsDynamicCast<Noesis::Gui::ToolBar*>(NoesisComponent.GetPtr());
	check(NoesisToolBar)


}

