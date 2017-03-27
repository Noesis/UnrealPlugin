////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGeneratedClasses.h"

NOESISGUI_API UClass* GetClassFor(const Noesis::Core::BaseComponent* BaseComponent);

NOESISGUI_API UNoesisBaseComponent* CreateClassFor(const Noesis::Core::BaseComponent* BaseComponent, UObject* Outer);

inline UClass* GetClassFor(const Noesis::Ptr<Noesis::Core::BaseComponent> BaseComponent)
{
	return GetClassFor(BaseComponent.GetPtr());
}

inline UNoesisBaseComponent* CreateClassFor(const Noesis::Ptr<Noesis::Core::BaseComponent> BaseComponent, UObject* Outer)
{
	return CreateClassFor(BaseComponent.GetPtr(), Outer);
}
