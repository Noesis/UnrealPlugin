////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisMultiTrigger.h"

using namespace Noesis;
using namespace Gui;

UNoesisMultiTrigger::UNoesisMultiTrigger(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisMultiTrigger::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::MultiTrigger* NoesisMultiTrigger = NsDynamicCast<Noesis::Gui::MultiTrigger*>(InNoesisComponent);
	check(NoesisMultiTrigger);
}

class UNoesisConditionCollection* UNoesisMultiTrigger::GetConditions()
{
	Noesis::Gui::MultiTrigger* NoesisMultiTrigger = NsDynamicCast<Noesis::Gui::MultiTrigger*>(NoesisComponent.GetPtr());
	check(NoesisMultiTrigger);
	return CastChecked<UNoesisConditionCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisMultiTrigger->GetConditions()));
}

class UNoesisBaseSetterCollection* UNoesisMultiTrigger::GetSetters()
{
	Noesis::Gui::MultiTrigger* NoesisMultiTrigger = NsDynamicCast<Noesis::Gui::MultiTrigger*>(NoesisComponent.GetPtr());
	check(NoesisMultiTrigger);
	return CastChecked<UNoesisBaseSetterCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisMultiTrigger->GetSetters()));
}

void UNoesisMultiTrigger::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::MultiTrigger* NoesisMultiTrigger = NsDynamicCast<Noesis::Gui::MultiTrigger*>(NoesisComponent.GetPtr());
	check(NoesisMultiTrigger)


}

void UNoesisMultiTrigger::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::MultiTrigger* NoesisMultiTrigger = NsDynamicCast<Noesis::Gui::MultiTrigger*>(NoesisComponent.GetPtr());
	check(NoesisMultiTrigger)


}

