////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBindingExpression.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBindingExpression::UNoesisGuiBindingExpression(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBindingExpression::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BindingExpression* NoesisBindingExpression = NsDynamicCast<Noesis::Gui::BindingExpression*>(InNoesisComponent);
	check(NoesisBindingExpression);
}

class UNoesisGuiBinding* UNoesisGuiBindingExpression::GetParentBinding()
{
	Noesis::Gui::BindingExpression* NoesisBindingExpression = NsDynamicCast<Noesis::Gui::BindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBindingExpression);
	return CastChecked<UNoesisGuiBinding>(Instance->FindUnrealComponentForNoesisComponent(NoesisBindingExpression->GetParentBinding()));
}

class UNoesisGuiBaseComponent* UNoesisGuiBindingExpression::Evaluate()
{
	Noesis::Gui::BindingExpression* NoesisBindingExpression = NsDynamicCast<Noesis::Gui::BindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBindingExpression);
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisBindingExpression->Evaluate()));
}

class UNoesisGuiIExpression* UNoesisGuiBindingExpression::Reapply(class UNoesisGuiDependencyObject* InTargetObject, const class UNoesisGuiDependencyProperty* InTargetProperty)
{
	Noesis::Gui::BindingExpression* NoesisBindingExpression = NsDynamicCast<Noesis::Gui::BindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBindingExpression);
	DependencyObject* NoesisInTargetObject = NsDynamicCast<DependencyObject*>(InTargetObject->NoesisComponent.GetPtr());
	const DependencyProperty* NoesisInTargetProperty = NsDynamicCast<const DependencyProperty*>(InTargetProperty->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiIExpression>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisBindingExpression->Reapply(NoesisInTargetObject, NoesisInTargetProperty)));
}

void UNoesisGuiBindingExpression::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BindingExpression* NoesisBindingExpression = NsDynamicCast<Noesis::Gui::BindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBindingExpression)


}

void UNoesisGuiBindingExpression::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BindingExpression* NoesisBindingExpression = NsDynamicCast<Noesis::Gui::BindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBindingExpression)


}

