////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiColorKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiColorKeyFrame::UNoesisGuiColorKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiColorKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<Noesis::Drawing::Color>* NoesisColorKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Color>*>(InNoesisComponent);
	check(NoesisColorKeyFrame);
}

void UNoesisGuiColorKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::KeyFrame<Noesis::Drawing::Color>* NoesisColorKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	check(NoesisColorKeyFrame)


}

void UNoesisGuiColorKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::KeyFrame<Noesis::Drawing::Color>* NoesisColorKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Drawing::Color>*>(NoesisComponent.GetPtr());
	check(NoesisColorKeyFrame)


}

