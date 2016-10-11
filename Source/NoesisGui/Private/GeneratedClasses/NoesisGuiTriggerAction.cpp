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

void UNoesisGuiTriggerAction::Invoke(class UNoesisGuiFrameworkElement* InTarget, class UNoesisGuiFrameworkElement* InNameScope)
{
	Noesis::Gui::TriggerAction* NoesisTriggerAction = NsDynamicCast<Noesis::Gui::TriggerAction*>(NoesisComponent.GetPtr());
	check(NoesisTriggerAction);
	FrameworkElement* NoesisInTarget = NsDynamicCast<FrameworkElement*>(InTarget->NoesisComponent.GetPtr());
	FrameworkElement* NoesisInNameScope = NsDynamicCast<FrameworkElement*>(InNameScope->NoesisComponent.GetPtr());
	return NoesisTriggerAction->Invoke(NoesisInTarget, NoesisInNameScope);
}

	void UNoesisGuiTriggerAction::BeginDestroy()
{
	Noesis::Gui::TriggerAction* NoesisTriggerAction = NsDynamicCast<Noesis::Gui::TriggerAction*>(NoesisComponent.GetPtr());
	if (!NoesisTriggerAction)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

