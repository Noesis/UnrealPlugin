////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSizeKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSizeKeyFrame::UNoesisGuiSizeKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSizeKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<Noesis::Drawing::Size>* NoesisSizeKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Size>*>(InNoesisComponent);
	check(NoesisSizeKeyFrame);

}

	void UNoesisGuiSizeKeyFrame::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::KeyFrame<Noesis::Drawing::Size>* NoesisSizeKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	if (!NoesisSizeKeyFrame)
		return;

}

