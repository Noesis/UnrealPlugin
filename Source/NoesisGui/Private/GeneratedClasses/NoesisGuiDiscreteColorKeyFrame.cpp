////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDiscreteColorKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDiscreteColorKeyFrame::UNoesisGuiDiscreteColorKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDiscreteColorKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Color>* NoesisDiscreteColorKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Color>*>(InNoesisComponent);
	check(NoesisDiscreteColorKeyFrame);
}

void UNoesisGuiDiscreteColorKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Color>* NoesisDiscreteColorKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteColorKeyFrame)


}

void UNoesisGuiDiscreteColorKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Color>* NoesisDiscreteColorKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteColorKeyFrame)


}

