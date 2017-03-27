////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisTrigger.h"

using namespace Noesis;
using namespace Gui;

UNoesisTrigger::UNoesisTrigger(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Trigger::StaticGetClassType();
}

void UNoesisTrigger::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(InNoesisComponent);
	check(NoesisTrigger);
}

class UNoesisDependencyProperty* UNoesisTrigger::GetProperty()
{
	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(NoesisComponent.GetPtr());
	check(NoesisTrigger);
	return CastChecked<UNoesisDependencyProperty>(CreateClassFor(NoesisTrigger->GetProperty(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisTrigger::SetProperty(class UNoesisDependencyProperty* InProperty)
{
	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(NoesisComponent.GetPtr());
	check(NoesisTrigger);
	NoesisTrigger->SetProperty(NsDynamicCast<const DependencyProperty*>(InProperty->NoesisComponent.GetPtr()));
}

class UNoesisBaseSetterCollection* UNoesisTrigger::GetSetters()
{
	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(NoesisComponent.GetPtr());
	check(NoesisTrigger);
	return CastChecked<UNoesisBaseSetterCollection>(CreateClassFor(NoesisTrigger->GetSetters(), nullptr), ECastCheckedType::NullAllowed);
}

FString UNoesisTrigger::GetSourceName()
{
	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(NoesisComponent.GetPtr());
	check(NoesisTrigger);
	return NsStringToFString(NoesisTrigger->GetSourceName());
}

void UNoesisTrigger::SetSourceName(FString InSourceName)
{
	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(NoesisComponent.GetPtr());
	check(NoesisTrigger);
	NoesisTrigger->SetSourceName(StringCast<NsChar>(*InSourceName).Get());
}

class UNoesisBaseComponent* UNoesisTrigger::GetValue()
{
	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(NoesisComponent.GetPtr());
	check(NoesisTrigger);
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisTrigger->GetValue(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisTrigger::SetValue(class UNoesisBaseComponent* InValue)
{
	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(NoesisComponent.GetPtr());
	check(NoesisTrigger);
	NoesisTrigger->SetValue(NsDynamicCast<Core::BaseComponent*>(InValue->NoesisComponent.GetPtr()));
}

void UNoesisTrigger::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(NoesisComponent.GetPtr());
	check(NoesisTrigger);


}

void UNoesisTrigger::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(NoesisComponent.GetPtr());
	check(NoesisTrigger);


}

