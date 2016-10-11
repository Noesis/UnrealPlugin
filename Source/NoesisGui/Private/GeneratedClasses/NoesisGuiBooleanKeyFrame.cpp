////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBooleanKeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBooleanKeyFrame::UNoesisGuiBooleanKeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBooleanKeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<NsBool>* NoesisBooleanKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsBool>*>(InNoesisComponent);
	check(NoesisBooleanKeyFrame);

}

	void UNoesisGuiBooleanKeyFrame::BeginDestroy()
{
	Noesis::Gui::KeyFrame<NsBool>* NoesisBooleanKeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsBool>*>(NoesisComponent.GetPtr());
	if (!NoesisBooleanKeyFrame)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

