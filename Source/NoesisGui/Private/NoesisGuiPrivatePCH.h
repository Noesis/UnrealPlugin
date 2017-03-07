////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Core.h"
#include "CoreUObject.h"
#include "Engine.h"

// Engine includes
#include "EngineClasses.h"

DECLARE_LOG_CATEGORY_EXTERN(LogNoesisGui, Verbose, All);

#pragma push_macro("GetCurrentTime")
#undef GetCurrentTime
#include "AllowWindowsPlatformTypes.h"

#include "NoesisGui.h"

#include "HideWindowsPlatformTypes.h"
#pragma pop_macro("GetCurrentTime")

#include "NoesisGuiSupport.h"

#include "NoesisGuiClasses.h"
#include "NoesisGuiModule.h"
