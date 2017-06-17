////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisControlTemplate.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisControlTemplate::UNoesisControlTemplate(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ControlTemplate::StaticGetClassType();
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
	return CastChecked<UNoesisResourceKeyType>(CreateClassFor(NoesisControlTemplate->GetTargetType(), nullptr), ECastCheckedType::NullAllowed);
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
	return CastChecked<UNoesisTriggerCollection>(CreateClassFor(NoesisControlTemplate->GetTriggers(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisControlTemplate::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ControlTemplate* NoesisControlTemplate = NsDynamicCast<Noesis::Gui::ControlTemplate*>(NoesisComponent.GetPtr());
	check(NoesisControlTemplate);


}

void UNoesisControlTemplate::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ControlTemplate* NoesisControlTemplate = NsDynamicCast<Noesis::Gui::ControlTemplate*>(NoesisComponent.GetPtr());
	check(NoesisControlTemplate);


}

