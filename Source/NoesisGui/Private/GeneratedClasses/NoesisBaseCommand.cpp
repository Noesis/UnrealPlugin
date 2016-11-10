////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisBaseCommand.h"

using namespace Noesis;
using namespace Gui;

UNoesisBaseCommand::UNoesisBaseCommand(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisBaseCommand::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseCommand* NoesisBaseCommand = NsDynamicCast<Noesis::Gui::BaseCommand*>(InNoesisComponent);
	check(NoesisBaseCommand);
}

void UNoesisBaseCommand::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseCommand* NoesisBaseCommand = NsDynamicCast<Noesis::Gui::BaseCommand*>(NoesisComponent.GetPtr());
	check(NoesisBaseCommand)


}

void UNoesisBaseCommand::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseCommand* NoesisBaseCommand = NsDynamicCast<Noesis::Gui::BaseCommand*>(NoesisComponent.GetPtr());
	check(NoesisBaseCommand)


}

