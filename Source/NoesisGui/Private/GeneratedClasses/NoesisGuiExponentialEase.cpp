////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiExponentialEase.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiExponentialEase::UNoesisGuiExponentialEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiExponentialEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ExponentialEase* NoesisExponentialEase = NsDynamicCast<Noesis::Gui::ExponentialEase*>(InNoesisComponent);
	check(NoesisExponentialEase);
}

void UNoesisGuiExponentialEase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ExponentialEase* NoesisExponentialEase = NsDynamicCast<Noesis::Gui::ExponentialEase*>(NoesisComponent.GetPtr());
	check(NoesisExponentialEase)


}

void UNoesisGuiExponentialEase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ExponentialEase* NoesisExponentialEase = NsDynamicCast<Noesis::Gui::ExponentialEase*>(NoesisComponent.GetPtr());
	check(NoesisExponentialEase)


}

