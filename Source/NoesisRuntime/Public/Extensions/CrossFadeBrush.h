////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Noesis includes
#include "NoesisSDK.h"

#include "Extensions/MaterialBrushShader.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Interpolates between two images.
///
/// .. code-block:: xml
///
///  <StackPanel
///    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
///    xmlns:noesis="clr-namespace:NoesisGUIExtensions;assembly=Noesis.GUI.Extensions"
///    Orientation="Horizontal"
///    Height="300">
///    <Image Source="tulip.png"/>
///    <Image Source="pinkrose.png"/>
///    <Rectangle Width="300">
///      <Rectangle.Fill>
///        <ImageBrush ImageSource="tulip.png">
///          <noesis:Brush.Shader>
///            <noesis:CrossFadeBrush Source="pinkrose.png" Weight="0.4" />
///          </noesis:Brush.Shader>
///        </ImageBrush>
///      </Rectangle.Fill>
///    </Rectangle>
///  </StackPanel>
///
/// .. image:: CrossFade.jpg
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class NOESISRUNTIME_API CrossFadeBrush final: public MaterialBrushShader
{
public:
    CrossFadeBrush();

    /// Gets or sets the primary source image
    //@{
    Noesis::ImageSource* GetSource1() const;
    void SetSource1(Noesis::ImageSource* source);
    //@}

    /// Gets or sets the secondary source image
    //@{
    Noesis::ImageSource* GetSource2() const;
    void SetSource2(Noesis::ImageSource* source);
    //@}

    /// Gets or sets how much to weigh the source image color values
    //@{
    float GetWeight() const;
    void SetWeight(float value);
    //@}

public:
    static const Noesis::DependencyProperty* Source1Property;
    static const Noesis::DependencyProperty* Source2Property;
    static const Noesis::DependencyProperty* WeightProperty;

    NS_DECLARE_REFLECTION(CrossFadeBrush, MaterialBrushShader)
};
