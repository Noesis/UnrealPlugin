////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisRenderDevice.h"

// Engine includes
#include "EngineModule.h"
#include "Engine/Texture2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Rendering/Texture2DResource.h"
#include "Materials/Material.h"
#if UE_VERSION_OLDER_THAN(5, 2, 0)
#include "MaterialShared.h"
#else
#include "Materials/MaterialRenderProxy.h"
#endif
#include "SceneView.h"

// RHI includes
#include "RHI.h"
#include "RHICommandList.h"
#include "RHIStaticStates.h"
#include "PipelineStateCache.h"
#if UE_VERSION_OLDER_THAN(5, 2, 0)
#include "RHIDefinitions.h"
#else
#include "DataDrivenShaderPlatformInfo.h"
#endif

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
	uint32 Width;
	uint32 Height;
	uint32 NumMipMaps;
	bool Alpha;
};

#if UE_VERSION_OLDER_THAN(5, 0, 0)
typedef FTicker FTSTicker;
#endif

class FNoesisMaterial
{
public:
	FNoesisMaterial(UMaterialInterface* InMaterial)
#if WITH_EDITOR
		: MaterialPtr(InMaterial)
#endif
	{
		MaterialProxy = InMaterial->GetRenderProxy();
#if WITH_EDITOR
		// We need this in the editor to account for material recompilations, which destroy the proxy.
		TickerHandle = FTSTicker::GetCoreTicker().AddTicker(TEXT("NoesisMaterial"), 0.0f, [this](float DeltaTime)
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
		FTSTicker::GetCoreTicker().RemoveTicker(TickerHandle);
#endif
	}

	FMaterialRenderProxy* MaterialProxy;
#if WITH_EDITOR
	TWeakObjectPtr<UMaterialInterface> MaterialPtr;
#if UE_VERSION_OLDER_THAN(5, 0, 0)
	FDelegateHandle TickerHandle;
#else
	FTSTicker::FDelegateHandle TickerHandle;
#endif

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

static TShaderRef<FNoesisMaterialPSBase> GetMaterialPixelShader(const FMaterial* Material, Noesis::Shader::Enum ShaderType, bool IsLinearColor)
{
	TShaderRef<FShader> FoundShader;

#if UE_VERSION_OLDER_THAN(4, 27, 0)
	const FMaterialShaderMap* MaterialShaderMap = Material->GetRenderingThreadShaderMap();

	if (IsLinearColor)
	{
		switch (ShaderType)
		{
			case Noesis::Shader::Path_Pattern:
				FoundShader = MaterialShaderMap->GetShader<FNoesisPathMaterialLinearColorPS>();
				break;
			case Noesis::Shader::Path_Pattern_Clamp:
				FoundShader = MaterialShaderMap->GetShader<FNoesisPathMaterialClampLinearColorPS>();
				break;
			case Noesis::Shader::Path_Pattern_Repeat:
				FoundShader = MaterialShaderMap->GetShader<FNoesisPathMaterialRepeatLinearColorPS>();
				break;
			case Noesis::Shader::Path_Pattern_MirrorU:
				FoundShader = MaterialShaderMap->GetShader<FNoesisPathMaterialMirrorULinearColorPS>();
				break;
			case Noesis::Shader::Path_Pattern_MirrorV:
				FoundShader = MaterialShaderMap->GetShader<FNoesisPathMaterialMirrorVLinearColorPS>();
				break;
			case Noesis::Shader::Path_Pattern_Mirror:
				FoundShader = MaterialShaderMap->GetShader<FNoesisPathMaterialMirrorLinearColorPS>();
				break;
			case Noesis::Shader::Path_AA_Pattern:
				FoundShader = MaterialShaderMap->GetShader<FNoesisPathAAMaterialLinearColorPS>();
				break;
			case Noesis::Shader::Path_AA_Pattern_Clamp:
				FoundShader = MaterialShaderMap->GetShader<FNoesisPathAAMaterialClampLinearColorPS>();
				break;
			case Noesis::Shader::Path_AA_Pattern_Repeat:
				FoundShader = MaterialShaderMap->GetShader<FNoesisPathAAMaterialRepeatLinearColorPS>();
				break;
			case Noesis::Shader::Path_AA_Pattern_MirrorU:
				FoundShader = MaterialShaderMap->GetShader<FNoesisPathAAMaterialMirrorULinearColorPS>();
				break;
			case Noesis::Shader::Path_AA_Pattern_MirrorV:
				FoundShader = MaterialShaderMap->GetShader<FNoesisPathAAMaterialMirrorVLinearColorPS>();
				break;
			case Noesis::Shader::Path_AA_Pattern_Mirror:
				FoundShader = MaterialShaderMap->GetShader<FNoesisPathAAMaterialMirrorLinearColorPS>();
				break;
			case Noesis::Shader::SDF_Pattern:
				FoundShader = MaterialShaderMap->GetShader<FNoesisSDFMaterialLinearColorPS>();
				break;
			case Noesis::Shader::SDF_Pattern_Clamp:
				FoundShader = MaterialShaderMap->GetShader<FNoesisSDFMaterialClampLinearColorPS>();
				break;
			case Noesis::Shader::SDF_Pattern_Repeat:
				FoundShader = MaterialShaderMap->GetShader<FNoesisSDFMaterialRepeatLinearColorPS>();
				break;
			case Noesis::Shader::SDF_Pattern_MirrorU:
				FoundShader = MaterialShaderMap->GetShader<FNoesisSDFMaterialMirrorULinearColorPS>();
				break;
			case Noesis::Shader::SDF_Pattern_MirrorV:
				FoundShader = MaterialShaderMap->GetShader<FNoesisSDFMaterialMirrorVLinearColorPS>();
				break;
			case Noesis::Shader::SDF_Pattern_Mirror:
				FoundShader = MaterialShaderMap->GetShader<FNoesisSDFMaterialMirrorLinearColorPS>();
				break;
			case Noesis::Shader::SDF_LCD_Pattern:
				FoundShader = MaterialShaderMap->GetShader<FNoesisSDFLCDMaterialLinearColorPS>();
				break;
			case Noesis::Shader::SDF_LCD_Pattern_Clamp:
				FoundShader = MaterialShaderMap->GetShader<FNoesisSDFLCDMaterialClampLinearColorPS>();
				break;
			case Noesis::Shader::SDF_LCD_Pattern_Repeat:
				FoundShader = MaterialShaderMap->GetShader<FNoesisSDFLCDMaterialRepeatLinearColorPS>();
				break;
			case Noesis::Shader::SDF_LCD_Pattern_MirrorU:
				FoundShader = MaterialShaderMap->GetShader<FNoesisSDFLCDMaterialMirrorULinearColorPS>();
				break;
			case Noesis::Shader::SDF_LCD_Pattern_MirrorV:
				FoundShader = MaterialShaderMap->GetShader<FNoesisSDFLCDMaterialMirrorVLinearColorPS>();
				break;
			case Noesis::Shader::SDF_LCD_Pattern_Mirror:
				FoundShader = MaterialShaderMap->GetShader<FNoesisSDFLCDMaterialMirrorLinearColorPS>();
				break;
			case Noesis::Shader::Opacity_Pattern:
				FoundShader = MaterialShaderMap->GetShader<FNoesisOpacityMaterialLinearColorPS>();
				break;
			case Noesis::Shader::Opacity_Pattern_Clamp:
				FoundShader = MaterialShaderMap->GetShader<FNoesisOpacityMaterialClampLinearColorPS>();
				break;
			case Noesis::Shader::Opacity_Pattern_Repeat:
				FoundShader = MaterialShaderMap->GetShader<FNoesisOpacityMaterialRepeatLinearColorPS>();
				break;
			case Noesis::Shader::Opacity_Pattern_MirrorU:
				FoundShader = MaterialShaderMap->GetShader<FNoesisOpacityMaterialMirrorULinearColorPS>();
				break;
			case Noesis::Shader::Opacity_Pattern_MirrorV:
				FoundShader = MaterialShaderMap->GetShader<FNoesisOpacityMaterialMirrorVLinearColorPS>();
				break;
			case Noesis::Shader::Opacity_Pattern_Mirror:
				FoundShader = MaterialShaderMap->GetShader<FNoesisOpacityMaterialMirrorLinearColorPS>();
				break;
			default:
				// Only pattern shaders should be requested
				check(false);
		}
	}
	else
	{
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
	}
#else
	FMaterialShaderTypes ShaderTypes;
	if (IsLinearColor)
	{
		switch (ShaderType)
		{
		case Noesis::Shader::Path_Pattern:
			ShaderTypes.AddShaderType<FNoesisPathMaterialLinearColorPS>();
			break;
		case Noesis::Shader::Path_Pattern_Clamp:
			ShaderTypes.AddShaderType<FNoesisPathMaterialClampLinearColorPS>();
			break;
		case Noesis::Shader::Path_Pattern_Repeat:
			ShaderTypes.AddShaderType<FNoesisPathMaterialRepeatLinearColorPS>();
			break;
		case Noesis::Shader::Path_Pattern_MirrorU:
			ShaderTypes.AddShaderType<FNoesisPathMaterialMirrorULinearColorPS>();
			break;
		case Noesis::Shader::Path_Pattern_MirrorV:
			ShaderTypes.AddShaderType<FNoesisPathMaterialMirrorVLinearColorPS>();
			break;
		case Noesis::Shader::Path_Pattern_Mirror:
			ShaderTypes.AddShaderType<FNoesisPathMaterialMirrorLinearColorPS>();
			break;
		case Noesis::Shader::Path_AA_Pattern:
			ShaderTypes.AddShaderType<FNoesisPathAAMaterialLinearColorPS>();
			break;
		case Noesis::Shader::Path_AA_Pattern_Clamp:
			ShaderTypes.AddShaderType<FNoesisPathAAMaterialClampLinearColorPS>();
			break;
		case Noesis::Shader::Path_AA_Pattern_Repeat:
			ShaderTypes.AddShaderType<FNoesisPathAAMaterialRepeatLinearColorPS>();
			break;
		case Noesis::Shader::Path_AA_Pattern_MirrorU:
			ShaderTypes.AddShaderType<FNoesisPathAAMaterialMirrorULinearColorPS>();
			break;
		case Noesis::Shader::Path_AA_Pattern_MirrorV:
			ShaderTypes.AddShaderType<FNoesisPathAAMaterialMirrorVLinearColorPS>();
			break;
		case Noesis::Shader::Path_AA_Pattern_Mirror:
			ShaderTypes.AddShaderType<FNoesisPathAAMaterialMirrorLinearColorPS>();
			break;
		case Noesis::Shader::SDF_Pattern:
			ShaderTypes.AddShaderType<FNoesisSDFMaterialLinearColorPS>();
			break;
		case Noesis::Shader::SDF_Pattern_Clamp:
			ShaderTypes.AddShaderType<FNoesisSDFMaterialClampLinearColorPS>();
			break;
		case Noesis::Shader::SDF_Pattern_Repeat:
			ShaderTypes.AddShaderType<FNoesisSDFMaterialRepeatLinearColorPS>();
			break;
		case Noesis::Shader::SDF_Pattern_MirrorU:
			ShaderTypes.AddShaderType<FNoesisSDFMaterialMirrorULinearColorPS>();
			break;
		case Noesis::Shader::SDF_Pattern_MirrorV:
			ShaderTypes.AddShaderType<FNoesisSDFMaterialMirrorVLinearColorPS>();
			break;
		case Noesis::Shader::SDF_Pattern_Mirror:
			ShaderTypes.AddShaderType<FNoesisSDFMaterialMirrorLinearColorPS>();
			break;
		case Noesis::Shader::SDF_LCD_Pattern:
			ShaderTypes.AddShaderType<FNoesisSDFLCDMaterialLinearColorPS>();
			break;
		case Noesis::Shader::SDF_LCD_Pattern_Clamp:
			ShaderTypes.AddShaderType<FNoesisSDFLCDMaterialClampLinearColorPS>();
			break;
		case Noesis::Shader::SDF_LCD_Pattern_Repeat:
			ShaderTypes.AddShaderType<FNoesisSDFLCDMaterialRepeatLinearColorPS>();
			break;
		case Noesis::Shader::SDF_LCD_Pattern_MirrorU:
			ShaderTypes.AddShaderType<FNoesisSDFLCDMaterialMirrorULinearColorPS>();
			break;
		case Noesis::Shader::SDF_LCD_Pattern_MirrorV:
			ShaderTypes.AddShaderType<FNoesisSDFLCDMaterialMirrorVLinearColorPS>();
			break;
		case Noesis::Shader::SDF_LCD_Pattern_Mirror:
			ShaderTypes.AddShaderType<FNoesisSDFLCDMaterialMirrorLinearColorPS>();
			break;
		case Noesis::Shader::Opacity_Pattern:
			ShaderTypes.AddShaderType<FNoesisOpacityMaterialLinearColorPS>();
			break;
		case Noesis::Shader::Opacity_Pattern_Clamp:
			ShaderTypes.AddShaderType<FNoesisOpacityMaterialClampLinearColorPS>();
			break;
		case Noesis::Shader::Opacity_Pattern_Repeat:
			ShaderTypes.AddShaderType<FNoesisOpacityMaterialRepeatLinearColorPS>();
			break;
		case Noesis::Shader::Opacity_Pattern_MirrorU:
			ShaderTypes.AddShaderType<FNoesisOpacityMaterialMirrorULinearColorPS>();
			break;
		case Noesis::Shader::Opacity_Pattern_MirrorV:
			ShaderTypes.AddShaderType<FNoesisOpacityMaterialMirrorVLinearColorPS>();
			break;
		case Noesis::Shader::Opacity_Pattern_Mirror:
			ShaderTypes.AddShaderType<FNoesisOpacityMaterialMirrorLinearColorPS>();
			break;
		default:
			// Only pattern shaders should be requested
			check(false);
		}
	}
	else
	{
		switch (ShaderType)
		{
		case Noesis::Shader::Path_Pattern:
			ShaderTypes.AddShaderType<FNoesisPathMaterialPS>();
			break;
		case Noesis::Shader::Path_Pattern_Clamp:
			ShaderTypes.AddShaderType<FNoesisPathMaterialClampPS>();
			break;
		case Noesis::Shader::Path_Pattern_Repeat:
			ShaderTypes.AddShaderType<FNoesisPathMaterialRepeatPS>();
			break;
		case Noesis::Shader::Path_Pattern_MirrorU:
			ShaderTypes.AddShaderType<FNoesisPathMaterialMirrorUPS>();
			break;
		case Noesis::Shader::Path_Pattern_MirrorV:
			ShaderTypes.AddShaderType<FNoesisPathMaterialMirrorVPS>();
			break;
		case Noesis::Shader::Path_Pattern_Mirror:
			ShaderTypes.AddShaderType<FNoesisPathMaterialMirrorPS>();
			break;
		case Noesis::Shader::Path_AA_Pattern:
			ShaderTypes.AddShaderType<FNoesisPathAAMaterialPS>();
			break;
		case Noesis::Shader::Path_AA_Pattern_Clamp:
			ShaderTypes.AddShaderType<FNoesisPathAAMaterialClampPS>();
			break;
		case Noesis::Shader::Path_AA_Pattern_Repeat:
			ShaderTypes.AddShaderType<FNoesisPathAAMaterialRepeatPS>();
			break;
		case Noesis::Shader::Path_AA_Pattern_MirrorU:
			ShaderTypes.AddShaderType<FNoesisPathAAMaterialMirrorUPS>();
			break;
		case Noesis::Shader::Path_AA_Pattern_MirrorV:
			ShaderTypes.AddShaderType<FNoesisPathAAMaterialMirrorVPS>();
			break;
		case Noesis::Shader::Path_AA_Pattern_Mirror:
			ShaderTypes.AddShaderType<FNoesisPathAAMaterialMirrorPS>();
			break;
		case Noesis::Shader::SDF_Pattern:
			ShaderTypes.AddShaderType<FNoesisSDFMaterialPS>();
			break;
		case Noesis::Shader::SDF_Pattern_Clamp:
			ShaderTypes.AddShaderType<FNoesisSDFMaterialClampPS>();
			break;
		case Noesis::Shader::SDF_Pattern_Repeat:
			ShaderTypes.AddShaderType<FNoesisSDFMaterialRepeatPS>();
			break;
		case Noesis::Shader::SDF_Pattern_MirrorU:
			ShaderTypes.AddShaderType<FNoesisSDFMaterialMirrorUPS>();
			break;
		case Noesis::Shader::SDF_Pattern_MirrorV:
			ShaderTypes.AddShaderType<FNoesisSDFMaterialMirrorVPS>();
			break;
		case Noesis::Shader::SDF_Pattern_Mirror:
			ShaderTypes.AddShaderType<FNoesisSDFMaterialMirrorPS>();
			break;
		case Noesis::Shader::SDF_LCD_Pattern:
			ShaderTypes.AddShaderType<FNoesisSDFLCDMaterialPS>();
			break;
		case Noesis::Shader::SDF_LCD_Pattern_Clamp:
			ShaderTypes.AddShaderType<FNoesisSDFLCDMaterialClampPS>();
			break;
		case Noesis::Shader::SDF_LCD_Pattern_Repeat:
			ShaderTypes.AddShaderType<FNoesisSDFLCDMaterialRepeatPS>();
			break;
		case Noesis::Shader::SDF_LCD_Pattern_MirrorU:
			ShaderTypes.AddShaderType<FNoesisSDFLCDMaterialMirrorUPS>();
			break;
		case Noesis::Shader::SDF_LCD_Pattern_MirrorV:
			ShaderTypes.AddShaderType<FNoesisSDFLCDMaterialMirrorVPS>();
			break;
		case Noesis::Shader::SDF_LCD_Pattern_Mirror:
			ShaderTypes.AddShaderType<FNoesisSDFLCDMaterialMirrorPS>();
			break;
		case Noesis::Shader::Opacity_Pattern:
			ShaderTypes.AddShaderType<FNoesisOpacityMaterialPS>();
			break;
		case Noesis::Shader::Opacity_Pattern_Clamp:
			ShaderTypes.AddShaderType<FNoesisOpacityMaterialClampPS>();
			break;
		case Noesis::Shader::Opacity_Pattern_Repeat:
			ShaderTypes.AddShaderType<FNoesisOpacityMaterialRepeatPS>();
			break;
		case Noesis::Shader::Opacity_Pattern_MirrorU:
			ShaderTypes.AddShaderType<FNoesisOpacityMaterialMirrorUPS>();
			break;
		case Noesis::Shader::Opacity_Pattern_MirrorV:
			ShaderTypes.AddShaderType<FNoesisOpacityMaterialMirrorVPS>();
			break;
		case Noesis::Shader::Opacity_Pattern_Mirror:
			ShaderTypes.AddShaderType<FNoesisOpacityMaterialMirrorPS>();
			break;
		default:
			// Only pattern shaders should be requested
			check(false);
		}
	}
	FMaterialShaders Shaders;
	Material->TryGetShaders(ShaderTypes, nullptr, Shaders);
	Shaders.TryGetPixelShader(FoundShader);

#endif

	return TShaderRef<FNoesisMaterialPSBase>::Cast(FoundShader);
}

template<ESamplerFilter Filter = SF_Point,
	ESamplerAddressMode AddressU = AM_Clamp,
	ESamplerAddressMode AddressV = AM_Clamp,
	int MaxMipLevel = 1>
class TNoesisStaticSamplerState : public TStaticStateRHI<TNoesisStaticSamplerState<Filter, AddressU, AddressV, MaxMipLevel>, FSamplerStateRHIRef, FRHISamplerState*>
{
public:
	static FSamplerStateRHIRef CreateRHI()
	{
		FSamplerStateInitializerRHI Initializer(Filter, AddressU, AddressV, AM_Clamp, -0.75f, 1, 0, MaxMipLevel == 0 ? 0.0f : FLT_MAX, 0, SCF_Never);
		return RHICreateSamplerState(Initializer);
	}
};

FNoesisRenderDevice::FNoesisRenderDevice(bool LinearColor)
	: IsLinearColor(LinearColor)
{
	auto VBName = TEXT("Noesis.VertexBuffer");
	FRHIResourceCreateInfo CreateInfo(VBName);
#if UE_VERSION_OLDER_THAN(5, 3, 0)
	DynamicVertexBuffer = RHICreateVertexBuffer(DYNAMIC_VB_SIZE, BUF_Volatile, CreateInfo);
#else
	DynamicVertexBuffer = FRHICommandListExecutor::GetImmediateCommandList().CreateVertexBuffer(DYNAMIC_VB_SIZE, BUF_Volatile, CreateInfo);
#endif
	NOESIS_BIND_DEBUG_BUFFER_LABEL(DynamicVertexBuffer, VBName);
	auto IBName = TEXT("Noesis.IndexBuffer");
	CreateInfo.DebugName = IBName;
#if UE_VERSION_OLDER_THAN(5, 3, 0)
	DynamicIndexBuffer = RHICreateIndexBuffer(sizeof(int16), DYNAMIC_IB_SIZE, BUF_Volatile, CreateInfo);
#else
	DynamicIndexBuffer = FRHICommandListExecutor::GetImmediateCommandList().CreateIndexBuffer(sizeof(int16), DYNAMIC_IB_SIZE, BUF_Volatile, CreateInfo);
#endif
	NOESIS_BIND_DEBUG_BUFFER_LABEL(DynamicIndexBuffer, IBName);

	VSConstantBuffer = TUniformBufferRef<FNoesisVSConstants>::CreateUniformBufferImmediate(FNoesisVSConstants(), UniformBuffer_MultiFrame);
	VSConstantBufferRightEye = TUniformBufferRef<FNoesisVSConstantsRightEye>::CreateUniformBufferImmediate(FNoesisVSConstantsRightEye(), UniformBuffer_MultiFrame);
	TextureSizeBuffer = TUniformBufferRef<FNoesisTextureSize>::CreateUniformBufferImmediate(FNoesisTextureSize(), UniformBuffer_MultiFrame);
	PSRgbaConstantBuffer = TUniformBufferRef<FNoesisPSRgbaConstants>::CreateUniformBufferImmediate(FNoesisPSRgbaConstants(), UniformBuffer_MultiFrame);
	PSOpacityConstantBuffer = TUniformBufferRef<FNoesisPSOpacityConstants>::CreateUniformBufferImmediate(FNoesisPSOpacityConstants(), UniformBuffer_MultiFrame);
	PSRadialGradConstantBuffer = TUniformBufferRef<FNoesisPSRadialGradConstants>::CreateUniformBufferImmediate(FNoesisPSRadialGradConstants(), UniformBuffer_MultiFrame);
	BlurConstantsBuffer = TUniformBufferRef<FNoesisBlurConstants>::CreateUniformBufferImmediate(FNoesisBlurConstants(), UniformBuffer_MultiFrame);
	ShadowConstantsBuffer = TUniformBufferRef<FNoesisShadowConstants>::CreateUniformBufferImmediate(FNoesisShadowConstants(), UniformBuffer_MultiFrame);

	const auto FeatureLevel = GMaxRHIFeatureLevel;

	FMemory::Memzero(VertexDeclarations);

	VertexDeclarations[Noesis::Shader::Vertex::Format::Pos] = GNoesisPosVertexDeclaration.VertexDeclarationRHI;
	VertexDeclarations[Noesis::Shader::Vertex::Format::PosColor] = GNoesisPosColorVertexDeclaration.VertexDeclarationRHI;
	VertexDeclarations[Noesis::Shader::Vertex::Format::PosTex0] = GNoesisPosTex0VertexDeclaration.VertexDeclarationRHI;
	VertexDeclarations[Noesis::Shader::Vertex::Format::PosTex0Rect] = GNoesisPosTex0RectVertexDeclaration.VertexDeclarationRHI;
	VertexDeclarations[Noesis::Shader::Vertex::Format::PosTex0RectTile] = GNoesisPosTex0RectTileVertexDeclaration.VertexDeclarationRHI;
	VertexDeclarations[Noesis::Shader::Vertex::Format::PosColorCoverage] = GNoesisPosColorCoverageVertexDeclaration.VertexDeclarationRHI;
	VertexDeclarations[Noesis::Shader::Vertex::Format::PosTex0Coverage] = GNoesisPosTex0CoverageVertexDeclaration.VertexDeclarationRHI;
	VertexDeclarations[Noesis::Shader::Vertex::Format::PosTex0CoverageRect] = GNoesisPosTex0CoverageRectVertexDeclaration.VertexDeclarationRHI;
	VertexDeclarations[Noesis::Shader::Vertex::Format::PosTex0CoverageRectTile] = GNoesisPosTex0CoverageRectTileVertexDeclaration.VertexDeclarationRHI;
	VertexDeclarations[Noesis::Shader::Vertex::Format::PosColorTex1] = GNoesisPosColorTex1VertexDeclaration.VertexDeclarationRHI;
	VertexDeclarations[Noesis::Shader::Vertex::Format::PosTex0Tex1] = GNoesisPosTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexDeclarations[Noesis::Shader::Vertex::Format::PosTex0Tex1Rect] = GNoesisPosTex0Tex1RectVertexDeclaration.VertexDeclarationRHI;
	VertexDeclarations[Noesis::Shader::Vertex::Format::PosTex0Tex1RectTile] = GNoesisPosTex0Tex1RectTileVertexDeclaration.VertexDeclarationRHI;
	VertexDeclarations[Noesis::Shader::Vertex::Format::PosColorTex0Tex1] = GNoesisPosColorTex0Tex1VertexDeclaration.VertexDeclarationRHI;
	VertexDeclarations[Noesis::Shader::Vertex::Format::PosColorTex1Rect] = GNoesisPosColorTex1RectVertexDeclaration.VertexDeclarationRHI;
	VertexDeclarations[Noesis::Shader::Vertex::Format::PosColorTex0RectImagePos] = GNoesisPosColorTex0RectImagePosVertexDeclaration.VertexDeclarationRHI;

	if (IsLinearColor)
	{
		VertexShaders[Noesis::Shader::Vertex::Pos] = TShaderMapRef<FNoesisPosVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosColor] = TShaderMapRef<FNoesisPosLinearColorVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0] = TShaderMapRef<FNoesisPosTex0VS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0Rect] = TShaderMapRef<FNoesisPosTex0RectVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0RectTile] = TShaderMapRef<FNoesisPosTex0RectTileVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosColorCoverage] = TShaderMapRef<FNoesisPosLinearColorCoverageVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0Coverage] = TShaderMapRef<FNoesisPosTex0CoverageVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0CoverageRect] = TShaderMapRef<FNoesisPosTex0CoverageRectVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0CoverageRectTile] = TShaderMapRef<FNoesisPosTex0CoverageRectTileVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosColorTex1_SDF] = TShaderMapRef<FNoesisPosLinearColorTex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0Tex1_SDF] = TShaderMapRef<FNoesisPosTex0Tex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0Tex1Rect_SDF] = TShaderMapRef<FNoesisPosTex0Tex1RectSDFVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0Tex1RectTile_SDF] = TShaderMapRef<FNoesisPosTex0Tex1RectTileSDFVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosColorTex1] = TShaderMapRef<FNoesisPosLinearColorTex1VS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0Tex1] = TShaderMapRef<FNoesisPosTex0Tex1VS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0Tex1Rect] = TShaderMapRef<FNoesisPosTex0Tex1RectVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0Tex1RectTile] = TShaderMapRef<FNoesisPosTex0Tex1RectTileVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosColorTex0Tex1] = TShaderMapRef<FNoesisPosLinearColorTex0Tex1VS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0Tex1_Downsample] = TShaderMapRef<FNoesisPosTex0Tex1DownsampleVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosColorTex1Rect] = TShaderMapRef<FNoesisPosLinearColorTex1RectVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosColorTex0RectImagePos] = TShaderMapRef<FNoesisPosLinearColorTex0RectImagePosVS>(GetGlobalShaderMap(FeatureLevel));

		VertexShadersStereo[Noesis::Shader::Vertex::Pos] = TShaderMapRef<FNoesisPosStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosColor] = TShaderMapRef<FNoesisPosLinearColorStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0] = TShaderMapRef<FNoesisPosTex0StereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0Rect] = TShaderMapRef<FNoesisPosTex0RectStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0RectTile] = TShaderMapRef<FNoesisPosTex0RectTileStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosColorCoverage] = TShaderMapRef<FNoesisPosLinearColorCoverageStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0Coverage] = TShaderMapRef<FNoesisPosTex0CoverageStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0CoverageRect] = TShaderMapRef<FNoesisPosTex0CoverageRectStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0CoverageRectTile] = TShaderMapRef<FNoesisPosTex0CoverageRectTileStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosColorTex1_SDF] = TShaderMapRef<FNoesisPosLinearColorTex1SDFStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0Tex1_SDF] = TShaderMapRef<FNoesisPosTex0Tex1SDFStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0Tex1Rect_SDF] = TShaderMapRef<FNoesisPosTex0Tex1RectSDFStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0Tex1RectTile_SDF] = TShaderMapRef<FNoesisPosTex0Tex1RectTileSDFStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosColorTex1] = TShaderMapRef<FNoesisPosLinearColorTex1StereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0Tex1] = TShaderMapRef<FNoesisPosTex0Tex1StereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0Tex1Rect] = TShaderMapRef<FNoesisPosTex0Tex1RectStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0Tex1RectTile] = TShaderMapRef<FNoesisPosTex0Tex1RectTileStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosColorTex0Tex1] = TShaderMapRef<FNoesisPosLinearColorTex0Tex1StereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0Tex1_Downsample] = TShaderMapRef<FNoesisPosTex0Tex1DownsampleStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosColorTex1Rect] = TShaderMapRef<FNoesisPosLinearColorTex1RectStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosColorTex0RectImagePos] = TShaderMapRef<FNoesisPosLinearColorTex0RectImagePosStereoVS>(GetGlobalShaderMap(FeatureLevel));

		// Read the comment next to PATTERN_LINEAR in FNoesisPS::ModifyCompilationEnvironment
		PixelShadersPatternConvertColor[Noesis::Shader::Path_Pattern] = TShaderMapRef<FNoesisPathPatternLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_Pattern_Clamp] = TShaderMapRef<FNoesisPathPatternClampLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_Pattern_Repeat] = TShaderMapRef<FNoesisPathPatternRepeatLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_Pattern_MirrorU] = TShaderMapRef<FNoesisPathPatternMirrorULinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_Pattern_MirrorV] = TShaderMapRef<FNoesisPathPatternMirrorVLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_Pattern_Mirror] = TShaderMapRef<FNoesisPathPatternMirrorLinearPS>(GetGlobalShaderMap(FeatureLevel));

		PixelShadersPatternConvertColor[Noesis::Shader::Path_AA_Pattern] = TShaderMapRef<FNoesisPathAAPatternLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_AA_Pattern_Clamp] = TShaderMapRef<FNoesisPathAAPatternClampLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_AA_Pattern_Repeat] = TShaderMapRef<FNoesisPathAAPatternRepeatLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_AA_Pattern_MirrorU] = TShaderMapRef<FNoesisPathAAPatternMirrorULinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_AA_Pattern_MirrorV] = TShaderMapRef<FNoesisPathAAPatternMirrorVLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_AA_Pattern_Mirror] = TShaderMapRef<FNoesisPathAAPatternMirrorLinearPS>(GetGlobalShaderMap(FeatureLevel));

		PixelShadersPatternConvertColor[Noesis::Shader::SDF_Pattern] = TShaderMapRef<FNoesisSDFPatternLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_Pattern_Clamp] = TShaderMapRef<FNoesisSDFPatternClampLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_Pattern_Repeat] = TShaderMapRef<FNoesisSDFPatternRepeatLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_Pattern_MirrorU] = TShaderMapRef<FNoesisSDFPatternMirrorULinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_Pattern_MirrorV] = TShaderMapRef<FNoesisSDFPatternMirrorVLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_Pattern_Mirror] = TShaderMapRef<FNoesisSDFPatternMirrorLinearPS>(GetGlobalShaderMap(FeatureLevel));

		PixelShadersPatternConvertColor[Noesis::Shader::SDF_LCD_Pattern] = TShaderMapRef<FNoesisSDFLCDPatternLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_LCD_Pattern_Clamp] = TShaderMapRef<FNoesisSDFLCDPatternClampLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_LCD_Pattern_Repeat] = TShaderMapRef<FNoesisSDFLCDPatternRepeatLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_LCD_Pattern_MirrorU] = TShaderMapRef<FNoesisSDFLCDPatternMirrorULinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_LCD_Pattern_MirrorV] = TShaderMapRef<FNoesisSDFLCDPatternMirrorVLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_LCD_Pattern_Mirror] = TShaderMapRef<FNoesisSDFLCDPatternMirrorLinearPS>(GetGlobalShaderMap(FeatureLevel));

		PixelShadersPatternConvertColor[Noesis::Shader::Opacity_Pattern] = TShaderMapRef<FNoesisOpacityPatternLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Opacity_Pattern_Clamp] = TShaderMapRef<FNoesisOpacityPatternClampLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Opacity_Pattern_Repeat] = TShaderMapRef<FNoesisOpacityPatternRepeatLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Opacity_Pattern_MirrorU] = TShaderMapRef<FNoesisOpacityPatternMirrorULinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Opacity_Pattern_MirrorV] = TShaderMapRef<FNoesisOpacityPatternMirrorVLinearPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Opacity_Pattern_Mirror] = TShaderMapRef<FNoesisOpacityPatternMirrorLinearPS>(GetGlobalShaderMap(FeatureLevel));
	}
	else
	{
		VertexShaders[Noesis::Shader::Vertex::Pos] = TShaderMapRef<FNoesisPosVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosColor] = TShaderMapRef<FNoesisPosColorVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0] = TShaderMapRef<FNoesisPosTex0VS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0Rect] = TShaderMapRef<FNoesisPosTex0RectVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0RectTile] = TShaderMapRef<FNoesisPosTex0RectTileVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosColorCoverage] = TShaderMapRef<FNoesisPosColorCoverageVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0Coverage] = TShaderMapRef<FNoesisPosTex0CoverageVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0CoverageRect] = TShaderMapRef<FNoesisPosTex0CoverageRectVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0CoverageRectTile] = TShaderMapRef<FNoesisPosTex0CoverageRectTileVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosColorTex1_SDF] = TShaderMapRef<FNoesisPosColorTex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0Tex1_SDF] = TShaderMapRef<FNoesisPosTex0Tex1SDFVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0Tex1Rect_SDF] = TShaderMapRef<FNoesisPosTex0Tex1RectSDFVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0Tex1RectTile_SDF] = TShaderMapRef<FNoesisPosTex0Tex1RectTileSDFVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosColorTex1] = TShaderMapRef<FNoesisPosColorTex1VS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0Tex1] = TShaderMapRef<FNoesisPosTex0Tex1VS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0Tex1Rect] = TShaderMapRef<FNoesisPosTex0Tex1RectVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0Tex1RectTile] = TShaderMapRef<FNoesisPosTex0Tex1RectTileVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosColorTex0Tex1] = TShaderMapRef<FNoesisPosColorTex0Tex1VS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosTex0Tex1_Downsample] = TShaderMapRef<FNoesisPosTex0Tex1DownsampleVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosColorTex1Rect] = TShaderMapRef<FNoesisPosColorTex1RectVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShaders[Noesis::Shader::Vertex::PosColorTex0RectImagePos] = TShaderMapRef<FNoesisPosColorTex0RectImagePosVS>(GetGlobalShaderMap(FeatureLevel));

		VertexShadersStereo[Noesis::Shader::Vertex::Pos] = TShaderMapRef<FNoesisPosStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosColor] = TShaderMapRef<FNoesisPosColorStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0] = TShaderMapRef<FNoesisPosTex0StereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0Rect] = TShaderMapRef<FNoesisPosTex0RectStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0RectTile] = TShaderMapRef<FNoesisPosTex0RectTileStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosColorCoverage] = TShaderMapRef<FNoesisPosColorCoverageStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0Coverage] = TShaderMapRef<FNoesisPosTex0CoverageStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0CoverageRect] = TShaderMapRef<FNoesisPosTex0CoverageRectStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0CoverageRectTile] = TShaderMapRef<FNoesisPosTex0CoverageRectTileStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosColorTex1_SDF] = TShaderMapRef<FNoesisPosColorTex1SDFStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0Tex1_SDF] = TShaderMapRef<FNoesisPosTex0Tex1SDFStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0Tex1Rect_SDF] = TShaderMapRef<FNoesisPosTex0Tex1RectSDFStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0Tex1RectTile_SDF] = TShaderMapRef<FNoesisPosTex0Tex1RectTileSDFStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosColorTex1] = TShaderMapRef<FNoesisPosColorTex1StereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0Tex1] = TShaderMapRef<FNoesisPosTex0Tex1StereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0Tex1Rect] = TShaderMapRef<FNoesisPosTex0Tex1RectStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0Tex1RectTile] = TShaderMapRef<FNoesisPosTex0Tex1RectTileStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosColorTex0Tex1] = TShaderMapRef<FNoesisPosColorTex0Tex1StereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosTex0Tex1_Downsample] = TShaderMapRef<FNoesisPosTex0Tex1DownsampleStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosColorTex1Rect] = TShaderMapRef<FNoesisPosColorTex1RectStereoVS>(GetGlobalShaderMap(FeatureLevel));
		VertexShadersStereo[Noesis::Shader::Vertex::PosColorTex0RectImagePos] = TShaderMapRef<FNoesisPosColorTex0RectImagePosStereoVS>(GetGlobalShaderMap(FeatureLevel));

		// Read the comment next to PATTERN_SRGB in FNoesisPS::ModifyCompilationEnvironment
		PixelShadersPatternConvertColor[Noesis::Shader::Path_Pattern] = TShaderMapRef<FNoesisPathPatternSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_Pattern_Clamp] = TShaderMapRef<FNoesisPathPatternClampSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_Pattern_Repeat] = TShaderMapRef<FNoesisPathPatternRepeatSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_Pattern_MirrorU] = TShaderMapRef<FNoesisPathPatternMirrorUSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_Pattern_MirrorV] = TShaderMapRef<FNoesisPathPatternMirrorVSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_Pattern_Mirror] = TShaderMapRef<FNoesisPathPatternMirrorSRGBPS>(GetGlobalShaderMap(FeatureLevel));

		PixelShadersPatternConvertColor[Noesis::Shader::Path_AA_Pattern] = TShaderMapRef<FNoesisPathAAPatternSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_AA_Pattern_Clamp] = TShaderMapRef<FNoesisPathAAPatternClampSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_AA_Pattern_Repeat] = TShaderMapRef<FNoesisPathAAPatternRepeatSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_AA_Pattern_MirrorU] = TShaderMapRef<FNoesisPathAAPatternMirrorUSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_AA_Pattern_MirrorV] = TShaderMapRef<FNoesisPathAAPatternMirrorVSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Path_AA_Pattern_Mirror] = TShaderMapRef<FNoesisPathAAPatternMirrorSRGBPS>(GetGlobalShaderMap(FeatureLevel));

		PixelShadersPatternConvertColor[Noesis::Shader::SDF_Pattern] = TShaderMapRef<FNoesisSDFPatternSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_Pattern_Clamp] = TShaderMapRef<FNoesisSDFPatternClampSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_Pattern_Repeat] = TShaderMapRef<FNoesisSDFPatternRepeatSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_Pattern_MirrorU] = TShaderMapRef<FNoesisSDFPatternMirrorUSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_Pattern_MirrorV] = TShaderMapRef<FNoesisSDFPatternMirrorVSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_Pattern_Mirror] = TShaderMapRef<FNoesisSDFPatternMirrorSRGBPS>(GetGlobalShaderMap(FeatureLevel));

		PixelShadersPatternConvertColor[Noesis::Shader::SDF_LCD_Pattern] = TShaderMapRef<FNoesisSDFLCDPatternSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_LCD_Pattern_Clamp] = TShaderMapRef<FNoesisSDFLCDPatternClampSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_LCD_Pattern_Repeat] = TShaderMapRef<FNoesisSDFLCDPatternRepeatSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_LCD_Pattern_MirrorU] = TShaderMapRef<FNoesisSDFLCDPatternMirrorUSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_LCD_Pattern_MirrorV] = TShaderMapRef<FNoesisSDFLCDPatternMirrorVSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::SDF_LCD_Pattern_Mirror] = TShaderMapRef<FNoesisSDFLCDPatternMirrorSRGBPS>(GetGlobalShaderMap(FeatureLevel));

		PixelShadersPatternConvertColor[Noesis::Shader::Opacity_Pattern] = TShaderMapRef<FNoesisOpacityPatternSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Opacity_Pattern_Clamp] = TShaderMapRef<FNoesisOpacityPatternClampSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Opacity_Pattern_Repeat] = TShaderMapRef<FNoesisOpacityPatternRepeatSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Opacity_Pattern_MirrorU] = TShaderMapRef<FNoesisOpacityPatternMirrorUSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Opacity_Pattern_MirrorV] = TShaderMapRef<FNoesisOpacityPatternMirrorVSRGBPS>(GetGlobalShaderMap(FeatureLevel));
		PixelShadersPatternConvertColor[Noesis::Shader::Opacity_Pattern_Mirror] = TShaderMapRef<FNoesisOpacityPatternMirrorSRGBPS>(GetGlobalShaderMap(FeatureLevel));
	}

	PixelShaders[Noesis::Shader::RGBA] = TShaderMapRef<FNoesisRgbaPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Mask] = TShaderMapRef<FNoesisMaskPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Clear] = TShaderMapRef<FNoesisClearPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Solid] = TShaderMapRef<FNoesisPathSolidPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Linear] = TShaderMapRef<FNoesisPathLinearPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Radial] = TShaderMapRef<FNoesisPathRadialPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Pattern] = TShaderMapRef<FNoesisPathPatternPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Pattern_Clamp] = TShaderMapRef<FNoesisPathPatternClampPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Pattern_Repeat] = TShaderMapRef<FNoesisPathPatternRepeatPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Pattern_MirrorU] = TShaderMapRef<FNoesisPathPatternMirrorUPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Pattern_MirrorV] = TShaderMapRef<FNoesisPathPatternMirrorVPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_Pattern_Mirror] = TShaderMapRef<FNoesisPathPatternMirrorPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_AA_Solid] = TShaderMapRef<FNoesisPathAASolidPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_AA_Linear] = TShaderMapRef<FNoesisPathAALinearPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_AA_Radial] = TShaderMapRef<FNoesisPathAARadialPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_AA_Pattern] = TShaderMapRef<FNoesisPathAAPatternPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_AA_Pattern_Clamp] = TShaderMapRef<FNoesisPathAAPatternClampPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_AA_Pattern_Repeat] = TShaderMapRef<FNoesisPathAAPatternRepeatPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_AA_Pattern_MirrorU] = TShaderMapRef<FNoesisPathAAPatternMirrorUPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_AA_Pattern_MirrorV] = TShaderMapRef<FNoesisPathAAPatternMirrorVPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Path_AA_Pattern_Mirror] = TShaderMapRef<FNoesisPathAAPatternMirrorPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Solid] = TShaderMapRef<FNoesisSDFSolidPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Linear] = TShaderMapRef<FNoesisSDFLinearPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Radial] = TShaderMapRef<FNoesisSDFRadialPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Pattern] = TShaderMapRef<FNoesisSDFPatternPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Pattern_Clamp] = TShaderMapRef<FNoesisSDFPatternClampPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Pattern_Repeat] = TShaderMapRef<FNoesisSDFPatternRepeatPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Pattern_MirrorU] = TShaderMapRef<FNoesisSDFPatternMirrorUPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Pattern_MirrorV] = TShaderMapRef<FNoesisSDFPatternMirrorVPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_Pattern_Mirror] = TShaderMapRef<FNoesisSDFPatternMirrorPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Solid] = TShaderMapRef<FNoesisSDFLCDSolidPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Linear] = TShaderMapRef<FNoesisSDFLCDLinearPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Radial] = TShaderMapRef<FNoesisSDFLCDRadialPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Pattern] = TShaderMapRef<FNoesisSDFLCDPatternPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Pattern_Clamp] = TShaderMapRef<FNoesisSDFLCDPatternClampPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Pattern_Repeat] = TShaderMapRef<FNoesisSDFLCDPatternRepeatPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Pattern_MirrorU] = TShaderMapRef<FNoesisSDFLCDPatternMirrorUPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Pattern_MirrorV] = TShaderMapRef<FNoesisSDFLCDPatternMirrorVPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::SDF_LCD_Pattern_Mirror] = TShaderMapRef<FNoesisSDFLCDPatternMirrorPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Opacity_Solid] = TShaderMapRef<FNoesisOpacitySolidPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Opacity_Linear] = TShaderMapRef<FNoesisOpacityLinearPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Opacity_Radial] = TShaderMapRef<FNoesisOpacityRadialPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Opacity_Pattern] = TShaderMapRef<FNoesisOpacityPatternPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Opacity_Pattern_Clamp] = TShaderMapRef<FNoesisOpacityPatternClampPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Opacity_Pattern_Repeat] = TShaderMapRef<FNoesisOpacityPatternRepeatPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Opacity_Pattern_MirrorU] = TShaderMapRef<FNoesisOpacityPatternMirrorUPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Opacity_Pattern_MirrorV] = TShaderMapRef<FNoesisOpacityPatternMirrorVPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Opacity_Pattern_Mirror] = TShaderMapRef<FNoesisOpacityPatternMirrorPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Upsample] = TShaderMapRef<FNoesisUpsamplePS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Downsample] = TShaderMapRef<FNoesisDownsamplePS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Shadow] = TShaderMapRef<FNoesisShadowPS>(GetGlobalShaderMap(FeatureLevel));
	PixelShaders[Noesis::Shader::Blur] = TShaderMapRef<FNoesisBlurPS>(GetGlobalShaderMap(FeatureLevel));
	//PixelShaders[Noesis::Shader::Custom_Effect] = nullptr;

	PixelShaderConstantBuffer0[Noesis::Shader::RGBA] = &PSRgbaConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Mask] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Clear] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Solid] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Linear] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Radial] = &PSRadialGradConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Pattern] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Pattern_Clamp] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Pattern_Repeat] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Pattern_MirrorU] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Pattern_MirrorV] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_Pattern_Mirror] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Solid] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Linear] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Radial] = &PSRadialGradConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Pattern] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Pattern_Clamp] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Pattern_Repeat] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Pattern_MirrorU] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Pattern_MirrorV] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Path_AA_Pattern_Mirror] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Solid] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Linear] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Radial] = &PSRadialGradConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Pattern] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Pattern_Clamp] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Pattern_Repeat] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Pattern_MirrorU] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Pattern_MirrorV] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_Pattern_Mirror] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Solid] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Linear] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Radial] = &PSRadialGradConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Pattern] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Pattern_Clamp] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Pattern_Repeat] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Pattern_MirrorU] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Pattern_MirrorV] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::SDF_LCD_Pattern_Mirror] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Solid] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Linear] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Radial] = &PSRadialGradConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Pattern] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Pattern_Clamp] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Pattern_Repeat] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Pattern_MirrorU] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Pattern_MirrorV] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Opacity_Pattern_Mirror] = &PSOpacityConstantBuffer;
	PixelShaderConstantBuffer0[Noesis::Shader::Upsample] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Downsample] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Shadow] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Blur] = nullptr;
	PixelShaderConstantBuffer0[Noesis::Shader::Custom_Effect] = nullptr;

	PixelShaderConstantBuffer1[Noesis::Shader::RGBA] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Mask] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Clear] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Solid] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Linear] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Radial] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Pattern] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Solid] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Linear] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Radial] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Pattern] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Path_AA_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Solid] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Linear] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Radial] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Pattern] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Solid] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Linear] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Radial] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Pattern] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::SDF_LCD_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Solid] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Linear] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Radial] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Pattern] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Opacity_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Upsample] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Downsample] = nullptr;
	PixelShaderConstantBuffer1[Noesis::Shader::Shadow] = &ShadowConstantsBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Blur] = &BlurConstantsBuffer;
	PixelShaderConstantBuffer1[Noesis::Shader::Custom_Effect] = nullptr;

	PixelShaderConstantBuffer0Hash[Noesis::Shader::RGBA] = &PSRgbaConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Mask] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Clear] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_Solid] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_Linear] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_Radial] = &PSRadialGradConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_Pattern] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_Pattern_Clamp] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_Pattern_Repeat] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_Pattern_MirrorU] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_Pattern_MirrorV] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_Pattern_Mirror] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_AA_Solid] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_AA_Linear] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_AA_Radial] = &PSRadialGradConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_AA_Pattern] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_AA_Pattern_Clamp] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_AA_Pattern_Repeat] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_AA_Pattern_MirrorU] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_AA_Pattern_MirrorV] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Path_AA_Pattern_Mirror] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_Solid] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_Linear] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_Radial] = &PSRadialGradConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_Pattern] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_Pattern_Clamp] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_Pattern_Repeat] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_Pattern_MirrorU] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_Pattern_MirrorV] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_Pattern_Mirror] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_LCD_Solid] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_LCD_Linear] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_LCD_Radial] = &PSRadialGradConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_LCD_Pattern] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_LCD_Pattern_Clamp] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_LCD_Pattern_Repeat] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_LCD_Pattern_MirrorU] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_LCD_Pattern_MirrorV] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::SDF_LCD_Pattern_Mirror] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Opacity_Solid] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Opacity_Linear] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Opacity_Radial] = &PSRadialGradConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Opacity_Pattern] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Opacity_Pattern_Clamp] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Opacity_Pattern_Repeat] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Opacity_Pattern_MirrorU] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Opacity_Pattern_MirrorV] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Opacity_Pattern_Mirror] = &PSOpacityConstantsHash;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Upsample] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Downsample] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Shadow] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Blur] = nullptr;
	PixelShaderConstantBuffer0Hash[Noesis::Shader::Custom_Effect] = nullptr;

	PixelShaderConstantBuffer1Hash[Noesis::Shader::RGBA] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Mask] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Clear] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_Solid] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_Linear] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_Radial] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_Pattern] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_AA_Solid] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_AA_Linear] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_AA_Radial] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_AA_Pattern] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_AA_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_AA_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_AA_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_AA_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Path_AA_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_Solid] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_Linear] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_Radial] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_Pattern] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_LCD_Solid] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_LCD_Linear] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_LCD_Radial] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_LCD_Pattern] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_LCD_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_LCD_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_LCD_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_LCD_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::SDF_LCD_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Opacity_Solid] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Opacity_Linear] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Opacity_Radial] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Opacity_Pattern] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Opacity_Pattern_Clamp] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Opacity_Pattern_Repeat] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Opacity_Pattern_MirrorU] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Opacity_Pattern_MirrorV] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Opacity_Pattern_Mirror] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Upsample] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Downsample] = nullptr;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Shadow] = &ShadowConstantsHash;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Blur] = &BlurConstantsHash;
	PixelShaderConstantBuffer1Hash[Noesis::Shader::Custom_Effect] = nullptr;

	DepthStencilStates[Noesis::StencilMode::Disabled] =         TStaticDepthStencilState<false, CF_Always>::GetRHI();
	DepthStencilStates[Noesis::StencilMode::Equal_Keep] =       TStaticDepthStencilState<false, CF_Always,           true, CF_Equal,  SO_Keep, SO_Keep, SO_Keep,      true, CF_Equal,  SO_Keep, SO_Keep, SO_Keep>::GetRHI();
	DepthStencilStates[Noesis::StencilMode::Equal_Incr] =       TStaticDepthStencilState<false, CF_Always,           true, CF_Equal,  SO_Keep, SO_Keep, SO_Increment, true, CF_Equal,  SO_Keep, SO_Keep, SO_Increment>::GetRHI();
	DepthStencilStates[Noesis::StencilMode::Equal_Decr] =       TStaticDepthStencilState<false, CF_Always,           true, CF_Equal,  SO_Keep, SO_Keep, SO_Decrement, true, CF_Equal,  SO_Keep, SO_Keep, SO_Decrement>::GetRHI();
	DepthStencilStates[Noesis::StencilMode::Clear] =            TStaticDepthStencilState<false, CF_Always,           true, CF_Always, SO_Keep, SO_Keep, SO_Zero,      true, CF_Always, SO_Keep, SO_Keep, SO_Zero>::GetRHI();
	DepthStencilStates[Noesis::StencilMode::Disabled_ZTest] =   TStaticDepthStencilState<false>::GetRHI();
	DepthStencilStates[Noesis::StencilMode::Equal_Keep_ZTest] = TStaticDepthStencilState<false, CF_DepthNearOrEqual, true, CF_Equal,  SO_Keep, SO_Keep, SO_Keep,      true, CF_Equal,  SO_Keep, SO_Keep, SO_Keep>::GetRHI();

	BlendStates[Noesis::BlendMode::Src] =              TStaticBlendState<CW_RGBA>::GetRHI();
	BlendStates[Noesis::BlendMode::SrcOver] =          TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_InverseSourceAlpha,  BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI();
	BlendStates[Noesis::BlendMode::SrcOver_Multiply] = TStaticBlendState<CW_RGBA, BO_Add, BF_DestColor, BF_InverseSourceAlpha,  BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI();
	BlendStates[Noesis::BlendMode::SrcOver_Screen] =   TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_InverseSourceColor,  BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI();
	BlendStates[Noesis::BlendMode::SrcOver_Additive] = TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_One,                 BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI();
	BlendStates[Noesis::BlendMode::SrcOver_Dual] =     TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_InverseSource1Color, BO_Add, BF_One, BF_InverseSource1Alpha>::GetRHI();

	BlendStatesWorldUI[Noesis::BlendMode::Src] =              TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_Zero,                BO_Add, BF_Zero, BF_InverseSourceAlpha>::GetRHI();
	BlendStatesWorldUI[Noesis::BlendMode::SrcOver] =          TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_InverseSourceAlpha,  BO_Add, BF_Zero, BF_InverseSourceAlpha>::GetRHI();
	BlendStatesWorldUI[Noesis::BlendMode::SrcOver_Multiply] = TStaticBlendState<CW_RGBA, BO_Add, BF_DestColor, BF_InverseSourceAlpha,  BO_Add, BF_Zero, BF_InverseSourceAlpha>::GetRHI();
	BlendStatesWorldUI[Noesis::BlendMode::SrcOver_Screen] =   TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_InverseSourceColor,  BO_Add, BF_Zero, BF_InverseSourceAlpha>::GetRHI();
	BlendStatesWorldUI[Noesis::BlendMode::SrcOver_Additive] = TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_One,                 BO_Add, BF_Zero, BF_InverseSourceAlpha>::GetRHI();
	BlendStatesWorldUI[Noesis::BlendMode::SrcOver_Dual] =     TStaticBlendState<CW_RGBA, BO_Add, BF_One,       BF_InverseSource1Color, BO_Add, BF_Zero, BF_InverseSource1Alpha>::GetRHI();

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
	VSConstantBufferRightEye.SafeRelease();
	TextureSizeBuffer.SafeRelease();
	PSRgbaConstantBuffer.SafeRelease();
	PSOpacityConstantBuffer.SafeRelease();
	PSRadialGradConstantBuffer.SafeRelease();
	BlurConstantsBuffer.SafeRelease();
	ShadowConstantsBuffer.SafeRelease();
}

uint32 GlyphCacheWidth[] = { 256, 512, 1024, 2048, 4096 };
uint32 GlyphCacheHeight[] = { 256, 512, 1024, 2048, 4096 };
static FNoesisRenderDevice* NoesisRenderDevice = nullptr;
static FNoesisRenderDevice* LinearNoesisRenderDevice = nullptr;

FNoesisRenderDevice* FNoesisRenderDevice::Get()
{
	if (!NoesisRenderDevice)
	{
		NoesisRenderDevice = new FNoesisRenderDevice(false);
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

FNoesisRenderDevice* FNoesisRenderDevice::GetLinear()
{
	if (!LinearNoesisRenderDevice)
	{
		LinearNoesisRenderDevice = new FNoesisRenderDevice(true);
		LinearNoesisRenderDevice->SetOffscreenWidth((uint32)FMath::Max(0, GetDefault<UNoesisSettings>()->OffscreenTextureWidth));
		LinearNoesisRenderDevice->SetOffscreenHeight((uint32)FMath::Max(0, GetDefault<UNoesisSettings>()->OffscreenTextureHeight));
		LinearNoesisRenderDevice->SetOffscreenSampleCount((uint32)GetDefault<UNoesisSettings>()->OffscreenTextureSampleCount);
		LinearNoesisRenderDevice->SetOffscreenDefaultNumSurfaces((uint32)FMath::Max(0, GetDefault<UNoesisSettings>()->OffscreenInitSurfaces));
		LinearNoesisRenderDevice->SetOffscreenMaxNumSurfaces((uint32)FMath::Max(0, GetDefault<UNoesisSettings>()->OffscreenMaxSurfaces));
		LinearNoesisRenderDevice->SetGlyphCacheWidth(GlyphCacheWidth[(uint8)GetDefault<UNoesisSettings>()->GlyphTextureSize]);
		LinearNoesisRenderDevice->SetGlyphCacheHeight(GlyphCacheHeight[(uint8)GetDefault<UNoesisSettings>()->GlyphTextureSize]);
	}
	return LinearNoesisRenderDevice;
}

void FNoesisRenderDevice::Destroy()
{
	delete NoesisRenderDevice;
	NoesisRenderDevice = nullptr;
	delete LinearNoesisRenderDevice;
	LinearNoesisRenderDevice = nullptr;
}

void FNoesisRenderDevice::SetRHICmdList(FRHICommandList* InRHICmdList)
{
	RHICmdList = InRHICmdList;
}

void FNoesisRenderDevice::SetWorldTime(FGameTime InWorldTime)
{
	WorldTime = InWorldTime;
}

void FNoesisRenderDevice::SetScene(FSceneInterface* InScene)
{
	Scene = InScene;
}

void FNoesisRenderDevice::CreateView(uint32 Left, uint32 Top, uint32 Right, uint32 Bottom, const FIntRect& ViewRect, const FMatrix& ViewProjectionMatrix)
{
	ViewLeft = Left;
	ViewTop = Top;
	ViewRight = Right;
	ViewBottom = Bottom;

	FSceneViewFamily::ConstructionValues ViewFamilyConstruction
	(
		nullptr,
		Scene,
		FEngineShowFlags(ESFIM_Game)
	);

#if UE_VERSION_OLDER_THAN(5, 0, 0)
	ViewFamilyConstruction.SetWorldTimes(WorldTime.GetWorldTimeSeconds(), WorldTime.GetDeltaWorldTimeSeconds(), WorldTime.GetRealTimeSeconds());
#else
	ViewFamilyConstruction.SetTime(WorldTime);
#endif
	ViewFamily = new FSceneViewFamily(ViewFamilyConstruction);
	FSceneViewInitOptions ViewInitOptions;
	memset(&ViewInitOptions, 0, sizeof(ViewInitOptions));
	ViewInitOptions.ViewFamily = ViewFamily;
	ViewInitOptions.SetViewRectangle(ViewRect);
	ViewInitOptions.ViewOrigin = FVector::ZeroVector;
	ViewInitOptions.ViewRotationMatrix = FMatrix::Identity;
	ViewInitOptions.ProjectionMatrix = ViewProjectionMatrix;
	GetRendererModule().CreateAndInitSingleView(FRHICommandListExecutor::GetImmediateCommandList(), ViewFamily, &ViewInitOptions);
	View = (FViewInfo*)ViewFamily->Views[0];
	ViewUniformBuffer = View->ViewUniformBuffer;
}

void FNoesisRenderDevice::DestroyView()
{
	if (View != nullptr)
	{
		delete View;
		View = nullptr;
	}

	if (ViewFamily != nullptr)
	{
		delete ViewFamily;
		ViewFamily = nullptr;
	}
}

Noesis::Ptr<Noesis::Texture> FNoesisRenderDevice::CreateTexture(uint32 InWidth, uint32 InHeight, uint32 InNumMipMaps, bool InAlpha)
{
	return *new FNoesisTexture(InWidth, InHeight, InNumMipMaps, InAlpha);
}

void FNoesisRenderDevice::SetRHITexture(Noesis::Texture* InTexture, FTexture2DRHIRef TextureRef)
{
	FNoesisTexture* Texture = (FNoesisTexture*)InTexture;
	Texture->ShaderResourceTexture = TextureRef;
}

Noesis::Ptr<Noesis::Texture> FNoesisRenderDevice::CreateTexture(UTexture* InTexture)
{
#if UE_VERSION_OLDER_THAN(4, 27, 0)
	if (!InTexture || !InTexture->Resource)
		return nullptr;

	FTextureResource* TextureResource = InTexture->Resource;
#else
	if (!InTexture || !InTexture->GetResource())
		return nullptr;

	FTextureResource* TextureResource = InTexture->GetResource();
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
		FTexture2DRHIRef TextureRef = Resource->GetTexture2DRHI();
		if (TextureRef)
		{
			check(Texture->Width == TextureRef->GetSizeX());
			check(Texture->Height == TextureRef->GetSizeY());
			check(Texture->NumMipMaps == TextureRef->GetNumMips());
			Texture->ShaderResourceTexture = TextureRef;
		}
		else
		{
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
					}
				}
			);
		}
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
	static Noesis::DeviceCaps Caps = { 0.f, IsLinearColor, false };
	return Caps;
}

static void NoesisCreateTargetableShaderResource2D(
	const TCHAR* Name,
	uint32 SizeX,
	uint32 SizeY,
	EPixelFormat Format,
	uint32 NumMips,
	ETextureCreateFlags Flags,
	ETextureCreateFlags TargetableTextureFlags,
	bool bForceSeparateTargetAndShaderResource,
	bool bForceSharedTargetAndShaderResource,
	FClearValueBinding ClearValue,
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
		if (bForceSeparateTargetAndShaderResource)
		{
			TargetableTextureFlags |= TexCreate_Memoryless;
		}
	}

	if (!bForceSeparateTargetAndShaderResource)
	{
		// Create a single texture that has both TargetableTextureFlags and TexCreate_ShaderResource set.
#if UE_VERSION_OLDER_THAN(5, 1, 0)
		FRHIResourceCreateInfo CreateInfo(Name);
		CreateInfo.ClearValueBinding = ClearValue;
		OutTargetableTexture = OutShaderResourceTexture = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, NumSamples, Flags | TargetableTextureFlags | TexCreate_ShaderResource, ERHIAccess::SRVGraphics, CreateInfo);
#else
		auto TextureDesc = FRHITextureCreateDesc::Create2D(Name)
			.SetExtent(SizeX, SizeY)
			.SetFormat(Format)
			.SetNumMips(NumMips)
			.SetNumSamples(NumSamples)
			.SetFlags(Flags | TargetableTextureFlags | TexCreate_ShaderResource)
			.SetInitialState(ERHIAccess::SRVGraphics)
			.SetClearValue(ClearValue);
		OutTargetableTexture = OutShaderResourceTexture = RHICreateTexture(TextureDesc);
#endif
		NOESIS_BIND_DEBUG_TEXTURE_LABEL(OutTargetableTexture, Name);
	}
	else
	{
		ETextureCreateFlags ResolveTargetableTextureFlags = TexCreate_ResolveTargetable;
		if (EnumHasAnyFlags(TargetableTextureFlags, TexCreate_DepthStencilTargetable))
		{
			ResolveTargetableTextureFlags |= TexCreate_DepthStencilResolveTarget;
		}
		// Create a texture that has TargetableTextureFlags set, and a second texture that has TexCreate_ResolveTargetable and TexCreate_ShaderResource set.
		TStringBuilder<64> RTName;
		RTName.Append(Name).Append(TEXT("_RT"));
		TStringBuilder<64> SRName;
		SRName.Append(Name).Append(TEXT("_SR"));
#if UE_VERSION_OLDER_THAN(5, 1, 0)
		FRHIResourceCreateInfo CreateInfo(*RTName);
		CreateInfo.ClearValueBinding = ClearValue;
		OutTargetableTexture = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, NumSamples, Flags | TargetableTextureFlags, ERHIAccess::RTV, CreateInfo);
		CreateInfo.DebugName = *SRName;
		OutShaderResourceTexture = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, 1, Flags | ResolveTargetableTextureFlags | TexCreate_ShaderResource, ERHIAccess::SRVGraphics, CreateInfo);
#else
		auto TargetableTextureDesc = FRHITextureCreateDesc::Create2D(*RTName)
			.SetExtent(SizeX, SizeY)
			.SetFormat(Format)
			.SetNumMips(NumMips)
			.SetNumSamples(NumSamples)
			.SetFlags(Flags | TargetableTextureFlags)
			.SetInitialState(ERHIAccess::RTV)
			.SetClearValue(ClearValue);
		OutTargetableTexture = RHICreateTexture(TargetableTextureDesc);
		auto ShaderResourceTextureDesc = FRHITextureCreateDesc::Create2D(*SRName)
			.SetExtent(SizeX, SizeY)
			.SetFormat(Format)
			.SetNumMips(NumMips)
			.SetNumSamples(1)
			.SetFlags(Flags | ResolveTargetableTextureFlags | TexCreate_ShaderResource)
			.SetInitialState(ERHIAccess::SRVGraphics)
			.SetClearValue(ClearValue);
		OutShaderResourceTexture = RHICreateTexture(ShaderResourceTextureDesc);
#endif
		NOESIS_BIND_DEBUG_TEXTURE_LABEL(OutTargetableTexture, *RTName);
		NOESIS_BIND_DEBUG_TEXTURE_LABEL(OutShaderResourceTexture, *SRName);
	}
}

static Noesis::Ptr<Noesis::RenderTarget> CreateRenderTarget(const TCHAR* Name, uint32 Width, uint32 Height, uint32 SampleCount, FTexture2DRHIRef DepthStencilTarget, bool IsLinearColor)
{
	EPixelFormat Format = PF_R8G8B8A8;
	uint32 NumMips = 1;
	ETextureCreateFlags Flags = IsLinearColor ? TexCreate_SRGB : TexCreate_None;
	ETextureCreateFlags TargetableTextureFlags = TexCreate_RenderTargetable | (IsLinearColor ? TexCreate_SRGB : TexCreate_None);
	bool bForceSeparateTargetAndShaderResource = false;
	FClearValueBinding ClearValue;
	FTexture2DRHIRef ColorTarget;
	FTexture2DRHIRef ShaderResourceTexture;
	NoesisCreateTargetableShaderResource2D(Name, Width, Height, Format, NumMips, Flags, TargetableTextureFlags, bForceSeparateTargetAndShaderResource, false, ClearValue, ColorTarget, ShaderResourceTexture, SampleCount);

	FNoesisRenderTarget* RenderTarget = new FNoesisRenderTarget();
	RenderTarget->Texture = *new FNoesisTexture(Width, Height, NumMips, true);
	RenderTarget->ColorTarget = ColorTarget;
	RenderTarget->Texture->ShaderResourceTexture = ShaderResourceTexture;
	RenderTarget->DepthStencilTarget = DepthStencilTarget;

	return Noesis::Ptr<Noesis::RenderTarget>(*RenderTarget);
}

Noesis::Ptr<Noesis::RenderTarget> FNoesisRenderDevice::CreateRenderTarget(const char* Label, uint32 Width, uint32 Height, uint32 SampleCount, bool NeedsStencil)
{
	TStringBuilder<64> Name;
	Name.Append(TEXT("Noesis.RenderTarget.")).Append(UTF8_TO_TCHAR(Label));
	FTexture2DRHIRef DepthStencilTarget;

	if (NeedsStencil)
	{
		TStringBuilder<64> DSName;
		DSName.Append(*Name).Append(TEXT("_DS"));
		uint32 NumMips = 1;
		EPixelFormat Format = PF_DepthStencil;
		ETextureCreateFlags TargetableTextureFlags = TexCreate_DepthStencilTargetable | TexCreate_Memoryless;
		ERHIAccess Access = ERHIAccess::DSVWrite;
		FClearValueBinding ClearValue(0.f, 0);
#if UE_VERSION_OLDER_THAN(5, 1, 0)
		FRHIResourceCreateInfo CreateInfo(*DSName);
		CreateInfo.ClearValueBinding = ClearValue;
		DepthStencilTarget = RHICreateTexture2D(Width, Height, Format, NumMips, SampleCount, TargetableTextureFlags, Access, CreateInfo);
#else
		auto DepthStencilTargetDesc = FRHITextureCreateDesc::Create2D(*DSName)
			.SetExtent(Width, Height)
			.SetFormat(Format)
			.SetNumMips(NumMips)
			.SetNumSamples(SampleCount)
			.SetFlags(TargetableTextureFlags)
			.SetInitialState(Access)
			.SetClearValue(ClearValue);
		DepthStencilTarget = RHICreateTexture(DepthStencilTargetDesc);
#endif
		NOESIS_BIND_DEBUG_TEXTURE_LABEL(DepthStencilTarget, *DSName);
	}

	return ::CreateRenderTarget(*Name, Width, Height, SampleCount, DepthStencilTarget, IsLinearColor);
}

Noesis::Ptr<Noesis::RenderTarget> FNoesisRenderDevice::CloneRenderTarget(const char* Label, Noesis::RenderTarget* InSharedRenderTarget)
{
	TStringBuilder<64> Name;
	Name.Append(TEXT("Noesis.RenderTarget.")).Append(UTF8_TO_TCHAR(Label)).ToString();
	FNoesisRenderTarget* SharedRenderTarget = (FNoesisRenderTarget*)InSharedRenderTarget;

	uint32 Width = SharedRenderTarget->ColorTarget->GetSizeX();
	uint32 Height = SharedRenderTarget->ColorTarget->GetSizeY();
	uint32 SampleCount = SharedRenderTarget->ColorTarget->GetNumSamples();
	FTexture2DRHIRef DepthStencilTarget = SharedRenderTarget->DepthStencilTarget;

	return ::CreateRenderTarget(*Name, Width, Height, SampleCount, DepthStencilTarget, IsLinearColor);
}

Noesis::Ptr<Noesis::Texture> FNoesisRenderDevice::CreateTexture(const char* Label, uint32 Width, uint32 Height, uint32 NumLevels, Noesis::TextureFormat::Enum TextureFormat, const void** Data)
{
	TStringBuilder<64> Name;
	Name.Append(TEXT("Noesis.Texture.")).Append(UTF8_TO_TCHAR(Label)).ToString();
	uint32 SizeX = (uint32)Width;
	uint32 SizeY = (uint32)Height;
	EPixelFormat Formats[Noesis::TextureFormat::Count] = { PF_R8G8B8A8, PF_R8G8B8A8, PF_G8 };
	EPixelFormat Format = Formats[TextureFormat];
	uint32 NumMips = (uint32)NumLevels;
	uint32 NumSamples = 1;
	ETextureCreateFlags Flags = IsLinearColor ? TexCreate_SRGB : TexCreate_None;
	ERHIAccess Access = ERHIAccess::SRVGraphics;
#if UE_VERSION_OLDER_THAN(5, 1, 0)
	FRHIResourceCreateInfo CreateInfo(*Name);
	FTexture2DRHIRef ShaderResourceTexture = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, NumSamples, Flags, Access, CreateInfo);
#else
	auto ShaderResourceTextureDesc = FRHITextureCreateDesc::Create2D(*Name)
		.SetExtent(SizeX, SizeY)
		.SetFormat(Format)
		.SetNumMips(NumMips)
		.SetNumSamples(NumSamples)
		.SetFlags(Flags)
		.SetInitialState(Access);
	FTexture2DRHIRef ShaderResourceTexture = RHICreateTexture(ShaderResourceTextureDesc);
#endif
	NOESIS_BIND_DEBUG_TEXTURE_LABEL(ShaderResourceTexture, *Name);

	FNoesisTexture* Texture = new FNoesisTexture(SizeX, SizeY, NumMips, TextureFormat == Noesis::TextureFormat::RGBA8);
	Texture->ShaderResourceTexture = ShaderResourceTexture;

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
	FUniformBufferStaticBindings StaticUniformBufferBindings;
	StaticUniformBufferBindings.TryAddUniformBuffer(SceneTexturesUniformBuffer);
	StaticUniformBufferBindings.TryAddUniformBuffer(ViewUniformBuffer);
	RHICmdList->SetStaticUniformBuffers(MoveTemp(StaticUniformBufferBindings));
}

void FNoesisRenderDevice::EndOffscreenRender()
{
	RHICmdList->SetStaticUniformBuffers({});
}

void FNoesisRenderDevice::BeginOnscreenRender()
{
	FUniformBufferStaticBindings StaticUniformBufferBindings;
	StaticUniformBufferBindings.TryAddUniformBuffer(SceneTexturesUniformBuffer);
	StaticUniformBufferBindings.TryAddUniformBuffer(ViewUniformBuffer);
	RHICmdList->SetStaticUniformBuffers(MoveTemp(StaticUniformBufferBindings));
}

void FNoesisRenderDevice::EndOnscreenRender()
{
	RHICmdList->SetStaticUniformBuffers({});
}

void FNoesisRenderDevice::SetRenderTarget(Noesis::RenderTarget* Surface)
{
	check(RHICmdList);
#if WANTS_DRAW_MESH_EVENTS
	BEGIN_DRAW_EVENTF(*RHICmdList, SetRenderTarget, SetRenderTargetEvent, TEXT("SetRenderTarget"));
#endif
	check(Surface);
	FNoesisRenderTarget* RenderTarget = (FNoesisRenderTarget*)Surface;
	bool NeedsResolve = (RenderTarget->ColorTarget != RenderTarget->Texture->ShaderResourceTexture) && RenderTarget->ColorTarget->IsMultisampled();
	constexpr uint8 DontLoad_Resolve = (((uint8)ERenderTargetLoadAction::ENoAction << (uint8)ERenderTargetActions::LoadOpMask) | (uint8)ERenderTargetStoreAction::EMultisampleResolve);
	ERenderTargetActions ColorTargetActions = NeedsResolve ? (ERenderTargetActions)DontLoad_Resolve : ERenderTargetActions::DontLoad_Store;

	EDepthStencilTargetActions DepthStencilTargetActions =
		MakeDepthStencilTargetActions(ERenderTargetActions::DontLoad_DontStore, ERenderTargetActions::DontLoad_DontStore);

	check(RHICmdList->IsOutsideRenderPass());
	if (RenderTarget->ColorTarget == RenderTarget->Texture->ShaderResourceTexture)
	{
		RHICmdList->Transition(FRHITransitionInfo(RenderTarget->ColorTarget, ERHIAccess::SRVGraphics, ERHIAccess::RTV));
	}
	else if (NeedsResolve)
	{
		RHICmdList->Transition(FRHITransitionInfo(RenderTarget->Texture->ShaderResourceTexture, ERHIAccess::SRVGraphics, ERHIAccess::RTV | ERHIAccess::ResolveDst));
	}

	if (RenderTarget->DepthStencilTarget)
	{
		FRHIRenderPassInfo RPInfo(RenderTarget->ColorTarget, ColorTargetActions, nullptr,
			RenderTarget->DepthStencilTarget, DepthStencilTargetActions, nullptr, FExclusiveDepthStencil::DepthNop_StencilWrite);

		// There's a bug in FRHIRenderPassInfo constructors. Can't pass it there.
		// check(!ResolveColorRT || ResolveColorRT->IsMultisampled()) should be
		// check(!ResolveColorRT || !ResolveColorRT->IsMultisampled());
		RPInfo.ColorRenderTargets[0].ResolveTarget = NeedsResolve ? RenderTarget->Texture->ShaderResourceTexture : nullptr;
		RHICmdList->BeginRenderPass(RPInfo, TEXT("NoesisOffScreen"));
	}
	else
	{
		FRHIRenderPassInfo RPInfo(RenderTarget->ColorTarget, ColorTargetActions, nullptr);

		// There's a bug in FRHIRenderPassInfo constructors. Can't pass it there.
		// check(!ResolveColorRT || ResolveColorRT->IsMultisampled()) should be
		// check(!ResolveColorRT || !ResolveColorRT->IsMultisampled());
		RPInfo.ColorRenderTargets[0].ResolveTarget = NeedsResolve ? RenderTarget->Texture->ShaderResourceTexture : nullptr;
		RHICmdList->BeginRenderPass(RPInfo, TEXT("NoesisOffScreen"));
	}
	RHICmdList->SetViewport(0, 0, 0.0f, RenderTarget->ColorTarget->GetSizeX(), RenderTarget->ColorTarget->GetSizeY(), 1.0f);

	CreateView(0, 0, RenderTarget->ColorTarget->GetSizeX(), RenderTarget->ColorTarget->GetSizeY(), FIntRect(0, 0, RenderTarget->ColorTarget->GetSizeX(), RenderTarget->ColorTarget->GetSizeY()), FMatrix::Identity);
}

void FNoesisRenderDevice::BeginTile(Noesis::RenderTarget* Surface, const Noesis::Tile& Tile)
{
	check(RHICmdList);
	FNoesisRenderTarget* RenderTarget = (FNoesisRenderTarget*)Surface;
	RHICmdList->SetScissorRect(true, Tile.x, (int32)(RenderTarget->Texture->ShaderResourceTexture->GetSizeY() - (Tile.y + Tile.height)), Tile.x + Tile.width, (int32)(RenderTarget->Texture->ShaderResourceTexture->GetSizeY() - Tile.y));
}

void FNoesisRenderDevice::EndTile(Noesis::RenderTarget* Surface)
{
	check(RHICmdList);
	RHICmdList->SetScissorRect(false, 0, 0, 0, 0);
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
		if (!RenderTarget->ColorTarget->IsMultisampled())
		{
			RHICmdList->Transition(FRHITransitionInfo(RenderTarget->ColorTarget, ERHIAccess::RTV, ERHIAccess::CopySrc));
			RHICmdList->Transition(FRHITransitionInfo(RenderTarget->Texture->ShaderResourceTexture, ERHIAccess::SRVGraphics, ERHIAccess::CopyDest));

			for (uint32 TileIndex = 0; TileIndex != (uint32)NumTiles; ++TileIndex)
			{
				const Noesis::Tile& Tile = Tiles[TileIndex];

				FRHICopyTextureInfo CopyTextureInfo;
				CopyTextureInfo.Size = FIntVector(Tile.width, Tile.height, 1);
				CopyTextureInfo.SourcePosition = FIntVector((int32)Tile.x, (int32)(RenderTarget->Texture->ShaderResourceTexture->GetSizeY() - (Tile.y + Tile.height)), 0);
				CopyTextureInfo.DestPosition = CopyTextureInfo.SourcePosition;
				RHICmdList->CopyTexture(RenderTarget->ColorTarget, RenderTarget->Texture->ShaderResourceTexture, CopyTextureInfo);
			}

			RHICmdList->Transition(FRHITransitionInfo(RenderTarget->ColorTarget, ERHIAccess::CopySrc, ERHIAccess::RTV));
			RHICmdList->Transition(FRHITransitionInfo(RenderTarget->Texture->ShaderResourceTexture, ERHIAccess::CopyDest, ERHIAccess::SRVGraphics));
		}
		else
		{
			RHICmdList->Transition(FRHITransitionInfo(RenderTarget->Texture->ShaderResourceTexture, ERHIAccess::RTV | ERHIAccess::ResolveDst, ERHIAccess::SRVGraphics));
		}
	}
	else
	{
		RHICmdList->Transition(FRHITransitionInfo(RenderTarget->ColorTarget, ERHIAccess::RTV, ERHIAccess::SRVGraphics));
	}

#if WANTS_DRAW_MESH_EVENTS
	STOP_DRAW_EVENT(SetRenderTargetEvent);
#endif

	DestroyView();
}

void* FNoesisRenderDevice::MapVertices(uint32 Bytes)
{
#if UE_VERSION_OLDER_THAN(5, 0, 0)
	void* Result = RHILockVertexBuffer(DynamicVertexBuffer, 0, Bytes, RLM_WriteOnly);
#elif UE_VERSION_OLDER_THAN(5, 3, 0)
	void* Result = RHILockBuffer(DynamicVertexBuffer, 0, Bytes, RLM_WriteOnly);
#else
	void* Result = RHICmdList->LockBuffer(DynamicVertexBuffer, 0, Bytes, RLM_WriteOnly);
#endif
	return Result;
}

void FNoesisRenderDevice::UnmapVertices()
{
#if UE_VERSION_OLDER_THAN(5, 0, 0)
	RHIUnlockVertexBuffer(DynamicVertexBuffer);
#elif UE_VERSION_OLDER_THAN(5, 3, 0)
	RHIUnlockBuffer(DynamicVertexBuffer);
#else
	RHICmdList->UnlockBuffer(DynamicVertexBuffer);
#endif
}

void* FNoesisRenderDevice::MapIndices(uint32 Bytes)
{
#if UE_VERSION_OLDER_THAN(5, 0, 0)
	void* Result = RHILockIndexBuffer(DynamicIndexBuffer, 0, Bytes, RLM_WriteOnly);
#elif UE_VERSION_OLDER_THAN(5, 3, 0)
	void* Result = RHILockBuffer(DynamicIndexBuffer, 0, Bytes, RLM_WriteOnly);
#else
	void* Result = RHICmdList->LockBuffer(DynamicIndexBuffer, 0, Bytes, RLM_WriteOnly);
#endif
	return Result;
}

void FNoesisRenderDevice::UnmapIndices()
{
#if UE_VERSION_OLDER_THAN(5, 0, 0)
	RHIUnlockIndexBuffer(DynamicIndexBuffer);
#elif UE_VERSION_OLDER_THAN(5, 3, 0)
	RHIUnlockBuffer(DynamicIndexBuffer);
#else
	RHICmdList->UnlockBuffer(DynamicIndexBuffer);
#endif
}

template<>
void FNoesisRenderDevice::SetPatternMaterialParameters<FNoesisPSBase>(const Noesis::Batch& Batch, TShaderRef<FNoesisPSBase>& PixelShader)
{
	if (Batch.pattern != nullptr)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.pattern);
		FRHITexture* PatternTexture = Texture->ShaderResourceTexture;
		if (PatternTexture != nullptr)
		{
			FRHISamplerState* PatternSamplerState = SamplerStates[Batch.patternSampler.v];
			PixelShader->SetPatternTexture(*RHICmdList, PatternTexture, PatternSamplerState);
		}
	}
}

template<>
void FNoesisRenderDevice::SetPatternMaterialParameters<FNoesisMaterialPSBase>(const Noesis::Batch& Batch, TShaderRef<FNoesisMaterialPSBase>& PixelShader)
{
	FMaterialRenderProxy* MaterialProxy = ((FNoesisMaterial*)Batch.pixelShader)->MaterialProxy;
#if UE_VERSION_OLDER_THAN(4, 27, 0)
	const FMaterial* Material = MaterialProxy->GetMaterial(GMaxRHIFeatureLevel);
#else
	const FMaterial* Material = &MaterialProxy->GetIncompleteMaterialWithFallback(GMaxRHIFeatureLevel);
#endif
	FRHIPixelShader* ShaderRHI = RHICmdList->GetBoundPixelShader();
	PixelShader->SetViewParameters(*RHICmdList, ShaderRHI, *View, ViewUniformBuffer);
#if UE_VERSION_OLDER_THAN(5, 1, 0)
	PixelShader->SetParameters<FRHIPixelShader>(*RHICmdList, ShaderRHI, MaterialProxy, *Material, *View);
#else
	PixelShader->SetParameters<FRHIPixelShader, FRHICommandList>(*RHICmdList, ShaderRHI, MaterialProxy, *Material, *View);
#endif
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
#if UE_VERSION_OLDER_THAN(4, 27, 0)
	const FMaterial* Material = MaterialProxy->GetMaterial(GMaxRHIFeatureLevel);
#else
	const FMaterial* Material = &MaterialProxy->GetIncompleteMaterialWithFallback(GMaxRHIFeatureLevel);
#endif
	FRHIPixelShader* ShaderRHI = RHICmdList->GetBoundPixelShader();
	PixelShader->SetViewParameters(*RHICmdList, ShaderRHI, *View, ViewUniformBuffer);

	FNoesisTexture* Texture = (FNoesisTexture*)(Batch.pattern);
	FRHITexture* PatternTexture = Texture->ShaderResourceTexture;
	//FRHISamplerState* PatternSamplerState = SamplerStates[Batch.patternSampler.v];
	FRHISamplerState* PatternSamplerState = TStaticSamplerState<SF_Point, AM_Clamp, AM_Clamp>::GetRHI(); // This should be point samplig for the behavior to be the same as UE4's
	FNoesisPostProcessMaterialParameters Params = {};
	Params.View = ViewUniformBuffer;
	Params.SceneTextures.SceneTextures = SceneTexturesUniformBuffer;
	Params.PostProcessInput_BilinearSampler = TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Clamp>::GetRHI();
	Params.PostProcessInput_0_Texture = PatternTexture;
	Params.PostProcessInput_0_Sampler = PatternSamplerState;
	// Texture extent in pixels.
	{
		const FVector2f Extent(Texture->GetWidth(), Texture->GetHeight());
		const FVector2f ViewportMin(0.0f, 0.0f);
		const FVector2f ViewportMax(Texture->GetWidth(), Texture->GetHeight());
		const FVector2f ViewportSize = ViewportMax - ViewportMin;

		FScreenPassTextureViewportParameters& Viewport = Params.PostProcessInput;

		Viewport.Extent = Extent;
		Viewport.ExtentInverse = FVector2f(1.0f / Extent.X, 1.0f / Extent.Y);

		Viewport.ScreenPosToViewportScale = FVector2f(0.5f, -0.5f) * ViewportSize;
		Viewport.ScreenPosToViewportBias = (0.5f * ViewportSize) + ViewportMin;

		Viewport.ViewportMin = FIntPoint(0, 0);
		Viewport.ViewportMax = FIntPoint(Texture->GetWidth(), Texture->GetHeight());

		Viewport.ViewportSize = ViewportSize;
		Viewport.ViewportSizeInverse = FVector2f(1.0f / Viewport.ViewportSize.X, 1.0f / Viewport.ViewportSize.Y);

		Viewport.UVViewportMin = ViewportMin * Viewport.ExtentInverse;
		Viewport.UVViewportMax = ViewportMax * Viewport.ExtentInverse;

		Viewport.UVViewportSize = Viewport.UVViewportMax - Viewport.UVViewportMin;
		Viewport.UVViewportSizeInverse = FVector2f(1.0f / Viewport.UVViewportSize.X, 1.0f / Viewport.UVViewportSize.Y);

		Viewport.UVViewportBilinearMin = Viewport.UVViewportMin + 0.5f * Viewport.ExtentInverse;
		Viewport.UVViewportBilinearMax = Viewport.UVViewportMax - 0.5f * Viewport.ExtentInverse;
	}

	{
		const FVector2f Extent(ViewRight - ViewLeft, ViewBottom - ViewTop);
		const FVector2f ViewportMin(ViewLeft, ViewTop);
		const FVector2f ViewportMax(ViewRight, ViewBottom);
		const FVector2f ViewportSize = ViewportMax - ViewportMin;

		FScreenPassTextureViewportParameters& Viewport = Params.PostProcessOutput;

		Viewport.Extent = Extent;
		Viewport.ExtentInverse = FVector2f(1.0f / Extent.X, 1.0f / Extent.Y);

		Viewport.ScreenPosToViewportScale = FVector2f(0.5f, -0.5f) * ViewportSize;
		Viewport.ScreenPosToViewportBias = (0.5f * ViewportSize) + ViewportMin;

		Viewport.ViewportMin = FIntPoint(ViewLeft, ViewTop);
		Viewport.ViewportMax = FIntPoint(ViewRight, ViewBottom);

		Viewport.ViewportSize = ViewportSize;
		Viewport.ViewportSizeInverse = FVector2f(1.0f / Viewport.ViewportSize.X, 1.0f / Viewport.ViewportSize.Y);

		Viewport.UVViewportMin = ViewportMin * Viewport.ExtentInverse;
		Viewport.UVViewportMax = ViewportMax * Viewport.ExtentInverse;

		Viewport.UVViewportSize = Viewport.UVViewportMax - Viewport.UVViewportMin;
		Viewport.UVViewportSizeInverse = FVector2f(1.0f / Viewport.UVViewportSize.X, 1.0f / Viewport.UVViewportSize.Y);

		Viewport.UVViewportBilinearMin = Viewport.UVViewportMin + 0.5f * Viewport.ExtentInverse;
		Viewport.UVViewportBilinearMax = Viewport.UVViewportMax - 0.5f * Viewport.ExtentInverse;
	}

	PixelShader->SetParameters(*RHICmdList, PixelShader, *View, MaterialProxy, Params);
}

static inline bool BufferNeedsUpdate(uint32& BufferHash, const Noesis::UniformData& UniformData)
{
	// There's no data.
	if (UniformData.values == nullptr)
		return false;

	// Buffer is up to date.
	if (BufferHash == UniformData.hash)
		return false;

	return true;
}

static inline void UpdateUniformBuffer(FRHICommandList* RHICmdList, FUniformBufferRHIRef& UniformBuffer, uint32 UniformDataSize, const void* UniformDataValues)
{
	check(UniformBuffer != nullptr);

	const auto& UniformBufferLayout = UniformBuffer->GetLayout();
	uint32 UniformBufferSize = UniformBufferLayout.ConstantBufferSize;

	// Need a copy on the stack because RHI requires a 16 byte alignment and 16 byte padding.
	// Reading from UniformData.values can cause an OOB read if UniformDataSize < UniformBufferSize.
	// We allocate UniformBufferSize bytes but only memcpy UniformDataSize bytes.
	check(UniformDataSize <= UniformBufferSize);
	void* UniformBufferData = FMemory_Alloca(UniformBufferSize);
	FMemory::Memcpy(UniformBufferData, UniformDataValues, UniformDataSize);

#if PLATFORM_APPLE
	// UniformBuffers on Metal are broken. They are all treated as Volatile, and new data is not pushed to the GPU after an update.
#if UE_VERSION_OLDER_THAN(5, 0, 0)
	UniformBuffer = RHICreateUniformBuffer(UniformBufferData, UniformBufferLayout, UniformBuffer_MultiFrame, EUniformBufferValidation::ValidateResources);
#else
	UniformBuffer = RHICreateUniformBuffer(UniformBufferData, &UniformBufferLayout, UniformBuffer_MultiFrame, EUniformBufferValidation::ValidateResources);
#endif
#else
#if UE_VERSION_OLDER_THAN(5, 3, 0)
	RHIUpdateUniformBuffer(UniformBuffer, UniformBufferData);
#else
	RHICmdList->UpdateUniformBuffer(UniformBuffer, UniformBufferData);
#endif
#endif
}

static inline bool ConditionalUpdateUniformBuffer(FRHICommandList* RHICmdList, FUniformBufferRHIRef& UniformBuffer, uint32& BufferHash, const Noesis::UniformData& UniformData)
{
	if (!BufferNeedsUpdate(BufferHash, UniformData))
		return false;

	uint32 UniformDataSize = UniformData.numDwords * 4;
	const void* UniformDataValues = UniformData.values;
	UpdateUniformBuffer(RHICmdList, UniformBuffer, UniformDataSize, UniformDataValues);

	BufferHash = UniformData.hash;

	return true;
}

void FNoesisRenderDevice::DrawBatch(const Noesis::Batch& Batch)
{
	check(RHICmdList);
	FGraphicsPipelineStateInitializer GraphicsPSOInit;
	RHICmdList->ApplyCachedRenderTargets(GraphicsPSOInit);

	GraphicsPSOInit.DepthStencilState = DepthStencilStates[Batch.renderState.f.stencilMode];

	GraphicsPSOInit.BlendState = Batch.renderState.f.colorEnable ? (IsWorldUI ? BlendStatesWorldUI[Batch.renderState.f.blendMode] : BlendStates[Batch.renderState.f.blendMode]) : TStaticBlendState<CW_NONE>::GetRHI();

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
#if UE_VERSION_OLDER_THAN(4, 27, 0)
			const FMaterial* Material = MaterialProxy->GetMaterial(GMaxRHIFeatureLevel);
#else
			const FMaterial* Material = &MaterialProxy->GetIncompleteMaterialWithFallback(GMaxRHIFeatureLevel);
#endif
			if (UsingCustomEffect)
			{
				UsingMaterialShader = false;
#if UE_VERSION_OLDER_THAN(4, 27, 0)
				const FMaterialShaderMap* MaterialShaderMap = Material->GetRenderingThreadShaderMap();
				CustomEffectPixelShader = MaterialShaderMap->GetShader<FNoesisCustomEffectPS>();
#else
				FMaterialShaderTypes ShaderTypes;
				ShaderTypes.AddShaderType<FNoesisCustomEffectPS>();
				FMaterialShaders Shaders;
				Material->TryGetShaders(ShaderTypes, nullptr, Shaders);
				Shaders.TryGetPixelShader(CustomEffectPixelShader);
#endif
			}
			else
			{
				MaterialPixelShader = GetMaterialPixelShader(Material, ShaderCode, IsLinearColor);
			}
		}
	}

	bool PatternConvertColor = false;
	if (Batch.pattern != nullptr)
	{
		FNoesisTexture* Texture = (FNoesisTexture*)(Batch.pattern);
		FRHITexture* PatternTexture = Texture->ShaderResourceTexture;
		if (PatternTexture != nullptr)
		{
			// Read the comment next to PATTERN_SRGB and PATTERN_LINEAR in FNoesisPS::ModifyCompilationEnvironment
			PatternConvertColor = IsLinearColor != EnumHasAnyFlags(PatternTexture->GetFlags(), TexCreate_SRGB);
		}
	}

	uint32 VertexShaderCode = Noesis::VertexForShader[ShaderCode];
	uint32 VertexFormatCode = Noesis::FormatForVertex[VertexShaderCode];
	FVertexDeclarationRHIRef& VertexDeclaration = VertexDeclarations[VertexFormatCode];
	TShaderRef<FNoesisVSBase> VertexShader = Batch.singlePassStereo ? VertexShadersStereo[VertexShaderCode] : VertexShaders[VertexShaderCode];
	TShaderRef<FNoesisPSBase> PixelShader = PatternConvertColor ? PixelShadersPatternConvertColor[ShaderCode] : PixelShaders[ShaderCode];
	FUniformBufferRHIRef& PSUniformBuffer0 = *PixelShaderConstantBuffer0[ShaderCode];
	FUniformBufferRHIRef& PSUniformBuffer1 = *PixelShaderConstantBuffer1[ShaderCode];
	uint32& PSUniformBuffer0Hash = *PixelShaderConstantBuffer0Hash[ShaderCode];
	uint32& PSUniformBuffer1Hash = *PixelShaderConstantBuffer1Hash[ShaderCode];
	GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = VertexDeclaration;
	GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
	GraphicsPSOInit.BoundShaderState.PixelShaderRHI = UsingCustomEffect ? CustomEffectPixelShader.GetPixelShader() : (UsingMaterialShader ? MaterialPixelShader.GetPixelShader() : PixelShader.GetPixelShader());
	GraphicsPSOInit.PrimitiveType = PT_TriangleList;

	// This can happen when the shaders are being recompiled in the editor.
	if (!VertexShader.IsValid())
		return;

	if (UsingCustomEffect)
	{
		if (!CustomEffectPixelShader.IsValid() || !ViewUniformBuffer.IsValid() || !SceneTexturesUniformBuffer.IsValid())
			return;
	}
	else if (UsingMaterialShader)
	{
		if (!MaterialPixelShader.IsValid() || !ViewUniformBuffer.IsValid())
			return;
	}
	else
	{
		if (!PixelShader.IsValid())
			return;
	}

#if UE_VERSION_OLDER_THAN(5, 0, 0)
	SetGraphicsPipelineState(*RHICmdList, GraphicsPSOInit);
#else
	SetGraphicsPipelineState(*RHICmdList, GraphicsPSOInit, Batch.stencilRef);
#endif

	uint32 NumInstances = 1;

	// Update the uniform buffers
	if (Batch.singlePassStereo)
	{
		//GraphicsPSOInit.MultiViewCount = 2;
		if (GraphicsPSOInit.MultiViewCount == 0)
		{
			NumInstances = 2;
		}

		const Noesis::UniformData& UniformData = Batch.vertexUniforms[0];
		if (BufferNeedsUpdate(VSConstantsHash, UniformData))
		{
			uint32 UniformDataSize = UniformData.numDwords * 4 / 2;
			const uint8* UniformDataValues = (const uint8 *)UniformData.values;
			UpdateUniformBuffer(RHICmdList, VSConstantBuffer, UniformDataSize, UniformDataValues);

			UniformDataValues += UniformDataSize;
			UpdateUniformBuffer(RHICmdList, VSConstantBufferRightEye, UniformDataSize, UniformDataValues);

			VSConstantsHash = UniformData.hash;
		}

		VertexShader->SetVSConstantsRightEye(*RHICmdList, VSConstantBufferRightEye);
	}
	else
	{
		ConditionalUpdateUniformBuffer(RHICmdList, VSConstantBuffer, VSConstantsHash, Batch.vertexUniforms[0]);
	}

	VertexShader->SetVSConstants(*RHICmdList, VSConstantBuffer);

	ConditionalUpdateUniformBuffer(RHICmdList, TextureSizeBuffer, TextureSizeHash, Batch.vertexUniforms[1]);

	ConditionalUpdateUniformBuffer(RHICmdList, PSUniformBuffer0, PSUniformBuffer0Hash, Batch.pixelUniforms[0]);

	ConditionalUpdateUniformBuffer(RHICmdList, PSUniformBuffer1, PSUniformBuffer1Hash, Batch.pixelUniforms[1]);

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

	RHICmdList->DrawIndexedPrimitive(DynamicIndexBuffer, 0, 0, Batch.numVertices, Batch.startIndex, Batch.numIndices / 3, NumInstances);
}
