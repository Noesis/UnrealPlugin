////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisStatusBar.h"

using namespace Noesis;
using namespace Gui;

UNoesisStatusBar::UNoesisStatusBar(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisStatusBar::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::StatusBar* NoesisStatusBar = NsDynamicCast<Noesis::Gui::StatusBar*>(InNoesisComponent);
	check(NoesisStatusBar);
}

void UNoesisStatusBar::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::StatusBar* NoesisStatusBar = NsDynamicCast<Noesis::Gui::StatusBar*>(NoesisComponent.GetPtr());
	check(NoesisStatusBar)


}

void UNoesisStatusBar::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::StatusBar* NoesisStatusBar = NsDynamicCast<Noesis::Gui::StatusBar*>(NoesisComponent.GetPtr());
	check(NoesisStatusBar)


}

