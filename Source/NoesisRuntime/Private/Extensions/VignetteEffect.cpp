////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Extensions/VignetteEffect.h"
#include "NoesisAssetDependency.h"

#include <NsGui/UIElementData.h>
#include <NsGui/UIPropertyMetadata.h>
#include <NsCore/ReflectionImplement.h>

#ifdef NS_HAVE_STUDIO
#include <NsGui/StudioMeta.h>
#endif


const Noesis::Color VignetteEffect::DefaultColor = Noesis::Color::Black();

////////////////////////////////////////////////////////////////////////////////////////////////////
VignetteEffect::VignetteEffect():
    MaterialShaderEffect(TEXT("/NoesisGUI/Internal/VignetteEffect.VignetteEffect"))
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::Color& VignetteEffect::GetColor() const
{
    return GetValue<Noesis::Color>(ColorProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void VignetteEffect::SetColor(const Noesis::Color& value)
{
    SetValue<Noesis::Color>(ColorProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float VignetteEffect::GetStrength() const
{
    return GetValue<float>(StrengthProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void VignetteEffect::SetStrength(float value)
{
    SetValue<float>(StrengthProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float VignetteEffect::GetSize() const
{
    return GetValue<float>(SizeProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void VignetteEffect::SetSize(float value)
{
    SetValue<float>(SizeProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(VignetteEffect, "NoesisGUIExtensions.VignetteEffect")
{
    using namespace Noesis;

#if WITH_EDITORONLY_DATA
    NsMeta<AssetDependency>("/NoesisGUI;component/Internal/VignetteEffect");
#endif

  #ifdef NS_HAVE_STUDIO
    NsProp("Color", &VignetteEffect::GetColor, &VignetteEffect::SetColor)
        .Meta<StudioOrder>(0);
    NsProp("Size", &VignetteEffect::GetSize, &VignetteEffect::SetSize)
        .Meta<StudioOrder>(1)
        .Meta<StudioRange>(0.1f, 5.0f);
    NsProp("Strength", &VignetteEffect::GetStrength, &VignetteEffect::SetStrength)
        .Meta<StudioOrder>(2)
        .Meta<StudioRange>(0.1f, 50.0f);
  #endif

    auto OnColorChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        VignetteEffect* this_ = DynamicCast<VignetteEffect*>(o);
        if (this_ != nullptr)
        {
            this_->SetVectorParameterValue(FName("Color"), args.NewValue<Color>());
        }
    };

    auto OnStrengthChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        VignetteEffect* this_ = DynamicCast<VignetteEffect*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("Strength"), args.NewValue<float>());
        }
    };

    auto OnSizeChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        VignetteEffect* this_ = DynamicCast<VignetteEffect*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("Size"), args.NewValue<float>());
        }
    };

    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<Color>(ColorProperty, "Color", UIPropertyMetadata::Create(
        DefaultColor, PropertyChangedCallback(OnColorChanged)));
    data->RegisterProperty<float>(StrengthProperty, "Strength", UIPropertyMetadata::Create(
        DefaulStrength, PropertyChangedCallback(OnStrengthChanged)));
    data->RegisterProperty<float>(SizeProperty, "Size", UIPropertyMetadata::Create(
        DefaulSize, PropertyChangedCallback(OnSizeChanged)));
}

NS_END_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* VignetteEffect::ColorProperty;
const Noesis::DependencyProperty* VignetteEffect::StrengthProperty;
const Noesis::DependencyProperty* VignetteEffect::SizeProperty;
