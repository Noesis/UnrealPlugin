////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisPopup.h"

using namespace Noesis;
using namespace Gui;

UNoesisPopup::UNoesisPopup(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Popup::StaticGetClassType();
}

void UNoesisPopup::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(InNoesisComponent);
	check(NoesisPopup);
}

bool UNoesisPopup::GetAllowsTransparency()
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	return NoesisPopup->GetAllowsTransparency();
}

void UNoesisPopup::SetAllowsTransparency(bool InAllowsTransparency)
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	NoesisPopup->SetAllowsTransparency(InAllowsTransparency);
}

class UNoesisUIElement* UNoesisPopup::GetChild()
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	return CastChecked<UNoesisUIElement>(CreateClassFor(NoesisPopup->GetChild(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisPopup::SetChild(class UNoesisUIElement* InChild)
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	NoesisPopup->SetChild(NsDynamicCast<UIElement*>(InChild->NoesisComponent.GetPtr()));
}

bool UNoesisPopup::GetHasDropShadow()
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	return NoesisPopup->GetHasDropShadow();
}

void UNoesisPopup::SetHasDropShadow(bool InHasDropShadow)
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	NoesisPopup->SetHasDropShadow(InHasDropShadow);
}

float UNoesisPopup::GetHorizontalOffset()
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	return (float)NoesisPopup->GetHorizontalOffset();
}

void UNoesisPopup::SetHorizontalOffset(float InHorizontalOffset)
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	NoesisPopup->SetHorizontalOffset(InHorizontalOffset);
}

bool UNoesisPopup::GetIsOpen()
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	return NoesisPopup->GetIsOpen();
}

void UNoesisPopup::SetIsOpen(bool InIsOpen)
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	NoesisPopup->SetIsOpen(InIsOpen);
}

ENoesisPlacementMode UNoesisPopup::GetPlacement()
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	return (ENoesisPlacementMode)NoesisPopup->GetPlacement();
}

void UNoesisPopup::SetPlacement(ENoesisPlacementMode InPlacement)
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	NoesisPopup->SetPlacement((Noesis::Gui::PlacementMode)InPlacement);
}

FNoesisDrawingRect UNoesisPopup::GetPlacementRectangle()
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	return FNoesisDrawingRect(NoesisPopup->GetPlacementRectangle());
}

void UNoesisPopup::SetPlacementRectangle(FNoesisDrawingRect InPlacementRectangle)
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	NoesisPopup->SetPlacementRectangle(InPlacementRectangle.ToNoesis());
}

class UNoesisUIElement* UNoesisPopup::GetPlacementTarget()
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	return CastChecked<UNoesisUIElement>(CreateClassFor(NoesisPopup->GetPlacementTarget(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisPopup::SetPlacementTarget(class UNoesisUIElement* InPlacementTarget)
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	NoesisPopup->SetPlacementTarget(NsDynamicCast<UIElement*>(InPlacementTarget->NoesisComponent.GetPtr()));
}

ENoesisPopupAnimation UNoesisPopup::GetPopupAnimation()
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	return (ENoesisPopupAnimation)NoesisPopup->GetPopupAnimation();
}

void UNoesisPopup::SetPopupAnimation(ENoesisPopupAnimation InPopupAnimation)
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	NoesisPopup->SetPopupAnimation((Noesis::Gui::PopupAnimation)InPopupAnimation);
}

bool UNoesisPopup::GetStaysOpen()
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	return NoesisPopup->GetStaysOpen();
}

void UNoesisPopup::SetStaysOpen(bool InStaysOpen)
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	NoesisPopup->SetStaysOpen(InStaysOpen);
}

float UNoesisPopup::GetVerticalOffset()
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	return (float)NoesisPopup->GetVerticalOffset();
}

void UNoesisPopup::SetVerticalOffset(float InVerticalOffset)
{
	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);
	NoesisPopup->SetVerticalOffset(InVerticalOffset);
}

void UNoesisPopup::Closed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::EventArgs& InArgs)
{
	if (!Closed.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisEventArgs Args(InArgs);
	Closed.Broadcast(Sender, Args);
}

void UNoesisPopup::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);

	Closed_Delegate = Noesis::MakeDelegate(this, &UNoesisPopup::Closed_Private);
	NoesisPopup->Closed() += Closed_Delegate;

}

void UNoesisPopup::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Popup* NoesisPopup = NsDynamicCast<Noesis::Gui::Popup*>(NoesisComponent.GetPtr());
	check(NoesisPopup);

	NoesisPopup->Closed() -= Closed_Delegate;

}

