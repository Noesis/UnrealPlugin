////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Noesis includes
#include "NoesisSDK.h"

#include "Extensions/MaterialShaderEffect.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Use this effect to alter the saturation of an image.
///
/// .. code-block:: xml
///
///  <StackPanel
///    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
///    xmlns:noesis="clr-namespace:NoesisGUIExtensions"
///    Orientation="Horizontal">
///    <Image Source="Images/tulip.png"/>
///    <Image Source="Images/tulip.png">
///      <Image.Effect>
///       <noesis:SaturationEffect Saturation="0"/>
///      </Image.Effect>
///    </Image>
///  </StackPanel>
///
/// .. image:: Saturation.jpg
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class NOESISRUNTIME_API SaturationEffect final: public MaterialShaderEffect
{
public:
    SaturationEffect();

    /// Gets or sets the saturation level (0.0 is grayscale, 1.0 is full color)
    //@{
    float GetSaturation() const;
    void SetSaturation(float value);
    //@}

public:
    static constexpr float DefaultSaturation = 0.0f;

    static const Noesis::DependencyProperty* SaturationProperty;

    NS_DECLARE_REFLECTION(SaturationEffect, MaterialShaderEffect)
};
