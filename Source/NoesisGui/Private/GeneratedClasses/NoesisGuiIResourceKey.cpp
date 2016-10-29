////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiIResourceKey.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiIResourceKey::UNoesisGuiIResourceKey(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiIResourceKey::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IResourceKey* NoesisIResourceKey = NsDynamicCast<Noesis::Gui::IResourceKey*>(InNoesisInterface);
	check(NoesisIResourceKey);
}

bool UNoesisGuiIResourceKey::Equals(const class UNoesisGuiIResourceKey* InResourceKey)
{
	Noesis::Gui::IResourceKey* NoesisIResourceKey = NsDynamicCast<Noesis::Gui::IResourceKey*>(NoesisInterface.GetPtr());
	check(NoesisIResourceKey);
	const IResourceKey* NoesisInResourceKey = NsDynamicCast<const IResourceKey*>(InResourceKey->NoesisInterface.GetPtr());
	return NoesisIResourceKey->Equals(NoesisInResourceKey);
}

FString UNoesisGuiIResourceKey::GetStr()
{
	Noesis::Gui::IResourceKey* NoesisIResourceKey = NsDynamicCast<Noesis::Gui::IResourceKey*>(NoesisInterface.GetPtr());
	check(NoesisIResourceKey);
	return NsStringToFString(NoesisIResourceKey->GetStr().c_str());
}

void UNoesisGuiIResourceKey::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IResourceKey* NoesisIResourceKey = NsDynamicCast<Noesis::Gui::IResourceKey*>(NoesisInterface.GetPtr());
	check(NoesisIResourceKey)


}

void UNoesisGuiIResourceKey::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IResourceKey* NoesisIResourceKey = NsDynamicCast<Noesis::Gui::IResourceKey*>(NoesisInterface.GetPtr());
	check(NoesisIResourceKey)


}

