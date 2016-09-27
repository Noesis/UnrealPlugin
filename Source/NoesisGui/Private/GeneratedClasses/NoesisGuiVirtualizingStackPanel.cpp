////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiVirtualizingStackPanel.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiVirtualizingStackPanel::UNoesisGuiVirtualizingStackPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiVirtualizingStackPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(InNoesisComponent);
	check(NoesisVirtualizingStackPanel);

}

bool UNoesisGuiVirtualizingStackPanel::GetCanHorizontallyScroll()
{
	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingStackPanel);
	return NoesisVirtualizingStackPanel->GetCanHorizontallyScroll();
}

void UNoesisGuiVirtualizingStackPanel::SetCanHorizontallyScroll(bool InCanHorizontallyScroll)
{
	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingStackPanel);
	NoesisVirtualizingStackPanel->SetCanHorizontallyScroll(InCanHorizontallyScroll);
}

bool UNoesisGuiVirtualizingStackPanel::GetCanVerticallyScroll()
{
	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingStackPanel);
	return NoesisVirtualizingStackPanel->GetCanVerticallyScroll();
}

void UNoesisGuiVirtualizingStackPanel::SetCanVerticallyScroll(bool InCanVerticallyScroll)
{
	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingStackPanel);
	NoesisVirtualizingStackPanel->SetCanVerticallyScroll(InCanVerticallyScroll);
}

float UNoesisGuiVirtualizingStackPanel::GetExtentHeight()
{
	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingStackPanel);
	return (float)NoesisVirtualizingStackPanel->GetExtentHeight();
}

float UNoesisGuiVirtualizingStackPanel::GetExtentWidth()
{
	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingStackPanel);
	return (float)NoesisVirtualizingStackPanel->GetExtentWidth();
}

float UNoesisGuiVirtualizingStackPanel::GetHorizontalOffset()
{
	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingStackPanel);
	return (float)NoesisVirtualizingStackPanel->GetHorizontalOffset();
}

void UNoesisGuiVirtualizingStackPanel::SetHorizontalOffset(float InHorizontalOffset)
{
	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingStackPanel);
	NoesisVirtualizingStackPanel->SetHorizontalOffset(InHorizontalOffset);
}

class UNoesisGuiScrollViewer* UNoesisGuiVirtualizingStackPanel::GetScrollOwner()
{
	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingStackPanel);
	return CastChecked<UNoesisGuiScrollViewer>(Instance->FindUnrealComponentForNoesisComponent(NoesisVirtualizingStackPanel->GetScrollOwner()));
}

void UNoesisGuiVirtualizingStackPanel::SetScrollOwner(class UNoesisGuiScrollViewer* InScrollOwner)
{
	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingStackPanel);
	NoesisVirtualizingStackPanel->SetScrollOwner(NsDynamicCast<ScrollViewer*>(InScrollOwner->NoesisComponent.GetPtr()));
}

float UNoesisGuiVirtualizingStackPanel::GetVerticalOffset()
{
	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingStackPanel);
	return (float)NoesisVirtualizingStackPanel->GetVerticalOffset();
}

void UNoesisGuiVirtualizingStackPanel::SetVerticalOffset(float InVerticalOffset)
{
	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingStackPanel);
	NoesisVirtualizingStackPanel->SetVerticalOffset(InVerticalOffset);
}

float UNoesisGuiVirtualizingStackPanel::GetViewportHeight()
{
	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingStackPanel);
	return (float)NoesisVirtualizingStackPanel->GetViewportHeight();
}

float UNoesisGuiVirtualizingStackPanel::GetViewportWidth()
{
	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	check(NoesisVirtualizingStackPanel);
	return (float)NoesisVirtualizingStackPanel->GetViewportWidth();
}

	void UNoesisGuiVirtualizingStackPanel::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::VirtualizingStackPanel* NoesisVirtualizingStackPanel = NsDynamicCast<Noesis::Gui::VirtualizingStackPanel*>(NoesisComponent.GetPtr());
	if (!NoesisVirtualizingStackPanel)
		return;

}

