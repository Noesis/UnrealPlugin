////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGeneratedClasses.h"

NOESISGUI_API UClass* GetInterfaceFor(const Noesis::Core::Interface* Interface);

NOESISGUI_API UNoesisInterface* CreateInterfaceFor(const Noesis::Core::Interface* Interface, UObject* Outer);

inline UClass* GetInterfaceFor(const Noesis::Ptr<Noesis::Core::Interface> Interface)
{
	return GetInterfaceFor(Interface.GetPtr());
}

inline UNoesisInterface* CreateInterfaceFor(const Noesis::Ptr<Noesis::Core::Interface> Interface, UObject* Outer)
{
	return CreateInterfaceFor(Interface.GetPtr(), Outer);
}
