////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiScrollContentPresenter.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiScrollContentPresenter::UNoesisGuiScrollContentPresenter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiScrollContentPresenter::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(InNoesisComponent);
	check(NoesisScrollContentPresenter);

}

bool UNoesisGuiScrollContentPresenter::GetCanHorizontallyScroll()
{
	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter);
	return NoesisScrollContentPresenter->GetCanHorizontallyScroll();
}

void UNoesisGuiScrollContentPresenter::SetCanHorizontallyScroll(bool InCanHorizontallyScroll)
{
	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter);
	NoesisScrollContentPresenter->SetCanHorizontallyScroll(InCanHorizontallyScroll);
}

bool UNoesisGuiScrollContentPresenter::GetCanVerticallyScroll()
{
	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter);
	return NoesisScrollContentPresenter->GetCanVerticallyScroll();
}

void UNoesisGuiScrollContentPresenter::SetCanVerticallyScroll(bool InCanVerticallyScroll)
{
	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter);
	NoesisScrollContentPresenter->SetCanVerticallyScroll(InCanVerticallyScroll);
}

float UNoesisGuiScrollContentPresenter::GetExtentHeight()
{
	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter);
	return (float)NoesisScrollContentPresenter->GetExtentHeight();
}

float UNoesisGuiScrollContentPresenter::GetExtentWidth()
{
	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter);
	return (float)NoesisScrollContentPresenter->GetExtentWidth();
}

float UNoesisGuiScrollContentPresenter::GetHorizontalOffset()
{
	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter);
	return (float)NoesisScrollContentPresenter->GetHorizontalOffset();
}

void UNoesisGuiScrollContentPresenter::SetHorizontalOffset(float InHorizontalOffset)
{
	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter);
	NoesisScrollContentPresenter->SetHorizontalOffset(InHorizontalOffset);
}

class UNoesisGuiScrollViewer* UNoesisGuiScrollContentPresenter::GetScrollOwner()
{
	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter);
	return CastChecked<UNoesisGuiScrollViewer>(Instance->FindUnrealComponentForNoesisComponent(NoesisScrollContentPresenter->GetScrollOwner()));
}

void UNoesisGuiScrollContentPresenter::SetScrollOwner(class UNoesisGuiScrollViewer* InScrollOwner)
{
	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter);
	NoesisScrollContentPresenter->SetScrollOwner(NsDynamicCast<ScrollViewer*>(InScrollOwner->NoesisComponent.GetPtr()));
}

float UNoesisGuiScrollContentPresenter::GetVerticalOffset()
{
	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter);
	return (float)NoesisScrollContentPresenter->GetVerticalOffset();
}

void UNoesisGuiScrollContentPresenter::SetVerticalOffset(float InVerticalOffset)
{
	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter);
	NoesisScrollContentPresenter->SetVerticalOffset(InVerticalOffset);
}

float UNoesisGuiScrollContentPresenter::GetViewportHeight()
{
	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter);
	return (float)NoesisScrollContentPresenter->GetViewportHeight();
}

float UNoesisGuiScrollContentPresenter::GetViewportWidth()
{
	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	check(NoesisScrollContentPresenter);
	return (float)NoesisScrollContentPresenter->GetViewportWidth();
}

	void UNoesisGuiScrollContentPresenter::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::ScrollContentPresenter* NoesisScrollContentPresenter = NsDynamicCast<Noesis::Gui::ScrollContentPresenter*>(NoesisComponent.GetPtr());
	if (!NoesisScrollContentPresenter)
		return;

}

