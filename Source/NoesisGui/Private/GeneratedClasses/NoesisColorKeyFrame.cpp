////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisColorKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisColorKeyFrame::UNoesisColorKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::KeyFrame<Noesis::Drawing::Color>::StaticGetClassType();
}

void UNoesisColorKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<Noesis::Drawing::Color>* NoesisColorKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Color>*>(InNoesisComponent);
	check(NoesisColorKeyFrame);
}

FNoesisKeyTime UNoesisColorKeyFrame::GetKeyTime()
{
	Noesis::Gui::KeyFrame<Noesis::Drawing::Color>* NoesisColorKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	check(NoesisColorKeyFrame);
	return FNoesisKeyTime(NoesisColorKeyFrame->GetKeyTime());
}

void UNoesisColorKeyFrame::SetKeyTime(FNoesisKeyTime InKeyTime)
{
	Noesis::Gui::KeyFrame<Noesis::Drawing::Color>* NoesisColorKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	check(NoesisColorKeyFrame);
	NoesisColorKeyFrame->SetKeyTime(InKeyTime.ToNoesis());
}

void UNoesisColorKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeyFrame<Noesis::Drawing::Color>* NoesisColorKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	check(NoesisColorKeyFrame);


}

void UNoesisColorKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeyFrame<Noesis::Drawing::Color>* NoesisColorKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	check(NoesisColorKeyFrame);


}

