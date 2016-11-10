////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisTemplateBindingExtension.h"

using namespace Noesis;
using namespace Gui;

UNoesisTemplateBindingExtension::UNoesisTemplateBindingExtension(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisTemplateBindingExtension::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TemplateBindingExtension* NoesisTemplateBindingExtension = NsDynamicCast<Noesis::Gui::TemplateBindingExtension*>(InNoesisComponent);
	check(NoesisTemplateBindingExtension);
}

class UNoesisDependencyProperty* UNoesisTemplateBindingExtension::GetProperty()
{
	Noesis::Gui::TemplateBindingExtension* NoesisTemplateBindingExtension = NsDynamicCast<Noesis::Gui::TemplateBindingExtension*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExtension);
	return CastChecked<UNoesisDependencyProperty>(Instance->FindUnrealComponentForNoesisComponent(NoesisTemplateBindingExtension->GetProperty()));
}

void UNoesisTemplateBindingExtension::SetProperty(class UNoesisDependencyProperty* InProperty)
{
	Noesis::Gui::TemplateBindingExtension* NoesisTemplateBindingExtension = NsDynamicCast<Noesis::Gui::TemplateBindingExtension*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExtension);
	NoesisTemplateBindingExtension->SetProperty(NsDynamicCast<const DependencyProperty*>(InProperty->NoesisComponent.GetPtr()));
}

void UNoesisTemplateBindingExtension::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TemplateBindingExtension* NoesisTemplateBindingExtension = NsDynamicCast<Noesis::Gui::TemplateBindingExtension*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExtension)


}

void UNoesisTemplateBindingExtension::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TemplateBindingExtension* NoesisTemplateBindingExtension = NsDynamicCast<Noesis::Gui::TemplateBindingExtension*>(NoesisComponent.GetPtr());
	check(NoesisTemplateBindingExtension)


}

