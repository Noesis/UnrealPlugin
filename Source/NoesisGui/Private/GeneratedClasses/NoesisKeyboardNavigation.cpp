////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisKeyboardNavigation.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisKeyboardNavigation::UNoesisKeyboardNavigation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::KeyboardNavigation::StaticGetClassType();
}

void UNoesisKeyboardNavigation::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyboardNavigation* NoesisKeyboardNavigation = NsDynamicCast<Noesis::Gui::KeyboardNavigation*>(InNoesisComponent);
	check(NoesisKeyboardNavigation);
}

void UNoesisKeyboardNavigation::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeyboardNavigation* NoesisKeyboardNavigation = NsDynamicCast<Noesis::Gui::KeyboardNavigation*>(NoesisComponent.GetPtr());
	check(NoesisKeyboardNavigation);


}

void UNoesisKeyboardNavigation::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeyboardNavigation* NoesisKeyboardNavigation = NsDynamicCast<Noesis::Gui::KeyboardNavigation*>(NoesisComponent.GetPtr());
	check(NoesisKeyboardNavigation);


}

