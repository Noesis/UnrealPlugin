////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisBlueprintModule.h"

// Core includes
#include "Modules/ModuleManager.h"

class FNoesisBlueprintModule : public INoesisBlueprintModuleInterface
{
public:
	// IModuleInterface interface
	virtual void StartupModule() override
	{
		NoesisBlueprintModuleInterface = this;
	}

	virtual void ShutdownModule() override
	{
		NoesisBlueprintModuleInterface = nullptr;
	}
	// End of IModuleInterface interface

	static INoesisBlueprintModuleInterface* NoesisBlueprintModuleInterface;
};

INoesisBlueprintModuleInterface* FNoesisBlueprintModule::NoesisBlueprintModuleInterface = 0;

INoesisBlueprintModuleInterface* INoesisBlueprintModuleInterface::Get()
{
	return FNoesisBlueprintModule::NoesisBlueprintModuleInterface;
}

IMPLEMENT_MODULE(FNoesisBlueprintModule, NoesisBlueprint);
DEFINE_LOG_CATEGORY(LogNoesisBlueprint);
