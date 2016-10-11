////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiEasingThicknessKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiEasingThicknessKeyFrame::UNoesisGuiEasingThicknessKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiEasingThicknessKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Thickness>* NoesisEasingThicknessKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Thickness>*>(InNoesisComponent);
	check(NoesisEasingThicknessKeyFrame);

}

	void UNoesisGuiEasingThicknessKeyFrame::BeginDestroy()
{
	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Thickness>* NoesisEasingThicknessKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	if (!NoesisEasingThicknessKeyFrame)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

