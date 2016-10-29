////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiLinearDoubleKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiLinearDoubleKeyFrame::UNoesisGuiLinearDoubleKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiLinearDoubleKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::LinearKeyFrame<NsFloat32>* NoesisLinearDoubleKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<NsFloat32>*>(InNoesisComponent);
	check(NoesisLinearDoubleKeyFrame);
}

void UNoesisGuiLinearDoubleKeyFrame::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::LinearKeyFrame<NsFloat32>* NoesisLinearDoubleKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisLinearDoubleKeyFrame)


}

void UNoesisGuiLinearDoubleKeyFrame::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::LinearKeyFrame<NsFloat32>* NoesisLinearDoubleKeyFrame = NsDynamicCast<Noesis::Gui::LinearKeyFrame<NsFloat32>*>(NoesisComponent.GetPtr());
	check(NoesisLinearDoubleKeyFrame)


}

