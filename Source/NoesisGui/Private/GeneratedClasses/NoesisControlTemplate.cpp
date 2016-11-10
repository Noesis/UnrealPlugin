////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisControlTemplate.h"

using namespace Noesis;
using namespace Gui;

UNoesisControlTemplate::UNoesisControlTemplate(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisControlTemplate::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ControlTemplate* NoesisControlTemplate = NsDynamicCast<Noesis::Gui::ControlTemplate*>(InNoesisComponent);
	check(NoesisControlTemplate);
}

class UNoesisResourceKeyType* UNoesisControlTemplate::GetTargetType()
{
	Noesis::Gui::ControlTemplate* NoesisControlTemplate = NsDynamicCast<Noesis::Gui::ControlTemplate*>(NoesisComponent.GetPtr());
	check(NoesisControlTemplate);
	return CastChecked<UNoesisResourceKeyType>(Instance->FindUnrealComponentForNoesisComponent(NoesisControlTemplate->GetTargetType()));
}

void UNoesisControlTemplate::SetTargetType(class UNoesisResourceKeyType* InTargetType)
{
	Noesis::Gui::ControlTemplate* NoesisControlTemplate = NsDynamicCast<Noesis::Gui::ControlTemplate*>(NoesisComponent.GetPtr());
	check(NoesisControlTemplate);
	NoesisControlTemplate->SetTargetType(NsDynamicCast<ResourceKeyType*>(InTargetType->NoesisComponent.GetPtr()));
}

class UNoesisTriggerCollection* UNoesisControlTemplate::GetTriggers()
{
	Noesis::Gui::ControlTemplate* NoesisControlTemplate = NsDynamicCast<Noesis::Gui::ControlTemplate*>(NoesisComponent.GetPtr());
	check(NoesisControlTemplate);
	return CastChecked<UNoesisTriggerCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisControlTemplate->GetTriggers()));
}

void UNoesisControlTemplate::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ControlTemplate* NoesisControlTemplate = NsDynamicCast<Noesis::Gui::ControlTemplate*>(NoesisComponent.GetPtr());
	check(NoesisControlTemplate)


}

void UNoesisControlTemplate::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ControlTemplate* NoesisControlTemplate = NsDynamicCast<Noesis::Gui::ControlTemplate*>(NoesisComponent.GetPtr());
	check(NoesisControlTemplate)


}

