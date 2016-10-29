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
}

UNoesisGuiPopup* UNoesisGuiToolTip::GetPopup()
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	return CastChecked<UNoesisGuiPopup>(Instance->FindUnrealComponentForNoesisComponent(NoesisToolTip->GetPopup()));
}

void UNoesisGuiToolTip::Closed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Closed.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Closed.Broadcast(Sender, Args);
}

void UNoesisGuiToolTip::Opened_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Opened.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Opened.Broadcast(Sender, Args);
}

void UNoesisGuiToolTip::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip)

	Closed_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiToolTip::Closed_Private);
	if (Closed.IsBound())
	{
		NoesisToolTip->Closed() += Closed_Delegate;
	}
	Opened_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiToolTip::Opened_Private);
	if (Opened.IsBound())
	{
		NoesisToolTip->Opened() += Opened_Delegate;
	}

}

void UNoesisGuiToolTip::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip)

	if (Closed.IsBound())
	{
		NoesisToolTip->Closed() -= Closed_Delegate;
	}
	if (Opened.IsBound())
	{
		NoesisToolTip->Opened() -= Opened_Delegate;
	}

}

