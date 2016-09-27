////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiMultiTrigger.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiMultiTrigger::UNoesisGuiMultiTrigger(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiMultiTrigger::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::MultiTrigger* NoesisMultiTrigger = NsDynamicCast<Noesis::Gui::MultiTrigger*>(InNoesisComponent);
	check(NoesisMultiTrigger);

}

class UNoesisGuiConditionCollection* UNoesisGuiMultiTrigger::GetConditions()
{
	Noesis::Gui::MultiTrigger* NoesisMultiTrigger = NsDynamicCast<Noesis::Gui::MultiTrigger*>(NoesisComponent.GetPtr());
	check(NoesisMultiTrigger);
	return CastChecked<UNoesisGuiConditionCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisMultiTrigger->GetConditions()));
}

class UNoesisGuiBaseSetterCollection* UNoesisGuiMultiTrigger::GetSetters()
{
	Noesis::Gui::MultiTrigger* NoesisMultiTrigger = NsDynamicCast<Noesis::Gui::MultiTrigger*>(NoesisComponent.GetPtr());
	check(NoesisMultiTrigger);
	return CastChecked<UNoesisGuiBaseSetterCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisMultiTrigger->GetSetters()));
}

	void UNoesisGuiMultiTrigger::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::MultiTrigger* NoesisMultiTrigger = NsDynamicCast<Noesis::Gui::MultiTrigger*>(NoesisComponent.GetPtr());
	if (!NoesisMultiTrigger)
		return;

}

