////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"
#include "Misc/EngineVersionComparison.h"
#include "CoreGlobals.h"
#include "Misc/ConfigCacheIni.h"

// RHI includes
#include "RHI.h"

// RenderCore includes
#include "RenderResource.h"
#include "GlobalShader.h"
#include "ShaderParameterUtils.h"
#include "StereoRenderUtils.h"

// Renderer includes
#include "MaterialShader.h"
#if UE_VERSION_OLDER_THAN(5, 3, 0)
#include "Runtime/Renderer/Private/ScreenPass.h"
#endif
#if UE_VERSION_OLDER_THAN(5, 6, 0)
#include "Runtime/Renderer/Private/PostProcess/PostProcessMaterial.h"
#else
#include "ScreenPass.h"
#endif

// Engine includes
#if UE_VERSION_OLDER_THAN(5, 2, 0)
#include "MaterialShared.h"
#else
#include "MaterialDomain.h"
#include "Materials/MaterialRenderProxy.h"
#endif
#if UE_VERSION_OLDER_THAN(5, 1, 0)
#else
#include "SceneTexturesConfig.h"
#endif
#include "SceneView.h"

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

#if UE_VERSION_OLDER_THAN(5, 3, 0)
	virtual void InitRHI() override
#else
	virtual void InitRHI(FRHICommandListBase& RHICmdList) override
#endif
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

#if UE_VERSION_OLDER_THAN(5, 0, 0)
typedef FMatrix FMatrix44f;
typedef FVector2D FVector2f;
typedef FVector4 FVector4f;
#endif

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisVSConstants, )
SHADER_PARAMETER(FMatrix44f, projectionMtx)
END_GLOBAL_SHADER_PARAMETER_STRUCT()

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisVSConstantsStereo, )
SHADER_PARAMETER_ARRAY(FMatrix44f, projectionMtx, [2])
END_GLOBAL_SHADER_PARAMETER_STRUCT()

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisTextureSize, )
SHADER_PARAMETER(FVector2f, textureSize)
END_GLOBAL_SHADER_PARAMETER_STRUCT()

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisPSRgbaConstants, )
SHADER_PARAMETER(FVector4f, rgba)
END_GLOBAL_SHADER_PARAMETER_STRUCT()

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisPSOpacityConstants, )
SHADER_PARAMETER(float, opacity)
END_GLOBAL_SHADER_PARAMETER_STRUCT()

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisPSRadialGradConstants, )
SHADER_PARAMETER_ARRAY(FVector4f, radialGrad, [2])
END_GLOBAL_SHADER_PARAMETER_STRUCT()

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisBlurConstants, )
SHADER_PARAMETER(float, blend)
END_GLOBAL_SHADER_PARAMETER_STRUCT()

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisShadowConstants, )
SHADER_PARAMETER(FVector4f, shadowColor)
SHADER_PARAMETER(FVector2f, shadowOffset)
SHADER_PARAMETER(float, blend)
END_GLOBAL_SHADER_PARAMETER_STRUCT()

constexpr static inline bool NoesisShaderHasPattern[Noesis::Shader::Enum::Count] = {
  false, //RGBA
  false, //Mask
  false, //Clear
  false, //Path_Solid
  false, //Path_Linear
  false, //Path_Radial
  true, //Path_Pattern
  true, //Path_Pattern_Clamp
  true, //Path_Pattern_Repeat
  true, //Path_Pattern_MirrorU
  true, //Path_Pattern_MirrorV
  true, //Path_Pattern_Mirror
  false, //Path_AA_Solid
  false, //Path_AA_Linear
  false, //Path_AA_Radial
  true, //Path_AA_Pattern
  true, //Path_AA_Pattern_Clamp
  true, //Path_AA_Pattern_Repeat
  true, //Path_AA_Pattern_MirrorU
  true, //Path_AA_Pattern_MirrorV
  true, //Path_AA_Pattern_Mirror
  false, //SDF_Solid
  false, //SDF_Linear
  false, //SDF_Radial
  true, //SDF_Pattern
  true, //SDF_Pattern_Clamp
  true, //SDF_Pattern_Repeat
  true, //SDF_Pattern_MirrorU
  true, //SDF_Pattern_MirrorV
  true, //SDF_Pattern_Mirror
  false, //SDF_LCD_Solid
  false, //SDF_LCD_Linear
  false, //SDF_LCD_Radial
  true, //SDF_LCD_Pattern
  true, //SDF_LCD_Pattern_Clamp
  true, //SDF_LCD_Pattern_Repeat
  true, //SDF_LCD_Pattern_MirrorU
  true, //SDF_LCD_Pattern_MirrorV
  true, //SDF_LCD_Pattern_Mirror
  false, //Opacity_Solid
  false, //Opacity_Linear
  false, //Opacity_Radial
  true, //Opacity_Pattern
  true, //Opacity_Pattern_Clamp
  true, //Opacity_Pattern_Repeat
  true, //Opacity_Pattern_MirrorU
  true, //Opacity_Pattern_MirrorV
  true, //Opacity_Pattern_Mirror
  false, //Upsample
  false, //Downsample
  false, //Shadow
  false, //Blur
  false, //Custom_Effect
};

class FNoesisVS : public FGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FNoesisVS);

	class FVertexShader : SHADER_PERMUTATION_INT("NOESIS_SHADER_VERTEX_ENUM", Noesis::Shader::Vertex::Enum::Count);
	class FLinearColor : SHADER_PERMUTATION_BOOL("LINEAR_COLOR");
	class FStereo : SHADER_PERMUTATION_BOOL("WITH_STEREO");
	using FPermutationDomain = TShaderPermutationDomain<FVertexShader, FLinearColor, FStereo>;

	FNoesisVS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FGlobalShader(Initializer)
	{
#if UE_VERSION_OLDER_THAN(5, 3, 0)
		VSConstantsBuffer.Bind(Initializer.ParameterMap, FNoesisVSConstants::StaticStructMetadata.GetShaderVariableName());
		VSConstantsBufferStereo.Bind(Initializer.ParameterMap, FNoesisVSConstantsStereo::StaticStructMetadata.GetShaderVariableName());
		TextureSizeBuffer.Bind(Initializer.ParameterMap, FNoesisTextureSize::StaticStructMetadata.GetShaderVariableName());
#else
		VSConstantsBuffer.Bind(Initializer.ParameterMap, FNoesisVSConstants::GetStructMetadata()->GetShaderVariableName());
		VSConstantsBufferStereo.Bind(Initializer.ParameterMap, FNoesisVSConstantsStereo::GetStructMetadata()->GetShaderVariableName());
		TextureSizeBuffer.Bind(Initializer.ParameterMap, FNoesisTextureSize::GetStructMetadata()->GetShaderVariableName());
#endif
	}

	FNoesisVS() = default;

	static bool ShouldCache(EShaderPlatform Platform)
	{
		return true;
	}

	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);

		FPermutationDomain PermutationVector(Parameters.PermutationId);
		const uint8 VertexShader = PermutationVector.Get<FVertexShader>();
		const uint8 VertexFormat = (uint8)Noesis::FormatForVertex[VertexShader];
		const uint8 Attributes = (uint8)Noesis::AttributesForFormat[VertexFormat];
		const bool HasColor = (Attributes & (1 << Noesis::Shader::Vertex::Format::Attr::Color)) != 0;
		const bool HasTex0 = (Attributes & (1 << Noesis::Shader::Vertex::Format::Attr::Tex0)) != 0;
		const bool HasTex1 = (Attributes & (1 << Noesis::Shader::Vertex::Format::Attr::Tex1)) != 0;
		const bool HasCoverage = (Attributes & (1 << Noesis::Shader::Vertex::Format::Attr::Coverage)) != 0;
		const bool HasRect = (Attributes & (1 << Noesis::Shader::Vertex::Format::Attr::Rect)) != 0;
		const bool HasTile = (Attributes & (1 << Noesis::Shader::Vertex::Format::Attr::Tile)) != 0;
		const bool HasImagePos = (Attributes & (1 << Noesis::Shader::Vertex::Format::Attr::ImagePos)) != 0;
		const bool Downsample = (VertexShader == Noesis::Shader::Vertex::PosTex0Tex1_Downsample);
		const bool SDF = (VertexShader >= Noesis::Shader::Vertex::PosColorTex1_SDF) && (VertexShader <= Noesis::Shader::Vertex::PosTex0Tex1RectTile_SDF);

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


	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		FPermutationDomain PermutationVector(Parameters.PermutationId);
		UE::StereoRenderUtils::FStereoShaderAspects Aspects(Parameters.Platform);
		if (PermutationVector.Get<FStereo>() && !Aspects.IsInstancedStereoEnabled())
		{
			return false;
		}
		return true;
	}

	void SetVSConstants(FRHICommandList& RHICmdList, const FUniformBufferRHIRef& VSConstants)
	{
		FRHIVertexShader* ShaderRHI = RHICmdList.GetBoundVertexShader();

		check(VSConstantsBuffer.IsBound());
#if UE_VERSION_OLDER_THAN(5, 3, 0)
		SetUniformBufferParameter(RHICmdList, ShaderRHI, VSConstantsBuffer, VSConstants);
#else
		FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
		BatchedParameters.SetShaderUniformBuffer(VSConstantsBuffer.GetBaseIndex(), VSConstants);
		RHICmdList.SetBatchedShaderParameters(ShaderRHI, BatchedParameters);
#endif
	}

	void SetVSConstantsStereo(FRHICommandList& RHICmdList, const FUniformBufferRHIRef& VSConstantsStereo)
	{
		FRHIVertexShader* ShaderRHI = RHICmdList.GetBoundVertexShader();

		check(VSConstantsBufferStereo.IsBound());
#if UE_VERSION_OLDER_THAN(5, 3, 0)
		SetUniformBufferParameter(RHICmdList, ShaderRHI, VSConstantsBufferStereo, VSConstantsStereo);
#else
		FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
		BatchedParameters.SetShaderUniformBuffer(VSConstantsBufferStereo.GetBaseIndex(), VSConstantsStereo);
		RHICmdList.SetBatchedShaderParameters(ShaderRHI, BatchedParameters);
#endif
	}

	void SetTextureSize(FRHICommandList& RHICmdList, const FUniformBufferRHIRef& TextureSize)
	{
		FRHIVertexShader* ShaderRHI = RHICmdList.GetBoundVertexShader();

		check(TextureSizeBuffer.IsBound());
#if UE_VERSION_OLDER_THAN(5, 3, 0)
		SetUniformBufferParameter(RHICmdList, ShaderRHI, TextureSizeBuffer, TextureSize);
#else
		FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
		BatchedParameters.SetShaderUniformBuffer(TextureSizeBuffer.GetBaseIndex(), TextureSize);
		RHICmdList.SetBatchedShaderParameters(ShaderRHI, BatchedParameters);
#endif
	}

	LAYOUT_FIELD(FShaderUniformBufferParameter, VSConstantsBuffer);
	LAYOUT_FIELD(FShaderUniformBufferParameter, VSConstantsBufferStereo);
	LAYOUT_FIELD(FShaderUniformBufferParameter, TextureSizeBuffer)
};

class FNoesisPS : public FGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FNoesisPS);

	class FEffect : SHADER_PERMUTATION_INT("EFFECT", Noesis::Shader::Enum::Count);
	// MediaTextures don't work correctly if they are not rendered to SRGB textures.
	// We need to convert them on the shaders.
	// MediaTextures are sampled from the pattern textures.
	// The shaders that need to do this conversion are more expensive, so we are still
	// setting SRGB to false when we import textures. But at least this means that
	// user textures should work regardless.
	class FLinearColor : SHADER_PERMUTATION_BOOL("LINEAR_COLOR");
	class FPatternLinear : SHADER_PERMUTATION_BOOL("PATTERN_LINEAR");
	class FPatternIgnoreAlpha : SHADER_PERMUTATION_BOOL("PATTERN_IGNORE_ALPHA");
	class FGammaCorrection : SHADER_PERMUTATION_BOOL("GAMMA_CORRECTION");
	class FAlphaMask : SHADER_PERMUTATION_BOOL("ALPHA_MASK");
	using FPermutationDomain = TShaderPermutationDomain<FEffect, FLinearColor, FPatternLinear, FPatternIgnoreAlpha, FGammaCorrection, FAlphaMask>;

	FNoesisPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FGlobalShader(Initializer)
	{
#if UE_VERSION_OLDER_THAN(5, 3, 0)
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
#else
		if (Initializer.ParameterMap.ContainsParameterAllocation(FNoesisPSRgbaConstants::GetStructMetadata()->GetShaderVariableName()))
		{
			PSConstantsBuffer.Bind(Initializer.ParameterMap, FNoesisPSRgbaConstants::GetStructMetadata()->GetShaderVariableName());
		}
		else if (Initializer.ParameterMap.ContainsParameterAllocation(FNoesisPSOpacityConstants::GetStructMetadata()->GetShaderVariableName()))
		{
			PSConstantsBuffer.Bind(Initializer.ParameterMap, FNoesisPSOpacityConstants::GetStructMetadata()->GetShaderVariableName());
		}
		else if (Initializer.ParameterMap.ContainsParameterAllocation(FNoesisPSRadialGradConstants::GetStructMetadata()->GetShaderVariableName()))
		{
			PSConstantsBuffer.Bind(Initializer.ParameterMap, FNoesisPSRadialGradConstants::GetStructMetadata()->GetShaderVariableName());
		}

		if (Initializer.ParameterMap.ContainsParameterAllocation(FNoesisBlurConstants::GetStructMetadata()->GetShaderVariableName()))
		{
			EffectsBuffer.Bind(Initializer.ParameterMap, FNoesisBlurConstants::GetStructMetadata()->GetShaderVariableName());
		}
		else if (Initializer.ParameterMap.ContainsParameterAllocation(FNoesisShadowConstants::GetStructMetadata()->GetShaderVariableName()))
		{
			EffectsBuffer.Bind(Initializer.ParameterMap, FNoesisShadowConstants::GetStructMetadata()->GetShaderVariableName());
		}
#endif

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
		GammaAndAlphaValues.Bind(Initializer.ParameterMap, TEXT("gammaAndAlphaValues"));
	}

	FNoesisPS() = default;

	static bool ShouldCache(EShaderPlatform Platform)
	{
		return true;
	}

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		FPermutationDomain Permutation(Parameters.PermutationId);

		// Custom effects use FNoesisCustomEffectPS.
		if (Permutation.Get<FEffect>() == Noesis::Shader::Enum::Custom_Effect)
		{
			return false;
		}

		// We don't support subpixel font rendering.
		if (Permutation.Get<FEffect>() >= Noesis::Shader::Enum::SDF_LCD_Solid && Permutation.Get<FEffect>() <= Noesis::Shader::Enum::SDF_LCD_Pattern_Mirror)
		{
			return false;
		}

		// Alpha masking is only used if UpdateVelocities is true.
		bool UpdateVelocities = true;
		GConfig->GetBool(TEXT("/Script/NoesisRuntime.NoesisSettings"), TEXT("UpdateVelocities"), UpdateVelocities, GEngineIni);
		if (Permutation.Get<FAlphaMask>() && !UpdateVelocities)
		{
			return false;
		}

		// If AlphaMask is true, the rest of the settings don't matter.
		if (Permutation.Get<FAlphaMask>() && (!Permutation.Get<FLinearColor>() || Permutation.Get<FPatternLinear>() || Permutation.Get<FPatternIgnoreAlpha>() || Permutation.Get<FGammaCorrection>()))
		{
			return false;
		}

		// No need to build more than one permutation of the shaders that don't use a pattern texture.
		if (!NoesisShaderHasPattern[Permutation.Get<FEffect>()] && !Permutation.Get<FAlphaMask>() && (Permutation.Get<FLinearColor>() || Permutation.Get<FPatternLinear>() || Permutation.Get<FPatternIgnoreAlpha>()))
		{
			return false;
		}

		// The combinations where LINEAR_COLOR == PATTERN_LINEAR are the same. We only need one, we pick (false, false).
		if (NoesisShaderHasPattern[Permutation.Get<FEffect>()] && Permutation.Get<FLinearColor>() && Permutation.Get<FPatternLinear>())
		{
			return false;
		}

		// Gamma correction can only happen on the final onscreen render.
		if (Permutation.Get<FLinearColor>() && Permutation.Get<FGammaCorrection>())
		{
			return false;
		}

		return true;
	}


	void SetPSConstants(FRHICommandList& RHICmdList, const FUniformBufferRHIRef& PSConstants)
	{
		FRHIPixelShader* ShaderRHI = RHICmdList.GetBoundPixelShader();

		check(PSConstantsBuffer.IsBound());
#if UE_VERSION_OLDER_THAN(5, 3, 0)
		SetUniformBufferParameter(RHICmdList, ShaderRHI, PSConstantsBuffer, PSConstants);
#else
		FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
		BatchedParameters.SetShaderUniformBuffer(PSConstantsBuffer.GetBaseIndex(), PSConstants);
		RHICmdList.SetBatchedShaderParameters(ShaderRHI, BatchedParameters);
#endif

	}

	void SetEffects(FRHICommandList& RHICmdList, const FUniformBufferRHIRef& Effects)
	{
		FRHIPixelShader* ShaderRHI = RHICmdList.GetBoundPixelShader();

		check(EffectsBuffer.IsBound());
#if UE_VERSION_OLDER_THAN(5, 3, 0)
		SetUniformBufferParameter(RHICmdList, ShaderRHI, EffectsBuffer, Effects);
#else
		FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
		BatchedParameters.SetShaderUniformBuffer(EffectsBuffer.GetBaseIndex(), Effects);
		RHICmdList.SetBatchedShaderParameters(ShaderRHI, BatchedParameters);
#endif
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

	void SetDisplayGammaAndInvertAlphaAndContrast(FRHICommandList& RHICmdList, float DisplayGamma, float InvertAlpha, float Contrast)
	{
		FRHIPixelShader* ShaderRHI = RHICmdList.GetBoundPixelShader();

		FVector4f Values(2.2f / DisplayGamma, 1.0f / DisplayGamma, InvertAlpha, Contrast);
#if UE_VERSION_OLDER_THAN(5, 3, 0)
		SetShaderValue(RHICmdList, ShaderRHI, GammaAndAlphaValues, Values);
#else
		FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
		SetShaderValue(BatchedParameters, GammaAndAlphaValues, Values);
		RHICmdList.SetBatchedShaderParameters(ShaderRHI, BatchedParameters);
#endif
	}

	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);

		static const auto CVar = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.HDR.Display.OutputDevice"));
#if UE_VERSION_OLDER_THAN(5, 1, 0)
		OutEnvironment.SetDefine(TEXT("USE_709"), CVar ? (CVar->GetValueOnAnyThread() == 1) : 1);
#else
		OutEnvironment.SetDefine(TEXT("USE_709"), CVar ? (CVar->GetValueOnAnyThread() == (int32)EDisplayOutputFormat::SDR_Rec709) : 1);
#endif
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
	LAYOUT_FIELD(FShaderParameter, GammaAndAlphaValues)
};

class FNoesisMaterialPS : public FMaterialShader
{
public:
	DECLARE_SHADER_TYPE(FNoesisMaterialPS, Material);

	class FEffect : SHADER_PERMUTATION_INT("EFFECT", Noesis::Shader::Enum::Count);
	class FLinearColor : SHADER_PERMUTATION_BOOL("LINEAR_COLOR");
	class FGammaCorrection : SHADER_PERMUTATION_BOOL("GAMMA_CORRECTION");
	class FAlphaMask : SHADER_PERMUTATION_BOOL("ALPHA_MASK");
	using FPermutationDomain = TShaderPermutationDomain<FEffect, FLinearColor, FGammaCorrection, FAlphaMask>;

	FNoesisMaterialPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FMaterialShader(Initializer)
	{
#if UE_VERSION_OLDER_THAN(5, 3, 0)
		PSConstantsBuffer.Bind(Initializer.ParameterMap, FNoesisPSOpacityConstants::StaticStructMetadata.GetShaderVariableName());
#else
		PSConstantsBuffer.Bind(Initializer.ParameterMap, FNoesisPSOpacityConstants::GetStructMetadata()->GetShaderVariableName());
#endif

		ImageTexture.Bind(Initializer.ParameterMap, TEXT("imageTex"));
		ImageSampler.Bind(Initializer.ParameterMap, TEXT("imageSampler"));
		GlyphsTexture.Bind(Initializer.ParameterMap, TEXT("glyphsTex"));
		GlyphsSampler.Bind(Initializer.ParameterMap, TEXT("glyphsSampler"));
		GammaAndAlphaValues.Bind(Initializer.ParameterMap, TEXT("gammaAndAlphaValues"));
	}

	FNoesisMaterialPS() = default;

	static bool ShouldCache(EShaderPlatform Platform)
	{
		return true;
	}

	static bool ShouldCompilePermutation(const FMaterialShaderPermutationParameters& Parameters)
	{
		FPermutationDomain Permutation(Parameters.PermutationId);

		// Only shaders with pattern textures can be used with materials.
		if (!NoesisShaderHasPattern[Permutation.Get<FEffect>()])
		{
			return false;
		}

		// We don't support subpixel font rendering.
		if (Permutation.Get<FEffect>() >= Noesis::Shader::Enum::SDF_LCD_Solid && Permutation.Get<FEffect>() <= Noesis::Shader::Enum::SDF_LCD_Pattern_Mirror)
		{
			return false;
		}

		// Alpha masking is only used if UpdateVelocities is true.
		bool UpdateVelocities = true;
		GConfig->GetBool(TEXT("/Script/NoesisRuntime.NoesisSettings"), TEXT("UpdateVelocities"), UpdateVelocities, GEngineIni);
		if (Permutation.Get<FAlphaMask>() && !UpdateVelocities)
		{
			return false;
		}

		// If AlphaMask is true, the rest of the settings don't matter.
		if (Permutation.Get<FAlphaMask>() && (!Permutation.Get<FLinearColor>() || Permutation.Get<FGammaCorrection>()))
		{
			return false;
		}

		// Gamma correction can only happen on the final onscreen render.
		if (Permutation.Get<FLinearColor>() && Permutation.Get<FGammaCorrection>())
		{
			return false;
		}

		return Parameters.MaterialParameters.MaterialDomain == MD_UI;
	}

	void SetPSConstants(FRHICommandList& RHICmdList, const FUniformBufferRHIRef& PSConstants)
	{
		FRHIPixelShader* ShaderRHI = RHICmdList.GetBoundPixelShader();

		check(PSConstantsBuffer.IsBound());
#if UE_VERSION_OLDER_THAN(5, 3, 0)
		SetUniformBufferParameter(RHICmdList, ShaderRHI, PSConstantsBuffer, PSConstants);
#else
		FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
		BatchedParameters.SetShaderUniformBuffer(PSConstantsBuffer.GetBaseIndex(), PSConstants);
		RHICmdList.SetBatchedShaderParameters(ShaderRHI, BatchedParameters);
#endif
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

	void SetDisplayGammaAndInvertAlphaAndContrast(FRHICommandList& RHICmdList, float DisplayGamma, float InvertAlpha, float Contrast)
	{
		FRHIPixelShader* ShaderRHI = RHICmdList.GetBoundPixelShader();

		FVector4f Values(2.2f / DisplayGamma, 1.0f / DisplayGamma, InvertAlpha, Contrast);
#if UE_VERSION_OLDER_THAN(5, 3, 0)
		SetShaderValue(RHICmdList, ShaderRHI, GammaAndAlphaValues, Values);
#else
		FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
		SetShaderValue(BatchedParameters, GammaAndAlphaValues, Values);
		RHICmdList.SetBatchedShaderParameters(ShaderRHI, BatchedParameters);
#endif
	}

	static void ModifyCompilationEnvironment(const FMaterialShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FMaterialShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);

		OutEnvironment.SetDefine(TEXT("GAMMA_CORRECTION"), false);

		static const auto CVar = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.HDR.Display.OutputDevice"));
#if UE_VERSION_OLDER_THAN(5, 1, 0)
		OutEnvironment.SetDefine(TEXT("USE_709"), CVar ? (CVar->GetValueOnAnyThread() == 1) : 1);
#else
		OutEnvironment.SetDefine(TEXT("USE_709"), CVar ? (CVar->GetValueOnAnyThread() == (int32)EDisplayOutputFormat::SDR_Rec709) : 1);
#endif
	}

	LAYOUT_FIELD(FShaderUniformBufferParameter, PSConstantsBuffer)
	LAYOUT_FIELD(FShaderResourceParameter, ImageTexture)
	LAYOUT_FIELD(FShaderResourceParameter, ImageSampler)
	LAYOUT_FIELD(FShaderResourceParameter, GlyphsTexture)
	LAYOUT_FIELD(FShaderResourceParameter, GlyphsSampler)
	LAYOUT_FIELD(FShaderParameter, GammaAndAlphaValues)
};


BEGIN_SHADER_PARAMETER_STRUCT(FNoesisSceneTextureShaderParameters, )
	SHADER_PARAMETER_STRUCT_REF(FSceneTextureUniformParameters, SceneTextures)
	SHADER_PARAMETER_STRUCT_REF(FMobileSceneTextureUniformParameters, MobileSceneTextures)
END_SHADER_PARAMETER_STRUCT()

BEGIN_SHADER_PARAMETER_STRUCT(FNoesisScreenPassTextureInput, )
	SHADER_PARAMETER_STRUCT_INCLUDE(FScreenPassTextureViewportParameters, Viewport)
	SHADER_PARAMETER_TEXTURE(Texture2D, Texture)
	SHADER_PARAMETER_SAMPLER(SamplerState, Sampler)
END_SHADER_PARAMETER_STRUCT()

BEGIN_SHADER_PARAMETER_STRUCT(FNoesisPostProcessMaterialParameters, )
	SHADER_PARAMETER_STRUCT_REF(FViewUniformShaderParameters, View)
	SHADER_PARAMETER_STRUCT_INCLUDE(FNoesisSceneTextureShaderParameters, SceneTextures)
	SHADER_PARAMETER_STRUCT(FScreenPassTextureViewportParameters, PostProcessInput)
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

	class FGammaCorrection : SHADER_PERMUTATION_BOOL("GAMMA_CORRECTION");
	class FAlphaMask : SHADER_PERMUTATION_BOOL("ALPHA_MASK");
	using FPermutationDomain = TShaderPermutationDomain<FGammaCorrection, FAlphaMask>;

	FNoesisCustomEffectPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FMaterialShader(Initializer)
	{
		BindForLegacyShaderParameters<FParameters>(this, Initializer.PermutationId, Initializer.ParameterMap, false);

		GammaAndAlphaValues.Bind(Initializer.ParameterMap, TEXT("gammaAndAlphaValues"));
	}

	FNoesisCustomEffectPS() = default;

	static bool ShouldCompilePermutation(const FMaterialShaderPermutationParameters& Parameters)
	{
		FPermutationDomain Permutation(Parameters.PermutationId);

		// Alpha masking is only used if UpdateVelocities is true.
		bool UpdateVelocities = true;
		GConfig->GetBool(TEXT("/Script/NoesisRuntime.NoesisSettings"), TEXT("UpdateVelocities"), UpdateVelocities, GEngineIni);
		if (Permutation.Get<FAlphaMask>() && !UpdateVelocities)
		{
			return false;
		}

		// If AlphaMask is true, the rest of the settings don't matter.
		if (Permutation.Get<FAlphaMask>() && Permutation.Get<FGammaCorrection>())
		{
			return false;
		}

		return Parameters.MaterialParameters.MaterialDomain == MD_PostProcess;
	}

	void SetDisplayGammaAndInvertAlphaAndContrast(FRHICommandList& RHICmdList, float DisplayGamma, float InvertAlpha, float Contrast)
	{
		FRHIPixelShader* ShaderRHI = RHICmdList.GetBoundPixelShader();

		FVector4f Values(2.2f / DisplayGamma, 1.0f / DisplayGamma, InvertAlpha, Contrast);
#if UE_VERSION_OLDER_THAN(5, 3, 0)
		SetShaderValue(RHICmdList, ShaderRHI, GammaAndAlphaValues, Values);
#else
		FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
		SetShaderValue(BatchedParameters, GammaAndAlphaValues, Values);
		RHICmdList.SetBatchedShaderParameters(ShaderRHI, BatchedParameters);
#endif
	}

	static void ModifyCompilationEnvironment(const FMaterialShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FMaterialShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
		OutEnvironment.SetDefine(TEXT("POST_PROCESS_MATERIAL"), 1);

		OutEnvironment.SetDefine(TEXT("POST_PROCESS_MATERIAL_BEFORE_TONEMAP"), 0);

		uint32 StencilCompareFunction = Parameters.MaterialParameters.bIsStencilTestEnabled ? Parameters.MaterialParameters.StencilCompare : EMaterialStencilCompare::MSC_Never;
		OutEnvironment.SetDefine(TEXT("MOBILE_STENCIL_COMPARE_FUNCTION"), StencilCompareFunction);

		static const auto CVar = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.HDR.Display.OutputDevice"));
#if UE_VERSION_OLDER_THAN(5, 1, 0)
		OutEnvironment.SetDefine(TEXT("USE_709"), CVar ? (CVar->GetValueOnAnyThread() == 1) : 1);
#else
		OutEnvironment.SetDefine(TEXT("USE_709"), CVar ? (CVar->GetValueOnAnyThread() == (int32)EDisplayOutputFormat::SDR_Rec709) : 1);
#endif
	}

	static void SetParameters(FRHICommandList& RHICmdList, const TShaderRef<FNoesisCustomEffectPS>& Shader, const FSceneView& View, const FMaterialRenderProxy* Proxy, const FMaterial& Material, const FParameters& Parameters)
	{
		FMaterialShader* MaterialShader = Shader.GetShader();
		FRHIPixelShader* ShaderRHI = Shader.GetPixelShader();
		MaterialShader->SetParameters(RHICmdList, ShaderRHI, Proxy, Material, View);
		SetShaderParameters(RHICmdList, Shader, ShaderRHI, Parameters);
	}

	LAYOUT_FIELD(FShaderParameter, GammaAndAlphaValues)
};
