////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisRoutedUICommand.h"

using namespace Noesis;
using namespace Gui;

UNoesisRoutedUICommand::UNoesisRoutedUICommand(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::RoutedUICommand::StaticGetClassType();
}

void UNoesisRoutedUICommand::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RoutedUICommand* NoesisRoutedUICommand = NsDynamicCast<Noesis::Gui::RoutedUICommand*>(InNoesisComponent);
	check(NoesisRoutedUICommand);
}

FString UNoesisRoutedUICommand::GetText()
{
	Noesis::Gui::RoutedUICommand* NoesisRoutedUICommand = NsDynamicCast<Noesis::Gui::RoutedUICommand*>(NoesisComponent.GetPtr());
	check(NoesisRoutedUICommand);
	return NsStringToFString(NoesisRoutedUICommand->GetText());
}

void UNoesisRoutedUICommand::SetText(FString InText)
{
	Noesis::Gui::RoutedUICommand* NoesisRoutedUICommand = NsDynamicCast<Noesis::Gui::RoutedUICommand*>(NoesisComponent.GetPtr());
	check(NoesisRoutedUICommand);
	NoesisRoutedUICommand->SetText(StringCast<NsChar>(*InText).Get());
}

void UNoesisRoutedUICommand::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::RoutedUICommand* NoesisRoutedUICommand = NsDynamicCast<Noesis::Gui::RoutedUICommand*>(NoesisComponent.GetPtr());
	check(NoesisRoutedUICommand);


}

void UNoesisRoutedUICommand::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::RoutedUICommand* NoesisRoutedUICommand = NsDynamicCast<Noesis::Gui::RoutedUICommand*>(NoesisComponent.GetPtr());
	check(NoesisRoutedUICommand);


}

