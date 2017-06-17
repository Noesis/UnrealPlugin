////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisKeyBinding.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisKeyBinding::UNoesisKeyBinding(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::KeyBinding::StaticGetClassType();
}

void UNoesisKeyBinding::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyBinding* NoesisKeyBinding = NsDynamicCast<Noesis::Gui::KeyBinding*>(InNoesisComponent);
	check(NoesisKeyBinding);
}

int32 UNoesisKeyBinding::GetKey()
{
	Noesis::Gui::KeyBinding* NoesisKeyBinding = NsDynamicCast<Noesis::Gui::KeyBinding*>(NoesisComponent.GetPtr());
	check(NoesisKeyBinding);
	return NoesisKeyBinding->GetKey();
}

int32 UNoesisKeyBinding::GetModifiers()
{
	Noesis::Gui::KeyBinding* NoesisKeyBinding = NsDynamicCast<Noesis::Gui::KeyBinding*>(NoesisComponent.GetPtr());
	check(NoesisKeyBinding);
	return NoesisKeyBinding->GetModifiers();
}

void UNoesisKeyBinding::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeyBinding* NoesisKeyBinding = NsDynamicCast<Noesis::Gui::KeyBinding*>(NoesisComponent.GetPtr());
	check(NoesisKeyBinding);


}

void UNoesisKeyBinding::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeyBinding* NoesisKeyBinding = NsDynamicCast<Noesis::Gui::KeyBinding*>(NoesisComponent.GetPtr());
	check(NoesisKeyBinding);


}

