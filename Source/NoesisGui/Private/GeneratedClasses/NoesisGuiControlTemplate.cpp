////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiControlTemplate.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiControlTemplate::UNoesisGuiControlTemplate(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiControlTemplate::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ControlTemplate* NoesisControlTemplate = NsDynamicCast<Noesis::Gui::ControlTemplate*>(InNoesisComponent);
	check(NoesisControlTemplate);
}

class UNoesisGuiResourceKeyType* UNoesisGuiControlTemplate::GetTargetType()
{
	Noesis::Gui::ControlTemplate* NoesisControlTemplate = NsDynamicCast<Noesis::Gui::ControlTemplate*>(NoesisComponent.GetPtr());
	check(NoesisControlTemplate);
	return CastChecked<UNoesisGuiResourceKeyType>(Instance->FindUnrealComponentForNoesisComponent(NoesisControlTemplate->GetTargetType()));
}

void UNoesisGuiControlTemplate::SetTargetType(class UNoesisGuiResourceKeyType* InTargetType)
{
	Noesis::Gui::ControlTemplate* NoesisControlTemplate = NsDynamicCast<Noesis::Gui::ControlTemplate*>(NoesisComponent.GetPtr());
	check(NoesisControlTemplate);
	NoesisControlTemplate->SetTargetType(NsDynamicCast<ResourceKeyType*>(InTargetType->NoesisComponent.GetPtr()));
}

class UNoesisGuiTriggerCollection* UNoesisGuiControlTemplate::GetTriggers()
{
	Noesis::Gui::ControlTemplate* NoesisControlTemplate = NsDynamicCast<Noesis::Gui::ControlTemplate*>(NoesisComponent.GetPtr());
	check(NoesisControlTemplate);
	return CastChecked<UNoesisGuiTriggerCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisControlTemplate->GetTriggers()));
}

void UNoesisGuiControlTemplate::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ControlTemplate* NoesisControlTemplate = NsDynamicCast<Noesis::Gui::ControlTemplate*>(NoesisComponent.GetPtr());
	check(NoesisControlTemplate)


}

void UNoesisGuiControlTemplate::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ControlTemplate* NoesisControlTemplate = NsDynamicCast<Noesis::Gui::ControlTemplate*>(NoesisComponent.GetPtr());
	check(NoesisControlTemplate)


}

