////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

DECLARE_LOG_CATEGORY_EXTERN(LogNoesisEditor, Verbose, All);

#define NOESISEDITOR_MODULE_NAME "NoesisEditor"

class NOESISEDITOR_API INoesisEditorModuleInterface : public IModuleInterface
{
public:

	static INoesisEditorModuleInterface* Get();
};
