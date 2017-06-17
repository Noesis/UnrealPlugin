////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisITimeManager.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisITimeManager::UNoesisITimeManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisInterfaceTypeClass = Noesis::Gui::ITimeManager::StaticGetClassType();
}

void UNoesisITimeManager::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::ITimeManager* NoesisITimeManager = NsDynamicCast<Noesis::Gui::ITimeManager*>(InNoesisInterface);
	check(NoesisITimeManager);
}

bool UNoesisITimeManager::GoToState(class UNoesisFrameworkElement* InTarget, FName InStateName)
{
	Noesis::Gui::ITimeManager* NoesisITimeManager = NsDynamicCast<Noesis::Gui::ITimeManager*>(NoesisInterface.GetPtr());
	check(NoesisITimeManager);
	FrameworkElement* NoesisInTarget = NsDynamicCast<FrameworkElement*>(InTarget->NoesisComponent.GetPtr());
	Core::Symbol NoesisInStateName = Noesis::Core::Symbol(InStateName.GetPlainANSIString());
	return NoesisITimeManager->GoToState(NoesisInTarget, NoesisInStateName);
}

bool UNoesisITimeManager::HasPendingAnimations()
{
	Noesis::Gui::ITimeManager* NoesisITimeManager = NsDynamicCast<Noesis::Gui::ITimeManager*>(NoesisInterface.GetPtr());
	check(NoesisITimeManager);
	return NoesisITimeManager->HasPendingAnimations();
}

void UNoesisITimeManager::Tick(float InTimeInSeconds)
{
	Noesis::Gui::ITimeManager* NoesisITimeManager = NsDynamicCast<Noesis::Gui::ITimeManager*>(NoesisInterface.GetPtr());
	check(NoesisITimeManager);
	NsFloat64 NoesisInTimeInSeconds = (NsFloat64)InTimeInSeconds;
	return NoesisITimeManager->Tick(NoesisInTimeInSeconds);
}

void UNoesisITimeManager::TickPending()
{
	Noesis::Gui::ITimeManager* NoesisITimeManager = NsDynamicCast<Noesis::Gui::ITimeManager*>(NoesisInterface.GetPtr());
	check(NoesisITimeManager);
	return NoesisITimeManager->TickPending();
}

void UNoesisITimeManager::TransferTo(class UNoesisITimeManager* InOther)
{
	Noesis::Gui::ITimeManager* NoesisITimeManager = NsDynamicCast<Noesis::Gui::ITimeManager*>(NoesisInterface.GetPtr());
	check(NoesisITimeManager);
	ITimeManager* NoesisInOther = NsDynamicCast<ITimeManager*>(InOther->NoesisInterface.GetPtr());
	return NoesisITimeManager->TransferTo(NoesisInOther);
}

void UNoesisITimeManager::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ITimeManager* NoesisITimeManager = NsDynamicCast<Noesis::Gui::ITimeManager*>(NoesisInterface.GetPtr());
	check(NoesisITimeManager);


}

void UNoesisITimeManager::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ITimeManager* NoesisITimeManager = NsDynamicCast<Noesis::Gui::ITimeManager*>(NoesisInterface.GetPtr());
	check(NoesisITimeManager);


}

