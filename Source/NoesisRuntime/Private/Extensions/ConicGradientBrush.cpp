////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Extensions/ConicGradientBrush.h"
#include "NoesisAssetDependency.h"

#include <NsGui/UIElementData.h>
#include <NsGui/UIPropertyMetadata.h>
#include <NsCore/ReflectionImplement.h>

#ifdef NS_HAVE_STUDIO
#include <NsGui/StudioMeta.h>
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////
ConicGradientBrush::ConicGradientBrush():
    MaterialBrushShader(TEXT("/NoesisGUI/Internal/ConicGradientBrush.ConicGradientBrush"))
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
Noesis::GradientStopCollection* ConicGradientBrush::GetGradientStops() const
{
    return GetValue<Noesis::Ptr<Noesis::GradientStopCollection>>(GradientStopsProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void ConicGradientBrush::SetGradientStops(Noesis::GradientStopCollection* stops)
{
    SetValue<Noesis::Ptr<Noesis::GradientStopCollection>>(GradientStopsProperty, stops);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::Point& ConicGradientBrush::GetCenter() const
{
    return GetValue<Noesis::Point>(CenterProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void ConicGradientBrush::SetCenter(const Noesis::Point& value)
{
    SetValue<Noesis::Point>(CenterProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void ConicGradientBrush::UpdateStops(Noesis::Freezable*, Noesis::FreezableEventReason)
{
    UpdateGradients(GetGradientStops());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void ConicGradientBrush::UpdateGradients(Noesis::GradientStopCollection* collection)
{
    using namespace Noesis;

    uint32_t numStops = collection ? (uint32_t)collection->Count() : 0u;
    if (numStops > 0)
    {
        // Create extra stops at 0.0 and 1.0 if missing
        bool needsFirst = collection->Get(0)->GetOffset() != 0.0f;
        bool needsLast = collection->Get(numStops - 1)->GetOffset() != 1.0f;

        const char* ParamOffset[] =
        {
            "Offset0", "Offset1", "Offset2", "Offset3", "Offset4", "Offset5", "Offset6", "Offset7"
        };
        const char* ParamColor[] =
        {
            "Color0", "Color1", "Color2", "Color3", "Color4", "Color5", "Color6", "Color7"
        };
        uint32_t availableStops = NS_COUNTOF(ParamOffset);

        uint32_t base = needsFirst ? 1 : 0;
        uint32_t n = Noesis::Min(numStops + base + (needsLast ? 1 : 0), availableStops);

        if (needsFirst)
        {
            GradientStop* stop = collection->Get(0);

            SetScalarParameterValue(FName(ParamOffset[0]), 0.0f);
            SetVectorParameterValue(FName(ParamColor[0]), stop->GetColor());
        }

        for (uint32_t i = 0; i < numStops; i++)
        {
            // break in case there are more stops than available inputs in the shader
            if (base + i == availableStops) break;

            GradientStop* stop = collection->Get(i);

            SetScalarParameterValue(FName(ParamOffset[base + i]), stop->GetOffset());
            SetVectorParameterValue(FName(ParamColor[base + i]), stop->GetColor());
        }

        if (needsLast)
        {
            GradientStop* stop = collection->Get(numStops - 1);

            SetScalarParameterValue(FName(ParamOffset[n - 1]), 1.0f);
            SetVectorParameterValue(FName(ParamColor[n - 1]), stop->GetColor());
        }

        numStops = n;
    }
    else
    {
        SetScalarParameterValue(FName("Offset0"), 0.0f);
        SetVectorParameterValue(FName("Color0"), Color(0.0f, 0.0f, 0.0f, 0.0f));

        numStops = 1;
    }

    SetScalarParameterValue(FName("NumStops"), (float)numStops);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(ConicGradientBrush, "NoesisGUIExtensions.ConicGradientBrush")
{
    using namespace Noesis;

#if WITH_EDITORONLY_DATA
    NsMeta<AssetDependency>("/NoesisGUI;component/Internal/ConicGradientBrush");
#endif

  #ifdef NS_HAVE_STUDIO
    NsProp("Center", &ConicGradientBrush::GetCenter, &ConicGradientBrush::SetCenter)
        .Meta<StudioOrder>(0);
    NsProp("GradientStops", &ConicGradientBrush::GetGradientStops, &ConicGradientBrush::SetGradientStops)
        .Meta<StudioOrder>(1);

    NsMeta<StudioInit>([](BaseComponent* instance)
    {
        ConicGradientBrush* brush = DynamicCast<ConicGradientBrush*>(instance);
        if (brush != nullptr)
        {
            Ptr<GradientStopCollection> stops = MakePtr<GradientStopCollection>();
            stops->Add(MakePtr<GradientStop>(Color::White(), 0.0f));
            stops->Add(MakePtr<GradientStop>(Color::Black(), 1.0f));
            brush->SetGradientStops(stops);
        }
    });
  #endif

    auto OnGradientStopsChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        ConicGradientBrush* this_ = DynamicCast<ConicGradientBrush*>(o);
        if (this_ != nullptr)
        {
            GradientStopCollection* oldCollection = args.OldValue<Ptr<GradientStopCollection>>();
            GradientStopCollection* collection = args.NewValue<Ptr<GradientStopCollection>>();

            if (oldCollection)
            {
                oldCollection->Changed() -= MakeDelegate(this_, &ConicGradientBrush::UpdateStops);
            }

            if (collection)
            {
                collection->Changed() += MakeDelegate(this_, &ConicGradientBrush::UpdateStops);
            }

            this_->UpdateGradients(collection);
        }
    };

    auto OnCenterChanged = [](DependencyObject* o, const DependencyPropertyChangedEventArgs& args)
    {
        ConicGradientBrush* this_ = DynamicCast<ConicGradientBrush*>(o);
        if (this_ != nullptr)
        {
            const Point& p = args.NewValue<Point>();
            this_->SetScalarParameterValue(FName("CenterX"), p.x);
            this_->SetScalarParameterValue(FName("CenterY"), p.y);
        }
    };

    NsMeta<ContentPropertyMetaData>("GradientStops");

    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<Ptr<GradientStopCollection>>(GradientStopsProperty, "GradientStops",
        UIPropertyMetadata::Create(Ptr<GradientStopCollection>(),
        PropertyChangedCallback(OnGradientStopsChanged)));
    data->RegisterProperty<Point>(CenterProperty, "Center", UIPropertyMetadata::Create(
        Point(0.5f, 0.5f), PropertyChangedCallback(OnCenterChanged)));
}

NS_END_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* ConicGradientBrush::GradientStopsProperty;
const Noesis::DependencyProperty* ConicGradientBrush::CenterProperty;
