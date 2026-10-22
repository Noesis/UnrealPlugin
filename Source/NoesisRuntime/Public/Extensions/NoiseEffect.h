////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Noesis includes
#include "NoesisSDK.h"

#include "Extensions/MaterialShaderEffect.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// The Noise effect simulates high-speed film grain, adding random pixel patterns.
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
///       <noesis:NoiseEffect Amount="0.45"/>
///      </Image.Effect>
///    </Image>
///  </StackPanel>
///
/// .. image:: Noise.jpg
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class NOESISRUNTIME_API NoiseEffect final: public MaterialShaderEffect
{
public:
    NoiseEffect();

    /// Gets or sets the amount of noise, ranging from 0.0 to 1.0
    //@{
    float GetAmount() const;
    void SetAmount(float value);
    //@}

    /// Gets or sets the time parameter associated with animating the noise effect
    //@{
    float GetTime() const;
    void SetTime(float value);
    //@}

    /// Gets or sets whether the noise is grayscale or multicolored
    //@{
    bool GetMonochromatic() const;
    void SetMonochromatic(bool value);
    //@}

public:
    static constexpr float DefaultAmount = 0.50f;
    static constexpr float DefaultTime = 0.0f;
    static constexpr bool DefaultMono = false;

    static const Noesis::DependencyProperty* AmountProperty;
    static const Noesis::DependencyProperty* TimeProperty;
    static const Noesis::DependencyProperty* MonochromaticProperty;

    NS_DECLARE_REFLECTION(NoiseEffect, MaterialShaderEffect)
};
