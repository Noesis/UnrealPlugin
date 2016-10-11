////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiStatusBar.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiStatusBar::UNoesisGuiStatusBar(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiStatusBar::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::StatusBar* NoesisStatusBar = NsDynamicCast<Noesis::Gui::StatusBar*>(InNoesisComponent);
	check(NoesisStatusBar);

}

	void UNoesisGuiStatusBar::BeginDestroy()
{
	Noesis::Gui::StatusBar* NoesisStatusBar = NsDynamicCast<Noesis::Gui::StatusBar*>(NoesisComponent.GetPtr());
	if (!NoesisStatusBar)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

