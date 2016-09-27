////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiLinearGradientBrush.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiLinearGradientBrush::UNoesisGuiLinearGradientBrush(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiLinearGradientBrush::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::LinearGradientBrush* NoesisLinearGradientBrush = NsDynamicCast<Noesis::Gui::LinearGradientBrush*>(InNoesisComponent);
	check(NoesisLinearGradientBrush);

}

	void UNoesisGuiLinearGradientBrush::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::LinearGradientBrush* NoesisLinearGradientBrush = NsDynamicCast<Noesis::Gui::LinearGradientBrush*>(NoesisComponent.GetPtr());
	if (!NoesisLinearGradientBrush)
		return;

}

