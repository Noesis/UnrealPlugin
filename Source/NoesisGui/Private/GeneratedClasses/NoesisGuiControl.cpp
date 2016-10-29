////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiControl.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiControl::UNoesisGuiControl(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiControl::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(InNoesisComponent);
	check(NoesisControl);
}

void UNoesisGuiControl::MouseDoubleClick_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!MouseDoubleClick.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiMouseButtonEventArgs Args(Instance, InArgs);
	MouseDoubleClick.Broadcast(Sender, Args);
}

void UNoesisGuiControl::PreviewMouseDoubleClick_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!PreviewMouseDoubleClick.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiMouseButtonEventArgs Args(Instance, InArgs);
	PreviewMouseDoubleClick.Broadcast(Sender, Args);
}

void UNoesisGuiControl::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl)

	MouseDoubleClick_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiControl::MouseDoubleClick_Private);
	if (MouseDoubleClick.IsBound())
	{
		NoesisControl->MouseDoubleClick() += MouseDoubleClick_Delegate;
	}
	PreviewMouseDoubleClick_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiControl::PreviewMouseDoubleClick_Private);
	if (PreviewMouseDoubleClick.IsBound())
	{
		NoesisControl->PreviewMouseDoubleClick() += PreviewMouseDoubleClick_Delegate;
	}

}

void UNoesisGuiControl::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	check(NoesisControl)

	if (MouseDoubleClick.IsBound())
	{
		NoesisControl->MouseDoubleClick() -= MouseDoubleClick_Delegate;
	}
	if (PreviewMouseDoubleClick.IsBound())
	{
		NoesisControl->PreviewMouseDoubleClick() -= PreviewMouseDoubleClick_Delegate;
	}

}

