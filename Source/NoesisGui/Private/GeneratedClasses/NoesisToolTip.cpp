////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisToolTip.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisToolTip::UNoesisToolTip(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ToolTip::StaticGetClassType();
}

void UNoesisToolTip::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(InNoesisComponent);
	check(NoesisToolTip);
}

bool UNoesisToolTip::GetHasDropShadow()
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	return NoesisToolTip->GetHasDropShadow();
}

void UNoesisToolTip::SetHasDropShadow(bool InHasDropShadow)
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	NoesisToolTip->SetHasDropShadow(InHasDropShadow);
}

float UNoesisToolTip::GetHorizontalOffset()
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	return (float)NoesisToolTip->GetHorizontalOffset();
}

void UNoesisToolTip::SetHorizontalOffset(float InHorizontalOffset)
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	NoesisToolTip->SetHorizontalOffset(InHorizontalOffset);
}

bool UNoesisToolTip::GetIsOpen()
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	return NoesisToolTip->GetIsOpen();
}

void UNoesisToolTip::SetIsOpen(bool InIsOpen)
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	NoesisToolTip->SetIsOpen(InIsOpen);
}

ENoesisPlacementMode UNoesisToolTip::GetPlacement()
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	return (ENoesisPlacementMode)NoesisToolTip->GetPlacement();
}

void UNoesisToolTip::SetPlacement(ENoesisPlacementMode InPlacement)
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	NoesisToolTip->SetPlacement((Noesis::Gui::PlacementMode)InPlacement);
}

FNoesisDrawingRect UNoesisToolTip::GetPlacementRectangle()
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	return FNoesisDrawingRect(NoesisToolTip->GetPlacementRectangle());
}

void UNoesisToolTip::SetPlacementRectangle(FNoesisDrawingRect InPlacementRectangle)
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	NoesisToolTip->SetPlacementRectangle(InPlacementRectangle.ToNoesis());
}

class UNoesisUIElement* UNoesisToolTip::GetPlacementTarget()
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	return CastChecked<UNoesisUIElement>(CreateClassFor(NoesisToolTip->GetPlacementTarget(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisToolTip::SetPlacementTarget(class UNoesisUIElement* InPlacementTarget)
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	NoesisToolTip->SetPlacementTarget(NsDynamicCast<UIElement*>(InPlacementTarget->NoesisComponent.GetPtr()));
}

bool UNoesisToolTip::GetStaysOpen()
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	return NoesisToolTip->GetStaysOpen();
}

void UNoesisToolTip::SetStaysOpen(bool InStaysOpen)
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	NoesisToolTip->SetStaysOpen(InStaysOpen);
}

float UNoesisToolTip::GetVerticalOffset()
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	return (float)NoesisToolTip->GetVerticalOffset();
}

void UNoesisToolTip::SetVerticalOffset(float InVerticalOffset)
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	NoesisToolTip->SetVerticalOffset(InVerticalOffset);
}

UNoesisPopup* UNoesisToolTip::GetPopup()
{
	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);
	return CastChecked<UNoesisPopup>(CreateClassFor(NoesisToolTip->GetPopup(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisToolTip::Closed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Closed.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Closed.Broadcast(Sender, Args);
}

void UNoesisToolTip::Opened_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Opened.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Opened.Broadcast(Sender, Args);
}

void UNoesisToolTip::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);

	Closed_Delegate = Noesis::MakeDelegate(this, &UNoesisToolTip::Closed_Private);
	NoesisToolTip->Closed() += Closed_Delegate;
	Opened_Delegate = Noesis::MakeDelegate(this, &UNoesisToolTip::Opened_Private);
	NoesisToolTip->Opened() += Opened_Delegate;

}

void UNoesisToolTip::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ToolTip* NoesisToolTip = NsDynamicCast<Noesis::Gui::ToolTip*>(NoesisComponent.GetPtr());
	check(NoesisToolTip);

	NoesisToolTip->Closed() -= Closed_Delegate;
	NoesisToolTip->Opened() -= Opened_Delegate;

}

