////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDiscreteBooleanKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDiscreteBooleanKeyFrame::UNoesisGuiDiscreteBooleanKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDiscreteBooleanKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<NsBool>* NoesisDiscreteBooleanKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsBool>*>(InNoesisComponent);
	check(NoesisDiscreteBooleanKeyFrame);

}

	void UNoesisGuiDiscreteBooleanKeyFrame::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::DiscreteKeyFrame<NsBool>* NoesisDiscreteBooleanKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsBool>*>(NoesisComponent.GetPtr());
	if (!NoesisDiscreteBooleanKeyFrame)
		return;

}

