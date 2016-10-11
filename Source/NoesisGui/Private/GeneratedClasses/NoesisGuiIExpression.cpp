////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiIExpression.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiIExpression::UNoesisGuiIExpression(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiIExpression::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IExpression* NoesisIExpression = NsDynamicCast<Noesis::Gui::IExpression*>(InNoesisInterface);
	check(NoesisIExpression);

}

class UNoesisGuiBaseComponent* UNoesisGuiIExpression::Evaluate()
{
	Noesis::Gui::IExpression* NoesisIExpression = NsDynamicCast<Noesis::Gui::IExpression*>(NoesisInterface.GetPtr());
	check(NoesisIExpression);
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisIExpression->Evaluate()));
}

ENoesisGuiEvaluateBehavior UNoesisGuiIExpression::GetEvaluateBehavior()
{
	Noesis::Gui::IExpression* NoesisIExpression = NsDynamicCast<Noesis::Gui::IExpression*>(NoesisInterface.GetPtr());
	check(NoesisIExpression);
	return (ENoesisGuiEvaluateBehavior)NoesisIExpression->GetEvaluateBehavior();
}

class UNoesisGuiIExpression* UNoesisGuiIExpression::Reapply(class UNoesisGuiDependencyObject* InTargetObject, const class UNoesisGuiDependencyProperty* InTargetProperty)
{
	Noesis::Gui::IExpression* NoesisIExpression = NsDynamicCast<Noesis::Gui::IExpression*>(NoesisInterface.GetPtr());
	check(NoesisIExpression);
	DependencyObject* NoesisInTargetObject = NsDynamicCast<DependencyObject*>(InTargetObject->NoesisComponent.GetPtr());
	const DependencyProperty* NoesisInTargetProperty = NsDynamicCast<const DependencyProperty*>(InTargetProperty->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiIExpression>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisIExpression->Reapply(NoesisInTargetObject, NoesisInTargetProperty)));
}

	void UNoesisGuiIExpression::BeginDestroy()
{
	Noesis::Gui::IExpression* NoesisIExpression = NsDynamicCast<Noesis::Gui::IExpression*>(NoesisInterface.GetPtr());
	if (!NoesisIExpression)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

