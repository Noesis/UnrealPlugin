////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisICommandSource.h"

using namespace Noesis;
using namespace Gui;

UNoesisICommandSource::UNoesisICommandSource(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisInterfaceTypeClass = Noesis::Gui::ICommandSource::StaticGetClassType();
}

void UNoesisICommandSource::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::ICommandSource* NoesisICommandSource = NsDynamicCast<Noesis::Gui::ICommandSource*>(InNoesisInterface);
	check(NoesisICommandSource);
}

class UNoesisICommand* UNoesisICommandSource::GetCommand()
{
	Noesis::Gui::ICommandSource* NoesisICommandSource = NsDynamicCast<Noesis::Gui::ICommandSource*>(NoesisInterface.GetPtr());
	check(NoesisICommandSource);
	return CastChecked<UNoesisICommand>(CreateInterfaceFor(NoesisICommandSource->GetCommand(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisBaseComponent* UNoesisICommandSource::GetCommandParameter()
{
	Noesis::Gui::ICommandSource* NoesisICommandSource = NsDynamicCast<Noesis::Gui::ICommandSource*>(NoesisInterface.GetPtr());
	check(NoesisICommandSource);
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisICommandSource->GetCommandParameter(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisUIElement* UNoesisICommandSource::GetCommandTarget()
{
	Noesis::Gui::ICommandSource* NoesisICommandSource = NsDynamicCast<Noesis::Gui::ICommandSource*>(NoesisInterface.GetPtr());
	check(NoesisICommandSource);
	return CastChecked<UNoesisUIElement>(CreateClassFor(NoesisICommandSource->GetCommandTarget(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisICommandSource::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ICommandSource* NoesisICommandSource = NsDynamicCast<Noesis::Gui::ICommandSource*>(NoesisInterface.GetPtr());
	check(NoesisICommandSource);


}

void UNoesisICommandSource::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ICommandSource* NoesisICommandSource = NsDynamicCast<Noesis::Gui::ICommandSource*>(NoesisInterface.GetPtr());
	check(NoesisICommandSource);


}

