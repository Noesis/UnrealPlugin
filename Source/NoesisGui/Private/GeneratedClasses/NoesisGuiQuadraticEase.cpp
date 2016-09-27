////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiQuadraticEase.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiQuadraticEase::UNoesisGuiQuadraticEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiQuadraticEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::QuadraticEase* NoesisQuadraticEase = NsDynamicCast<Noesis::Gui::QuadraticEase*>(InNoesisComponent);
	check(NoesisQuadraticEase);

}

	void UNoesisGuiQuadraticEase::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::QuadraticEase* NoesisQuadraticEase = NsDynamicCast<Noesis::Gui::QuadraticEase*>(NoesisComponent.GetPtr());
	if (!NoesisQuadraticEase)
		return;

}

