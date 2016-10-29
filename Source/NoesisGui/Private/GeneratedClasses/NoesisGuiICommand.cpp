////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiICommand.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiICommand::UNoesisGuiICommand(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiICommand::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::ICommand* NoesisICommand = NsDynamicCast<Noesis::Gui::ICommand*>(InNoesisInterface);
	check(NoesisICommand);
}

FName UNoesisGuiICommand::GetName()
{
	Noesis::Gui::ICommand* NoesisICommand = NsDynamicCast<Noesis::Gui::ICommand*>(NoesisInterface.GetPtr());
	check(NoesisICommand);
	return FName(NoesisICommand->GetName().GetStr());
}

bool UNoesisGuiICommand::CanExecute(class UNoesisGuiBaseComponent* InParam)
{
	Noesis::Gui::ICommand* NoesisICommand = NsDynamicCast<Noesis::Gui::ICommand*>(NoesisInterface.GetPtr());
	check(NoesisICommand);
	Core::BaseComponent* NoesisInParam = NsDynamicCast<Core::BaseComponent*>(InParam->NoesisComponent.GetPtr());
	return NoesisICommand->CanExecute(NoesisInParam);
}

void UNoesisGuiICommand::Execute(class UNoesisGuiBaseComponent* InParam)
{
	Noesis::Gui::ICommand* NoesisICommand = NsDynamicCast<Noesis::Gui::ICommand*>(NoesisInterface.GetPtr());
	check(NoesisICommand);
	Core::BaseComponent* NoesisInParam = NsDynamicCast<Core::BaseComponent*>(InParam->NoesisComponent.GetPtr());
	return NoesisICommand->Execute(NoesisInParam);
}

void UNoesisGuiICommand::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ICommand* NoesisICommand = NsDynamicCast<Noesis::Gui::ICommand*>(NoesisInterface.GetPtr());
	check(NoesisICommand)


}

void UNoesisGuiICommand::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ICommand* NoesisICommand = NsDynamicCast<Noesis::Gui::ICommand*>(NoesisInterface.GetPtr());
	check(NoesisICommand)


}

