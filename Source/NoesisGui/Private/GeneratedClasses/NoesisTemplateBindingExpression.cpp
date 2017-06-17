////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisTemplateBindingExpression.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisTemplateBindingExpression::UNoesisTemplateBindingExpression(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::TemplateBindingExpression::StaticGetClassType();
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
	return CastChecked<UNoesisTemplateBindingExtension>(CreateClassFor(NoesisTemplateBindingExpression->GetTemplateBindingExtension(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisBaseComponent* UNoesisTemplateBindingExpression::Evaluate()
{
	Noesis::Gui::TemplateBindingExpression* NoesisTemplateBindingExpression = NsDynamicCast<Noesis::Gui::TemplateBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExpression);
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisTemplateBindingExpression->Evaluate(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisIExpression* UNoesisTemplateBindingExpression::Reapply(class UNoesisDependencyObject* InTargetObject, const class UNoesisDependencyProperty* InTargetProperty)
{
	Noesis::Gui::TemplateBindingExpression* NoesisTemplateBindingExpression = NsDynamicCast<Noesis::Gui::TemplateBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExpression);
	DependencyObject* NoesisInTargetObject = NsDynamicCast<DependencyObject*>(InTargetObject->NoesisComponent.GetPtr());
	const DependencyProperty* NoesisInTargetProperty = NsDynamicCast<const DependencyProperty*>(InTargetProperty->NoesisComponent.GetPtr());
	return CastChecked<UNoesisIExpression>(CreateInterfaceFor(NoesisTemplateBindingExpression->Reapply(NoesisInTargetObject, NoesisInTargetProperty), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisTemplateBindingExpression::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TemplateBindingExpression* NoesisTemplateBindingExpression = NsDynamicCast<Noesis::Gui::TemplateBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExpression);


}

void UNoesisTemplateBindingExpression::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TemplateBindingExpression* NoesisTemplateBindingExpression = NsDynamicCast<Noesis::Gui::TemplateBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExpression);


}

