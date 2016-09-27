////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiCubicEase.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiCubicEase::UNoesisGuiCubicEase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiCubicEase::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::CubicEase* NoesisCubicEase = NsDynamicCast<Noesis::Gui::CubicEase*>(InNoesisComponent);
	check(NoesisCubicEase);

}

	void UNoesisGuiCubicEase::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::CubicEase* NoesisCubicEase = NsDynamicCast<Noesis::Gui::CubicEase*>(NoesisComponent.GetPtr());
	if (!NoesisCubicEase)
		return;

}

