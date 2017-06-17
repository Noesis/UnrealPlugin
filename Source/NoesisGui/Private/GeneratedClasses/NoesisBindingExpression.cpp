////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisBindingExpression.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisBindingExpression::UNoesisBindingExpression(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::BindingExpression::StaticGetClassType();
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
	return CastChecked<UNoesisBinding>(CreateClassFor(NoesisBindingExpression->GetParentBinding(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisBaseComponent* UNoesisBindingExpression::Evaluate()
{
	Noesis::Gui::BindingExpression* NoesisBindingExpression = NsDynamicCast<Noesis::Gui::BindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBindingExpression);
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisBindingExpression->Evaluate(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisIExpression* UNoesisBindingExpression::Reapply(class UNoesisDependencyObject* InTargetObject, const class UNoesisDependencyProperty* InTargetProperty)
{
	Noesis::Gui::BindingExpression* NoesisBindingExpression = NsDynamicCast<Noesis::Gui::BindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBindingExpression);
	DependencyObject* NoesisInTargetObject = NsDynamicCast<DependencyObject*>(InTargetObject->NoesisComponent.GetPtr());
	const DependencyProperty* NoesisInTargetProperty = NsDynamicCast<const DependencyProperty*>(InTargetProperty->NoesisComponent.GetPtr());
	return CastChecked<UNoesisIExpression>(CreateInterfaceFor(NoesisBindingExpression->Reapply(NoesisInTargetObject, NoesisInTargetProperty), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisBindingExpression::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BindingExpression* NoesisBindingExpression = NsDynamicCast<Noesis::Gui::BindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBindingExpression);


}

void UNoesisBindingExpression::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BindingExpression* NoesisBindingExpression = NsDynamicCast<Noesis::Gui::BindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBindingExpression);


}

