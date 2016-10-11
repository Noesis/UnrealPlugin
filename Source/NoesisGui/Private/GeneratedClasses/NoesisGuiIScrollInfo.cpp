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

void UNoesisGuiIScrollInfo::MouseWheelDown()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->MouseWheelDown();
}

void UNoesisGuiIScrollInfo::MouseWheelLeft()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->MouseWheelLeft();
}

void UNoesisGuiIScrollInfo::MouseWheelRight()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->MouseWheelRight();
}

void UNoesisGuiIScrollInfo::MouseWheelUp()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	check(NoesisIScrollInfo);
	return NoesisIScrollInfo->MouseWheelUp();
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

	void UNoesisGuiIScrollInfo::BeginDestroy()
{
	Noesis::Gui::IScrollInfo* NoesisIScrollInfo = NsDynamicCast<Noesis::Gui::IScrollInfo*>(NoesisInterface.GetPtr());
	if (!NoesisIScrollInfo)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

