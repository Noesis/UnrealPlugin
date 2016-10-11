////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDependencyObject.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDependencyObject::UNoesisGuiDependencyObject(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDependencyObject::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(InNoesisComponent);
	check(NoesisDependencyObject);

	DependencyPropertyChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiDependencyObject::DependencyPropertyChanged_Private);
	NoesisDependencyObject->DependencyPropertyChanged() += DependencyPropertyChanged_Delegate;
}

void UNoesisGuiDependencyObject::ClearAnimation(const class UNoesisGuiDependencyProperty* InDp)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	return NoesisDependencyObject->ClearAnimation(NoesisInDp);
}

void UNoesisGuiDependencyObject::ClearAnimation_(const class UNoesisGuiDependencyProperty* InDp)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	return NoesisDependencyObject->ClearAnimation(NoesisInDp);
}

void UNoesisGuiDependencyObject::ClearLocalValue(const class UNoesisGuiDependencyProperty* InDp)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	return NoesisDependencyObject->ClearLocalValue(NoesisInDp);
}

void UNoesisGuiDependencyObject::CoerceValue(const class UNoesisGuiDependencyProperty* InDp)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	return NoesisDependencyObject->CoerceValue(NoesisInDp);
}

void UNoesisGuiDependencyObject::CoerceValue_(const class UNoesisGuiDependencyProperty* InDp)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	return NoesisDependencyObject->CoerceValue(NoesisInDp);
}

class UNoesisGuiBaseComponent* UNoesisGuiDependencyObject::GetLocalValue(const class UNoesisGuiDependencyProperty* InDp)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisDependencyObject->GetLocalValue(NoesisInDp)));
}

class UNoesisGuiBaseComponent* UNoesisGuiDependencyObject::GetValueObject(const class UNoesisGuiDependencyProperty* InDp)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisDependencyObject->GetValueObject(NoesisInDp)));
}

int32 UNoesisGuiDependencyObject::GetValueProvider(const class UNoesisGuiDependencyProperty* InDp)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	return (int32)NoesisDependencyObject->GetValueProvider(NoesisInDp);
}

bool UNoesisGuiDependencyObject::HasAnimatedProperties()
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	return NoesisDependencyObject->HasAnimatedProperties();
}

void UNoesisGuiDependencyObject::InvalidateProperty(const class UNoesisGuiDependencyProperty* InDp, int32 InPriority)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	NsUInt8 NoesisInPriority = InPriority;
	return NoesisDependencyObject->InvalidateProperty(NoesisInDp, NoesisInPriority);
}

void UNoesisGuiDependencyObject::SetCurrentValueObject(const class UNoesisGuiDependencyProperty* InDp, const class UNoesisGuiBaseComponent* InValue)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	const Ptr<Core::BaseComponent> NoesisInValue = NsDynamicCast<const Ptr<Core::BaseComponent>>(InValue->NoesisComponent);
	return NoesisDependencyObject->SetCurrentValueObject(NoesisInDp, NoesisInValue);
}

void UNoesisGuiDependencyObject::SetExpression(const class UNoesisGuiDependencyProperty* InDp, class UNoesisGuiIExpression* InExpression)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	IExpression* NoesisInExpression = NsDynamicCast<IExpression*>(InExpression->NoesisInterface.GetPtr());
	return NoesisDependencyObject->SetExpression(NoesisInDp, NoesisInExpression);
}

void UNoesisGuiDependencyObject::SetValueObject(const class UNoesisGuiDependencyProperty* InDp, const class UNoesisGuiBaseComponent* InValue)
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	check(NoesisDependencyObject);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	const Ptr<Core::BaseComponent> NoesisInValue = NsDynamicCast<const Ptr<Core::BaseComponent>>(InValue->NoesisComponent);
	return NoesisDependencyObject->SetValueObject(NoesisInDp, NoesisInValue);
}

	void UNoesisGuiDependencyObject::DependencyPropertyChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiDependencyPropertyChangedEventArgs Args(Instance, InArgs);
	DependencyPropertyChanged.Broadcast(Sender, Args);
}

	void UNoesisGuiDependencyObject::BeginDestroy()
{
	Noesis::Gui::DependencyObject* NoesisDependencyObject = NsDynamicCast<Noesis::Gui::DependencyObject*>(NoesisComponent.GetPtr());
	if (!NoesisDependencyObject)
		return Super::BeginDestroy();

	NoesisDependencyObject->DependencyPropertyChanged() -= DependencyPropertyChanged_Delegate;

	Super::BeginDestroy();
}

