////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiMultiDataTrigger.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiMultiDataTrigger::UNoesisGuiMultiDataTrigger(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiMultiDataTrigger::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::MultiDataTrigger* NoesisMultiDataTrigger = NsDynamicCast<Noesis::Gui::MultiDataTrigger*>(InNoesisComponent);
	check(NoesisMultiDataTrigger);

}

class UNoesisGuiConditionCollection* UNoesisGuiMultiDataTrigger::GetConditions()
{
	Noesis::Gui::MultiDataTrigger* NoesisMultiDataTrigger = NsDynamicCast<Noesis::Gui::MultiDataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisMultiDataTrigger);
	return CastChecked<UNoesisGuiConditionCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisMultiDataTrigger->GetConditions()));
}

class UNoesisGuiBaseSetterCollection* UNoesisGuiMultiDataTrigger::GetSetters()
{
	Noesis::Gui::MultiDataTrigger* NoesisMultiDataTrigger = NsDynamicCast<Noesis::Gui::MultiDataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisMultiDataTrigger);
	return CastChecked<UNoesisGuiBaseSetterCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisMultiDataTrigger->GetSetters()));
}

	void UNoesisGuiMultiDataTrigger::BeginDestroy()
{
	Noesis::Gui::MultiDataTrigger* NoesisMultiDataTrigger = NsDynamicCast<Noesis::Gui::MultiDataTrigger*>(NoesisComponent.GetPtr());
	if (!NoesisMultiDataTrigger)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

