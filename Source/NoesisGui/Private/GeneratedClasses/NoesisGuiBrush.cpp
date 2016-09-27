////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBrush.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBrush::UNoesisGuiBrush(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBrush::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Brush* NoesisBrush = NsDynamicCast<Noesis::Gui::Brush*>(InNoesisComponent);
	check(NoesisBrush);

}

	void UNoesisGuiBrush::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Brush* NoesisBrush = NsDynamicCast<Noesis::Gui::Brush*>(NoesisComponent.GetPtr());
	if (!NoesisBrush)
		return;

}

