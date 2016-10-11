////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiToolBarOverflowPanel.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiToolBarOverflowPanel::UNoesisGuiToolBarOverflowPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiToolBarOverflowPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ToolBarOverflowPanel* NoesisToolBarOverflowPanel = NsDynamicCast<Noesis::Gui::ToolBarOverflowPanel*>(InNoesisComponent);
	check(NoesisToolBarOverflowPanel);

}

	void UNoesisGuiToolBarOverflowPanel::BeginDestroy()
{
	Noesis::Gui::ToolBarOverflowPanel* NoesisToolBarOverflowPanel = NsDynamicCast<Noesis::Gui::ToolBarOverflowPanel*>(NoesisComponent.GetPtr());
	if (!NoesisToolBarOverflowPanel)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

