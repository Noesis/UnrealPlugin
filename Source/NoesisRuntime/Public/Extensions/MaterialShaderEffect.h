////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once

// Noesis includes
#include "NoesisSDK.h"

#include "UObject/WeakObjectPtr.h"


class UMaterialInstanceDynamic;

////////////////////////////////////////////////////////////////////////////////////////////////////
class NOESISRUNTIME_API MaterialShaderEffect: public Noesis::ShaderEffect
{
public:
    MaterialShaderEffect(const TCHAR* ShaderName);
    ~MaterialShaderEffect();

protected:
    void SetScalarParameterValue(FName ParamName, float Value);
    void SetVectorParameterValue(FName ParamName, const Noesis::Color& Value);
    void SetTextureParameterValue(FName ParamName, Noesis::ImageSource* Value);

    bool OnSubPropertyChanged(const Noesis::DependencyProperty* Dp) override;

private:
    TWeakObjectPtr<UMaterialInstanceDynamic> mMaterial;
    void* mNativeMaterial;

    NS_DECLARE_REFLECTION(MaterialShaderEffect, Noesis::ShaderEffect)
};
