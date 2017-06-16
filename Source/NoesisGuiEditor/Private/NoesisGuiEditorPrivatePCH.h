////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "Misc/MessageDialog.h"

// Engine includes
#include "EngineClasses.h"

// UnrealEd includes
#include "AutomatedAssetImportData.h"
#include "ObjectTools.h"

// Kismet2 includes
#include "KismetEditorUtilities.h"
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
#include "NoesisGuiModule.h"

#include "NoesisGuiEditorClasses.h"
#include "NoesisGuiEditorModule.h"
