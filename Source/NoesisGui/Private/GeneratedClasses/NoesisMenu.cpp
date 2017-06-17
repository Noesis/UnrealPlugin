////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisMenu.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisMenu::UNoesisMenu(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Menu::StaticGetClassType();
}

void UNoesisMenu::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Menu* NoesisMenu = NsDynamicCast<Noesis::Gui::Menu*>(InNoesisComponent);
	check(NoesisMenu);
}

bool UNoesisMenu::GetIsMainMenu()
{
	Noesis::Gui::Menu* NoesisMenu = NsDynamicCast<Noesis::Gui::Menu*>(NoesisComponent.GetPtr());
	check(NoesisMenu);
	return NoesisMenu->GetIsMainMenu();
}

void UNoesisMenu::SetIsMainMenu(bool InIsMainMenu)
{
	Noesis::Gui::Menu* NoesisMenu = NsDynamicCast<Noesis::Gui::Menu*>(NoesisComponent.GetPtr());
	check(NoesisMenu);
	NoesisMenu->SetIsMainMenu(InIsMainMenu);
}

bool UNoesisMenu::GetActivated()
{
	Noesis::Gui::Menu* NoesisMenu = NsDynamicCast<Noesis::Gui::Menu*>(NoesisComponent.GetPtr());
	check(NoesisMenu);
	return NoesisMenu->GetActivated();
}

void UNoesisMenu::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Menu* NoesisMenu = NsDynamicCast<Noesis::Gui::Menu*>(NoesisComponent.GetPtr());
	check(NoesisMenu);


}

void UNoesisMenu::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Menu* NoesisMenu = NsDynamicCast<Noesis::Gui::Menu*>(NoesisComponent.GetPtr());
	check(NoesisMenu);


}

