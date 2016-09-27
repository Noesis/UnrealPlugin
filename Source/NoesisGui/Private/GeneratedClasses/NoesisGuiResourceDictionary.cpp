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

	void UNoesisGuiResourceDictionary::BeginDestroy()
{
	Super::BeginDestroy();

	Noesis::Gui::ResourceDictionary* NoesisResourceDictionary = NsDynamicCast<Noesis::Gui::ResourceDictionary*>(NoesisComponent.GetPtr());
	if (!NoesisResourceDictionary)
		return;

}

