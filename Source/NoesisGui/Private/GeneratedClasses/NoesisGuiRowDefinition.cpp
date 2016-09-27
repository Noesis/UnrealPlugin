////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiRowDefinition.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiRowDefinition::UNoesisGuiRowDefinition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiRowDefinition::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::RowDefinition* NoesisRowDefinition = NsDynamicCast<Noesis::Gui::RowDefinition*>(InNoesisComponent);
	check(NoesisRowDefinition);

}

	void UNoesisGuiRowDefinition::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::RowDefinition* NoesisRowDefinition = NsDynamicCast<Noesis::Gui::RowDefinition*>(NoesisComponent.GetPtr());
	if (!NoesisRowDefinition)
		return;

}

