////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiButton.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiButton::UNoesisGuiButton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiButton::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Button* NoesisButton = NsDynamicCast<Noesis::Gui::Button*>(InNoesisComponent);
	check(NoesisButton);

}

	void UNoesisGuiButton::BeginDestroy()
{
	Noesis::Gui::Button* NoesisButton = NsDynamicCast<Noesis::Gui::Button*>(NoesisComponent.GetPtr());
	if (!NoesisButton)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

