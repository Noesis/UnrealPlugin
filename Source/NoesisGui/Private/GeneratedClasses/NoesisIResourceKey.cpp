////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisIResourceKey.h"

using namespace Noesis;
using namespace Gui;

UNoesisIResourceKey::UNoesisIResourceKey(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisInterfaceTypeClass = Noesis::Gui::IResourceKey::StaticGetClassType();
}

void UNoesisIResourceKey::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IResourceKey* NoesisIResourceKey = NsDynamicCast<Noesis::Gui::IResourceKey*>(InNoesisInterface);
	check(NoesisIResourceKey);
}

bool UNoesisIResourceKey::Equals(const class UNoesisIResourceKey* InResourceKey)
{
	Noesis::Gui::IResourceKey* NoesisIResourceKey = NsDynamicCast<Noesis::Gui::IResourceKey*>(NoesisInterface.GetPtr());
	check(NoesisIResourceKey);
	const IResourceKey* NoesisInResourceKey = NsDynamicCast<const IResourceKey*>(InResourceKey->NoesisInterface.GetPtr());
	return NoesisIResourceKey->Equals(NoesisInResourceKey);
}

FString UNoesisIResourceKey::GetStr()
{
	Noesis::Gui::IResourceKey* NoesisIResourceKey = NsDynamicCast<Noesis::Gui::IResourceKey*>(NoesisInterface.GetPtr());
	check(NoesisIResourceKey);
	return NsStringToFString(NoesisIResourceKey->GetStr().c_str());
}

void UNoesisIResourceKey::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IResourceKey* NoesisIResourceKey = NsDynamicCast<Noesis::Gui::IResourceKey*>(NoesisInterface.GetPtr());
	check(NoesisIResourceKey);


}

void UNoesisIResourceKey::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IResourceKey* NoesisIResourceKey = NsDynamicCast<Noesis::Gui::IResourceKey*>(NoesisInterface.GetPtr());
	check(NoesisIResourceKey);


}

