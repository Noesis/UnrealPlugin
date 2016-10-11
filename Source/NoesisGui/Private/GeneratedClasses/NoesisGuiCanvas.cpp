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

	void UNoesisGuiCanvas::BeginDestroy()
{
	Noesis::Gui::Canvas* NoesisCanvas = NsDynamicCast<Noesis::Gui::Canvas*>(NoesisComponent.GetPtr());
	if (!NoesisCanvas)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

