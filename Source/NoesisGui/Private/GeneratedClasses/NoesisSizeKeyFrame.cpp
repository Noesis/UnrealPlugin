////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisSizeKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisSizeKeyFrame::UNoesisSizeKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::KeyFrame<Noesis::Drawing::Size>::StaticGetClassType();
}

void UNoesisSizeKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<Noesis::Drawing::Size>* NoesisSizeKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Size>*>(InNoesisComponent);
	check(NoesisSizeKeyFrame);
}

FNoesisKeyTime UNoesisSizeKeyFrame::GetKeyTime()
{
	Noesis::Gui::KeyFrame<Noesis::Drawing::Size>* NoesisSizeKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisSizeKeyFrame);
	return FNoesisKeyTime(NoesisSizeKeyFrame->GetKeyTime());
}

void UNoesisSizeKeyFrame::SetKeyTime(FNoesisKeyTime InKeyTime)
{
	Noesis::Gui::KeyFrame<Noesis::Drawing::Size>* NoesisSizeKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisSizeKeyFrame);
	NoesisSizeKeyFrame->SetKeyTime(InKeyTime.ToNoesis());
}

void UNoesisSizeKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeyFrame<Noesis::Drawing::Size>* NoesisSizeKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisSizeKeyFrame);


}

void UNoesisSizeKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeyFrame<Noesis::Drawing::Size>* NoesisSizeKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Size>*>(NoesisComponent.GetPtr());
	check(NoesisSizeKeyFrame);


}

