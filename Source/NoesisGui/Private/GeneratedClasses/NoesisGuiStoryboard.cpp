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

void UNoesisGuiStoryboard::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Storyboard* NoesisStoryboard = NsDynamicCast<Noesis::Gui::Storyboard*>(NoesisComponent.GetPtr());
	check(NoesisStoryboard)


}

void UNoesisGuiStoryboard::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Storyboard* NoesisStoryboard = NsDynamicCast<Noesis::Gui::Storyboard*>(NoesisComponent.GetPtr());
	check(NoesisStoryboard)


}

