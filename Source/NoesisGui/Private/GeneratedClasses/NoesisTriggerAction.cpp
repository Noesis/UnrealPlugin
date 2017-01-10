////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisTriggerAction.h"

using namespace Noesis;
using namespace Gui;

UNoesisTriggerAction::UNoesisTriggerAction(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisTriggerAction::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::TriggerAction* NoesisTriggerAction = NsDynamicCast<Noesis::Gui::TriggerAction*>(InNoesisComponent);
	check(NoesisTriggerAction);
}

void UNoesisTriggerAction::Invoke(class UNoesisFrameworkElement* InTarget, class UNoesisFrameworkElement* InNameScope)
{
	Noesis::Gui::TriggerAction* NoesisTriggerAction = NsDynamicCast<Noesis::Gui::TriggerAction*>(NoesisComponent.GetPtr());
	check(NoesisTriggerAction);
	FrameworkElement* NoesisInTarget = NsDynamicCast<FrameworkElement*>(InTarget->NoesisComponent.GetPtr());
	FrameworkElement* NoesisInNameScope = NsDynamicCast<FrameworkElement*>(InNameScope->NoesisComponent.GetPtr());
	return NoesisTriggerAction->Invoke(NoesisInTarget, NoesisInNameScope);
}

void UNoesisTriggerAction::Seal()
{
	Noesis::Gui::TriggerAction* NoesisTriggerAction = NsDynamicCast<Noesis::Gui::TriggerAction*>(NoesisComponent.GetPtr());
	check(NoesisTriggerAction);
	return NoesisTriggerAction->Seal();
}

void UNoesisTriggerAction::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::TriggerAction* NoesisTriggerAction = NsDynamicCast<Noesis::Gui::TriggerAction*>(NoesisComponent.GetPtr());
	check(NoesisTriggerAction)


}

void UNoesisTriggerAction::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::TriggerAction* NoesisTriggerAction = NsDynamicCast<Noesis::Gui::TriggerAction*>(NoesisComponent.GetPtr());
	check(NoesisTriggerAction)


}

