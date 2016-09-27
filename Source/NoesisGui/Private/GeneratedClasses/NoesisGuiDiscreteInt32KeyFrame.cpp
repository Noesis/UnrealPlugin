////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDiscreteInt32KeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDiscreteInt32KeyFrame::UNoesisGuiDiscreteInt32KeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDiscreteInt32KeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<NsInt32>* NoesisDiscreteInt32KeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsInt32>*>(InNoesisComponent);
	check(NoesisDiscreteInt32KeyFrame);

}

	void UNoesisGuiDiscreteInt32KeyFrame::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::DiscreteKeyFrame<NsInt32>* NoesisDiscreteInt32KeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	if (!NoesisDiscreteInt32KeyFrame)
		return;

}

