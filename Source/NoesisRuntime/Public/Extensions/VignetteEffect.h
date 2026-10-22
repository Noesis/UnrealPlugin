////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Noesis includes
#include "NoesisSDK.h"

#include "Extensions/MaterialShaderEffect.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Fades the input image at the edges to a user-set color.
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
///        <noesis:VignetteEffect Strength="30" Size="0.50"/>
///      </Image.Effect>
///    </Image>
///  </StackPanel>
///
/// .. image:: Vignette.jpg
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class NOESISRUNTIME_API VignetteEffect final: public MaterialShaderEffect
{
public:
    VignetteEffect();

    /// Gets or sets the RGB tripplet that specifies the color to fade the image's edges to
    //@{
    const Noesis::Color& GetColor() const;
    void SetColor(const Noesis::Color& value);
    //@}

    /// Gets or sets a float value that specifies how much the vignette color bleeds in for a 
    /// given transition size
    //@{
    float GetStrength() const;
    void SetStrength(float value);
    //@}

    /// Gets or sets a float value that specifies the size of the vignette region as a percentage
    /// of the full image region
    //@{
    float GetSize() const;
    void SetSize(float value);
    //@}

public:
    static const Noesis::Color DefaultColor;
    static constexpr float DefaulStrength = 15.0f;
    static constexpr float DefaulSize = 0.25f;

    static const Noesis::DependencyProperty* ColorProperty;
    static const Noesis::DependencyProperty* StrengthProperty;
    static const Noesis::DependencyProperty* SizeProperty;

    NS_DECLARE_REFLECTION(VignetteEffect, MaterialShaderEffect)
};
