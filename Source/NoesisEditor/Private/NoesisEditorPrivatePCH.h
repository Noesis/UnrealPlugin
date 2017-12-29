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
#include "ObjectEditorUtils.h"
#include "Engine/Font.h"
#include "Engine/FontFace.h"
#include "Engine/Texture2D.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "EditorFramework/AssetImportData.h"

// UnrealEd includes
#include "AutomatedAssetImportData.h"
#include "ObjectTools.h"
#include "PackageTools.h"
#include "EdGraphUtilities.h"
#include "UnrealEdGlobals.h"
#include "EditorCategoryUtils.h"
#include "EditorReimportHandler.h"
#include "Editor/EditorEngine.h"
#include "Editor/UnrealEdEngine.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Factories/Factory.h"
#include "Factories/FontFactory.h"
#include "Factories/FontFileImportFactory.h"
#include "Factories/TextureFactory.h"
#include "ThumbnailRendering/DefaultSizedThumbnailRenderer.h"

// BlueprintGraph includes
#include "EdGraphSchema_K2.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintVariableNodeSpawner.h"
#include "K2Node_CallFunction.h"
#include "K2Node_VariableGet.h"
#include "K2Node_VariableSet.h"
#include "K2Node_IfThenElse.h"
#include "K2Node_Self.h"
#include "K2Node_EnumInequality.h"
#include "K2Node_Variable.h"

// FreeType2 includes
THIRD_PARTY_INCLUDES_START
#include "ft2build.h"
#include FT_FREETYPE_H
THIRD_PARTY_INCLUDES_END

// BlueprintGraph includes
#include "BlueprintGraphModule.h"

// AssetRegistry includes
#include "AssetRegistryModule.h"

// EditorStyle includes
#include "EditorStyleSettings.h"

// KismetCompiler includes
#include "KismetCompiler.h"

// Kismet includes
#include "BlueprintCompilationManager.h"
#include "BlueprintEditorModule.h"

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
#include "Widgets/Images/SImage.h"







DECLARE_LOG_CATEGORY_EXTERN(LogNoesisEditor, Verbose, All);

#include "NoesisRuntime.h"

#include "NoesisEditorClasses.h"
#include "NoesisEditorModule.h"
