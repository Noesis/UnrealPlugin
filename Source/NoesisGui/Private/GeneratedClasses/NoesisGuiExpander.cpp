////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiExpander.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiExpander::UNoesisGuiExpander(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiExpander::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Expander* NoesisExpander = NsDynamicCast<Noesis::Gui::Expander*>(InNoesisComponent);
	check(NoesisExpander);

	NoesisExpander->Collapsed() += Noesis::MakeDelegate(this, &UNoesisGuiExpander::Collapsed_Private);
	NoesisExpander->Expanded() += Noesis::MakeDelegate(this, &UNoesisGuiExpander::Expanded_Private);
}

	void UNoesisGuiExpander::Collapsed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Collapsed.Broadcast(Sender, Args);
}

	void UNoesisGuiExpander::Expanded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Expanded.Broadcast(Sender, Args);
}

	void UNoesisGuiExpander::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Expander* NoesisExpander = NsDynamicCast<Noesis::Gui::Expander*>(NoesisComponent.GetPtr());
	if (!NoesisExpander)
		return;

	NoesisExpander->Collapsed() -= Noesis::MakeDelegate(this, &UNoesisGuiExpander::Collapsed_Private);
	NoesisExpander->Expanded() -= Noesis::MakeDelegate(this, &UNoesisGuiExpander::Expanded_Private);
}

