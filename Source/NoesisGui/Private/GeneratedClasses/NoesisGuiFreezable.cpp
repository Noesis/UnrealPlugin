////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiFreezable.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiFreezable::UNoesisGuiFreezable(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiFreezable::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(InNoesisComponent);
	check(NoesisFreezable);

}

	void UNoesisGuiFreezable::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Freezable* NoesisFreezable = NsDynamicCast<Noesis::Gui::Freezable*>(NoesisComponent.GetPtr());
	if (!NoesisFreezable)
		return;

}

