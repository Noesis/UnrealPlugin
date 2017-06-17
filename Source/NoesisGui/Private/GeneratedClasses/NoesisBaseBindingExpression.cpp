////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisBaseBindingExpression.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisBaseBindingExpression::UNoesisBaseBindingExpression(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::BaseBindingExpression::StaticGetClassType();
}

void UNoesisBaseBindingExpression::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(InNoesisComponent);
	check(NoesisBaseBindingExpression);
}

class UNoesisBaseBinding* UNoesisBaseBindingExpression::GetParentBindingBase()
{
	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBaseBindingExpression);
	return CastChecked<UNoesisBaseBinding>(CreateClassFor(NoesisBaseBindingExpression->GetParentBindingBase(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisDependencyObject* UNoesisBaseBindingExpression::GetTarget()
{
	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBaseBindingExpression);
	return CastChecked<UNoesisDependencyObject>(CreateClassFor(NoesisBaseBindingExpression->GetTarget(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisDependencyProperty* UNoesisBaseBindingExpression::GetTargetProperty()
{
	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBaseBindingExpression);
	return CastChecked<UNoesisDependencyProperty>(CreateClassFor(NoesisBaseBindingExpression->GetTargetProperty(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisBaseBindingExpression::UpdateSource()
{
	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBaseBindingExpression);
	return NoesisBaseBindingExpression->UpdateSource();
}

void UNoesisBaseBindingExpression::UpdateTarget()
{
	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBaseBindingExpression);
	return NoesisBaseBindingExpression->UpdateTarget();
}

void UNoesisBaseBindingExpression::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBaseBindingExpression);


}

void UNoesisBaseBindingExpression::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBaseBindingExpression);


}

