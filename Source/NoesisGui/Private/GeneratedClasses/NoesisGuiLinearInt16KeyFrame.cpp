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

	void UNoesisGuiLinearInt16KeyFrame::BeginDestroy()
{
	Noesis::Gui::LinearKeyFrame<NsInt16>* NoesisLinearInt16KeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<NsInt16>*>(NoesisComponent.GetPtr());
	if (!NoesisLinearInt16KeyFrame)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

