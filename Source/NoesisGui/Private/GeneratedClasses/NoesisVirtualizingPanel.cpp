////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisVirtualizingPanel.h"

using namespace Noesis;
using namespace Gui;

UNoesisVirtualizingPanel::UNoesisVirtualizingPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisVirtualizingPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::VirtualizingPanel* NoesisVirtualizingPanel = NsDynamicCast<Noesis::Gui::VirtualizingPanel*>(InNoesisComponent);
	check(NoesisVirtualizingPanel);
}

void UNoesisVirtualizingPanel::BringIndexIntoView(int32 InIndex)
{
	Noesis::Gui::VirtualizingPanel* NoesisVirtualizingPanel = NsDynamicCast<Noesis::Gui::VirtualizingPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingPanel);
	NsInt32 NoesisInIndex = InIndex;
	return NoesisVirtualizingPanel->BringIndexIntoView(NoesisInIndex);
}

class UNoesisIItemContainerGenerator* UNoesisVirtualizingPanel::GetItemContainerGenerator()
{
	Noesis::Gui::VirtualizingPanel* NoesisVirtualizingPanel = NsDynamicCast<Noesis::Gui::VirtualizingPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingPanel);
	return CastChecked<UNoesisIItemContainerGenerator>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisVirtualizingPanel->GetItemContainerGenerator()));
}

void UNoesisVirtualizingPanel::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::VirtualizingPanel* NoesisVirtualizingPanel = NsDynamicCast<Noesis::Gui::VirtualizingPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingPanel)


}

void UNoesisVirtualizingPanel::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::VirtualizingPanel* NoesisVirtualizingPanel = NsDynamicCast<Noesis::Gui::VirtualizingPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingPanel)


}

