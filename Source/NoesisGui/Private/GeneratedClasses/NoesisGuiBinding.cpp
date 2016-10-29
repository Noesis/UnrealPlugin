////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBinding.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBinding::UNoesisGuiBinding(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBinding::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(InNoesisComponent);
	check(NoesisBinding);
}

UNoesisGuiIValueConverter* UNoesisGuiBinding::GetConverter()
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	return CastChecked<UNoesisGuiIValueConverter>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisBinding->GetConverter()));
}

void UNoesisGuiBinding::SetConverter(UNoesisGuiIValueConverter* InConverter)
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	NoesisBinding->SetConverter(NsDynamicCast<IValueConverter*>(InConverter->NoesisInterface.GetPtr()));
}

class UNoesisGuiBaseComponent* UNoesisGuiBinding::GetConverterParameter()
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisBinding->GetConverterParameter()));
}

void UNoesisGuiBinding::SetConverterParameter(class UNoesisGuiBaseComponent* InConverterParameter)
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	NoesisBinding->SetConverterParameter(NsDynamicCast<Core::BaseComponent*>(InConverterParameter->NoesisComponent.GetPtr()));
}

FString UNoesisGuiBinding::GetElementName()
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	return NsStringToFString(NoesisBinding->GetElementName());
}

void UNoesisGuiBinding::SetElementName(FString InElementName)
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	NoesisBinding->SetElementName(StringCast<NsChar>(*InElementName).Get());
}

ENoesisGuiBindingMode UNoesisGuiBinding::GetMode()
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	return (ENoesisGuiBindingMode)NoesisBinding->GetMode();
}

void UNoesisGuiBinding::SetMode(ENoesisGuiBindingMode InMode)
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	NoesisBinding->SetMode((BindingMode)InMode);
}

class UNoesisGuiPropertyPath* UNoesisGuiBinding::GetPath()
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	return CastChecked<UNoesisGuiPropertyPath>(Instance->FindUnrealComponentForNoesisComponent(NoesisBinding->GetPath()));
}

void UNoesisGuiBinding::SetPath(class UNoesisGuiPropertyPath* InPath)
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	NoesisBinding->SetPath(NsDynamicCast<PropertyPath*>(InPath->NoesisComponent.GetPtr()));
}

class UNoesisGuiRelativeSource* UNoesisGuiBinding::GetRelativeSource()
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	return CastChecked<UNoesisGuiRelativeSource>(Instance->FindUnrealComponentForNoesisComponent(NoesisBinding->GetRelativeSource()));
}

void UNoesisGuiBinding::SetRelativeSource(class UNoesisGuiRelativeSource* InRelativeSource)
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	NoesisBinding->SetRelativeSource(NsDynamicCast<RelativeSource*>(InRelativeSource->NoesisComponent.GetPtr()));
}

class UNoesisGuiBaseComponent* UNoesisGuiBinding::GetSource()
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisBinding->GetSource()));
}

void UNoesisGuiBinding::SetSource(class UNoesisGuiBaseComponent* InSource)
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	NoesisBinding->SetSource(NsDynamicCast<Core::BaseComponent*>(InSource->NoesisComponent.GetPtr()));
}

ENoesisGuiUpdateSourceTrigger UNoesisGuiBinding::GetUpdateSourceTrigger()
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	return (ENoesisGuiUpdateSourceTrigger)NoesisBinding->GetUpdateSourceTrigger();
}

void UNoesisGuiBinding::SetUpdateSourceTrigger(ENoesisGuiUpdateSourceTrigger InUpdateSourceTrigger)
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	NoesisBinding->SetUpdateSourceTrigger((UpdateSourceTrigger)InUpdateSourceTrigger);
}

FNoesisGuiObjectWithNameScope UNoesisGuiBinding::GetSourceObject(class UNoesisGuiBaseComponent* InTarget, const class UNoesisGuiDependencyProperty* InTargetProperty)
{
	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding);
	Core::BaseComponent* NoesisInTarget = NsDynamicCast<Core::BaseComponent*>(InTarget->NoesisComponent.GetPtr());
	const DependencyProperty* NoesisInTargetProperty = NsDynamicCast<const DependencyProperty*>(InTargetProperty->NoesisComponent.GetPtr());
	return FNoesisGuiObjectWithNameScope(Instance, NoesisBinding->GetSourceObject(NoesisInTarget, NoesisInTargetProperty));
}

void UNoesisGuiBinding::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding)


}

void UNoesisGuiBinding::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Binding* NoesisBinding = NsDynamicCast<Noesis::Gui::Binding*>(NoesisComponent.GetPtr());
	check(NoesisBinding)


}

