////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDockPanel.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDockPanel::UNoesisGuiDockPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDockPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DockPanel* NoesisDockPanel = NsDynamicCast<Noesis::Gui::DockPanel*>(InNoesisComponent);
	check(NoesisDockPanel);
}

void UNoesisGuiDockPanel::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DockPanel* NoesisDockPanel = NsDynamicCast<Noesis::Gui::DockPanel*>(NoesisComponent.GetPtr());
	check(NoesisDockPanel)


}

void UNoesisGuiDockPanel::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DockPanel* NoesisDockPanel = NsDynamicCast<Noesis::Gui::DockPanel*>(NoesisComponent.GetPtr());
	check(NoesisDockPanel)


}

