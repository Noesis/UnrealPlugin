////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiKeyboardNavigation.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiKeyboardNavigation::UNoesisGuiKeyboardNavigation(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiKeyboardNavigation::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyboardNavigation* NoesisKeyboardNavigation = NsDynamicCast<Noesis::Gui::KeyboardNavigation*>(InNoesisComponent);
	check(NoesisKeyboardNavigation);

}

	void UNoesisGuiKeyboardNavigation::BeginDestroy()
{
	Noesis::Gui::KeyboardNavigation* NoesisKeyboardNavigation = NsDynamicCast<Noesis::Gui::KeyboardNavigation*>(NoesisComponent.GetPtr());
	if (!NoesisKeyboardNavigation)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

