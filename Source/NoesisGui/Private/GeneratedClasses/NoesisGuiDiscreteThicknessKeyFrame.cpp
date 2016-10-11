////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDiscreteThicknessKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDiscreteThicknessKeyFrame::UNoesisGuiDiscreteThicknessKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDiscreteThicknessKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Thickness>* NoesisDiscreteThicknessKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Thickness>*>(InNoesisComponent);
	check(NoesisDiscreteThicknessKeyFrame);

}

	void UNoesisGuiDiscreteThicknessKeyFrame::BeginDestroy()
{
	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Thickness>* NoesisDiscreteThicknessKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	if (!NoesisDiscreteThicknessKeyFrame)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

