////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisExpander.h"

using namespace Noesis;
using namespace Gui;

UNoesisExpander::UNoesisExpander(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Expander::StaticGetClassType();
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
	if (!Collapsed.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Collapsed.Broadcast(Sender, Args);
}

void UNoesisExpander::Expanded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Expanded.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Expanded.Broadcast(Sender, Args);
}

void UNoesisExpander::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Expander* NoesisExpander = NsDynamicCast<Noesis::Gui::Expander*>(NoesisComponent.GetPtr());
	check(NoesisExpander);

	Collapsed_Delegate = Noesis::MakeDelegate(this, &UNoesisExpander::Collapsed_Private);
	NoesisExpander->Collapsed() += Collapsed_Delegate;
	Expanded_Delegate = Noesis::MakeDelegate(this, &UNoesisExpander::Expanded_Private);
	NoesisExpander->Expanded() += Expanded_Delegate;

}

void UNoesisExpander::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Expander* NoesisExpander = NsDynamicCast<Noesis::Gui::Expander*>(NoesisComponent.GetPtr());
	check(NoesisExpander);

	NoesisExpander->Collapsed() -= Collapsed_Delegate;
	NoesisExpander->Expanded() -= Expanded_Delegate;

}

