////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisICommand.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisICommand::UNoesisICommand(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisInterfaceTypeClass = Noesis::Gui::ICommand::StaticGetClassType();
}

void UNoesisICommand::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::ICommand* NoesisICommand = NsDynamicCast<Noesis::Gui::ICommand*>(InNoesisInterface);
	check(NoesisICommand);
}

FName UNoesisICommand::GetName()
{
	Noesis::Gui::ICommand* NoesisICommand = NsDynamicCast<Noesis::Gui::ICommand*>(NoesisInterface.GetPtr());
	check(NoesisICommand);
	return FName(NoesisICommand->GetName().GetStr());
}

bool UNoesisICommand::CanExecute(class UNoesisBaseComponent* InParam)
{
	Noesis::Gui::ICommand* NoesisICommand = NsDynamicCast<Noesis::Gui::ICommand*>(NoesisInterface.GetPtr());
	check(NoesisICommand);
	Core::BaseComponent* NoesisInParam = NsDynamicCast<Core::BaseComponent*>(InParam->NoesisComponent.GetPtr());
	return NoesisICommand->CanExecute(NoesisInParam);
}

void UNoesisICommand::Execute(class UNoesisBaseComponent* InParam)
{
	Noesis::Gui::ICommand* NoesisICommand = NsDynamicCast<Noesis::Gui::ICommand*>(NoesisInterface.GetPtr());
	check(NoesisICommand);
	Core::BaseComponent* NoesisInParam = NsDynamicCast<Core::BaseComponent*>(InParam->NoesisComponent.GetPtr());
	return NoesisICommand->Execute(NoesisInParam);
}

void UNoesisICommand::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ICommand* NoesisICommand = NsDynamicCast<Noesis::Gui::ICommand*>(NoesisInterface.GetPtr());
	check(NoesisICommand);


}

void UNoesisICommand::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ICommand* NoesisICommand = NsDynamicCast<Noesis::Gui::ICommand*>(NoesisInterface.GetPtr());
	check(NoesisICommand);


}

