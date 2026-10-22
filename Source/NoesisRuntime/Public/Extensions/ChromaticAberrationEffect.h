////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Noesis includes
#include "NoesisSDK.h"

#include "Extensions/MaterialShaderEffect.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Creates a chromatic distortion simulating a lens failure to focus all colors to the same point.
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
///        <noesis:ChromaticAberrationEffect AmountX="11.0"/>
///      </Image.Effect>
///    </Image>
///  </StackPanel>
///
/// .. image:: Aberration.jpg
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class NOESISRUNTIME_API ChromaticAberrationEffect final: public MaterialShaderEffect
{
public:
    ChromaticAberrationEffect();

    /// Gets or sets the horizontal intensity of the chromatic aberration
    //@{
    float GetAmountX() const;
    void SetAmountX(float value);
    //@}

    /// Gets or sets the vertical intensity of the chromatic aberration
    //@{
    float GetAmountY() const;
    void SetAmountY(float value);
    //@}

public:
    static const Noesis::DependencyProperty* AmountXProperty;
    static const Noesis::DependencyProperty* AmountYProperty;

    NS_DECLARE_REFLECTION(ChromaticAberrationEffect, ShaderEffect)
};
