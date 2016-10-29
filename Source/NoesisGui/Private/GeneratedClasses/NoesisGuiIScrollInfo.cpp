////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiIScrollInfo.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiIScrollInfo::UNoesisGuiIScrollInfo(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiIScrollInfo::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(InNoesisInterface);
	check(NoesisIScrollInfo);
}

void UNoesisGuiIScrollInfo::LineDown()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->LineDown();
}

void UNoesisGuiIScrollInfo::LineLeft()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->LineLeft();
}

void UNoesisGuiIScrollInfo::LineRight()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->LineRight();
}

void UNoesisGuiIScrollInfo::LineUp()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->LineUp();
}

FNoesisGuiDrawingRect UNoesisGuiIScrollInfo::MakeVisible(class UNoesisGuiVisual* InVisual, FNoesisGuiDrawingRect InRectangle)
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	Visual* NoesisInVisual = NsDynamicCast<Visual*>(InVisual->NoesisComponent.GetPtr());
	const Drawing::Rect NoesisInRectangle = InRectangle.ToNoesis();
	return FNoesisGuiDrawingRect(NoesisIScrollInfo->MakeVisible(NoesisInVisual, NoesisInRectangle));
}

void UNoesisGuiIScrollInfo::MouseWheelDown(float InDelta)
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	NsFloat32 NoesisInDelta = InDelta;
	return NoesisIScrollInfo->MouseWheelDown(NoesisInDelta);
}

void UNoesisGuiIScrollInfo::MouseWheelLeft(float InDelta)
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	NsFloat32 NoesisInDelta = InDelta;
	return NoesisIScrollInfo->MouseWheelLeft(NoesisInDelta);
}

void UNoesisGuiIScrollInfo::MouseWheelRight(float InDelta)
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	NsFloat32 NoesisInDelta = InDelta;
	return NoesisIScrollInfo->MouseWheelRight(NoesisInDelta);
}

void UNoesisGuiIScrollInfo::MouseWheelUp(float InDelta)
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	NsFloat32 NoesisInDelta = InDelta;
	return NoesisIScrollInfo->MouseWheelUp(NoesisInDelta);
}

void UNoesisGuiIScrollInfo::PageDown()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->PageDown();
}

void UNoesisGuiIScrollInfo::PageLeft()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->PageLeft();
}

void UNoesisGuiIScrollInfo::PageRight()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->PageRight();
}

void UNoesisGuiIScrollInfo::PageUp()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->PageUp();
}

void UNoesisGuiIScrollInfo::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo)


}

void UNoesisGuiIScrollInfo::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo)


}

