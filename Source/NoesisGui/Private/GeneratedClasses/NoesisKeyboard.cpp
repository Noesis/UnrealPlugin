////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisKeyboard.h"

using namespace Noesis;
using namespace Gui;

UNoesisKeyboard::UNoesisKeyboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Keyboard::StaticGetClassType();
}

void UNoesisKeyboard::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Keyboard* NoesisKeyboard = NsDynamicCast<Noesis::Gui::Keyboard*>(InNoesisComponent);
	check(NoesisKeyboard);
}

class UNoesisUIElement* UNoesisKeyboard::Focus(class UNoesisUIElement* InElement)
{
	Noesis::Gui::Keyboard* NoesisKeyboard = NsDynamicCast<Noesis::Gui::Keyboard*>(NoesisComponent.GetPtr());
	check(NoesisKeyboard);
	UIElement* NoesisInElement = NsDynamicCast<UIElement*>(InElement->NoesisComponent.GetPtr());
	return CastChecked<UNoesisUIElement>(CreateClassFor(NoesisKeyboard->Focus(NoesisInElement), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisUIElement* UNoesisKeyboard::GetFocused()
{
	Noesis::Gui::Keyboard* NoesisKeyboard = NsDynamicCast<Noesis::Gui::Keyboard*>(NoesisComponent.GetPtr());
	check(NoesisKeyboard);
	return CastChecked<UNoesisUIElement>(CreateClassFor(NoesisKeyboard->GetFocused(), nullptr), ECastCheckedType::NullAllowed);
}

int32 UNoesisKeyboard::GetModifiers()
{
	Noesis::Gui::Keyboard* NoesisKeyboard = NsDynamicCast<Noesis::Gui::Keyboard*>(NoesisComponent.GetPtr());
	check(NoesisKeyboard);
	return NoesisKeyboard->GetModifiers();
}

void UNoesisKeyboard::ResetState()
{
	Noesis::Gui::Keyboard* NoesisKeyboard = NsDynamicCast<Noesis::Gui::Keyboard*>(NoesisComponent.GetPtr());
	check(NoesisKeyboard);
	return NoesisKeyboard->ResetState();
}

void UNoesisKeyboard::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Keyboard* NoesisKeyboard = NsDynamicCast<Noesis::Gui::Keyboard*>(NoesisComponent.GetPtr());
	check(NoesisKeyboard);


}

void UNoesisKeyboard::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Keyboard* NoesisKeyboard = NsDynamicCast<Noesis::Gui::Keyboard*>(NoesisComponent.GetPtr());
	check(NoesisKeyboard);


}

