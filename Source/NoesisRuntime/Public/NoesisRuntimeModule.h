////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

DECLARE_LOG_CATEGORY_EXTERN(LogNoesis, VeryVerbose, All);

#define NOESISGUI_MODULE_NAME "NoesisRuntime"

class NOESISRUNTIME_API INoesisRuntimeModuleInterface : public IModuleInterface
{
public:
	static INoesisRuntimeModuleInterface& Get();
};
