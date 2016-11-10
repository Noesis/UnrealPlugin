////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisIExpression.h"

using namespace Noesis;
using namespace Gui;

UNoesisIExpression::UNoesisIExpression(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisIExpression::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IExpression* NoesisIExpression = NsDynamicCast<Noesis::Gui::IExpression*>(InNoesisInterface);
	check(NoesisIExpression);
}

class UNoesisBaseComponent* UNoesisIExpression::Evaluate()
{
	Noesis::Gui::IExpression* NoesisIExpression = NsDynamicCast<Noesis::Gui::IExpression*>(NoesisInterface.GetPtr());
	check(NoesisIExpression);
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisIExpression->Evaluate()));
}

ENoesisEvaluateBehavior UNoesisIExpression::GetEvaluateBehavior()
{
	Noesis::Gui::IExpression* NoesisIExpression = NsDynamicCast<Noesis::Gui::IExpression*>(NoesisInterface.GetPtr());
	check(NoesisIExpression);
	return (ENoesisEvaluateBehavior)NoesisIExpression->GetEvaluateBehavior();
}

class UNoesisIExpression* UNoesisIExpression::Reapply(class UNoesisDependencyObject* InTargetObject, const class UNoesisDependencyProperty* InTargetProperty)
{
	Noesis::Gui::IExpression* NoesisIExpression = NsDynamicCast<Noesis::Gui::IExpression*>(NoesisInterface.GetPtr());
	check(NoesisIExpression);
	DependencyObject* NoesisInTargetObject = NsDynamicCast<DependencyObject*>(InTargetObject->NoesisComponent.GetPtr());
	const DependencyProperty* NoesisInTargetProperty = NsDynamicCast<const DependencyProperty*>(InTargetProperty->NoesisComponent.GetPtr());
	return CastChecked<UNoesisIExpression>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisIExpression->Reapply(NoesisInTargetObject, NoesisInTargetProperty)));
}

void UNoesisIExpression::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IExpression* NoesisIExpression = NsDynamicCast<Noesis::Gui::IExpression*>(NoesisInterface.GetPtr());
	check(NoesisIExpression)


}

void UNoesisIExpression::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IExpression* NoesisIExpression = NsDynamicCast<Noesis::Gui::IExpression*>(NoesisInterface.GetPtr());
	check(NoesisIExpression)


}

