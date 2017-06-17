////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisDataTrigger.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisDataTrigger::UNoesisDataTrigger(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::DataTrigger::StaticGetClassType();
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
	return CastChecked<UNoesisBaseBinding>(CreateClassFor(NoesisDataTrigger->GetBinding(), nullptr), ECastCheckedType::NullAllowed);
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
	return CastChecked<UNoesisBaseSetterCollection>(CreateClassFor(NoesisDataTrigger->GetSetters(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisBaseComponent* UNoesisDataTrigger::GetValue()
{
	Noesis::Gui::DataTrigger* NoesisDataTrigger = NsDynamicCast<Noesis::Gui::DataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisDataTrigger);
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisDataTrigger->GetValue(), nullptr), ECastCheckedType::NullAllowed);
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
	check(NoesisDataTrigger);


}

void UNoesisDataTrigger::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DataTrigger* NoesisDataTrigger = NsDynamicCast<Noesis::Gui::DataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisDataTrigger);


}

