////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiVirtualizingPanel.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiVirtualizingPanel::UNoesisGuiVirtualizingPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiVirtualizingPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::VirtualizingPanel* NoesisVirtualizingPanel = NsDynamicCast<Noesis::Gui::VirtualizingPanel*>(InNoesisComponent);
	check(NoesisVirtualizingPanel);

}

	void UNoesisGuiVirtualizingPanel::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::VirtualizingPanel* NoesisVirtualizingPanel = NsDynamicCast<Noesis::Gui::VirtualizingPanel*>(NoesisComponent.GetPtr());
	if (!NoesisVirtualizingPanel)
		return;

}

