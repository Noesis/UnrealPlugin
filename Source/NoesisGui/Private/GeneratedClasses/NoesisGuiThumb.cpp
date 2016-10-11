////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiThumb.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiThumb::UNoesisGuiThumb(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiThumb::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Thumb* NoesisThumb = NsDynamicCast<Noesis::Gui::Thumb*>(InNoesisComponent);
	check(NoesisThumb);

	DragCompleted_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiThumb::DragCompleted_Private);
	NoesisThumb->DragCompleted() += DragCompleted_Delegate;
	DragDelta_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiThumb::DragDelta_Private);
	NoesisThumb->DragDelta() += DragDelta_Delegate;
	DragStarted_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiThumb::DragStarted_Private);
	NoesisThumb->DragStarted() += DragStarted_Delegate;
}

void UNoesisGuiThumb::CancelDrag()
{
	Noesis::Gui::Thumb* NoesisThumb = NsDynamicCast<Noesis::Gui::Thumb*>(NoesisComponent.GetPtr());
	check(NoesisThumb);
	return NoesisThumb->CancelDrag();
}

	void UNoesisGuiThumb::DragCompleted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DragCompletedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiDragCompletedEventArgs Args(Instance, InArgs);
	DragCompleted.Broadcast(Sender, Args);
}

	void UNoesisGuiThumb::DragDelta_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DragDeltaEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiDragDeltaEventArgs Args(Instance, InArgs);
	DragDelta.Broadcast(Sender, Args);
}

	void UNoesisGuiThumb::DragStarted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DragStartedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiDragStartedEventArgs Args(Instance, InArgs);
	DragStarted.Broadcast(Sender, Args);
}

	void UNoesisGuiThumb::BeginDestroy()
{
	Noesis::Gui::Thumb* NoesisThumb = NsDynamicCast<Noesis::Gui::Thumb*>(NoesisComponent.GetPtr());
	if (!NoesisThumb)
		return Super::BeginDestroy();

	NoesisThumb->DragCompleted() -= DragCompleted_Delegate;
	NoesisThumb->DragDelta() -= DragDelta_Delegate;
	NoesisThumb->DragStarted() -= DragStarted_Delegate;

	Super::BeginDestroy();
}

