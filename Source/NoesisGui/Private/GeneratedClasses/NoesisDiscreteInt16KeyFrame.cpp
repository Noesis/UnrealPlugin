////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisDiscreteInt16KeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisDiscreteInt16KeyFrame::UNoesisDiscreteInt16KeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisDiscreteInt16KeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<NsInt16>* NoesisDiscreteInt16KeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsInt16>*>(InNoesisComponent);
	check(NoesisDiscreteInt16KeyFrame);
}

void UNoesisDiscreteInt16KeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DiscreteKeyFrame<NsInt16>* NoesisDiscreteInt16KeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteInt16KeyFrame)


}

void UNoesisDiscreteInt16KeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DiscreteKeyFrame<NsInt16>* NoesisDiscreteInt16KeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteInt16KeyFrame)


}

