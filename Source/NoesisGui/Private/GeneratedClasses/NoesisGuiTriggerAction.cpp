////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiTriggerAction.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiTriggerAction::UNoesisGuiTriggerAction(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiTriggerAction::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TriggerAction* NoesisTriggerAction = NsDynamicCast<Noesis::Gui::TriggerAction*>(InNoesisComponent);
	check(NoesisTriggerAction);

}

	void UNoesisGuiTriggerAction::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::TriggerAction* NoesisTriggerAction = NsDynamicCast<Noesis::Gui::TriggerAction*>(NoesisComponent.GetPtr());
	if (!NoesisTriggerAction)
		return;

}

