////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisStyle.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisStyle::UNoesisStyle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Style::StaticGetClassType();
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
	return CastChecked<UNoesisStyle>(CreateClassFor(NoesisStyle->GetBasedOn(), nullptr), ECastCheckedType::NullAllowed);
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
	return CastChecked<UNoesisResourceDictionary>(CreateClassFor(NoesisStyle->GetResources(), nullptr), ECastCheckedType::NullAllowed);
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
	return CastChecked<UNoesisBaseSetterCollection>(CreateClassFor(NoesisStyle->GetSetters(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisResourceKeyType* UNoesisStyle::GetTargetType()
{
	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);
	return CastChecked<UNoesisResourceKeyType>(CreateClassFor(NoesisStyle->GetTargetType(), nullptr), ECastCheckedType::NullAllowed);
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
	return CastChecked<UNoesisTriggerCollection>(CreateClassFor(NoesisStyle->GetTriggers(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisStyle::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);


}

void UNoesisStyle::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Style* NoesisStyle = NsDynamicCast<Noesis::Gui::Style*>(NoesisComponent.GetPtr());
	check(NoesisStyle);


}

