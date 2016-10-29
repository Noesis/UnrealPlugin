////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseTextBox.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseTextBox::UNoesisGuiBaseTextBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseTextBox::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseTextBox* NoesisBaseTextBox = NsDynamicCast<Noesis::Gui::BaseTextBox*>(InNoesisComponent);
	check(NoesisBaseTextBox);
}

void UNoesisGuiBaseTextBox::SelectionChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!SelectionChanged.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	SelectionChanged.Broadcast(Sender, Args);
}

void UNoesisGuiBaseTextBox::TextChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!TextChanged.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	TextChanged.Broadcast(Sender, Args);
}

void UNoesisGuiBaseTextBox::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseTextBox* NoesisBaseTextBox = NsDynamicCast<Noesis::Gui::BaseTextBox*>(NoesisComponent.GetPtr());
	check(NoesisBaseTextBox)

	SelectionChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiBaseTextBox::SelectionChanged_Private);
	if (SelectionChanged.IsBound())
	{
		NoesisBaseTextBox->SelectionChanged() += SelectionChanged_Delegate;
	}
	TextChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiBaseTextBox::TextChanged_Private);
	if (TextChanged.IsBound())
	{
		NoesisBaseTextBox->TextChanged() += TextChanged_Delegate;
	}

}

void UNoesisGuiBaseTextBox::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseTextBox* NoesisBaseTextBox = NsDynamicCast<Noesis::Gui::BaseTextBox*>(NoesisComponent.GetPtr());
	check(NoesisBaseTextBox)

	if (SelectionChanged.IsBound())
	{
		NoesisBaseTextBox->SelectionChanged() -= SelectionChanged_Delegate;
	}
	if (TextChanged.IsBound())
	{
		NoesisBaseTextBox->TextChanged() -= TextChanged_Delegate;
	}

}

