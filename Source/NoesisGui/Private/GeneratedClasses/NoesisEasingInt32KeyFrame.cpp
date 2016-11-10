////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisEasingInt32KeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisEasingInt32KeyFrame::UNoesisEasingInt32KeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisEasingInt32KeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EasingKeyFrame<NsInt32>* NoesisEasingInt32KeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<NsInt32>*>(InNoesisComponent);
	check(NoesisEasingInt32KeyFrame);
}

void UNoesisEasingInt32KeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::EasingKeyFrame<NsInt32>* NoesisEasingInt32KeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisEasingInt32KeyFrame)


}

void UNoesisEasingInt32KeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::EasingKeyFrame<NsInt32>* NoesisEasingInt32KeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisEasingInt32KeyFrame)


}

