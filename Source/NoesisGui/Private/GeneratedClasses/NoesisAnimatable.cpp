////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisAnimatable.h"

using namespace Noesis;
using namespace Gui;

UNoesisAnimatable::UNoesisAnimatable(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisAnimatable::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Animatable* NoesisAnimatable = NsDynamicCast<Noesis::Gui::Animatable*>(InNoesisComponent);
	check(NoesisAnimatable);
}

void UNoesisAnimatable::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Animatable* NoesisAnimatable = NsDynamicCast<Noesis::Gui::Animatable*>(NoesisComponent.GetPtr());
	check(NoesisAnimatable)


}

void UNoesisAnimatable::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Animatable* NoesisAnimatable = NsDynamicCast<Noesis::Gui::Animatable*>(NoesisComponent.GetPtr());
	check(NoesisAnimatable)


}

