////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiVisualBrush.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiVisualBrush::UNoesisGuiVisualBrush(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiVisualBrush::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::VisualBrush* NoesisVisualBrush = NsDynamicCast<Noesis::Gui::VisualBrush*>(InNoesisComponent);
	check(NoesisVisualBrush);

}

	void UNoesisGuiVisualBrush::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::VisualBrush* NoesisVisualBrush = NsDynamicCast<Noesis::Gui::VisualBrush*>(NoesisComponent.GetPtr());
	if (!NoesisVisualBrush)
		return;

}

