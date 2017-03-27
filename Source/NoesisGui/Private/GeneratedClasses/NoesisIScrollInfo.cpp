////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisIScrollInfo.h"

using namespace Noesis;
using namespace Gui;

UNoesisIScrollInfo::UNoesisIScrollInfo(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisInterfaceTypeClass = Noesis::Gui::IScrollInfo::StaticGetClassType();
}

void UNoesisIScrollInfo::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(InNoesisInterface);
	check(NoesisIScrollInfo);
}

void UNoesisIScrollInfo::LineDown()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->LineDown();
}

void UNoesisIScrollInfo::LineLeft()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->LineLeft();
}

void UNoesisIScrollInfo::LineRight()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->LineRight();
}

void UNoesisIScrollInfo::LineUp()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->LineUp();
}

FNoesisDrawingRect UNoesisIScrollInfo::MakeVisible(class UNoesisVisual* InVisual, FNoesisDrawingRect InRectangle)
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	Visual* NoesisInVisual = NsDynamicCast<Visual*>(InVisual->NoesisComponent.GetPtr());
	const Drawing::Rect NoesisInRectangle = InRectangle.ToNoesis();
	return FNoesisDrawingRect(NoesisIScrollInfo->MakeVisible(NoesisInVisual, NoesisInRectangle));
}

void UNoesisIScrollInfo::MouseWheelDown(float InDelta)
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	NsFloat32 NoesisInDelta = InDelta;
	return NoesisIScrollInfo->MouseWheelDown(NoesisInDelta);
}

void UNoesisIScrollInfo::MouseWheelLeft(float InDelta)
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	NsFloat32 NoesisInDelta = InDelta;
	return NoesisIScrollInfo->MouseWheelLeft(NoesisInDelta);
}

void UNoesisIScrollInfo::MouseWheelRight(float InDelta)
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	NsFloat32 NoesisInDelta = InDelta;
	return NoesisIScrollInfo->MouseWheelRight(NoesisInDelta);
}

void UNoesisIScrollInfo::MouseWheelUp(float InDelta)
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	NsFloat32 NoesisInDelta = InDelta;
	return NoesisIScrollInfo->MouseWheelUp(NoesisInDelta);
}

void UNoesisIScrollInfo::PageDown()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->PageDown();
}

void UNoesisIScrollInfo::PageLeft()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->PageLeft();
}

void UNoesisIScrollInfo::PageRight()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->PageRight();
}

void UNoesisIScrollInfo::PageUp()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->PageUp();
}

void UNoesisIScrollInfo::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);


}

void UNoesisIScrollInfo::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);


}

