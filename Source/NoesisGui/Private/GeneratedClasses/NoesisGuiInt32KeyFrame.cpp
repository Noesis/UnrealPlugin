////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiInt32KeyFrame.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiInt32KeyFrame::UNoesisGuiInt32KeyFrame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiInt32KeyFrame::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::KeyFrame<NsInt32>* NoesisInt32KeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsInt32>*>(InNoesisComponent);
	check(NoesisInt32KeyFrame);

}

	void UNoesisGuiInt32KeyFrame::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::KeyFrame<NsInt32>* NoesisInt32KeyFrame = NsDynamicCast<Noesis::Gui::KeyFrame<NsInt32>*>(NoesisComponent.GetPtr());
	if (!NoesisInt32KeyFrame)
		return;

}

