////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisBlueprint.h"

// NoesisGui includes
#include "NoesisBlueprintGeneratedClass.h"

UNoesisBlueprint::UNoesisBlueprint(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bRecompileOnLoad = false;
}

UClass* UNoesisBlueprint::GetBlueprintClass() const
{
	return UNoesisBlueprintGeneratedClass::StaticClass();
}

bool UNoesisBlueprint::SupportedByDefaultBlueprintFactory() const
{
	return false;
}
