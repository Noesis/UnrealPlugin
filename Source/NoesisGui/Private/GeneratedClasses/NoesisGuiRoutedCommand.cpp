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

	void UNoesisGuiRoutedCommand::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::RoutedCommand* NoesisRoutedCommand = NsDynamicCast<Noesis::Gui::RoutedCommand*>(NoesisComponent.GetPtr());
	if (!NoesisRoutedCommand)
		return;

}

