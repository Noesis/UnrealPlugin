////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Noesis includes
#include "NoesisSDK.h"

#include "Extensions/MaterialShaderEffect.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Effect to warp or pinch a specific area in a visual.
///
/// .. code-block:: xml
///
///  <StackPanel Orientation="Horizontal"
///    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
///    xmlns:noesis="clr-namespace:NoesisGUIExtensions">
///
///    <Image Source="Images/tulip.png"/>
///    <Image Source="Images/tulip.png">
///      <Image.Effect>
///        <noesis:PinchEffect Amount="2.0"/>
///      </Image.Effect>
///    </Image>
///
///  </StackPanel>
///
/// .. image:: Pinch.jpg
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class NOESISRUNTIME_API PinchEffect final: public MaterialShaderEffect
{
public:
    PinchEffect();

    /// Gets or sets the origin of the pinch effect in relative coordinates (0.0 to 1.0)
    //@{
    const Noesis::Point& GetCenter() const;
    void SetCenter(const Noesis::Point& value);
    //@}

    /// Gets or sets the horizontal radius of the pinch effect in relative units (0.0 to 1.0)
    //@{
    float GetRadiusX() const;
    void SetRadiusX(float value);
    //@}

    /// Gets or sets the vertical radius of the pinch effect in relative units (0.0 to 1.0)
    //@{
    float GetRadiusY() const;
    void SetRadiusY(float value);
    //@}

    /// Gets or sets the intensity of the pinch effect
    //@{
    float GetAmount() const;
    void SetAmount(float value);
    //@}

public:
    static const Noesis::Point DefaultCenter;
    static constexpr float DefaultRadius = 0.5f;
    static constexpr float DefaultAmount = 0.5f;

    static const Noesis::DependencyProperty* CenterProperty;
    static const Noesis::DependencyProperty* RadiusXProperty;
    static const Noesis::DependencyProperty* RadiusYProperty;
    static const Noesis::DependencyProperty* AmountProperty;

    NS_DECLARE_REFLECTION(PinchEffect, MaterialShaderEffect)
};
