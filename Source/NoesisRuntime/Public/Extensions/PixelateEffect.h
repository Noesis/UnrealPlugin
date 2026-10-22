////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Noesis includes
#include "NoesisSDK.h"

#include "Extensions/MaterialShaderEffect.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// ShaderEffect that applies a mosaic/pixelated style to a visual.
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
///       <noesis:PixelateEffect Size="5"/>
///      </Image.Effect>
///    </Image>
///  </StackPanel>
///
/// .. image:: Pixelate.jpg
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class NOESISRUNTIME_API PixelateEffect final: public MaterialShaderEffect
{
public:
    PixelateEffect();

    /// Gets or sets the dimensions of the pixelation blocks, measured in pixels
    //@{
    float GetSize() const;
    void SetSize(float value);
    //@}

public:
    static const Noesis::DependencyProperty* SizeProperty;

    NS_DECLARE_REFLECTION(PixelateEffect, MaterialShaderEffect)
};
