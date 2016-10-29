////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiEasingInt16KeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiEasingInt16KeyFrame::UNoesisGuiEasingInt16KeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiEasingInt16KeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EasingKeyFrame<NsInt16>* NoesisEasingInt16KeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<NsInt16>*>(InNoesisComponent);
	check(NoesisEasingInt16KeyFrame);
}

void UNoesisGuiEasingInt16KeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::EasingKeyFrame<NsInt16>* NoesisEasingInt16KeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisEasingInt16KeyFrame)


}

void UNoesisGuiEasingInt16KeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::EasingKeyFrame<NsInt16>* NoesisEasingInt16KeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisEasingInt16KeyFrame)


}

