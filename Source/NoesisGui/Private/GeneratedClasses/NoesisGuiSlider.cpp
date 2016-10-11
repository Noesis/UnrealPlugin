////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSlider.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSlider::UNoesisGuiSlider(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSlider::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(InNoesisComponent);
	check(NoesisSlider);

}

	void UNoesisGuiSlider::BeginDestroy()
{
	Noesis::Gui::Slider* NoesisSlider = NsDynamicCast<Noesis::Gui::Slider*>(NoesisComponent.GetPtr());
	if (!NoesisSlider)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

