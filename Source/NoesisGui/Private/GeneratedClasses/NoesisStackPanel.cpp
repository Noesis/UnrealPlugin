////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisStackPanel.h"

using namespace Noesis;
using namespace Gui;

UNoesisStackPanel::UNoesisStackPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisStackPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(InNoesisComponent);
	check(NoesisStackPanel);
}

ENoesisOrientation UNoesisStackPanel::GetOrientation()
{
	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel);
	return (ENoesisOrientation)NoesisStackPanel->GetOrientation();
}

void UNoesisStackPanel::SetOrientation(ENoesisOrientation InOrientation)
{
	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel);
	NoesisStackPanel->SetOrientation((Noesis::Gui::Orientation)InOrientation);
}

void UNoesisStackPanel::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel)


}

void UNoesisStackPanel::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel)


}

