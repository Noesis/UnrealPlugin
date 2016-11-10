////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisRectKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisRectKeyFrame::UNoesisRectKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisRectKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>* NoesisRectKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>*>(InNoesisComponent);
	check(NoesisRectKeyFrame);
}

FNoesisKeyTime UNoesisRectKeyFrame::GetKeyTime()
{
	Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>* NoesisRectKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	check(NoesisRectKeyFrame);
	return FNoesisKeyTime(NoesisRectKeyFrame->GetKeyTime());
}

void UNoesisRectKeyFrame::SetKeyTime(FNoesisKeyTime InKeyTime)
{
	Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>* NoesisRectKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	check(NoesisRectKeyFrame);
	NoesisRectKeyFrame->SetKeyTime(InKeyTime.ToNoesis());
}

void UNoesisRectKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>* NoesisRectKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	check(NoesisRectKeyFrame)


}

void UNoesisRectKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>* NoesisRectKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Rect>*>(NoesisComponent.GetPtr());
	check(NoesisRectKeyFrame)


}

