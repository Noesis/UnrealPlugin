////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiEasingRectKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiEasingRectKeyFrame::UNoesisGuiEasingRectKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiEasingRectKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Rect>* NoesisEasingRectKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Rect>*>(InNoesisComponent);
	check(NoesisEasingRectKeyFrame);

}

	void UNoesisGuiEasingRectKeyFrame::BeginDestroy()
{
	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Rect>* NoesisEasingRectKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	if (!NoesisEasingRectKeyFrame)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

