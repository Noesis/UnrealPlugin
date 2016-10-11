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

	MouseDoubleClick_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiControl::MouseDoubleClick_Private);
	NoesisControl->MouseDoubleClick() += MouseDoubleClick_Delegate;
	PreviewMouseDoubleClick_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiControl::PreviewMouseDoubleClick_Private);
	NoesisControl->PreviewMouseDoubleClick() += PreviewMouseDoubleClick_Delegate;
}

	void UNoesisGuiControl::MouseDoubleClick_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiMouseButtonEventArgs Args(Instance, InArgs);
	MouseDoubleClick.Broadcast(Sender, Args);
}

	void UNoesisGuiControl::PreviewMouseDoubleClick_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiMouseButtonEventArgs Args(Instance, InArgs);
	PreviewMouseDoubleClick.Broadcast(Sender, Args);
}

	void UNoesisGuiControl::BeginDestroy()
{
	Noesis::Gui::Control* NoesisControl = NsDynamicCast<Noesis::Gui::Control*>(NoesisComponent.GetPtr());
	if (!NoesisControl)
		return Super::BeginDestroy();

	NoesisControl->MouseDoubleClick() -= MouseDoubleClick_Delegate;
	NoesisControl->PreviewMouseDoubleClick() -= PreviewMouseDoubleClick_Delegate;

	Super::BeginDestroy();
}

