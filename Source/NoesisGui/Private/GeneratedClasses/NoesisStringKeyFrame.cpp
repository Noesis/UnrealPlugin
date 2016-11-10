////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisStringKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisStringKeyFrame::UNoesisStringKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisStringKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<NsString>* NoesisStringKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsString>*>(InNoesisComponent);
	check(NoesisStringKeyFrame);
}

FNoesisKeyTime UNoesisStringKeyFrame::GetKeyTime()
{
	Noesis::Gui::KeyFrame<NsString>* NoesisStringKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsString>*>(NoesisComponent.GetPtr());
	check(NoesisStringKeyFrame);
	return FNoesisKeyTime(NoesisStringKeyFrame->GetKeyTime());
}

void UNoesisStringKeyFrame::SetKeyTime(FNoesisKeyTime InKeyTime)
{
	Noesis::Gui::KeyFrame<NsString>* NoesisStringKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsString>*>(NoesisComponent.GetPtr());
	check(NoesisStringKeyFrame);
	NoesisStringKeyFrame->SetKeyTime(InKeyTime.ToNoesis());
}

void UNoesisStringKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeyFrame<NsString>* NoesisStringKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsString>*>(NoesisComponent.GetPtr());
	check(NoesisStringKeyFrame)


}

void UNoesisStringKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeyFrame<NsString>* NoesisStringKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsString>*>(NoesisComponent.GetPtr());
	check(NoesisStringKeyFrame)


}

