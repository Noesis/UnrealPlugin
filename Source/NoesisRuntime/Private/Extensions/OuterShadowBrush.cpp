////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "OuterShadowBrush.h"
#include "NoesisAssetDependency.h"

#include <NsGui/UIElementData.h>
#include <NsGui/UIPropertyMetadata.h>
#include <NsCore/ReflectionImplement.h>


////////////////////////////////////////////////////////////////////////////////////////////////////
OuterShadowBrush::OuterShadowBrush():
    MaterialBrushShader(TEXT("/NoesisGUI/Internal/OuterShadowBrush.OuterShadowBrush"))
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void OuterShadowBrush::SetColor(const Noesis::Color& color)
{
    SetValue<Noesis::Color>(ColorProperty, color);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void OuterShadowBrush::SetWidth(float width)
{
    SetValue<float>(WidthProperty, width);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void OuterShadowBrush::SetHeight(float height)
{
    SetValue<float>(HeightProperty, height);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void OuterShadowBrush::SetCornerRadius(float r)
{
    SetValue<float>(CornerRadiusProperty, r);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void OuterShadowBrush::SetBlurRadius(float r)
{
    SetValue<float>(BlurRadiusProperty, r);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_IMPLEMENT_REFLECTION(OuterShadowBrush)
{
    using namespace Noesis;

#if WITH_EDITORONLY_DATA
    NsMeta<AssetDependency>("/NoesisGUI;component/Internal/OuterShadowBrush");
#endif

    auto OnColorChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        OuterShadowBrush* this_ = DynamicCast<OuterShadowBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetVectorParameterValue(FName("Color"), args.NewValue<Color>());
        }
    };

    auto OnWidthChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        OuterShadowBrush* this_ = DynamicCast<OuterShadowBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("Width"), args.NewValue<float>());
        }
    };

    auto OnHeightChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        OuterShadowBrush* this_ = DynamicCast<OuterShadowBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("Height"), args.NewValue<float>());
        }
    };

    auto OnCornerRadiusChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        OuterShadowBrush* this_ = DynamicCast<OuterShadowBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("CornerRadius"), args.NewValue<float>());
        }
    };

    auto OnBlurRadiusChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        OuterShadowBrush* this_ = DynamicCast<OuterShadowBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("BlurRadius"), args.NewValue<float>());
        }
    };

    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<Color>(ColorProperty, "Color",
        UIPropertyMetadata::Create(Color::White(), PropertyChangedCallback(OnColorChanged)));
    data->RegisterProperty<float>(WidthProperty, "Width",
        UIPropertyMetadata::Create(1.0f, PropertyChangedCallback(OnWidthChanged)));
    data->RegisterProperty<float>(HeightProperty, "Height",
        UIPropertyMetadata::Create(1.0f, PropertyChangedCallback(OnHeightChanged)));
    data->RegisterProperty<float>(CornerRadiusProperty, "CornerRadius",
        UIPropertyMetadata::Create(0.0f, PropertyChangedCallback(OnCornerRadiusChanged)));
    data->RegisterProperty<float>(BlurRadiusProperty, "BlurRadius",
        UIPropertyMetadata::Create(0.0f, PropertyChangedCallback(OnBlurRadiusChanged)));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* OuterShadowBrush::ColorProperty;
const Noesis::DependencyProperty* OuterShadowBrush::WidthProperty;
const Noesis::DependencyProperty* OuterShadowBrush::HeightProperty;
const Noesis::DependencyProperty* OuterShadowBrush::CornerRadiusProperty;
const Noesis::DependencyProperty* OuterShadowBrush::BlurRadiusProperty;
