////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiIDictionary.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiIDictionary::UNoesisGuiIDictionary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiIDictionary::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(InNoesisInterface);
	check(NoesisIDictionary);

}

void UNoesisGuiIDictionary::Add(class UNoesisGuiIResourceKey* InKey, class UNoesisGuiBaseComponent* InValue)
{
	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(NoesisInterface.GetPtr());
	check(NoesisIDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	Core::BaseComponent* NoesisInValue = NsDynamicCast<Core::BaseComponent*>(InValue->NoesisComponent.GetPtr());
	return NoesisIDictionary->Add(NoesisInKey, NoesisInValue);
}

void UNoesisGuiIDictionary::Clear()
{
	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(NoesisInterface.GetPtr());
	check(NoesisIDictionary);
	return NoesisIDictionary->Clear();
}

bool UNoesisGuiIDictionary::Contains(class UNoesisGuiIResourceKey* InKey)
{
	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(NoesisInterface.GetPtr());
	check(NoesisIDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	return NoesisIDictionary->Contains(NoesisInKey);
}

int32 UNoesisGuiIDictionary::Count()
{
	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(NoesisInterface.GetPtr());
	check(NoesisIDictionary);
	return (int32)NoesisIDictionary->Count();
}

bool UNoesisGuiIDictionary::Find(class UNoesisGuiIResourceKey* InKey, class UNoesisGuiBaseComponent* InResource)
{
	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(NoesisInterface.GetPtr());
	check(NoesisIDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	Core::BaseComponent* NoesisInResource = NsDynamicCast<Core::BaseComponent*>(InResource->NoesisComponent.GetPtr());
	return NoesisIDictionary->Find(NoesisInKey, NoesisInResource);
}

class UNoesisGuiBaseComponent* UNoesisGuiIDictionary::Get(class UNoesisGuiIResourceKey* InKey)
{
	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(NoesisInterface.GetPtr());
	check(NoesisIDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisIDictionary->Get(NoesisInKey)));
}

void UNoesisGuiIDictionary::Remove(class UNoesisGuiIResourceKey* InKey)
{
	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(NoesisInterface.GetPtr());
	check(NoesisIDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	return NoesisIDictionary->Remove(NoesisInKey);
}

	void UNoesisGuiIDictionary::BeginDestroy()
{
	Noesis::Gui::IDictionary* NoesisIDictionary = NsDynamicCast<Noesis::Gui::IDictionary*>(NoesisInterface.GetPtr());
	if (!NoesisIDictionary)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

