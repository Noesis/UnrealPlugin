////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisRenderDevice.h"

// Engine includes
#include "Engine/Texture2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Rendering/Texture2DResource.h"
#include "Materials/Material.h"
#include "SceneView.h"

// RHI includes
#include "RHI.h"
#include "RHICommandList.h"
#include "RHIStaticStates.h"
#include "PipelineStateCache.h"

// MediaAsset includes
#include "MediaTexture.h"

// RenderCore includes
#include "ClearQuad.h"

// Renderer includes
#include "SystemTextures.h"
#include "SceneRendering.h"

// NoesisRuntime includes
#include "Render/NoesisShaders.h"
#include "NoesisSettings.h"

class FNoesisTexture : public Noesis::Texture
{
public:
	FNoesisTexture(UTexture2D* Texture2D)
	{
		Width = (uint32)Texture2D->GetSizeX();
		Height = (uint32)Texture2D->GetSizeY();
		NumMipMaps = (uint32)Texture2D->GetNumMips();
		Alpha = Texture2D->HasAlphaChannel();
	}

	FNoesisTexture(UTextureRenderTarget2D* TextureRenderTarget2D)
	{
		Width = (uint32)TextureRenderTarget2D->SizeX;
		Height = (uint32)TextureRenderTarget2D->SizeY;
		NumMipMaps = (uint32)TextureRenderTarget2D->GetNumMips();
		Alpha = true; // Guess
	}

	FNoesisTexture(UMediaTexture* MediaTexture)
	{
		Width = (uint32)MediaTexture->GetWidth();
		Height = (uint32)MediaTexture->GetHeight();
		NumMipMaps = (uint32)MediaTexture->NumMips;
		Alpha = false; // Guess
	}

	FNoesisTexture(uint32 InWidth, uint32 InHeight, uint32 InNumMipMaps, bool InAlpha)
		: Width(InWidth), Height(InHeight), NumMipMaps(InNumMipMaps), Alpha(InAlpha)
	{
	}

	// Texture interface
	virtual uint32 GetWidth() const override
	{
		return Width;
	}

	virtual uint32 GetHeight() const override
	{
		return Height;
	}

	virtual bool HasMipMaps() const override
	{
		return NumMipMaps > 1;
	}

	virtual bool IsInverted() const override
	{
		return (bool)false;
	}
	
	virtual bool HasAlpha() const override
	{
		return Alpha;
	}
	// End of Texture interface

	FTexture2DRHIRef ShaderResourceTexture;
	Noesis::TextureFormat::Enum Format;
	uint32 Width;
	uint32 Height;
	uint32 NumMipMaps;
	bool Alpha;
};

class FNoesisMaterial
{
public:
	FNoesisMaterial(UMaterialInterface* InMaterial)
		: MaterialPtr(InMaterial)
	{
		MaterialProxy = InMaterial->GetRenderProxy();
#if WITH_EDITOR
		// We need this in the editor to account for material recompilations, which destroy the proxy.
		TickerHandle = FTicker::GetCoreTicker().AddTicker(TEXT("NoesisMaterial"), 0.0f, [this](float DeltaTime)
		{
			UMaterialInterface* Material = MaterialPtr.Get();
			if (Material != nullptr)
			{
				MaterialProxy = Material->GetRenderProxy();
			}
			else
			{
				MaterialProxy = nullptr;
			}
			return true;
		});
#endif
	}

	~FNoesisMaterial()
	{
#if WITH_EDITOR
		FTicker::GetCoreTicker().RemoveTicker(TickerHandle);
#endif
	}

	TWeakObjectPtr<UMaterialInterface> MaterialPtr;
	FMaterialRenderProxy* MaterialProxy;
#if WITH_EDITOR
	FDelegateHandle TickerHandle;
#endif
};

class FNoesisRenderTarget : public Noesis::RenderTarget
{
public:

	// RenderTarget interface
	virtual Noesis::Texture* GetTexture() override
	{
		return Texture;
	}
	// End of RenderTarget interface

	Noesis::Ptr<FNoesisTexture> Texture;
	FTexture2DRHIRef ColorTarget;
	FTexture2DRHIRef DepthStencilTarget;
};

static TShaderRef<FNoesisMaterialPSBase> GetMaterialPixelShader(const FMaterial* Material, Noesis::Shader::Enum ShaderType)
{
	const FMaterialShaderMap* MaterialShaderMap = Material->GetRenderingThreadShaderMap();

	TShaderRef<FShader> FoundShader;
	switch (ShaderType)
	{
		case Noesis::Shader::Path_Pattern:
			FoundShader = MaterialShaderMap->GetShader<FNoesisPathMaterialPS>();
			break;
		case Noesis::Shader::Path_Pattern_Clamp:
			FoundShader = MaterialShaderMap->GetShader<FNoesisPathMaterialClampPS>();
			break;
		case Noesis::Shader::Path_Pattern_Repeat:
			FoundShader = MaterialShaderMap->GetShader<FNoesisPathMaterialRepeatPS>();
			break;
		case Noesis::Shader::Path_Pattern_MirrorU:
			FoundShader = MaterialShaderMap->GetShader<FNoesisPathMaterialMirrorUPS>();
			break;
		case Noesis::Shader::Path_Pattern_MirrorV:
			FoundShader = MaterialShaderMap->GetShader<FNoesisPathMaterialMirrorVPS>();
			break;
		case Noesis::Shader::Path_Pattern_Mirror:
			FoundShader = MaterialShaderMap->GetShader<FNoesisPathMaterialMirrorPS>();
			break;
		case Noesis::Shader::Path_AA_Pattern:
			FoundShader = MaterialShaderMap->GetShader<FNoesisPathAAMaterialPS>();
			break;
		case Noesis::Shader::Path_AA_Pattern_Clamp:
			FoundShader = MaterialShaderMap->GetShader<FNoesisPathAAMaterialClampPS>();
			break;
		case Noesis::Shader::Path_AA_Pattern_Repeat:
			FoundShader = MaterialShaderMap->GetShader<FNoesisPathAAMaterialRepeatPS>();
			break;
		case Noesis::Shader::Path_AA_Pattern_MirrorU:
			FoundShader = MaterialShaderMap->GetShader<FNoesisPathAAMaterialMirrorUPS>();
			break;
		case Noesis::Shader::Path_AA_Pattern_MirrorV:
			FoundShader = MaterialShaderMap->GetShader<FNoesisPathAAMaterialMirrorVPS>();
			break;
		case Noesis::Shader::Path_AA_Pattern_Mirror:
			FoundShader = MaterialShaderMap->GetShader<FNoesisPathAAMaterialMirrorPS>();
			break;
		case Noesis::Shader::SDF_Pattern:
			FoundShader = MaterialShaderMap->GetShader<FNoesisSDFMaterialPS>();
			break;
		case Noesis::Shader::SDF_Pattern_Clamp:
			FoundShader = MaterialShaderMap->GetShader<FNoesisSDFMaterialClampPS>();
			break;
		case Noesis::Shader::SDF_Pattern_Repeat:
			FoundShader = MaterialShaderMap->GetShader<FNoesisSDFMaterialRepeatPS>();
			break;
		case Noesis::Shader::SDF_Pattern_MirrorU:
			FoundShader = MaterialShaderMap->GetShader<FNoesisSDFMaterialMirrorUPS>();
			break;
		case Noesis::Shader::SDF_Pattern_MirrorV:
			FoundShader = MaterialShaderMap->GetShader<FNoesisSDFMaterialMirrorVPS>();
			break;
		case Noesis::Shader::SDF_Pattern_Mirror:
			FoundShader = MaterialShaderMap->GetShader<FNoesisSDFMaterialMirrorPS>();
			break;
		case Noesis::Shader::SDF_LCD_Pattern:
			FoundShader = MaterialShaderMap->GetShader<FNoesisSDFLCDMaterialPS>();
			break;
		case Noesis::Shader::SDF_LCD_Pattern_Clamp:
			FoundShader = MaterialShaderMap->GetShader<FNoesisSDFLCDMaterialClampPS>();
			break;
		case Noesis::Shader::SDF_LCD_Pattern_Repeat:
			FoundShader = MaterialShaderMap->GetShader<FNoesisSDFLCDMaterialRepeatPS>();
			break;
		case Noesis::Shader::SDF_LCD_Pattern_MirrorU:
			FoundShader = MaterialShaderMap->GetShader<FNoesisSDFLCDMaterialMirrorUPS>();
			break;
		case Noesis::Shader::SDF_LCD_Pattern_MirrorV:
			FoundShader = MaterialShaderMap->GetShader<FNoesisSDFLCDMaterialMirrorVPS>();
			break;
		case Noesis::Shader::SDF_LCD_Pattern_Mirror:
			FoundShader = MaterialShaderMap->GetShader<FNoesisSDFLCDMaterialMirrorPS>();
			break;
		case Noesis::Shader::Opacity_Pattern:
			FoundShader = MaterialShaderMap->GetShader<FNoesisOpacityMaterialPS>();
			break;
		case Noesis::Shader::Opacity_Pattern_Clamp:
			FoundShader = MaterialShaderMap->GetShader<FNoesisOpacityMaterialClampPS>();
			break;
		case Noesis::Shader::Opacity_Pattern_Repeat:
			FoundShader = MaterialShaderMap->GetShader<FNoesisOpacityMaterialRepeatPS>();
			break;
		case Noesis::Shader::Opacity_Pattern_MirrorU:
			FoundShader = MaterialShaderMap->GetShader<FNoesisOpacityMaterialMirrorUPS>();
			break;
		case Noesis::Shader::Opacity_Pattern_MirrorV:
			FoundShader = MaterialShaderMap->GetShader<FNoesisOpacityMaterialMirrorVPS>();
			break;
		case Noesis::Shader::Opacity_Pattern_Mirror:
			FoundShader = MaterialShaderMap->GetShader<FNoesisOpacityMaterialMirrorPS>();
			break;
		default:
			// Only pattern shaders should be requested
			check(false);
	}

	return TShaderRef<FNoesisMaterialPSBase>::Cast(FoundShader);
}

template<ESamplerFilter Filter = SF_Point,
	ESamplerAddressMode AddressU = AM_Clamp,
	ESamplerAddressMode AddressV = AM_Clamp,
	int MaxMipLevel = 0>
class TNoesisStaticSamplerState : public TStaticStateRHI<TNoesisStaticSamplerState<Filter, AddressU, AddressV, MaxMipLevel>, FSamplerStateRHIRef, FRHISamplerState*>
{
public:
	static FSamplerStateRHIRef CreateRHI()
	{
		FSamplerStateInitializerRHI Initializer(Filter, AddressU, AddressV, AM_Clamp, -0.75f, 1, 0, MaxMipLevel == 0 ? 0.0f : FLT_MAX, 0, SCF_Never);
		return RHICreateSamplerState(Initializer);
	}
};

FNoesisRenderDevice::FNoesisRenderDevice()
	: VSConstantsHash(0), TextureSizeHash(0), PSConstantsHash(0), EffectsHash(0)
{
	FRHIResourceCreateInfo CreateInfo(TEXT("Noesis.VertexIndexBuffer"));
	DynamicVertexBuffer = RHICreateVertexBuffer(DYNAMIC_VB_SIZE, BUF_Volatile, CreateInfo);
	DynamicIndexBuffer = RHICreateIndexBuffer(sizeof(int16), DYNAMIC_IB_SIZE, BUF_Volatile, CreateInfo);

	VSConstantBuffer = TUniformBufferRef<FNoesisVSConstants>::CreateUniformBufferImmediate(FNoesisVSConstants(), UniformBuffer_MultiFrame);
	TextureSizeBuffer = TUniformBufferRef<FNoesisTextureSize>::CreateUniformBufferImmediate(FNoesisTextureSize(), UniformBuffer_MultiFrame);
	PSRgbaConstantBuffer = TUniformBufferRef<FNoesisPSRgbaConstants>::CreateUniformBufferImmediate(FNoesisPSRgbaConstants(), UniformBuffer_MultiFrame);
	PSOpacityConstantBuffer = TUniformBufferRef<FNoesisPSOpacityConstants>::CreateUniformBufferImmediate(FNoesisPSOpacityConstants(), UniformBuffer_MultiFrame);
	PSRadialGradConstantBuffer = TUniformBufferRef<FNoesisPSRadialGradConstants>::CreateUniformBufferImmediate(FNoesisPSRadialGradConstants(), UniformBuffer_MultiFrame);
	BlurConstantsBuffer = TUniformBufferRef<FNoesisBlurConstants>::CreateUniformBufferImmediate(FNoesisBlurConstants(), UniformBuffer_MultiFrame);
	ShadowConstantsBuffer = TUniformBufferRef<FNoesisShadowConstants>::CreateUniformBufferImmediate(FNoesisShadowConstants(), UniformBuffer_MultiFrame);
	ViewBuffer = TUniformBufferRef<FViewUniformShaderParameters>::CreateUniformBufferImmediate(FViewUniformShaderParameters(), UniformBuffer_MultiFrame);

	const auto FeatureLevel = GMaxRHIFeatureLevel;

	FMemory::Memzero(VertexDeclarations);

	VertexDeclarations[Noesis::Shader::RGBA] = GNoesisPosVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::RGBA] = TShaderMapRef<FNoesisPosVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::RGBA] = TShaderMapRef<FNoesisRgbaPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::RGBA] = &PSRgbaConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::RGBA] = nullptr;

	VertexDeclarations[Noesis::Shader::Mask] = GNoesisPosVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Mask] = TShaderMapRef<FNoesisPosVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Mask] = TShaderMapRef<FNoesisMaskPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Mask] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Mask] = nullptr;

	VertexDeclarations[Noesis::Shader::Clear] = GNoesisPosVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Clear] = TShaderMapRef<FNoesisPosVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Clear] = TShaderMapRef<FNoesisClearPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Clear] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Clear] = nullptr;

	VertexDeclarations[Noesis::Shader::Path_Solid] = GNoesisPosColorVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_Solid] = TShaderMapRef<FNoesisPosColorVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Solid] = TShaderMapRef<FNoesisPathSolidPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Solid] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Solid] = nullptr;

	VertexDeclarations[Noesis::Shader::Path_Linear] = GNoesisPosTex0VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_Linear] = TShaderMapRef<FNoesisPosTex0VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Linear] = TShaderMapRef<FNoesisPathLinearPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Linear] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Linear] = nullptr;

	VertexDeclarations[Noesis::Shader::Path_Radial] = GNoesisPosTex0VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_Radial] = TShaderMapRef<FNoesisPosTex0VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Radial] = TShaderMapRef<FNoesisPathRadialPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Radial] = &PSRadialGradConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Radial] = nullptr;

	VertexDeclarations[Noesis::Shader::Path_Pattern] = GNoesisPosTex0VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_Pattern] = TShaderMapRef<FNoesisPosTex0VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Pattern] = TShaderMapRef<FNoesisPathPatternPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Pattern] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Pattern] = nullptr;

	VertexDeclarations[Noesis::Shader::Path_Pattern_Clamp] = GNoesisPosTex0RectVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_Pattern_Clamp] = TShaderMapRef<FNoesisPosTex0RectVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Pattern_Clamp] = TShaderMapRef<FNoesisPathPatternClampPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Pattern_Clamp] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Pattern_Clamp] = nullptr;

	VertexDeclarations[Noesis::Shader::Path_Pattern_Repeat] = GNoesisPosTex0RectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_Pattern_Repeat] = TShaderMapRef<FNoesisPosTex0RectTileVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Pattern_Repeat] = TShaderMapRef<FNoesisPathPatternRepeatPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Pattern_Repeat] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Pattern_Repeat] = nullptr;

	VertexDeclarations[Noesis::Shader::Path_Pattern_MirrorU] = GNoesisPosTex0RectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_Pattern_MirrorU] = TShaderMapRef<FNoesisPosTex0RectTileVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Pattern_MirrorU] = TShaderMapRef<FNoesisPathPatternMirrorUPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Pattern_MirrorU] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Pattern_MirrorU] = nullptr;

	VertexDeclarations[Noesis::Shader::Path_Pattern_MirrorV] = GNoesisPosTex0RectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_Pattern_MirrorV] = TShaderMapRef<FNoesisPosTex0RectTileVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Pattern_MirrorV] = TShaderMapRef<FNoesisPathPatternMirrorVPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Pattern_MirrorV] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Pattern_MirrorV] = nullptr;

	VertexDeclarations[Noesis::Shader::Path_Pattern_Mirror] = GNoesisPosTex0RectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_Pattern_Mirror] = TShaderMapRef<FNoesisPosTex0RectTileVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Pattern_Mirror] = TShaderMapRef<FNoesisPathPatternMirrorPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Pattern_Mirror] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Pattern_Mirror] = nullptr;

	VertexDeclarations[Noesis::Shader::Path_AA_Solid] = GNoesisPosColorCoverageVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_AA_Solid] = TShaderMapRef<FNoesisPosColorCoverageVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_AA_Solid] = TShaderMapRef<FNoesisPathAASolidPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Solid] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Solid] = nullptr;

	VertexDeclarations[Noesis::Shader::Path_AA_Linear] = GNoesisPosTex0CoverageVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_AA_Linear] = TShaderMapRef<FNoesisPosTex0CoverageVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_AA_Linear] = TShaderMapRef<FNoesisPathAALinearPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Linear] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Linear] = nullptr;

	VertexDeclarations[Noesis::Shader::Path_AA_Radial] = GNoesisPosTex0CoverageVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_AA_Radial] = TShaderMapRef<FNoesisPosTex0CoverageVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_AA_Radial] = TShaderMapRef<FNoesisPathAARadialPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Radial] = &PSRadialGradConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Radial] = nullptr;

	VertexDeclarations[Noesis::Shader::Path_AA_Pattern] = GNoesisPosTex0CoverageVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_AA_Pattern] = TShaderMapRef<FNoesisPosTex0CoverageVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_AA_Pattern] = TShaderMapRef<FNoesisPathAAPatternPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Pattern] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Pattern] = nullptr;

	VertexDeclarations[Noesis::Shader::Path_AA_Pattern_Clamp] = GNoesisPosTex0CoverageRectVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_AA_Pattern_Clamp] = TShaderMapRef<FNoesisPosTex0CoverageRectVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_AA_Pattern_Clamp] = TShaderMapRef<FNoesisPathAAPatternClampPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Pattern_Clamp] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Pattern_Clamp] = nullptr;

	VertexDeclarations[Noesis::Shader::Path_AA_Pattern_Repeat] = GNoesisPosTex0CoverageRectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_AA_Pattern_Repeat] = TShaderMapRef<FNoesisPosTex0CoverageRectTileVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_AA_Pattern_Repeat] = TShaderMapRef<FNoesisPathAAPatternRepeatPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Pattern_Repeat] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Pattern_Repeat] = nullptr;

	VertexDeclarations[Noesis::Shader::Path_AA_Pattern_MirrorU] = GNoesisPosTex0CoverageRectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_AA_Pattern_MirrorU] = TShaderMapRef<FNoesisPosTex0CoverageRectTileVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_AA_Pattern_MirrorU] = TShaderMapRef<FNoesisPathAAPatternMirrorUPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Pattern_MirrorU] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Pattern_MirrorU] = nullptr;

	VertexDeclarations[Noesis::Shader::Path_AA_Pattern_MirrorV] = GNoesisPosTex0CoverageRectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_AA_Pattern_MirrorV] = TShaderMapRef<FNoesisPosTex0CoverageRectTileVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_AA_Pattern_MirrorV] = TShaderMapRef<FNoesisPathAAPatternMirrorVPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Pattern_MirrorV] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Pattern_MirrorV] = nullptr;

	VertexDeclarations[Noesis::Shader::Path_AA_Pattern_Mirror] = GNoesisPosTex0CoverageRectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Path_AA_Pattern_Mirror] = TShaderMapRef<FNoesisPosTex0CoverageRectTileVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_AA_Pattern_Mirror] = TShaderMapRef<FNoesisPathAAPatternMirrorPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Pattern_Mirror] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Pattern_Mirror] = nullptr;

	VertexDeclarations[Noesis::Shader::SDF_Solid] = GNoesisPosColorTex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_Solid] = TShaderMapRef<FNoesisPosColorTex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Solid] = TShaderMapRef<FNoesisSDFSolidPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Solid] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Solid] = nullptr;

	VertexDeclarations[Noesis::Shader::SDF_Linear] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_Linear] = TShaderMapRef<FNoesisPosTex0Tex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Linear] = TShaderMapRef<FNoesisSDFLinearPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Linear] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Linear] = nullptr;

	VertexDeclarations[Noesis::Shader::SDF_Radial] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_Radial] = TShaderMapRef<FNoesisPosTex0Tex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Radial] = TShaderMapRef<FNoesisSDFRadialPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Radial] = &PSRadialGradConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Radial] = nullptr;

	VertexDeclarations[Noesis::Shader::SDF_Pattern] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_Pattern] = TShaderMapRef<FNoesisPosTex0Tex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Pattern] = TShaderMapRef<FNoesisSDFPatternPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Pattern] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Pattern] = nullptr;

	VertexDeclarations[Noesis::Shader::SDF_Pattern_Clamp] = GNoesisPosTex0Tex1RectVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_Pattern_Clamp] = TShaderMapRef<FNoesisPosTex0Tex1RectSDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Pattern_Clamp] = TShaderMapRef<FNoesisSDFPatternClampPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Pattern_Clamp] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Pattern_Clamp] = nullptr;

	VertexDeclarations[Noesis::Shader::SDF_Pattern_Repeat] = GNoesisPosTex0Tex1RectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_Pattern_Repeat] = TShaderMapRef<FNoesisPosTex0Tex1RectTileSDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Pattern_Repeat] = TShaderMapRef<FNoesisSDFPatternRepeatPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Pattern_Repeat] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Pattern_Repeat] = nullptr;

	VertexDeclarations[Noesis::Shader::SDF_Pattern_MirrorU] = GNoesisPosTex0Tex1RectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_Pattern_MirrorU] = TShaderMapRef<FNoesisPosTex0Tex1RectTileSDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Pattern_MirrorU] = TShaderMapRef<FNoesisSDFPatternMirrorUPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Pattern_MirrorU] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Pattern_MirrorU] = nullptr;

	VertexDeclarations[Noesis::Shader::SDF_Pattern_MirrorV] = GNoesisPosTex0Tex1RectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_Pattern_MirrorV] = TShaderMapRef<FNoesisPosTex0Tex1RectTileSDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Pattern_MirrorV] = TShaderMapRef<FNoesisSDFPatternMirrorVPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Pattern_MirrorV] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Pattern_MirrorV] = nullptr;

	VertexDeclarations[Noesis::Shader::SDF_Pattern_Mirror] = GNoesisPosTex0Tex1RectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_Pattern_Mirror] = TShaderMapRef<FNoesisPosTex0Tex1RectTileSDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Pattern_Mirror] = TShaderMapRef<FNoesisSDFPatternMirrorPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Pattern_Mirror] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Pattern_Mirror] = nullptr;

	VertexDeclarations[Noesis::Shader::SDF_LCD_Solid] = GNoesisPosColorTex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_LCD_Solid] = TShaderMapRef<FNoesisPosColorTex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Solid] = TShaderMapRef<FNoesisSDFLCDSolidPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Solid] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Solid] = nullptr;

	VertexDeclarations[Noesis::Shader::SDF_LCD_Linear] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_LCD_Linear] = TShaderMapRef<FNoesisPosTex0Tex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Linear] = TShaderMapRef<FNoesisSDFLCDLinearPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Linear] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Linear] = nullptr;

	VertexDeclarations[Noesis::Shader::SDF_LCD_Radial] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_LCD_Radial] = TShaderMapRef<FNoesisPosTex0Tex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Radial] = TShaderMapRef<FNoesisSDFLCDRadialPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Radial] = &PSRadialGradConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Radial] = nullptr;

	VertexDeclarations[Noesis::Shader::SDF_LCD_Pattern] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_LCD_Pattern] = TShaderMapRef<FNoesisPosTex0Tex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Pattern] = TShaderMapRef<FNoesisSDFLCDPatternPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Pattern] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Pattern] = nullptr;

	VertexDeclarations[Noesis::Shader::SDF_LCD_Pattern_Clamp] = GNoesisPosTex0Tex1RectVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_LCD_Pattern_Clamp] = TShaderMapRef<FNoesisPosTex0Tex1RectSDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Pattern_Clamp] = TShaderMapRef<FNoesisSDFLCDPatternClampPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Pattern_Clamp] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Pattern_Clamp] = nullptr;

	VertexDeclarations[Noesis::Shader::SDF_LCD_Pattern_Repeat] = GNoesisPosTex0Tex1RectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_LCD_Pattern_Repeat] = TShaderMapRef<FNoesisPosTex0Tex1RectTileSDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Pattern_Repeat] = TShaderMapRef<FNoesisSDFLCDPatternRepeatPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Pattern_Repeat] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Pattern_Repeat] = nullptr;

	VertexDeclarations[Noesis::Shader::SDF_LCD_Pattern_MirrorU] = GNoesisPosTex0Tex1RectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_LCD_Pattern_MirrorU] = TShaderMapRef<FNoesisPosTex0Tex1RectTileSDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Pattern_MirrorU] = TShaderMapRef<FNoesisSDFLCDPatternMirrorUPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Pattern_MirrorU] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Pattern_MirrorU] = nullptr;

	VertexDeclarations[Noesis::Shader::SDF_LCD_Pattern_MirrorV] = GNoesisPosTex0Tex1RectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_LCD_Pattern_MirrorV] = TShaderMapRef<FNoesisPosTex0Tex1RectTileSDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Pattern_MirrorV] = TShaderMapRef<FNoesisSDFLCDPatternMirrorVPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Pattern_MirrorV] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Pattern_MirrorV] = nullptr;

	VertexDeclarations[Noesis::Shader::SDF_LCD_Pattern_Mirror] = GNoesisPosTex0Tex1RectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::SDF_LCD_Pattern_Mirror] = TShaderMapRef<FNoesisPosTex0Tex1RectTileSDFVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Pattern_Mirror] = TShaderMapRef<FNoesisSDFLCDPatternMirrorPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Pattern_Mirror] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Pattern_Mirror] = nullptr;

	VertexDeclarations[Noesis::Shader::Opacity_Solid] = GNoesisPosColorTex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Opacity_Solid] = TShaderMapRef<FNoesisPosColorTex1VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Opacity_Solid] = TShaderMapRef<FNoesisOpacitySolidPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Solid] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Solid] = nullptr;

	VertexDeclarations[Noesis::Shader::Opacity_Linear] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Opacity_Linear] = TShaderMapRef<FNoesisPosTex0Tex1VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Opacity_Linear] = TShaderMapRef<FNoesisOpacityLinearPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Linear] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Linear] = nullptr;

	VertexDeclarations[Noesis::Shader::Opacity_Radial] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Opacity_Radial] = TShaderMapRef<FNoesisPosTex0Tex1VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Opacity_Radial] = TShaderMapRef<FNoesisOpacityRadialPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Radial] = &PSRadialGradConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Radial] = nullptr;

	VertexDeclarations[Noesis::Shader::Opacity_Pattern] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Opacity_Pattern] = TShaderMapRef<FNoesisPosTex0Tex1VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Opacity_Pattern] = TShaderMapRef<FNoesisOpacityPatternPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Pattern] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Pattern] = nullptr;

	VertexDeclarations[Noesis::Shader::Opacity_Pattern_Clamp] = GNoesisPosTex0Tex1RectVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Opacity_Pattern_Clamp] = TShaderMapRef<FNoesisPosTex0Tex1RectVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Opacity_Pattern_Clamp] = TShaderMapRef<FNoesisOpacityPatternClampPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Pattern_Clamp] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Pattern_Clamp] = nullptr;

	VertexDeclarations[Noesis::Shader::Opacity_Pattern_Repeat] = GNoesisPosTex0Tex1RectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Opacity_Pattern_Repeat] = TShaderMapRef<FNoesisPosTex0Tex1RectTileVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Opacity_Pattern_Repeat] = TShaderMapRef<FNoesisOpacityPatternRepeatPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Pattern_Repeat] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Pattern_Repeat] = nullptr;

	VertexDeclarations[Noesis::Shader::Opacity_Pattern_MirrorU] = GNoesisPosTex0Tex1RectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Opacity_Pattern_MirrorU] = TShaderMapRef<FNoesisPosTex0Tex1RectTileVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Opacity_Pattern_MirrorU] = TShaderMapRef<FNoesisOpacityPatternMirrorUPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Pattern_MirrorU] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Pattern_MirrorU] = nullptr;

	VertexDeclarations[Noesis::Shader::Opacity_Pattern_MirrorV] = GNoesisPosTex0Tex1RectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Opacity_Pattern_MirrorV] = TShaderMapRef<FNoesisPosTex0Tex1RectTileVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Opacity_Pattern_MirrorV] = TShaderMapRef<FNoesisOpacityPatternMirrorVPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Pattern_MirrorV] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Pattern_MirrorV] = nullptr;

	VertexDeclarations[Noesis::Shader::Opacity_Pattern_Mirror] = GNoesisPosTex0Tex1RectTileVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Opacity_Pattern_Mirror] = TShaderMapRef<FNoesisPosTex0Tex1RectTileVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Opacity_Pattern_Mirror] = TShaderMapRef<FNoesisOpacityPatternMirrorPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Pattern_Mirror] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Pattern_Mirror] = nullptr;

	VertexDeclarations[Noesis::Shader::Upsample] = GNoesisPosColorTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Upsample] = TShaderMapRef<FNoesisPosColorTex0Tex1VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Upsample] = TShaderMapRef<FNoesisUpsamplePS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Upsample] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Upsample] = nullptr;

	VertexDeclarations[Noesis::Shader::Downsample] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Downsample] = TShaderMapRef<FNoesisPosTex0Tex1DownsampleVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Downsample] = TShaderMapRef<FNoesisDownsamplePS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Downsample] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Downsample] = nullptr;

	VertexDeclarations[Noesis::Shader::Shadow] = GNoesisPosColorTex1RectVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Shadow] = TShaderMapRef<FNoesisPosColorTex1RectVS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Shadow] = TShaderMapRef<FNoesisShadowPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Shadow] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Shadow] = &ShadowConstantsBuffer;

	VertexDeclarations[Noesis::Shader::Blur] = GNoesisPosColorTex1VertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Blur] = TShaderMapRef<FNoesisPosColorTex1VS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Blur] = TShaderMapRef<FNoesisBlurPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaderConstantBuffer0[Noesis::Shader::Blur] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Blur] = &BlurConstantsBuffer;

	VertexDeclarations[Noesis::Shader::Custom_Effect] = GNoesisPosColorTex0RectImagePosVertexDeclaration.VertexDeclarationRHI;
	VertexShaders[Noesis::Shader::Custom_Effect] = TShaderMapRef<FNoesisPosColorTex0RectImagePosVS>(GetGlobalShaderMap(FeatureLevel));
	// PixelShaders[Noesis::Shader::Custom_Effect] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Custom_Effect] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Custom_Effect] = nullptr;

	// Read the comment next to PATTERN_SRGB in FNoesisPS::ModifyCompilationEnvironment
	PixelShadersPatternSRGB[Noesis::Shader::Path_Pattern] = TShaderMapRef<FNoesisPathPatternSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::Path_Pattern_Clamp] = TShaderMapRef<FNoesisPathPatternClampSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::Path_Pattern_Repeat] = TShaderMapRef<FNoesisPathPatternRepeatSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::Path_Pattern_MirrorU] = TShaderMapRef<FNoesisPathPatternMirrorUSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::Path_Pattern_MirrorV] = TShaderMapRef<FNoesisPathPatternMirrorVSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::Path_Pattern_Mirror] = TShaderMapRef<FNoesisPathPatternMirrorSRGBPS>(GetGlobalShaderMap(FeatureLevel));

	PixelShadersPatternSRGB[Noesis::Shader::Path_AA_Pattern] = TShaderMapRef<FNoesisPathAAPatternSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::Path_AA_Pattern_Clamp] = TShaderMapRef<FNoesisPathAAPatternClampSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::Path_AA_Pattern_Repeat] = TShaderMapRef<FNoesisPathAAPatternRepeatSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::Path_AA_Pattern_MirrorU] = TShaderMapRef<FNoesisPathAAPatternMirrorUSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::Path_AA_Pattern_MirrorV] = TShaderMapRef<FNoesisPathAAPatternMirrorVSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::Path_AA_Pattern_Mirror] = TShaderMapRef<FNoesisPathAAPatternMirrorSRGBPS>(GetGlobalShaderMap(FeatureLevel));

	PixelShadersPatternSRGB[Noesis::Shader::SDF_Pattern] = TShaderMapRef<FNoesisSDFPatternSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::SDF_Pattern_Clamp] = TShaderMapRef<FNoesisSDFPatternClampSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::SDF_Pattern_Repeat] = TShaderMapRef<FNoesisSDFPatternRepeatSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::SDF_Pattern_MirrorU] = TShaderMapRef<FNoesisSDFPatternMirrorUSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::SDF_Pattern_MirrorV] = TShaderMapRef<FNoesisSDFPatternMirrorVSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::SDF_Pattern_Mirror] = TShaderMapRef<FNoesisSDFPatternMirrorSRGBPS>(GetGlobalShaderMap(FeatureLevel));

	PixelShadersPatternSRGB[Noesis::Shader::SDF_LCD_Pattern] = TShaderMapRef<FNoesisSDFLCDPatternSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::SDF_LCD_Pattern_Clamp] = TShaderMapRef<FNoesisSDFLCDPatternClampSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::SDF_LCD_Pattern_Repeat] = TShaderMapRef<FNoesisSDFLCDPatternRepeatSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::SDF_LCD_Pattern_MirrorU] = TShaderMapRef<FNoesisSDFLCDPatternMirrorUSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::SDF_LCD_Pattern_MirrorV] = TShaderMapRef<FNoesisSDFLCDPatternMirrorVSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::SDF_LCD_Pattern_Mirror] = TShaderMapRef<FNoesisSDFLCDPatternMirrorSRGBPS>(GetGlobalShaderMap(FeatureLevel));

	PixelShadersPatternSRGB[Noesis::Shader::Opacity_Pattern] = TShaderMapRef<FNoesisOpacityPatternSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::Opacity_Pattern_Clamp] = TShaderMapRef<FNoesisOpacityPatternClampSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::Opacity_Pattern_Repeat] = TShaderMapRef<FNoesisOpacityPatternRepeatSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::Opacity_Pattern_MirrorU] = TShaderMapRef<FNoesisOpacityPatternMirrorUSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::Opacity_Pattern_MirrorV] = TShaderMapRef<FNoesisOpacityPatternMirrorVSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShadersPatternSRGB[Noesis::Shader::Opacity_Pattern_Mirror] = TShaderMapRef<FNoesisOpacityPatternMirrorSRGBPS>(GetGlobalShaderMap(FeatureLevel));


	DepthStencilStates[Noesis::StencilMode::Disabled] =   TStaticDepthStencilState<false,  CF_Always>::GetRHI();
	DepthStencilStates[Noesis::StencilMode::Equal_Keep] = TStaticDepthStencilState<false, CF_Always, true, CF_Equal,  SO_Keep, SO_Keep, SO_Keep,      true, CF_Equal,  SO_Keep, SO_Keep, SO_Keep>::GetRHI();
	DepthStencilStates[Noesis::StencilMode::Equal_Incr] = TStaticDepthStencilState<false, CF_Always, true, CF_Equal,  SO_Keep, SO_Keep, SO_Increment, true, CF_Equal,  SO_Keep, SO_Keep, SO_Increment>::GetRHI();
	DepthStencilStates[Noesis::StencilMode::Equal_Decr] = TStaticDepthStencilState<false, CF_Always, true, CF_Equal,  SO_Keep, SO_Keep, SO_Decrement, true, CF_Equal,  SO_Keep, SO_Keep, SO_Decrement>::GetRHI();
	DepthStencilStates[Noesis::StencilMode::Clear] =      TStaticDepthStencilState<false, CF_Always, true, CF_Always, SO_Keep, SO_Keep, SO_Zero,      true, CF_Always, SO_Keep, SO_Keep, SO_Zero>::GetRHI();

	BlendStates[Noesis::BlendMode::Src] =              TStaticBlendState<CW_RGBA>::GetRHI();
	BlendStates[Noesis::BlendMode::SrcOver] =          TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_InverseSourceAlpha,  BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI();
	BlendStates[Noesis::BlendMode::SrcOver_Multiply] = TStaticBlendState<CW_RGBA, BO_Add, BF_DestColor, BF_InverseSourceAlpha,  BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI();
	BlendStates[Noesis::BlendMode::SrcOver_Screen] =   TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_InverseSourceColor,  BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI();
	BlendStates[Noesis::BlendMode::SrcOver_Additive] = TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_One,                 BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI();
	BlendStates[Noesis::BlendMode::SrcOver_Dual] =     TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_InverseSource1Color, BO_Add, BF_One, BF_InverseSource1Alpha>::GetRHI();

	FMemory::Memzero(SamplerStates);
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToEdge, Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Disabled } }.v] = TNoesisStaticSamplerState<SF_Point,     AM_Clamp,  AM_Clamp,  0>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToZero, Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Disabled } }.v] = TNoesisStaticSamplerState<SF_Point,     AM_Border, AM_Border, 0>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Repeat,      Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Disabled } }.v] = TNoesisStaticSamplerState<SF_Point,     AM_Wrap,   AM_Wrap,   0>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorU,     Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Disabled } }.v] = TNoesisStaticSamplerState<SF_Point,     AM_Mirror, AM_Wrap,   0>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorV,     Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Disabled } }.v] = TNoesisStaticSamplerState<SF_Point,     AM_Wrap,   AM_Mirror, 0>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Mirror,      Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Disabled } }.v] = TNoesisStaticSamplerState<SF_Point,     AM_Mirror, AM_Mirror, 0>::GetRHI();

	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToEdge, Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Disabled } }.v] = TNoesisStaticSamplerState<SF_Bilinear,  AM_Clamp,  AM_Clamp,  0>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToZero, Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Disabled } }.v] = TNoesisStaticSamplerState<SF_Bilinear,  AM_Border, AM_Border, 0>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Repeat,      Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Disabled } }.v] = TNoesisStaticSamplerState<SF_Bilinear,  AM_Wrap,   AM_Wrap,   0>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorU,     Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Disabled } }.v] = TNoesisStaticSamplerState<SF_Bilinear,  AM_Mirror, AM_Wrap,   0>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorV,     Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Disabled } }.v] = TNoesisStaticSamplerState<SF_Bilinear,  AM_Wrap,   AM_Mirror, 0>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Mirror,      Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Disabled } }.v] = TNoesisStaticSamplerState<SF_Bilinear,  AM_Mirror, AM_Mirror, 0>::GetRHI();

	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToZero, Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Nearest } }.v] =  TNoesisStaticSamplerState<SF_Point,     AM_Border, AM_Border>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Repeat,      Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Nearest } }.v] =  TNoesisStaticSamplerState<SF_Point,     AM_Wrap,   AM_Wrap>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorU,     Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Nearest } }.v] =  TNoesisStaticSamplerState<SF_Point,     AM_Mirror, AM_Wrap>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToEdge, Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Nearest } }.v] =  TNoesisStaticSamplerState<SF_Point,     AM_Clamp,  AM_Clamp>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorV,     Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Nearest } }.v] =  TNoesisStaticSamplerState<SF_Point,     AM_Wrap,   AM_Mirror>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Mirror,      Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Nearest } }.v] =  TNoesisStaticSamplerState<SF_Point,     AM_Mirror, AM_Mirror>::GetRHI();

	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToEdge, Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Nearest } }.v] =  TNoesisStaticSamplerState<SF_Bilinear,  AM_Clamp,  AM_Clamp>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToZero, Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Nearest } }.v] =  TNoesisStaticSamplerState<SF_Bilinear,  AM_Border, AM_Border>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Repeat,      Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Nearest } }.v] =  TNoesisStaticSamplerState<SF_Bilinear,  AM_Wrap,   AM_Wrap>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorU,     Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Nearest } }.v] =  TNoesisStaticSamplerState<SF_Bilinear,  AM_Mirror, AM_Wrap>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorV,     Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Nearest } }.v] =  TNoesisStaticSamplerState<SF_Bilinear,  AM_Wrap,   AM_Mirror>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Mirror,      Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Nearest } }.v] =  TNoesisStaticSamplerState<SF_Bilinear,  AM_Mirror, AM_Mirror>::GetRHI();

	// Can't do linear mip sampling and point UV sampling. We have to choose between SF_Point or SF_Trilinear.
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToZero, Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Linear } }.v] =   TNoesisStaticSamplerState<SF_Point,     AM_Border, AM_Border>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Repeat,      Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Linear } }.v] =   TNoesisStaticSamplerState<SF_Point,     AM_Wrap,   AM_Wrap>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorU,     Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Linear } }.v] =   TNoesisStaticSamplerState<SF_Point,     AM_Mirror, AM_Wrap>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToEdge, Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Linear } }.v] =   TNoesisStaticSamplerState<SF_Point,     AM_Clamp,  AM_Clamp>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorV,     Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Linear } }.v] =   TNoesisStaticSamplerState<SF_Point,     AM_Wrap,   AM_Mirror>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Mirror,      Noesis::MinMagFilter::Nearest, Noesis::MipFilter::Linear } }.v] =   TNoesisStaticSamplerState<SF_Point,     AM_Mirror, AM_Mirror>::GetRHI();

	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToEdge, Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Linear } }.v] =   TNoesisStaticSamplerState<SF_Trilinear, AM_Clamp,  AM_Clamp>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::ClampToZero, Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Linear } }.v] =   TNoesisStaticSamplerState<SF_Trilinear, AM_Border, AM_Border>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Repeat,      Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Linear } }.v] =   TNoesisStaticSamplerState<SF_Trilinear, AM_Wrap,   AM_Wrap>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorU,     Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Linear } }.v] =   TNoesisStaticSamplerState<SF_Trilinear, AM_Mirror, AM_Wrap>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::MirrorV,     Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Linear } }.v] =   TNoesisStaticSamplerState<SF_Trilinear, AM_Wrap,   AM_Mirror>::GetRHI();
	SamplerStates[Noesis::SamplerState{ { Noesis::WrapMode::Mirror,      Noesis::MinMagFilter::Linear,  Noesis::MipFilter::Linear } }.v] =   TNoesisStaticSamplerState<SF_Trilinear, AM_Mirror, AM_Mirror>::GetRHI();
}

FNoesisRenderDevice::~FNoesisRenderDevice()
{
	DynamicVertexBuffer.SafeRelease();
	DynamicIndexBuffer.SafeRelease();
	VSConstantBuffer.SafeRelease();
	TextureSizeBuffer.SafeRelease();
	PSRgbaConstantBuffer.SafeRelease();
	PSOpacityConstantBuffer.SafeRelease();
	PSRadialGradConstantBuffer.SafeRelease();
	BlurConstantsBuffer.SafeRelease();
	ShadowConstantsBuffer.SafeRelease();
	ViewBuffer.SafeRelease();
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
	}
	return NoesisRenderDevice;
}

void FNoesisRenderDevice::Destroy()
{
	delete NoesisRenderDevice;
	NoesisRenderDevice = nullptr;
}

void FNoesisRenderDevice::SetRHICmdList(FRHICommandList* InRHICmdList)
{
	RHICmdList = InRHICmdList;
}

void FNoesisRenderDevice::SetWorldTimes(float InWorldTimeSeconds, float InWorldDeltaSeconds, float InWorldRealTimeSeconds)
{
	WorldTimeSeconds = InWorldTimeSeconds;
	WorldDeltaSeconds = InWorldDeltaSeconds;
	WorldRealTimeSeconds = InWorldRealTimeSeconds;
}

void FNoesisRenderDevice::CreateView(uint32 Left, uint32 Top, uint32 Right, uint32 Bottom)
{
	ViewLeft = Left;
	ViewTop = Top;
	ViewRight = Right;
	ViewBottom = Bottom;

	float Width = Right - Left;
	float Height = Bottom - Top;
	// Matrix construction from FSlateRHIRenderer::CreateProjectionMatrix
	const float ZNear = -100.0f;
	const float ZFar = 100.0f;
	FMatrix Projection = AdjustProjectionMatrixForRHI(
		FMatrix(
			FPlane(2.0f / Width, 0.0f, 0.0f, 0.0f),
			FPlane(0.0f, 2.0f / Height, 0.0f, 0.0f),
			FPlane(0.0f, 0.0f, 1.0f / (ZNear - ZFar), 0.0f),
			FPlane((Left + Right) / -Width, (Top + Bottom) / Height, ZNear / (ZNear - ZFar), 1.0f)
		)
	);
	FSceneViewFamily::ConstructionValues ViewFamilyConstruction
	(
		nullptr,
		nullptr,
		FEngineShowFlags(ESFIM_Game)
	);
	ViewFamilyConstruction.SetWorldTimes(WorldTimeSeconds, WorldDeltaSeconds, WorldRealTimeSeconds);
	/*.SetGammaCorrection(DisplayGamma)
	.SetRealtimeUpdate(true)*/
	FSceneViewFamilyContext Family(ViewFamilyConstruction);
	FSceneViewInitOptions ViewInitOptions;
	memset(&ViewInitOptions, 0, sizeof(ViewInitOptions));
	ViewInitOptions.ViewFamily = &Family;
	ViewInitOptions.SetViewRectangle(FIntRect(Left, Top, Right, Bottom));
	ViewInitOptions.ViewOrigin = FVector::ZeroVector;
	ViewInitOptions.ViewRotationMatrix = FMatrix::Identity;
	ViewInitOptions.ProjectionMatrix = Projection;
	View = new FSceneView(ViewInitOptions);
	FViewUniformShaderParameters ViewUniformShaderParameters;
	ViewUniformShaderParameters.VTFeedbackBuffer = GEmptyVertexBufferWithUAV->UnorderedAccessViewRHI;
	View->SetupCommonViewUniformBufferParameters(
		ViewUniformShaderParameters,
		FIntPoint(Right - Left, Bottom - Top),
		1,
		FIntRect(Left, Top, Right, Bottom),
		View->ViewMatrices,
		FViewMatrices()
	);

	ViewUniformShaderParameters.WorldViewOrigin = View->ViewMatrices.GetViewOrigin();


	ERHIFeatureLevel::Type RHIFeatureLevel = View->GetFeatureLevel();

	ViewUniformShaderParameters.MobilePreviewMode =
		(GIsEditor &&
			(RHIFeatureLevel == ERHIFeatureLevel::ES3_1) &&
			GMaxRHIFeatureLevel > ERHIFeatureLevel::ES3_1) ? 1.0f : 0.0f;

	if (GSystemTextures.PerlinNoiseGradient.GetReference())
	{
		ViewUniformShaderParameters.PerlinNoiseGradientTexture = (FTexture2DRHIRef&)GSystemTextures.PerlinNoiseGradient->GetRenderTargetItem().ShaderResourceTexture;
		SetBlack2DIfNull(ViewUniformShaderParameters.PerlinNoiseGradientTexture);
	}
	check(ViewUniformShaderParameters.PerlinNoiseGradientTexture);
	ViewUniformShaderParameters.PerlinNoiseGradientTextureSampler = TStaticSamplerState<SF_Point, AM_Wrap, AM_Wrap, AM_Wrap>::GetRHI();

	if (GSystemTextures.PerlinNoise3D.GetReference())
	{
		ViewUniformShaderParameters.PerlinNoise3DTexture = (FTexture3DRHIRef&)GSystemTextures.PerlinNoise3D->GetRenderTargetItem().ShaderResourceTexture;
		SetBlack3DIfNull(ViewUniformShaderParameters.PerlinNoise3DTexture);
	}
	check(ViewUniformShaderParameters.PerlinNoise3DTexture);
	ViewUniformShaderParameters.PerlinNoise3DTextureSampler = TStaticSamplerState<SF_Bilinear, AM_Wrap, AM_Wrap, AM_Wrap>::GetRHI();

	if (GSystemTextures.SobolSampling.GetReference())
	{
		ViewUniformShaderParameters.SobolSamplingTexture = (FTexture2DRHIRef&)GSystemTextures.SobolSampling->GetRenderTargetItem().ShaderResourceTexture;
		SetBlack2DIfNull(ViewUniformShaderParameters.SobolSamplingTexture);
	}
	check(ViewUniformShaderParameters.SobolSamplingTexture);

	uint32 Hash = Noesis::HashBytes(&ViewUniformShaderParameters, sizeof(ViewUniformShaderParameters));
	if (ViewHash != Hash)
	{
#if PLATFORM_APPLE
		// UniformBuffers on Metal are broken. They are all treated as Volatile, and new data is not pushed to the GPU after an update.
		ViewBuffer = TUniformBufferRef<FViewUniformShaderParameters>::CreateUniformBufferImmediate(ViewUniformShaderParameters, UniformBuffer_SingleFrame);
#else
		RHIUpdateUniformBuffer(ViewBuffer, &ViewUniformShaderParameters);
#endif
		ViewHash = Hash;
	}
}

void FNoesisRenderDevice::DestroyView()
{
	delete View;
	View = nullptr;
}

static void SetTextureFormat(FNoesisTexture* Texture, EPixelFormat Format)
{
	switch (Format)
	{
		case PF_R8G8B8A8:
			Texture->Format = Texture->HasAlpha() ? Noesis::TextureFormat::RGBA8 : Noesis::TextureFormat::RGBX8;
			break;
		case PF_G8:
			Texture->Format = Noesis::TextureFormat::R8;
			break;
	}
}

Noesis::Ptr<Noesis::Texture> FNoesisRenderDevice::CreateTexture(UTexture* InTexture)
{
#if (ENGINE_MAJOR_VERSION >= 5) || ((ENGINE_MAJOR_VERSION == 4) && (ENGINE_MINOR_VERSION >= 27))
	if (!InTexture || !InTexture->GetResource())
		return nullptr;

	FTextureResource* TextureResource = InTexture->GetResource();
#else
	if (!InTexture || !InTexture->Resource)
		return nullptr;

	FTextureResource* TextureResource = InTexture->Resource;
#endif

	Noesis::Ptr<FNoesisTexture> Texture;
	if (InTexture->IsA<UTexture2D>())
	{
		UTexture2D* Texture2D = (UTexture2D*)InTexture;
		Texture = *new FNoesisTexture(Texture2D);
		FTexture2DResource* Resource = (FTexture2DResource*)TextureResource;
		// Usually the RHI resource is ready when we create the texture.
		// However, when we are hot-reloading a texture, UE4 enqueues the
		// creation to the render thread, so we must do the same.
		ENQUEUE_RENDER_COMMAND(FNoesisInstance_InitRenderer)
		(
			[Texture, Resource](FRHICommandListImmediate&)
			{
				FTexture2DRHIRef TextureRef = Resource->GetTexture2DRHI();
				if (TextureRef)
				{
					check(Texture->Width == TextureRef->GetSizeX());
					check(Texture->Height == TextureRef->GetSizeY());
					check(Texture->NumMipMaps == TextureRef->GetNumMips());
					Texture->ShaderResourceTexture = TextureRef;
					SetTextureFormat(Texture, TextureRef->GetFormat());
				}
			}
		);
	}
	else if (InTexture->IsA<UTextureRenderTarget2D>())
	{
		FTexture2DRHIRef TextureRef = ((FTextureRenderTarget2DResource*)TextureResource)->GetTextureRHI();
		if (!TextureRef)
		{
			return nullptr;
		}
		UTextureRenderTarget2D* TextureRenderTarget2D = (UTextureRenderTarget2D*)InTexture;
		Texture = *new FNoesisTexture(TextureRenderTarget2D);
		check(Texture->Width == TextureRef->GetSizeX());
		check(Texture->Height == TextureRef->GetSizeY());
		check(Texture->NumMipMaps == TextureRef->GetNumMips());
		Texture->ShaderResourceTexture = TextureRef;
		SetTextureFormat(Texture, TextureRef->GetFormat());
	}
	else if (InTexture->IsA<UMediaTexture>())
	{
		FTextureResource* Resource = (FTextureResource*)TextureResource;
		FTextureRHIRef TextureRHI = Resource->TextureRHI;
		if (!TextureRHI)
		{
			return nullptr;
		}
		FTexture2DRHIRef TextureRef = TextureRHI->GetTexture2D();
		if (!TextureRef)
		{
			return nullptr;
		}
		UMediaTexture* MediaTexture = (UMediaTexture*)InTexture;
		Texture = *new FNoesisTexture(MediaTexture);
		check(Texture->Width == TextureRef->GetSizeX());
		check(Texture->Height == TextureRef->GetSizeY());
		check(Texture->NumMipMaps == TextureRef->GetNumMips());
		Texture->ShaderResourceTexture = TextureRef;
		SetTextureFormat(Texture, TextureRef->GetFormat());
	}
	else
	{
		return nullptr;
	}

	return Texture;
}

void* FNoesisRenderDevice::CreateMaterial(UMaterialInterface* InMaterial)
{
	if (!InMaterial)
		return nullptr;

	FNoesisMaterial* Material = new FNoesisMaterial(InMaterial);
	return Material;
}

void FNoesisRenderDevice::DestroyMaterial(void* InMaterial)
{
	if (!InMaterial)
		return;

	FNoesisMaterial* Material = (FNoesisMaterial*)InMaterial;
	ENQUEUE_RENDER_COMMAND(FNoesisDestroyMaterial)
	(
		[Material](FRHICommandListImmediate&)
		{
			delete Material;
		}
	);
}

const Noesis::DeviceCaps& FNoesisRenderDevice::GetCaps() const
{
	static Noesis::DeviceCaps Caps = { 0.f, false, false };
	return Caps;
}

static void NoesisCreateTargetableShaderResource2D(
	uint32 SizeX,
	uint32 SizeY,
	uint8 Format,
	uint32 NumMips,
	ETextureCreateFlags Flags,
	ETextureCreateFlags TargetableTextureFlags,
	bool bForceSeparateTargetAndShaderResource,
	bool bForceSharedTargetAndShaderResource,
	FRHIResourceCreateInfo& CreateInfo,
	FTexture2DRHIRef& OutTargetableTexture,
	FTexture2DRHIRef& OutShaderResourceTexture,
	uint32 NumSamples = 1
)
{
	// Ensure none of the usage flags are passed in.
	check(!EnumHasAnyFlags(Flags, TexCreate_RenderTargetable | TexCreate_ResolveTargetable));

	// Ensure we aren't forcing separate and shared textures at the same time.
	check(!(bForceSeparateTargetAndShaderResource && bForceSharedTargetAndShaderResource));

	// Ensure that the targetable texture is either render or depth-stencil targetable.
	check(EnumHasAnyFlags(TargetableTextureFlags, TexCreate_RenderTargetable | TexCreate_DepthStencilTargetable | TexCreate_UAV));

	if (NumSamples > 1 && !bForceSharedTargetAndShaderResource)
	{
		bForceSeparateTargetAndShaderResource = RHISupportsSeparateMSAAAndResolveTextures(GMaxRHIShaderPlatform);
	}

	if (!bForceSeparateTargetAndShaderResource)
	{
		// Create a single texture that has both TargetableTextureFlags and TexCreate_ShaderResource set.
		OutTargetableTexture = OutShaderResourceTexture = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, NumSamples, Flags | TargetableTextureFlags | TexCreate_ShaderResource, ERHIAccess::SRVGraphics, CreateInfo);
	}
	else
	{
		ETextureCreateFlags ResolveTargetableTextureFlags = TexCreate_ResolveTargetable;
		if (EnumHasAnyFlags(TargetableTextureFlags, TexCreate_DepthStencilTargetable))
		{
			ResolveTargetableTextureFlags |= TexCreate_DepthStencilResolveTarget;
		}
		// Create a texture that has TargetableTextureFlags set, and a second texture that has TexCreate_ResolveTargetable and TexCreate_ShaderResource set.
		OutTargetableTexture = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, NumSamples, Flags | TargetableTextureFlags, ERHIAccess::RTV, CreateInfo);
		OutShaderResourceTexture = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, 1, Flags | ResolveTargetableTextureFlags | TexCreate_ShaderResource, ERHIAccess::SRVGraphics, CreateInfo);
	}
}

static Noesis::Ptr<Noesis::RenderTarget> CreateRenderTarget(const char* Label, uint32 Width, uint32 Height, uint32 SampleCount, FTexture2DRHIRef DepthStencilTarget)
{
	uint8 Format = (uint8)PF_R8G8B8A8;
	uint32 NumMips = 1;
	ETextureCreateFlags Flags = TexCreate_None;
	ETextureCreateFlags TargetableTextureFlags = TexCreate_RenderTargetable;
	bool bForceSeparateTargetAndShaderResource = false;
	FRHIResourceCreateInfo CreateInfo(TEXT("Noesis.RenderTarget"));
	FTexture2DRHIRef ColorTarget;
	FTexture2DRHIRef ShaderResourceTexture;
	NoesisCreateTargetableShaderResource2D(Width, Height, Format, NumMips, Flags, TargetableTextureFlags, bForceSeparateTargetAndShaderResource, false, CreateInfo, ColorTarget, ShaderResourceTexture, SampleCount);

	FNoesisRenderTarget* RenderTarget = new FNoesisRenderTarget();
	RenderTarget->Texture = *new FNoesisTexture(Width, Height, NumMips, true);
	RenderTarget->ColorTarget = ColorTarget;
	RenderTarget->Texture->ShaderResourceTexture = ShaderResourceTexture;
	RenderTarget->Texture->Format = Noesis::TextureFormat::RGBA8;
	RenderTarget->DepthStencilTarget = DepthStencilTarget;

	FName TextureName = FName(Label);
	ColorTarget->SetName(TextureName);
	ShaderResourceTexture->SetName(TextureName);

	return Noesis::Ptr<Noesis::RenderTarget>(*RenderTarget);
}

Noesis::Ptr<Noesis::RenderTarget> FNoesisRenderDevice::CreateRenderTarget(const char* Label, uint32 Width, uint32 Height, uint32 SampleCount, bool NeedsStencil)
{
	FTexture2DRHIRef DepthStencilTarget;

	if (NeedsStencil)
	{
		uint32 NumMips = 1;
		uint8 Format = (uint8)PF_DepthStencil;
		ETextureCreateFlags TargetableTextureFlags = TexCreate_DepthStencilTargetable;
		ERHIAccess Access = ERHIAccess::DSVWrite;
		FRHIResourceCreateInfo CreateInfo(TEXT("Noesis.RenderTarget"));
		CreateInfo.ClearValueBinding = FClearValueBinding(0.f, 0);
		DepthStencilTarget = RHICreateTexture2D(Width, Height, Format, NumMips, SampleCount, TargetableTextureFlags, Access, CreateInfo);

		FName TextureName = FName(Label);
		DepthStencilTarget->SetName(TextureName);
	}

	return ::CreateRenderTarget(Label, Width, Height, SampleCount, DepthStencilTarget);
}

Noesis::Ptr<Noesis::RenderTarget> FNoesisRenderDevice::CloneRenderTarget(const char* Label, Noesis::RenderTarget* InSharedRenderTarget)
{
	FNoesisRenderTarget* SharedRenderTarget = (FNoesisRenderTarget*)InSharedRenderTarget;

	uint32 Width = SharedRenderTarget->ColorTarget->GetSizeX();
	uint32 Height = SharedRenderTarget->ColorTarget->GetSizeY();
	uint32 SampleCount = SharedRenderTarget->ColorTarget->GetNumSamples();
	FTexture2DRHIRef DepthStencilTarget = SharedRenderTarget->DepthStencilTarget;

	return ::CreateRenderTarget(Label, Width, Height, SampleCount, DepthStencilTarget);
}

Noesis::Ptr<Noesis::Texture> FNoesisRenderDevice::CreateTexture(const char* Label, uint32 Width, uint32 Height, uint32 NumLevels, Noesis::TextureFormat::Enum TextureFormat, const void** Data)
{
	uint32 SizeX = (uint32)Width;
	uint32 SizeY = (uint32)Height;
	EPixelFormat Formats[Noesis::TextureFormat::Count] = { PF_R8G8B8A8, PF_R8G8B8A8, PF_G8 };
	uint8 Format = (uint8)Formats[TextureFormat];
	uint32 NumMips = (uint32)NumLevels;
	uint32 NumSamples = 1;
	ETextureCreateFlags Flags = TexCreate_None;
	ERHIAccess Access = ERHIAccess::SRVGraphics;
	FRHIResourceCreateInfo CreateInfo(TEXT("Noesis.Texture"));
	FTexture2DRHIRef ShaderResourceTexture = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, NumSamples, Flags, Access, CreateInfo);

	FNoesisTexture* Texture = new FNoesisTexture(SizeX, SizeY, NumMips, TextureFormat == Noesis::TextureFormat::RGBA8);
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

void FNoesisRenderDevice::BeginOffscreenRender()
{
	RHICmdList->SetScissorRect(false, 0, 0, 0, 0);
}

void FNoesisRenderDevice::EndOffscreenRender()
{
}

void FNoesisRenderDevice::BeginOnscreenRender()
{
	RHICmdList->SetScissorRect(false, 0, 0, 0, 0);
}

void FNoesisRenderDevice::EndOnscreenRender()
{
}

void FNoesisRenderDevice::SetRenderTarget(Noesis::RenderTarget* Surface)
{
	check(RHICmdList);
#if WANTS_DRAW_MESH_EVENTS
	SetRenderTargetEvent = new FDrawEvent();
	BEGIN_DRAW_EVENTF(*RHICmdList, SetRenderTarget, (*SetRenderTargetEvent), TEXT("SetRenderTarget"));
#endif
	check(Surface);
	FNoesisRenderTarget* RenderTarget = (FNoesisRenderTarget*)Surface;
	ERenderTargetActions ColorTargetActions = ERenderTargetActions::DontLoad_Store;

	EDepthStencilTargetActions DepthStencilTargetActions =
		MakeDepthStencilTargetActions(ERenderTargetActions::DontLoad_DontStore, ERenderTargetActions::DontLoad_DontStore);

	check(RHICmdList->IsOutsideRenderPass());
	if (RenderTarget->ColorTarget == RenderTarget->Texture->ShaderResourceTexture)
	{
		RHICmdList->Transition(FRHITransitionInfo(RenderTarget->ColorTarget, ERHIAccess::SRVGraphics, ERHIAccess::RTV));
	}

	if (RenderTarget->DepthStencilTarget)
	{
		FRHIRenderPassInfo RPInfo(RenderTarget->ColorTarget, ColorTargetActions, nullptr,
			RenderTarget->DepthStencilTarget, DepthStencilTargetActions, nullptr, FExclusiveDepthStencil::DepthNop_StencilWrite);
		RHICmdList->BeginRenderPass(RPInfo, TEXT("NoesisOffScreen"));
	}
	else
	{
		FRHIRenderPassInfo RPInfo(RenderTarget->ColorTarget, ColorTargetActions, nullptr);
		RHICmdList->BeginRenderPass(RPInfo, TEXT("NoesisOffScreen"));
	}
	RHICmdList->SetViewport(0, 0, 0.0f, RenderTarget->ColorTarget->GetSizeX(), RenderTarget->ColorTarget->GetSizeY(), 1.0f);

	CreateView(0, 0, RenderTarget->ColorTarget->GetSizeX(), RenderTarget->ColorTarget->GetSizeY());
}

void FNoesisRenderDevice::ResolveRenderTarget(Noesis::RenderTarget* Surface, const Noesis::Tile* Tiles, uint32 NumTiles)
{
	check(RHICmdList);
	check(RHICmdList->IsInsideRenderPass());
	SCOPED_DRAW_EVENT(*RHICmdList, Resolve);
	FNoesisRenderTarget* RenderTarget = (FNoesisRenderTarget*)Surface;
	RHICmdList->EndRenderPass();
	if (RenderTarget->ColorTarget != RenderTarget->Texture->ShaderResourceTexture)
	{
		for (uint32 TileIndex = 0; TileIndex != (uint32)NumTiles; ++TileIndex)
		{
			const Noesis::Tile& Tile = Tiles[TileIndex];

			uint32 ResolveMinX = Tile.x;
			uint32 ResolveMinY = RenderTarget->Texture->ShaderResourceTexture->GetSizeY() - (Tile.y + Tile.height);
			uint32 ResolveMaxX = Tile.x + Tile.width;
			uint32 ResolveMaxY = RenderTarget->Texture->ShaderResourceTexture->GetSizeY() - Tile.y;

			FResolveParams ResolveParams;
			ResolveParams.Rect.X1 = ResolveMinX;
			ResolveParams.Rect.Y1 = ResolveMinY;
			ResolveParams.Rect.X2 = ResolveMaxX;
			ResolveParams.Rect.Y2 = ResolveMaxY;
			ResolveParams.DestRect.X1 = ResolveMinX;
			ResolveParams.DestRect.Y1 = ResolveMinY;
			ResolveParams.DestRect.X2 = ResolveMaxX;
			ResolveParams.DestRect.Y2 = ResolveMaxY;
			ResolveParams.MipIndex = 0;
			ResolveParams.SourceArrayIndex = 0;
			ResolveParams.DestArrayIndex = 0;
			ResolveParams.SourceAccessFinal = ERHIAccess::RTV;
			ResolveParams.DestAccessFinal = ERHIAccess::SRVGraphics;
			RHICmdList->CopyToResolveTarget(RenderTarget->ColorTarget, RenderTarget->Texture->ShaderResourceTexture, ResolveParams);
		}
	}
	else
	{
		RHICmdList->Transition(FRHITransitionInfo(RenderTarget->ColorTarget, ERHIAccess::RTV, ERHIAccess::SRVGraphics));
	}

#if WANTS_DRAW_MESH_EVENTS
	STOP_DRAW_EVENT((*SetRenderTargetEvent));
#endif

	DestroyView();
}

void* FNoesisRenderDevice::MapVertices(uint32 Bytes)
{
#if ENGINE_MAJOR_VERSION >= 5
	void* Result = RHILockBuffer(DynamicVertexBuffer, 0, Bytes, RLM_WriteOnly);
#else
	void* Result = RHILockVertexBuffer(DynamicVertexBuffer, 0, Bytes, RLM_WriteOnly);
#endif
	return Result;
}

void FNoesisRenderDevice::UnmapVertices()
{
#if ENGINE_MAJOR_VERSION >= 5
	RHIUnlockBuffer(DynamicVertexBuffer);
#else
	RHIUnlockVertexBuffer(DynamicVertexBuffer);
#endif
}

void* FNoesisRenderDevice::MapIndices(uint32 Bytes)
{
#if ENGINE_MAJOR_VERSION >= 5
	void* Result = RHILockBuffer(DynamicIndexBuffer, 0, Bytes, RLM_WriteOnly);
#else
	void* Result = RHILockIndexBuffer(DynamicIndexBuffer, 0, Bytes, RLM_WriteOnly);
#endif
	return Result;
}

void FNoesisRenderDevice::UnmapIndices()
{
#if ENGINE_MAJOR_VERSION >= 5
	RHIUnlockBuffer(DynamicIndexBuffer);
#else
	RHIUnlockIndexBuffer(DynamicIndexBuffer);
#endif
}

template<>
void FNoesisRenderDevice::SetPatternMaterialParameters<FNoesisPSBase>(const Noesis::Batch& Batch, TShaderRef<FNoesisPSBase>& PixelShader)
{
	if (Batch.pattern != nullptr)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.pattern);
		FRHITexture* PatternTexture = Texture->ShaderResourceTexture;
		FRHISamplerState* PatternSamplerState = SamplerStates[Batch.patternSampler.v];
		PixelShader->SetPatternTexture(*RHICmdList, PatternTexture, PatternSamplerState);
	}
}

template<>
void FNoesisRenderDevice::SetPatternMaterialParameters<FNoesisMaterialPSBase>(const Noesis::Batch& Batch, TShaderRef<FNoesisMaterialPSBase>& PixelShader)
{
	FMaterialRenderProxy* MaterialProxy = ((FNoesisMaterial*)Batch.pixelShader)->MaterialProxy;
#if (ENGINE_MAJOR_VERSION >= 5) || ((ENGINE_MAJOR_VERSION == 4) && (ENGINE_MINOR_VERSION >= 27))
	const FMaterial* Material = &MaterialProxy->GetIncompleteMaterialWithFallback(GMaxRHIFeatureLevel);
#else
	const FMaterial* Material = MaterialProxy->GetMaterial(GMaxRHIFeatureLevel);
#endif
	FRHIPixelShader* ShaderRHI = RHICmdList->GetBoundPixelShader();
	PixelShader->SetViewParameters(*RHICmdList, ShaderRHI, *View, ViewBuffer);
	PixelShader->SetParameters<FRHIPixelShader>(*RHICmdList, ShaderRHI, MaterialProxy, *Material, *View);
}

template<class PixelShaderClass>
void FNoesisRenderDevice::SetPixelShaderParameters(const Noesis::Batch& Batch, TShaderRef<PixelShaderClass>& BasePixelShader, FUniformBufferRHIRef& PSUniformBuffer0, FUniformBufferRHIRef& PSUniformBuffer1)
{
	TShaderRef<PixelShaderClass> PixelShader = TShaderRef<PixelShaderClass>::Cast(BasePixelShader);
	if (Batch.pixelUniforms[0].values != nullptr)
	{
		PixelShader->SetPSConstants(*RHICmdList, PSUniformBuffer0);
	}

	if (Batch.pixelUniforms[1].values != nullptr)
	{
		PixelShader->SetEffects(*RHICmdList, PSUniformBuffer1);
	}

	SetPatternMaterialParameters(Batch, PixelShader);

	if (Batch.ramps != nullptr)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.ramps);
		FRHITexture* RampsTexture = Texture->ShaderResourceTexture;
		FRHISamplerState* RampsSamplerState = SamplerStates[Batch.rampsSampler.v];
		PixelShader->SetRampsTexture(*RHICmdList, RampsTexture, RampsSamplerState);
	}

	if (Batch.image != nullptr)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.image);
		FRHITexture* ImageTexture = Texture->ShaderResourceTexture;
		FRHISamplerState* ImageSamplerState = SamplerStates[Batch.imageSampler.v];
		PixelShader->SetImageTexture(*RHICmdList, ImageTexture, ImageSamplerState);
	}

	if (Batch.glyphs != nullptr)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.glyphs);
		FRHITexture* GlyphsTexture = Texture->ShaderResourceTexture;
		FRHISamplerState* GlyphsSamplerState = SamplerStates[Batch.glyphsSampler.v];
		PixelShader->SetGlyphsTexture(*RHICmdList, GlyphsTexture, GlyphsSamplerState);
	}

	if (Batch.shadow != nullptr)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.shadow);
		FRHITexture* ShadowTexture = Texture->ShaderResourceTexture;
		FRHISamplerState* ShadowSamplerState = SamplerStates[Batch.shadowSampler.v];
		PixelShader->SetShadowTexture(*RHICmdList, ShadowTexture, ShadowSamplerState);
	}
}

template<>
void FNoesisRenderDevice::SetPixelShaderParameters<FNoesisCustomEffectPS>(const Noesis::Batch& Batch, TShaderRef<FNoesisCustomEffectPS>& PixelShader, FUniformBufferRHIRef& PSUniformBuffer0, FUniformBufferRHIRef& PSUniformBuffer1)
{
	FMaterialRenderProxy* MaterialProxy = ((FNoesisMaterial*)Batch.pixelShader)->MaterialProxy;
#if (ENGINE_MAJOR_VERSION >= 5) || ((ENGINE_MAJOR_VERSION == 4) && (ENGINE_MINOR_VERSION >= 27))
	const FMaterial* Material = &MaterialProxy->GetIncompleteMaterialWithFallback(GMaxRHIFeatureLevel);
#else
	const FMaterial* Material = MaterialProxy->GetMaterial(GMaxRHIFeatureLevel);
#endif
	FRHIPixelShader* ShaderRHI = RHICmdList->GetBoundPixelShader();
	PixelShader->SetViewParameters(*RHICmdList, ShaderRHI, *View, ViewBuffer);

	FNoesisTexture* Texture = (FNoesisTexture*)(Batch.pattern);
	FRHITexture* PatternTexture = Texture->ShaderResourceTexture;
	//FRHISamplerState* PatternSamplerState = SamplerStates[Batch.patternSampler.v];
	FRHISamplerState* PatternSamplerState = TStaticSamplerState<SF_Point, AM_Clamp, AM_Clamp>::GetRHI(); // This should be point samplig for the behavior to be the same as UE4's
	FNoesisPostProcessMaterialParameters Params = {};
	Params.View = ViewBuffer;
	Params.PostProcessInput_BilinearSampler = TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Clamp>::GetRHI();
	Params.PostProcessInput_0_Texture = PatternTexture;
	Params.PostProcessInput_0_Sampler = PatternSamplerState;
	// Texture extent in pixels.
	{
		const FVector2D Extent(Texture->GetWidth(), Texture->GetHeight());
		const FVector2D ViewportMin(0.0f, 0.0f);
		const FVector2D ViewportMax(Texture->GetWidth(), Texture->GetHeight());
		const FVector2D ViewportSize = ViewportMax - ViewportMin;

		FScreenPassTextureViewportParameters& Viewport = Params.PostProcessInput_1.Viewport;

		Viewport.Extent = Extent;
		Viewport.ExtentInverse = FVector2D(1.0f / Extent.X, 1.0f / Extent.Y);

		Viewport.ScreenPosToViewportScale = FVector2D(0.5f, -0.5f) * ViewportSize;
		Viewport.ScreenPosToViewportBias = (0.5f * ViewportSize) + ViewportMin;

		Viewport.ViewportMin = FIntPoint(0, 0);
		Viewport.ViewportMax = FIntPoint(Texture->GetWidth(), Texture->GetHeight());

		Viewport.ViewportSize = ViewportSize;
		Viewport.ViewportSizeInverse = FVector2D(1.0f / Viewport.ViewportSize.X, 1.0f / Viewport.ViewportSize.Y);

		Viewport.UVViewportMin = ViewportMin * Viewport.ExtentInverse;
		Viewport.UVViewportMax = ViewportMax * Viewport.ExtentInverse;

		Viewport.UVViewportSize = Viewport.UVViewportMax - Viewport.UVViewportMin;
		Viewport.UVViewportSizeInverse = FVector2D(1.0f / Viewport.UVViewportSize.X, 1.0f / Viewport.UVViewportSize.Y);

		Viewport.UVViewportBilinearMin = Viewport.UVViewportMin + 0.5f * Viewport.ExtentInverse;
		Viewport.UVViewportBilinearMax = Viewport.UVViewportMax - 0.5f * Viewport.ExtentInverse;
	}

	{
		const FVector2D Extent(ViewRight - ViewLeft, ViewBottom - ViewTop);
		const FVector2D ViewportMin(ViewLeft, ViewTop);
		const FVector2D ViewportMax(ViewRight, ViewBottom);
		const FVector2D ViewportSize = ViewportMax - ViewportMin;

		FScreenPassTextureViewportParameters& Viewport = Params.PostProcessOutput;

		Viewport.Extent = Extent;
		Viewport.ExtentInverse = FVector2D(1.0f / Extent.X, 1.0f / Extent.Y);

		Viewport.ScreenPosToViewportScale = FVector2D(0.5f, -0.5f) * ViewportSize;
		Viewport.ScreenPosToViewportBias = (0.5f * ViewportSize) + ViewportMin;

		Viewport.ViewportMin = FIntPoint(ViewLeft, ViewTop);
		Viewport.ViewportMax = FIntPoint(ViewRight, ViewBottom);

		Viewport.ViewportSize = ViewportSize;
		Viewport.ViewportSizeInverse = FVector2D(1.0f / Viewport.ViewportSize.X, 1.0f / Viewport.ViewportSize.Y);

		Viewport.UVViewportMin = ViewportMin * Viewport.ExtentInverse;
		Viewport.UVViewportMax = ViewportMax * Viewport.ExtentInverse;

		Viewport.UVViewportSize = Viewport.UVViewportMax - Viewport.UVViewportMin;
		Viewport.UVViewportSizeInverse = FVector2D(1.0f / Viewport.UVViewportSize.X, 1.0f / Viewport.UVViewportSize.Y);

		Viewport.UVViewportBilinearMin = Viewport.UVViewportMin + 0.5f * Viewport.ExtentInverse;
		Viewport.UVViewportBilinearMax = Viewport.UVViewportMax - 0.5f * Viewport.ExtentInverse;
	}

	PixelShader->SetParameters(*RHICmdList, PixelShader, *View, MaterialProxy, Params);
}


void FNoesisRenderDevice::DrawBatch(const Noesis::Batch& Batch)
{
	check(RHICmdList);
	FGraphicsPipelineStateInitializer GraphicsPSOInit;
	RHICmdList->ApplyCachedRenderTargets(GraphicsPSOInit);

	GraphicsPSOInit.DepthStencilState = DepthStencilStates[Batch.renderState.f.stencilMode];

	GraphicsPSOInit.BlendState = Batch.renderState.f.colorEnable ? BlendStates[Batch.renderState.f.blendMode] : TStaticBlendState<CW_NONE>::GetRHI();

	GraphicsPSOInit.RasterizerState = Batch.renderState.f.wireframe ? TStaticRasterizerState<FM_Wireframe, CM_None>::GetRHI() : TStaticRasterizerState<FM_Solid, CM_None>::GetRHI();

	Noesis::Shader::Enum ShaderCode = (Noesis::Shader::Enum)Batch.shader.v;

	bool UsingMaterialShader = Batch.pixelShader != nullptr;
	bool UsingCustomEffect = ShaderCode == Noesis::Shader::Custom_Effect;
	TShaderRef<FNoesisMaterialPSBase> MaterialPixelShader;
	TShaderRef<FNoesisCustomEffectPS> CustomEffectPixelShader;
	if (UsingMaterialShader)
	{
		FMaterialRenderProxy* MaterialProxy = ((FNoesisMaterial*)Batch.pixelShader)->MaterialProxy;
		if (MaterialProxy != nullptr)
		{
#if (ENGINE_MAJOR_VERSION >= 5) || ((ENGINE_MAJOR_VERSION == 4) && (ENGINE_MINOR_VERSION >= 27))
			const FMaterial* Material = &MaterialProxy->GetIncompleteMaterialWithFallback(GMaxRHIFeatureLevel);
#else
			const FMaterial* Material = MaterialProxy->GetMaterial(GMaxRHIFeatureLevel);
#endif
			if (UsingCustomEffect)
			{
				UsingMaterialShader = false;
				const FMaterialShaderMap* MaterialShaderMap = Material->GetRenderingThreadShaderMap();
				CustomEffectPixelShader = MaterialShaderMap->GetShader<FNoesisCustomEffectPS>();
			}
			else
			{
				MaterialPixelShader = GetMaterialPixelShader(Material, ShaderCode);
			}
		}
	}

	bool PatternSRGB = false;
	if (Batch.pattern != nullptr)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.pattern);
		FRHITexture* PatternTexture = Texture->ShaderResourceTexture;
		if (PatternTexture != nullptr && EnumHasAnyFlags(PatternTexture->GetFlags(), TexCreate_SRGB))
		{
			// Read the comment next to PATTERN_SRGB in FNoesisPS::ModifyCompilationEnvironment
			PatternSRGB = true;
		}
	}

	FVertexDeclarationRHIRef& VertexDeclaration = VertexDeclarations[ShaderCode];
	TShaderRef<FNoesisVSBase> VertexShader = VertexShaders[ShaderCode];
	TShaderRef<FNoesisPSBase> PixelShader = PatternSRGB ? PixelShadersPatternSRGB[ShaderCode] : PixelShaders[ShaderCode];
	FUniformBufferRHIRef& PSUniformBuffer0 = *PixelShaderConstantBuffer0[ShaderCode];
	FUniformBufferRHIRef& PSUniformBuffer1 = *PixelShaderConstantBuffer1[ShaderCode];
	GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = VertexDeclaration;
	GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
	GraphicsPSOInit.BoundShaderState.PixelShaderRHI = UsingCustomEffect ? CustomEffectPixelShader.GetPixelShader() : (UsingMaterialShader ? MaterialPixelShader.GetPixelShader() : PixelShader.GetPixelShader());
	GraphicsPSOInit.PrimitiveType = PT_TriangleList;

	// This can happen when the shaders are being recompiled in the editor.
	if (!VertexShader.IsValid())
		return;

	if (UsingCustomEffect && !CustomEffectPixelShader.IsValid())
		return;
	else if (UsingMaterialShader && !MaterialPixelShader.IsValid())
		return;
	else if (!UsingCustomEffect && !UsingMaterialShader && !PixelShader.IsValid())
		return;

	SetGraphicsPipelineState(*RHICmdList, GraphicsPSOInit);

	// Update the uniform buffers
	if (VSConstantsHash != Batch.vertexUniforms[0].hash)
	{
		uint32 Size = Batch.vertexUniforms[0].numDwords * 4;
		void* VSConstants = FMemory_Alloca(Size);
		FMemory::Memcpy(VSConstants, Batch.vertexUniforms[0].values, Size);
		check((Batch.vertexUniforms[0].numDwords * 4) == sizeof(FNoesisVSConstants));
#if PLATFORM_APPLE
		// UniformBuffers on Metal are broken. They are all treated as Volatile, and new data is not pushed to the GPU after an update.
		VSConstantBuffer = RHICreateUniformBuffer(VSConstants, VSConstantBuffer->GetLayout(), UniformBuffer_MultiFrame, EUniformBufferValidation::ValidateResources);
#else
		RHIUpdateUniformBuffer(VSConstantBuffer, VSConstants);
#endif
		VSConstantsHash = Batch.vertexUniforms[0].hash;
	}

	if (Batch.vertexUniforms[1].values != nullptr)
	{
		if (TextureSizeHash != Batch.vertexUniforms[1].hash)
		{
			uint32 Size = Batch.vertexUniforms[1].numDwords * 4;
			void* TextureSize = FMemory_Alloca(Size);
			FMemory::Memcpy(TextureSize, Batch.vertexUniforms[1].values, Size);
#if PLATFORM_APPLE
			// UniformBuffers on Metal are broken. They are all treated as Volatile, and new data is not pushed to the GPU after an update.
			TextureSizeBuffer = RHICreateUniformBuffer(TextureSize, TextureSizeBuffer->GetLayout(), UniformBuffer_MultiFrame, EUniformBufferValidation::ValidateResources);
#else
			RHIUpdateUniformBuffer(TextureSizeBuffer, TextureSize);
#endif
			TextureSizeHash = Batch.vertexUniforms[1].hash;
		}
	}

	if (Batch.pixelUniforms[0].values != nullptr)
	{
		check(PSUniformBuffer0 != nullptr);
		if (PSConstantsHash != Batch.pixelUniforms[0].hash)
		{
			uint32 Size = Batch.pixelUniforms[0].numDwords * 4;
			void* PSConstants = FMemory_Alloca(Size);
			FMemory::Memcpy(PSConstants, Batch.pixelUniforms[0].values, Size);
#if PLATFORM_APPLE
			// UniformBuffers on Metal are broken. They are all treated as Volatile, and new data is not pushed to the GPU after an update.
			PSUniformBuffer0 = RHICreateUniformBuffer(PSConstants, PSUniformBuffer0->GetLayout(), UniformBuffer_MultiFrame, EUniformBufferValidation::ValidateResources);
#else
			RHIUpdateUniformBuffer(PSUniformBuffer0, PSConstants);
#endif
			PSConstantsHash = Batch.pixelUniforms[0].hash;
		}
	}

	if (Batch.pixelUniforms[1].values != nullptr)
	{
		check(PSUniformBuffer1 != nullptr);
		if (EffectsHash != Batch.pixelUniforms[1].hash)
		{
			uint32 Size = Batch.pixelUniforms[1].numDwords * 4;
			void* PSConstants = FMemory_Alloca(Size);
			FMemory::Memcpy(PSConstants, Batch.pixelUniforms[1].values, Size);
#if PLATFORM_APPLE
			// UniformBuffers on Metal are broken. They are all treated as Volatile, and new data is not pushed to the GPU after an update.
			PSUniformBuffer1 = RHICreateUniformBuffer(PSConstants, PSUniformBuffer1->GetLayout(), UniformBuffer_MultiFrame, EUniformBufferValidation::ValidateResources);
#else
			RHIUpdateUniformBuffer(PSUniformBuffer1, PSConstants);
#endif
			EffectsHash = Batch.pixelUniforms[1].hash;
		}
	}

	VertexShader->SetVSConstants(*RHICmdList, VSConstantBuffer);

	if (Batch.vertexUniforms[1].values != nullptr)
	{
		VertexShader->SetTextureSize(*RHICmdList, TextureSizeBuffer);
	}

	if (UsingCustomEffect)
	{
		SetPixelShaderParameters(Batch, CustomEffectPixelShader, PSUniformBuffer0, PSUniformBuffer1);
	}
	else if (UsingMaterialShader)
	{
		SetPixelShaderParameters(Batch, MaterialPixelShader, PSUniformBuffer0, PSUniformBuffer1);
	}
	else
	{
		SetPixelShaderParameters(Batch, PixelShader, PSUniformBuffer0, PSUniformBuffer1);
	}

	RHICmdList->SetStencilRef(Batch.stencilRef);
	RHICmdList->SetStreamSource(0, DynamicVertexBuffer, Batch.vertexOffset);

	RHICmdList->DrawIndexedPrimitive(DynamicIndexBuffer, 0, 0, Batch.numVertices, Batch.startIndex, Batch.numIndices / 3, 1);
}
