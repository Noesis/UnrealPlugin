  ////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "Extensions/MaterialShaderEffect.h"
#include "Render/NoesisRenderDevice.h"
#include "NoesisTypeClass.h"
#include "NoesisSupport.h"

#include <NsGui/BitmapImage.h>
#include <NsCore/ReflectionImplementEmpty.h>

#include "Materials/MaterialInstanceDynamic.h"
#include "UObject/Package.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
MaterialShaderEffect::MaterialShaderEffect(const TCHAR* ShaderName): mNativeMaterial(0)
{
    UMaterialInterface* MaterialAsset = LoadObject<UMaterialInterface>(nullptr, ShaderName,
        nullptr, LOAD_NoWarn);

    if (MaterialAsset != nullptr)
    {
        mMaterial = UMaterialInstanceDynamic::Create(MaterialAsset, GetTransientPackage());
        mMaterial->AddToRoot(); // Prevent garbage collection

        mNativeMaterial = FNoesisRenderDevice::CreateMaterial(mMaterial.Get());

        SetPixelShader(mNativeMaterial);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
MaterialShaderEffect::~MaterialShaderEffect()
{
    if (mMaterial.IsValid())
    {
        mMaterial->RemoveFromRoot();
    }

    if (mNativeMaterial)
    {
        FNoesisRenderDevice::DestroyMaterial(mNativeMaterial);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void MaterialShaderEffect::SetScalarParameterValue(FName ParamName, float Value)
{
    if (mMaterial.IsValid())
    {
        mMaterial->SetScalarParameterValue(ParamName, Value);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void MaterialShaderEffect::SetVectorParameterValue(FName ParamName, const Noesis::Color& Value)
{
    if (mMaterial.IsValid())
    {
        FLinearColor LinearColor(Value.r, Value.g, Value.b, Value.a);
        mMaterial->SetVectorParameterValue(ParamName, LinearColor);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void MaterialShaderEffect::SetTextureParameterValue(FName ParamName, Noesis::ImageSource* Value)
{
    if (mMaterial.IsValid())
    {
        UTexture* Texture = NoesisUTextureForComponent(Value);
        if (Texture != nullptr)
        {
            mMaterial->SetTextureParameterValue(ParamName, Texture);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool MaterialShaderEffect::OnSubPropertyChanged(const Noesis::DependencyProperty* Dp)
{
    if (Dp->GetType() == Noesis::TypeOf<Noesis::BitmapSource>())
    {
        SetTextureParameterValue(NsStringToFName(Dp->GetName().Str()),
            GetValue<Noesis::Ptr<Noesis::BitmapSource>>(Dp));
    }

    return ParentClass::OnSubPropertyChanged(Dp);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION_(MaterialShaderEffect)

NS_END_COLD_REGION
