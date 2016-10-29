////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiPopup.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiPopup::UNoesisGuiPopup(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiPopup::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(InNoesisComponent);
	check(NoesisPopup);
}

void UNoesisGuiPopup::Closed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::EventArgs& InArgs)
{
	if (!Closed.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiEventArgs Args(Instance, InArgs);
	Closed.Broadcast(Sender, Args);
}

void UNoesisGuiPopup::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup)

	Closed_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiPopup::Closed_Private);
	if (Closed.IsBound())
	{
		NoesisPopup->Closed() += Closed_Delegate;
	}

}

void UNoesisGuiPopup::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup)

	if (Closed.IsBound())
	{
		NoesisPopup->Closed() -= Closed_Delegate;
	}

}

