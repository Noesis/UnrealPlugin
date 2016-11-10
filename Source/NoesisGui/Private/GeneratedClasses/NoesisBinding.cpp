////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisBinding.h"

using namespace Noesis;
using namespace Gui;

UNoesisBinding::UNoesisBinding(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisBinding::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(InNoesisComponent);
	check(NoesisBinding);
}

class UNoesisIValueConverter* UNoesisBinding::GetConverter()
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	return CastChecked<UNoesisIValueConverter>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisBinding->GetConverter()));
}

void UNoesisBinding::SetConverter(class UNoesisIValueConverter* InConverter)
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	NoesisBinding->SetConverter(NsDynamicCast<IValueConverter*>(InConverter->NoesisInterface.GetPtr()));
}

class UNoesisBaseComponent* UNoesisBinding::GetConverterParameter()
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisBinding->GetConverterParameter()));
}

void UNoesisBinding::SetConverterParameter(class UNoesisBaseComponent* InConverterParameter)
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	NoesisBinding->SetConverterParameter(NsDynamicCast<Core::BaseComponent*>(InConverterParameter->NoesisComponent.GetPtr()));
}

FString UNoesisBinding::GetElementName()
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	return NsStringToFString(NoesisBinding->GetElementName());
}

void UNoesisBinding::SetElementName(FString InElementName)
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	NoesisBinding->SetElementName(StringCast<NsChar>(*InElementName).Get());
}

ENoesisBindingMode UNoesisBinding::GetMode()
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	return (ENoesisBindingMode)NoesisBinding->GetMode();
}

void UNoesisBinding::SetMode(ENoesisBindingMode InMode)
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	NoesisBinding->SetMode((Noesis::Gui::BindingMode)InMode);
}

class UNoesisPropertyPath* UNoesisBinding::GetPath()
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	return CastChecked<UNoesisPropertyPath>(Instance->FindUnrealComponentForNoesisComponent(NoesisBinding->GetPath()));
}

void UNoesisBinding::SetPath(class UNoesisPropertyPath* InPath)
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	NoesisBinding->SetPath(NsDynamicCast<PropertyPath*>(InPath->NoesisComponent.GetPtr()));
}

class UNoesisRelativeSource* UNoesisBinding::GetRelativeSource()
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	return CastChecked<UNoesisRelativeSource>(Instance->FindUnrealComponentForNoesisComponent(NoesisBinding->GetRelativeSource()));
}

void UNoesisBinding::SetRelativeSource(class UNoesisRelativeSource* InRelativeSource)
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	NoesisBinding->SetRelativeSource(NsDynamicCast<RelativeSource*>(InRelativeSource->NoesisComponent.GetPtr()));
}

class UNoesisBaseComponent* UNoesisBinding::GetSource()
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	return CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisBinding->GetSource()));
}

void UNoesisBinding::SetSource(class UNoesisBaseComponent* InSource)
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	NoesisBinding->SetSource(NsDynamicCast<Core::BaseComponent*>(InSource->NoesisComponent.GetPtr()));
}

ENoesisUpdateSourceTrigger UNoesisBinding::GetUpdateSourceTrigger()
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	return (ENoesisUpdateSourceTrigger)NoesisBinding->GetUpdateSourceTrigger();
}

void UNoesisBinding::SetUpdateSourceTrigger(ENoesisUpdateSourceTrigger InUpdateSourceTrigger)
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	NoesisBinding->SetUpdateSourceTrigger((Noesis::Gui::UpdateSourceTrigger)InUpdateSourceTrigger);
}

FNoesisObjectWithNameScope UNoesisBinding::GetSourceObject(class UNoesisBaseComponent* InTarget, const class UNoesisDependencyProperty* InTargetProperty)
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	Core::BaseComponent* NoesisInTarget = NsDynamicCast<Core::BaseComponent*>(InTarget->NoesisComponent.GetPtr());
	const DependencyProperty* NoesisInTargetProperty = NsDynamicCast<const DependencyProperty*>(InTargetProperty->NoesisComponent.GetPtr());
	return FNoesisObjectWithNameScope(Instance, NoesisBinding->GetSourceObject(NoesisInTarget, NoesisInTargetProperty));
}

void UNoesisBinding::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding)


}

void UNoesisBinding::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding)


}

