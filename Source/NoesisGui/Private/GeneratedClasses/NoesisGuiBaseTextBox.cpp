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

	NoesisBaseTextBox->SelectionChanged() += Noesis::MakeDelegate(this, &UNoesisGuiBaseTextBox::SelectionChanged_Private);
	NoesisBaseTextBox->TextChanged() += Noesis::MakeDelegate(this, &UNoesisGuiBaseTextBox::TextChanged_Private);
}

	void UNoesisGuiBaseTextBox::SelectionChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	SelectionChanged.Broadcast(Sender, Args);
}

	void UNoesisGuiBaseTextBox::TextChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	TextChanged.Broadcast(Sender, Args);
}

	void UNoesisGuiBaseTextBox::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::BaseTextBox* NoesisBaseTextBox = NsDynamicCast<Noesis::Gui::BaseTextBox*>(NoesisComponent.GetPtr());
	if (!NoesisBaseTextBox)
		return;

	NoesisBaseTextBox->SelectionChanged() -= Noesis::MakeDelegate(this, &UNoesisGuiBaseTextBox::SelectionChanged_Private);
	NoesisBaseTextBox->TextChanged() -= Noesis::MakeDelegate(this, &UNoesisGuiBaseTextBox::TextChanged_Private);
}

