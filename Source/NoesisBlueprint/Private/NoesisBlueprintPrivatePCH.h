////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"
#include "Misc/EngineVersionComparison.h"
#include "Modules/ModuleManager.h"

// Engine includes
#include "ObjectEditorUtils.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/KismetTextLibrary.h"

// UnrealEd includes
#include "EditorCategoryUtils.h"
#include "Editor/EditorEngine.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"

// BlueprintGraph includes
#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintGraphModule.h"
#include "BlueprintVariableNodeSpawner.h"
#include "EdGraphSchema_K2.h"
#include "K2Node_CallFunction.h"
#include "K2Node_EnumInequality.h"
#include "K2Node_IfThenElse.h"
#include "K2Node_Self.h"
#include "K2Node_VariableGet.h"
#include "K2Node_VariableSet.h"
#include "K2Node_Variable.h"

// EditorStyle includes
#if UE_VERSION_OLDER_THAN(5, 1, 0)
#include "Classes/EditorStyleSettings.h"
#else
#include "Settings/EditorStyleSettings.h"
#endif

// KismetCompiler includes
#include "KismetCompiler.h"


#include "NoesisRuntime.h"

#include "NoesisBlueprintClasses.h"
#include "NoesisBlueprintModule.h"
