////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDataTrigger.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDataTrigger::UNoesisGuiDataTrigger(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDataTrigger::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DataTrigger* NoesisDataTrigger = NsDynamicCast<Noesis::Gui::DataTrigger*>(InNoesisComponent);
	check(NoesisDataTrigger);

}

class UNoesisGuiBaseBinding* UNoesisGuiDataTrigger::GetBinding()
{
	Noesis::Gui::DataTrigger* NoesisDataTrigger = NsDynamicCast<Noesis::Gui::DataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisDataTrigger);
	return CastChecked<UNoesisGuiBaseBinding>(Instance->FindUnrealComponentForNoesisComponent(NoesisDataTrigger->GetBinding()));
}

void UNoesisGuiDataTrigger::SetBinding(class UNoesisGuiBaseBinding* InBinding)
{
	Noesis::Gui::DataTrigger* NoesisDataTrigger = NsDynamicCast<Noesis::Gui::DataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisDataTrigger);
	NoesisDataTrigger->SetBinding(NsDynamicCast<BaseBinding*>(InBinding->NoesisComponent.GetPtr()));
}

class UNoesisGuiBaseSetterCollection* UNoesisGuiDataTrigger::GetSetters()
{
	Noesis::Gui::DataTrigger* NoesisDataTrigger = NsDynamicCast<Noesis::Gui::DataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisDataTrigger);
	return CastChecked<UNoesisGuiBaseSetterCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisDataTrigger->GetSetters()));
}

class UNoesisGuiBaseComponent* UNoesisGuiDataTrigger::GetValue()
{
	Noesis::Gui::DataTrigger* NoesisDataTrigger = NsDynamicCast<Noesis::Gui::DataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisDataTrigger);
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisDataTrigger->GetValue()));
}

void UNoesisGuiDataTrigger::SetValue(class UNoesisGuiBaseComponent* InValue)
{
	Noesis::Gui::DataTrigger* NoesisDataTrigger = NsDynamicCast<Noesis::Gui::DataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisDataTrigger);
	NoesisDataTrigger->SetValue(NsDynamicCast<Core::BaseComponent*>(InValue->NoesisComponent.GetPtr()));
}

	void UNoesisGuiDataTrigger::BeginDestroy()
{
	Noesis::Gui::DataTrigger* NoesisDataTrigger = NsDynamicCast<Noesis::Gui::DataTrigger*>(NoesisComponent.GetPtr());
	if (!NoesisDataTrigger)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

