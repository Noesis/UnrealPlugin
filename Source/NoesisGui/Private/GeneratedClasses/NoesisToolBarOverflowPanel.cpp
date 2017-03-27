////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisToolBarOverflowPanel.h"

using namespace Noesis;
using namespace Gui;

UNoesisToolBarOverflowPanel::UNoesisToolBarOverflowPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ToolBarOverflowPanel::StaticGetClassType();
}

void UNoesisToolBarOverflowPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ToolBarOverflowPanel* NoesisToolBarOverflowPanel = NsDynamicCast<Noesis::Gui::ToolBarOverflowPanel*>(InNoesisComponent);
	check(NoesisToolBarOverflowPanel);
}

float UNoesisToolBarOverflowPanel::GetWrapWidth()
{
	Noesis::Gui::ToolBarOverflowPanel* NoesisToolBarOverflowPanel = NsDynamicCast<Noesis::Gui::ToolBarOverflowPanel*>(NoesisComponent.GetPtr());
	check(NoesisToolBarOverflowPanel);
	return (float)NoesisToolBarOverflowPanel->GetWrapWidth();
}

void UNoesisToolBarOverflowPanel::SetWrapWidth(float InWrapWidth)
{
	Noesis::Gui::ToolBarOverflowPanel* NoesisToolBarOverflowPanel = NsDynamicCast<Noesis::Gui::ToolBarOverflowPanel*>(NoesisComponent.GetPtr());
	check(NoesisToolBarOverflowPanel);
	NoesisToolBarOverflowPanel->SetWrapWidth(InWrapWidth);
}

void UNoesisToolBarOverflowPanel::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ToolBarOverflowPanel* NoesisToolBarOverflowPanel = NsDynamicCast<Noesis::Gui::ToolBarOverflowPanel*>(NoesisComponent.GetPtr());
	check(NoesisToolBarOverflowPanel);


}

void UNoesisToolBarOverflowPanel::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ToolBarOverflowPanel* NoesisToolBarOverflowPanel = NsDynamicCast<Noesis::Gui::ToolBarOverflowPanel*>(NoesisComponent.GetPtr());
	check(NoesisToolBarOverflowPanel);


}

