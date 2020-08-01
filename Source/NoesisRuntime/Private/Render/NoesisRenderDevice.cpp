////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisRenderDevice.h"

// Engine includes
#include "Engine/Texture2D.h"
#include "Engine/TextureRenderTarget2D.h"

// RHI includes
#include "RHICommandList.h"
#include "RHIStaticStates.h"
#include "PipelineStateCache.h"

// NoesisRuntime includes
#include "Render/NoesisShaders.h"
#include "NoesisSettings.h"

class FNoesisTexture : public Noesis::Texture
{
public:

	// Texture interface
	virtual uint32 GetWidth() const override
	{
		return (uint32)ShaderResourceTexture->GetSizeX();
	}

	virtual uint32 GetHeight() const override
	{
		return (uint32)ShaderResourceTexture->GetSizeY();
	}

	virtual bool HasMipMaps() const override
	{
		return (bool)(ShaderResourceTexture->GetNumMips() > 1);
	}

	virtual bool IsInverted() const override
	{
		return (bool)false;
	}
	// End of Texture interface

	FTexture2DRHIRef ShaderResourceTexture;
	Noesis::TextureFormat::Enum Format;
};

class FNoesisRenderTarget : public Noesis::RenderTarget
{
public:

	// RenderTarget interface
	virtual Noesis::Texture* GetTexture() override
	{
		return Texture.GetPtr();
	}
	// End of RenderTarget interface

	Noesis::Ptr<FNoesisTexture> Texture;
	FTexture2DRHIRef ColorTarget;
	FTexture2DRHIRef DepthStencilTarget;
};

uint32 FNoesisRenderDevice::RHICmdListTlsSlot;

FNoesisRenderDevice::FNoesisRenderDevice()
	: VertexBufferOffset(0), IndexBufferOffset(0), CurrentRenderTarget(0)
{
	FRHIResourceCreateInfo CreateInfo;
	DynamicVertexBuffer = RHICreateVertexBuffer(VertexBufferSize, BUF_Dynamic, CreateInfo);
	DynamicIndexBuffer = RHICreateIndexBuffer(sizeof(int16), IndexBufferSize, BUF_Dynamic, CreateInfo);

	const auto FeatureLevel = GMaxRHIFeatureLevel;

	FMemory::Memzero(VertexDeclarations);

	VertexDeclarations[Noesis::Shader::RGBA] = GNoesisPosVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::RGBA] = TShaderMapRef<FNoesisPosVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::RGBA] = TShaderMapRef<FNoesisRgbaPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Mask] = GNoesisPosVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Mask] = TShaderMapRef<FNoesisPosVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Mask] = TShaderMapRef<FNoesisMaskPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Path_Solid] = GNoesisPosColorVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_Solid] = TShaderMapRef<FNoesisPosColorVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Solid] = TShaderMapRef<FNoesisPathSolidPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Path_Linear] = GNoesisPosTex0VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_Linear] = TShaderMapRef<FNoesisPosTex0VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Linear] = TShaderMapRef<FNoesisPathLinearPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Path_Radial] = GNoesisPosTex0VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_Radial] = TShaderMapRef<FNoesisPosTex0VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Radial] = TShaderMapRef<FNoesisPathRadialPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Path_Pattern] = GNoesisPosTex0VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_Pattern] = TShaderMapRef<FNoesisPosTex0VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Pattern] = TShaderMapRef<FNoesisPathPatternPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::PathAA_Solid] = GNoesisPosColorCoverageVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::PathAA_Solid] = TShaderMapRef<FNoesisPosColorCoverageVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::PathAA_Solid] = TShaderMapRef<FNoesisPathAaSolidPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::PathAA_Linear] = GNoesisPosTex0CoverageVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::PathAA_Linear] = TShaderMapRef<FNoesisPosTex0CoverageVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::PathAA_Linear] = TShaderMapRef<FNoesisPathAaLinearPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::PathAA_Radial] = GNoesisPosTex0CoverageVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::PathAA_Radial] = TShaderMapRef<FNoesisPosTex0CoverageVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::PathAA_Radial] = TShaderMapRef<FNoesisPathAaRadialPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::PathAA_Pattern] = GNoesisPosTex0CoverageVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::PathAA_Pattern] = TShaderMapRef<FNoesisPosTex0CoverageVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::PathAA_Pattern] = TShaderMapRef<FNoesisPathAaPatternPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::SDF_Solid] = GNoesisPosColorTex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_Solid] = TShaderMapRef<FNoesisPosColorTex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Solid] = TShaderMapRef<FNoesisSDFSolidPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::SDF_Linear] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_Linear] = TShaderMapRef<FNoesisPosTex0Tex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Linear] = TShaderMapRef<FNoesisSDFLinearPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::SDF_Radial] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_Radial] = TShaderMapRef<FNoesisPosTex0Tex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Radial] = TShaderMapRef<FNoesisSDFRadialPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::SDF_Pattern] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_Pattern] = TShaderMapRef<FNoesisPosTex0Tex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Pattern] = TShaderMapRef<FNoesisSDFPatternPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::SDF_LCD_Solid] = GNoesisPosColorTex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_LCD_Solid] = TShaderMapRef<FNoesisPosColorTex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Solid] = TShaderMapRef<FNoesisSDFLCDSolidPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::SDF_LCD_Linear] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_LCD_Linear] = TShaderMapRef<FNoesisPosTex0Tex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Linear] = TShaderMapRef<FNoesisSDFLCDLinearPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::SDF_LCD_Radial] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_LCD_Radial] = TShaderMapRef<FNoesisPosTex0Tex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Radial] = TShaderMapRef<FNoesisSDFLCDRadialPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::SDF_LCD_Pattern] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_LCD_Pattern] = TShaderMapRef<FNoesisPosTex0Tex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Pattern] = TShaderMapRef<FNoesisSDFLCDPatternPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Opacity_Solid] = GNoesisPosColorTex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Opacity_Solid] = TShaderMapRef<FNoesisPosColorTex1VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Opacity_Solid] = TShaderMapRef<FNoesisImageOpacitySolidPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Opacity_Linear] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Opacity_Linear] = TShaderMapRef<FNoesisPosTex0Tex1VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Opacity_Linear] = TShaderMapRef<FNoesisImageOpacityLinearPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Opacity_Radial] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Opacity_Radial] = TShaderMapRef<FNoesisPosTex0Tex1VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Opacity_Radial] = TShaderMapRef<FNoesisImageOpacityRadialPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Opacity_Pattern] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Opacity_Pattern] = TShaderMapRef<FNoesisPosTex0Tex1VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Opacity_Pattern] = TShaderMapRef<FNoesisImageOpacityPatternPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Shadow35V] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Shadow35V] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Shadow35V] = TShaderMapRef<FNoesisImageShadow35VPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Shadow63V] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Shadow63V] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Shadow63V] = TShaderMapRef<FNoesisImageShadow63VPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Shadow127V] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Shadow127V] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Shadow127V] = TShaderMapRef<FNoesisImageShadow127VPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Shadow35H_Solid] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Shadow35H_Solid] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Shadow35H_Solid] = TShaderMapRef<FNoesisImageShadow35HSolidPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Shadow35H_Linear] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Shadow35H_Linear] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Shadow35H_Linear] = TShaderMapRef<FNoesisImageShadow35HLinearPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Shadow35H_Radial] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Shadow35H_Radial] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Shadow35H_Radial] = TShaderMapRef<FNoesisImageShadow35HRadialPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Shadow35H_Pattern] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Shadow35H_Pattern] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Shadow35H_Pattern] = TShaderMapRef<FNoesisImageShadow35HPatternPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Shadow63H_Solid] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Shadow63H_Solid] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Shadow63H_Solid] = TShaderMapRef<FNoesisImageShadow63HSolidPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Shadow63H_Linear] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Shadow63H_Linear] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Shadow63H_Linear] = TShaderMapRef<FNoesisImageShadow63HLinearPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Shadow63H_Radial] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Shadow63H_Radial] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Shadow63H_Radial] = TShaderMapRef<FNoesisImageShadow63HRadialPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Shadow63H_Pattern] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Shadow63H_Pattern] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Shadow63H_Pattern] = TShaderMapRef<FNoesisImageShadow63HPatternPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Shadow127H_Solid] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Shadow127H_Solid] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Shadow127H_Solid] = TShaderMapRef<FNoesisImageShadow127HSolidPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Shadow127H_Linear] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Shadow127H_Linear] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Shadow127H_Linear] = TShaderMapRef<FNoesisImageShadow127HLinearPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Shadow127H_Radial] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Shadow127H_Radial] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Shadow127H_Radial] = TShaderMapRef<FNoesisImageShadow127HRadialPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Shadow127H_Pattern] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Shadow127H_Pattern] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Shadow127H_Pattern] = TShaderMapRef<FNoesisImageShadow127HPatternPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Blur35V] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Blur35V] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Blur35V] = TShaderMapRef<FNoesisImageBlur35VPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Blur63V] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Blur63V] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Blur63V] = TShaderMapRef<FNoesisImageBlur63VPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Blur127V] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Blur127V] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Blur127V] = TShaderMapRef<FNoesisImageBlur127VPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Blur35H_Solid] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Blur35H_Solid] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Blur35H_Solid] = TShaderMapRef<FNoesisImageBlur35HSolidPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Blur35H_Linear] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Blur35H_Linear] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Blur35H_Linear] = TShaderMapRef<FNoesisImageBlur35HLinearPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Blur35H_Radial] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Blur35H_Radial] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Blur35H_Radial] = TShaderMapRef<FNoesisImageBlur35HRadialPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Blur35H_Pattern] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Blur35H_Pattern] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Blur35H_Pattern] = TShaderMapRef<FNoesisImageBlur35HPatternPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Blur63H_Solid] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Blur63H_Solid] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Blur63H_Solid] = TShaderMapRef<FNoesisImageBlur63HSolidPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Blur63H_Linear] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Blur63H_Linear] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Blur63H_Linear] = TShaderMapRef<FNoesisImageBlur63HLinearPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Blur63H_Radial] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Blur63H_Radial] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Blur63H_Radial] = TShaderMapRef<FNoesisImageBlur63HRadialPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Blur63H_Pattern] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Blur63H_Pattern] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Blur63H_Pattern] = TShaderMapRef<FNoesisImageBlur63HPatternPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Blur127H_Solid] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Blur127H_Solid] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Blur127H_Solid] = TShaderMapRef<FNoesisImageBlur127HSolidPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Blur127H_Linear] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Blur127H_Linear] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Blur127H_Linear] = TShaderMapRef<FNoesisImageBlur127HLinearPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Blur127H_Radial] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Blur127H_Radial] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Blur127H_Radial] = TShaderMapRef<FNoesisImageBlur127HRadialPS>(GetGlobalShaderMap(FeatureLevel));

	VertexDeclarations[Noesis::Shader::Image_Blur127H_Pattern] = GNoesisPosColorTex1Tex2VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Image_Blur127H_Pattern] = TShaderMapRef<FNoesisPosColorTex1Tex2VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Image_Blur127H_Pattern] = TShaderMapRef<FNoesisImageBlur127HPatternPS>(GetGlobalShaderMap(FeatureLevel));
}

FNoesisRenderDevice::~FNoesisRenderDevice()
{
}

uint32 GlyphCacheWidth[] = { 256, 512, 1024, 2048, 4096 };
uint32 GlyphCacheHeight[] = { 256, 512, 1024, 2048, 4096 };
static FNoesisRenderDevice* NoesisRenderDevice = 0;

FNoesisRenderDevice* FNoesisRenderDevice::Get()
{
	if (!NoesisRenderDevice)
	{
		NoesisRenderDevice = new FNoesisRenderDevice();
		NoesisRenderDevice->SetOffscreenWidth((uint32)FMath::Max(0, GetDefault<UNoesisSettings>()->OffscreenTextureWidth));
		NoesisRenderDevice->SetOffscreenHeight((uint32)FMath::Max(0, GetDefault<UNoesisSettings>()->OffscreenTextureHeight));
		NoesisRenderDevice->SetOffscreenSampleCount((uint32)GetDefault<UNoesisSettings>()->OffscreenTextureSampleCount);
		NoesisRenderDevice->SetOffscreenDefaultNumSurfaces((uint32)FMath::Max(0, GetDefault<UNoesisSettings>()->OffscreenInitSurfaces));
		NoesisRenderDevice->SetOffscreenMaxNumSurfaces((uint32)FMath::Max(0, GetDefault<UNoesisSettings>()->OffscreenMaxSurfaces));
		NoesisRenderDevice->SetGlyphCacheWidth(GlyphCacheWidth[(uint8)GetDefault<UNoesisSettings>()->GlyphTextureSize]);
		NoesisRenderDevice->SetGlyphCacheHeight(GlyphCacheHeight[(uint8)GetDefault<UNoesisSettings>()->GlyphTextureSize]);
		RHICmdListTlsSlot = FPlatformTLS::AllocTlsSlot();
	}
	return NoesisRenderDevice;
}

void FNoesisRenderDevice::Destroy()
{
	delete NoesisRenderDevice;
	NoesisRenderDevice = nullptr;
}

void FNoesisRenderDevice::ThreadLocal_SetRHICmdList(FRHICommandList* RHICmdList)
{
	FPlatformTLS::SetTlsValue(RHICmdListTlsSlot, RHICmdList);
}

FRHICommandList* FNoesisRenderDevice::ThreadLocal_GetRHICmdList()
{
	return (FRHICommandList*)FPlatformTLS::GetTlsValue(RHICmdListTlsSlot);
}

Noesis::Ptr<Noesis::Texture> FNoesisRenderDevice::CreateTexture(UTexture* InTexture)
{
	if (!InTexture || !InTexture->Resource)
		return nullptr;

	FNoesisTexture* Texture = nullptr;
	if (InTexture->IsA<UTexture2D>())
	{
		FTexture2DRHIRef TextureRef = ((FTexture2DResource*)InTexture->Resource)->GetTexture2DRHI();
		if (!TextureRef)
		{
			return nullptr;
		}
		Texture = new FNoesisTexture();
		Texture->ShaderResourceTexture = TextureRef;
	}
	else if (InTexture->IsA<UTextureRenderTarget2D>())
	{
		FTexture2DRHIRef TextureRef = ((FTextureRenderTarget2DResource*)InTexture->Resource)->GetTextureRHI();
		if (!TextureRef)
		{
			return nullptr;
		}
		Texture = new FNoesisTexture();
		Texture->ShaderResourceTexture = TextureRef;
	}
	else
	{
		return nullptr;
	}
	switch (Texture->ShaderResourceTexture->GetFormat())
	{
	case PF_R8G8B8A8:
		Texture->Format = Noesis::TextureFormat::RGBA8;
		break;
	case PF_G8:
		Texture->Format = Noesis::TextureFormat::R8;
		break;
	}

	return Noesis::Ptr<Noesis::Texture>(*Texture);
}

const Noesis::DeviceCaps& FNoesisRenderDevice::GetCaps() const
{
	static Noesis::DeviceCaps Caps = { 0.f, false, false };
	return Caps;
}

Noesis::Ptr<Noesis::RenderTarget> FNoesisRenderDevice::CreateRenderTarget(const char* Label, uint32 Width, uint32 Height, uint32 SampleCount)
{
	uint32 SizeX = (uint32)Width;
	uint32 SizeY = (uint32)Height;
	uint8 Format = (uint8)PF_R8G8B8A8;
	uint32 NumMips = 1;
	uint32 Flags = 0;
	uint32 TargetableTextureFlags = (uint32)TexCreate_RenderTargetable;
	bool bForceSeparateTargetAndShaderResource = true;
	FRHIResourceCreateInfo CreateInfo;
	FTexture2DRHIRef ColorTarget;
	FTexture2DRHIRef ShaderResourceTexture;
	uint32 NumSamples = (uint32)SampleCount;
	RHICreateTargetableShaderResource2D(SizeX, SizeY, Format, NumMips, Flags, TargetableTextureFlags, bForceSeparateTargetAndShaderResource, CreateInfo, ColorTarget, ShaderResourceTexture, NumSamples);

	Format = (uint8)PF_DepthStencil;
	TargetableTextureFlags = (uint32)TexCreate_DepthStencilTargetable;
	CreateInfo.ClearValueBinding = FClearValueBinding(0.f, 0);
	FTexture2DRHIRef DepthStencilTarget = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, NumSamples, TargetableTextureFlags, CreateInfo);

	FNoesisRenderTarget* RenderTarget = new FNoesisRenderTarget();
	RenderTarget->Texture = *new FNoesisTexture();
	RenderTarget->ColorTarget = ColorTarget;
	RenderTarget->Texture->ShaderResourceTexture = ShaderResourceTexture;
	RenderTarget->Texture->Format = Noesis::TextureFormat::RGBA8;
	RenderTarget->DepthStencilTarget = DepthStencilTarget;

	FName TextureName = FName(Label);
	ColorTarget->SetName(TextureName);
	ShaderResourceTexture->SetName(TextureName);
	DepthStencilTarget->SetName(TextureName);

	return Noesis::Ptr<Noesis::RenderTarget>(*RenderTarget);
}

Noesis::Ptr<Noesis::RenderTarget> FNoesisRenderDevice::CloneRenderTarget(const char* Label, Noesis::RenderTarget* InSharedRenderTarget)
{
	FNoesisRenderTarget* SharedRenderTarget = (FNoesisRenderTarget*)InSharedRenderTarget;
	FNoesisRenderTarget* RenderTarget = new FNoesisRenderTarget();
	RenderTarget->Texture = *new FNoesisTexture();
	RenderTarget->ColorTarget = SharedRenderTarget->ColorTarget;
	RenderTarget->DepthStencilTarget = SharedRenderTarget->DepthStencilTarget;

	uint32 SizeX = SharedRenderTarget->Texture->ShaderResourceTexture->GetSizeX();
	uint32 SizeY = SharedRenderTarget->Texture->ShaderResourceTexture->GetSizeY();
	uint8 Format = (uint8)PF_R8G8B8A8;
	uint32 NumMips = 1;
	uint32 Flags = TexCreate_ResolveTargetable | TexCreate_ShaderResource;
	FRHIResourceCreateInfo CreateInfo;
	FTexture2DRHIRef ShaderResourceTexture = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, 1, Flags, CreateInfo);
	RenderTarget->Texture->ShaderResourceTexture = ShaderResourceTexture;
	RenderTarget->Texture->Format = Noesis::TextureFormat::RGBA8;

	return Noesis::Ptr<Noesis::RenderTarget>(*RenderTarget);
}

Noesis::Ptr<Noesis::Texture> FNoesisRenderDevice::CreateTexture(const char* Label, uint32 Width, uint32 Height, uint32 NumLevels, Noesis::TextureFormat::Enum TextureFormat, const void** Data)
{
	uint32 SizeX = (uint32)Width;
	uint32 SizeY = (uint32)Height;
	EPixelFormat Formats[Noesis::TextureFormat::Count] = { PF_R8G8B8A8, PF_G8 };
	uint8 Format = (uint8)Formats[TextureFormat];
	uint32 NumMips = (uint32)NumLevels;
	uint32 NumSamples = 1;
	uint32 Flags = 0;
	FRHIResourceCreateInfo CreateInfo;
	FTexture2DRHIRef ShaderResourceTexture = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, NumSamples, Flags, CreateInfo);

	FNoesisTexture* Texture = new FNoesisTexture();
	Texture->ShaderResourceTexture = ShaderResourceTexture;
	Texture->Format = TextureFormat;

	FName TextureName = FName(Label);
	ShaderResourceTexture->SetName(TextureName);

	if (Data != nullptr)
	{
		for (uint32 Level = 0; Level < NumMips; ++Level)
		{
			UpdateTexture(Texture, Level, 0, 0, Width, Height, Data[Level]);
			Width >>= 1;
			Height >>= 1;
		}
	}

	return Noesis::Ptr<Noesis::Texture>(*Texture);
}

void FNoesisRenderDevice::UpdateTexture(Noesis::Texture* InTexture, uint32 Level, uint32 X, uint32 Y, uint32 Width, uint32 Height, const void* Data)
{
	FNoesisTexture* Texture = (FNoesisTexture*)InTexture;

	int32 MipIndex = (int32)Level;
	FUpdateTextureRegion2D UpdateRegion;
	UpdateRegion.SrcX = 0;
	UpdateRegion.SrcY = 0;
	UpdateRegion.DestX = (uint32)X;
	UpdateRegion.DestY = (uint32)Y;
	UpdateRegion.Width = (uint32)Width;
	UpdateRegion.Height = (uint32)Height;
	uint32 SourcePitch = (uint32)Width * ((Texture->ShaderResourceTexture->GetFormat() == PF_R8G8B8A8) ? 4 : 1);
	const uint8* SourceData = (const uint8*)Data;

	RHIUpdateTexture2D(Texture->ShaderResourceTexture, MipIndex, UpdateRegion, SourcePitch, SourceData);
}

void FNoesisRenderDevice::BeginRender(bool Offscreen)
{
}

void FNoesisRenderDevice::SetRenderTarget(Noesis::RenderTarget* Surface)
{
	FRHICommandList* RHICmdList = ThreadLocal_GetRHICmdList();
	check(RHICmdList);
	check(Surface);
	FNoesisRenderTarget* RenderTarget = (FNoesisRenderTarget*)Surface;
	FRHIRenderPassInfo RPInfo(RenderTarget->ColorTarget, ERenderTargetActions::Clear_DontStore, RenderTarget->DepthStencilTarget,
		MakeDepthStencilTargetActions(ERenderTargetActions::DontLoad_DontStore, ERenderTargetActions::Clear_DontStore), FExclusiveDepthStencil::DepthNop_StencilWrite);

	check(RHICmdList->IsOutsideRenderPass());
	RHICmdList->BeginRenderPass(RPInfo, TEXT("NoesisOffScreen"));
	RHICmdList->SetViewport(0, 0, 0.0f, RenderTarget->ColorTarget->GetSizeX(), RenderTarget->ColorTarget->GetSizeY(), 1.0f);
	CurrentRenderTarget = RenderTarget;
}

void FNoesisRenderDevice::BeginTile(const Noesis::Tile& Tile, uint32 SurfaceWidth, uint32 SurfaceHeight)
{
	FRHICommandList* RHICmdList = ThreadLocal_GetRHICmdList();
	check(RHICmdList);
	check(SurfaceHeight == CurrentRenderTarget->Texture->ShaderResourceTexture->GetSizeY());

	uint32 ScissorMinX = Tile.x;
	uint32 ScissorMinY = SurfaceHeight - (Tile.y + Tile.height);
	uint32 ScissorMaxX = Tile.x + Tile.width;
	uint32 ScissorMaxY = SurfaceHeight - Tile.y;
	RHICmdList->SetScissorRect(true, ScissorMinX, ScissorMinY, ScissorMaxX, ScissorMaxY);
}

void FNoesisRenderDevice::EndTile()
{
	FRHICommandList* RHICmdList = ThreadLocal_GetRHICmdList();
	check(RHICmdList);
	RHICmdList->SetScissorRect(false, 0, 0, 0, 0);
}

void FNoesisRenderDevice::ResolveRenderTarget(Noesis::RenderTarget* Surface, const Noesis::Tile* Tiles, uint32 NumTiles)
{
	FRHICommandList* RHICmdList = ThreadLocal_GetRHICmdList();
	check(RHICmdList);
	for (uint32 TileIndex = 0; TileIndex != (uint32)NumTiles; ++TileIndex)
	{
		const Noesis::Tile& Tile = Tiles[TileIndex];

		uint32 ResolveMinX = Tile.x;
		uint32 ResolveMinY = CurrentRenderTarget->Texture->ShaderResourceTexture->GetSizeY() - (Tile.y + Tile.height);
		uint32 ResolveMaxX = Tile.x + Tile.width;
		uint32 ResolveMaxY = CurrentRenderTarget->Texture->ShaderResourceTexture->GetSizeY() - Tile.y;

		FResolveParams ResolveParams;
		ResolveParams.Rect.X1 = ResolveMinX;
		ResolveParams.Rect.Y1 = ResolveMinY;
		ResolveParams.Rect.X2 = ResolveMaxX;
		ResolveParams.Rect.Y2 = ResolveMaxY;
		ResolveParams.DestRect.X1 = ResolveMinX;
		ResolveParams.DestRect.Y1 = ResolveMinY;
		ResolveParams.DestRect.X2 = ResolveMaxX;
		ResolveParams.DestRect.Y2 = ResolveMaxY;
		RHICmdList->CopyToResolveTarget(CurrentRenderTarget->ColorTarget, CurrentRenderTarget->Texture->ShaderResourceTexture, ResolveParams);
	}

	check(RHICmdList->IsInsideRenderPass());
	RHICmdList->EndRenderPass();
}

void FNoesisRenderDevice::EndRender()
{
}

void* FNoesisRenderDevice::MapVertices(uint32 Bytes)
{
	void* Result = RHILockVertexBuffer(DynamicVertexBuffer, 0, Bytes, RLM_WriteOnly);
	return Result;
}

void FNoesisRenderDevice::UnmapVertices()
{
	RHIUnlockVertexBuffer(DynamicVertexBuffer);
}

void* FNoesisRenderDevice::MapIndices(uint32 Bytes)
{
	void* Result = RHILockIndexBuffer(DynamicIndexBuffer, 0, Bytes, RLM_WriteOnly);
	return Result;
}

void FNoesisRenderDevice::UnmapIndices()
{
	RHIUnlockIndexBuffer(DynamicIndexBuffer);
}

static FRHISamplerState* GetSamplerState(uint32 SamplerCode)
{
	switch (SamplerCode & 63)
	{
	case 0:  return TStaticSamplerState<SF_Point, AM_Clamp, AM_Clamp>::GetRHI();
	case 1:  return TStaticSamplerState<SF_Point, AM_Border, AM_Border>::GetRHI();
	case 2:  return TStaticSamplerState<SF_Point, AM_Wrap, AM_Wrap>::GetRHI();
	case 3:  return TStaticSamplerState<SF_Point, AM_Mirror, AM_Wrap>::GetRHI();
	case 4:  return TStaticSamplerState<SF_Point, AM_Wrap, AM_Mirror>::GetRHI();
	case 5:  return TStaticSamplerState<SF_Point, AM_Mirror, AM_Mirror>::GetRHI();

	case 8:  return TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Clamp>::GetRHI();
	case 9:  return TStaticSamplerState<SF_Bilinear, AM_Border, AM_Border>::GetRHI();
	case 10:  return TStaticSamplerState<SF_Bilinear, AM_Wrap, AM_Wrap>::GetRHI();
	case 11:  return TStaticSamplerState<SF_Bilinear, AM_Mirror, AM_Wrap>::GetRHI();
	case 12:  return TStaticSamplerState<SF_Bilinear, AM_Wrap, AM_Mirror>::GetRHI();
	case 13:  return TStaticSamplerState<SF_Bilinear, AM_Mirror, AM_Mirror>::GetRHI();

	case 16: return TStaticSamplerState<SF_Point, AM_Clamp, AM_Clamp>::GetRHI();
	case 17: return TStaticSamplerState<SF_Point, AM_Border, AM_Border>::GetRHI();
	case 18: return TStaticSamplerState<SF_Point, AM_Wrap, AM_Wrap>::GetRHI();
	case 19: return TStaticSamplerState<SF_Point, AM_Mirror, AM_Wrap>::GetRHI();
	case 20: return TStaticSamplerState<SF_Point, AM_Wrap, AM_Mirror>::GetRHI();
	case 21: return TStaticSamplerState<SF_Point, AM_Mirror, AM_Mirror>::GetRHI();

	case 24: return TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Clamp>::GetRHI();
	case 25: return TStaticSamplerState<SF_Bilinear, AM_Border, AM_Border>::GetRHI();
	case 26:  return TStaticSamplerState<SF_Bilinear, AM_Wrap, AM_Wrap>::GetRHI();
	case 27:  return TStaticSamplerState<SF_Bilinear, AM_Mirror, AM_Wrap>::GetRHI();
	case 28:  return TStaticSamplerState<SF_Bilinear, AM_Wrap, AM_Mirror>::GetRHI();
	case 29:  return TStaticSamplerState<SF_Bilinear, AM_Mirror, AM_Mirror>::GetRHI();

	case 32:  return TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Clamp>::GetRHI();
	case 33:  return TStaticSamplerState<SF_Trilinear, AM_Border, AM_Border>::GetRHI();
	case 34:  return TStaticSamplerState<SF_Trilinear, AM_Wrap, AM_Wrap>::GetRHI();
	case 35:  return TStaticSamplerState<SF_Trilinear, AM_Mirror, AM_Wrap>::GetRHI();
	case 36:  return TStaticSamplerState<SF_Trilinear, AM_Wrap, AM_Mirror>::GetRHI();
	case 37:  return TStaticSamplerState<SF_Trilinear, AM_Mirror, AM_Mirror>::GetRHI();

	case 40:  return TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Clamp>::GetRHI();
	case 41:  return TStaticSamplerState<SF_Trilinear, AM_Border, AM_Border>::GetRHI();
	case 42:  return TStaticSamplerState<SF_Trilinear, AM_Wrap, AM_Wrap>::GetRHI();
	case 43:  return TStaticSamplerState<SF_Trilinear, AM_Mirror, AM_Wrap>::GetRHI();
	case 44:  return TStaticSamplerState<SF_Trilinear, AM_Wrap, AM_Mirror>::GetRHI();
	case 45:  return TStaticSamplerState<SF_Trilinear, AM_Mirror, AM_Mirror>::GetRHI();

	default:
		check(false);
	}

	return 0;
}

void FNoesisRenderDevice::DrawBatch(const Noesis::Batch& Batch)
{
	FRHICommandList* RHICmdList = ThreadLocal_GetRHICmdList();
	check(RHICmdList);
	FGraphicsPipelineStateInitializer GraphicsPSOInit;
	RHICmdList->ApplyCachedRenderTargets(GraphicsPSOInit);

	switch (Batch.renderState.f.stencilMode)
	{
		case Noesis::StencilMode::Disabled:
		{
			GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
		} break;
		case Noesis::StencilMode::Equal_Keep:
		{
			GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always, true, CF_Equal>::GetRHI();
		} break;
		case Noesis::StencilMode::Equal_Incr:
		{
			GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always, true, CF_Equal, SO_Keep, SO_Keep, SO_Increment>::GetRHI();
		} break;
		case Noesis::StencilMode::Equal_Decr:
		{
			GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always, true, CF_Equal, SO_Keep, SO_Keep, SO_Decrement>::GetRHI();
		} break;
		default:
		{
		} break;
	}

	if (Batch.renderState.f.colorEnable)
	{
		if (Batch.renderState.f.blendMode == Noesis::BlendMode::SrcOver)
		{
			GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGBA, BO_Add, BF_One, BF_InverseSourceAlpha, BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI();
		}
		else
		{
			GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGBA>::GetRHI();
		}
	}
	else
	{
		if (Batch.renderState.f.blendMode == Noesis::BlendMode::SrcOver)
		{
			GraphicsPSOInit.BlendState = TStaticBlendState<CW_NONE, BO_Add, BF_One, BF_InverseSourceAlpha, BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI();
		}
		else
		{
			GraphicsPSOInit.BlendState = TStaticBlendState<CW_NONE>::GetRHI();
		}
	}

	GraphicsPSOInit.RasterizerState = Batch.renderState.f.wireframe ? TStaticRasterizerState<FM_Wireframe, CM_None>::GetRHI() : TStaticRasterizerState<FM_Solid, CM_None>::GetRHI();

	FRHITexture* PatternTexture = 0;
	FRHISamplerState* PatternSamplerState = 0;
	if (Batch.pattern)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.pattern);
		PatternTexture = Texture->ShaderResourceTexture;
		PatternSamplerState = GetSamplerState((uint32)*(uint8*)&Batch.patternSampler);
	}

	FRHITexture* RampsTexture = 0;
	FRHISamplerState* RampsSamplerState = 0;
	if (Batch.ramps)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.ramps);
		RampsTexture = Texture->ShaderResourceTexture;
		RampsSamplerState = GetSamplerState((uint32)*(uint8*)&Batch.rampsSampler);
	}

	FRHITexture* ImageTexture = 0;
	FRHISamplerState* ImageSamplerState = 0;
	if (Batch.image)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.image);
		ImageTexture = Texture->ShaderResourceTexture;
		ImageSamplerState = GetSamplerState((uint32)*(uint8*)&Batch.imageSampler);
	}

	FRHITexture* GlyphsTexture = 0;
	FRHISamplerState* GlyphsSamplerState = 0;
	if (Batch.glyphs)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.glyphs);
		GlyphsTexture = Texture->ShaderResourceTexture;
		GlyphsSamplerState = GetSamplerState((uint32)*(uint8*)&Batch.glyphsSampler);
	}

	FRHITexture* ShadowTexture = 0;
	FRHISamplerState* ShadowSamplerState = 0;
	if (Batch.shadow)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.shadow);
		ShadowTexture = Texture->ShaderResourceTexture;
		ShadowSamplerState = GetSamplerState((uint32)*(uint8*)&Batch.shadowSampler);
	}

	const auto FeatureLevel = GMaxRHIFeatureLevel;

	uint32 ShaderCode = (uint32)Batch.shader.v;

	FVertexDeclarationRHIRef& VertexDeclaration = VertexDeclarations[ShaderCode];
	TShaderRef<FNoesisVSBase> VertexShader = VertexShaders[ShaderCode];
	TShaderRef<FNoesisPSBase> PixelShader = PixelShaders[ShaderCode];
	GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = VertexDeclaration;
	GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
	GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
	GraphicsPSOInit.PrimitiveType = PT_TriangleList;

	SetGraphicsPipelineState(*RHICmdList, GraphicsPSOInit);

	float TextureSize[4];
	if (Batch.glyphs || Batch.image)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.glyphs ? Batch.glyphs : Batch.image);
		uint32 Width = Texture->GetWidth();
		uint32 Height = Texture->GetHeight();
		TextureSize[0] = (float)Width;
		TextureSize[1] = (float)Height;
		TextureSize[2] = 1.0f / Width;
		TextureSize[3] = 1.0f / Height;
	}
	bool GenSt1 = ShaderCode >= Noesis::Shader::SDF_Solid && ShaderCode <= Noesis::Shader::SDF_LCD_Pattern;

	FMatrix ProjectionMtxValue(FPlane((*Batch.projMtx)[0], (*Batch.projMtx)[4], (*Batch.projMtx)[8], (*Batch.projMtx)[12]),
		FPlane((*Batch.projMtx)[1], (*Batch.projMtx)[5], (*Batch.projMtx)[9], (*Batch.projMtx)[13]),
		FPlane((*Batch.projMtx)[2], (*Batch.projMtx)[6], (*Batch.projMtx)[10], (*Batch.projMtx)[14]),
		FPlane((*Batch.projMtx)[3], (*Batch.projMtx)[7], (*Batch.projMtx)[11], (*Batch.projMtx)[15]));
	VertexShader->SetParameters(*RHICmdList, ProjectionMtxValue, GenSt1 ? (float(*)[2])&TextureSize : nullptr);

	const FVector4* RgbaValue = (const FVector4*)Batch.rgba;
	const FVector4 (*RadialGradValue)[2] = (const FVector4(*)[2])Batch.radialGrad;
	const float* OpacityValue = Batch.opacity;
	PixelShader->SetParameters(*RHICmdList, RgbaValue, RadialGradValue, OpacityValue);

	PixelShader->SetEffectsParameters(*RHICmdList, &TextureSize, Batch.effectParams, Batch.effectParamsSize);

	if (PatternTexture)
	{
		PixelShader->SetPatternTexture(*RHICmdList, PatternTexture, PatternSamplerState);
	}
	if (RampsTexture)
	{
		PixelShader->SetRampsTexture(*RHICmdList, RampsTexture, RampsSamplerState);
	}
	if (ImageTexture)
	{
		PixelShader->SetImageTexture(*RHICmdList, ImageTexture, ImageSamplerState);
	}
	if (GlyphsTexture)
	{
		PixelShader->SetGlyphsTexture(*RHICmdList, GlyphsTexture, GlyphsSamplerState);
	}
	if (ShadowTexture)
	{
		PixelShader->SetShadowTexture(*RHICmdList, ShadowTexture, ShadowSamplerState);
	}

	RHICmdList->SetStencilRef(Batch.stencilRef);
	RHICmdList->SetStreamSource(0, DynamicVertexBuffer, Batch.vertexOffset);

	RHICmdList->DrawIndexedPrimitive(DynamicIndexBuffer, 0, 0, VertexBufferSize, Batch.startIndex, Batch.numIndices / 3, 1);
}
