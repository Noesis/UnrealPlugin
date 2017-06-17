////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisInputBinding.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisInputBinding::UNoesisInputBinding(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::InputBinding::StaticGetClassType();
}

void UNoesisInputBinding::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::InputBinding* NoesisInputBinding = NsDynamicCast<Noesis::Gui::InputBinding*>(InNoesisComponent);
	check(NoesisInputBinding);
}

class UNoesisICommand* UNoesisInputBinding::GetCommand()
{
	Noesis::Gui::InputBinding* NoesisInputBinding = NsDynamicCast<Noesis::Gui::InputBinding*>(NoesisComponent.GetPtr());
	check(NoesisInputBinding);
	return CastChecked<UNoesisICommand>(CreateInterfaceFor(NoesisInputBinding->GetCommand(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisInputBinding::SetCommand(class UNoesisICommand* InCommand)
{
	Noesis::Gui::InputBinding* NoesisInputBinding = NsDynamicCast<Noesis::Gui::InputBinding*>(NoesisComponent.GetPtr());
	check(NoesisInputBinding);
	NoesisInputBinding->SetCommand(NsDynamicCast<ICommand*>(InCommand->NoesisInterface.GetPtr()));
}

class UNoesisBaseComponent* UNoesisInputBinding::GetCommandParameter()
{
	Noesis::Gui::InputBinding* NoesisInputBinding = NsDynamicCast<Noesis::Gui::InputBinding*>(NoesisComponent.GetPtr());
	check(NoesisInputBinding);
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisInputBinding->GetCommandParameter(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisInputBinding::SetCommandParameter(class UNoesisBaseComponent* InCommandParameter)
{
	Noesis::Gui::InputBinding* NoesisInputBinding = NsDynamicCast<Noesis::Gui::InputBinding*>(NoesisComponent.GetPtr());
	check(NoesisInputBinding);
	NoesisInputBinding->SetCommandParameter(NsDynamicCast<Core::BaseComponent*>(InCommandParameter->NoesisComponent.GetPtr()));
}

class UNoesisUIElement* UNoesisInputBinding::GetCommandTarget()
{
	Noesis::Gui::InputBinding* NoesisInputBinding = NsDynamicCast<Noesis::Gui::InputBinding*>(NoesisComponent.GetPtr());
	check(NoesisInputBinding);
	return CastChecked<UNoesisUIElement>(CreateClassFor(NoesisInputBinding->GetCommandTarget(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisInputBinding::SetCommandTarget(class UNoesisUIElement* InCommandTarget)
{
	Noesis::Gui::InputBinding* NoesisInputBinding = NsDynamicCast<Noesis::Gui::InputBinding*>(NoesisComponent.GetPtr());
	check(NoesisInputBinding);
	NoesisInputBinding->SetCommandTarget(NsDynamicCast<UIElement*>(InCommandTarget->NoesisComponent.GetPtr()));
}

class UNoesisInputGesture* UNoesisInputBinding::GetGesture()
{
	Noesis::Gui::InputBinding* NoesisInputBinding = NsDynamicCast<Noesis::Gui::InputBinding*>(NoesisComponent.GetPtr());
	check(NoesisInputBinding);
	return CastChecked<UNoesisInputGesture>(CreateClassFor(NoesisInputBinding->GetGesture(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisInputBinding::SetGesture(class UNoesisInputGesture* InGesture)
{
	Noesis::Gui::InputBinding* NoesisInputBinding = NsDynamicCast<Noesis::Gui::InputBinding*>(NoesisComponent.GetPtr());
	check(NoesisInputBinding);
	NoesisInputBinding->SetGesture(NsDynamicCast<InputGesture*>(InGesture->NoesisComponent.GetPtr()));
}

void UNoesisInputBinding::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::InputBinding* NoesisInputBinding = NsDynamicCast<Noesis::Gui::InputBinding*>(NoesisComponent.GetPtr());
	check(NoesisInputBinding);


}

void UNoesisInputBinding::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::InputBinding* NoesisInputBinding = NsDynamicCast<Noesis::Gui::InputBinding*>(NoesisComponent.GetPtr());
	check(NoesisInputBinding);


}

