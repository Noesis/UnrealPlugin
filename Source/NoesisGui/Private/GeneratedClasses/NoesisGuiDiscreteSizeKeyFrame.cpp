////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDiscreteSizeKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDiscreteSizeKeyFrame::UNoesisGuiDiscreteSizeKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDiscreteSizeKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Size>* NoesisDiscreteSizeKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Size>*>(InNoesisComponent);
	check(NoesisDiscreteSizeKeyFrame);
}

void UNoesisGuiDiscreteSizeKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Size>* NoesisDiscreteSizeKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteSizeKeyFrame)


}

void UNoesisGuiDiscreteSizeKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Size>* NoesisDiscreteSizeKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteSizeKeyFrame)


}

