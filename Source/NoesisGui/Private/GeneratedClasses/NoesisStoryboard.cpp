////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisStoryboard.h"

using namespace Noesis;
using namespace Gui;

UNoesisStoryboard::UNoesisStoryboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisStoryboard::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Storyboard* NoesisStoryboard = NsDynamicCast<Noesis::Gui::Storyboard*>(InNoesisComponent);
	check(NoesisStoryboard);
}

void UNoesisStoryboard::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Storyboard* NoesisStoryboard = NsDynamicCast<Noesis::Gui::Storyboard*>(NoesisComponent.GetPtr());
	check(NoesisStoryboard)


}

void UNoesisStoryboard::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Storyboard* NoesisStoryboard = NsDynamicCast<Noesis::Gui::Storyboard*>(NoesisComponent.GetPtr());
	check(NoesisStoryboard)


}

