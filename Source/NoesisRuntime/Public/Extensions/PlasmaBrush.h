////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Noesis includes
#include "NoesisSDK.h"

#include "Extensions/MaterialBrushShader.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// BrushShader that renders an animated, high-energy plasma noise effect.
///
/// .. code-block:: xml
///
///  <Page
///    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
///    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
///    xmlns:noesis="clr-namespace:NoesisGUIExtensions;assembly=Noesis.GUI.Extensions">
///    <Rectangle Width="590" Height="290">
///      <Rectangle.Fill>
///        <ImageBrush>
///          <noesis:Brush.Shader>
///            <noesis:PlasmaBrush x:Name="plasma" Color="DeepSkyBlue"
///                 ScaleX="128.0" ScaleY="128.0" />
///          </noesis:Brush.Shader>
///        </ImageBrush>
///      </Rectangle.Fill>
///      <Rectangle.Triggers>
///        <EventTrigger RoutedEvent="FrameworkElement.Loaded">
///          <BeginStoryboard>
///            <Storyboard>
///              <DoubleAnimation Storyboard.TargetName="plasma"
///                 Storyboard.TargetProperty="Time" From="0" To="100" Duration="0:2:0"
///                 RepeatBehavior="Forever" />
///            </Storyboard>
///          </BeginStoryboard>
///        </EventTrigger>
///      </Rectangle.Triggers>
///    </Rectangle>
///  </Page>
///
/// .. image:: Plasma.jpg
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class NOESISRUNTIME_API PlasmaBrush final: public MaterialBrushShader
{
public:
    PlasmaBrush();

    /// Gets or sets the base color of the plasma
    //@{
    const Noesis::Color& GetColor() const;
    void SetColor(const Noesis::Color& value);
    //@}

    /// Gets or sets the X scale of the noise
    //@{
    float GetScaleX() const;
    void SetScaleX(float value);
    //@}

    /// Gets or sets the Y scale of the noise
    //@{
    float GetScaleY() const;
    void SetScaleY(float value);
    //@}

    /// Gets or sets the thickness multiplier of the plasma arcs
    //@{
    float GetThickness() const;
    void SetThickness(float value);
    //@}

    /// Gets or sets the animation time
    //@{
    float GetTime() const;
    void SetTime(float value);
    //@}

    /// Gets or sets the noise generation seed
    //@{
    float GetSeed() const;
    void SetSeed(float value);
    //@}

public:
    static const Noesis::Color DefaultColor;
    static constexpr float DefaulScaleX = 64.0f;
    static constexpr float DefaulScaleY = 64.0f;
    static constexpr float DefaultTime = 0.0f;
    static constexpr float DefaultSeed = 0.0f;
    static constexpr float DefaultThickness = 1.0f;

    static const Noesis::DependencyProperty* ColorProperty;
    static const Noesis::DependencyProperty* ScaleXProperty;
    static const Noesis::DependencyProperty* ScaleYProperty;
    static const Noesis::DependencyProperty* TimeProperty;
    static const Noesis::DependencyProperty* SeedProperty;
    static const Noesis::DependencyProperty* ThicknessProperty;

    NS_DECLARE_REFLECTION(PlasmaBrush, MaterialBrushShader)
};
