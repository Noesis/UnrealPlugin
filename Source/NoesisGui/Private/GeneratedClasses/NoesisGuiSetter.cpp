////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSetter.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSetter::UNoesisGuiSetter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSetter::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Setter* NoesisSetter = NsDynamicCast<Noesis::Gui::Setter*>(InNoesisComponent);
	check(NoesisSetter);

}

class UNoesisGuiDependencyProperty* UNoesisGuiSetter::GetProperty()
{
	Noesis::Gui::Setter* NoesisSetter = NsDynamicCast<Noesis::Gui::Setter*>(NoesisComponent.GetPtr());
	check(NoesisSetter);
	return CastChecked<UNoesisGuiDependencyProperty>(Instance->FindUnrealComponentForNoesisComponent(NoesisSetter->GetProperty()));
}

void UNoesisGuiSetter::SetProperty(class UNoesisGuiDependencyProperty* InProperty)
{
	Noesis::Gui::Setter* NoesisSetter = NsDynamicCast<Noesis::Gui::Setter*>(NoesisComponent.GetPtr());
	check(NoesisSetter);
	NoesisSetter->SetProperty(NsDynamicCast<const DependencyProperty*>(InProperty->NoesisComponent.GetPtr()));
}

FString UNoesisGuiSetter::GetTargetName()
{
	Noesis::Gui::Setter* NoesisSetter = NsDynamicCast<Noesis::Gui::Setter*>(NoesisComponent.GetPtr());
	check(NoesisSetter);
	return NsStringToFString(NoesisSetter->GetTargetName());
}

void UNoesisGuiSetter::SetTargetName(FString InTargetName)
{
	Noesis::Gui::Setter* NoesisSetter = NsDynamicCast<Noesis::Gui::Setter*>(NoesisComponent.GetPtr());
	check(NoesisSetter);
	NoesisSetter->SetTargetName(StringCast<NsChar>(*InTargetName).Get());
}

class UNoesisGuiBaseComponent* UNoesisGuiSetter::GetValue()
{
	Noesis::Gui::Setter* NoesisSetter = NsDynamicCast<Noesis::Gui::Setter*>(NoesisComponent.GetPtr());
	check(NoesisSetter);
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisSetter->GetValue()));
}

void UNoesisGuiSetter::SetValue(class UNoesisGuiBaseComponent* InValue)
{
	Noesis::Gui::Setter* NoesisSetter = NsDynamicCast<Noesis::Gui::Setter*>(NoesisComponent.GetPtr());
	check(NoesisSetter);
	NoesisSetter->SetValue(NsDynamicCast<Core::BaseComponent*>(InValue->NoesisComponent.GetPtr()));
}

	void UNoesisGuiSetter::BeginDestroy()
{
	Noesis::Gui::Setter* NoesisSetter = NsDynamicCast<Noesis::Gui::Setter*>(NoesisComponent.GetPtr());
	if (!NoesisSetter)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

