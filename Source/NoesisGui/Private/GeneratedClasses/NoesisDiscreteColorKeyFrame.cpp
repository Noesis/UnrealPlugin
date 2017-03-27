////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisDiscreteColorKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisDiscreteColorKeyFrame::UNoesisDiscreteColorKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Color>::StaticGetClassType();
}

void UNoesisDiscreteColorKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Color>* NoesisDiscreteColorKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Color>*>(InNoesisComponent);
	check(NoesisDiscreteColorKeyFrame);
}

void UNoesisDiscreteColorKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Color>* NoesisDiscreteColorKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteColorKeyFrame);


}

void UNoesisDiscreteColorKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Color>* NoesisDiscreteColorKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteColorKeyFrame);


}

