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

// MediaAsset includes
#include "MediaSource.h"
#include "MediaPlayer.h"
#include "MediaTexture.h"
#include "MediaSoundComponent.h"
#include "IMediaEventSink.h"
#include "AudioDevice.h"

// CoreUObject includes
#include "UObject/UObjectGlobals.h"
#include "UObject/UObjectBaseUtility.h"

// UMG includes
#include "Blueprint/UserWidget.h"

// Core includes
#include "Misc/FileHelper.h"
#include "Misc/CoreDelegates.h"
#include "UObject/PropertyPortFlags.h"
#include "Modules/ModuleInterface.h"

// RHI includes
#include "RHI.h"
#include "RHIStaticStates.h"
#include "PipelineStateCache.h"
#include "RHIResources.h"
#include "RHICommandList.h"

// RenderCore includes
#include "RenderingThread.h"
#include "ShaderParameterUtils.h"

// SlateCore includes
#include "Widgets/SLeafWidget.h"
#include "Rendering/DrawElements.h"

// ApplicationCore includes
#include "HAL/PlatformApplicationMisc.h"
#include "GenericPlatform/ITextInputMethodSystem.h"

// Slate includes
#include "Framework/Application/SlateApplication.h"

// Noesis includes
#include "NoesisSDK.h"

#if WITH_EDITOR
// UnrealEd includes
#include "Editor.h"
#include "Kismet2/EnumEditorUtils.h"
#include "Kismet2/StructureEditorUtils.h"

// AssetRegistry includes
#include "AssetRegistry/AssetRegistryModule.h"
#endif

#include "NoesisSupport.h"

#include "NoesisRuntimeClasses.h"
#include "NoesisRuntimeModule.h"

