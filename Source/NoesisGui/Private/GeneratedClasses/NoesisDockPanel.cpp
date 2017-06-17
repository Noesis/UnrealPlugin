////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisDockPanel.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisDockPanel::UNoesisDockPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::DockPanel::StaticGetClassType();
}

void UNoesisDockPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DockPanel* NoesisDockPanel = NsDynamicCast<Noesis::Gui::DockPanel*>(InNoesisComponent);
	check(NoesisDockPanel);
}

bool UNoesisDockPanel::GetLastChildFill()
{
	Noesis::Gui::DockPanel* NoesisDockPanel = NsDynamicCast<Noesis::Gui::DockPanel*>(NoesisComponent.GetPtr());
	check(NoesisDockPanel);
	return NoesisDockPanel->GetLastChildFill();
}

void UNoesisDockPanel::SetLastChildFill(bool InLastChildFill)
{
	Noesis::Gui::DockPanel* NoesisDockPanel = NsDynamicCast<Noesis::Gui::DockPanel*>(NoesisComponent.GetPtr());
	check(NoesisDockPanel);
	NoesisDockPanel->SetLastChildFill(InLastChildFill);
}

void UNoesisDockPanel::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DockPanel* NoesisDockPanel = NsDynamicCast<Noesis::Gui::DockPanel*>(NoesisComponent.GetPtr());
	check(NoesisDockPanel);


}

void UNoesisDockPanel::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DockPanel* NoesisDockPanel = NsDynamicCast<Noesis::Gui::DockPanel*>(NoesisComponent.GetPtr());
	check(NoesisDockPanel);


}

