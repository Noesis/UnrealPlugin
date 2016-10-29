////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiLinearInt16KeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiLinearInt16KeyFrame::UNoesisGuiLinearInt16KeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiLinearInt16KeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::LinearKeyFrame<NsInt16>* NoesisLinearInt16KeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<NsInt16>*>(InNoesisComponent);
	check(NoesisLinearInt16KeyFrame);
}

void UNoesisGuiLinearInt16KeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::LinearKeyFrame<NsInt16>* NoesisLinearInt16KeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisLinearInt16KeyFrame)


}

void UNoesisGuiLinearInt16KeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::LinearKeyFrame<NsInt16>* NoesisLinearInt16KeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	check(NoesisLinearInt16KeyFrame)


}

