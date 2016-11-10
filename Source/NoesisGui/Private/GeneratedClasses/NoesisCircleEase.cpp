////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisCircleEase.h"

using namespace Noesis;
using namespace Gui;

UNoesisCircleEase::UNoesisCircleEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisCircleEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::CircleEase* NoesisCircleEase = NsDynamicCast<Noesis::Gui::CircleEase*>(InNoesisComponent);
	check(NoesisCircleEase);
}

void UNoesisCircleEase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::CircleEase* NoesisCircleEase = NsDynamicCast<Noesis::Gui::CircleEase*>(NoesisComponent.GetPtr());
	check(NoesisCircleEase)


}

void UNoesisCircleEase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::CircleEase* NoesisCircleEase = NsDynamicCast<Noesis::Gui::CircleEase*>(NoesisComponent.GetPtr());
	check(NoesisCircleEase)


}

