////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Extensions/PinchEffect.h"
#include "NoesisAssetDependency.h"

#include <NsGui/UIElementData.h>
#include <NsGui/UIPropertyMetadata.h>
#include <NsCore/ReflectionImplement.h>

#ifdef NS_HAVE_STUDIO
#include <NsGui/StudioMeta.h>
#endif


const Noesis::Point PinchEffect::DefaultCenter = Noesis::Point(0.5f, 0.5f);

////////////////////////////////////////////////////////////////////////////////////////////////////
PinchEffect::PinchEffect():
    MaterialShaderEffect(TEXT("/NoesisGUI/Internal/PinchEffect.PinchEffect"))
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::Point& PinchEffect::GetCenter() const
{
    return GetValue<Noesis::Point>(CenterProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void PinchEffect::SetCenter(const Noesis::Point& value)
{
    SetValue<Noesis::Point>(CenterProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float PinchEffect::GetRadiusX() const
{
    return GetValue<float>(RadiusXProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void PinchEffect::SetRadiusX(float value)
{
    SetValue<float>(RadiusXProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float PinchEffect::GetRadiusY() const
{
    return GetValue<float>(RadiusYProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void PinchEffect::SetRadiusY(float value)
{
    SetValue<float>(RadiusYProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float PinchEffect::GetAmount() const
{
    return GetValue<float>(AmountProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void PinchEffect::SetAmount(float value)
{
    SetValue<float>(AmountProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(PinchEffect, "NoesisGUIExtensions.PinchEffect")
{
    using namespace Noesis;

#if WITH_EDITORONLY_DATA
    NsMeta<AssetDependency>("/NoesisGUI;component/Internal/PinchEffect");
#endif

  #ifdef NS_HAVE_STUDIO
    NsProp("Center", &PinchEffect::GetCenter, &PinchEffect::SetCenter)
        .Meta<StudioOrder>(0);
    NsProp("RadiusX", &PinchEffect::GetRadiusX, &PinchEffect::SetRadiusX)
        .Meta<StudioOrder>(1)
        .Meta<StudioRange>(0.0f, 1.0f);
    NsProp("RadiusY", &PinchEffect::GetRadiusY, &PinchEffect::SetRadiusY)
        .Meta<StudioOrder>(2)
        .Meta<StudioRange>(0.0f, 1.0f);
    NsProp("Amount", &PinchEffect::GetAmount, &PinchEffect::SetAmount)
        .Meta<StudioOrder>(3)
        .Meta<StudioRange>(-2.0f, 2.0f);
  #endif

    auto OnCenterChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        PinchEffect* this_ = DynamicCast<PinchEffect*>(o);
        if (this_ != nullptr)
        {
            const Point& c = args.NewValue<Point>();
            this_->SetScalarParameterValue(FName("CenterX"), c.x);
            this_->SetScalarParameterValue(FName("CenterY"), c.y);
        }
    };

    auto OnRadiusXChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        PinchEffect* this_ = DynamicCast<PinchEffect*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("RadiusX"), Max(args.NewValue<float>(), 0.0001f));
        }
    };

    auto OnRadiusYChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        PinchEffect* this_ = DynamicCast<PinchEffect*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("RadiusY"), Max(args.NewValue<float>(), 0.0001f));
        }
    };

    auto OnAmountChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        PinchEffect* this_ = DynamicCast<PinchEffect*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("Amount"), args.NewValue<float>());
        }
    };

    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<Point>(CenterProperty, "Center", UIPropertyMetadata::Create(
        DefaultCenter, PropertyChangedCallback(OnCenterChanged)));
    data->RegisterProperty<float>(RadiusXProperty, "RadiusX", UIPropertyMetadata::Create(
        DefaultRadius, PropertyChangedCallback(OnRadiusXChanged)));
    data->RegisterProperty<float>(RadiusYProperty, "RadiusY", UIPropertyMetadata::Create(
        DefaultRadius, PropertyChangedCallback(OnRadiusYChanged)));
    data->RegisterProperty<float>(AmountProperty, "Amount", UIPropertyMetadata::Create(
        DefaultAmount, PropertyChangedCallback(OnAmountChanged)));
}

NS_END_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* PinchEffect::CenterProperty;
const Noesis::DependencyProperty* PinchEffect::RadiusXProperty;
const Noesis::DependencyProperty* PinchEffect::RadiusYProperty;
const Noesis::DependencyProperty* PinchEffect::AmountProperty;
