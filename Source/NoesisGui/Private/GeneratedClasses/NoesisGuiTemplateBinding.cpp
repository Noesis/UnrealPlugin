////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTemplateBinding.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTemplateBinding::UNoesisGuiTemplateBinding(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTemplateBinding::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TemplateBinding* NoesisTemplateBinding = NsDynamicCast<Noesis::Gui::TemplateBinding*>(InNoesisComponent);
	check(NoesisTemplateBinding);

}

class UNoesisGuiDependencyProperty* UNoesisGuiTemplateBinding::GetProperty()
{
	Noesis::Gui::TemplateBinding* NoesisTemplateBinding = NsDynamicCast<Noesis::Gui::TemplateBinding*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBinding);
	return CastChecked<UNoesisGuiDependencyProperty>(Instance->FindUnrealComponentForNoesisComponent(NoesisTemplateBinding->GetProperty()));
}

void UNoesisGuiTemplateBinding::SetProperty(class UNoesisGuiDependencyProperty* InProperty)
{
	Noesis::Gui::TemplateBinding* NoesisTemplateBinding = NsDynamicCast<Noesis::Gui::TemplateBinding*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBinding);
	NoesisTemplateBinding->SetProperty(NsDynamicCast<const DependencyProperty*>(InProperty->NoesisComponent.GetPtr()));
}

	void UNoesisGuiTemplateBinding::BeginDestroy()
{
	Noesis::Gui::TemplateBinding* NoesisTemplateBinding = NsDynamicCast<Noesis::Gui::TemplateBinding*>(NoesisComponent.GetPtr());
	if (!NoesisTemplateBinding)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

