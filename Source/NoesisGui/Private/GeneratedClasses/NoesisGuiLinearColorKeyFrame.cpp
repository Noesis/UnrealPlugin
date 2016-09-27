////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiLinearColorKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiLinearColorKeyFrame::UNoesisGuiLinearColorKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiLinearColorKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Color>* NoesisLinearColorKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Color>*>(InNoesisComponent);
	check(NoesisLinearColorKeyFrame);

}

	void UNoesisGuiLinearColorKeyFrame::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Color>* NoesisLinearColorKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	if (!NoesisLinearColorKeyFrame)
		return;

}

