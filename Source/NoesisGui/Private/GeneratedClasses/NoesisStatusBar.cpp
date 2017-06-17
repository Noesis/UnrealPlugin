////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisStatusBar.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisStatusBar::UNoesisStatusBar(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::StatusBar::StaticGetClassType();
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
	check(NoesisStatusBar);


}

void UNoesisStatusBar::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::StatusBar* NoesisStatusBar = NsDynamicCast<Noesis::Gui::StatusBar*>(NoesisComponent.GetPtr());
	check(NoesisStatusBar);


}

