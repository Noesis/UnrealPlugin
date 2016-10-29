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

void UNoesisGuiLinearGradientBrush::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::LinearGradientBrush* NoesisLinearGradientBrush = NsDynamicCast<Noesis::Gui::LinearGradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisLinearGradientBrush)


}

void UNoesisGuiLinearGradientBrush::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::LinearGradientBrush* NoesisLinearGradientBrush = NsDynamicCast<Noesis::Gui::LinearGradientBrush*>(NoesisComponent.GetPtr());
	check(NoesisLinearGradientBrush)


}

