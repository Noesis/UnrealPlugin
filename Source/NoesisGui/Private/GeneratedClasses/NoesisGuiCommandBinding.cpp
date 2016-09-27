////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiCommandBinding.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiCommandBinding::UNoesisGuiCommandBinding(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiCommandBinding::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::CommandBinding* NoesisCommandBinding = NsDynamicCast<Noesis::Gui::CommandBinding*>(InNoesisComponent);
	check(NoesisCommandBinding);

}

	void UNoesisGuiCommandBinding::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::CommandBinding* NoesisCommandBinding = NsDynamicCast<Noesis::Gui::CommandBinding*>(NoesisComponent.GetPtr());
	if (!NoesisCommandBinding)
		return;

}

