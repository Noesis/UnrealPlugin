////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisDependencyObject.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisDependencyObject::UNoesisDependencyObject(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::DependencyObject::StaticGetClassType();
}

void UNoesisDependencyObject::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(InNoesisComponent);
	check(NoesisDependencyObject);
}

void UNoesisDependencyObject::ClearAnimation(const class UNoesisDependencyProperty* InDp)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	return NoesisDependencyObject->ClearAnimation(NoesisInDp);
}

void UNoesisDependencyObject::ClearAnimation_(const class UNoesisDependencyProperty* InDp)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	return NoesisDependencyObject->ClearAnimation(NoesisInDp);
}

void UNoesisDependencyObject::ClearLocalValue(const class UNoesisDependencyProperty* InDp)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	return NoesisDependencyObject->ClearLocalValue(NoesisInDp);
}

void UNoesisDependencyObject::CoerceValue(const class UNoesisDependencyProperty* InDp)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	return NoesisDependencyObject->CoerceValue(NoesisInDp);
}

void UNoesisDependencyObject::CoerceValue_(const class UNoesisDependencyProperty* InDp)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	return NoesisDependencyObject->CoerceValue(NoesisInDp);
}

class UNoesisBaseComponent* UNoesisDependencyObject::GetLocalValue(const class UNoesisDependencyProperty* InDp)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisDependencyObject->GetLocalValue(NoesisInDp), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisBaseComponent* UNoesisDependencyObject::GetValueObject(const class UNoesisDependencyProperty* InDp)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisDependencyObject->GetValueObject(NoesisInDp), nullptr), ECastCheckedType::NullAllowed);
}

int32 UNoesisDependencyObject::GetValueProvider(const class UNoesisDependencyProperty* InDp)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	return (int32)NoesisDependencyObject->GetValueProvider(NoesisInDp);
}

bool UNoesisDependencyObject::HasAnimatedProperties()
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	return NoesisDependencyObject->HasAnimatedProperties();
}

void UNoesisDependencyObject::InvalidateProperty(const class UNoesisDependencyProperty* InDp, int32 InPriority)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	NsUInt8 NoesisInPriority = (NsUInt8)InPriority;
	return NoesisDependencyObject->InvalidateProperty(NoesisInDp, NoesisInPriority);
}

void UNoesisDependencyObject::SetCurrentValueObject(const class UNoesisDependencyProperty* InDp, const class UNoesisBaseComponent* InValue)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	const Ptr<Core::BaseComponent> NoesisInValue = NsDynamicCast<const Ptr<Core::BaseComponent>>(InValue->NoesisComponent);
	return NoesisDependencyObject->SetCurrentValueObject(NoesisInDp, NoesisInValue);
}

void UNoesisDependencyObject::SetExpression(const class UNoesisDependencyProperty* InDp, class UNoesisIExpression* InExpression)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	IExpression* NoesisInExpression = NsDynamicCast<IExpression*>(InExpression->NoesisInterface.GetPtr());
	return NoesisDependencyObject->SetExpression(NoesisInDp, NoesisInExpression);
}

void UNoesisDependencyObject::SetValueObject(const class UNoesisDependencyProperty* InDp, const class UNoesisBaseComponent* InValue)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	const Ptr<Core::BaseComponent> NoesisInValue = NsDynamicCast<const Ptr<Core::BaseComponent>>(InValue->NoesisComponent);
	return NoesisDependencyObject->SetValueObject(NoesisInDp, NoesisInValue);
}

void UNoesisDependencyObject::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);


}

void UNoesisDependencyObject::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);


}

