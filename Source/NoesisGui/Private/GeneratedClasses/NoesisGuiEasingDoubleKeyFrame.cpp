////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiEasingDoubleKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiEasingDoubleKeyFrame::UNoesisGuiEasingDoubleKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiEasingDoubleKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::EasingKeyFrame<NsFloat32>* NoesisEasingDoubleKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<NsFloat32>*>(InNoesisComponent);
	check(NoesisEasingDoubleKeyFrame);
}

void UNoesisGuiEasingDoubleKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::EasingKeyFrame<NsFloat32>* NoesisEasingDoubleKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisEasingDoubleKeyFrame)


}

void UNoesisGuiEasingDoubleKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::EasingKeyFrame<NsFloat32>* NoesisEasingDoubleKeyFrame = NsDynamicCast<Noesis::Gui::EasingKeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisEasingDoubleKeyFrame)


}

