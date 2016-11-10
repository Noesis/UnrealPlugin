////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisMultiDataTrigger.h"

using namespace Noesis;
using namespace Gui;

UNoesisMultiDataTrigger::UNoesisMultiDataTrigger(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisMultiDataTrigger::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::MultiDataTrigger* NoesisMultiDataTrigger = NsDynamicCast<Noesis::Gui::MultiDataTrigger*>(InNoesisComponent);
	check(NoesisMultiDataTrigger);
}

class UNoesisConditionCollection* UNoesisMultiDataTrigger::GetConditions()
{
	Noesis::Gui::MultiDataTrigger* NoesisMultiDataTrigger = NsDynamicCast<Noesis::Gui::MultiDataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisMultiDataTrigger);
	return CastChecked<UNoesisConditionCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisMultiDataTrigger->GetConditions()));
}

class UNoesisBaseSetterCollection* UNoesisMultiDataTrigger::GetSetters()
{
	Noesis::Gui::MultiDataTrigger* NoesisMultiDataTrigger = NsDynamicCast<Noesis::Gui::MultiDataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisMultiDataTrigger);
	return CastChecked<UNoesisBaseSetterCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisMultiDataTrigger->GetSetters()));
}

void UNoesisMultiDataTrigger::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::MultiDataTrigger* NoesisMultiDataTrigger = NsDynamicCast<Noesis::Gui::MultiDataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisMultiDataTrigger)


}

void UNoesisMultiDataTrigger::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::MultiDataTrigger* NoesisMultiDataTrigger = NsDynamicCast<Noesis::Gui::MultiDataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisMultiDataTrigger)


}

