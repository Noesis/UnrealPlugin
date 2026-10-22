  ////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Extensions/TintBrush.h"
#include "NoesisAssetDependency.h"

#include <NsGui/UIElementData.h>
#include <NsGui/UIPropertyMetadata.h>
#include <NsCore/ReflectionImplement.h>

#ifdef NS_HAVE_STUDIO
#include <NsGui/StudioMeta.h>
#endif


const Noesis::Color TintBrush::DefaultColor = Noesis::Color(1.0f, 0.8f, 0.6f, 1.0f);

////////////////////////////////////////////////////////////////////////////////////////////////////
TintBrush::TintBrush():
    MaterialBrushShader(TEXT("/NoesisGUI/Internal/TintBrush.TintBrush"))
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
Noesis::ImageSource* TintBrush::GetSource() const
{
    return GetValue<Noesis::Ptr<Noesis::ImageSource>>(SourceProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void TintBrush::SetSource(Noesis::ImageSource* source)
{
    SetValue<Noesis::Ptr<Noesis::ImageSource>>(SourceProperty, source);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::Color& TintBrush::GetColor() const
{
    return GetValue<Noesis::Color>(ColorProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void TintBrush::SetColor(const Noesis::Color& value)
{
    SetValue<Noesis::Color>(ColorProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float TintBrush::GetIntensity() const
{
    return GetValue<float>(IntensityProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void TintBrush::SetIntensity(float value)
{
    SetValue<float>(IntensityProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(TintBrush, "NoesisGUIExtensions.TintBrush")
{
    using namespace Noesis;

#if WITH_EDITORONLY_DATA
    NsMeta<AssetDependency>("/NoesisGUI;component/Internal/TintBrush");
#endif

  #ifdef NS_HAVE_STUDIO
    NsProp("Source", &TintBrush::GetSource, &TintBrush::SetSource)
        .Meta<StudioOrder>(0);
    NsProp("Color", &TintBrush::GetColor, &TintBrush::SetColor)
        .Meta<StudioOrder>(1);
    NsProp("Intensity", &TintBrush::GetIntensity, &TintBrush::SetIntensity)
        .Meta<StudioOrder>(2)
        .Meta<StudioEditor>("NumericProperty.Percentage");
  #endif

    auto OnSourceChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        TintBrush* this_ = DynamicCast<TintBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetTextureParameterValue(FName("Source"), args.NewValue<Ptr<ImageSource>>());
        }
    };

    auto OnColorChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        TintBrush* this_ = DynamicCast<TintBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetVectorParameterValue(FName("Color"), args.NewValue<Color>());
        }
    };

    auto OnIntensityChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        TintBrush* this_ = DynamicCast<TintBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("Intensity"), args.NewValue<float>());
        }
    };

    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<Ptr<ImageSource>>(SourceProperty, "Source", UIPropertyMetadata::Create(
        Ptr<ImageSource>(), PropertyChangedCallback(OnSourceChanged)));
    data->RegisterProperty<Color>(ColorProperty, "Color",
        UIPropertyMetadata::Create(DefaultColor, PropertyChangedCallback(OnColorChanged)));
    data->RegisterProperty<float>(IntensityProperty, "Intensity",
        UIPropertyMetadata::Create(DefaultAmount, PropertyChangedCallback(OnIntensityChanged)));
}

NS_END_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* TintBrush::SourceProperty;
const Noesis::DependencyProperty* TintBrush::ColorProperty;
const Noesis::DependencyProperty* TintBrush::IntensityProperty;
