////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Extensions/DirectionalBlurEffect.h"
#include "NoesisAssetDependency.h"

#include <NsGui/UIElementData.h>
#include <NsGui/UIPropertyMetadata.h>
#include <NsCore/ReflectionImplement.h>

#ifdef NS_HAVE_STUDIO
#include <NsGui/StudioMeta.h>
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////
DirectionalBlurEffect::DirectionalBlurEffect():
    MaterialShaderEffect(TEXT("/NoesisGUI/Internal/DirectionalBlurEffect.DirectionalBlurEffect"))
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float DirectionalBlurEffect::GetRadius() const
{
    return GetValue<float>(RadiusProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DirectionalBlurEffect::SetRadius(float value)
{
    SetValue<float>(RadiusProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float DirectionalBlurEffect::GetAngle() const
{
    return GetValue<float>(AngleProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DirectionalBlurEffect::SetAngle(float value)
{
    SetValue<float>(AngleProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(DirectionalBlurEffect, "NoesisGUIExtensions.DirectionalBlurEffect")
{
    using namespace Noesis;

#if WITH_EDITORONLY_DATA
    NsMeta<AssetDependency>("/NoesisGUI;component/Internal/DirectionalBlurEffect");
#endif

  #ifdef NS_HAVE_STUDIO
    NsProp("Radius", &DirectionalBlurEffect::GetRadius, &DirectionalBlurEffect::SetRadius)
        .Meta<StudioOrder>(0)
        .Meta<StudioMin>(0.0f);
    NsProp("Angle", &DirectionalBlurEffect::GetAngle, &DirectionalBlurEffect::SetAngle)
        .Meta<StudioOrder>(1)
        .Meta<StudioEditor>("NumericProperty.Rotation");
  #endif

    auto OnRadiusChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        DirectionalBlurEffect* this_ = DynamicCast<DirectionalBlurEffect*>(o);
        if (this_ != nullptr)
        {
            float radius = Max(args.NewValue<float>(), 0.0f);
            this_->SetScalarParameterValue(FName("Radius"), radius);
            this_->SetPadding(radius, radius, radius, radius);
        }
    };

    auto OnAngleChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        DirectionalBlurEffect* this_ = DynamicCast<DirectionalBlurEffect*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("Angle"), args.NewValue<float>());
        }
    };

    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<float>(RadiusProperty, "Radius", UIPropertyMetadata::Create(
        DefaultRadius, PropertyChangedCallback(OnRadiusChanged)));
    data->RegisterProperty<float>(AngleProperty, "Angle", UIPropertyMetadata::Create(
        0.0f, PropertyChangedCallback(OnAngleChanged)));
}

NS_END_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* DirectionalBlurEffect::RadiusProperty;
const Noesis::DependencyProperty* DirectionalBlurEffect::AngleProperty;
