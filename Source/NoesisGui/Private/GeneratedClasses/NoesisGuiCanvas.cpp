////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiCanvas.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiCanvas::UNoesisGuiCanvas(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiCanvas::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Canvas* NoesisCanvas = NsDynamicCast<Noesis::Gui::Canvas*>(InNoesisComponent);
	check(NoesisCanvas);
}

void UNoesisGuiCanvas::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Canvas* NoesisCanvas = NsDynamicCast<Noesis::Gui::Canvas*>(NoesisComponent.GetPtr());
	check(NoesisCanvas)


}

void UNoesisGuiCanvas::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Canvas* NoesisCanvas = NsDynamicCast<Noesis::Gui::Canvas*>(NoesisComponent.GetPtr());
	check(NoesisCanvas)


}

