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
}

void UNoesisGuiExpander::Collapsed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Collapsed.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Collapsed.Broadcast(Sender, Args);
}

void UNoesisGuiExpander::Expanded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Expanded.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Expanded.Broadcast(Sender, Args);
}

void UNoesisGuiExpander::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Expander* NoesisExpander = NsDynamicCast<Noesis::Gui::Expander*>(NoesisComponent.GetPtr());
	check(NoesisExpander)

	Collapsed_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiExpander::Collapsed_Private);
	if (Collapsed.IsBound())
	{
		NoesisExpander->Collapsed() += Collapsed_Delegate;
	}
	Expanded_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiExpander::Expanded_Private);
	if (Expanded.IsBound())
	{
		NoesisExpander->Expanded() += Expanded_Delegate;
	}

}

void UNoesisGuiExpander::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Expander* NoesisExpander = NsDynamicCast<Noesis::Gui::Expander*>(NoesisComponent.GetPtr());
	check(NoesisExpander)

	if (Collapsed.IsBound())
	{
		NoesisExpander->Collapsed() -= Collapsed_Delegate;
	}
	if (Expanded.IsBound())
	{
		NoesisExpander->Expanded() -= Expanded_Delegate;
	}

}

