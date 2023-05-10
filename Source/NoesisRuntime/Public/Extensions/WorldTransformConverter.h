////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Noesis includes
#include "NoesisSDK.h"
#include <NsGui/BaseValueConverter.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
class WorldTransformConverter final : public Noesis::BaseValueConverter
{
public:
	bool TryConvert(Noesis::BaseComponent* Value, const Noesis::Type* TargetType,
		Noesis::BaseComponent* Parameter, Noesis::Ptr<Noesis::BaseComponent>& Result) override;

	NS_DECLARE_REFLECTION(WorldTransformConverter, Noesis::BaseValueConverter)
};
