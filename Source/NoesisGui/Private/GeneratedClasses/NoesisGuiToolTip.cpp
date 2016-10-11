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

	Closed_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiToolTip::Closed_Private);
	NoesisToolTip->Closed() += Closed_Delegate;
	Opened_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiToolTip::Opened_Private);
	NoesisToolTip->Opened() += Opened_Delegate;
}

UNoesisGuiPopup* UNoesisGuiToolTip::GetPopup()
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	return CastChecked<UNoesisGuiPopup>(Instance->FindUnrealComponentForNoesisComponent(NoesisToolTip->GetPopup()));
}

	void UNoesisGuiToolTip::Closed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Closed.Broadcast(Sender, Args);
}

	void UNoesisGuiToolTip::Opened_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Opened.Broadcast(Sender, Args);
}

	void UNoesisGuiToolTip::BeginDestroy()
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	if (!NoesisToolTip)
		return Super::BeginDestroy();

	NoesisToolTip->Closed() -= Closed_Delegate;
	NoesisToolTip->Opened() -= Opened_Delegate;

	Super::BeginDestroy();
}

