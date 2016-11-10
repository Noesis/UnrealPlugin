////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisControllableStoryboardAction.h"

using namespace Noesis;
using namespace Gui;

UNoesisControllableStoryboardAction::UNoesisControllableStoryboardAction(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisControllableStoryboardAction::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ControllableStoryboardAction* NoesisControllableStoryboardAction = NsDynamicCast<Noesis::Gui::ControllableStoryboardAction*>(InNoesisComponent);
	check(NoesisControllableStoryboardAction);
}

FString UNoesisControllableStoryboardAction::GetBeginStoryboardName()
{
	Noesis::Gui::ControllableStoryboardAction* NoesisControllableStoryboardAction = NsDynamicCast<Noesis::Gui::ControllableStoryboardAction*>(NoesisComponent.GetPtr());
	check(NoesisControllableStoryboardAction);
	return NsStringToFString(NoesisControllableStoryboardAction->GetBeginStoryboardName());
}

void UNoesisControllableStoryboardAction::SetBeginStoryboardName(FString InBeginStoryboardName)
{
	Noesis::Gui::ControllableStoryboardAction* NoesisControllableStoryboardAction = NsDynamicCast<Noesis::Gui::ControllableStoryboardAction*>(NoesisComponent.GetPtr());
	check(NoesisControllableStoryboardAction);
	NoesisControllableStoryboardAction->SetBeginStoryboardName(StringCast<NsChar>(*InBeginStoryboardName).Get());
}

void UNoesisControllableStoryboardAction::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ControllableStoryboardAction* NoesisControllableStoryboardAction = NsDynamicCast<Noesis::Gui::ControllableStoryboardAction*>(NoesisComponent.GetPtr());
	check(NoesisControllableStoryboardAction)


}

void UNoesisControllableStoryboardAction::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ControllableStoryboardAction* NoesisControllableStoryboardAction = NsDynamicCast<Noesis::Gui::ControllableStoryboardAction*>(NoesisComponent.GetPtr());
	check(NoesisControllableStoryboardAction)


}

