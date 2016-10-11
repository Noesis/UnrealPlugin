////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiICommandSource.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiICommandSource::UNoesisGuiICommandSource(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiICommandSource::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::ICommandSource* NoesisICommandSource = NsDynamicCast<Noesis::Gui::ICommandSource*>(InNoesisInterface);
	check(NoesisICommandSource);

}

class UNoesisGuiICommand* UNoesisGuiICommandSource::GetCommand()
{
	Noesis::Gui::ICommandSource* NoesisICommandSource = NsDynamicCast<Noesis::Gui::ICommandSource*>(NoesisInterface.GetPtr());
	check(NoesisICommandSource);
	return CastChecked<UNoesisGuiICommand>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisICommandSource->GetCommand()));
}

class UNoesisGuiBaseComponent* UNoesisGuiICommandSource::GetCommandParameter()
{
	Noesis::Gui::ICommandSource* NoesisICommandSource = NsDynamicCast<Noesis::Gui::ICommandSource*>(NoesisInterface.GetPtr());
	check(NoesisICommandSource);
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisICommandSource->GetCommandParameter()));
}

class UNoesisGuiUIElement* UNoesisGuiICommandSource::GetCommandTarget()
{
	Noesis::Gui::ICommandSource* NoesisICommandSource = NsDynamicCast<Noesis::Gui::ICommandSource*>(NoesisInterface.GetPtr());
	check(NoesisICommandSource);
	return CastChecked<UNoesisGuiUIElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisICommandSource->GetCommandTarget()));
}

	void UNoesisGuiICommandSource::BeginDestroy()
{
	Noesis::Gui::ICommandSource* NoesisICommandSource = NsDynamicCast<Noesis::Gui::ICommandSource*>(NoesisInterface.GetPtr());
	if (!NoesisICommandSource)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

