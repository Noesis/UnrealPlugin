////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTimeline.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTimeline::UNoesisGuiTimeline(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTimeline::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(InNoesisComponent);
	check(NoesisTimeline);

}

	void UNoesisGuiTimeline::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Timeline* NoesisTimeline = NsDynamicCast<Noesis::Gui::Timeline*>(NoesisComponent.GetPtr());
	if (!NoesisTimeline)
		return;

}

