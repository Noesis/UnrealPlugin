////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiToggleButton.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiToggleButton::UNoesisGuiToggleButton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiToggleButton::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ToggleButton* NoesisToggleButton = NsDynamicCast<Noesis::Gui::ToggleButton*>(InNoesisComponent);
	check(NoesisToggleButton);

	NoesisToggleButton->Checked() += Noesis::MakeDelegate(this, &UNoesisGuiToggleButton::Checked_Private);
	NoesisToggleButton->Indeterminate() += Noesis::MakeDelegate(this, &UNoesisGuiToggleButton::Indeterminate_Private);
	NoesisToggleButton->Unchecked() += Noesis::MakeDelegate(this, &UNoesisGuiToggleButton::Unchecked_Private);
}

	void UNoesisGuiToggleButton::Checked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Checked.Broadcast(Sender, Args);
}

	void UNoesisGuiToggleButton::Indeterminate_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Indeterminate.Broadcast(Sender, Args);
}

	void UNoesisGuiToggleButton::Unchecked_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Unchecked.Broadcast(Sender, Args);
}

	void UNoesisGuiToggleButton::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::ToggleButton* NoesisToggleButton = NsDynamicCast<Noesis::Gui::ToggleButton*>(NoesisComponent.GetPtr());
	if (!NoesisToggleButton)
		return;

	NoesisToggleButton->Checked() -= Noesis::MakeDelegate(this, &UNoesisGuiToggleButton::Checked_Private);
	NoesisToggleButton->Indeterminate() -= Noesis::MakeDelegate(this, &UNoesisGuiToggleButton::Indeterminate_Private);
	NoesisToggleButton->Unchecked() -= Noesis::MakeDelegate(this, &UNoesisGuiToggleButton::Unchecked_Private);
}

