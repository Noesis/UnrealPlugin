////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisDiscreteThicknessKeyFrame.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisDiscreteThicknessKeyFrame::UNoesisDiscreteThicknessKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Thickness>::StaticGetClassType();
}

void UNoesisDiscreteThicknessKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Thickness>* NoesisDiscreteThicknessKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Thickness>*>(InNoesisComponent);
	check(NoesisDiscreteThicknessKeyFrame);
}

void UNoesisDiscreteThicknessKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Thickness>* NoesisDiscreteThicknessKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteThicknessKeyFrame);


}

void UNoesisDiscreteThicknessKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Thickness>* NoesisDiscreteThicknessKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteThicknessKeyFrame);


}

