////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Noesis includes
#include "NoesisSDK.h"

#include "Extensions/MaterialBrushShader.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// BrushShader that tints an image by multiplying it with a specified color and intensity.
///
/// .. code-block:: xml
///
///  <StackPanel
///    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
///    xmlns:noesis="clr-namespace:NoesisGUIExtensions"
///    Orientation="Horizontal">
///    <Image Source="Images/icon.png"/>
///    <Rectangle Width="300" Height="300">
///      <Rectangle.Fill>
///        <ImageBrush ImageSource="Images/icon.png">
///          <noesis:Brush.Shader>
///            <noesis:TintBrush Color="Orange" Intensity="1.0"/>
///          </noesis:Brush.Shader>
///        </ImageBrush>
///      </Rectangle.Fill>
///    </Rectangle>
///  </StackPanel>
///
/// .. image:: Tint.jpg
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class NOESISRUNTIME_API TintBrush final: public MaterialBrushShader
{
public:
    TintBrush();

    /// Gets or sets the source image
    //@{
    Noesis::ImageSource* GetSource() const;
    void SetSource(Noesis::ImageSource* Value);
    //@}

    /// Gets or sets the tint color applied to the image
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
    static constexpr float DefaultAmount = 1.0f;

    static const Noesis::DependencyProperty* SourceProperty;
    static const Noesis::DependencyProperty* ColorProperty;
    static const Noesis::DependencyProperty* IntensityProperty;

    NS_DECLARE_REFLECTION(TintBrush, MaterialBrushShader)
};
