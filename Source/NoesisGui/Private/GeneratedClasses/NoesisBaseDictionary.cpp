////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisBaseDictionary.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisBaseDictionary::UNoesisBaseDictionary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::BaseDictionary::StaticGetClassType();
}

void UNoesisBaseDictionary::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseDictionary* NoesisBaseDictionary = NsDynamicCast<Noesis::Gui::BaseDictionary*>(InNoesisComponent);
	check(NoesisBaseDictionary);
}

void UNoesisBaseDictionary::RemoveDictionaryChangedListeners()
{
	Noesis::Gui::BaseDictionary* NoesisBaseDictionary = NsDynamicCast<Noesis::Gui::BaseDictionary*>(NoesisComponent.GetPtr());
	check(NoesisBaseDictionary);
	return NoesisBaseDictionary->RemoveDictionaryChangedListeners();
}

void UNoesisBaseDictionary::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseDictionary* NoesisBaseDictionary = NsDynamicCast<Noesis::Gui::BaseDictionary*>(NoesisComponent.GetPtr());
	check(NoesisBaseDictionary);


}

void UNoesisBaseDictionary::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseDictionary* NoesisBaseDictionary = NsDynamicCast<Noesis::Gui::BaseDictionary*>(NoesisComponent.GetPtr());
	check(NoesisBaseDictionary);


}

