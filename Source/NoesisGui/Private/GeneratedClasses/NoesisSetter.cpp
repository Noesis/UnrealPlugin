////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisSetter.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisSetter::UNoesisSetter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Setter::StaticGetClassType();
}

void UNoesisSetter::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Setter* NoesisSetter = NsDynamicCast<Noesis::Gui::Setter*>(InNoesisComponent);
	check(NoesisSetter);
}

class UNoesisDependencyProperty* UNoesisSetter::GetProperty()
{
	Noesis::Gui::Setter* NoesisSetter = NsDynamicCast<Noesis::Gui::Setter*>(NoesisComponent.GetPtr());
	check(NoesisSetter);
	return CastChecked<UNoesisDependencyProperty>(CreateClassFor(NoesisSetter->GetProperty(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisSetter::SetProperty(class UNoesisDependencyProperty* InProperty)
{
	Noesis::Gui::Setter* NoesisSetter = NsDynamicCast<Noesis::Gui::Setter*>(NoesisComponent.GetPtr());
	check(NoesisSetter);
	NoesisSetter->SetProperty(NsDynamicCast<const DependencyProperty*>(InProperty->NoesisComponent.GetPtr()));
}

FString UNoesisSetter::GetTargetName()
{
	Noesis::Gui::Setter* NoesisSetter = NsDynamicCast<Noesis::Gui::Setter*>(NoesisComponent.GetPtr());
	check(NoesisSetter);
	return NsStringToFString(NoesisSetter->GetTargetName());
}

void UNoesisSetter::SetTargetName(FString InTargetName)
{
	Noesis::Gui::Setter* NoesisSetter = NsDynamicCast<Noesis::Gui::Setter*>(NoesisComponent.GetPtr());
	check(NoesisSetter);
	NoesisSetter->SetTargetName(StringCast<NsChar>(*InTargetName).Get());
}

class UNoesisBaseComponent* UNoesisSetter::GetValue()
{
	Noesis::Gui::Setter* NoesisSetter = NsDynamicCast<Noesis::Gui::Setter*>(NoesisComponent.GetPtr());
	check(NoesisSetter);
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisSetter->GetValue(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisSetter::SetValue(class UNoesisBaseComponent* InValue)
{
	Noesis::Gui::Setter* NoesisSetter = NsDynamicCast<Noesis::Gui::Setter*>(NoesisComponent.GetPtr());
	check(NoesisSetter);
	NoesisSetter->SetValue(NsDynamicCast<Core::BaseComponent*>(InValue->NoesisComponent.GetPtr()));
}

void UNoesisSetter::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Setter* NoesisSetter = NsDynamicCast<Noesis::Gui::Setter*>(NoesisComponent.GetPtr());
	check(NoesisSetter);


}

void UNoesisSetter::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Setter* NoesisSetter = NsDynamicCast<Noesis::Gui::Setter*>(NoesisComponent.GetPtr());
	check(NoesisSetter);


}

