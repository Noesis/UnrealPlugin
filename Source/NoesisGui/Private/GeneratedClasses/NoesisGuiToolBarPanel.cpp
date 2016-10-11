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

	void UNoesisGuiToolBarPanel::BeginDestroy()
{
	Noesis::Gui::ToolBarPanel* NoesisToolBarPanel = NsDynamicCast<Noesis::Gui::ToolBarPanel*>(NoesisComponent.GetPtr());
	if (!NoesisToolBarPanel)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

