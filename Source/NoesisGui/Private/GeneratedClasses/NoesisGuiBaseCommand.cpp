////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseCommand.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseCommand::UNoesisGuiBaseCommand(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseCommand::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseCommand* NoesisBaseCommand = NsDynamicCast<Noesis::Gui::BaseCommand*>(InNoesisComponent);
	check(NoesisBaseCommand);
}

void UNoesisGuiBaseCommand::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseCommand* NoesisBaseCommand = NsDynamicCast<Noesis::Gui::BaseCommand*>(NoesisComponent.GetPtr());
	check(NoesisBaseCommand)


}

void UNoesisGuiBaseCommand::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseCommand* NoesisBaseCommand = NsDynamicCast<Noesis::Gui::BaseCommand*>(NoesisComponent.GetPtr());
	check(NoesisBaseCommand)


}

