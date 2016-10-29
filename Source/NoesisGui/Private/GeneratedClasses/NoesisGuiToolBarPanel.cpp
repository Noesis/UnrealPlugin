////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiToolBarPanel.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiToolBarPanel::UNoesisGuiToolBarPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiToolBarPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ToolBarPanel* NoesisToolBarPanel = NsDynamicCast<Noesis::Gui::ToolBarPanel*>(InNoesisComponent);
	check(NoesisToolBarPanel);
}

void UNoesisGuiToolBarPanel::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ToolBarPanel* NoesisToolBarPanel = NsDynamicCast<Noesis::Gui::ToolBarPanel*>(NoesisComponent.GetPtr());
	check(NoesisToolBarPanel)


}

void UNoesisGuiToolBarPanel::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ToolBarPanel* NoesisToolBarPanel = NsDynamicCast<Noesis::Gui::ToolBarPanel*>(NoesisComponent.GetPtr());
	check(NoesisToolBarPanel)


}

