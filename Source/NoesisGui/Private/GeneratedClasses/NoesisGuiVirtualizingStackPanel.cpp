////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiVirtualizingStackPanel.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiVirtualizingStackPanel::UNoesisGuiVirtualizingStackPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiVirtualizingStackPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(InNoesisComponent);
	check(NoesisVirtualizingStackPanel);

}

	void UNoesisGuiVirtualizingStackPanel::BeginDestroy()
{
	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	if (!NoesisVirtualizingStackPanel)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

