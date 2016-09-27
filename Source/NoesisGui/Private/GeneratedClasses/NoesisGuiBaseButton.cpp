////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseButton.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseButton::UNoesisGuiBaseButton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseButton::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(InNoesisComponent);
	check(NoesisBaseButton);

	NoesisBaseButton->Click() += Noesis::MakeDelegate(this, &UNoesisGuiBaseButton::Click_Private);
}

	void UNoesisGuiBaseButton::Click_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Click.Broadcast(Sender, Args);
}

	void UNoesisGuiBaseButton::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::BaseButton* NoesisBaseButton = NsDynamicCast<Noesis::Gui::BaseButton*>(NoesisComponent.GetPtr());
	if (!NoesisBaseButton)
		return;

	NoesisBaseButton->Click() -= Noesis::MakeDelegate(this, &UNoesisGuiBaseButton::Click_Private);
}

