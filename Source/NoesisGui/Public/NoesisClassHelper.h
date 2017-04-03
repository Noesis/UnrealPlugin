////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisBaseComponent.h"
#include "NoesisGuiSupport.h"
#include "NoesisCreateClass.h"

template<class BaseClass>
class NoesisClassHelper : public BaseClass
{
public:
	NoesisClassHelper()
	{
		// The unreal object has a ref counted reference to this object,
		// and this object is adding the Unreal object to the root set.
		// Without care this will prevent both objects from ever being destroyed.
		BaseComponent = CreateClassFor(this, nullptr);
		BaseComponent->AddToRoot();
	}

protected:
	virtual NsInt32 InternalRelease() const override
	{
		// Here's where we take care of making sure the objects are correctly destroyed.
		// When the reference count reaches 1, the only reference to this object is in the
		// Unreal object, so we remove it from the root set to allow it to be garbage collected.
		// This object will in turn be destroyed in NoesisBaseComponent::BeginDestroy.
		NsInt32 RefCount = Noesis::Core::BaseComponent::InternalRelease();
		if (RefCount == 1)
		{
			BaseComponent->RemoveFromRoot();
		}
		return RefCount;
	}

	UNoesisBaseComponent* BaseComponent;
};
