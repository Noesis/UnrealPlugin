////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisBooleanKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisBooleanKeyFrame::UNoesisBooleanKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisBooleanKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<NsBool>* NoesisBooleanKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsBool>*>(InNoesisComponent);
	check(NoesisBooleanKeyFrame);
}

FNoesisKeyTime UNoesisBooleanKeyFrame::GetKeyTime()
{
	Noesis::Gui::KeyFrame<NsBool>* NoesisBooleanKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsBool>*>(NoesisComponent.GetPtr());
	check(NoesisBooleanKeyFrame);
	return FNoesisKeyTime(NoesisBooleanKeyFrame->GetKeyTime());
}

void UNoesisBooleanKeyFrame::SetKeyTime(FNoesisKeyTime InKeyTime)
{
	Noesis::Gui::KeyFrame<NsBool>* NoesisBooleanKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsBool>*>(NoesisComponent.GetPtr());
	check(NoesisBooleanKeyFrame);
	NoesisBooleanKeyFrame->SetKeyTime(InKeyTime.ToNoesis());
}

void UNoesisBooleanKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeyFrame<NsBool>* NoesisBooleanKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsBool>*>(NoesisComponent.GetPtr());
	check(NoesisBooleanKeyFrame)


}

void UNoesisBooleanKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeyFrame<NsBool>* NoesisBooleanKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsBool>*>(NoesisComponent.GetPtr());
	check(NoesisBooleanKeyFrame)


}

