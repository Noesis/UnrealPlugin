////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiKeyboard.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiKeyboard::UNoesisGuiKeyboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiKeyboard::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Keyboard* NoesisKeyboard = NsDynamicCast<Noesis::Gui::Keyboard*>(InNoesisComponent);
	check(NoesisKeyboard);

}

class UNoesisGuiUIElement* UNoesisGuiKeyboard::Focus(class UNoesisGuiUIElement* InElement)
{
	Noesis::Gui::Keyboard* NoesisKeyboard = NsDynamicCast<Noesis::Gui::Keyboard*>(NoesisComponent.GetPtr());
	check(NoesisKeyboard);
	UIElement* NoesisInElement = NsDynamicCast<UIElement*>(InElement->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiUIElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisKeyboard->Focus(NoesisInElement)));
}

class UNoesisGuiUIElement* UNoesisGuiKeyboard::GetFocused()
{
	Noesis::Gui::Keyboard* NoesisKeyboard = NsDynamicCast<Noesis::Gui::Keyboard*>(NoesisComponent.GetPtr());
	check(NoesisKeyboard);
	return CastChecked<UNoesisGuiUIElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisKeyboard->GetFocused()));
}

int32 UNoesisGuiKeyboard::GetModifiers()
{
	Noesis::Gui::Keyboard* NoesisKeyboard = NsDynamicCast<Noesis::Gui::Keyboard*>(NoesisComponent.GetPtr());
	check(NoesisKeyboard);
	return NoesisKeyboard->GetModifiers();
}

void UNoesisGuiKeyboard::ResetState()
{
	Noesis::Gui::Keyboard* NoesisKeyboard = NsDynamicCast<Noesis::Gui::Keyboard*>(NoesisComponent.GetPtr());
	check(NoesisKeyboard);
	return NoesisKeyboard->ResetState();
}

	void UNoesisGuiKeyboard::BeginDestroy()
{
	Noesis::Gui::Keyboard* NoesisKeyboard = NsDynamicCast<Noesis::Gui::Keyboard*>(NoesisComponent.GetPtr());
	if (!NoesisKeyboard)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

