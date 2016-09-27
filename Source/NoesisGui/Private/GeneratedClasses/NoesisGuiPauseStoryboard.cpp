////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiPauseStoryboard.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiPauseStoryboard::UNoesisGuiPauseStoryboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiPauseStoryboard::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::PauseStoryboard* NoesisPauseStoryboard = NsDynamicCast<Noesis::Gui::PauseStoryboard*>(InNoesisComponent);
	check(NoesisPauseStoryboard);

}

	void UNoesisGuiPauseStoryboard::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::PauseStoryboard* NoesisPauseStoryboard = NsDynamicCast<Noesis::Gui::PauseStoryboard*>(NoesisComponent.GetPtr());
	if (!NoesisPauseStoryboard)
		return;

}

