////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDiscreteRectKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDiscreteRectKeyFrame::UNoesisGuiDiscreteRectKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDiscreteRectKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Rect>* NoesisDiscreteRectKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Rect>*>(InNoesisComponent);
	check(NoesisDiscreteRectKeyFrame);

}

	void UNoesisGuiDiscreteRectKeyFrame::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Rect>* NoesisDiscreteRectKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	if (!NoesisDiscreteRectKeyFrame)
		return;

}

