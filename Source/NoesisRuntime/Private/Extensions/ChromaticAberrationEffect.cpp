////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Extensions/ChromaticAberrationEffect.h"
#include "NoesisAssetDependency.h"

#include <NsGui/UIElementData.h>
#include <NsGui/UIPropertyMetadata.h>
#include <NsCore/ReflectionImplement.h>

#ifdef NS_HAVE_STUDIO
#include <NsGui/StudioMeta.h>
#endif


static constexpr float DefaultAmountX = 10.0f;
static constexpr float DefaultAmountY = 0.0f;


////////////////////////////////////////////////////////////////////////////////////////////////////
ChromaticAberrationEffect::ChromaticAberrationEffect():
    MaterialShaderEffect(TEXT("/NoesisGUI/Internal/ChromaticAberrationEffect.ChromaticAberrationEffect"))
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float ChromaticAberrationEffect::GetAmountX() const
{
    return GetValue<float>(AmountXProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void ChromaticAberrationEffect::SetAmountX(float value)
{
    SetValue<float>(AmountXProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float ChromaticAberrationEffect::GetAmountY() const
{
    return GetValue<float>(AmountYProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void ChromaticAberrationEffect::SetAmountY(float value)
{
    SetValue<float>(AmountYProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(ChromaticAberrationEffect, "NoesisGUIExtensions.ChromaticAberrationEffect")
{
    using namespace Noesis;

#if WITH_EDITORONLY_DATA
    NsMeta<AssetDependency>("/NoesisGUI;component/Internal/ChromaticAberrationEffect");
#endif

#ifdef NS_HAVE_STUDIO
    NsProp("AmountX", &ChromaticAberrationEffect::GetAmountX, &ChromaticAberrationEffect::SetAmountX)
        .Meta<StudioOrder>(0)
        .Meta<StudioMin>(0.0f);
    NsProp("AmountY", &ChromaticAberrationEffect::GetAmountY, &ChromaticAberrationEffect::SetAmountY)
        .Meta<StudioOrder>(1)
        .Meta<StudioMin>(0.0f);
  #endif

    auto OnAmountXChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        ChromaticAberrationEffect* this_ = DynamicCast<ChromaticAberrationEffect*>(o);
        if (this_ != nullptr)
        {
            float amountX = args.NewValue<float>();
            this_->SetScalarParameterValue(FName("AmountX"), amountX);
            this_->SetPaddingHorizontal(fabsf(0.5f * amountX));
        }
    };

    auto OnAmountYChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        ChromaticAberrationEffect* this_ = DynamicCast<ChromaticAberrationEffect*>(o);
        if (this_ != nullptr)
        {
            float amountY = args.NewValue<float>();
            this_->SetScalarParameterValue(FName("AmountY"), amountY);
            this_->SetPaddingVertical(fabsf(0.5f * amountY));
        }
    };

    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<float>(AmountXProperty, "AmountX", UIPropertyMetadata::Create(
        DefaultAmountX, PropertyChangedCallback(OnAmountXChanged)));
    data->RegisterProperty<float>(AmountYProperty, "AmountY", UIPropertyMetadata::Create(
        DefaultAmountY, PropertyChangedCallback(OnAmountYChanged)));
}

NS_END_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* ChromaticAberrationEffect::AmountXProperty;
const Noesis::DependencyProperty* ChromaticAberrationEffect::AmountYProperty;
