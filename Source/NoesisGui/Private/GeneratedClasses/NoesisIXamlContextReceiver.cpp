////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisIXamlContextReceiver.h"

using namespace Noesis;
using namespace Gui;

UNoesisIXamlContextReceiver::UNoesisIXamlContextReceiver(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisIXamlContextReceiver::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IXamlContextReceiver* NoesisIXamlContextReceiver = NsDynamicCast<Noesis::Gui::IXamlContextReceiver*>(InNoesisInterface);
	check(NoesisIXamlContextReceiver);
}

void UNoesisIXamlContextReceiver::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IXamlContextReceiver* NoesisIXamlContextReceiver = NsDynamicCast<Noesis::Gui::IXamlContextReceiver*>(NoesisInterface.GetPtr());
	check(NoesisIXamlContextReceiver)


}

void UNoesisIXamlContextReceiver::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IXamlContextReceiver* NoesisIXamlContextReceiver = NsDynamicCast<Noesis::Gui::IXamlContextReceiver*>(NoesisInterface.GetPtr());
	check(NoesisIXamlContextReceiver)


}

