////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisPointKeyFrame.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisPointKeyFrame::UNoesisPointKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::KeyFrame<Noesis::Drawing::Point>::StaticGetClassType();
}

void UNoesisPointKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<Noesis::Drawing::Point>* NoesisPointKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Point>*>(InNoesisComponent);
	check(NoesisPointKeyFrame);
}

FNoesisKeyTime UNoesisPointKeyFrame::GetKeyTime()
{
	Noesis::Gui::KeyFrame<Noesis::Drawing::Point>* NoesisPointKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Point>*>(NoesisComponent.GetPtr());
	check(NoesisPointKeyFrame);
	return FNoesisKeyTime(NoesisPointKeyFrame->GetKeyTime());
}

void UNoesisPointKeyFrame::SetKeyTime(FNoesisKeyTime InKeyTime)
{
	Noesis::Gui::KeyFrame<Noesis::Drawing::Point>* NoesisPointKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Point>*>(NoesisComponent.GetPtr());
	check(NoesisPointKeyFrame);
	NoesisPointKeyFrame->SetKeyTime(InKeyTime.ToNoesis());
}

void UNoesisPointKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeyFrame<Noesis::Drawing::Point>* NoesisPointKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Point>*>(NoesisComponent.GetPtr());
	check(NoesisPointKeyFrame);


}

void UNoesisPointKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeyFrame<Noesis::Drawing::Point>* NoesisPointKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Point>*>(NoesisComponent.GetPtr());
	check(NoesisPointKeyFrame);


}

