////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Extensions/CrossFadeBrush.h"
#include "NoesisAssetDependency.h"

#include <NsGui/UIElementData.h>
#include <NsGui/UIPropertyMetadata.h>
#include <NsCore/ReflectionImplement.h>

#ifdef NS_HAVE_STUDIO
#include <NsGui/StudioMeta.h>
#endif


static constexpr float DefaultWeight = 0.5f;


////////////////////////////////////////////////////////////////////////////////////////////////////
CrossFadeBrush::CrossFadeBrush():
    MaterialBrushShader(TEXT("/NoesisGUI/Internal/CrossFadeBrush.CrossFadeBrush"))
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
Noesis::ImageSource* CrossFadeBrush::GetSource1() const
{
    return GetValue<Noesis::Ptr<Noesis::ImageSource>>(Source1Property);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CrossFadeBrush::SetSource1(Noesis::ImageSource* source)
{
    SetValue<Noesis::Ptr<Noesis::ImageSource>>(Source1Property, source);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
Noesis::ImageSource* CrossFadeBrush::GetSource2() const
{
    return GetValue<Noesis::Ptr<Noesis::ImageSource>>(Source2Property);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CrossFadeBrush::SetSource2(Noesis::ImageSource* source)
{
    SetValue<Noesis::Ptr<Noesis::ImageSource>>(Source2Property, source);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float CrossFadeBrush::GetWeight() const
{
    return GetValue<float>(WeightProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CrossFadeBrush::SetWeight(float value)
{
    SetValue<float>(WeightProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(CrossFadeBrush, "NoesisGUIExtensions.CrossFadeBrush")
{
    using namespace Noesis;

#if WITH_EDITORONLY_DATA
    NsMeta<AssetDependency>("/NoesisGUI;component/Internal/CrossFadeBrush");
#endif

  #ifdef NS_HAVE_STUDIO
    NsProp("Source1", &CrossFadeBrush::GetSource1, &CrossFadeBrush::SetSource1)
        .Meta<StudioOrder>(0);
    NsProp("Source2", &CrossFadeBrush::GetSource2, &CrossFadeBrush::SetSource2)
        .Meta<StudioOrder>(1);
    NsProp("Weight", &CrossFadeBrush::GetWeight, &CrossFadeBrush::SetWeight)
        .Meta<StudioOrder>(2)
        .Meta<StudioEditor>("NumericProperty.Percentage");
  #endif

    auto OnSource1Changed = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        CrossFadeBrush* this_ = DynamicCast<CrossFadeBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetTextureParameterValue(FName("Source1"), args.NewValue<Ptr<ImageSource>>());
        }
    };

    auto OnSource2Changed = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        CrossFadeBrush* this_ = DynamicCast<CrossFadeBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetTextureParameterValue(FName("Source2"), args.NewValue<Ptr<ImageSource>>());
        }
    };

    auto OnWeightChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        CrossFadeBrush* this_ = DynamicCast<CrossFadeBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("Weight"), args.NewValue<float>());
        }
    };

    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<Ptr<ImageSource>>(Source1Property, "Source1", UIPropertyMetadata::Create(
        Ptr<ImageSource>(), PropertyChangedCallback(OnSource1Changed)));
    data->RegisterProperty<Ptr<ImageSource>>(Source2Property, "Source2", UIPropertyMetadata::Create(
        Ptr<ImageSource>(), PropertyChangedCallback(OnSource2Changed)));
    data->RegisterProperty<float>(WeightProperty, "Weight", UIPropertyMetadata::Create(
        DefaultWeight, PropertyChangedCallback(OnWeightChanged)));
}

NS_END_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* CrossFadeBrush::Source1Property;
const Noesis::DependencyProperty* CrossFadeBrush::Source2Property;
const Noesis::DependencyProperty* CrossFadeBrush::WeightProperty;
