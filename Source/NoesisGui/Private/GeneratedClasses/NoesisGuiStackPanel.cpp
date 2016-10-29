////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiStackPanel.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiStackPanel::UNoesisGuiStackPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiStackPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(InNoesisComponent);
	check(NoesisStackPanel);
}

void UNoesisGuiStackPanel::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel)


}

void UNoesisGuiStackPanel::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel)


}

