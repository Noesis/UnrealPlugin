////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTabControl.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTabControl::UNoesisGuiTabControl(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTabControl::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TabControl* NoesisTabControl = NsDynamicCast<Noesis::Gui::TabControl*>(InNoesisComponent);
	check(NoesisTabControl);

}

	void UNoesisGuiTabControl::BeginDestroy()
{
	Noesis::Gui::TabControl* NoesisTabControl = NsDynamicCast<Noesis::Gui::TabControl*>(NoesisComponent.GetPtr());
	if (!NoesisTabControl)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

