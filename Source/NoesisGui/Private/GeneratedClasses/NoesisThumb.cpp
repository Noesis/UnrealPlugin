////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisThumb.h"

using namespace Noesis;
using namespace Gui;

UNoesisThumb::UNoesisThumb(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisThumb::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Thumb* NoesisThumb = NsDynamicCast<Noesis::Gui::Thumb*>(InNoesisComponent);
	check(NoesisThumb);
}

bool UNoesisThumb::GetIsDragging()
{
	Noesis::Gui::Thumb* NoesisThumb = NsDynamicCast<Noesis::Gui::Thumb*>(NoesisComponent.GetPtr());
	check(NoesisThumb);
	return NoesisThumb->GetIsDragging();
}

void UNoesisThumb::CancelDrag()
{
	Noesis::Gui::Thumb* NoesisThumb = NsDynamicCast<Noesis::Gui::Thumb*>(NoesisComponent.GetPtr());
	check(NoesisThumb);
	return NoesisThumb->CancelDrag();
}

void UNoesisThumb::DragCompleted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DragCompletedEventArgs& InArgs)
{
	if (!DragCompleted.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisDragCompletedEventArgs Args(Instance, InArgs);
	DragCompleted.Broadcast(Sender, Args);
}

void UNoesisThumb::DragDelta_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DragDeltaEventArgs& InArgs)
{
	if (!DragDelta.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisDragDeltaEventArgs Args(Instance, InArgs);
	DragDelta.Broadcast(Sender, Args);
}

void UNoesisThumb::DragStarted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DragStartedEventArgs& InArgs)
{
	if (!DragStarted.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisDragStartedEventArgs Args(Instance, InArgs);
	DragStarted.Broadcast(Sender, Args);
}

void UNoesisThumb::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Thumb* NoesisThumb = NsDynamicCast<Noesis::Gui::Thumb*>(NoesisComponent.GetPtr());
	check(NoesisThumb)

	DragCompleted_Delegate = Noesis::MakeDelegate(this, &UNoesisThumb::DragCompleted_Private);
	if (DragCompleted.IsBound())
	{
		NoesisThumb->DragCompleted() += DragCompleted_Delegate;
	}
	DragDelta_Delegate = Noesis::MakeDelegate(this, &UNoesisThumb::DragDelta_Private);
	if (DragDelta.IsBound())
	{
		NoesisThumb->DragDelta() += DragDelta_Delegate;
	}
	DragStarted_Delegate = Noesis::MakeDelegate(this, &UNoesisThumb::DragStarted_Private);
	if (DragStarted.IsBound())
	{
		NoesisThumb->DragStarted() += DragStarted_Delegate;
	}

}

void UNoesisThumb::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Thumb* NoesisThumb = NsDynamicCast<Noesis::Gui::Thumb*>(NoesisComponent.GetPtr());
	check(NoesisThumb)

	if (DragCompleted.IsBound())
	{
		NoesisThumb->DragCompleted() -= DragCompleted_Delegate;
	}
	if (DragDelta.IsBound())
	{
		NoesisThumb->DragDelta() -= DragDelta_Delegate;
	}
	if (DragStarted.IsBound())
	{
		NoesisThumb->DragStarted() -= DragStarted_Delegate;
	}

}

