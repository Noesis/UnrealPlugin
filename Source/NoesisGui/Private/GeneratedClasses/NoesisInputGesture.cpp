////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisInputGesture.h"

using namespace Noesis;
using namespace Gui;

UNoesisInputGesture::UNoesisInputGesture(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::InputGesture::StaticGetClassType();
}

void UNoesisInputGesture::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::InputGesture* NoesisInputGesture = NsDynamicCast<Noesis::Gui::InputGesture*>(InNoesisComponent);
	check(NoesisInputGesture);
}

void UNoesisInputGesture::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::InputGesture* NoesisInputGesture = NsDynamicCast<Noesis::Gui::InputGesture*>(NoesisComponent.GetPtr());
	check(NoesisInputGesture);


}

void UNoesisInputGesture::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::InputGesture* NoesisInputGesture = NsDynamicCast<Noesis::Gui::InputGesture*>(NoesisComponent.GetPtr());
	check(NoesisInputGesture);


}

