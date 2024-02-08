////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// Noesis includes
#include "NoesisSDK.h"

namespace Noesis
{
    class DependencyProperty;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Adds a *Text* attached property for TextBlock which formats Unreal-style RichText into Inlines.
///
/// Default provided Decorator markup tags, with their Inline output:
///
/// * *img*: Image, with Style set to the **id** parameter,
///   `"<img id='StyleKey' />`
///
/// Custom markup tag support can be implemented using the TryCreateInlineCallback, which is
/// invoked whenever an unknown tag is found. This method can create an Inline, which will be added
/// to the TextBlock, or return nullptr if there is no match.
///
/// .. code-block:: c++
///
///    RichText::SetTryCreateInlineCallback([](const char* tagName,
///      Noesis::ArrayRef<RichText::Parameter> parameters,
///      const Noesis::TextBlock* parent) -> Noesis::Ptr<Noesis::Inline>
///    {
///      if (Noesis::StrEquals(tagName, "run"))
///      {
///        return Noesis::MakePtr<Noesis::Run>("A run with some text");
///      }
///      return nullptr;
///    });
///
/// If a tag name is not matched, it will be used as a Style resource key. If a
/// resource is found with this key, an element of the Style TargetType will be created
/// with that Style set to it. If a TargetType ContentControl is used, and the tag has
/// content, this content will be applied to ContentControl.Content.
///
/// This example uses the following DataContext:
/// Title: "<Header1>Header Text</> <img id='HeaderIcon'/> <RiveAnim/> <RndCorner>Content</>"
///
/// .. code-block:: xml
///
///    <Grid
///      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
///      xmlns:noesis="clr-namespace:NoesisGUIExtensions;assembly=Noesis.GUI.Extensions">
///      <Grid.Resources>
///        <Style x:Key="Header1" TargetType="{x:Type Span}">
///          <Setter Property="FontSize" Value="30"/>
///          <Setter Property="Foreground" Value="Green"/>
///        </Style>
///        <Style x:Key="HeaderIcon" TargetType="{x:Type Image}">
///          <Setter Property="Source" Value="icon.png"/>
///          <Setter Property="Width" Value="32"/>
///          <Setter Property="Height" Value="32"/>
///        </Style>
///        <Style x:Key="RiveAnim" TargetType="{x:Type noesis:RiveControl}">
///          <Setter Property="Source" Value="anim.riv"/>
///          <Setter Property="Width" Value="120"/>
///          <Setter Property="Height" Value="60"/>
///        </Style>
///        <Style x:Key="RndCorner" TargetType="ContentControl">
///          <Setter Property="Background" Value="Gray"/>
///          <Setter Property="Template">
///            <Setter.Value>
///              <ControlTemplate TargetType="ContentControl">
///                <Border Background="{TemplateBinding Background}" CornerRadius="4">
///                  <ContentPresenter/>
///                </Border>
///              </ControlTemplate>
///            </Setter.Value>
///          </Setter>
///        </Style>
///      </Grid.Resources>
///      <TextBlock noesis:RichText.Text="{Binding Title}" />
///    </Grid>
///
////////////////////////////////////////////////////////////////////////////////////////////////////
struct NOESISRUNTIME_API RichText
{
    typedef Noesis::Pair<Noesis::FixedString<8>, Noesis::FixedString<128>> Parameter;

    /// Sets the callback invoked when a tag requires that an Inline be created
    typedef Noesis::Ptr<Noesis::Inline> (*TryCreateInlineCallback)(const char* tagName,
        Noesis::ArrayRef<Parameter> parameters, const Noesis::TextBlock* parent);
    static void SetTryCreateInlineCallback(TryCreateInlineCallback callback);

    static const Noesis::DependencyProperty* TextProperty;

    NS_DECLARE_REFLECTION(RichText, Noesis::NoParent)
};
