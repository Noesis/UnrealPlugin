////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisThicknessKeyFrame.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisThicknessKeyFrame::UNoesisThicknessKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::KeyFrame<Noesis::Drawing::Thickness>::StaticGetClassType();
}

void UNoesisThicknessKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<Noesis::Drawing::Thickness>* NoesisThicknessKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Thickness>*>(InNoesisComponent);
	check(NoesisThicknessKeyFrame);
}

FNoesisKeyTime UNoesisThicknessKeyFrame::GetKeyTime()
{
	Noesis::Gui::KeyFrame<Noesis::Drawing::Thickness>* NoesisThicknessKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	check(NoesisThicknessKeyFrame);
	return FNoesisKeyTime(NoesisThicknessKeyFrame->GetKeyTime());
}

void UNoesisThicknessKeyFrame::SetKeyTime(FNoesisKeyTime InKeyTime)
{
	Noesis::Gui::KeyFrame<Noesis::Drawing::Thickness>* NoesisThicknessKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	check(NoesisThicknessKeyFrame);
	NoesisThicknessKeyFrame->SetKeyTime(InKeyTime.ToNoesis());
}

void UNoesisThicknessKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeyFrame<Noesis::Drawing::Thickness>* NoesisThicknessKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	check(NoesisThicknessKeyFrame);


}

void UNoesisThicknessKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeyFrame<Noesis::Drawing::Thickness>* NoesisThicknessKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Thickness>*>(NoesisComponent.GetPtr());
	check(NoesisThicknessKeyFrame);


}

