////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDiscreteInt16KeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDiscreteInt16KeyFrame::UNoesisGuiDiscreteInt16KeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDiscreteInt16KeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<NsInt16>* NoesisDiscreteInt16KeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsInt16>*>(InNoesisComponent);
	check(NoesisDiscreteInt16KeyFrame);

}

	void UNoesisGuiDiscreteInt16KeyFrame::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::DiscreteKeyFrame<NsInt16>* NoesisDiscreteInt16KeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	if (!NoesisDiscreteInt16KeyFrame)
		return;

}

