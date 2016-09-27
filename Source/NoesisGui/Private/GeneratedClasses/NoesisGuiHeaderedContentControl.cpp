////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiHeaderedContentControl.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiHeaderedContentControl::UNoesisGuiHeaderedContentControl(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiHeaderedContentControl::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::HeaderedContentControl* NoesisHeaderedContentControl = NsDynamicCast<Noesis::Gui::HeaderedContentControl*>(InNoesisComponent);
	check(NoesisHeaderedContentControl);

}

	void UNoesisGuiHeaderedContentControl::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::HeaderedContentControl* NoesisHeaderedContentControl = NsDynamicCast<Noesis::Gui::HeaderedContentControl*>(NoesisComponent.GetPtr());
	if (!NoesisHeaderedContentControl)
		return;

}

