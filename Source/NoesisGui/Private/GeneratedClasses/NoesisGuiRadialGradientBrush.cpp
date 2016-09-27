////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiRadialGradientBrush.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiRadialGradientBrush::UNoesisGuiRadialGradientBrush(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiRadialGradientBrush::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RadialGradientBrush* NoesisRadialGradientBrush = NsDynamicCast<Noesis::Gui::RadialGradientBrush*>(InNoesisComponent);
	check(NoesisRadialGradientBrush);

}

	void UNoesisGuiRadialGradientBrush::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::RadialGradientBrush* NoesisRadialGradientBrush = NsDynamicCast<Noesis::Gui::RadialGradientBrush*>(NoesisComponent.GetPtr());
	if (!NoesisRadialGradientBrush)
		return;

}

