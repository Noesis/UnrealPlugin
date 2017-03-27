////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisIDictionary.h"

using namespace Noesis;
using namespace Gui;

UNoesisIDictionary::UNoesisIDictionary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisInterfaceTypeClass = Noesis::Gui::IDictionary::StaticGetClassType();
}

void UNoesisIDictionary::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(InNoesisInterface);
	check(NoesisIDictionary);
}

void UNoesisIDictionary::Add(class UNoesisIResourceKey* InKey, class UNoesisBaseComponent* InValue)
{
	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(NoesisInterface.GetPtr());
	check(NoesisIDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	Core::BaseComponent* NoesisInValue = NsDynamicCast<Core::BaseComponent*>(InValue->NoesisComponent.GetPtr());
	return NoesisIDictionary->Add(NoesisInKey, NoesisInValue);
}

void UNoesisIDictionary::Clear()
{
	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(NoesisInterface.GetPtr());
	check(NoesisIDictionary);
	return NoesisIDictionary->Clear();
}

bool UNoesisIDictionary::Contains(class UNoesisIResourceKey* InKey)
{
	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(NoesisInterface.GetPtr());
	check(NoesisIDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	return NoesisIDictionary->Contains(NoesisInKey);
}

int32 UNoesisIDictionary::Count()
{
	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(NoesisInterface.GetPtr());
	check(NoesisIDictionary);
	return (int32)NoesisIDictionary->Count();
}

bool UNoesisIDictionary::Find(class UNoesisIResourceKey* InKey, class UNoesisBaseComponent* InResource)
{
	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(NoesisInterface.GetPtr());
	check(NoesisIDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	Core::BaseComponent* NoesisInResource = NsDynamicCast<Core::BaseComponent*>(InResource->NoesisComponent.GetPtr());
	return NoesisIDictionary->Find(NoesisInKey, NoesisInResource);
}

class UNoesisBaseComponent* UNoesisIDictionary::Get(class UNoesisIResourceKey* InKey)
{
	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(NoesisInterface.GetPtr());
	check(NoesisIDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisIDictionary->Get(NoesisInKey), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisIDictionary::Remove(class UNoesisIResourceKey* InKey)
{
	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(NoesisInterface.GetPtr());
	check(NoesisIDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	return NoesisIDictionary->Remove(NoesisInKey);
}

void UNoesisIDictionary::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(NoesisInterface.GetPtr());
	check(NoesisIDictionary);


}

void UNoesisIDictionary::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(NoesisInterface.GetPtr());
	check(NoesisIDictionary);


}

