////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDependencyProperty.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDependencyProperty::UNoesisGuiDependencyProperty(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDependencyProperty::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(InNoesisComponent);
	check(NoesisDependencyProperty);

}

FName UNoesisGuiDependencyProperty::GetName()
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	return FName(NoesisDependencyProperty->GetName().GetStr());
}

int32 UNoesisGuiDependencyProperty::GetSize()
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	return (int32)NoesisDependencyProperty->GetSize();
}

bool UNoesisGuiDependencyProperty::CheckType(const class UNoesisGuiBaseComponent* InValue)
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	const Ptr<Core::BaseComponent> NoesisInValue = NsDynamicCast<const Ptr<Core::BaseComponent>>(InValue->NoesisComponent);
	return NoesisDependencyProperty->CheckType(NoesisInValue);
}

void UNoesisGuiDependencyProperty::ClearAnimation(class UNoesisGuiDependencyObject* InObj)
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	DependencyObject* NoesisInObj = NsDynamicCast<DependencyObject*>(InObj->NoesisComponent.GetPtr());
	return NoesisDependencyProperty->ClearAnimation(NoesisInObj);
}

class UNoesisGuiBaseComponent* UNoesisGuiDependencyProperty::GetBaseValueObject(const class UNoesisGuiDependencyObject* InObj)
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	const DependencyObject* NoesisInObj = NsDynamicCast<const DependencyObject*>(InObj->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisDependencyProperty->GetBaseValueObject(NoesisInObj)));
}

class UNoesisGuiBaseComponent* UNoesisGuiDependencyProperty::GetValueObject(const class UNoesisGuiDependencyObject* InObj)
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	const DependencyObject* NoesisInObj = NsDynamicCast<const DependencyObject*>(InObj->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisDependencyProperty->GetValueObject(NoesisInObj)));
}

bool UNoesisGuiDependencyProperty::IsReadOnly()
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	return NoesisDependencyProperty->IsReadOnly();
}

bool UNoesisGuiDependencyProperty::IsSameValue(const class UNoesisGuiDependencyObject* InObj, const class UNoesisGuiBaseComponent* InValue)
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	const DependencyObject* NoesisInObj = NsDynamicCast<const DependencyObject*>(InObj->NoesisComponent.GetPtr());
	const Ptr<Core::BaseComponent> NoesisInValue = NsDynamicCast<const Ptr<Core::BaseComponent>>(InValue->NoesisComponent);
	return NoesisDependencyProperty->IsSameValue(NoesisInObj, NoesisInValue);
}

bool UNoesisGuiDependencyProperty::IsSameValue_(const class UNoesisGuiBaseComponent* InLeft, const class UNoesisGuiBaseComponent* InRight)
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	const Ptr<Core::BaseComponent> NoesisInLeft = NsDynamicCast<const Ptr<Core::BaseComponent>>(InLeft->NoesisComponent);
	const Ptr<Core::BaseComponent> NoesisInRight = NsDynamicCast<const Ptr<Core::BaseComponent>>(InRight->NoesisComponent);
	return NoesisDependencyProperty->IsSameValue(NoesisInLeft, NoesisInRight);
}

bool UNoesisGuiDependencyProperty::IsValidValue(const class UNoesisGuiBaseComponent* InValue)
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	const Ptr<Core::BaseComponent> NoesisInValue = NsDynamicCast<const Ptr<Core::BaseComponent>>(InValue->NoesisComponent);
	return NoesisDependencyProperty->IsValidValue(NoesisInValue);
}

void UNoesisGuiDependencyProperty::SetAnimationObject(class UNoesisGuiDependencyObject* InObj, const class UNoesisGuiBaseComponent* InValue)
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	check(NoesisDependencyProperty);
	DependencyObject* NoesisInObj = NsDynamicCast<DependencyObject*>(InObj->NoesisComponent.GetPtr());
	const Ptr<Core::BaseComponent> NoesisInValue = NsDynamicCast<const Ptr<Core::BaseComponent>>(InValue->NoesisComponent);
	return NoesisDependencyProperty->SetAnimationObject(NoesisInObj, NoesisInValue);
}

	void UNoesisGuiDependencyProperty::BeginDestroy()
{
	Noesis::Gui::DependencyProperty* NoesisDependencyProperty = NsDynamicCast<Noesis::Gui::DependencyProperty*>(NoesisComponent.GetPtr());
	if (!NoesisDependencyProperty)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

