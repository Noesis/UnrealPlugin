////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogNoesisEditor, Verbose, All);

#define NOESISEDITOR_MODULE_NAME "NoesisEditor"

class NOESISEDITOR_API INoesisEditorModuleInterface : public IModuleInterface
{
public:
	static INoesisEditorModuleInterface& Get();

	virtual void EnsurePremultiplyAlpha(class UTexture2D* Texture) = 0;

	virtual void AddSamplePlugin(const FString& PluginName, int Order) = 0;
};

inline void RegisterNoesisProject(const FString& PluginName, int InsertIndex)
{
	if (FModuleManager::Get().IsModuleLoaded("NoesisEditor"))
	{
		INoesisEditorModuleInterface* NoesisEditor = FModuleManager::Get().LoadModulePtr<INoesisEditorModuleInterface>("NoesisEditor");
		if (NoesisEditor)
		{
			NoesisEditor->AddSamplePlugin(PluginName, InsertIndex);
		}
	}
}
