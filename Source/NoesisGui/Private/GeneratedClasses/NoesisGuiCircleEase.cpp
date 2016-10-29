////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiCircleEase.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiCircleEase::UNoesisGuiCircleEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiCircleEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::CircleEase* NoesisCircleEase = NsDynamicCast<Noesis::Gui::CircleEase*>(InNoesisComponent);
	check(NoesisCircleEase);
}

void UNoesisGuiCircleEase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::CircleEase* NoesisCircleEase = NsDynamicCast<Noesis::Gui::CircleEase*>(NoesisComponent.GetPtr());
	check(NoesisCircleEase)


}

void UNoesisGuiCircleEase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::CircleEase* NoesisCircleEase = NsDynamicCast<Noesis::Gui::CircleEase*>(NoesisComponent.GetPtr());
	check(NoesisCircleEase)


}

