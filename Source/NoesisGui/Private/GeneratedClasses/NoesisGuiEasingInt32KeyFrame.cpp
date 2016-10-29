////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiEasingInt32KeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiEasingInt32KeyFrame::UNoesisGuiEasingInt32KeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiEasingInt32KeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EasingKeyFrame<NsInt32>* NoesisEasingInt32KeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<NsInt32>*>(InNoesisComponent);
	check(NoesisEasingInt32KeyFrame);
}

void UNoesisGuiEasingInt32KeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::EasingKeyFrame<NsInt32>* NoesisEasingInt32KeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisEasingInt32KeyFrame)


}

void UNoesisGuiEasingInt32KeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::EasingKeyFrame<NsInt32>* NoesisEasingInt32KeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	check(NoesisEasingInt32KeyFrame)


}

