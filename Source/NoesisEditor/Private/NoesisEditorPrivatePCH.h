////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "Misc/MessageDialog.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "HAL/FileManager.h"
#include "HAL/PlatformFileManager.h"
#include "Internationalization/Regex.h"

// Engine includes
#include "Engine/Font.h"
#include "Engine/FontFace.h"
#include "Engine/Texture2D.h"
#include "Engine/LevelScriptBlueprint.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "EditorFramework/AssetImportData.h"
#include "Sound/SoundWave.h"

// MediaAsset includes
#include "MediaSource.h"

// UnrealEd includes
#include "AutomatedAssetImportData.h"
#include "ObjectTools.h"
#include "PackageTools.h"
#include "EdGraphUtilities.h"
#include "UnrealEdGlobals.h"
#include "EditorReimportHandler.h"
#include "Editor/UnrealEdEngine.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Factories/Factory.h"
#include "Factories/FontFactory.h"
#include "Factories/FontFileImportFactory.h"
#include "Factories/TextureFactory.h"
#include "ThumbnailRendering/DefaultSizedThumbnailRenderer.h"

// BlueprintGraph includes
#include "K2Node_CallFunction.h"

// BlueprintGraph includes
#include "BlueprintNodeTemplateCache.h"

// AssetRegistry includes
#include "AssetRegistry/AssetRegistryModule.h"

// Kismet includes
#include "BlueprintCompilationManager.h"
#include "BlueprintEditorModule.h"
#include "BlueprintEditor.h"
#include "BlueprintEditorModes.h"
#include "BlueprintEditorTabs.h"
#include "BlueprintEditorContext.h"
#include "SBlueprintEditorToolbar.h"
#include "WorkflowOrientedApp/SModeWidget.h"

// AssetTools includes
#include "AssetTypeActions_Base.h"

// KismetCompiler includes
#include "KismetCompilerModule.h"
#include "KismetCompiler.h"

// Settings includes
#include "ISettingsModule.h"

// SlateCore includes
#include "Styling/ISlateStyle.h"
#include "Styling/SlateStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Styling/SlateTypes.h"
#include "Styling/SlateIconFinder.h"

// EditorStyle includes
#include "EditorStyleSet.h"

// Projects includes
#include "Interfaces/IPluginManager.h"

// Slate includes
#include "SlateOptMacros.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SSpacer.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/SButton.h"
#include "Framework/Commands/Commands.h"

// ToolMenus includes
#include "ToolMenuSection.h"
#include "ToolMenu.h"

// UMG includes
#include "Blueprint/WidgetBlueprintLibrary.h"

// LevelEditor includes
#include "LevelEditor.h"

// WorkspaceMenuStructure includes
#include "WorkspaceMenuStructure.h"
#include "WorkspaceMenuStructureModule.h"




#include "NoesisRuntime.h"

#include "NoesisEditorClasses.h"
#include "NoesisEditorModule.h"
