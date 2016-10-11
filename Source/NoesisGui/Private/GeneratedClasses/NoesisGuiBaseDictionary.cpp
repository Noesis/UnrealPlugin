////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseDictionary.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseDictionary::UNoesisGuiBaseDictionary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseDictionary::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseDictionary* NoesisBaseDictionary = NsDynamicCast<Noesis::Gui::BaseDictionary*>(InNoesisComponent);
	check(NoesisBaseDictionary);

}

void UNoesisGuiBaseDictionary::RemoveDictionaryChangedListeners()
{
	Noesis::Gui::BaseDictionary* NoesisBaseDictionary = NsDynamicCast<Noesis::Gui::BaseDictionary*>(NoesisComponent.GetPtr());
	check(NoesisBaseDictionary);
	return NoesisBaseDictionary->RemoveDictionaryChangedListeners();
}

	void UNoesisGuiBaseDictionary::BeginDestroy()
{
	Noesis::Gui::BaseDictionary* NoesisBaseDictionary = NsDynamicCast<Noesis::Gui::BaseDictionary*>(NoesisComponent.GetPtr());
	if (!NoesisBaseDictionary)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

