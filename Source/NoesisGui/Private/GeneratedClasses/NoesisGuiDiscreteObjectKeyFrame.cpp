////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDiscreteObjectKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDiscreteObjectKeyFrame::UNoesisGuiDiscreteObjectKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDiscreteObjectKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>* NoesisDiscreteObjectKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>*>(InNoesisComponent);
	check(NoesisDiscreteObjectKeyFrame);

}

	void UNoesisGuiDiscreteObjectKeyFrame::BeginDestroy()
{
	Noesis::Gui::DiscreteKeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>* NoesisDiscreteObjectKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>*>(NoesisComponent.GetPtr());
	if (!NoesisDiscreteObjectKeyFrame)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

