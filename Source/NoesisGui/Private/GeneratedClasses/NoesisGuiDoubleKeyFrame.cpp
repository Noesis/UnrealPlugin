////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiDoubleKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiDoubleKeyFrame::UNoesisGuiDoubleKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiDoubleKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<NsFloat32>* NoesisDoubleKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsFloat32>*>(InNoesisComponent);
	check(NoesisDoubleKeyFrame);

}

	void UNoesisGuiDoubleKeyFrame::BeginDestroy()
{
	Noesis::Gui::KeyFrame<NsFloat32>* NoesisDoubleKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	if (!NoesisDoubleKeyFrame)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

