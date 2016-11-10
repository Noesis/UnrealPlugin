////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisTemplateBindingExpression.h"

using namespace Noesis;
using namespace Gui;

UNoesisTemplateBindingExpression::UNoesisTemplateBindingExpression(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisTemplateBindingExpression::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TemplateBindingExpression* NoesisTemplateBindingExpression = NsDynamicCast<Noesis::Gui::TemplateBindingExpression*>(InNoesisComponent);
	check(NoesisTemplateBindingExpression);
}

class UNoesisTemplateBindingExtension* UNoesisTemplateBindingExpression::GetTemplateBindingExtension()
{
	Noesis::Gui::TemplateBindingExpression* NoesisTemplateBindingExpression = NsDynamicCast<Noesis::Gui::TemplateBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExpression);
	return CastChecked<UNoesisTemplateBindingExtension>(Instance->FindUnrealComponentForNoesisComponent(NoesisTemplateBindingExpression->GetTemplateBindingExtension()));
}

class UNoesisBaseComponent* UNoesisTemplateBindingExpression::Evaluate()
{
	Noesis::Gui::TemplateBindingExpression* NoesisTemplateBindingExpression = NsDynamicCast<Noesis::Gui::TemplateBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExpression);
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisTemplateBindingExpression->Evaluate()));
}

class UNoesisIExpression* UNoesisTemplateBindingExpression::Reapply(class UNoesisDependencyObject* InTargetObject, const class UNoesisDependencyProperty* InTargetProperty)
{
	Noesis::Gui::TemplateBindingExpression* NoesisTemplateBindingExpression = NsDynamicCast<Noesis::Gui::TemplateBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExpression);
	DependencyObject* NoesisInTargetObject = NsDynamicCast<DependencyObject*>(InTargetObject->NoesisComponent.GetPtr());
	const DependencyProperty* NoesisInTargetProperty = NsDynamicCast<const DependencyProperty*>(InTargetProperty->NoesisComponent.GetPtr());
	return CastChecked<UNoesisIExpression>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisTemplateBindingExpression->Reapply(NoesisInTargetObject, NoesisInTargetProperty)));
}

void UNoesisTemplateBindingExpression::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TemplateBindingExpression* NoesisTemplateBindingExpression = NsDynamicCast<Noesis::Gui::TemplateBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExpression)


}

void UNoesisTemplateBindingExpression::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TemplateBindingExpression* NoesisTemplateBindingExpression = NsDynamicCast<Noesis::Gui::TemplateBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExpression)


}

