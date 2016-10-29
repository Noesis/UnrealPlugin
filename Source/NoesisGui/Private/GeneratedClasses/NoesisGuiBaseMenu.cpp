////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseMenu.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseMenu::UNoesisGuiBaseMenu(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseMenu::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseMenu* NoesisBaseMenu = NsDynamicCast<Noesis::Gui::BaseMenu*>(InNoesisComponent);
	check(NoesisBaseMenu);
}

void UNoesisGuiBaseMenu::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseMenu* NoesisBaseMenu = NsDynamicCast<Noesis::Gui::BaseMenu*>(NoesisComponent.GetPtr());
	check(NoesisBaseMenu)


}

void UNoesisGuiBaseMenu::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseMenu* NoesisBaseMenu = NsDynamicCast<Noesis::Gui::BaseMenu*>(NoesisComponent.GetPtr());
	check(NoesisBaseMenu)


}

