////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisRoutedCommand.h"

using namespace Noesis;
using namespace Gui;

UNoesisRoutedCommand::UNoesisRoutedCommand(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisRoutedCommand::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RoutedCommand* NoesisRoutedCommand = NsDynamicCast<Noesis::Gui::RoutedCommand*>(InNoesisComponent);
	check(NoesisRoutedCommand);
}

class UNoesisInputGestureCollection* UNoesisRoutedCommand::GetInputGestures()
{
	Noesis::Gui::RoutedCommand* NoesisRoutedCommand = NsDynamicCast<Noesis::Gui::RoutedCommand*>(NoesisComponent.GetPtr());
	check(NoesisRoutedCommand);
	return CastChecked<UNoesisInputGestureCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisRoutedCommand->GetInputGestures()));
}

bool UNoesisRoutedCommand::CanExecute(class UNoesisBaseComponent* InParam, class UNoesisUIElement* InTarget)
{
	Noesis::Gui::RoutedCommand* NoesisRoutedCommand = NsDynamicCast<Noesis::Gui::RoutedCommand*>(NoesisComponent.GetPtr());
	check(NoesisRoutedCommand);
	Core::BaseComponent* NoesisInParam = NsDynamicCast<Core::BaseComponent*>(InParam->NoesisComponent.GetPtr());
	UIElement* NoesisInTarget = NsDynamicCast<UIElement*>(InTarget->NoesisComponent.GetPtr());
	return NoesisRoutedCommand->CanExecute(NoesisInParam, NoesisInTarget);
}

void UNoesisRoutedCommand::Execute(class UNoesisBaseComponent* InParam, class UNoesisUIElement* InTarget)
{
	Noesis::Gui::RoutedCommand* NoesisRoutedCommand = NsDynamicCast<Noesis::Gui::RoutedCommand*>(NoesisComponent.GetPtr());
	check(NoesisRoutedCommand);
	Core::BaseComponent* NoesisInParam = NsDynamicCast<Core::BaseComponent*>(InParam->NoesisComponent.GetPtr());
	UIElement* NoesisInTarget = NsDynamicCast<UIElement*>(InTarget->NoesisComponent.GetPtr());
	return NoesisRoutedCommand->Execute(NoesisInParam, NoesisInTarget);
}

void UNoesisRoutedCommand::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::RoutedCommand* NoesisRoutedCommand = NsDynamicCast<Noesis::Gui::RoutedCommand*>(NoesisComponent.GetPtr());
	check(NoesisRoutedCommand)


}

void UNoesisRoutedCommand::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::RoutedCommand* NoesisRoutedCommand = NsDynamicCast<Noesis::Gui::RoutedCommand*>(NoesisComponent.GetPtr());
	check(NoesisRoutedCommand)


}

