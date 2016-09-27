////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiSelector.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiSelector::UNoesisGuiSelector(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiSelector::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::Selector* NoesisSelector = NsDynamicCast<Noesis::Gui::Selector*>(InNoesisComponent);
	check(NoesisSelector);

}

	void UNoesisGuiSelector::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::Selector* NoesisSelector = NsDynamicCast<Noesis::Gui::Selector*>(NoesisComponent.GetPtr());
	if (!NoesisSelector)
		return;

}

