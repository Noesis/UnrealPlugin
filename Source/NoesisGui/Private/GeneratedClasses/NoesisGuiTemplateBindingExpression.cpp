////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTemplateBindingExpression.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTemplateBindingExpression::UNoesisGuiTemplateBindingExpression(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTemplateBindingExpression::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TemplateBindingExpression* NoesisTemplateBindingExpression = NsDynamicCast<Noesis::Gui::TemplateBindingExpression*>(InNoesisComponent);
	check(NoesisTemplateBindingExpression);
}

class UNoesisGuiTemplateBindingExtension* UNoesisGuiTemplateBindingExpression::GetTemplateBindingExtension()
{
	Noesis::Gui::TemplateBindingExpression* NoesisTemplateBindingExpression = NsDynamicCast<Noesis::Gui::TemplateBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExpression);
	return CastChecked<UNoesisGuiTemplateBindingExtension>(Instance->FindUnrealComponentForNoesisComponent(NoesisTemplateBindingExpression->GetTemplateBindingExtension()));
}

class UNoesisGuiBaseComponent* UNoesisGuiTemplateBindingExpression::Evaluate()
{
	Noesis::Gui::TemplateBindingExpression* NoesisTemplateBindingExpression = NsDynamicCast<Noesis::Gui::TemplateBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExpression);
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisTemplateBindingExpression->Evaluate()));
}

class UNoesisGuiIExpression* UNoesisGuiTemplateBindingExpression::Reapply(class UNoesisGuiDependencyObject* InTargetObject, const class UNoesisGuiDependencyProperty* InTargetProperty)
{
	Noesis::Gui::TemplateBindingExpression* NoesisTemplateBindingExpression = NsDynamicCast<Noesis::Gui::TemplateBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExpression);
	DependencyObject* NoesisInTargetObject = NsDynamicCast<DependencyObject*>(InTargetObject->NoesisComponent.GetPtr());
	const DependencyProperty* NoesisInTargetProperty = NsDynamicCast<const DependencyProperty*>(InTargetProperty->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiIExpression>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisTemplateBindingExpression->Reapply(NoesisInTargetObject, NoesisInTargetProperty)));
}

void UNoesisGuiTemplateBindingExpression::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TemplateBindingExpression* NoesisTemplateBindingExpression = NsDynamicCast<Noesis::Gui::TemplateBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExpression)


}

void UNoesisGuiTemplateBindingExpression::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TemplateBindingExpression* NoesisTemplateBindingExpression = NsDynamicCast<Noesis::Gui::TemplateBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExpression)


}

