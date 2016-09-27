////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDiscreteStringKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDiscreteStringKeyFrame::UNoesisGuiDiscreteStringKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDiscreteStringKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<NsString>* NoesisDiscreteStringKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsString>*>(InNoesisComponent);
	check(NoesisDiscreteStringKeyFrame);

}

	void UNoesisGuiDiscreteStringKeyFrame::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::DiscreteKeyFrame<NsString>* NoesisDiscreteStringKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsString>*>(NoesisComponent.GetPtr());
	if (!NoesisDiscreteStringKeyFrame)
		return;

}

