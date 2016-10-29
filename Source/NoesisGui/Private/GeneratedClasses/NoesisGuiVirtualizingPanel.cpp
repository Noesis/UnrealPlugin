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

void UNoesisGuiVirtualizingPanel::BringIndexIntoView(int32 InIndex)
{
	Noesis::Gui::VirtualizingPanel* NoesisVirtualizingPanel = NsDynamicCast<Noesis::Gui::VirtualizingPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingPanel);
	NsInt32 NoesisInIndex = InIndex;
	return NoesisVirtualizingPanel->BringIndexIntoView(NoesisInIndex);
}

class UNoesisGuiIItemContainerGenerator* UNoesisGuiVirtualizingPanel::GetItemContainerGenerator()
{
	Noesis::Gui::VirtualizingPanel* NoesisVirtualizingPanel = NsDynamicCast<Noesis::Gui::VirtualizingPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingPanel);
	return CastChecked<UNoesisGuiIItemContainerGenerator>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisVirtualizingPanel->GetItemContainerGenerator()));
}

void UNoesisGuiVirtualizingPanel::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::VirtualizingPanel* NoesisVirtualizingPanel = NsDynamicCast<Noesis::Gui::VirtualizingPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingPanel)


}

void UNoesisGuiVirtualizingPanel::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::VirtualizingPanel* NoesisVirtualizingPanel = NsDynamicCast<Noesis::Gui::VirtualizingPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingPanel)


}

