////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiLine.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiLine::UNoesisGuiLine(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiLine::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Line* NoesisLine = NsDynamicCast<Noesis::Gui::Line*>(InNoesisComponent);
	check(NoesisLine);
}

void UNoesisGuiLine::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Line* NoesisLine = NsDynamicCast<Noesis::Gui::Line*>(NoesisComponent.GetPtr());
	check(NoesisLine)


}

void UNoesisGuiLine::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Line* NoesisLine = NsDynamicCast<Noesis::Gui::Line*>(NoesisComponent.GetPtr());
	check(NoesisLine)


}

