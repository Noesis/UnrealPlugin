////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiContentControl.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiContentControl::UNoesisGuiContentControl(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiContentControl::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ContentControl* NoesisContentControl = NsDynamicCast<Noesis::Gui::ContentControl*>(InNoesisComponent);
	check(NoesisContentControl);

}

	void UNoesisGuiContentControl::BeginDestroy()
{
	Noesis::Gui::ContentControl* NoesisContentControl = NsDynamicCast<Noesis::Gui::ContentControl*>(NoesisComponent.GetPtr());
	if (!NoesisContentControl)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

