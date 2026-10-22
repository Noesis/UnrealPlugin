////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Noesis includes
#include "NoesisSDK.h"

#include "Extensions/MaterialBrushShader.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// BrushShader that adjusts the saturation of an image.
///
/// .. code-block:: xml
///
///  <StackPanel
///    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
///    xmlns:noesis="clr-namespace:NoesisGUIExtensions"
///    Orientation="Horizontal">
///    <Image Source="Images/tulip.png"/>
///    <Rectangle Width="300" Height="300">
///      <Rectangle.Fill>
///        <ImageBrush ImageSource="Images/tulip.png">
///          <noesis:Brush.Shader>
///            <noesis:SaturationBrush Saturation="0.0" />
///          </noesis:Brush.Shader>
///        </ImageBrush>
///      </Rectangle.Fill>
///    </Rectangle>
///  </StackPanel>
///
/// .. image:: Saturation.jpg
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class NOESISRUNTIME_API SaturationBrush final: public MaterialBrushShader
{
public:
    SaturationBrush();

    /// Gets or sets the source image
    //@{
    Noesis::ImageSource* GetSource() const;
    void SetSource(Noesis::ImageSource* Value);
    //@}

    /// Gets or sets the saturation level (0.0 is grayscale, 1.0 is full color)
    //@{
    float GetSaturation() const;
    void SetSaturation(float value);
    //@}

public:
    static constexpr float DefaultSaturation = 0.0f;

    static const Noesis::DependencyProperty* SourceProperty;
    static const Noesis::DependencyProperty* SaturationProperty;

    NS_DECLARE_REFLECTION(SaturationBrush, MaterialBrushShader)
};
