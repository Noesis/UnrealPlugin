////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiWrapPanel.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiWrapPanel::UNoesisGuiWrapPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiWrapPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::WrapPanel* NoesisWrapPanel = NsDynamicCast<Noesis::Gui::WrapPanel*>(InNoesisComponent);
	check(NoesisWrapPanel);
}

void UNoesisGuiWrapPanel::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::WrapPanel* NoesisWrapPanel = NsDynamicCast<Noesis::Gui::WrapPanel*>(NoesisComponent.GetPtr());
	check(NoesisWrapPanel)


}

void UNoesisGuiWrapPanel::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::WrapPanel* NoesisWrapPanel = NsDynamicCast<Noesis::Gui::WrapPanel*>(NoesisComponent.GetPtr());
	check(NoesisWrapPanel)


}

