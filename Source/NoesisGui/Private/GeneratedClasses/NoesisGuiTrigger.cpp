////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTrigger.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTrigger::UNoesisGuiTrigger(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTrigger::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(InNoesisComponent);
	check(NoesisTrigger);
}

class UNoesisGuiDependencyProperty* UNoesisGuiTrigger::GetProperty()
{
	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(NoesisComponent.GetPtr());
	check(NoesisTrigger);
	return CastChecked<UNoesisGuiDependencyProperty>(Instance->FindUnrealComponentForNoesisComponent(NoesisTrigger->GetProperty()));
}

void UNoesisGuiTrigger::SetProperty(class UNoesisGuiDependencyProperty* InProperty)
{
	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(NoesisComponent.GetPtr());
	check(NoesisTrigger);
	NoesisTrigger->SetProperty(NsDynamicCast<const DependencyProperty*>(InProperty->NoesisComponent.GetPtr()));
}

class UNoesisGuiBaseSetterCollection* UNoesisGuiTrigger::GetSetters()
{
	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(NoesisComponent.GetPtr());
	check(NoesisTrigger);
	return CastChecked<UNoesisGuiBaseSetterCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisTrigger->GetSetters()));
}

FString UNoesisGuiTrigger::GetSourceName()
{
	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(NoesisComponent.GetPtr());
	check(NoesisTrigger);
	return NsStringToFString(NoesisTrigger->GetSourceName());
}

void UNoesisGuiTrigger::SetSourceName(FString InSourceName)
{
	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(NoesisComponent.GetPtr());
	check(NoesisTrigger);
	NoesisTrigger->SetSourceName(StringCast<NsChar>(*InSourceName).Get());
}

class UNoesisGuiBaseComponent* UNoesisGuiTrigger::GetValue()
{
	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(NoesisComponent.GetPtr());
	check(NoesisTrigger);
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisTrigger->GetValue()));
}

void UNoesisGuiTrigger::SetValue(class UNoesisGuiBaseComponent* InValue)
{
	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(NoesisComponent.GetPtr());
	check(NoesisTrigger);
	NoesisTrigger->SetValue(NsDynamicCast<Core::BaseComponent*>(InValue->NoesisComponent.GetPtr()));
}

void UNoesisGuiTrigger::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(NoesisComponent.GetPtr());
	check(NoesisTrigger)


}

void UNoesisGuiTrigger::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Trigger* NoesisTrigger = NsDynamicCast<Noesis::Gui::Trigger*>(NoesisComponent.GetPtr());
	check(NoesisTrigger)


}

