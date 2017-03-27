////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisDependencyProperty.h"

using namespace Noesis;
using namespace Gui;

UNoesisDependencyProperty::UNoesisDependencyProperty(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::DependencyProperty::StaticGetClassType();
}

void UNoesisDependencyProperty::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(InNoesisComponent);
	check(NoesisDependencyProperty);
}

FName UNoesisDependencyProperty::GetName()
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	return FName(NoesisDependencyProperty->GetName().GetStr());
}

int32 UNoesisDependencyProperty::GetSize()
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	return (int32)NoesisDependencyProperty->GetSize();
}

bool UNoesisDependencyProperty::CheckType(const class UNoesisBaseComponent* InValue)
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	const Ptr<Core::BaseComponent> NoesisInValue = NsDynamicCast<const Ptr<Core::BaseComponent>>(InValue->NoesisComponent);
	return NoesisDependencyProperty->CheckType(NoesisInValue);
}

void UNoesisDependencyProperty::ClearAnimation(class UNoesisDependencyObject* InObj)
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	DependencyObject* NoesisInObj = NsDynamicCast<DependencyObject*>(InObj->NoesisComponent.GetPtr());
	return NoesisDependencyProperty->ClearAnimation(NoesisInObj);
}

class UNoesisBaseComponent* UNoesisDependencyProperty::GetBaseValueObject(const class UNoesisDependencyObject* InObj)
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	const DependencyObject* NoesisInObj = NsDynamicCast<const DependencyObject*>(InObj->NoesisComponent.GetPtr());
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisDependencyProperty->GetBaseValueObject(NoesisInObj), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisBaseComponent* UNoesisDependencyProperty::GetValueObject(const class UNoesisDependencyObject* InObj)
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	const DependencyObject* NoesisInObj = NsDynamicCast<const DependencyObject*>(InObj->NoesisComponent.GetPtr());
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisDependencyProperty->GetValueObject(NoesisInObj), nullptr), ECastCheckedType::NullAllowed);
}

bool UNoesisDependencyProperty::IsReadOnly()
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	return NoesisDependencyProperty->IsReadOnly();
}

bool UNoesisDependencyProperty::IsSameValue(const class UNoesisDependencyObject* InObj, const class UNoesisBaseComponent* InValue)
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	const DependencyObject* NoesisInObj = NsDynamicCast<const DependencyObject*>(InObj->NoesisComponent.GetPtr());
	const Ptr<Core::BaseComponent> NoesisInValue = NsDynamicCast<const Ptr<Core::BaseComponent>>(InValue->NoesisComponent);
	return NoesisDependencyProperty->IsSameValue(NoesisInObj, NoesisInValue);
}

bool UNoesisDependencyProperty::IsSameValue_(const class UNoesisBaseComponent* InLeft, const class UNoesisBaseComponent* InRight)
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	const Ptr<Core::BaseComponent> NoesisInLeft = NsDynamicCast<const Ptr<Core::BaseComponent>>(InLeft->NoesisComponent);
	const Ptr<Core::BaseComponent> NoesisInRight = NsDynamicCast<const Ptr<Core::BaseComponent>>(InRight->NoesisComponent);
	return NoesisDependencyProperty->IsSameValue(NoesisInLeft, NoesisInRight);
}

bool UNoesisDependencyProperty::IsValidValue(const class UNoesisBaseComponent* InValue)
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	const Ptr<Core::BaseComponent> NoesisInValue = NsDynamicCast<const Ptr<Core::BaseComponent>>(InValue->NoesisComponent);
	return NoesisDependencyProperty->IsValidValue(NoesisInValue);
}

void UNoesisDependencyProperty::SetAnimationObject(class UNoesisDependencyObject* InObj, const class UNoesisBaseComponent* InValue)
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	DependencyObject* NoesisInObj = NsDynamicCast<DependencyObject*>(InObj->NoesisComponent.GetPtr());
	const Ptr<Core::BaseComponent> NoesisInValue = NsDynamicCast<const Ptr<Core::BaseComponent>>(InValue->NoesisComponent);
	return NoesisDependencyProperty->SetAnimationObject(NoesisInObj, NoesisInValue);
}

void UNoesisDependencyProperty::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);


}

void UNoesisDependencyProperty::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);


}

