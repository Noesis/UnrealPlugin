////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisDataTrigger.h"

using namespace Noesis;
using namespace Gui;

UNoesisDataTrigger::UNoesisDataTrigger(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisDataTrigger::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DataTrigger* NoesisDataTrigger = NsDynamicCast<Noesis::Gui::DataTrigger*>(InNoesisComponent);
	check(NoesisDataTrigger);
}

class UNoesisBaseBinding* UNoesisDataTrigger::GetBinding()
{
	Noesis::Gui::DataTrigger* NoesisDataTrigger = NsDynamicCast<Noesis::Gui::DataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisDataTrigger);
	return CastChecked<UNoesisBaseBinding>(Instance->FindUnrealComponentForNoesisComponent(NoesisDataTrigger->GetBinding()));
}

void UNoesisDataTrigger::SetBinding(class UNoesisBaseBinding* InBinding)
{
	Noesis::Gui::DataTrigger* NoesisDataTrigger = NsDynamicCast<Noesis::Gui::DataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisDataTrigger);
	NoesisDataTrigger->SetBinding(NsDynamicCast<BaseBinding*>(InBinding->NoesisComponent.GetPtr()));
}

class UNoesisBaseSetterCollection* UNoesisDataTrigger::GetSetters()
{
	Noesis::Gui::DataTrigger* NoesisDataTrigger = NsDynamicCast<Noesis::Gui::DataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisDataTrigger);
	return CastChecked<UNoesisBaseSetterCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisDataTrigger->GetSetters()));
}

class UNoesisBaseComponent* UNoesisDataTrigger::GetValue()
{
	Noesis::Gui::DataTrigger* NoesisDataTrigger = NsDynamicCast<Noesis::Gui::DataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisDataTrigger);
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisDataTrigger->GetValue()));
}

void UNoesisDataTrigger::SetValue(class UNoesisBaseComponent* InValue)
{
	Noesis::Gui::DataTrigger* NoesisDataTrigger = NsDynamicCast<Noesis::Gui::DataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisDataTrigger);
	NoesisDataTrigger->SetValue(NsDynamicCast<Core::BaseComponent*>(InValue->NoesisComponent.GetPtr()));
}

void UNoesisDataTrigger::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DataTrigger* NoesisDataTrigger = NsDynamicCast<Noesis::Gui::DataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisDataTrigger)


}

void UNoesisDataTrigger::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DataTrigger* NoesisDataTrigger = NsDynamicCast<Noesis::Gui::DataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisDataTrigger)


}

