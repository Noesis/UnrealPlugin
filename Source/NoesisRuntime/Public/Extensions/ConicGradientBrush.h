////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Noesis includes
#include "NoesisSDK.h"

#include "MaterialBrushShader.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Creates an pattern consisting of a gradient with color transitions rotated around a center point
///
/// Conic gradients are similar to radial gradients, except that the color stops are on the outer
/// edge of the circle that gets created.
///
/// .. code-block:: xml
///
///  <StackPanel
///    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
///    xmlns:noesis="clr-namespace:NoesisGUIExtensions"
///    Orientation="Horizontal">
///    <Rectangle Width="600" Height="300">
///      <Rectangle.Fill>
///        <ImageBrush>
///          <noesis:Brush.Shader>
///            <noesis:ConicGradientBrush CenterX="0.5" CenterY="0.5">
///              <GradientStop Color="Red" Offset="0.0" />
///              <GradientStop Color="Orange" Offset="0.25" />
///              <GradientStop Color="Yellow" Offset="0.50" />
///              <GradientStop Color="Green" Offset="0.75" />
///              <GradientStop Color="Blue" Offset="1.0" />
///            </noesis:ConicGradientBrush>
///          </noesis:Brush.Shader>
///        </ImageBrush>
///      </Rectangle.Fill>
///    </Rectangle>
///  </StackPanel>
///
/// .. image:: Conic.jpg
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class NOESISRUNTIME_API ConicGradientBrush final: public MaterialBrushShader
{
public:
    ConicGradientBrush();

    /// Gets or sets the brush's gradient stops
    //@{
    Noesis::GradientStopCollection* GetGradientStops() const;
    void SetGradientStops(Noesis::GradientStopCollection* stops);
    //@}

    /// Gets or sets the origin of of the gradient's center in relative coordinates (0.0 to 1.0)
    //@{
    const Noesis::Point& GetCenter() const;
    void SetCenter(const Noesis::Point& value);
    //@}

public:
    static const Noesis::DependencyProperty* GradientStopsProperty;
    static const Noesis::DependencyProperty* CenterProperty;

private:
    void UpdateStops(Noesis::Freezable*, Noesis::FreezableEventReason);
    void UpdateGradients(Noesis::GradientStopCollection* collection);

    NS_DECLARE_REFLECTION(ConicGradientBrush, MaterialBrushShader)
};
