////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiPowerEase.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiPowerEase::UNoesisGuiPowerEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiPowerEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::PowerEase* NoesisPowerEase = NsDynamicCast<Noesis::Gui::PowerEase*>(InNoesisComponent);
	check(NoesisPowerEase);

}

	void UNoesisGuiPowerEase::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::PowerEase* NoesisPowerEase = NsDynamicCast<Noesis::Gui::PowerEase*>(NoesisComponent.GetPtr());
	if (!NoesisPowerEase)
		return;

}

