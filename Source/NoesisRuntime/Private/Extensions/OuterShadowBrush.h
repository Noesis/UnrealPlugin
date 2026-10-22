////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Noesis includes
#include "NoesisSDK.h"

#include "Extensions/MaterialBrushShader.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
class OuterShadowBrush final: public MaterialBrushShader
{
public:
    OuterShadowBrush();

    void SetColor(const Noesis::Color& color);
    void SetWidth(float width);
    void SetHeight(float height);
    void SetCornerRadius(float r);
    void SetBlurRadius(float r);

public:
    static const Noesis::DependencyProperty* ColorProperty;
    static const Noesis::DependencyProperty* WidthProperty;
    static const Noesis::DependencyProperty* HeightProperty;
    static const Noesis::DependencyProperty* CornerRadiusProperty;
    static const Noesis::DependencyProperty* BlurRadiusProperty;

    NS_DECLARE_REFLECTION(OuterShadowBrush, MaterialBrushShader)
};
