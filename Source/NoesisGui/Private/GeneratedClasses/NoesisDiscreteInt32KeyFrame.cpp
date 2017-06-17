////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisDiscreteInt32KeyFrame.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisDiscreteInt32KeyFrame::UNoesisDiscreteInt32KeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::DiscreteKeyFrame<NsInt32>::StaticGetClassType();
}

void UNoesisDiscreteInt32KeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<NsInt32>* NoesisDiscreteInt32KeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsInt32>*>(InNoesisComponent);
	check(NoesisDiscreteInt32KeyFrame);
}

void UNoesisDiscreteInt32KeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DiscreteKeyFrame<NsInt32>* NoesisDiscreteInt32KeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteInt32KeyFrame);


}

void UNoesisDiscreteInt32KeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DiscreteKeyFrame<NsInt32>* NoesisDiscreteInt32KeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteInt32KeyFrame);


}

