////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisMultiDataTrigger.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisMultiDataTrigger::UNoesisMultiDataTrigger(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::MultiDataTrigger::StaticGetClassType();
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
	return CastChecked<UNoesisConditionCollection>(CreateClassFor(NoesisMultiDataTrigger->GetConditions(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisBaseSetterCollection* UNoesisMultiDataTrigger::GetSetters()
{
	Noesis::Gui::MultiDataTrigger* NoesisMultiDataTrigger = NsDynamicCast<Noesis::Gui::MultiDataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisMultiDataTrigger);
	return CastChecked<UNoesisBaseSetterCollection>(CreateClassFor(NoesisMultiDataTrigger->GetSetters(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisMultiDataTrigger::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::MultiDataTrigger* NoesisMultiDataTrigger = NsDynamicCast<Noesis::Gui::MultiDataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisMultiDataTrigger);


}

void UNoesisMultiDataTrigger::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::MultiDataTrigger* NoesisMultiDataTrigger = NsDynamicCast<Noesis::Gui::MultiDataTrigger*>(NoesisComponent.GetPtr());
	check(NoesisMultiDataTrigger);


}

