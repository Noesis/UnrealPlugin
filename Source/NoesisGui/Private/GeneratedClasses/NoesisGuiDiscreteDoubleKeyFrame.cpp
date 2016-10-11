////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDiscreteDoubleKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDiscreteDoubleKeyFrame::UNoesisGuiDiscreteDoubleKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDiscreteDoubleKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<NsFloat32>* NoesisDiscreteDoubleKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsFloat32>*>(InNoesisComponent);
	check(NoesisDiscreteDoubleKeyFrame);

}

	void UNoesisGuiDiscreteDoubleKeyFrame::BeginDestroy()
{
	Noesis::Gui::DiscreteKeyFrame<NsFloat32>* NoesisDiscreteDoubleKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	if (!NoesisDiscreteDoubleKeyFrame)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

