////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiRectKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiRectKeyFrame::UNoesisGuiRectKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiRectKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>* NoesisRectKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>*>(InNoesisComponent);
	check(NoesisRectKeyFrame);
}

void UNoesisGuiRectKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>* NoesisRectKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	check(NoesisRectKeyFrame)


}

void UNoesisGuiRectKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>* NoesisRectKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	check(NoesisRectKeyFrame)


}

