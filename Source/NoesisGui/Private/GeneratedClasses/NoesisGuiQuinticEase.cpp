////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiQuinticEase.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiQuinticEase::UNoesisGuiQuinticEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiQuinticEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::QuinticEase* NoesisQuinticEase = NsDynamicCast<Noesis::Gui::QuinticEase*>(InNoesisComponent);
	check(NoesisQuinticEase);
}

void UNoesisGuiQuinticEase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::QuinticEase* NoesisQuinticEase = NsDynamicCast<Noesis::Gui::QuinticEase*>(NoesisComponent.GetPtr());
	check(NoesisQuinticEase)


}

void UNoesisGuiQuinticEase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::QuinticEase* NoesisQuinticEase = NsDynamicCast<Noesis::Gui::QuinticEase*>(NoesisComponent.GetPtr());
	check(NoesisQuinticEase)


}

