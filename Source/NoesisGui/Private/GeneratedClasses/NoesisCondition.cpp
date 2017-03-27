////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisCondition.h"

using namespace Noesis;
using namespace Gui;

UNoesisCondition::UNoesisCondition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Condition::StaticGetClassType();
}

void UNoesisCondition::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(InNoesisComponent);
	check(NoesisCondition);
}

class UNoesisBaseBinding* UNoesisCondition::GetBinding()
{
	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	check(NoesisCondition);
	return CastChecked<UNoesisBaseBinding>(CreateClassFor(NoesisCondition->GetBinding(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisCondition::SetBinding(class UNoesisBaseBinding* InBinding)
{
	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	check(NoesisCondition);
	NoesisCondition->SetBinding(NsDynamicCast<BaseBinding*>(InBinding->NoesisComponent.GetPtr()));
}

class UNoesisDependencyProperty* UNoesisCondition::GetProperty()
{
	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	check(NoesisCondition);
	return CastChecked<UNoesisDependencyProperty>(CreateClassFor(NoesisCondition->GetProperty(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisCondition::SetProperty(class UNoesisDependencyProperty* InProperty)
{
	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	check(NoesisCondition);
	NoesisCondition->SetProperty(NsDynamicCast<const DependencyProperty*>(InProperty->NoesisComponent.GetPtr()));
}

FString UNoesisCondition::GetSourceName()
{
	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	check(NoesisCondition);
	return NsStringToFString(NoesisCondition->GetSourceName());
}

void UNoesisCondition::SetSourceName(FString InSourceName)
{
	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	check(NoesisCondition);
	NoesisCondition->SetSourceName(StringCast<NsChar>(*InSourceName).Get());
}

class UNoesisBaseComponent* UNoesisCondition::GetValue()
{
	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	check(NoesisCondition);
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisCondition->GetValue(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisCondition::SetValue(class UNoesisBaseComponent* InValue)
{
	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	check(NoesisCondition);
	NoesisCondition->SetValue(NsDynamicCast<Core::BaseComponent*>(InValue->NoesisComponent.GetPtr()));
}

void UNoesisCondition::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	check(NoesisCondition);


}

void UNoesisCondition::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Condition* NoesisCondition = NsDynamicCast<Noesis::Gui::Condition*>(NoesisComponent.GetPtr());
	check(NoesisCondition);


}

