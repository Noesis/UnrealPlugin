////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiVisual.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiVisual::UNoesisGuiVisual(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiVisual::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(InNoesisComponent);
	check(NoesisVisual);

}

	void UNoesisGuiVisual::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Visual* NoesisVisual = NsDynamicCast<Noesis::Gui::Visual*>(NoesisComponent.GetPtr());
	if (!NoesisVisual)
		return;

}

