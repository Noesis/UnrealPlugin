////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Extensions/NoiseEffect.h"
#include "NoesisAssetDependency.h"

#include <NsGui/UIElementData.h>
#include <NsGui/UIPropertyMetadata.h>
#include <NsCore/ReflectionImplement.h>

#ifdef NS_HAVE_STUDIO
#include <NsGui/StudioMeta.h>
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////
NoiseEffect::NoiseEffect():
    MaterialShaderEffect(TEXT("/NoesisGUI/Internal/NoiseEffect.NoiseEffect"))
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float NoiseEffect::GetAmount() const
{
    return GetValue<float>(AmountProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void NoiseEffect::SetAmount(float value)
{
    SetValue<float>(AmountProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float NoiseEffect::GetTime() const
{
    return GetValue<float>(TimeProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void NoiseEffect::SetTime(float value)
{
    SetValue<float>(TimeProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool NoiseEffect::GetMonochromatic() const
{
    return GetValue<bool>(MonochromaticProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void NoiseEffect::SetMonochromatic(bool value)
{
    SetValue<bool>(MonochromaticProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(NoiseEffect, "NoesisGUIExtensions.NoiseEffect")
{
    using namespace Noesis;

#if WITH_EDITORONLY_DATA
    NsMeta<AssetDependency>("/NoesisGUI;component/Internal/NoiseEffect");
#endif

  #ifdef NS_HAVE_STUDIO
    NsProp("Amount", &NoiseEffect::GetAmount, &NoiseEffect::SetAmount)
        .Meta<StudioOrder>(0)
        .Meta<StudioEditor>("NumericProperty.Percentage");
    NsProp("Time", &NoiseEffect::GetTime, &NoiseEffect::SetTime)
        .Meta<StudioOrder>(1);
    NsProp("Monochromatic", &NoiseEffect::GetMonochromatic, &NoiseEffect::SetMonochromatic)
        .Meta<StudioOrder>(2);
  #endif

    auto OnAmountChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        NoiseEffect* this_ = DynamicCast<NoiseEffect*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("Amount"), args.NewValue<float>());
        }
    };

    auto OnTimeChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        NoiseEffect* this_ = DynamicCast<NoiseEffect*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("Time"), args.NewValue<float>());
        }
    };

    auto OnMonochromaticChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        NoiseEffect* this_ = DynamicCast<NoiseEffect*>(o);
        if (this_ != nullptr)
        {
            bool mono = args.NewValue<bool>();
            this_->SetScalarParameterValue(FName("Monochromatic"), mono ? 1.0f : 0.0f);
        }
    };

    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<float>(AmountProperty, "Amount", UIPropertyMetadata::Create(
        DefaultAmount, PropertyChangedCallback(OnAmountChanged)));
    data->RegisterProperty<float>(TimeProperty, "Time", UIPropertyMetadata::Create(
        DefaultTime, PropertyChangedCallback(OnTimeChanged)));
    data->RegisterProperty<bool>(MonochromaticProperty, "Monochromatic", UIPropertyMetadata::Create(
        DefaultMono, PropertyChangedCallback(OnMonochromaticChanged)));
}

NS_END_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* NoiseEffect::AmountProperty;
const Noesis::DependencyProperty* NoiseEffect::TimeProperty;
const Noesis::DependencyProperty* NoiseEffect::MonochromaticProperty;
