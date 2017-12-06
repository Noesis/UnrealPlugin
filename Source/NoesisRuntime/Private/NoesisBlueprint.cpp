////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisBlueprint.h"

// NoesisRuntime includes
#include "NoesisBlueprintGeneratedClass.h"

UNoesisBlueprint::UNoesisBlueprint(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bRecompileOnLoad = false;

	TessellationQuality = ENoesisTessellationQuality::Medium;
}

#if WITH_EDITOR
UClass* UNoesisBlueprint::GetBlueprintClass() const
{
	return UNoesisBlueprintGeneratedClass::StaticClass();
}

bool UNoesisBlueprint::SupportedByDefaultBlueprintFactory() const
{
	return false;
}
#endif // WITH_EDITOR
