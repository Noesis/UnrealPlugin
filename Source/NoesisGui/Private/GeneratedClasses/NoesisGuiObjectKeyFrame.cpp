////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiObjectKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiObjectKeyFrame::UNoesisGuiObjectKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiObjectKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>* NoesisObjectKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>*>(InNoesisComponent);
	check(NoesisObjectKeyFrame);

}

	void UNoesisGuiObjectKeyFrame::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>* NoesisObjectKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<Noesis::Ptr<Noesis::Core::BaseComponent>>*>(NoesisComponent.GetPtr());
	if (!NoesisObjectKeyFrame)
		return;

}

