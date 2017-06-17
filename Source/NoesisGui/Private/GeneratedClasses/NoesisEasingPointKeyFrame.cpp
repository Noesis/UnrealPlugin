////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisEasingPointKeyFrame.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisEasingPointKeyFrame::UNoesisEasingPointKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Point>::StaticGetClassType();
}

void UNoesisEasingPointKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Point>* NoesisEasingPointKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Point>*>(InNoesisComponent);
	check(NoesisEasingPointKeyFrame);
}

void UNoesisEasingPointKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Point>* NoesisEasingPointKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Point>*>(NoesisComponent.GetPtr());
	check(NoesisEasingPointKeyFrame);


}

void UNoesisEasingPointKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Point>* NoesisEasingPointKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<Noesis::Drawing::Point>*>(NoesisComponent.GetPtr());
	check(NoesisEasingPointKeyFrame);


}

