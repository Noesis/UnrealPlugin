////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiRoutedCommand.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiRoutedCommand::UNoesisGuiRoutedCommand(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiRoutedCommand::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RoutedCommand* NoesisRoutedCommand = NsDynamicCast<Noesis::Gui::RoutedCommand*>(InNoesisComponent);
	check(NoesisRoutedCommand);

}

class UNoesisGuiInputGestureCollection* UNoesisGuiRoutedCommand::GetInputGestures()
{
	Noesis::Gui::RoutedCommand* NoesisRoutedCommand = NsDynamicCast<Noesis::Gui::RoutedCommand*>(NoesisComponent.GetPtr());
	check(NoesisRoutedCommand);
	return CastChecked<UNoesisGuiInputGestureCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisRoutedCommand->GetInputGestures()));
}

bool UNoesisGuiRoutedCommand::CanExecute(class UNoesisGuiBaseComponent* InParam, class UNoesisGuiUIElement* InTarget)
{
	Noesis::Gui::RoutedCommand* NoesisRoutedCommand = NsDynamicCast<Noesis::Gui::RoutedCommand*>(NoesisComponent.GetPtr());
	check(NoesisRoutedCommand);
	Core::BaseComponent* NoesisInParam = NsDynamicCast<Core::BaseComponent*>(InParam->NoesisComponent.GetPtr());
	UIElement* NoesisInTarget = NsDynamicCast<UIElement*>(InTarget->NoesisComponent.GetPtr());
	return NoesisRoutedCommand->CanExecute(NoesisInParam, NoesisInTarget);
}

void UNoesisGuiRoutedCommand::Execute(class UNoesisGuiBaseComponent* InParam, class UNoesisGuiUIElement* InTarget)
{
	Noesis::Gui::RoutedCommand* NoesisRoutedCommand = NsDynamicCast<Noesis::Gui::RoutedCommand*>(NoesisComponent.GetPtr());
	check(NoesisRoutedCommand);
	Core::BaseComponent* NoesisInParam = NsDynamicCast<Core::BaseComponent*>(InParam->NoesisComponent.GetPtr());
	UIElement* NoesisInTarget = NsDynamicCast<UIElement*>(InTarget->NoesisComponent.GetPtr());
	return NoesisRoutedCommand->Execute(NoesisInParam, NoesisInTarget);
}

	void UNoesisGuiRoutedCommand::BeginDestroy()
{
	Noesis::Gui::RoutedCommand* NoesisRoutedCommand = NsDynamicCast<Noesis::Gui::RoutedCommand*>(NoesisComponent.GetPtr());
	if (!NoesisRoutedCommand)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

