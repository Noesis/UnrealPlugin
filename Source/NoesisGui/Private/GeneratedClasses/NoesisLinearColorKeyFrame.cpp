////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisLinearColorKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisLinearColorKeyFrame::UNoesisLinearColorKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Color>::StaticGetClassType();
}

void UNoesisLinearColorKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Color>* NoesisLinearColorKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Color>*>(InNoesisComponent);
	check(NoesisLinearColorKeyFrame);
}

void UNoesisLinearColorKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Color>* NoesisLinearColorKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	check(NoesisLinearColorKeyFrame);


}

void UNoesisLinearColorKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Color>* NoesisLinearColorKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	check(NoesisLinearColorKeyFrame);


}

