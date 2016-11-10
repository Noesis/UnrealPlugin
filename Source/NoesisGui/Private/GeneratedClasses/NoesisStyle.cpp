////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisStyle.h"

using namespace Noesis;
using namespace Gui;

UNoesisStyle::UNoesisStyle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisStyle::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(InNoesisComponent);
	check(NoesisStyle);
}

class UNoesisStyle* UNoesisStyle::GetBasedOn()
{
	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);
	return CastChecked<UNoesisStyle>(Instance->FindUnrealComponentForNoesisComponent(NoesisStyle->GetBasedOn()));
}

void UNoesisStyle::SetBasedOn(class UNoesisStyle* InBasedOn)
{
	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);
	NoesisStyle->SetBasedOn(NsDynamicCast<Style*>(InBasedOn->NoesisComponent.GetPtr()));
}

class UNoesisResourceDictionary* UNoesisStyle::GetResources()
{
	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);
	return CastChecked<UNoesisResourceDictionary>(Instance->FindUnrealComponentForNoesisComponent(NoesisStyle->GetResources()));
}

void UNoesisStyle::SetResources(class UNoesisResourceDictionary* InResources)
{
	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);
	NoesisStyle->SetResources(NsDynamicCast<ResourceDictionary*>(InResources->NoesisComponent.GetPtr()));
}

class UNoesisBaseSetterCollection* UNoesisStyle::GetSetters()
{
	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);
	return CastChecked<UNoesisBaseSetterCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisStyle->GetSetters()));
}

class UNoesisResourceKeyType* UNoesisStyle::GetTargetType()
{
	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);
	return CastChecked<UNoesisResourceKeyType>(Instance->FindUnrealComponentForNoesisComponent(NoesisStyle->GetTargetType()));
}

void UNoesisStyle::SetTargetType(class UNoesisResourceKeyType* InTargetType)
{
	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);
	NoesisStyle->SetTargetType(NsDynamicCast<ResourceKeyType*>(InTargetType->NoesisComponent.GetPtr()));
}

class UNoesisTriggerCollection* UNoesisStyle::GetTriggers()
{
	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);
	return CastChecked<UNoesisTriggerCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisStyle->GetTriggers()));
}

void UNoesisStyle::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle)


}

void UNoesisStyle::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle)


}

