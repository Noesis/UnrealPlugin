////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTileBrush.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTileBrush::UNoesisGuiTileBrush(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTileBrush::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(InNoesisComponent);
	check(NoesisTileBrush);

}

	void UNoesisGuiTileBrush::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::TileBrush* NoesisTileBrush = NsDynamicCast<Noesis::Gui::TileBrush*>(NoesisComponent.GetPtr());
	if (!NoesisTileBrush)
		return;

}

