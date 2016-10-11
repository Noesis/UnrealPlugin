////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiToolBarTray.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiToolBarTray::UNoesisGuiToolBarTray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiToolBarTray::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ToolBarTray* NoesisToolBarTray = NsDynamicCast<Noesis::Gui::ToolBarTray*>(InNoesisComponent);
	check(NoesisToolBarTray);

}

	void UNoesisGuiToolBarTray::BeginDestroy()
{
	Noesis::Gui::ToolBarTray* NoesisToolBarTray = NsDynamicCast<Noesis::Gui::ToolBarTray*>(NoesisComponent.GetPtr());
	if (!NoesisToolBarTray)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

