////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisDiscreteBooleanKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisDiscreteBooleanKeyFrame::UNoesisDiscreteBooleanKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisDiscreteBooleanKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<NsBool>* NoesisDiscreteBooleanKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsBool>*>(InNoesisComponent);
	check(NoesisDiscreteBooleanKeyFrame);
}

void UNoesisDiscreteBooleanKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DiscreteKeyFrame<NsBool>* NoesisDiscreteBooleanKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsBool>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteBooleanKeyFrame)


}

void UNoesisDiscreteBooleanKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DiscreteKeyFrame<NsBool>* NoesisDiscreteBooleanKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsBool>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteBooleanKeyFrame)


}

