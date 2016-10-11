////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiITimeManager.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiITimeManager::UNoesisGuiITimeManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiITimeManager::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::ITimeManager* NoesisITimeManager = NsDynamicCast<Noesis::Gui::ITimeManager*>(InNoesisInterface);
	check(NoesisITimeManager);

}

bool UNoesisGuiITimeManager::GoToState(class UNoesisGuiFrameworkElement* InTarget, FName InStateName)
{
	Noesis::Gui::ITimeManager* NoesisITimeManager = NsDynamicCast<Noesis::Gui::ITimeManager*>(NoesisInterface.GetPtr());
	check(NoesisITimeManager);
	FrameworkElement* NoesisInTarget = NsDynamicCast<FrameworkElement*>(InTarget->NoesisComponent.GetPtr());
	Core::Symbol NoesisInStateName = Noesis::Core::Symbol(InStateName.GetPlainANSIString());
	return NoesisITimeManager->GoToState(NoesisInTarget, NoesisInStateName);
}

bool UNoesisGuiITimeManager::HasPendingAnimations()
{
	Noesis::Gui::ITimeManager* NoesisITimeManager = NsDynamicCast<Noesis::Gui::ITimeManager*>(NoesisInterface.GetPtr());
	check(NoesisITimeManager);
	return NoesisITimeManager->HasPendingAnimations();
}

void UNoesisGuiITimeManager::Tick(float InTimeInSeconds)
{
	Noesis::Gui::ITimeManager* NoesisITimeManager = NsDynamicCast<Noesis::Gui::ITimeManager*>(NoesisInterface.GetPtr());
	check(NoesisITimeManager);
	NsFloat64 NoesisInTimeInSeconds = InTimeInSeconds;
	return NoesisITimeManager->Tick(NoesisInTimeInSeconds);
}

void UNoesisGuiITimeManager::TickPending()
{
	Noesis::Gui::ITimeManager* NoesisITimeManager = NsDynamicCast<Noesis::Gui::ITimeManager*>(NoesisInterface.GetPtr());
	check(NoesisITimeManager);
	return NoesisITimeManager->TickPending();
}

void UNoesisGuiITimeManager::TransferTo(class UNoesisGuiITimeManager* InOther)
{
	Noesis::Gui::ITimeManager* NoesisITimeManager = NsDynamicCast<Noesis::Gui::ITimeManager*>(NoesisInterface.GetPtr());
	check(NoesisITimeManager);
	ITimeManager* NoesisInOther = NsDynamicCast<ITimeManager*>(InOther->NoesisInterface.GetPtr());
	return NoesisITimeManager->TransferTo(NoesisInOther);
}

	void UNoesisGuiITimeManager::BeginDestroy()
{
	Noesis::Gui::ITimeManager* NoesisITimeManager = NsDynamicCast<Noesis::Gui::ITimeManager*>(NoesisInterface.GetPtr());
	if (!NoesisITimeManager)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

