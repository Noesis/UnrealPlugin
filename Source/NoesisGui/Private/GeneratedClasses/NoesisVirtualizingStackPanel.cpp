////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisVirtualizingStackPanel.h"

using namespace Noesis;
using namespace Gui;

UNoesisVirtualizingStackPanel::UNoesisVirtualizingStackPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::VirtualizingStackPanel::StaticGetClassType();
}

void UNoesisVirtualizingStackPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(InNoesisComponent);
	check(NoesisVirtualizingStackPanel);
}

ENoesisOrientation UNoesisVirtualizingStackPanel::GetOrientation()
{
	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingStackPanel);
	return (ENoesisOrientation)NoesisVirtualizingStackPanel->GetOrientation();
}

void UNoesisVirtualizingStackPanel::SetOrientation(ENoesisOrientation InOrientation)
{
	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingStackPanel);
	NoesisVirtualizingStackPanel->SetOrientation((Noesis::Gui::Orientation)InOrientation);
}

void UNoesisVirtualizingStackPanel::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingStackPanel);


}

void UNoesisVirtualizingStackPanel::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingStackPanel);


}

