////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTemplateBindingExtension.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTemplateBindingExtension::UNoesisGuiTemplateBindingExtension(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTemplateBindingExtension::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TemplateBindingExtension* NoesisTemplateBindingExtension = NsDynamicCast<Noesis::Gui::TemplateBindingExtension*>(InNoesisComponent);
	check(NoesisTemplateBindingExtension);
}

class UNoesisGuiDependencyProperty* UNoesisGuiTemplateBindingExtension::GetProperty()
{
	Noesis::Gui::TemplateBindingExtension* NoesisTemplateBindingExtension = NsDynamicCast<Noesis::Gui::TemplateBindingExtension*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExtension);
	return CastChecked<UNoesisGuiDependencyProperty>(Instance->FindUnrealComponentForNoesisComponent(NoesisTemplateBindingExtension->GetProperty()));
}

void UNoesisGuiTemplateBindingExtension::SetProperty(class UNoesisGuiDependencyProperty* InProperty)
{
	Noesis::Gui::TemplateBindingExtension* NoesisTemplateBindingExtension = NsDynamicCast<Noesis::Gui::TemplateBindingExtension*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExtension);
	NoesisTemplateBindingExtension->SetProperty(NsDynamicCast<const DependencyProperty*>(InProperty->NoesisComponent.GetPtr()));
}

void UNoesisGuiTemplateBindingExtension::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TemplateBindingExtension* NoesisTemplateBindingExtension = NsDynamicCast<Noesis::Gui::TemplateBindingExtension*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExtension)


}

void UNoesisGuiTemplateBindingExtension::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TemplateBindingExtension* NoesisTemplateBindingExtension = NsDynamicCast<Noesis::Gui::TemplateBindingExtension*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExtension)


}

