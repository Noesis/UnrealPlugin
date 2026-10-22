////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Noesis includes
#include "NoesisSDK.h"

#include "Extensions/MaterialShaderEffect.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// This effect tints the source image by multiplying the source image by the specified color
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
///        <noesis:TintEffect Color="Orange"/>
///      </Image.Effect>
///    </Image>
///  </StackPanel>
///
/// .. image:: Tint.jpg
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class NOESISRUNTIME_API TintEffect final: public MaterialShaderEffect
{
public:
    TintEffect();

    /// Gets or Sets the color used to multiply the source image
    //@{
    const Noesis::Color& GetColor() const;
    void SetColor(const Noesis::Color& value);
    //@}

    /// Gets or sets the intensity of the tint effect (0.0 to 1.0)
    //@{
    float GetIntensity() const;
    void SetIntensity(float value);
    //@}

public:
    static const Noesis::Color DefaultColor;
    static constexpr float DefaultIntensity = 1.0f;

    static const Noesis::DependencyProperty* ColorProperty;
    static const Noesis::DependencyProperty* IntensityProperty;

    NS_DECLARE_REFLECTION(TintEffect, MaterialShaderEffect)
};
