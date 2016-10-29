////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiAnimatable.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiAnimatable::UNoesisGuiAnimatable(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiAnimatable::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Animatable* NoesisAnimatable = NsDynamicCast<Noesis::Gui::Animatable*>(InNoesisComponent);
	check(NoesisAnimatable);
}

void UNoesisGuiAnimatable::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::Animatable* NoesisAnimatable = NsDynamicCast<Noesis::Gui::Animatable*>(NoesisComponent.GetPtr());
	check(NoesisAnimatable)


}

void UNoesisGuiAnimatable::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::Animatable* NoesisAnimatable = NsDynamicCast<Noesis::Gui::Animatable*>(NoesisComponent.GetPtr());
	check(NoesisAnimatable)


}

