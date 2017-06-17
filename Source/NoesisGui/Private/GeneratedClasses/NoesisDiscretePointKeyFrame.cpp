////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisDiscretePointKeyFrame.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisDiscretePointKeyFrame::UNoesisDiscretePointKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Point>::StaticGetClassType();
}

void UNoesisDiscretePointKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Point>* NoesisDiscretePointKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Point>*>(InNoesisComponent);
	check(NoesisDiscretePointKeyFrame);
}

void UNoesisDiscretePointKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Point>* NoesisDiscretePointKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Point>*>(NoesisComponent.GetPtr());
	check(NoesisDiscretePointKeyFrame);


}

void UNoesisDiscretePointKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Point>* NoesisDiscretePointKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Point>*>(NoesisComponent.GetPtr());
	check(NoesisDiscretePointKeyFrame);


}

