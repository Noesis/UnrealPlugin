////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiKeyBinding.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiKeyBinding::UNoesisGuiKeyBinding(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiKeyBinding::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyBinding* NoesisKeyBinding = NsDynamicCast<Noesis::Gui::KeyBinding*>(InNoesisComponent);
	check(NoesisKeyBinding);
}

int32 UNoesisGuiKeyBinding::GetKey()
{
	Noesis::Gui::KeyBinding* NoesisKeyBinding = NsDynamicCast<Noesis::Gui::KeyBinding*>(NoesisComponent.GetPtr());
	check(NoesisKeyBinding);
	return NoesisKeyBinding->GetKey();
}

int32 UNoesisGuiKeyBinding::GetModifiers()
{
	Noesis::Gui::KeyBinding* NoesisKeyBinding = NsDynamicCast<Noesis::Gui::KeyBinding*>(NoesisComponent.GetPtr());
	check(NoesisKeyBinding);
	return NoesisKeyBinding->GetModifiers();
}

void UNoesisGuiKeyBinding::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeyBinding* NoesisKeyBinding = NsDynamicCast<Noesis::Gui::KeyBinding*>(NoesisComponent.GetPtr());
	check(NoesisKeyBinding)


}

void UNoesisGuiKeyBinding::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeyBinding* NoesisKeyBinding = NsDynamicCast<Noesis::Gui::KeyBinding*>(NoesisComponent.GetPtr());
	check(NoesisKeyBinding)


}

