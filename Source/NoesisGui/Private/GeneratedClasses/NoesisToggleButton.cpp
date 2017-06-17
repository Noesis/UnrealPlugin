////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisToggleButton.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisToggleButton::UNoesisToggleButton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ToggleButton::StaticGetClassType();
}

void UNoesisToggleButton::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ToggleButton* NoesisToggleButton = NsDynamicCast<Noesis::Gui::ToggleButton*>(InNoesisComponent);
	check(NoesisToggleButton);
}

bool UNoesisToggleButton::GetIsThreeState()
{
	Noesis::Gui::ToggleButton* NoesisToggleButton = NsDynamicCast<Noesis::Gui::ToggleButton*>(NoesisComponent.GetPtr());
	check(NoesisToggleButton);
	return NoesisToggleButton->GetIsThreeState();
}

void UNoesisToggleButton::SetIsThreeState(bool InIsThreeState)
{
	Noesis::Gui::ToggleButton* NoesisToggleButton = NsDynamicCast<Noesis::Gui::ToggleButton*>(NoesisComponent.GetPtr());
	check(NoesisToggleButton);
	NoesisToggleButton->SetIsThreeState(InIsThreeState);
}

void UNoesisToggleButton::Checked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Checked.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Checked.Broadcast(Sender, Args);
}

void UNoesisToggleButton::Indeterminate_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Indeterminate.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Indeterminate.Broadcast(Sender, Args);
}

void UNoesisToggleButton::Unchecked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Unchecked.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Unchecked.Broadcast(Sender, Args);
}

void UNoesisToggleButton::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ToggleButton* NoesisToggleButton = NsDynamicCast<Noesis::Gui::ToggleButton*>(NoesisComponent.GetPtr());
	check(NoesisToggleButton);

	Checked_Delegate = Noesis::MakeDelegate(this, &UNoesisToggleButton::Checked_Private);
	NoesisToggleButton->Checked() += Checked_Delegate;
	Indeterminate_Delegate = Noesis::MakeDelegate(this, &UNoesisToggleButton::Indeterminate_Private);
	NoesisToggleButton->Indeterminate() += Indeterminate_Delegate;
	Unchecked_Delegate = Noesis::MakeDelegate(this, &UNoesisToggleButton::Unchecked_Private);
	NoesisToggleButton->Unchecked() += Unchecked_Delegate;

}

void UNoesisToggleButton::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ToggleButton* NoesisToggleButton = NsDynamicCast<Noesis::Gui::ToggleButton*>(NoesisComponent.GetPtr());
	check(NoesisToggleButton);

	NoesisToggleButton->Checked() -= Checked_Delegate;
	NoesisToggleButton->Indeterminate() -= Indeterminate_Delegate;
	NoesisToggleButton->Unchecked() -= Unchecked_Delegate;

}

