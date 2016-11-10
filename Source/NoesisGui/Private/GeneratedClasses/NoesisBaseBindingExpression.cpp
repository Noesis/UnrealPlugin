////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisBaseBindingExpression.h"

using namespace Noesis;
using namespace Gui;

UNoesisBaseBindingExpression::UNoesisBaseBindingExpression(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
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
	return CastChecked<UNoesisBaseBinding>(Instance->FindUnrealComponentForNoesisComponent(NoesisBaseBindingExpression->GetParentBindingBase()));
}

class UNoesisDependencyObject* UNoesisBaseBindingExpression::GetTarget()
{
	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBaseBindingExpression);
	return CastChecked<UNoesisDependencyObject>(Instance->FindUnrealComponentForNoesisComponent(NoesisBaseBindingExpression->GetTarget()));
}

class UNoesisDependencyProperty* UNoesisBaseBindingExpression::GetTargetProperty()
{
	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBaseBindingExpression);
	return CastChecked<UNoesisDependencyProperty>(Instance->FindUnrealComponentForNoesisComponent(NoesisBaseBindingExpression->GetTargetProperty()));
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
	check(NoesisBaseBindingExpression)


}

void UNoesisBaseBindingExpression::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBaseBindingExpression)


}

