////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiScrollBar.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiScrollBar::UNoesisGuiScrollBar(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiScrollBar::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ScrollBar* NoesisScrollBar = NsDynamicCast<Noesis::Gui::ScrollBar*>(InNoesisComponent);
	check(NoesisScrollBar);

}

class UNoesisGuiTrack* UNoesisGuiScrollBar::GetTrack()
{
	Noesis::Gui::ScrollBar* NoesisScrollBar = NsDynamicCast<Noesis::Gui::ScrollBar*>(NoesisComponent.GetPtr());
	check(NoesisScrollBar);
	return CastChecked<UNoesisGuiTrack>(Instance->FindUnrealComponentForNoesisComponent(NoesisScrollBar->GetTrack()));
}

	void UNoesisGuiScrollBar::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::ScrollBar* NoesisScrollBar = NsDynamicCast<Noesis::Gui::ScrollBar*>(NoesisComponent.GetPtr());
	if (!NoesisScrollBar)
		return;

}

