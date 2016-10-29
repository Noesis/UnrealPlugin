////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiMouse.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiMouse::UNoesisGuiMouse(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiMouse::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Mouse* NoesisMouse = NsDynamicCast<Noesis::Gui::Mouse*>(InNoesisComponent);
	check(NoesisMouse);
}

class UNoesisGuiUIElement* UNoesisGuiMouse::GetCaptured()
{
	Noesis::Gui::Mouse* NoesisMouse = NsDynamicCast<Noesis::Gui::Mouse*>(NoesisComponent.GetPtr());
	check(NoesisMouse);
	return CastChecked<UNoesisGuiUIElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisMouse->GetCaptured()));
}

FNoesisGuiDrawingPoint UNoesisGuiMouse::GetPosition()
{
	Noesis::Gui::Mouse* NoesisMouse = NsDynamicCast<Noesis::Gui::Mouse*>(NoesisComponent.GetPtr());
	check(NoesisMouse);
	return FNoesisGuiDrawingPoint(NoesisMouse->GetPosition());
}

void UNoesisGuiMouse::ResetState()
{
	Noesis::Gui::Mouse* NoesisMouse = NsDynamicCast<Noesis::Gui::Mouse*>(NoesisComponent.GetPtr());
	check(NoesisMouse);
	return NoesisMouse->ResetState();
}

void UNoesisGuiMouse::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Mouse* NoesisMouse = NsDynamicCast<Noesis::Gui::Mouse*>(NoesisComponent.GetPtr());
	check(NoesisMouse)


}

void UNoesisGuiMouse::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Mouse* NoesisMouse = NsDynamicCast<Noesis::Gui::Mouse*>(NoesisComponent.GetPtr());
	check(NoesisMouse)


}

