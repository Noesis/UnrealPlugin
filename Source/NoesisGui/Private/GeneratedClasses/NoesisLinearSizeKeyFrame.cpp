////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisLinearSizeKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisLinearSizeKeyFrame::UNoesisLinearSizeKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Size>::StaticGetClassType();
}

void UNoesisLinearSizeKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Size>* NoesisLinearSizeKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Size>*>(InNoesisComponent);
	check(NoesisLinearSizeKeyFrame);
}

void UNoesisLinearSizeKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Size>* NoesisLinearSizeKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisLinearSizeKeyFrame);


}

void UNoesisLinearSizeKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Size>* NoesisLinearSizeKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisLinearSizeKeyFrame);


}

