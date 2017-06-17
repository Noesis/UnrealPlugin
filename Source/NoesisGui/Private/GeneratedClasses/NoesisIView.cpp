////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisIView.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisIView::UNoesisIView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisInterfaceTypeClass = Noesis::Gui::IView::StaticGetClassType();
}

void UNoesisIView::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(InNoesisInterface);
	check(NoesisIView);
}

void UNoesisIView::Char(int32 InCh)
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	NsUInt32 NoesisInCh = InCh;
	return NoesisIView->Char(NoesisInCh);
}

class UNoesisFrameworkElement* UNoesisIView::GetContent()
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	return CastChecked<UNoesisFrameworkElement>(CreateClassFor(NoesisIView->GetContent(), nullptr), ECastCheckedType::NullAllowed);
}

FNoesisDrawingSizei UNoesisIView::GetSize()
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	return FNoesisDrawingSizei(NoesisIView->GetSize());
}

void UNoesisIView::MouseMove(int32 InX, int32 InY)
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	NsInt NoesisInX = InX;
	NsInt NoesisInY = InY;
	return NoesisIView->MouseMove(NoesisInX, NoesisInY);
}

void UNoesisIView::MouseWheel(int32 InX, int32 InY, int32 InWheelRotation)
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	NsInt NoesisInX = InX;
	NsInt NoesisInY = InY;
	NsInt NoesisInWheelRotation = InWheelRotation;
	return NoesisIView->MouseWheel(NoesisInX, NoesisInY, NoesisInWheelRotation);
}

void UNoesisIView::ResetInputState()
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	return NoesisIView->ResetInputState();
}

void UNoesisIView::SetFlags(int32 InFlags)
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	NsUInt32 NoesisInFlags = InFlags;
	return NoesisIView->SetFlags(NoesisInFlags);
}

void UNoesisIView::SetSize(int32 InWidth, int32 InHeight)
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	NsSize NoesisInWidth = (NsSize)InWidth;
	NsSize NoesisInHeight = (NsSize)InHeight;
	return NoesisIView->SetSize(NoesisInWidth, NoesisInHeight);
}

void UNoesisIView::TouchDown(int32 InX, int32 InY, int32 InId)
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	NsInt NoesisInX = InX;
	NsInt NoesisInY = InY;
	NsUInt32 NoesisInId = InId;
	return NoesisIView->TouchDown(NoesisInX, NoesisInY, NoesisInId);
}

void UNoesisIView::TouchMove(int32 InX, int32 InY, int32 InId)
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	NsInt NoesisInX = InX;
	NsInt NoesisInY = InY;
	NsUInt32 NoesisInId = InId;
	return NoesisIView->TouchMove(NoesisInX, NoesisInY, NoesisInId);
}

void UNoesisIView::TouchUp(int32 InX, int32 InY, int32 InId)
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	NsInt NoesisInX = InX;
	NsInt NoesisInY = InY;
	NsUInt32 NoesisInId = InId;
	return NoesisIView->TouchUp(NoesisInX, NoesisInY, NoesisInId);
}

void UNoesisIView::Update(float InTimeInSeconds)
{
	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);
	NsFloat64 NoesisInTimeInSeconds = (NsFloat64)InTimeInSeconds;
	return NoesisIView->Update(NoesisInTimeInSeconds);
}

void UNoesisIView::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);


}

void UNoesisIView::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IView* NoesisIView = NsDynamicCast<Noesis::Gui::IView*>(NoesisInterface.GetPtr());
	check(NoesisIView);


}

