////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisScrollBar.h"

using namespace Noesis;
using namespace Gui;

UNoesisScrollBar::UNoesisScrollBar(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ScrollBar::StaticGetClassType();
}

void UNoesisScrollBar::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ScrollBar* NoesisScrollBar = NsDynamicCast<Noesis::Gui::ScrollBar*>(InNoesisComponent);
	check(NoesisScrollBar);
}

ENoesisOrientation UNoesisScrollBar::GetOrientation()
{
	Noesis::Gui::ScrollBar* NoesisScrollBar = NsDynamicCast<Noesis::Gui::ScrollBar*>(NoesisComponent.GetPtr());
	check(NoesisScrollBar);
	return (ENoesisOrientation)NoesisScrollBar->GetOrientation();
}

void UNoesisScrollBar::SetOrientation(ENoesisOrientation InOrientation)
{
	Noesis::Gui::ScrollBar* NoesisScrollBar = NsDynamicCast<Noesis::Gui::ScrollBar*>(NoesisComponent.GetPtr());
	check(NoesisScrollBar);
	NoesisScrollBar->SetOrientation((Noesis::Gui::Orientation)InOrientation);
}

class UNoesisTrack* UNoesisScrollBar::GetTrack()
{
	Noesis::Gui::ScrollBar* NoesisScrollBar = NsDynamicCast<Noesis::Gui::ScrollBar*>(NoesisComponent.GetPtr());
	check(NoesisScrollBar);
	return CastChecked<UNoesisTrack>(CreateClassFor(NoesisScrollBar->GetTrack(), nullptr), ECastCheckedType::NullAllowed);
}

float UNoesisScrollBar::GetViewportSize()
{
	Noesis::Gui::ScrollBar* NoesisScrollBar = NsDynamicCast<Noesis::Gui::ScrollBar*>(NoesisComponent.GetPtr());
	check(NoesisScrollBar);
	return (float)NoesisScrollBar->GetViewportSize();
}

void UNoesisScrollBar::SetViewportSize(float InViewportSize)
{
	Noesis::Gui::ScrollBar* NoesisScrollBar = NsDynamicCast<Noesis::Gui::ScrollBar*>(NoesisComponent.GetPtr());
	check(NoesisScrollBar);
	NoesisScrollBar->SetViewportSize(InViewportSize);
}

void UNoesisScrollBar::Scroll_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ScrollEventArgs& InArgs)
{
	if (!Scroll.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisScrollEventArgs Args(InArgs);
	Scroll.Broadcast(Sender, Args);
}

void UNoesisScrollBar::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ScrollBar* NoesisScrollBar = NsDynamicCast<Noesis::Gui::ScrollBar*>(NoesisComponent.GetPtr());
	check(NoesisScrollBar);

	Scroll_Delegate = Noesis::MakeDelegate(this, &UNoesisScrollBar::Scroll_Private);
	NoesisScrollBar->Scroll() += Scroll_Delegate;

}

void UNoesisScrollBar::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ScrollBar* NoesisScrollBar = NsDynamicCast<Noesis::Gui::ScrollBar*>(NoesisComponent.GetPtr());
	check(NoesisScrollBar);

	NoesisScrollBar->Scroll() -= Scroll_Delegate;

}

