////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Extensions/PixelateEffect.h"
#include "NoesisAssetDependency.h"

#include <NsGui/UIElementData.h>
#include <NsGui/UIPropertyMetadata.h>
#include <NsCore/ReflectionImplement.h>

#ifdef NS_HAVE_STUDIO
#include <NsGui/StudioMeta.h>
#endif


static constexpr float DefaultSize = 10.0f;


////////////////////////////////////////////////////////////////////////////////////////////////////
PixelateEffect::PixelateEffect():
    MaterialShaderEffect(TEXT("/NoesisGUI/Internal/PixelateEffect.PixelateEffect"))
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float PixelateEffect::GetSize() const
{
    return GetValue<float>(SizeProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void PixelateEffect::SetSize(float value)
{
    SetValue<float>(SizeProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(PixelateEffect, "NoesisGUIExtensions.PixelateEffect")
{
    using namespace Noesis;

#if WITH_EDITORONLY_DATA
    NsMeta<AssetDependency>("/NoesisGUI;component/Internal/PixelateEffect");
#endif

  #ifdef NS_HAVE_STUDIO
    NsProp("Size", &PixelateEffect::GetSize, &PixelateEffect::SetSize)
        .Meta<StudioMin>(0.0f);
  #endif

    auto OnSizeChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        PixelateEffect* this_ = DynamicCast<PixelateEffect*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("Size"), args.NewValue<float>());
        }
    };

    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<float>(SizeProperty, "Size", UIPropertyMetadata::Create(
        DefaultSize, PropertyChangedCallback(OnSizeChanged)));
}

NS_END_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* PixelateEffect::SizeProperty;
