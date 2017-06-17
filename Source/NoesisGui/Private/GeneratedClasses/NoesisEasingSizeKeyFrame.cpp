////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisEasingSizeKeyFrame.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisEasingSizeKeyFrame::UNoesisEasingSizeKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Size>::StaticGetClassType();
}

void UNoesisEasingSizeKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Size>* NoesisEasingSizeKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Size>*>(InNoesisComponent);
	check(NoesisEasingSizeKeyFrame);
}

void UNoesisEasingSizeKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Size>* NoesisEasingSizeKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisEasingSizeKeyFrame);


}

void UNoesisEasingSizeKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Size>* NoesisEasingSizeKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisEasingSizeKeyFrame);


}

