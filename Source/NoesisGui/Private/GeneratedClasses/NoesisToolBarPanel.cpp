////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisToolBarPanel.h"

using namespace Noesis;
using namespace Gui;

UNoesisToolBarPanel::UNoesisToolBarPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ToolBarPanel::StaticGetClassType();
}

void UNoesisToolBarPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ToolBarPanel* NoesisToolBarPanel = NsDynamicCast<Noesis::Gui::ToolBarPanel*>(InNoesisComponent);
	check(NoesisToolBarPanel);
}

void UNoesisToolBarPanel::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ToolBarPanel* NoesisToolBarPanel = NsDynamicCast<Noesis::Gui::ToolBarPanel*>(NoesisComponent.GetPtr());
	check(NoesisToolBarPanel);


}

void UNoesisToolBarPanel::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ToolBarPanel* NoesisToolBarPanel = NsDynamicCast<Noesis::Gui::ToolBarPanel*>(NoesisComponent.GetPtr());
	check(NoesisToolBarPanel);


}

