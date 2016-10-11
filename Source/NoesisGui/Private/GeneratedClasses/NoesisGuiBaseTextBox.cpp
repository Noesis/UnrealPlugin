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

	SelectionChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiBaseTextBox::SelectionChanged_Private);
	NoesisBaseTextBox->SelectionChanged() += SelectionChanged_Delegate;
	TextChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiBaseTextBox::TextChanged_Private);
	NoesisBaseTextBox->TextChanged() += TextChanged_Delegate;
}

	void UNoesisGuiBaseTextBox::SelectionChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	SelectionChanged.Broadcast(Sender, Args);
}

	void UNoesisGuiBaseTextBox::TextChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	TextChanged.Broadcast(Sender, Args);
}

	void UNoesisGuiBaseTextBox::BeginDestroy()
{
	Noesis::Gui::BaseTextBox* NoesisBaseTextBox = NsDynamicCast<Noesis::Gui::BaseTextBox*>(NoesisComponent.GetPtr());
	if (!NoesisBaseTextBox)
		return Super::BeginDestroy();

	NoesisBaseTextBox->SelectionChanged() -= SelectionChanged_Delegate;
	NoesisBaseTextBox->TextChanged() -= TextChanged_Delegate;

	Super::BeginDestroy();
}

