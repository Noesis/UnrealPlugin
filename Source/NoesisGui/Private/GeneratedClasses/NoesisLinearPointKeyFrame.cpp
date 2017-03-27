////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisLinearPointKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisLinearPointKeyFrame::UNoesisLinearPointKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Point>::StaticGetClassType();
}

void UNoesisLinearPointKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Point>* NoesisLinearPointKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Point>*>(InNoesisComponent);
	check(NoesisLinearPointKeyFrame);
}

void UNoesisLinearPointKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Point>* NoesisLinearPointKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Point>*>(NoesisComponent.GetPtr());
	check(NoesisLinearPointKeyFrame);


}

void UNoesisLinearPointKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Point>* NoesisLinearPointKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Point>*>(NoesisComponent.GetPtr());
	check(NoesisLinearPointKeyFrame);


}

