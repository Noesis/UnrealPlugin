////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisThumb.h"

using namespace Noesis;
using namespace Gui;

UNoesisThumb::UNoesisThumb(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Thumb::StaticGetClassType();
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
	if (!DragCompleted.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisDragCompletedEventArgs Args(InArgs);
	DragCompleted.Broadcast(Sender, Args);
}

void UNoesisThumb::DragDelta_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DragDeltaEventArgs& InArgs)
{
	if (!DragDelta.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisDragDeltaEventArgs Args(InArgs);
	DragDelta.Broadcast(Sender, Args);
}

void UNoesisThumb::DragStarted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DragStartedEventArgs& InArgs)
{
	if (!DragStarted.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisDragStartedEventArgs Args(InArgs);
	DragStarted.Broadcast(Sender, Args);
}

void UNoesisThumb::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Thumb* NoesisThumb = NsDynamicCast<Noesis::Gui::Thumb*>(NoesisComponent.GetPtr());
	check(NoesisThumb);

	DragCompleted_Delegate = Noesis::MakeDelegate(this, &UNoesisThumb::DragCompleted_Private);
	NoesisThumb->DragCompleted() += DragCompleted_Delegate;
	DragDelta_Delegate = Noesis::MakeDelegate(this, &UNoesisThumb::DragDelta_Private);
	NoesisThumb->DragDelta() += DragDelta_Delegate;
	DragStarted_Delegate = Noesis::MakeDelegate(this, &UNoesisThumb::DragStarted_Private);
	NoesisThumb->DragStarted() += DragStarted_Delegate;

}

void UNoesisThumb::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Thumb* NoesisThumb = NsDynamicCast<Noesis::Gui::Thumb*>(NoesisComponent.GetPtr());
	check(NoesisThumb);

	NoesisThumb->DragCompleted() -= DragCompleted_Delegate;
	NoesisThumb->DragDelta() -= DragDelta_Delegate;
	NoesisThumb->DragStarted() -= DragStarted_Delegate;

}

