////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisDiscreteStringKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisDiscreteStringKeyFrame::UNoesisDiscreteStringKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisDiscreteStringKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<NsString>* NoesisDiscreteStringKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsString>*>(InNoesisComponent);
	check(NoesisDiscreteStringKeyFrame);
}

void UNoesisDiscreteStringKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DiscreteKeyFrame<NsString>* NoesisDiscreteStringKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsString>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteStringKeyFrame)


}

void UNoesisDiscreteStringKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DiscreteKeyFrame<NsString>* NoesisDiscreteStringKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsString>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteStringKeyFrame)


}

