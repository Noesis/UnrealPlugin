////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiPointKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiPointKeyFrame::UNoesisGuiPointKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiPointKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<Noesis::Drawing::Point>* NoesisPointKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Point>*>(InNoesisComponent);
	check(NoesisPointKeyFrame);

}

	void UNoesisGuiPointKeyFrame::BeginDestroy()
{
	Noesis::Gui::KeyFrame<Noesis::Drawing::Point>* NoesisPointKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Point>*>(NoesisComponent.GetPtr());
	if (!NoesisPointKeyFrame)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

