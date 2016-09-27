////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiLinearInt32KeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiLinearInt32KeyFrame::UNoesisGuiLinearInt32KeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiLinearInt32KeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::LinearKeyFrame<NsInt32>* NoesisLinearInt32KeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<NsInt32>*>(InNoesisComponent);
	check(NoesisLinearInt32KeyFrame);

}

	void UNoesisGuiLinearInt32KeyFrame::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::LinearKeyFrame<NsInt32>* NoesisLinearInt32KeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	if (!NoesisLinearInt32KeyFrame)
		return;

}

