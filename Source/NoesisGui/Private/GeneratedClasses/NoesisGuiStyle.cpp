////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiStyle.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiStyle::UNoesisGuiStyle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiStyle::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(InNoesisComponent);
	check(NoesisStyle);
}

class UNoesisGuiStyle* UNoesisGuiStyle::GetBasedOn()
{
	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);
	return CastChecked<UNoesisGuiStyle>(Instance->FindUnrealComponentForNoesisComponent(NoesisStyle->GetBasedOn()));
}

void UNoesisGuiStyle::SetBasedOn(class UNoesisGuiStyle* InBasedOn)
{
	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);
	NoesisStyle->SetBasedOn(NsDynamicCast<Style*>(InBasedOn->NoesisComponent.GetPtr()));
}

class UNoesisGuiResourceDictionary* UNoesisGuiStyle::GetResources()
{
	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);
	return CastChecked<UNoesisGuiResourceDictionary>(Instance->FindUnrealComponentForNoesisComponent(NoesisStyle->GetResources()));
}

void UNoesisGuiStyle::SetResources(class UNoesisGuiResourceDictionary* InResources)
{
	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);
	NoesisStyle->SetResources(NsDynamicCast<ResourceDictionary*>(InResources->NoesisComponent.GetPtr()));
}

class UNoesisGuiBaseSetterCollection* UNoesisGuiStyle::GetSetters()
{
	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);
	return CastChecked<UNoesisGuiBaseSetterCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisStyle->GetSetters()));
}

class UNoesisGuiResourceKeyType* UNoesisGuiStyle::GetTargetType()
{
	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);
	return CastChecked<UNoesisGuiResourceKeyType>(Instance->FindUnrealComponentForNoesisComponent(NoesisStyle->GetTargetType()));
}

void UNoesisGuiStyle::SetTargetType(class UNoesisGuiResourceKeyType* InTargetType)
{
	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);
	NoesisStyle->SetTargetType(NsDynamicCast<ResourceKeyType*>(InTargetType->NoesisComponent.GetPtr()));
}

class UNoesisGuiTriggerCollection* UNoesisGuiStyle::GetTriggers()
{
	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);
	return CastChecked<UNoesisGuiTriggerCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisStyle->GetTriggers()));
}

void UNoesisGuiStyle::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle)


}

void UNoesisGuiStyle::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle)


}

