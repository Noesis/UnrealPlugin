////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiResourceDictionary.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiResourceDictionary::UNoesisGuiResourceDictionary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiResourceDictionary::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(InNoesisComponent);
	check(NoesisResourceDictionary);

}

FString UNoesisGuiResourceDictionary::GetSource()
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	return NsStringToFString(NoesisResourceDictionary->GetSource());
}

void UNoesisGuiResourceDictionary::SetSource(FString InSource)
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	NoesisResourceDictionary->SetSource(StringCast<NsChar>(*InSource).Get());
}

void UNoesisGuiResourceDictionary::Add(class UNoesisGuiIResourceKey* InKey, class UNoesisGuiBaseComponent* InValue)
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	Core::BaseComponent* NoesisInValue = NsDynamicCast<Core::BaseComponent*>(InValue->NoesisComponent.GetPtr());
	return NoesisResourceDictionary->Add(NoesisInKey, NoesisInValue);
}

void UNoesisGuiResourceDictionary::Clear()
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	return NoesisResourceDictionary->Clear();
}

bool UNoesisGuiResourceDictionary::Contains(class UNoesisGuiIResourceKey* InKey)
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	return NoesisResourceDictionary->Contains(NoesisInKey);
}

int32 UNoesisGuiResourceDictionary::Count()
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	return (int32)NoesisResourceDictionary->Count();
}

bool UNoesisGuiResourceDictionary::Find(class UNoesisGuiIResourceKey* InKey, class UNoesisGuiBaseComponent* InResource)
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	Core::BaseComponent* NoesisInResource = NsDynamicCast<Core::BaseComponent*>(InResource->NoesisComponent.GetPtr());
	return NoesisResourceDictionary->Find(NoesisInKey, NoesisInResource);
}

class UNoesisGuiBaseComponent* UNoesisGuiResourceDictionary::Get(class UNoesisGuiIResourceKey* InKey)
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisResourceDictionary->Get(NoesisInKey)));
}

class UNoesisGuiResourceDictionaryCollection* UNoesisGuiResourceDictionary::GetMergedDictionaries()
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	return CastChecked<UNoesisGuiResourceDictionaryCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisResourceDictionary->GetMergedDictionaries()));
}

bool UNoesisGuiResourceDictionary::HasResourcesDefined()
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	return NoesisResourceDictionary->HasResourcesDefined();
}

void UNoesisGuiResourceDictionary::Remove(class UNoesisGuiIResourceKey* InKey)
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	return NoesisResourceDictionary->Remove(NoesisInKey);
}

	void UNoesisGuiResourceDictionary::BeginDestroy()
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	if (!NoesisResourceDictionary)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

