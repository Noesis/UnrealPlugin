////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// RenderCore includes
#include "RenderResource.h"
#include "GlobalShader.h"
#include "ShaderParameterUtils.h"

// Renderer includes
#include "MaterialShader.h"
#include "Runtime/Renderer/Private/ScreenPass.h"
#include "Runtime/Renderer/Private/PostProcess/PostProcessMaterial.h"

// Noesis includes
#include "NoesisSDK.h"

template<Noesis::Shader::Vertex::Format::Enum VertexFormat>
class FNoesisVertexDeclaration : public FRenderResource
{
public:

	FVertexDeclarationRHIRef VertexDeclarationRHI;

	const EVertexElementType UnrealVertexTypes[Noesis::Shader::Vertex::Format::Attr::Type::Count] =
	{
		VET_Float1,
		VET_Float2,
		VET_Float4,
		VET_Color,
		VET_UShort4N
	};

	virtual ~FNoesisVertexDeclaration()
	{
	}

	virtual void InitRHI() override
	{
		const uint16 Stride = (uint16)Noesis::SizeForFormat[VertexFormat];
		const uint8 Attributes = (uint8)Noesis::AttributesForFormat[VertexFormat];
		FVertexDeclarationElementList Elements;
		uint8 Offset = 0;
		uint8 AttributeMask = 1;
		for (uint32 AttrIndex = 0; AttrIndex < (uint32)Noesis::Shader::Vertex::Format::Attr::Count; ++AttrIndex)
		{
			bool HasAttribute = (Attributes & AttributeMask) != 0;
			if (HasAttribute)
			{
				uint8 Type = (uint8)Noesis::TypeForAttr[AttrIndex];
				Elements.Add(FVertexElement(0, Offset, UnrealVertexTypes[Type], (uint8)AttrIndex, Stride));
				Offset += Noesis::SizeForType[Type];
			}
			AttributeMask <<= 1;
		}
		check(Offset == Stride);
		VertexDeclarationRHI = RHICreateVertexDeclaration(Elements);
	}

	virtual void ReleaseRHI() override
	{
		VertexDeclarationRHI.SafeRelease();
	}
};

typedef FNoesisVertexDeclaration<Noesis::Shader::Vertex::Format::Pos> FNoesisPosVertexDeclaration;
typedef FNoesisVertexDeclaration<Noesis::Shader::Vertex::Format::PosColor> FNoesisPosColorVertexDeclaration;
typedef FNoesisVertexDeclaration<Noesis::Shader::Vertex::Format::PosTex0> FNoesisPosTex0VertexDeclaration;
typedef FNoesisVertexDeclaration<Noesis::Shader::Vertex::Format::PosTex0Rect> FNoesisPosTex0RectVertexDeclaration;
typedef FNoesisVertexDeclaration<Noesis::Shader::Vertex::Format::PosTex0RectTile> FNoesisPosTex0RectTileVertexDeclaration;
typedef FNoesisVertexDeclaration<Noesis::Shader::Vertex::Format::PosColorCoverage> FNoesisPosColorCoverageVertexDeclaration;
typedef FNoesisVertexDeclaration<Noesis::Shader::Vertex::Format::PosTex0Coverage> FNoesisPosTex0CoverageVertexDeclaration;
typedef FNoesisVertexDeclaration<Noesis::Shader::Vertex::Format::PosTex0CoverageRect> FNoesisPosTex0CoverageRectVertexDeclaration;
typedef FNoesisVertexDeclaration<Noesis::Shader::Vertex::Format::PosTex0CoverageRectTile> FNoesisPosTex0CoverageRectTileVertexDeclaration;
typedef FNoesisVertexDeclaration<Noesis::Shader::Vertex::Format::PosColorTex1> FNoesisPosColorTex1VertexDeclaration;
typedef FNoesisVertexDeclaration<Noesis::Shader::Vertex::Format::PosTex0Tex1> FNoesisPosTex0Tex1VertexDeclaration;
typedef FNoesisVertexDeclaration<Noesis::Shader::Vertex::Format::PosTex0Tex1Rect> FNoesisPosTex0Tex1RectVertexDeclaration;
typedef FNoesisVertexDeclaration<Noesis::Shader::Vertex::Format::PosTex0Tex1RectTile> FNoesisPosTex0Tex1RectTileVertexDeclaration;
typedef FNoesisVertexDeclaration<Noesis::Shader::Vertex::Format::PosColorTex0Tex1> FNoesisPosColorTex0Tex1VertexDeclaration;
typedef FNoesisVertexDeclaration<Noesis::Shader::Vertex::Format::PosColorTex1Rect> FNoesisPosColorTex1RectVertexDeclaration;
typedef FNoesisVertexDeclaration<Noesis::Shader::Vertex::Format::PosColorTex0RectImagePos>  FNoesisPosColorTex0RectImagePosVertexDeclaration;

extern TGlobalResource<FNoesisPosVertexDeclaration> GNoesisPosVertexDeclaration;
extern TGlobalResource<FNoesisPosColorVertexDeclaration> GNoesisPosColorVertexDeclaration;
extern TGlobalResource<FNoesisPosTex0VertexDeclaration> GNoesisPosTex0VertexDeclaration;
extern TGlobalResource<FNoesisPosTex0RectVertexDeclaration> GNoesisPosTex0RectVertexDeclaration;
extern TGlobalResource<FNoesisPosTex0RectTileVertexDeclaration> GNoesisPosTex0RectTileVertexDeclaration;
extern TGlobalResource<FNoesisPosColorCoverageVertexDeclaration> GNoesisPosColorCoverageVertexDeclaration;
extern TGlobalResource<FNoesisPosTex0CoverageVertexDeclaration> GNoesisPosTex0CoverageVertexDeclaration;
extern TGlobalResource<FNoesisPosTex0CoverageRectVertexDeclaration> GNoesisPosTex0CoverageRectVertexDeclaration;
extern TGlobalResource<FNoesisPosTex0CoverageRectTileVertexDeclaration> GNoesisPosTex0CoverageRectTileVertexDeclaration;
extern TGlobalResource<FNoesisPosColorTex1VertexDeclaration> GNoesisPosColorTex1VertexDeclaration;
extern TGlobalResource<FNoesisPosTex0Tex1VertexDeclaration> GNoesisPosTex0Tex1VertexDeclaration;
extern TGlobalResource<FNoesisPosTex0Tex1RectVertexDeclaration> GNoesisPosTex0Tex1RectVertexDeclaration;
extern TGlobalResource<FNoesisPosTex0Tex1RectTileVertexDeclaration> GNoesisPosTex0Tex1RectTileVertexDeclaration;
extern TGlobalResource<FNoesisPosColorTex0Tex1VertexDeclaration> GNoesisPosColorTex0Tex1VertexDeclaration;
extern TGlobalResource<FNoesisPosColorTex1RectVertexDeclaration> GNoesisPosColorTex1RectVertexDeclaration;
extern TGlobalResource<FNoesisPosColorTex0RectImagePosVertexDeclaration> GNoesisPosColorTex0RectImagePosVertexDeclaration;

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisVSConstants, )
SHADER_PARAMETER(FMatrix, projectionMtx)
END_GLOBAL_SHADER_PARAMETER_STRUCT()

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisTextureSize, )
SHADER_PARAMETER(FVector2D, textureSize)
END_GLOBAL_SHADER_PARAMETER_STRUCT()

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisPSRgbaConstants, )
SHADER_PARAMETER(FVector4, rgba)
END_GLOBAL_SHADER_PARAMETER_STRUCT()

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisPSOpacityConstants, )
SHADER_PARAMETER(float, opacity)
END_GLOBAL_SHADER_PARAMETER_STRUCT()

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisPSRadialGradConstants, )
SHADER_PARAMETER_ARRAY(FVector4, radialGrad, [2])
END_GLOBAL_SHADER_PARAMETER_STRUCT()

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisBlurConstants, )
SHADER_PARAMETER(float, blend)
END_GLOBAL_SHADER_PARAMETER_STRUCT()

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisShadowConstants, )
SHADER_PARAMETER(FVector4, shadowColor)
SHADER_PARAMETER(FVector2D, shadowOffset)
SHADER_PARAMETER(float, blend)
END_GLOBAL_SHADER_PARAMETER_STRUCT()

class FNoesisVSBase : public FGlobalShader
{
	DECLARE_INLINE_TYPE_LAYOUT(FNoesisVSBase, NonVirtual);
public:
	FNoesisVSBase(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FGlobalShader(Initializer)
	{
		VSConstantsBuffer.Bind(Initializer.ParameterMap, FNoesisVSConstants::StaticStructMetadata.GetShaderVariableName());
		TextureSizeBuffer.Bind(Initializer.ParameterMap, FNoesisTextureSize::StaticStructMetadata.GetShaderVariableName());
	}

	FNoesisVSBase()
	{
	}

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters) { return true; }

	void SetVSConstants(FRHICommandList& RHICmdList, const FUniformBufferRHIRef& VSConstants)
	{
		FRHIVertexShader* ShaderRHI = RHICmdList.GetBoundVertexShader();

		check(VSConstantsBuffer.IsBound());
		SetUniformBufferParameter(RHICmdList, ShaderRHI, VSConstantsBuffer, VSConstants);
	}

	void SetTextureSize(FRHICommandList& RHICmdList, const FUniformBufferRHIRef& TextureSize)
	{
		FRHIVertexShader* ShaderRHI = RHICmdList.GetBoundVertexShader();

		check(TextureSizeBuffer.IsBound());
		SetUniformBufferParameter(RHICmdList, ShaderRHI, TextureSizeBuffer, TextureSize);
	}

	LAYOUT_FIELD(FShaderUniformBufferParameter, VSConstantsBuffer);
	LAYOUT_FIELD(FShaderUniformBufferParameter, TextureSizeBuffer)
};

template<Noesis::Shader::Vertex::Enum VertexShader>
class FNoesisVS : public FNoesisVSBase
{
	DECLARE_SHADER_TYPE(FNoesisVS, Global);

	static const constexpr uint8 VertexFormat = (uint8)Noesis::FormatForVertex[VertexShader];
	static const constexpr uint8 Attributes = (uint8)Noesis::AttributesForFormat[VertexFormat];
	static const constexpr bool HasColor = (Attributes & (1 << Noesis::Shader::Vertex::Format::Attr::Color)) != 0;
	static const constexpr bool HasTex0 = (Attributes & (1 << Noesis::Shader::Vertex::Format::Attr::Tex0)) != 0;
	static const constexpr bool HasTex1 = (Attributes & (1 << Noesis::Shader::Vertex::Format::Attr::Tex1)) != 0;
	static const constexpr bool HasCoverage = (Attributes & (1 << Noesis::Shader::Vertex::Format::Attr::Coverage)) != 0;
	static const constexpr bool HasRect = (Attributes & (1 << Noesis::Shader::Vertex::Format::Attr::Rect)) != 0;
	static const constexpr bool HasTile = (Attributes & (1 << Noesis::Shader::Vertex::Format::Attr::Tile)) != 0;
	static const constexpr bool HasImagePos = (Attributes & (1 << Noesis::Shader::Vertex::Format::Attr::ImagePos)) != 0;
	static const constexpr bool Downsample = (VertexShader == Noesis::Shader::Vertex::PosTex0Tex1_Downsample);
	static const constexpr bool SDF = (VertexShader >= Noesis::Shader::Vertex::PosColorTex1_SDF) && (VertexShader <= Noesis::Shader::Vertex::PosTex0Tex1RectTile_SDF);

	FNoesisVS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FNoesisVSBase(Initializer)
	{
	}

	FNoesisVS()
	{
	}

	static bool ShouldCache(EShaderPlatform Platform)
	{
		return true;
	}

	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
		OutEnvironment.SetDefine(TEXT("HAS_COLOR"), HasColor);
		OutEnvironment.SetDefine(TEXT("HAS_UV0"), HasTex0);
		OutEnvironment.SetDefine(TEXT("HAS_UV1"), HasTex1);
		OutEnvironment.SetDefine(TEXT("HAS_COVERAGE"), HasCoverage);
		OutEnvironment.SetDefine(TEXT("HAS_RECT"), HasRect);
		OutEnvironment.SetDefine(TEXT("HAS_TILE"), HasTile);
		OutEnvironment.SetDefine(TEXT("HAS_IMAGE_POSITION"), HasImagePos);
		OutEnvironment.SetDefine(TEXT("DOWNSAMPLE"), Downsample);
		OutEnvironment.SetDefine(TEXT("SDF"), SDF);
	}
};

typedef FNoesisVS<Noesis::Shader::Vertex::Pos> FNoesisPosVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColor> FNoesisPosColorVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0> FNoesisPosTex0VS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0Rect> FNoesisPosTex0RectVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0RectTile> FNoesisPosTex0RectTileVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorCoverage> FNoesisPosColorCoverageVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0Coverage> FNoesisPosTex0CoverageVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0CoverageRect> FNoesisPosTex0CoverageRectVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0CoverageRectTile> FNoesisPosTex0CoverageRectTileVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex1_SDF> FNoesisPosColorTex1SDFVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0Tex1_SDF> FNoesisPosTex0Tex1SDFVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0Tex1Rect_SDF> FNoesisPosTex0Tex1RectSDFVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0Tex1RectTile_SDF> FNoesisPosTex0Tex1RectTileSDFVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex1> FNoesisPosColorTex1VS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0Tex1> FNoesisPosTex0Tex1VS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0Tex1Rect> FNoesisPosTex0Tex1RectVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0Tex1RectTile> FNoesisPosTex0Tex1RectTileVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex0Tex1> FNoesisPosColorTex0Tex1VS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0Tex1_Downsample> FNoesisPosTex0Tex1DownsampleVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex1Rect> FNoesisPosColorTex1RectVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex0RectImagePos> FNoesisPosColorTex0RectImagePosVS;

class FNoesisPSBase : public FGlobalShader
{
	DECLARE_INLINE_TYPE_LAYOUT(FNoesisPSBase, NonVirtual);

public:
	FNoesisPSBase(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FGlobalShader(Initializer)
	{
		if (Initializer.ParameterMap.ContainsParameterAllocation(FNoesisPSRgbaConstants::StaticStructMetadata.GetShaderVariableName()))
		{
			PSConstantsBuffer.Bind(Initializer.ParameterMap, FNoesisPSRgbaConstants::StaticStructMetadata.GetShaderVariableName());
		}
		else if (Initializer.ParameterMap.ContainsParameterAllocation(FNoesisPSOpacityConstants::StaticStructMetadata.GetShaderVariableName()))
		{
			PSConstantsBuffer.Bind(Initializer.ParameterMap, FNoesisPSOpacityConstants::StaticStructMetadata.GetShaderVariableName());
		}
		else if (Initializer.ParameterMap.ContainsParameterAllocation(FNoesisPSRadialGradConstants::StaticStructMetadata.GetShaderVariableName()))
		{
			PSConstantsBuffer.Bind(Initializer.ParameterMap, FNoesisPSRadialGradConstants::StaticStructMetadata.GetShaderVariableName());
		}
		
		if (Initializer.ParameterMap.ContainsParameterAllocation(FNoesisBlurConstants::StaticStructMetadata.GetShaderVariableName()))
		{
			EffectsBuffer.Bind(Initializer.ParameterMap, FNoesisBlurConstants::StaticStructMetadata.GetShaderVariableName());
		}
		else if (Initializer.ParameterMap.ContainsParameterAllocation(FNoesisShadowConstants::StaticStructMetadata.GetShaderVariableName()))
		{
			EffectsBuffer.Bind(Initializer.ParameterMap, FNoesisShadowConstants::StaticStructMetadata.GetShaderVariableName());
		}

		PatternTexture.Bind(Initializer.ParameterMap, TEXT("patternTex"));
		PatternSampler.Bind(Initializer.ParameterMap, TEXT("patternSampler"));
		RampsTexture.Bind(Initializer.ParameterMap, TEXT("rampsTex"));
		RampsSampler.Bind(Initializer.ParameterMap, TEXT("rampsSampler"));
		ImageTexture.Bind(Initializer.ParameterMap, TEXT("imageTex"));
		ImageSampler.Bind(Initializer.ParameterMap, TEXT("imageSampler"));
		GlyphsTexture.Bind(Initializer.ParameterMap, TEXT("glyphsTex"));
		GlyphsSampler.Bind(Initializer.ParameterMap, TEXT("glyphsSampler"));
		ShadowTexture.Bind(Initializer.ParameterMap, TEXT("shadowTex"));
		ShadowSampler.Bind(Initializer.ParameterMap, TEXT("shadowSampler"));
	}

	FNoesisPSBase()
	{
	}

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters) { return true; }

	void SetPSConstants(FRHICommandList& RHICmdList, const FUniformBufferRHIRef& PSConstants)
	{
		FRHIPixelShader* ShaderRHI = RHICmdList.GetBoundPixelShader();

		check(PSConstantsBuffer.IsBound());
		SetUniformBufferParameter(RHICmdList, ShaderRHI, PSConstantsBuffer, PSConstants);
	}

	void SetEffects(FRHICommandList& RHICmdList, const FUniformBufferRHIRef& Effects)
	{
		FRHIPixelShader* ShaderRHI = RHICmdList.GetBoundPixelShader();

		check(EffectsBuffer.IsBound());
		SetUniformBufferParameter(RHICmdList, ShaderRHI, EffectsBuffer, Effects);
	}

	void SetPatternTexture(FRHICommandList& RHICmdList, FRHITexture* PatternTextureResource, FRHISamplerState* PatternSamplerResource)
	{
		FRHIPixelShader* ShaderRHI = RHICmdList.GetBoundPixelShader();

		SetTextureParameter(RHICmdList, ShaderRHI, PatternTexture, PatternSampler, PatternSamplerResource, PatternTextureResource);
	}

	void SetRampsTexture(FRHICommandList& RHICmdList, FRHITexture* RampsTextureResource, FRHISamplerState* RampsSamplerResource)
	{
		FRHIPixelShader* ShaderRHI = RHICmdList.GetBoundPixelShader();

		SetTextureParameter(RHICmdList, ShaderRHI, RampsTexture, RampsSampler, RampsSamplerResource, RampsTextureResource);
	}

	void SetImageTexture(FRHICommandList& RHICmdList, FRHITexture* ImageTextureResource, FRHISamplerState* ImageSamplerResource)
	{
		FRHIPixelShader* ShaderRHI = RHICmdList.GetBoundPixelShader();

		SetTextureParameter(RHICmdList, ShaderRHI, ImageTexture, ImageSampler, ImageSamplerResource, ImageTextureResource);
	}

	void SetGlyphsTexture(FRHICommandList& RHICmdList, FRHITexture* GlyphsTextureResource, FRHISamplerState* GlyphsSamplerResource)
	{
		FRHIPixelShader* ShaderRHI = RHICmdList.GetBoundPixelShader();

		SetTextureParameter(RHICmdList, ShaderRHI, GlyphsTexture, GlyphsSampler, GlyphsSamplerResource, GlyphsTextureResource);
	}

	void SetShadowTexture(FRHICommandList& RHICmdList, FRHITexture* ShadowTextureResource, FRHISamplerState* ShadowSamplerResource)
	{
		FRHIPixelShader* ShaderRHI = RHICmdList.GetBoundPixelShader();

		SetTextureParameter(RHICmdList, ShaderRHI, ShadowTexture, ShadowSampler, ShadowSamplerResource, ShadowTextureResource);
	}

	LAYOUT_FIELD(FShaderUniformBufferParameter, PSConstantsBuffer)
	LAYOUT_FIELD(FShaderUniformBufferParameter, EffectsBuffer)
	LAYOUT_FIELD(FShaderResourceParameter, PatternTexture)
	LAYOUT_FIELD(FShaderResourceParameter, PatternSampler)
	LAYOUT_FIELD(FShaderResourceParameter, RampsTexture)
	LAYOUT_FIELD(FShaderResourceParameter, RampsSampler)
	LAYOUT_FIELD(FShaderResourceParameter, ImageTexture)
	LAYOUT_FIELD(FShaderResourceParameter, ImageSampler)
	LAYOUT_FIELD(FShaderResourceParameter, GlyphsTexture)
	LAYOUT_FIELD(FShaderResourceParameter, GlyphsSampler)
	LAYOUT_FIELD(FShaderResourceParameter, ShadowTexture)
	LAYOUT_FIELD(FShaderResourceParameter, ShadowSampler)
};

template<Noesis::Shader::Enum Effect, bool PatternSRGB = false>
class FNoesisPS : public FNoesisPSBase
{
	DECLARE_SHADER_TYPE(FNoesisPS, Global);

	FNoesisPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FNoesisPSBase(Initializer)
	{
	}

	FNoesisPS()
	{
	}

	static bool ShouldCache(EShaderPlatform Platform)
	{
		return true;
	}

	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
		OutEnvironment.SetDefine(TEXT("EFFECT"), Effect);

		// MediaTextures don't work correctly if they are not rendered to SRGB textures.
		// We need to convert them on the shaders.
		// MediaTextures are sampled from the pattern textures.
		// The shaders that need to do this conversion are more expensive, so we are still
		// setting SRGB to false when we import textures. But at least this means that
		// user textures should work regardless.
		OutEnvironment.SetDefine(TEXT("PATTERN_SRGB"), PatternSRGB);
	}
};

// The commas in the template parameter list break the IMPLEMENT_SHADER_TYPE macro, so we need typedefs.
typedef FNoesisPS<Noesis::Shader::RGBA> FNoesisRgbaPS;
typedef FNoesisPS<Noesis::Shader::Mask> FNoesisMaskPS;
typedef FNoesisPS<Noesis::Shader::Clear> FNoesisClearPS;

typedef FNoesisPS<Noesis::Shader::Path_Solid> FNoesisPathSolidPS;
typedef FNoesisPS<Noesis::Shader::Path_Linear> FNoesisPathLinearPS;
typedef FNoesisPS<Noesis::Shader::Path_Radial> FNoesisPathRadialPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern> FNoesisPathPatternPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Clamp> FNoesisPathPatternClampPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Repeat> FNoesisPathPatternRepeatPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorU> FNoesisPathPatternMirrorUPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorV> FNoesisPathPatternMirrorVPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Mirror> FNoesisPathPatternMirrorPS;

typedef FNoesisPS<Noesis::Shader::Path_AA_Solid> FNoesisPathAASolidPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Linear> FNoesisPathAALinearPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Radial> FNoesisPathAARadialPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern> FNoesisPathAAPatternPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Clamp> FNoesisPathAAPatternClampPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Repeat> FNoesisPathAAPatternRepeatPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorU> FNoesisPathAAPatternMirrorUPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorV> FNoesisPathAAPatternMirrorVPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Mirror> FNoesisPathAAPatternMirrorPS;

typedef FNoesisPS<Noesis::Shader::SDF_Solid> FNoesisSDFSolidPS;
typedef FNoesisPS<Noesis::Shader::SDF_Linear> FNoesisSDFLinearPS;
typedef FNoesisPS<Noesis::Shader::SDF_Radial> FNoesisSDFRadialPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern> FNoesisSDFPatternPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Clamp> FNoesisSDFPatternClampPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Repeat> FNoesisSDFPatternRepeatPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorU> FNoesisSDFPatternMirrorUPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorV> FNoesisSDFPatternMirrorVPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Mirror> FNoesisSDFPatternMirrorPS;

typedef FNoesisPS<Noesis::Shader::SDF_LCD_Solid> FNoesisSDFLCDSolidPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Linear> FNoesisSDFLCDLinearPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Radial> FNoesisSDFLCDRadialPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern> FNoesisSDFLCDPatternPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Clamp> FNoesisSDFLCDPatternClampPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Repeat> FNoesisSDFLCDPatternRepeatPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorU> FNoesisSDFLCDPatternMirrorUPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorV> FNoesisSDFLCDPatternMirrorVPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Mirror> FNoesisSDFLCDPatternMirrorPS;

typedef FNoesisPS<Noesis::Shader::Opacity_Solid> FNoesisOpacitySolidPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Linear> FNoesisOpacityLinearPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Radial> FNoesisOpacityRadialPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern> FNoesisOpacityPatternPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Clamp> FNoesisOpacityPatternClampPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Repeat> FNoesisOpacityPatternRepeatPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorU> FNoesisOpacityPatternMirrorUPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorV> FNoesisOpacityPatternMirrorVPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Mirror> FNoesisOpacityPatternMirrorPS;

typedef FNoesisPS<Noesis::Shader::Upsample> FNoesisUpsamplePS;
typedef FNoesisPS<Noesis::Shader::Downsample> FNoesisDownsamplePS;

typedef FNoesisPS<Noesis::Shader::Shadow> FNoesisShadowPS;
typedef FNoesisPS<Noesis::Shader::Blur> FNoesisBlurPS;

// Read the comment next to PATTERN_SRGB in FNoesisPS::ModifyCompilationEnvironment
typedef FNoesisPS<Noesis::Shader::Path_Pattern, true> FNoesisPathPatternSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Clamp, true> FNoesisPathPatternClampSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Repeat, true> FNoesisPathPatternRepeatSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorU, true> FNoesisPathPatternMirrorUSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorV, true> FNoesisPathPatternMirrorVSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Mirror, true> FNoesisPathPatternMirrorSRGBPS;

typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern, true> FNoesisPathAAPatternSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Clamp, true> FNoesisPathAAPatternClampSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Repeat, true> FNoesisPathAAPatternRepeatSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorU, true> FNoesisPathAAPatternMirrorUSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorV, true> FNoesisPathAAPatternMirrorVSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Mirror, true> FNoesisPathAAPatternMirrorSRGBPS;

typedef FNoesisPS<Noesis::Shader::SDF_Pattern, true> FNoesisSDFPatternSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Clamp, true> FNoesisSDFPatternClampSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Repeat, true> FNoesisSDFPatternRepeatSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorU, true> FNoesisSDFPatternMirrorUSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorV, true> FNoesisSDFPatternMirrorVSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Mirror, true> FNoesisSDFPatternMirrorSRGBPS;

typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern, true> FNoesisSDFLCDPatternSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Clamp, true> FNoesisSDFLCDPatternClampSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Repeat, true> FNoesisSDFLCDPatternRepeatSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorU, true> FNoesisSDFLCDPatternMirrorUSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorV, true> FNoesisSDFLCDPatternMirrorVSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Mirror, true> FNoesisSDFLCDPatternMirrorSRGBPS;

typedef FNoesisPS<Noesis::Shader::Opacity_Pattern, true> FNoesisOpacityPatternSRGBPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Clamp, true> FNoesisOpacityPatternClampSRGBPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Repeat, true> FNoesisOpacityPatternRepeatSRGBPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorU, true> FNoesisOpacityPatternMirrorUSRGBPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorV, true> FNoesisOpacityPatternMirrorVSRGBPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Mirror, true> FNoesisOpacityPatternMirrorSRGBPS;

class FNoesisMaterialPSBase : public FMaterialShader
{
	DECLARE_INLINE_TYPE_LAYOUT(FNoesisMaterialPSBase, NonVirtual);

public:
	FNoesisMaterialPSBase(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FMaterialShader(Initializer)
	{
		PSConstantsBuffer.Bind(Initializer.ParameterMap, FNoesisPSOpacityConstants::StaticStructMetadata.GetShaderVariableName());

		ImageTexture.Bind(Initializer.ParameterMap, TEXT("imageTex"));
		ImageSampler.Bind(Initializer.ParameterMap, TEXT("imageSampler"));
		GlyphsTexture.Bind(Initializer.ParameterMap, TEXT("glyphsTex"));
		GlyphsSampler.Bind(Initializer.ParameterMap, TEXT("glyphsSampler"));
	}

	FNoesisMaterialPSBase()
	{
	}

	static bool ShouldCompilePermutation(const FMaterialShaderPermutationParameters& Parameters)
	{
		return Parameters.MaterialParameters.MaterialDomain == MD_UI;
	}

	void SetPSConstants(FRHICommandList& RHICmdList, const FUniformBufferRHIRef& PSConstants)
	{
		FRHIPixelShader* ShaderRHI = RHICmdList.GetBoundPixelShader();

		check(PSConstantsBuffer.IsBound());
		SetUniformBufferParameter(RHICmdList, ShaderRHI, PSConstantsBuffer, PSConstants);
	}

	void SetEffects(FRHICommandList& RHICmdList, const FUniformBufferRHIRef& Effects)
	{
		check(false);
	}

	void SetPatternTexture(FRHICommandList& RHICmdList, FRHITexture* PatternTextureResource, FRHISamplerState* PatternSamplerResource)
	{
		check(false);
	}

	void SetRampsTexture(FRHICommandList& RHICmdList, FRHITexture* RampsTextureResource, FRHISamplerState* RampsSamplerResource)
	{
		check(false);
	}

	void SetImageTexture(FRHICommandList& RHICmdList, FRHITexture* ImageTextureResource, FRHISamplerState* ImageSamplerResource)
	{
		FRHIPixelShader* ShaderRHI = RHICmdList.GetBoundPixelShader();

		SetTextureParameter(RHICmdList, ShaderRHI, ImageTexture, ImageSampler, ImageSamplerResource, ImageTextureResource);
	}

	void SetGlyphsTexture(FRHICommandList& RHICmdList, FRHITexture* GlyphsTextureResource, FRHISamplerState* GlyphsSamplerResource)
	{
		FRHIPixelShader* ShaderRHI = RHICmdList.GetBoundPixelShader();

		SetTextureParameter(RHICmdList, ShaderRHI, GlyphsTexture, GlyphsSampler, GlyphsSamplerResource, GlyphsTextureResource);
	}

	void SetShadowTexture(FRHICommandList& RHICmdList, FRHITexture* ShadowTextureResource, FRHISamplerState* ShadowSamplerResource)
	{
		check(false);
	}

	LAYOUT_FIELD(FShaderUniformBufferParameter, PSConstantsBuffer)
	LAYOUT_FIELD(FShaderResourceParameter, ImageTexture)
	LAYOUT_FIELD(FShaderResourceParameter, ImageSampler)
	LAYOUT_FIELD(FShaderResourceParameter, GlyphsTexture)
	LAYOUT_FIELD(FShaderResourceParameter, GlyphsSampler)
};

template<Noesis::Shader::Enum Effect>
class FNoesisMaterialPS : public FNoesisMaterialPSBase
{
	DECLARE_SHADER_TYPE(FNoesisMaterialPS, Material);

	FNoesisMaterialPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FNoesisMaterialPSBase(Initializer)
	{
	}

	FNoesisMaterialPS()
	{
	}

	static bool ShouldCache(EShaderPlatform Platform)
	{
		return true;
	}

	static void ModifyCompilationEnvironment(const FMaterialShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FMaterialShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
		OutEnvironment.SetDefine(TEXT("EFFECT"), Effect);
	}
};

// The commas in the template parameter list break the IMPLEMENT_SHADER_TYPE macro, so we need typedefs.
typedef FNoesisMaterialPS<Noesis::Shader::Path_Pattern> FNoesisPathMaterialPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_Pattern_Clamp> FNoesisPathMaterialClampPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_Pattern_Repeat> FNoesisPathMaterialRepeatPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_Pattern_MirrorU> FNoesisPathMaterialMirrorUPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_Pattern_MirrorV> FNoesisPathMaterialMirrorVPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_Pattern_Mirror> FNoesisPathMaterialMirrorPS;

typedef FNoesisMaterialPS<Noesis::Shader::Path_AA_Pattern> FNoesisPathAAMaterialPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_AA_Pattern_Clamp> FNoesisPathAAMaterialClampPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_AA_Pattern_Repeat> FNoesisPathAAMaterialRepeatPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_AA_Pattern_MirrorU> FNoesisPathAAMaterialMirrorUPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_AA_Pattern_MirrorV> FNoesisPathAAMaterialMirrorVPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_AA_Pattern_Mirror> FNoesisPathAAMaterialMirrorPS;

typedef FNoesisMaterialPS<Noesis::Shader::SDF_Pattern> FNoesisSDFMaterialPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_Pattern_Clamp> FNoesisSDFMaterialClampPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_Pattern_Repeat> FNoesisSDFMaterialRepeatPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_Pattern_MirrorU> FNoesisSDFMaterialMirrorUPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_Pattern_MirrorV> FNoesisSDFMaterialMirrorVPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_Pattern_Mirror> FNoesisSDFMaterialMirrorPS;

typedef FNoesisMaterialPS<Noesis::Shader::SDF_LCD_Pattern> FNoesisSDFLCDMaterialPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_LCD_Pattern_Clamp> FNoesisSDFLCDMaterialClampPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_LCD_Pattern_Repeat> FNoesisSDFLCDMaterialRepeatPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_LCD_Pattern_MirrorU> FNoesisSDFLCDMaterialMirrorUPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_LCD_Pattern_MirrorV> FNoesisSDFLCDMaterialMirrorVPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_LCD_Pattern_Mirror> FNoesisSDFLCDMaterialMirrorPS;

typedef FNoesisMaterialPS<Noesis::Shader::Opacity_Pattern> FNoesisOpacityMaterialPS;
typedef FNoesisMaterialPS<Noesis::Shader::Opacity_Pattern_Clamp> FNoesisOpacityMaterialClampPS;
typedef FNoesisMaterialPS<Noesis::Shader::Opacity_Pattern_Repeat> FNoesisOpacityMaterialRepeatPS;
typedef FNoesisMaterialPS<Noesis::Shader::Opacity_Pattern_MirrorU> FNoesisOpacityMaterialMirrorUPS;
typedef FNoesisMaterialPS<Noesis::Shader::Opacity_Pattern_MirrorV> FNoesisOpacityMaterialMirrorVPS;
typedef FNoesisMaterialPS<Noesis::Shader::Opacity_Pattern_Mirror> FNoesisOpacityMaterialMirrorPS;


BEGIN_SHADER_PARAMETER_STRUCT(FNoesisSceneTextureUniformParameters, )
	// Scene Color / Depth
	SHADER_PARAMETER_TEXTURE(Texture2D, SceneColorTexture)
	SHADER_PARAMETER_TEXTURE(Texture2D, SceneDepthTexture)

	// GBuffer
	SHADER_PARAMETER_TEXTURE(Texture2D, GBufferATexture)
	SHADER_PARAMETER_TEXTURE(Texture2D, GBufferBTexture)
	SHADER_PARAMETER_TEXTURE(Texture2D, GBufferCTexture)
	SHADER_PARAMETER_TEXTURE(Texture2D, GBufferDTexture)
	SHADER_PARAMETER_TEXTURE(Texture2D, GBufferETexture)
	SHADER_PARAMETER_TEXTURE(Texture2D, GBufferFTexture)
	SHADER_PARAMETER_TEXTURE(Texture2D, GBufferVelocityTexture)

	// SSAO
	SHADER_PARAMETER_TEXTURE(Texture2D, ScreenSpaceAOTexture)

	// Custom Depth / Stencil
	SHADER_PARAMETER_TEXTURE(Texture2D, CustomDepthTexture)
	SHADER_PARAMETER_SRV(Texture2D<uint2>, CustomStencilTexture)

	// Misc
	SHADER_PARAMETER_SAMPLER(SamplerState, PointClampSampler)
END_GLOBAL_SHADER_PARAMETER_STRUCT()

BEGIN_SHADER_PARAMETER_STRUCT(FNoesisMobileSceneTextureUniformParameters, )
	SHADER_PARAMETER_TEXTURE(Texture2D, SceneColorTexture)
	SHADER_PARAMETER_SAMPLER(SamplerState, SceneColorTextureSampler)
	SHADER_PARAMETER_TEXTURE(Texture2D, SceneDepthTexture)
	SHADER_PARAMETER_SAMPLER(SamplerState, SceneDepthTextureSampler)
	SHADER_PARAMETER_TEXTURE(Texture2D, CustomDepthTexture)
	SHADER_PARAMETER_SAMPLER(SamplerState, CustomDepthTextureSampler)
	SHADER_PARAMETER_TEXTURE(Texture2D, MobileCustomStencilTexture)
	SHADER_PARAMETER_SAMPLER(SamplerState, MobileCustomStencilTextureSampler)
	SHADER_PARAMETER_UAV(RWBuffer<uint>, VirtualTextureFeedbackUAV)
	// GBuffer
	SHADER_PARAMETER_TEXTURE(Texture2D, GBufferATexture)
	SHADER_PARAMETER_TEXTURE(Texture2D, GBufferBTexture)
	SHADER_PARAMETER_TEXTURE(Texture2D, GBufferCTexture)
	SHADER_PARAMETER_TEXTURE(Texture2D, GBufferDTexture)
	SHADER_PARAMETER_TEXTURE(Texture2D, SceneDepthAuxTexture)
	SHADER_PARAMETER_SAMPLER(SamplerState, GBufferATextureSampler)
	SHADER_PARAMETER_SAMPLER(SamplerState, GBufferBTextureSampler)
	SHADER_PARAMETER_SAMPLER(SamplerState, GBufferCTextureSampler)
	SHADER_PARAMETER_SAMPLER(SamplerState, GBufferDTextureSampler)
	SHADER_PARAMETER_SAMPLER(SamplerState, SceneDepthAuxTextureSampler)
END_GLOBAL_SHADER_PARAMETER_STRUCT()

BEGIN_SHADER_PARAMETER_STRUCT(FNoesisSceneTextureShaderParameters, )
	SHADER_PARAMETER_STRUCT_INCLUDE(FNoesisSceneTextureUniformParameters, SceneTextures)
	SHADER_PARAMETER_STRUCT_INCLUDE(FNoesisMobileSceneTextureUniformParameters, MobileSceneTextures)
END_SHADER_PARAMETER_STRUCT()

BEGIN_SHADER_PARAMETER_STRUCT(FNoesisScreenPassTextureInput, )
	SHADER_PARAMETER_STRUCT_INCLUDE(FScreenPassTextureViewportParameters, Viewport)
	SHADER_PARAMETER_TEXTURE(Texture2D, Texture)
	SHADER_PARAMETER_SAMPLER(SamplerState, Sampler)
END_SHADER_PARAMETER_STRUCT()

BEGIN_SHADER_PARAMETER_STRUCT(FNoesisPostProcessMaterialParameters, )
	SHADER_PARAMETER_STRUCT_REF(FViewUniformShaderParameters, View)
	SHADER_PARAMETER_STRUCT_INCLUDE(FNoesisSceneTextureShaderParameters, SceneTextures)
	SHADER_PARAMETER_STRUCT(FScreenPassTextureViewportParameters, PostProcessOutput)
	SHADER_PARAMETER_TEXTURE(Texture2D, PostProcessInput_0_Texture)
	SHADER_PARAMETER_SAMPLER(SamplerState, PostProcessInput_0_Sampler)
	SHADER_PARAMETER_STRUCT(FNoesisScreenPassTextureInput, PostProcessInput_1)
	SHADER_PARAMETER_STRUCT(FNoesisScreenPassTextureInput, PostProcessInput_2)
	SHADER_PARAMETER_STRUCT(FNoesisScreenPassTextureInput, PostProcessInput_3)
	SHADER_PARAMETER_STRUCT(FNoesisScreenPassTextureInput, PostProcessInput_4)
	SHADER_PARAMETER_STRUCT(FNoesisScreenPassTextureInput, PostProcessInput_5)
	SHADER_PARAMETER_STRUCT(FNoesisScreenPassTextureInput, PostProcessInput_6)
	SHADER_PARAMETER_STRUCT(FNoesisScreenPassTextureInput, PostProcessInput_7)
	SHADER_PARAMETER_SAMPLER(SamplerState, PostProcessInput_BilinearSampler)
	SHADER_PARAMETER_TEXTURE(Texture2D, MobileCustomStencilTexture)
	SHADER_PARAMETER_SAMPLER(SamplerState, MobileCustomStencilTextureSampler)
	SHADER_PARAMETER_TEXTURE(Texture2D, EyeAdaptationTexture)
	SHADER_PARAMETER_SRV(Buffer<float4>, EyeAdaptationBuffer)
	SHADER_PARAMETER(int32, MobileStencilValueRef)
	SHADER_PARAMETER(uint32, bFlipYAxis)
	SHADER_PARAMETER(uint32, bMetalMSAAHDRDecode)
	RENDER_TARGET_BINDING_SLOTS()
END_SHADER_PARAMETER_STRUCT()

class FNoesisCustomEffectPS : public FMaterialShader
{
public:
	DECLARE_SHADER_TYPE(FNoesisCustomEffectPS, Material);

	using FParameters = FNoesisPostProcessMaterialParameters;
	SHADER_USE_PARAMETER_STRUCT_WITH_LEGACY_BASE(FNoesisCustomEffectPS, FMaterialShader);

	static bool ShouldCompilePermutation(const FMaterialShaderPermutationParameters& Parameters)
	{
		return Parameters.MaterialParameters.MaterialDomain == MD_PostProcess;
	}

	static void ModifyCompilationEnvironment(const FMaterialShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FMaterialShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
		OutEnvironment.SetDefine(TEXT("POST_PROCESS_MATERIAL"), 1);

		OutEnvironment.SetDefine(TEXT("POST_PROCESS_MATERIAL_BEFORE_TONEMAP"), 0);

		uint32 StencilCompareFunction = Parameters.MaterialParameters.bIsStencilTestEnabled ? Parameters.MaterialParameters.StencilCompare : EMaterialStencilCompare::MSC_Never;
		OutEnvironment.SetDefine(TEXT("MOBILE_STENCIL_COMPARE_FUNCTION"), StencilCompareFunction);
	}

	static void SetParameters(FRHICommandList& RHICmdList, const TShaderRef<FNoesisCustomEffectPS>& Shader, const FSceneView& View, const FMaterialRenderProxy* Proxy, const FParameters& Parameters)
	{
		FMaterialShader* MaterialShader = Shader.GetShader();
		FRHIPixelShader* ShaderRHI = Shader.GetPixelShader();
#if (ENGINE_MAJOR_VERSION >= 5) || ((ENGINE_MAJOR_VERSION == 4) && (ENGINE_MINOR_VERSION >= 27))
		const FMaterial* Material = &Proxy->GetIncompleteMaterialWithFallback(View.GetFeatureLevel());
#else
		const FMaterial* Material = Proxy->GetMaterial(View.GetFeatureLevel());
#endif
		MaterialShader->SetParameters(RHICmdList, ShaderRHI, Proxy, *Material, View);
		SetShaderParameters(RHICmdList, Shader, ShaderRHI, Parameters);
	}
};
