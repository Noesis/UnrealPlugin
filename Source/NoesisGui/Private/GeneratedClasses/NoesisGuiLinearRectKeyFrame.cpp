////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiLinearRectKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiLinearRectKeyFrame::UNoesisGuiLinearRectKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiLinearRectKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Rect>* NoesisLinearRectKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Rect>*>(InNoesisComponent);
	check(NoesisLinearRectKeyFrame);

}

	void UNoesisGuiLinearRectKeyFrame::BeginDestroy()
{
	Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Rect>* NoesisLinearRectKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	if (!NoesisLinearRectKeyFrame)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

