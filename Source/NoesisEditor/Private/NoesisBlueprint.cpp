////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisBlueprint.h"

// NoesisEditor includes
#include "NoesisBlueprintGeneratedClass.h"

UNoesisBlueprint::UNoesisBlueprint()
	: Super()
{
	bRecompileOnLoad = false;

	DPIScale = true;

	TessellationQuality = ENoesisTessellationQuality::Medium;

	EnableKeyboard = true;
	EnableMouse = true;
	EmulateTouch = false;
	SetUserFocusToViewport = false;
	EnableTouch = true;
	EnableActions = false;
	PixelDepthBias = -1.0f;
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
