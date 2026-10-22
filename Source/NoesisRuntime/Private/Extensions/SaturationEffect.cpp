////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Extensions/SaturationEffect.h"
#include "NoesisAssetDependency.h"

#include <NsGui/UIElementData.h>
#include <NsGui/UIPropertyMetadata.h>
#include <NsCore/ReflectionImplement.h>

#ifdef NS_HAVE_STUDIO
#include <NsGui/StudioMeta.h>
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////
SaturationEffect::SaturationEffect():
    MaterialShaderEffect(TEXT("/NoesisGUI/Internal/SaturationEffect.SaturationEffect"))
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float SaturationEffect::GetSaturation() const
{
    return GetValue<float>(SaturationProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void SaturationEffect::SetSaturation(float value)
{
    SetValue<float>(SaturationProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(SaturationEffect, "NoesisGUIExtensions.SaturationEffect")
{
    using namespace Noesis;

#if WITH_EDITORONLY_DATA
    NsMeta<AssetDependency>("/NoesisGUI;component/Internal/SaturationEffect");
#endif

  #ifdef NS_HAVE_STUDIO
    NsProp("Saturation", &SaturationEffect::GetSaturation, &SaturationEffect::SetSaturation)
        .Meta<StudioEditor>("NumericProperty.Percentage");
  #endif

    auto OnSaturationChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        SaturationEffect* this_ = DynamicCast<SaturationEffect*>(o);
        if (this_ != nullptr)
        {
            this_->SetScalarParameterValue(FName("Saturation"), args.NewValue<float>());
        }
    };

    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<float>(SaturationProperty, "Saturation", UIPropertyMetadata::Create(
        DefaultSaturation, PropertyChangedCallback(OnSaturationChanged)));
}

NS_END_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* SaturationEffect::SaturationProperty;
