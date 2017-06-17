////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisDiscreteSizeKeyFrame.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisDiscreteSizeKeyFrame::UNoesisDiscreteSizeKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Size>::StaticGetClassType();
}

void UNoesisDiscreteSizeKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Size>* NoesisDiscreteSizeKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Size>*>(InNoesisComponent);
	check(NoesisDiscreteSizeKeyFrame);
}

void UNoesisDiscreteSizeKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Size>* NoesisDiscreteSizeKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteSizeKeyFrame);


}

void UNoesisDiscreteSizeKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Size>* NoesisDiscreteSizeKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteSizeKeyFrame);


}

