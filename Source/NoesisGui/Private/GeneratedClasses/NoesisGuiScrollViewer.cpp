////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiScrollViewer.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiScrollViewer::UNoesisGuiScrollViewer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiScrollViewer::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(InNoesisComponent);
	check(NoesisScrollViewer);
}

void UNoesisGuiScrollViewer::InvalidateScrollInfo()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->InvalidateScrollInfo();
}

void UNoesisGuiScrollViewer::LineDown()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->LineDown();
}

void UNoesisGuiScrollViewer::LineLeft()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->LineLeft();
}

void UNoesisGuiScrollViewer::LineRight()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->LineRight();
}

void UNoesisGuiScrollViewer::LineUp()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->LineUp();
}

void UNoesisGuiScrollViewer::PageDown()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->PageDown();
}

void UNoesisGuiScrollViewer::PageLeft()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->PageLeft();
}

void UNoesisGuiScrollViewer::PageRight()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->PageRight();
}

void UNoesisGuiScrollViewer::PageUp()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->PageUp();
}

void UNoesisGuiScrollViewer::ScrollToBottom()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->ScrollToBottom();
}

void UNoesisGuiScrollViewer::ScrollToEnd()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->ScrollToEnd();
}

void UNoesisGuiScrollViewer::ScrollToHome()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->ScrollToHome();
}

void UNoesisGuiScrollViewer::ScrollToHorizontalOffset(float InOffset)
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	NsFloat32 NoesisInOffset = InOffset;
	return NoesisScrollViewer->ScrollToHorizontalOffset(NoesisInOffset);
}

void UNoesisGuiScrollViewer::ScrollToLeftEnd()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->ScrollToLeftEnd();
}

void UNoesisGuiScrollViewer::ScrollToRightEnd()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->ScrollToRightEnd();
}

void UNoesisGuiScrollViewer::ScrollToTop()
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	return NoesisScrollViewer->ScrollToTop();
}

void UNoesisGuiScrollViewer::ScrollToVerticalOffset(float InOffset)
{
	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer);
	NsFloat32 NoesisInOffset = InOffset;
	return NoesisScrollViewer->ScrollToVerticalOffset(NoesisInOffset);
}

void UNoesisGuiScrollViewer::ScrollChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ScrollChangedEventArgs& InArgs)
{
	if (!ScrollChanged.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiScrollChangedEventArgs Args(Instance, InArgs);
	ScrollChanged.Broadcast(Sender, Args);
}

void UNoesisGuiScrollViewer::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer)

	ScrollChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiScrollViewer::ScrollChanged_Private);
	if (ScrollChanged.IsBound())
	{
		NoesisScrollViewer->ScrollChanged() += ScrollChanged_Delegate;
	}

}

void UNoesisGuiScrollViewer::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ScrollViewer* NoesisScrollViewer = NsDynamicCast<Noesis::Gui::ScrollViewer*>(NoesisComponent.GetPtr());
	check(NoesisScrollViewer)

	if (ScrollChanged.IsBound())
	{
		NoesisScrollViewer->ScrollChanged() -= ScrollChanged_Delegate;
	}

}

