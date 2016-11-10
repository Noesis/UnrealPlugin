////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisToolBarTray.h"

using namespace Noesis;
using namespace Gui;

UNoesisToolBarTray::UNoesisToolBarTray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisToolBarTray::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ToolBarTray* NoesisToolBarTray = NsDynamicCast<Noesis::Gui::ToolBarTray*>(InNoesisComponent);
	check(NoesisToolBarTray);
}

class UNoesisBrush* UNoesisToolBarTray::GetBackground()
{
	Noesis::Gui::ToolBarTray* NoesisToolBarTray = NsDynamicCast<Noesis::Gui::ToolBarTray*>(NoesisComponent.GetPtr());
	check(NoesisToolBarTray);
	return CastChecked<UNoesisBrush>(Instance->FindUnrealComponentForNoesisComponent(NoesisToolBarTray->GetBackground()));
}

void UNoesisToolBarTray::SetBackground(class UNoesisBrush* InBackground)
{
	Noesis::Gui::ToolBarTray* NoesisToolBarTray = NsDynamicCast<Noesis::Gui::ToolBarTray*>(NoesisComponent.GetPtr());
	check(NoesisToolBarTray);
	NoesisToolBarTray->SetBackground(NsDynamicCast<Brush*>(InBackground->NoesisComponent.GetPtr()));
}

ENoesisOrientation UNoesisToolBarTray::GetOrientation()
{
	Noesis::Gui::ToolBarTray* NoesisToolBarTray = NsDynamicCast<Noesis::Gui::ToolBarTray*>(NoesisComponent.GetPtr());
	check(NoesisToolBarTray);
	return (ENoesisOrientation)NoesisToolBarTray->GetOrientation();
}

void UNoesisToolBarTray::SetOrientation(ENoesisOrientation InOrientation)
{
	Noesis::Gui::ToolBarTray* NoesisToolBarTray = NsDynamicCast<Noesis::Gui::ToolBarTray*>(NoesisComponent.GetPtr());
	check(NoesisToolBarTray);
	NoesisToolBarTray->SetOrientation((Noesis::Gui::Orientation)InOrientation);
}

void UNoesisToolBarTray::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ToolBarTray* NoesisToolBarTray = NsDynamicCast<Noesis::Gui::ToolBarTray*>(NoesisComponent.GetPtr());
	check(NoesisToolBarTray)


}

void UNoesisToolBarTray::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ToolBarTray* NoesisToolBarTray = NsDynamicCast<Noesis::Gui::ToolBarTray*>(NoesisComponent.GetPtr());
	check(NoesisToolBarTray)


}

