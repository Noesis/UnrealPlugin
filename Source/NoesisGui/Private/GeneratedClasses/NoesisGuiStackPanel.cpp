////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiStackPanel.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiStackPanel::UNoesisGuiStackPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiStackPanel::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(InNoesisComponent);
	check(NoesisStackPanel);

}

bool UNoesisGuiStackPanel::GetCanHorizontallyScroll()
{
	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel);
	return NoesisStackPanel->GetCanHorizontallyScroll();
}

void UNoesisGuiStackPanel::SetCanHorizontallyScroll(bool InCanHorizontallyScroll)
{
	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel);
	NoesisStackPanel->SetCanHorizontallyScroll(InCanHorizontallyScroll);
}

bool UNoesisGuiStackPanel::GetCanVerticallyScroll()
{
	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel);
	return NoesisStackPanel->GetCanVerticallyScroll();
}

void UNoesisGuiStackPanel::SetCanVerticallyScroll(bool InCanVerticallyScroll)
{
	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel);
	NoesisStackPanel->SetCanVerticallyScroll(InCanVerticallyScroll);
}

float UNoesisGuiStackPanel::GetExtentHeight()
{
	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel);
	return (float)NoesisStackPanel->GetExtentHeight();
}

float UNoesisGuiStackPanel::GetExtentWidth()
{
	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel);
	return (float)NoesisStackPanel->GetExtentWidth();
}

float UNoesisGuiStackPanel::GetHorizontalOffset()
{
	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel);
	return (float)NoesisStackPanel->GetHorizontalOffset();
}

void UNoesisGuiStackPanel::SetHorizontalOffset(float InHorizontalOffset)
{
	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel);
	NoesisStackPanel->SetHorizontalOffset(InHorizontalOffset);
}

class UNoesisGuiScrollViewer* UNoesisGuiStackPanel::GetScrollOwner()
{
	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel);
	return CastChecked<UNoesisGuiScrollViewer>(Instance->FindUnrealComponentForNoesisComponent(NoesisStackPanel->GetScrollOwner()));
}

void UNoesisGuiStackPanel::SetScrollOwner(class UNoesisGuiScrollViewer* InScrollOwner)
{
	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel);
	NoesisStackPanel->SetScrollOwner(NsDynamicCast<ScrollViewer*>(InScrollOwner->NoesisComponent.GetPtr()));
}

float UNoesisGuiStackPanel::GetVerticalOffset()
{
	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel);
	return (float)NoesisStackPanel->GetVerticalOffset();
}

void UNoesisGuiStackPanel::SetVerticalOffset(float InVerticalOffset)
{
	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel);
	NoesisStackPanel->SetVerticalOffset(InVerticalOffset);
}

float UNoesisGuiStackPanel::GetViewportHeight()
{
	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel);
	return (float)NoesisStackPanel->GetViewportHeight();
}

float UNoesisGuiStackPanel::GetViewportWidth()
{
	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	check(NoesisStackPanel);
	return (float)NoesisStackPanel->GetViewportWidth();
}

	void UNoesisGuiStackPanel::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::StackPanel* NoesisStackPanel = NsDynamicCast<Noesis::Gui::StackPanel*>(NoesisComponent.GetPtr());
	if (!NoesisStackPanel)
		return;

}

