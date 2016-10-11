////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseDefinition.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseDefinition::UNoesisGuiBaseDefinition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseDefinition::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseDefinition* NoesisBaseDefinition = NsDynamicCast<Noesis::Gui::BaseDefinition*>(InNoesisComponent);
	check(NoesisBaseDefinition);

}

	void UNoesisGuiBaseDefinition::BeginDestroy()
{
	Noesis::Gui::BaseDefinition* NoesisBaseDefinition = NsDynamicCast<Noesis::Gui::BaseDefinition*>(NoesisComponent.GetPtr());
	if (!NoesisBaseDefinition)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

