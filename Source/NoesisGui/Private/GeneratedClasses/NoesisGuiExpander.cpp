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

	Collapsed_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiExpander::Collapsed_Private);
	NoesisExpander->Collapsed() += Collapsed_Delegate;
	Expanded_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiExpander::Expanded_Private);
	NoesisExpander->Expanded() += Expanded_Delegate;
}

	void UNoesisGuiExpander::Collapsed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Collapsed.Broadcast(Sender, Args);
}

	void UNoesisGuiExpander::Expanded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Expanded.Broadcast(Sender, Args);
}

	void UNoesisGuiExpander::BeginDestroy()
{
	Noesis::Gui::Expander* NoesisExpander = NsDynamicCast<Noesis::Gui::Expander*>(NoesisComponent.GetPtr());
	if (!NoesisExpander)
		return Super::BeginDestroy();

	NoesisExpander->Collapsed() -= Collapsed_Delegate;
	NoesisExpander->Expanded() -= Expanded_Delegate;

	Super::BeginDestroy();
}

