////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiEasingPointKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiEasingPointKeyFrame::UNoesisGuiEasingPointKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiEasingPointKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Point>* NoesisEasingPointKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Point>*>(InNoesisComponent);
	check(NoesisEasingPointKeyFrame);

}

	void UNoesisGuiEasingPointKeyFrame::BeginDestroy()
{
	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Point>* NoesisEasingPointKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Point>*>(NoesisComponent.GetPtr());
	if (!NoesisEasingPointKeyFrame)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

