////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiStoryboard.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiStoryboard::UNoesisGuiStoryboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiStoryboard::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Storyboard* NoesisStoryboard = NsDynamicCast<Noesis::Gui::Storyboard*>(InNoesisComponent);
	check(NoesisStoryboard);

}

	void UNoesisGuiStoryboard::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Storyboard* NoesisStoryboard = NsDynamicCast<Noesis::Gui::Storyboard*>(NoesisComponent.GetPtr());
	if (!NoesisStoryboard)
		return;

}

