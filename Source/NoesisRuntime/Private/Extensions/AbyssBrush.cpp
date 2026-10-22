////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Extensions/AbyssBrush.h"
#include "NoesisAssetDependency.h"

#include <NsGui/UIElementData.h>
#include <NsGui/UIPropertyMetadata.h>
#include <NsCore/ReflectionImplement.h>

#ifdef NS_HAVE_STUDIO
#include <NsGui/StudioMeta.h>
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////
AbyssBrush::AbyssBrush():
    MaterialBrushShader(TEXT("/NoesisGUI/Internal/AbyssBrush.AbyssBrush"))
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float AbyssBrush::GetSpeed() const
{
    return GetValue<float>(SpeedProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void AbyssBrush::SetSpeed(float value)
{
    SetValue<float>(SpeedProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(AbyssBrush, "NoesisGUIExtensions.AbyssBrush")
{
    using namespace Noesis;

  #if WITH_EDITORONLY_DATA
    NsMeta<AssetDependency>("/NoesisGUI;component/Internal/AbyssBrush");
  #endif

  #ifdef NS_HAVE_STUDIO
    NsProp("Speed", &AbyssBrush::GetSpeed, &AbyssBrush::SetSpeed)
        .Meta<StudioOrder>(0)
        .Meta<StudioMin>(0);
  #endif

    auto OnSpeedChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        AbyssBrush* this_ = DynamicCast<AbyssBrush*>(o);
        if (this_)
        {
            this_->SetScalarParameterValue(FName("Speed"), args.NewValue<float>());
        }
    };

    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<float>(SpeedProperty, "Speed", UIPropertyMetadata::Create(
        DefaultSpeed, PropertyChangedCallback(OnSpeedChanged)));
}

NS_END_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* AbyssBrush::SpeedProperty;
