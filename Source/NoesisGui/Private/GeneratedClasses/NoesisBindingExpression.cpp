////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisBindingExpression.h"

using namespace Noesis;
using namespace Gui;

UNoesisBindingExpression::UNoesisBindingExpression(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisBindingExpression::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BindingExpression* NoesisBindingExpression = NsDynamicCast<Noesis::Gui::BindingExpression*>(InNoesisComponent);
	check(NoesisBindingExpression);
}

class UNoesisBinding* UNoesisBindingExpression::GetParentBinding()
{
	Noesis::Gui::BindingExpression* NoesisBindingExpression = NsDynamicCast<Noesis::Gui::BindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBindingExpression);
	return CastChecked<UNoesisBinding>(Instance->FindUnrealComponentForNoesisComponent(NoesisBindingExpression->GetParentBinding()));
}

class UNoesisBaseComponent* UNoesisBindingExpression::Evaluate()
{
	Noesis::Gui::BindingExpression* NoesisBindingExpression = NsDynamicCast<Noesis::Gui::BindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBindingExpression);
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisBindingExpression->Evaluate()));
}

class UNoesisIExpression* UNoesisBindingExpression::Reapply(class UNoesisDependencyObject* InTargetObject, const class UNoesisDependencyProperty* InTargetProperty)
{
	Noesis::Gui::BindingExpression* NoesisBindingExpression = NsDynamicCast<Noesis::Gui::BindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBindingExpression);
	DependencyObject* NoesisInTargetObject = NsDynamicCast<DependencyObject*>(InTargetObject->NoesisComponent.GetPtr());
	const DependencyProperty* NoesisInTargetProperty = NsDynamicCast<const DependencyProperty*>(InTargetProperty->NoesisComponent.GetPtr());
	return CastChecked<UNoesisIExpression>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisBindingExpression->Reapply(NoesisInTargetObject, NoesisInTargetProperty)));
}

void UNoesisBindingExpression::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BindingExpression* NoesisBindingExpression = NsDynamicCast<Noesis::Gui::BindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBindingExpression)


}

void UNoesisBindingExpression::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BindingExpression* NoesisBindingExpression = NsDynamicCast<Noesis::Gui::BindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBindingExpression)


}

