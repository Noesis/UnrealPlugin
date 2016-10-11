////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiToolBar.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiToolBar::UNoesisGuiToolBar(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiToolBar::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ToolBar* NoesisToolBar = NsDynamicCast<Noesis::Gui::ToolBar*>(InNoesisComponent);
	check(NoesisToolBar);

}

	void UNoesisGuiToolBar::BeginDestroy()
{
	Noesis::Gui::ToolBar* NoesisToolBar = NsDynamicCast<Noesis::Gui::ToolBar*>(NoesisComponent.GetPtr());
	if (!NoesisToolBar)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

