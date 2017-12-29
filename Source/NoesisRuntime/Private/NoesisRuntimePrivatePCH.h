////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Engine includes
#include "StaticBoundShaderState.h"
#include "GlobalShader.h"
#include "Engine/Font.h"
#include "Engine/FontFace.h"
#include "Engine/Texture2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/Blueprint.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetArrayLibrary.h"
#include "EditorFramework/AssetImportData.h"

// ShaderCore includes
#include "ShaderParameterUtils.h"

// CoreUObject includes
#include "UObjectGlobals.h"

// UMG includes
#include "Blueprint/UserWidget.h"

// Core includes
#include "Misc/FileHelper.h"
#include "Misc/CoreDelegates.h"
#include "UObject/PropertyPortFlags.h"

// RHI includes
#include "RHIStaticStates.h"
#include "PipelineStateCache.h"
#include "RHICommandList.h"

// RenderCore includes
#include "RenderingThread.h"

// SlateCore includes
#include "SLeafWidget.h"
#include "Rendering/DrawElements.h"

// ApplicationCore includes
#include "GenericPlatform/ITextInputMethodSystem.h"

// Slate includes
#include "Framework/Application/SlateApplication.h"

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

#define EA_CHAR32_NATIVE 0
#include "Noesis_pch.h"

#if PLATFORM_WINDOWS
#include "HideWindowsPlatformTypes.h"
#endif

#include "NoesisSupport.h"

#include "NoesisRuntimeClasses.h"
#include "NoesisRuntimeModule.h"
