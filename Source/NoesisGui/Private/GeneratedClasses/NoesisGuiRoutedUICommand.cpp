////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiRoutedUICommand.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiRoutedUICommand::UNoesisGuiRoutedUICommand(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiRoutedUICommand::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RoutedUICommand* NoesisRoutedUICommand = NsDynamicCast<Noesis::Gui::RoutedUICommand*>(InNoesisComponent);
	check(NoesisRoutedUICommand);

}

FString UNoesisGuiRoutedUICommand::GetText()
{
	Noesis::Gui::RoutedUICommand* NoesisRoutedUICommand = NsDynamicCast<Noesis::Gui::RoutedUICommand*>(NoesisComponent.GetPtr());
	check(NoesisRoutedUICommand);
	return NsStringToFString(NoesisRoutedUICommand->GetText());
}

void UNoesisGuiRoutedUICommand::SetText(FString InText)
{
	Noesis::Gui::RoutedUICommand* NoesisRoutedUICommand = NsDynamicCast<Noesis::Gui::RoutedUICommand*>(NoesisComponent.GetPtr());
	check(NoesisRoutedUICommand);
	NoesisRoutedUICommand->SetText(StringCast<NsChar>(*InText).Get());
}

	void UNoesisGuiRoutedUICommand::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::RoutedUICommand* NoesisRoutedUICommand = NsDynamicCast<Noesis::Gui::RoutedUICommand*>(NoesisComponent.GetPtr());
	if (!NoesisRoutedUICommand)
		return;

}

