////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisDiscreteDoubleKeyFrame.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisDiscreteDoubleKeyFrame::UNoesisDiscreteDoubleKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::DiscreteKeyFrame<NsFloat32>::StaticGetClassType();
}

void UNoesisDiscreteDoubleKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<NsFloat32>* NoesisDiscreteDoubleKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsFloat32>*>(InNoesisComponent);
	check(NoesisDiscreteDoubleKeyFrame);
}

void UNoesisDiscreteDoubleKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DiscreteKeyFrame<NsFloat32>* NoesisDiscreteDoubleKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteDoubleKeyFrame);


}

void UNoesisDiscreteDoubleKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DiscreteKeyFrame<NsFloat32>* NoesisDiscreteDoubleKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteDoubleKeyFrame);


}

