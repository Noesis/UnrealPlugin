////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Core.h"
#include "CoreUObject.h"
#include "Engine.h"
#include "UnrealEd.h"
#include "ObjectTools.h"

#include "KismetCompiler.h"
#include "BlueprintGraphModule.h"
#include "AssetRegistryModule.h"

DECLARE_LOG_CATEGORY_EXTERN(LogNoesisGuiEditor, Verbose, All);

#pragma push_macro("GetCurrentTime")
#undef GetCurrentTime
#include "AllowWindowsPlatformTypes.h"

#include "NoesisGui.h"

#include "HideWindowsPlatformTypes.h"
#pragma pop_macro("GetCurrentTime")

#include "NoesisGuiSupport.h"

#include "NoesisGuiClasses.h"

#include "NoesisGuiEditorClasses.h"
#include "NoesisGuiEditorModule.h"
