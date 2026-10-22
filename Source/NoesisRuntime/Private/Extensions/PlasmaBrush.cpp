////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Extensions/PlasmaBrush.h"
#include "NoesisAssetDependency.h"

#include <NsGui/UIElementData.h>
#include <NsGui/UIPropertyMetadata.h>
#include <NsCore/ReflectionImplement.h>

#ifdef NS_HAVE_STUDIO
#include <NsGui/StudioMeta.h>
#endif


const Noesis::Color PlasmaBrush::DefaultColor = Noesis::Color(0.0f, 0.63f, 1.0f, 1.0f);

////////////////////////////////////////////////////////////////////////////////////////////////////
PlasmaBrush::PlasmaBrush():
    MaterialBrushShader(TEXT("/NoesisGUI/Internal/PlasmaBrush.PlasmaBrush"))
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::Color& PlasmaBrush::GetColor() const
{
    return GetValue<Noesis::Color>(ColorProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void PlasmaBrush::SetColor(const Noesis::Color& value)
{
    SetValue<Noesis::Color>(ColorProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float PlasmaBrush::GetScaleX() const
{
    return GetValue<float>(ScaleXProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void PlasmaBrush::SetScaleX(float value)
{
    SetValue<float>(ScaleXProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float PlasmaBrush::GetScaleY() const
{
    return GetValue<float>(ScaleYProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void PlasmaBrush::SetScaleY(float value)
{
    SetValue<float>(ScaleYProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float PlasmaBrush::GetThickness() const
{
    return GetValue<float>(ThicknessProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void PlasmaBrush::SetThickness(float value)
{
    SetValue<float>(ThicknessProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float PlasmaBrush::GetTime() const
{
    return GetValue<float>(TimeProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void PlasmaBrush::SetTime(float value)
{
    SetValue<float>(TimeProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float PlasmaBrush::GetSeed() const
{
    return GetValue<float>(SeedProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void PlasmaBrush::SetSeed(float value)
{
    SetValue<float>(SeedProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(PlasmaBrush, "NoesisGUIExtensions.PlasmaBrush")
{
    using namespace Noesis;

#if WITH_EDITORONLY_DATA
    NsMeta<AssetDependency>("/NoesisGUI;component/Internal/PlasmaBrush");
#endif

  #ifdef NS_HAVE_STUDIO
    NsProp("ScaleX", &PlasmaBrush::GetScaleX, &PlasmaBrush::SetScaleX)
        .Meta<StudioOrder>(0);
    NsProp("ScaleY", &PlasmaBrush::GetScaleY, &PlasmaBrush::SetScaleY)
        .Meta<StudioOrder>(1);
    NsProp("Color", &PlasmaBrush::GetColor, &PlasmaBrush::SetColor)
        .Meta<StudioOrder>(2);
    NsProp("Thickness", &PlasmaBrush::GetThickness, &PlasmaBrush::SetThickness)
        .Meta<StudioOrder>(3)
        .Meta<StudioRange>(0.0f, 1.0f);
    NsProp("Time", &PlasmaBrush::GetTime, &PlasmaBrush::SetTime)
        .Meta<StudioOrder>(4);
    NsProp("Seed", &PlasmaBrush::GetSeed, &PlasmaBrush::SetSeed)
        .Meta<StudioOrder>(5);
  #endif

    auto OnColorChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        PlasmaBrush* this_ = DynamicCast<PlasmaBrush*>(o);
        if (this_)
        {
            this_->SetVectorParameterValue(FName("Color"), args.NewValue<Color>());
        }
    };

    auto OnScaleXChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        PlasmaBrush* this_ = DynamicCast<PlasmaBrush*>(o);
        if (this_)
        {
            this_->SetScalarParameterValue(FName("ScaleX"), args.NewValue<float>());
        }
    };

    auto OnScaleYChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        PlasmaBrush* this_ = DynamicCast<PlasmaBrush*>(o);
        if (this_)
        {
            this_->SetScalarParameterValue(FName("ScaleY"), args.NewValue<float>());
        }
    };

    auto OnTimeChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        PlasmaBrush* this_ = DynamicCast<PlasmaBrush*>(o);
        if (this_)
        {
            this_->SetScalarParameterValue(FName("Time"), args.NewValue<float>());
        }
    };

    auto OnSeedChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        PlasmaBrush* this_ = DynamicCast<PlasmaBrush*>(o);
        if (this_)
        {
            this_->SetScalarParameterValue(FName("Seed"), args.NewValue<float>());
        }
    };

    auto OnThicknessChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        PlasmaBrush* this_ = DynamicCast<PlasmaBrush*>(o);
        if (this_)
        {
            this_->SetScalarParameterValue(FName("Thickness"), args.NewValue<float>());
        }
    };

    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<Color>(ColorProperty, "Color", UIPropertyMetadata::Create(
        DefaultColor, PropertyChangedCallback(OnColorChanged)));
    data->RegisterProperty<float>(ScaleXProperty, "ScaleX", UIPropertyMetadata::Create(
        DefaulScaleX, PropertyChangedCallback(OnScaleXChanged)));
    data->RegisterProperty<float>(ScaleYProperty, "ScaleY", UIPropertyMetadata::Create(
        DefaulScaleY, PropertyChangedCallback(OnScaleYChanged)));
    data->RegisterProperty<float>(TimeProperty, "Time", UIPropertyMetadata::Create(
        DefaultTime, PropertyChangedCallback(OnTimeChanged)));
    data->RegisterProperty<float>(SeedProperty, "Seed", UIPropertyMetadata::Create(
        DefaultSeed, PropertyChangedCallback(OnSeedChanged)));
    data->RegisterProperty<float>(ThicknessProperty, "Thickness", UIPropertyMetadata::Create(
        DefaultThickness, PropertyChangedCallback(OnThicknessChanged)));
}

NS_END_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* PlasmaBrush::ColorProperty;
const Noesis::DependencyProperty* PlasmaBrush::ScaleXProperty;
const Noesis::DependencyProperty* PlasmaBrush::ScaleYProperty;
const Noesis::DependencyProperty* PlasmaBrush::TimeProperty;
const Noesis::DependencyProperty* PlasmaBrush::SeedProperty;
const Noesis::DependencyProperty* PlasmaBrush::ThicknessProperty;
