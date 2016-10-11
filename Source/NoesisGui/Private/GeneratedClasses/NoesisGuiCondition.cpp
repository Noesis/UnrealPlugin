////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiCondition.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiCondition::UNoesisGuiCondition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiCondition::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(InNoesisComponent);
	check(NoesisCondition);

}

class UNoesisGuiBaseBinding* UNoesisGuiCondition::GetBinding()
{
	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	check(NoesisCondition);
	return CastChecked<UNoesisGuiBaseBinding>(Instance->FindUnrealComponentForNoesisComponent(NoesisCondition->GetBinding()));
}

void UNoesisGuiCondition::SetBinding(class UNoesisGuiBaseBinding* InBinding)
{
	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	check(NoesisCondition);
	NoesisCondition->SetBinding(NsDynamicCast<BaseBinding*>(InBinding->NoesisComponent.GetPtr()));
}

class UNoesisGuiDependencyProperty* UNoesisGuiCondition::GetProperty()
{
	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	check(NoesisCondition);
	return CastChecked<UNoesisGuiDependencyProperty>(Instance->FindUnrealComponentForNoesisComponent(NoesisCondition->GetProperty()));
}

void UNoesisGuiCondition::SetProperty(class UNoesisGuiDependencyProperty* InProperty)
{
	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	check(NoesisCondition);
	NoesisCondition->SetProperty(NsDynamicCast<const DependencyProperty*>(InProperty->NoesisComponent.GetPtr()));
}

FString UNoesisGuiCondition::GetSourceName()
{
	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	check(NoesisCondition);
	return NsStringToFString(NoesisCondition->GetSourceName());
}

void UNoesisGuiCondition::SetSourceName(FString InSourceName)
{
	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	check(NoesisCondition);
	NoesisCondition->SetSourceName(StringCast<NsChar>(*InSourceName).Get());
}

class UNoesisGuiBaseComponent* UNoesisGuiCondition::GetValue()
{
	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	check(NoesisCondition);
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisCondition->GetValue()));
}

void UNoesisGuiCondition::SetValue(class UNoesisGuiBaseComponent* InValue)
{
	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	check(NoesisCondition);
	NoesisCondition->SetValue(NsDynamicCast<Core::BaseComponent*>(InValue->NoesisComponent.GetPtr()));
}

	void UNoesisGuiCondition::BeginDestroy()
{
	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	if (!NoesisCondition)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

