////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisDoubleKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisDoubleKeyFrame::UNoesisDoubleKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisDoubleKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<NsFloat32>* NoesisDoubleKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsFloat32>*>(InNoesisComponent);
	check(NoesisDoubleKeyFrame);
}

FNoesisKeyTime UNoesisDoubleKeyFrame::GetKeyTime()
{
	Noesis::Gui::KeyFrame<NsFloat32>* NoesisDoubleKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisDoubleKeyFrame);
	return FNoesisKeyTime(NoesisDoubleKeyFrame->GetKeyTime());
}

void UNoesisDoubleKeyFrame::SetKeyTime(FNoesisKeyTime InKeyTime)
{
	Noesis::Gui::KeyFrame<NsFloat32>* NoesisDoubleKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisDoubleKeyFrame);
	NoesisDoubleKeyFrame->SetKeyTime(InKeyTime.ToNoesis());
}

void UNoesisDoubleKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeyFrame<NsFloat32>* NoesisDoubleKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisDoubleKeyFrame)


}

void UNoesisDoubleKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeyFrame<NsFloat32>* NoesisDoubleKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisDoubleKeyFrame)


}

