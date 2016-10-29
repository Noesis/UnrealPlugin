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

void UNoesisGuiDiscreteInt16KeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DiscreteKeyFrame<NsInt16>* NoesisDiscreteInt16KeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteInt16KeyFrame)


}

void UNoesisGuiDiscreteInt16KeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DiscreteKeyFrame<NsInt16>* NoesisDiscreteInt16KeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteInt16KeyFrame)


}

