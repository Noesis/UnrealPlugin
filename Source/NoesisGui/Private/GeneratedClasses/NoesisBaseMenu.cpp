////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisBaseMenu.h"

using namespace Noesis;
using namespace Gui;

UNoesisBaseMenu::UNoesisBaseMenu(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisBaseMenu::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseMenu* NoesisBaseMenu = NsDynamicCast<Noesis::Gui::BaseMenu*>(InNoesisComponent);
	check(NoesisBaseMenu);
}

void UNoesisBaseMenu::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseMenu* NoesisBaseMenu = NsDynamicCast<Noesis::Gui::BaseMenu*>(NoesisComponent.GetPtr());
	check(NoesisBaseMenu)


}

void UNoesisBaseMenu::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseMenu* NoesisBaseMenu = NsDynamicCast<Noesis::Gui::BaseMenu*>(NoesisComponent.GetPtr());
	check(NoesisBaseMenu)


}

