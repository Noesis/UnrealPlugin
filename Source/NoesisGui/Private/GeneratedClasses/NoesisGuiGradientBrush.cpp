////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiGradientBrush.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiGradientBrush::UNoesisGuiGradientBrush(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiGradientBrush::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::GradientBrush* NoesisGradientBrush = NsDynamicCast<Noesis::Gui::GradientBrush*>(InNoesisComponent);
	check(NoesisGradientBrush);

}

	void UNoesisGuiGradientBrush::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::GradientBrush* NoesisGradientBrush = NsDynamicCast<Noesis::Gui::GradientBrush*>(NoesisComponent.GetPtr());
	if (!NoesisGradientBrush)
		return;

}

