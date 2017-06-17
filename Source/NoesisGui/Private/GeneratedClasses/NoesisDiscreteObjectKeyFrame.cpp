////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisDiscreteObjectKeyFrame.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisDiscreteObjectKeyFrame::UNoesisDiscreteObjectKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::DiscreteKeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>::StaticGetClassType();
}

void UNoesisDiscreteObjectKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::DiscreteKeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>* NoesisDiscreteObjectKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>*>(InNoesisComponent);
	check(NoesisDiscreteObjectKeyFrame);
}

void UNoesisDiscreteObjectKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::DiscreteKeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>* NoesisDiscreteObjectKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteObjectKeyFrame);


}

void UNoesisDiscreteObjectKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::DiscreteKeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>* NoesisDiscreteObjectKeyFrame = NsDynamicCast<Noesis::Gui::DiscreteKeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>*>(NoesisComponent.GetPtr());
	check(NoesisDiscreteObjectKeyFrame);


}

