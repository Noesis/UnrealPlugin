////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisQuadraticEase.h"

using namespace Noesis;
using namespace Gui;

UNoesisQuadraticEase::UNoesisQuadraticEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisQuadraticEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::QuadraticEase* NoesisQuadraticEase = NsDynamicCast<Noesis::Gui::QuadraticEase*>(InNoesisComponent);
	check(NoesisQuadraticEase);
}

void UNoesisQuadraticEase::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::QuadraticEase* NoesisQuadraticEase = NsDynamicCast<Noesis::Gui::QuadraticEase*>(NoesisComponent.GetPtr());
	check(NoesisQuadraticEase)


}

void UNoesisQuadraticEase::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::QuadraticEase* NoesisQuadraticEase = NsDynamicCast<Noesis::Gui::QuadraticEase*>(NoesisComponent.GetPtr());
	check(NoesisQuadraticEase)


}

