////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiMenu.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiMenu::UNoesisGuiMenu(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiMenu::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Menu* NoesisMenu = NsDynamicCast<Noesis::Gui::Menu*>(InNoesisComponent);
	check(NoesisMenu);

}

	void UNoesisGuiMenu::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Menu* NoesisMenu = NsDynamicCast<Noesis::Gui::Menu*>(NoesisComponent.GetPtr());
	if (!NoesisMenu)
		return;

}

