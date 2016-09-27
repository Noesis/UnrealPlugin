////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#define NOESISGUI_MODULE_NAME "NoesisGuiEditor"

class NOESISGUIEDITOR_API INoesisGuiEditorModuleInterface : public IModuleInterface
{
public:

	static INoesisGuiEditorModuleInterface* Get();
};
