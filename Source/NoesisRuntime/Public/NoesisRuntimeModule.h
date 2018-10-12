////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Stats/Stats.h"
#include "Stats/Stats2.h"

DECLARE_LOG_CATEGORY_EXTERN(LogNoesis, VeryVerbose, All);

DECLARE_STATS_GROUP(TEXT("Noesis"), STATGROUP_Noesis, STATCAT_Advanced);

#define NOESISGUI_MODULE_NAME "NoesisRuntime"

class NOESISRUNTIME_API INoesisRuntimeModuleInterface : public IModuleInterface
{
public:
	static INoesisRuntimeModuleInterface& Get();
};
