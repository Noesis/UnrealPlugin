////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Engine includes
#include "EngineClasses.h"
#include "StaticBoundShaderState.h"
#include "GlobalShader.h"
#include "Engine/Blueprint.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "Kismet/BlueprintFunctionLibrary.h"

// ShaderCore includes
#include "ShaderParameterUtils.h"

// CoreUObject includes
#include "UObjectGlobals.h"

// UMG includes
#include "Blueprint/UserWidget.h"

// Core includes
#include "Misc/FileHelper.h"
#include "Misc/CoreDelegates.h"

// RHI includes
#include "RHIStaticStates.h"
#include "PipelineStateCache.h"
#include "RHICommandList.h"

// RenderCore includes
#include "RenderingThread.h"

// SlateCore includes
#include "SLeafWidget.h"
#include "Rendering/DrawElements.h"

#if WITH_EDITOR
// UnrealEd includes
#include "Editor.h"
#include "Kismet2/EnumEditorUtils.h"
#include "Kismet2/StructureEditorUtils.h"

// AssetRegistry includes
#include "AssetRegistryModule.h"
#endif


DECLARE_LOG_CATEGORY_EXTERN(LogNoesis, VeryVerbose, All);

#if PLATFORM_WINDOWS
#include "AllowWindowsPlatformTypes.h"
#endif

#include "Noesis_pch.h"

#if PLATFORM_WINDOWS
#include "HideWindowsPlatformTypes.h"
#endif

#include "NoesisSupport.h"

#include "NoesisRuntimeClasses.h"
#include "NoesisRuntimeModule.h"
