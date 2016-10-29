////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiIXamlContextReceiver.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiIXamlContextReceiver::UNoesisGuiIXamlContextReceiver(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiIXamlContextReceiver::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IXamlContextReceiver* NoesisIXamlContextReceiver = NsDynamicCast<Noesis::Gui::IXamlContextReceiver*>(InNoesisInterface);
	check(NoesisIXamlContextReceiver);
}

void UNoesisGuiIXamlContextReceiver::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IXamlContextReceiver* NoesisIXamlContextReceiver = NsDynamicCast<Noesis::Gui::IXamlContextReceiver*>(NoesisInterface.GetPtr());
	check(NoesisIXamlContextReceiver)


}

void UNoesisGuiIXamlContextReceiver::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IXamlContextReceiver* NoesisIXamlContextReceiver = NsDynamicCast<Noesis::Gui::IXamlContextReceiver*>(NoesisInterface.GetPtr());
	check(NoesisIXamlContextReceiver)


}

