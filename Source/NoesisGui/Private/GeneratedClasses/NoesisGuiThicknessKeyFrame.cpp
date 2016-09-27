////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiThicknessKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiThicknessKeyFrame::UNoesisGuiThicknessKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiThicknessKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<Noesis::Drawing::Thickness>* NoesisThicknessKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Thickness>*>(InNoesisComponent);
	check(NoesisThicknessKeyFrame);

}

	void UNoesisGuiThicknessKeyFrame::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::KeyFrame<Noesis::Drawing::Thickness>* NoesisThicknessKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	if (!NoesisThicknessKeyFrame)
		return;

}

