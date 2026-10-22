////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Noesis includes
#include "NoesisSDK.h"

#include "Extensions/MaterialBrushShader.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
class AbyssBrush final: public MaterialBrushShader
{
public:
    AbyssBrush();

    /// Gets or sets the speed of the waves
    //@{
    float GetSpeed() const;
    void SetSpeed(float value);
    //@}

public:
    static constexpr float DefaultSpeed = 0.1f;

    static const Noesis::DependencyProperty* SpeedProperty;

    NS_DECLARE_REFLECTION(AbyssBrush, MaterialBrushShader)
};
