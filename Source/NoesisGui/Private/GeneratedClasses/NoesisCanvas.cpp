////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisCanvas.h"

using namespace Noesis;
using namespace Gui;

UNoesisCanvas::UNoesisCanvas(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::Canvas::StaticGetClassType();
}

void UNoesisCanvas::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Canvas* NoesisCanvas = NsDynamicCast<Noesis::Gui::Canvas*>(InNoesisComponent);
	check(NoesisCanvas);
}

void UNoesisCanvas::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Canvas* NoesisCanvas = NsDynamicCast<Noesis::Gui::Canvas*>(NoesisComponent.GetPtr());
	check(NoesisCanvas);


}

void UNoesisCanvas::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Canvas* NoesisCanvas = NsDynamicCast<Noesis::Gui::Canvas*>(NoesisComponent.GetPtr());
	check(NoesisCanvas);


}

