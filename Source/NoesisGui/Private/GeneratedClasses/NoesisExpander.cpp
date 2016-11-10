////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisExpander.h"

using namespace Noesis;
using namespace Gui;

UNoesisExpander::UNoesisExpander(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisExpander::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Expander* NoesisExpander = NsDynamicCast<Noesis::Gui::Expander*>(InNoesisComponent);
	check(NoesisExpander);
}

ENoesisExpandDirection UNoesisExpander::GetExpandDirection()
{
	Noesis::Gui::Expander* NoesisExpander = NsDynamicCast<Noesis::Gui::Expander*>(NoesisComponent.GetPtr());
	check(NoesisExpander);
	return (ENoesisExpandDirection)NoesisExpander->GetExpandDirection();
}

void UNoesisExpander::SetExpandDirection(ENoesisExpandDirection InExpandDirection)
{
	Noesis::Gui::Expander* NoesisExpander = NsDynamicCast<Noesis::Gui::Expander*>(NoesisComponent.GetPtr());
	check(NoesisExpander);
	NoesisExpander->SetExpandDirection((Noesis::Gui::ExpandDirection)InExpandDirection);
}

bool UNoesisExpander::GetIsExpanded()
{
	Noesis::Gui::Expander* NoesisExpander = NsDynamicCast<Noesis::Gui::Expander*>(NoesisComponent.GetPtr());
	check(NoesisExpander);
	return NoesisExpander->GetIsExpanded();
}

void UNoesisExpander::SetIsExpanded(bool InIsExpanded)
{
	Noesis::Gui::Expander* NoesisExpander = NsDynamicCast<Noesis::Gui::Expander*>(NoesisComponent.GetPtr());
	check(NoesisExpander);
	NoesisExpander->SetIsExpanded(InIsExpanded);
}

void UNoesisExpander::Collapsed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Collapsed.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	Collapsed.Broadcast(Sender, Args);
}

void UNoesisExpander::Expanded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Expanded.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	Expanded.Broadcast(Sender, Args);
}

void UNoesisExpander::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Expander* NoesisExpander = NsDynamicCast<Noesis::Gui::Expander*>(NoesisComponent.GetPtr());
	check(NoesisExpander)

	Collapsed_Delegate = Noesis::MakeDelegate(this, &UNoesisExpander::Collapsed_Private);
	if (Collapsed.IsBound())
	{
		NoesisExpander->Collapsed() += Collapsed_Delegate;
	}
	Expanded_Delegate = Noesis::MakeDelegate(this, &UNoesisExpander::Expanded_Private);
	if (Expanded.IsBound())
	{
		NoesisExpander->Expanded() += Expanded_Delegate;
	}

}

void UNoesisExpander::UnbindEvents()
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

