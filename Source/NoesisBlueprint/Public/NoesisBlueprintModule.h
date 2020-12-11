////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#define NOESISBLUEPRINT_MODULE_NAME "NoesisBlueprint"

class NOESISBLUEPRINT_API INoesisBlueprintModuleInterface : public IModuleInterface
{
public:

	static INoesisBlueprintModuleInterface* Get();
};
