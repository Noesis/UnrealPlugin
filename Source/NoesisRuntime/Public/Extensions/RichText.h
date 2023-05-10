////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// Noesis includes
#include "NsCore/ReflectionDeclare.h"

namespace Noesis
{
    class DependencyProperty;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Adds a *Text* attached property for TextBlock which formats Unreal-style RichText into Inlines.
///
/// A single Decorator markup tag, **img**, is provided. This will generate an Image contained in 
/// an InlineUIContainer, with it's Style set to the resource key supplied by the id parameter.
///
/// If a tag name does not match a Decorator, it will be used as a Style resource key. If a
/// resource is found with this key, a Span will be created with that Style set to it.
///
/// This example uses the following DataContext:
/// Title: "<Header1>Header Text</> <img id='HeaderIcon' />"
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
///      </Grid.Resources>
///      <TextBlock noesis:RichText.Text="{Binding Title}" />
///    </Grid>
///
////////////////////////////////////////////////////////////////////////////////////////////////////
struct NOESISRUNTIME_API RichText
{
    static const Noesis::DependencyProperty* TextProperty;

    NS_DECLARE_REFLECTION(RichText, Noesis::NoParent)
};