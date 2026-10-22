  ////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "InnerShadowBrush.h"
#include "NoesisAssetDependency.h"

#include <NsGui/UIElementData.h>
#include <NsGui/UIPropertyMetadata.h>
#include <NsCore/ReflectionImplement.h>


////////////////////////////////////////////////////////////////////////////////////////////////////
InnerShadowBrush::InnerShadowBrush():
    MaterialBrushShader(TEXT("/NoesisGUI/Internal/InnerShadowBrush.InnerShadowBrush"))
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InnerShadowBrush::SetColor(const Noesis::Color& color)
{
    SetValue<Noesis::Color>(ColorProperty, color);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InnerShadowBrush::SetWidth(float width)
{
    SetValue<float>(WidthProperty, width);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InnerShadowBrush::SetHeight(float height)
{
    SetValue<float>(HeightProperty, height);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InnerShadowBrush::SetCornerRadius(float r)
{
    SetValue<float>(CornerRadiusProperty, r);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InnerShadowBrush::SetBlurRadius(float r)
{
    SetValue<float>(BlurRadiusProperty, r);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InnerShadowBrush::SetSpread(float spread)
{
    SetValue<float>(SpreadProperty, spread);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InnerShadowBrush::SetOffsetX(float offset)
{
    SetValue<float>(OffsetXProperty, offset);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InnerShadowBrush::SetOffsetY(float offset)
{
    SetValue<float>(OffsetYProperty, offset);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(InnerShadowBrush)
{
    using namespace Noesis;

#if WITH_EDITORONLY_DATA
    NsMeta<AssetDependency>("/NoesisGUI;component/Internal/InnerShadowBrush");
#endif

    auto OnColorChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        InnerShadowBrush* this_ = DynamicCast<InnerShadowBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetVectorParameterValue(FName("Color"), args.NewValue<Color>());
        }
    };

    auto OnWidthChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        InnerShadowBrush* this_ = DynamicCast<InnerShadowBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("Width"), args.NewValue<float>());
        }
    };

    auto OnHeightChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        InnerShadowBrush* this_ = DynamicCast<InnerShadowBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("Height"), args.NewValue<float>());
        }
    };

    auto OnCornerRadiusChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        InnerShadowBrush* this_ = DynamicCast<InnerShadowBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("CornerRadius"), args.NewValue<float>());
        }
    };

    auto OnBlurRadiusChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        InnerShadowBrush* this_ = DynamicCast<InnerShadowBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("BlurRadius"), args.NewValue<float>());
        }
    };

    auto OnSpreadChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        InnerShadowBrush* this_ = DynamicCast<InnerShadowBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("Spread"), args.NewValue<float>());
        }
    };

    auto OnOffsetXChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        InnerShadowBrush* this_ = DynamicCast<InnerShadowBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("OffsetX"), args.NewValue<float>());
        }
    };

    auto OnOffsetYChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        InnerShadowBrush* this_ = DynamicCast<InnerShadowBrush*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("OffsetY"), args.NewValue<float>());
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
    data->RegisterProperty<float>(SpreadProperty, "Spread",
        UIPropertyMetadata::Create(0.0f, PropertyChangedCallback(OnSpreadChanged)));
    data->RegisterProperty<float>(OffsetXProperty, "OffsetX",
        UIPropertyMetadata::Create(0.0f, PropertyChangedCallback(OnOffsetXChanged)));
    data->RegisterProperty<float>(OffsetYProperty, "OffsetY",
        UIPropertyMetadata::Create(0.0f, PropertyChangedCallback(OnOffsetYChanged)));
}

NS_END_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* InnerShadowBrush::ColorProperty;
const Noesis::DependencyProperty* InnerShadowBrush::WidthProperty;
const Noesis::DependencyProperty* InnerShadowBrush::HeightProperty;
const Noesis::DependencyProperty* InnerShadowBrush::CornerRadiusProperty;
const Noesis::DependencyProperty* InnerShadowBrush::BlurRadiusProperty;
const Noesis::DependencyProperty* InnerShadowBrush::SpreadProperty;
const Noesis::DependencyProperty* InnerShadowBrush::OffsetXProperty;
const Noesis::DependencyProperty* InnerShadowBrush::OffsetYProperty;
