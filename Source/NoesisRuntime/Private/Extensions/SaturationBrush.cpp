  ////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Extensions/SaturationBrush.h"
#include "NoesisAssetDependency.h"

#include <NsGui/UIElementData.h>
#include <NsGui/UIPropertyMetadata.h>
#include <NsCore/ReflectionImplement.h>

#ifdef NS_HAVE_STUDIO
#include <NsGui/StudioMeta.h>
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////
SaturationBrush::SaturationBrush():
    MaterialBrushShader(TEXT("/NoesisGUI/Internal/SaturationBrush.SaturationBrush"))
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
Noesis::ImageSource* SaturationBrush::GetSource() const
{
    return GetValue<Noesis::Ptr<Noesis::ImageSource>>(SourceProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void SaturationBrush::SetSource(Noesis::ImageSource* source)
{
    SetValue<Noesis::Ptr<Noesis::ImageSource>>(SourceProperty, source);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float SaturationBrush::GetSaturation() const
{
    return GetValue<float>(SaturationProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void SaturationBrush::SetSaturation(float value)
{
    SetValue<float>(SaturationProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(SaturationBrush, "NoesisGUIExtensions.SaturationBrush")
{
    using namespace Noesis;

#if WITH_EDITORONLY_DATA
    NsMeta<AssetDependency>("/NoesisGUI;component/Internal/SaturationBrush");
#endif

  #ifdef NS_HAVE_STUDIO
    NsProp("Source", &SaturationBrush::GetSource, &SaturationBrush::SetSource)
        .Meta<StudioOrder>(0);
    NsProp("Saturation", &SaturationBrush::GetSaturation, &SaturationBrush::SetSaturation)
        .Meta<StudioOrder>(1)
        .Meta<StudioEditor>("NumericProperty.Percentage");
  #endif

    auto OnSourceChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        SaturationBrush* this_ = DynamicCast<SaturationBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetTextureParameterValue(FName("Source"), args.NewValue<Ptr<ImageSource>>());
        }
    };

    auto OnSaturationChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        SaturationBrush* this_ = DynamicCast<SaturationBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("Saturation"), args.NewValue<float>());
        }
    };

    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<Ptr<ImageSource>>(SourceProperty, "Source", UIPropertyMetadata::Create(
        Ptr<ImageSource>(), PropertyChangedCallback(OnSourceChanged)));
    data->RegisterProperty<float>(SaturationProperty, "Saturation",
        UIPropertyMetadata::Create(DefaultSaturation, PropertyChangedCallback(OnSaturationChanged)));
}

NS_END_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* SaturationBrush::SourceProperty;
const Noesis::DependencyProperty* SaturationBrush::SaturationProperty;
