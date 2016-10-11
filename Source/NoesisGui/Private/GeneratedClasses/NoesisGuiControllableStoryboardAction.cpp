////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiControllableStoryboardAction.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiControllableStoryboardAction::UNoesisGuiControllableStoryboardAction(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiControllableStoryboardAction::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ControllableStoryboardAction* NoesisControllableStoryboardAction = NsDynamicCast<Noesis::Gui::ControllableStoryboardAction*>(InNoesisComponent);
	check(NoesisControllableStoryboardAction);

}

FString UNoesisGuiControllableStoryboardAction::GetBeginStoryboardName()
{
	Noesis::Gui::ControllableStoryboardAction* NoesisControllableStoryboardAction = NsDynamicCast<Noesis::Gui::ControllableStoryboardAction*>(NoesisComponent.GetPtr());
	check(NoesisControllableStoryboardAction);
	return NsStringToFString(NoesisControllableStoryboardAction->GetBeginStoryboardName());
}

void UNoesisGuiControllableStoryboardAction::SetBeginStoryboardName(FString InBeginStoryboardName)
{
	Noesis::Gui::ControllableStoryboardAction* NoesisControllableStoryboardAction = NsDynamicCast<Noesis::Gui::ControllableStoryboardAction*>(NoesisComponent.GetPtr());
	check(NoesisControllableStoryboardAction);
	NoesisControllableStoryboardAction->SetBeginStoryboardName(StringCast<NsChar>(*InBeginStoryboardName).Get());
}

	void UNoesisGuiControllableStoryboardAction::BeginDestroy()
{
	Noesis::Gui::ControllableStoryboardAction* NoesisControllableStoryboardAction = NsDynamicCast<Noesis::Gui::ControllableStoryboardAction*>(NoesisComponent.GetPtr());
	if (!NoesisControllableStoryboardAction)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

