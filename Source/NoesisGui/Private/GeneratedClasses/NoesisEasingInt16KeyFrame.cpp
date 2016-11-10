////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisEasingInt16KeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisEasingInt16KeyFrame::UNoesisEasingInt16KeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisEasingInt16KeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EasingKeyFrame<NsInt16>* NoesisEasingInt16KeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<NsInt16>*>(InNoesisComponent);
	check(NoesisEasingInt16KeyFrame);
}

void UNoesisEasingInt16KeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::EasingKeyFrame<NsInt16>* NoesisEasingInt16KeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisEasingInt16KeyFrame)


}

void UNoesisEasingInt16KeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::EasingKeyFrame<NsInt16>* NoesisEasingInt16KeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisEasingInt16KeyFrame)


}

