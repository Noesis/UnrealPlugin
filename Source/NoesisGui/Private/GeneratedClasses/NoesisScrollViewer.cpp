////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisScrollViewer.h"

using namespace Noesis;
using namespace Gui;

UNoesisScrollViewer::UNoesisScrollViewer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ScrollViewer::StaticGetClassType();
}

void UNoesisScrollViewer::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(InNoesisComponent);
	check(NoesisScrollViewer);
}

bool UNoesisScrollViewer::GetCanContentScroll()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->GetCanContentScroll();
}

void UNoesisScrollViewer::SetCanContentScroll(bool InCanContentScroll)
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	NoesisScrollViewer->SetCanContentScroll(InCanContentScroll);
}

ENoesisVisibility UNoesisScrollViewer::GetComputedHorizontalScrollBarVisibility()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return (ENoesisVisibility)NoesisScrollViewer->GetComputedHorizontalScrollBarVisibility();
}

ENoesisVisibility UNoesisScrollViewer::GetComputedVerticalScrollBarVisibility()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return (ENoesisVisibility)NoesisScrollViewer->GetComputedVerticalScrollBarVisibility();
}

float UNoesisScrollViewer::GetExtentHeight()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return (float)NoesisScrollViewer->GetExtentHeight();
}

float UNoesisScrollViewer::GetExtentWidth()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return (float)NoesisScrollViewer->GetExtentWidth();
}

float UNoesisScrollViewer::GetHorizontalOffset()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return (float)NoesisScrollViewer->GetHorizontalOffset();
}

ENoesisScrollBarVisibility UNoesisScrollViewer::GetHorizontalScrollBarVisibility()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return (ENoesisScrollBarVisibility)NoesisScrollViewer->GetHorizontalScrollBarVisibility();
}

void UNoesisScrollViewer::SetHorizontalScrollBarVisibility(ENoesisScrollBarVisibility InHorizontalScrollBarVisibility)
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	NoesisScrollViewer->SetHorizontalScrollBarVisibility((Noesis::Gui::ScrollBarVisibility)InHorizontalScrollBarVisibility);
}

bool UNoesisScrollViewer::GetIsDeferredScrollingEnabled()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->GetIsDeferredScrollingEnabled();
}

void UNoesisScrollViewer::SetIsDeferredScrollingEnabled(bool InIsDeferredScrollingEnabled)
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	NoesisScrollViewer->SetIsDeferredScrollingEnabled(InIsDeferredScrollingEnabled);
}

float UNoesisScrollViewer::GetPanningDeceleration()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return (float)NoesisScrollViewer->GetPanningDeceleration();
}

void UNoesisScrollViewer::SetPanningDeceleration(float InPanningDeceleration)
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	NoesisScrollViewer->SetPanningDeceleration(InPanningDeceleration);
}

ENoesisPanningMode UNoesisScrollViewer::GetPanningMode()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return (ENoesisPanningMode)NoesisScrollViewer->GetPanningMode();
}

void UNoesisScrollViewer::SetPanningMode(ENoesisPanningMode InPanningMode)
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	NoesisScrollViewer->SetPanningMode((Noesis::Gui::PanningMode)InPanningMode);
}

float UNoesisScrollViewer::GetPanningRatio()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return (float)NoesisScrollViewer->GetPanningRatio();
}

void UNoesisScrollViewer::SetPanningRatio(float InPanningRatio)
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	NoesisScrollViewer->SetPanningRatio(InPanningRatio);
}

float UNoesisScrollViewer::GetScrollableHeight()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return (float)NoesisScrollViewer->GetScrollableHeight();
}

float UNoesisScrollViewer::GetScrollableWidth()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return (float)NoesisScrollViewer->GetScrollableWidth();
}

float UNoesisScrollViewer::GetVerticalOffset()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return (float)NoesisScrollViewer->GetVerticalOffset();
}

ENoesisScrollBarVisibility UNoesisScrollViewer::GetVerticalScrollBarVisibility()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return (ENoesisScrollBarVisibility)NoesisScrollViewer->GetVerticalScrollBarVisibility();
}

void UNoesisScrollViewer::SetVerticalScrollBarVisibility(ENoesisScrollBarVisibility InVerticalScrollBarVisibility)
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	NoesisScrollViewer->SetVerticalScrollBarVisibility((Noesis::Gui::ScrollBarVisibility)InVerticalScrollBarVisibility);
}

float UNoesisScrollViewer::GetViewportHeight()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return (float)NoesisScrollViewer->GetViewportHeight();
}

float UNoesisScrollViewer::GetViewportWidth()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return (float)NoesisScrollViewer->GetViewportWidth();
}

void UNoesisScrollViewer::InvalidateScrollInfo()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->InvalidateScrollInfo();
}

void UNoesisScrollViewer::LineDown()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->LineDown();
}

void UNoesisScrollViewer::LineLeft()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->LineLeft();
}

void UNoesisScrollViewer::LineRight()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->LineRight();
}

void UNoesisScrollViewer::LineUp()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->LineUp();
}

void UNoesisScrollViewer::PageDown()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->PageDown();
}

void UNoesisScrollViewer::PageLeft()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->PageLeft();
}

void UNoesisScrollViewer::PageRight()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->PageRight();
}

void UNoesisScrollViewer::PageUp()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->PageUp();
}

void UNoesisScrollViewer::ScrollToBottom()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->ScrollToBottom();
}

void UNoesisScrollViewer::ScrollToEnd()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->ScrollToEnd();
}

void UNoesisScrollViewer::ScrollToHome()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->ScrollToHome();
}

void UNoesisScrollViewer::ScrollToHorizontalOffset(float InOffset)
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	NsFloat32 NoesisInOffset = InOffset;
	return NoesisScrollViewer->ScrollToHorizontalOffset(NoesisInOffset);
}

void UNoesisScrollViewer::ScrollToLeftEnd()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->ScrollToLeftEnd();
}

void UNoesisScrollViewer::ScrollToRightEnd()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->ScrollToRightEnd();
}

void UNoesisScrollViewer::ScrollToTop()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->ScrollToTop();
}

void UNoesisScrollViewer::ScrollToVerticalOffset(float InOffset)
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	NsFloat32 NoesisInOffset = InOffset;
	return NoesisScrollViewer->ScrollToVerticalOffset(NoesisInOffset);
}

void UNoesisScrollViewer::ScrollChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ScrollChangedEventArgs& InArgs)
{
	if (!ScrollChanged.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisScrollChangedEventArgs Args(InArgs);
	ScrollChanged.Broadcast(Sender, Args);
}

void UNoesisScrollViewer::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);

	ScrollChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisScrollViewer::ScrollChanged_Private);
	NoesisScrollViewer->ScrollChanged() += ScrollChanged_Delegate;

}

void UNoesisScrollViewer::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);

	NoesisScrollViewer->ScrollChanged() -= ScrollChanged_Delegate;

}

