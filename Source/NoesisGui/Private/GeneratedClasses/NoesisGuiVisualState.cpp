////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiVisualState.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiVisualState::UNoesisGuiVisualState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiVisualState::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::VisualState* NoesisVisualState = NsDynamicCast<Noesis::Gui::VisualState*>(InNoesisComponent);
	check(NoesisVisualState);

}

class UNoesisGuiStoryboard* UNoesisGuiVisualState::GetStoryboard()
{
	Noesis::Gui::VisualState* NoesisVisualState = NsDynamicCast<Noesis::Gui::VisualState*>(NoesisComponent.GetPtr());
	check(NoesisVisualState);
	return CastChecked<UNoesisGuiStoryboard>(Instance->FindUnrealComponentForNoesisComponent(NoesisVisualState->GetStoryboard()));
}

void UNoesisGuiVisualState::SetStoryboard(class UNoesisGuiStoryboard* InStoryboard)
{
	Noesis::Gui::VisualState* NoesisVisualState = NsDynamicCast<Noesis::Gui::VisualState*>(NoesisComponent.GetPtr());
	check(NoesisVisualState);
	NoesisVisualState->SetStoryboard(NsDynamicCast<Storyboard*>(InStoryboard->NoesisComponent.GetPtr()));
}

	void UNoesisGuiVisualState::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::VisualState* NoesisVisualState = NsDynamicCast<Noesis::Gui::VisualState*>(NoesisComponent.GetPtr());
	if (!NoesisVisualState)
		return;

}

