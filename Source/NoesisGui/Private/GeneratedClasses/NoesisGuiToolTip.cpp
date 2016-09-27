////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiToolTip.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiToolTip::UNoesisGuiToolTip(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiToolTip::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(InNoesisComponent);
	check(NoesisToolTip);

	NoesisToolTip->Closed() += Noesis::MakeDelegate(this, &UNoesisGuiToolTip::Closed_Private);
	NoesisToolTip->Opened() += Noesis::MakeDelegate(this, &UNoesisGuiToolTip::Opened_Private);
}

	void UNoesisGuiToolTip::Closed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Closed.Broadcast(Sender, Args);
}

	void UNoesisGuiToolTip::Opened_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args;
	Args.Source = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.source));
	Args.RoutedEvent = CastChecked<UNoesisGuiRoutedEvent>(Instance->FindUnrealComponentForNoesisComponent(InArgs.routedEvent));
	Opened.Broadcast(Sender, Args);
}

	void UNoesisGuiToolTip::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	if (!NoesisToolTip)
		return;

	NoesisToolTip->Closed() -= Noesis::MakeDelegate(this, &UNoesisGuiToolTip::Closed_Private);
	NoesisToolTip->Opened() -= Noesis::MakeDelegate(this, &UNoesisGuiToolTip::Opened_Private);
}

