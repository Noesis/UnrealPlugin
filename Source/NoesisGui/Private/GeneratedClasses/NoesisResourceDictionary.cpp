////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisResourceDictionary.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisResourceDictionary::UNoesisResourceDictionary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::ResourceDictionary::StaticGetClassType();
}

void UNoesisResourceDictionary::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(InNoesisComponent);
	check(NoesisResourceDictionary);
}

FString UNoesisResourceDictionary::GetSource()
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	return NsStringToFString(NoesisResourceDictionary->GetSource());
}

void UNoesisResourceDictionary::SetSource(FString InSource)
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	NoesisResourceDictionary->SetSource(StringCast<NsChar>(*InSource).Get());
}

void UNoesisResourceDictionary::Add(class UNoesisIResourceKey* InKey, class UNoesisBaseComponent* InValue)
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	Core::BaseComponent* NoesisInValue = NsDynamicCast<Core::BaseComponent*>(InValue->NoesisComponent.GetPtr());
	return NoesisResourceDictionary->Add(NoesisInKey, NoesisInValue);
}

void UNoesisResourceDictionary::Clear()
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	return NoesisResourceDictionary->Clear();
}

bool UNoesisResourceDictionary::Contains(class UNoesisIResourceKey* InKey)
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	return NoesisResourceDictionary->Contains(NoesisInKey);
}

int32 UNoesisResourceDictionary::Count()
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	return (int32)NoesisResourceDictionary->Count();
}

bool UNoesisResourceDictionary::Find(class UNoesisIResourceKey* InKey, class UNoesisBaseComponent* InResource)
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	Core::BaseComponent* NoesisInResource = NsDynamicCast<Core::BaseComponent*>(InResource->NoesisComponent.GetPtr());
	return NoesisResourceDictionary->Find(NoesisInKey, NoesisInResource);
}

class UNoesisBaseComponent* UNoesisResourceDictionary::Get(class UNoesisIResourceKey* InKey)
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisResourceDictionary->Get(NoesisInKey), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisResourceDictionaryCollection* UNoesisResourceDictionary::GetMergedDictionaries()
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	return CastChecked<UNoesisResourceDictionaryCollection>(CreateClassFor(NoesisResourceDictionary->GetMergedDictionaries(), nullptr), ECastCheckedType::NullAllowed);
}

bool UNoesisResourceDictionary::HasResourcesDefined()
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	return NoesisResourceDictionary->HasResourcesDefined();
}

bool UNoesisResourceDictionary::IsReadOnly()
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	return NoesisResourceDictionary->IsReadOnly();
}

void UNoesisResourceDictionary::Remove(class UNoesisIResourceKey* InKey)
{
	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	return NoesisResourceDictionary->Remove(NoesisInKey);
}

void UNoesisResourceDictionary::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);


}

void UNoesisResourceDictionary::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	check(NoesisResourceDictionary);


}

