////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiFrameworkElement.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiFrameworkElement::UNoesisGuiFrameworkElement(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiFrameworkElement::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(InNoesisComponent);
	check(NoesisFrameworkElement);

	NoesisFrameworkElement->Loaded() += Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::Loaded_Private);
	NoesisFrameworkElement->Unloaded() += Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::Unloaded_Private);
}

class UNoesisGuiFrameworkElement* UNoesisGuiFrameworkElement::GetParent()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisGuiFrameworkElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->GetParent()));
}

class UNoesisGuiResourceDictionary* UNoesisGuiFrameworkElement::GetResources()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisGuiResourceDictionary>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->GetResources()));
}

void UNoesisGuiFrameworkElement::SetResources(class UNoesisGuiResourceDictionary* InResources)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetResources(NsDynamicCast<ResourceDictionary*>(InResources->NoesisComponent.GetPtr()));
}

class UNoesisGuiFrameworkElement* UNoesisGuiFrameworkElement::GetTemplatedParent()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisGuiFrameworkElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->GetTemplatedParent()));
}

class UNoesisGuiTriggerCollection* UNoesisGuiFrameworkElement::GetTriggers()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisGuiTriggerCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->GetTriggers()));
}

	void UNoesisGuiFrameworkElement::Loaded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Loaded.Broadcast(Sender, Args);
}

	void UNoesisGuiFrameworkElement::Unloaded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Unloaded.Broadcast(Sender, Args);
}

	void UNoesisGuiFrameworkElement::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	if (!NoesisFrameworkElement)
		return;

	NoesisFrameworkElement->Loaded() -= Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::Loaded_Private);
	NoesisFrameworkElement->Unloaded() -= Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::Unloaded_Private);
}

