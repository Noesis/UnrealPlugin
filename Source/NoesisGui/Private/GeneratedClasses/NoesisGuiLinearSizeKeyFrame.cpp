////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiLinearSizeKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiLinearSizeKeyFrame::UNoesisGuiLinearSizeKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiLinearSizeKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Size>* NoesisLinearSizeKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Size>*>(InNoesisComponent);
	check(NoesisLinearSizeKeyFrame);

}

	void UNoesisGuiLinearSizeKeyFrame::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Size>* NoesisLinearSizeKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	if (!NoesisLinearSizeKeyFrame)
		return;

}

