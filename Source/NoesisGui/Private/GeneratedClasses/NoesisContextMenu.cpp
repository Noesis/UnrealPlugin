////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisContextMenu.h"

using namespace Noesis;
using namespace Gui;

UNoesisContextMenu::UNoesisContextMenu(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisContextMenu::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(InNoesisComponent);
	check(NoesisContextMenu);
}

bool UNoesisContextMenu::GetHasDropShadow()
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	return NoesisContextMenu->GetHasDropShadow();
}

void UNoesisContextMenu::SetHasDropShadow(bool InHasDropShadow)
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	NoesisContextMenu->SetHasDropShadow(InHasDropShadow);
}

float UNoesisContextMenu::GetHorizontalOffset()
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	return (float)NoesisContextMenu->GetHorizontalOffset();
}

void UNoesisContextMenu::SetHorizontalOffset(float InHorizontalOffset)
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	NoesisContextMenu->SetHorizontalOffset(InHorizontalOffset);
}

bool UNoesisContextMenu::GetIsOpen()
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	return NoesisContextMenu->GetIsOpen();
}

void UNoesisContextMenu::SetIsOpen(bool InIsOpen)
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	NoesisContextMenu->SetIsOpen(InIsOpen);
}

ENoesisPlacementMode UNoesisContextMenu::GetPlacement()
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	return (ENoesisPlacementMode)NoesisContextMenu->GetPlacement();
}

void UNoesisContextMenu::SetPlacement(ENoesisPlacementMode InPlacement)
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	NoesisContextMenu->SetPlacement((Noesis::Gui::PlacementMode)InPlacement);
}

FNoesisDrawingRect UNoesisContextMenu::GetPlacementRectangle()
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	return FNoesisDrawingRect(NoesisContextMenu->GetPlacementRectangle());
}

void UNoesisContextMenu::SetPlacementRectangle(FNoesisDrawingRect InPlacementRectangle)
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	NoesisContextMenu->SetPlacementRectangle(InPlacementRectangle.ToNoesis());
}

class UNoesisUIElement* UNoesisContextMenu::GetPlacementTarget()
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	return CastChecked<UNoesisUIElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisContextMenu->GetPlacementTarget()));
}

void UNoesisContextMenu::SetPlacementTarget(class UNoesisUIElement* InPlacementTarget)
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	NoesisContextMenu->SetPlacementTarget(NsDynamicCast<UIElement*>(InPlacementTarget->NoesisComponent.GetPtr()));
}

bool UNoesisContextMenu::GetStaysOpen()
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	return NoesisContextMenu->GetStaysOpen();
}

void UNoesisContextMenu::SetStaysOpen(bool InStaysOpen)
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	NoesisContextMenu->SetStaysOpen(InStaysOpen);
}

float UNoesisContextMenu::GetVerticalOffset()
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	return (float)NoesisContextMenu->GetVerticalOffset();
}

void UNoesisContextMenu::SetVerticalOffset(float InVerticalOffset)
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	NoesisContextMenu->SetVerticalOffset(InVerticalOffset);
}

UNoesisPopup* UNoesisContextMenu::GetPopup()
{
	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu);
	return CastChecked<UNoesisPopup>(Instance->FindUnrealComponentForNoesisComponent(NoesisContextMenu->GetPopup()));
}

void UNoesisContextMenu::Closed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Closed.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	Closed.Broadcast(Sender, Args);
}

void UNoesisContextMenu::Opened_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Opened.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisRoutedEventArgs Args(Instance, InArgs);
	Opened.Broadcast(Sender, Args);
}

void UNoesisContextMenu::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu)

	Closed_Delegate = Noesis::MakeDelegate(this, &UNoesisContextMenu::Closed_Private);
	if (Closed.IsBound())
	{
		NoesisContextMenu->Closed() += Closed_Delegate;
	}
	Opened_Delegate = Noesis::MakeDelegate(this, &UNoesisContextMenu::Opened_Private);
	if (Opened.IsBound())
	{
		NoesisContextMenu->Opened() += Opened_Delegate;
	}

}

void UNoesisContextMenu::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ContextMenu* NoesisContextMenu = NsDynamicCast<Noesis::Gui::ContextMenu*>(NoesisComponent.GetPtr());
	check(NoesisContextMenu)

	if (Closed.IsBound())
	{
		NoesisContextMenu->Closed() -= Closed_Delegate;
	}
	if (Opened.IsBound())
	{
		NoesisContextMenu->Opened() -= Opened_Delegate;
	}

}

