////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisGuiBlueprint.h"

// NoesisGui includes
#include "NoesisGuiBlueprintGeneratedClass.h"

UNoesisGuiBlueprint::UNoesisGuiBlueprint(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bRecompileOnLoad = false;
}

UClass* UNoesisGuiBlueprint::GetBlueprintClass() const
{
	return UNoesisGuiBlueprintGeneratedClass::StaticClass();
}

bool UNoesisGuiBlueprint::SupportedByDefaultBlueprintFactory() const
{
	return false;
}
