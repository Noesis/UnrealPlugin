////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#define NOESISGUI_MODULE_NAME "NoesisGui"

class NOESISGUI_API INoesisGuiModuleInterface : public IModuleInterface
{
public:
	virtual void SetResourceProvider(class UNoesisGuiXaml* NoesisGuiXaml) = 0;

	static INoesisGuiModuleInterface* Get();
};
