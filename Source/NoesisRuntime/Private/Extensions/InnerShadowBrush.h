////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Noesis includes
#include "NoesisSDK.h"

#include "Extensions/MaterialBrushShader.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
class InnerShadowBrush final: public MaterialBrushShader
{
public:
    InnerShadowBrush();

    void SetColor(const Noesis::Color& color);
    void SetWidth(float width);
    void SetHeight(float height);
    void SetCornerRadius(float r);
    void SetBlurRadius(float r);
    void SetSpread(float spread);
    void SetOffsetX(float offset);
    void SetOffsetY(float offset);

public:
    static const Noesis::DependencyProperty* ColorProperty;
    static const Noesis::DependencyProperty* WidthProperty;
    static const Noesis::DependencyProperty* HeightProperty;
    static const Noesis::DependencyProperty* CornerRadiusProperty;
    static const Noesis::DependencyProperty* BlurRadiusProperty;
    static const Noesis::DependencyProperty* SpreadProperty;
    static const Noesis::DependencyProperty* OffsetXProperty;
    static const Noesis::DependencyProperty* OffsetYProperty;

    NS_DECLARE_REFLECTION(InnerShadowBrush, MaterialBrushShader)
};
