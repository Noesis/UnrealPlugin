////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiEasingColorKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiEasingColorKeyFrame::UNoesisGuiEasingColorKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiEasingColorKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Color>* NoesisEasingColorKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Color>*>(InNoesisComponent);
	check(NoesisEasingColorKeyFrame);

}

	void UNoesisGuiEasingColorKeyFrame::BeginDestroy()
{
	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Color>* NoesisEasingColorKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	if (!NoesisEasingColorKeyFrame)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

