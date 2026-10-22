////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Extensions/TintEffect.h"
#include "NoesisAssetDependency.h"

#include <NsGui/UIElementData.h>
#include <NsGui/UIPropertyMetadata.h>
#include <NsCore/ReflectionImplement.h>

#ifdef NS_HAVE_STUDIO
#include <NsGui/StudioMeta.h>
#endif


const Noesis::Color TintEffect::DefaultColor = Noesis::Color(1.0f, 0.8f, 0.6f, 1.0f);

////////////////////////////////////////////////////////////////////////////////////////////////////
TintEffect::TintEffect():
    MaterialShaderEffect(TEXT("/NoesisGUI/Internal/TintEffect.TintEffect"))
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::Color& TintEffect::GetColor() const
{
    return GetValue<Noesis::Color>(ColorProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void TintEffect::SetColor(const Noesis::Color& value)
{
    SetValue<Noesis::Color>(ColorProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float TintEffect::GetIntensity() const
{
    return GetValue<float>(IntensityProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void TintEffect::SetIntensity(float value)
{
    SetValue<float>(IntensityProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(TintEffect, "NoesisGUIExtensions.TintEffect")
{
    using namespace Noesis;

#if WITH_EDITORONLY_DATA
    NsMeta<AssetDependency>("/NoesisGUI;component/Internal/TintEffect");
#endif

  #ifdef NS_HAVE_STUDIO
    NsProp("Color", &TintEffect::GetColor, &TintEffect::SetColor)
        .Meta<StudioOrder>(0);
    NsProp("Intensity", &TintEffect::GetIntensity, &TintEffect::SetIntensity)
        .Meta<StudioOrder>(1)
        .Meta<StudioEditor>("NumericProperty.Percentage");
  #endif

    auto OnColorChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        TintEffect* this_ = DynamicCast<TintEffect*>(o);
        {
            this_->SetVectorParameterValue(FName("Color"), args.NewValue<Color>());
        }
    };

    auto OnIntensityChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        TintEffect* this_ = DynamicCast<TintEffect*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("Intensity"), args.NewValue<float>());
        }
    };

    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<Color>(ColorProperty, "Color", UIPropertyMetadata::Create(
        DefaultColor, PropertyChangedCallback(OnColorChanged)));
    data->RegisterProperty<float>(IntensityProperty, "Intensity", UIPropertyMetadata::Create(
        DefaultIntensity, PropertyChangedCallback(OnIntensityChanged)));
}

NS_END_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* TintEffect::ColorProperty;
const Noesis::DependencyProperty* TintEffect::IntensityProperty;
