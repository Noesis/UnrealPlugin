////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiIView.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiIView::UNoesisGuiIView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiIView::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(InNoesisInterface);
	check(NoesisIView);

}

void UNoesisGuiIView::Char(int32 InCh)
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	NsUInt32 NoesisInCh = InCh;
	return NoesisIView->Char(NoesisInCh);
}

class UNoesisGuiFrameworkElement* UNoesisGuiIView::GetContent()
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	return CastChecked<UNoesisGuiFrameworkElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisIView->GetContent()));
}

FNoesisGuiDrawingSizei UNoesisGuiIView::GetSize()
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	return FNoesisGuiDrawingSizei(NoesisIView->GetSize());
}

class UNoesisGuiResourceDictionary* UNoesisGuiIView::GetThemeResources()
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	return CastChecked<UNoesisGuiResourceDictionary>(Instance->FindUnrealComponentForNoesisComponent(NoesisIView->GetThemeResources()));
}

void UNoesisGuiIView::MouseMove(int32 InX, int32 InY)
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	NsInt NoesisInX = InX;
	NsInt NoesisInY = InY;
	return NoesisIView->MouseMove(NoesisInX, NoesisInY);
}

void UNoesisGuiIView::MouseWheel(int32 InX, int32 InY, int32 InWheelRotation)
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	NsInt NoesisInX = InX;
	NsInt NoesisInY = InY;
	NsInt NoesisInWheelRotation = InWheelRotation;
	return NoesisIView->MouseWheel(NoesisInX, NoesisInY, NoesisInWheelRotation);
}

void UNoesisGuiIView::ResetInputState()
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	return NoesisIView->ResetInputState();
}

void UNoesisGuiIView::SetFlags(int32 InFlags)
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	NsUInt32 NoesisInFlags = InFlags;
	return NoesisIView->SetFlags(NoesisInFlags);
}

void UNoesisGuiIView::SetSize(int32 InWidth, int32 InHeight)
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	NsSize NoesisInWidth = InWidth;
	NsSize NoesisInHeight = InHeight;
	return NoesisIView->SetSize(NoesisInWidth, NoesisInHeight);
}

void UNoesisGuiIView::TouchDown(int32 InX, int32 InY, int32 InId)
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	NsInt NoesisInX = InX;
	NsInt NoesisInY = InY;
	NsUInt32 NoesisInId = InId;
	return NoesisIView->TouchDown(NoesisInX, NoesisInY, NoesisInId);
}

void UNoesisGuiIView::TouchMove(int32 InX, int32 InY, int32 InId)
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	NsInt NoesisInX = InX;
	NsInt NoesisInY = InY;
	NsUInt32 NoesisInId = InId;
	return NoesisIView->TouchMove(NoesisInX, NoesisInY, NoesisInId);
}

void UNoesisGuiIView::TouchUp(int32 InX, int32 InY, int32 InId)
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	NsInt NoesisInX = InX;
	NsInt NoesisInY = InY;
	NsUInt32 NoesisInId = InId;
	return NoesisIView->TouchUp(NoesisInX, NoesisInY, NoesisInId);
}

void UNoesisGuiIView::Update(float InTimeInSeconds)
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	NsFloat64 NoesisInTimeInSeconds = InTimeInSeconds;
	return NoesisIView->Update(NoesisInTimeInSeconds);
}

	void UNoesisGuiIView::BeginDestroy()
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	if (!NoesisIView)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

