////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiInputBinding.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiInputBinding::UNoesisGuiInputBinding(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiInputBinding::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::InputBinding* NoesisInputBinding = NsDynamicCast<Noesis::Gui::InputBinding*>(InNoesisComponent);
	check(NoesisInputBinding);
}

class UNoesisGuiInputGesture* UNoesisGuiInputBinding::GetGesture()
{
	Noesis::Gui::InputBinding* NoesisInputBinding = NsDynamicCast<Noesis::Gui::InputBinding*>(NoesisComponent.GetPtr());
	check(NoesisInputBinding);
	return CastChecked<UNoesisGuiInputGesture>(Instance->FindUnrealComponentForNoesisComponent(NoesisInputBinding->GetGesture()));
}

void UNoesisGuiInputBinding::SetGesture(class UNoesisGuiInputGesture* InGesture)
{
	Noesis::Gui::InputBinding* NoesisInputBinding = NsDynamicCast<Noesis::Gui::InputBinding*>(NoesisComponent.GetPtr());
	check(NoesisInputBinding);
	NoesisInputBinding->SetGesture(NsDynamicCast<InputGesture*>(InGesture->NoesisComponent.GetPtr()));
}

void UNoesisGuiInputBinding::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::InputBinding* NoesisInputBinding = NsDynamicCast<Noesis::Gui::InputBinding*>(NoesisComponent.GetPtr());
	check(NoesisInputBinding)


}

void UNoesisGuiInputBinding::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::InputBinding* NoesisInputBinding = NsDynamicCast<Noesis::Gui::InputBinding*>(NoesisComponent.GetPtr());
	check(NoesisInputBinding)


}

