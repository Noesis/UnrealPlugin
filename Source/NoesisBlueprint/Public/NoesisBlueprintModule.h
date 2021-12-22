////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "Logging/LogMacros.h"
#include "Modules/ModuleInterface.h"

DECLARE_LOG_CATEGORY_EXTERN(LogNoesisBlueprint, VeryVerbose, All);

#define NOESISBLUEPRINT_MODULE_NAME "NoesisBlueprint"

class NOESISBLUEPRINT_API INoesisBlueprintModuleInterface : public IModuleInterface
{
public:

	static INoesisBlueprintModuleInterface* Get();
};
