////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiInputGesture.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiInputGesture::UNoesisGuiInputGesture(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiInputGesture::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::InputGesture* NoesisInputGesture = NsDynamicCast<Noesis::Gui::InputGesture*>(InNoesisComponent);
	check(NoesisInputGesture);
}

void UNoesisGuiInputGesture::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::InputGesture* NoesisInputGesture = NsDynamicCast<Noesis::Gui::InputGesture*>(NoesisComponent.GetPtr());
	check(NoesisInputGesture)


}

void UNoesisGuiInputGesture::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::InputGesture* NoesisInputGesture = NsDynamicCast<Noesis::Gui::InputGesture*>(NoesisComponent.GetPtr());
	check(NoesisInputGesture)


}

