////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseBindingExpression.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseBindingExpression::UNoesisGuiBaseBindingExpression(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseBindingExpression::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(InNoesisComponent);
	check(NoesisBaseBindingExpression);
}

class UNoesisGuiBaseBinding* UNoesisGuiBaseBindingExpression::GetParentBindingBase()
{
	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBaseBindingExpression);
	return CastChecked<UNoesisGuiBaseBinding>(Instance->FindUnrealComponentForNoesisComponent(NoesisBaseBindingExpression->GetParentBindingBase()));
}

class UNoesisGuiDependencyObject* UNoesisGuiBaseBindingExpression::GetTarget()
{
	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBaseBindingExpression);
	return CastChecked<UNoesisGuiDependencyObject>(Instance->FindUnrealComponentForNoesisComponent(NoesisBaseBindingExpression->GetTarget()));
}

class UNoesisGuiDependencyProperty* UNoesisGuiBaseBindingExpression::GetTargetProperty()
{
	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBaseBindingExpression);
	return CastChecked<UNoesisGuiDependencyProperty>(Instance->FindUnrealComponentForNoesisComponent(NoesisBaseBindingExpression->GetTargetProperty()));
}

void UNoesisGuiBaseBindingExpression::UpdateSource()
{
	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBaseBindingExpression);
	return NoesisBaseBindingExpression->UpdateSource();
}

void UNoesisGuiBaseBindingExpression::UpdateTarget()
{
	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBaseBindingExpression);
	return NoesisBaseBindingExpression->UpdateTarget();
}

void UNoesisGuiBaseBindingExpression::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBaseBindingExpression)


}

void UNoesisGuiBaseBindingExpression::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseBindingExpression* NoesisBaseBindingExpression = NsDynamicCast<Noesis::Gui::BaseBindingExpression*>(NoesisComponent.GetPtr());
	check(NoesisBaseBindingExpression)


}

