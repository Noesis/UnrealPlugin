////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"
#include "Misc/EngineVersionComparison.h"

// RHI includes
#include "RHI.h"

// RenderCore includes
#include "RenderResource.h"
#include "GlobalShader.h"
#include "ShaderParameterUtils.h"

// Renderer includes
#include "MaterialShader.h"
#if UE_VERSION_OLDER_THAN(5, 3, 0)
#include "Runtime/Renderer/Private/ScreenPass.h"
#endif
#include "Runtime/Renderer/Private/PostProcess/PostProcessMaterial.h"

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

class FNoesisVSBase : public FGlobalShader
{
	DECLARE_INLINE_TYPE_LAYOUT(FNoesisVSBase, NonVirtual);
public:
	FNoesisVSBase(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
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

	FNoesisVSBase()
	{
	}

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters) { return true; }

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

enum class NoesisColorSpace
{
	sRGB,
	Linear
};

template<Noesis::Shader::Vertex::Enum VertexShader, NoesisColorSpace ColorSpace = NoesisColorSpace::sRGB, bool Stereo = false>
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
	static const constexpr bool LinearColor = ColorSpace == NoesisColorSpace::Linear;

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
		FNoesisVSBase::ModifyCompilationEnvironment(Parameters, OutEnvironment);
		OutEnvironment.SetDefine(TEXT("HAS_COLOR"), HasColor);
		OutEnvironment.SetDefine(TEXT("HAS_UV0"), HasTex0);
		OutEnvironment.SetDefine(TEXT("HAS_UV1"), HasTex1);
		OutEnvironment.SetDefine(TEXT("HAS_COVERAGE"), HasCoverage);
		OutEnvironment.SetDefine(TEXT("HAS_RECT"), HasRect);
		OutEnvironment.SetDefine(TEXT("HAS_TILE"), HasTile);
		OutEnvironment.SetDefine(TEXT("HAS_IMAGE_POSITION"), HasImagePos);
		OutEnvironment.SetDefine(TEXT("DOWNSAMPLE"), Downsample);
		OutEnvironment.SetDefine(TEXT("SDF"), SDF);
		OutEnvironment.SetDefine(TEXT("LINEAR_COLOR"), LinearColor);
		OutEnvironment.SetDefine(TEXT("WITH_STEREO"), Stereo);
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

typedef FNoesisVS<Noesis::Shader::Vertex::PosColor, NoesisColorSpace::Linear> FNoesisPosLinearColorVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorCoverage, NoesisColorSpace::Linear> FNoesisPosLinearColorCoverageVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex1_SDF, NoesisColorSpace::Linear> FNoesisPosLinearColorTex1SDFVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex1, NoesisColorSpace::Linear> FNoesisPosLinearColorTex1VS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex0Tex1, NoesisColorSpace::Linear> FNoesisPosLinearColorTex0Tex1VS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex1Rect, NoesisColorSpace::Linear> FNoesisPosLinearColorTex1RectVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex0RectImagePos, NoesisColorSpace::Linear> FNoesisPosLinearColorTex0RectImagePosVS;

typedef FNoesisVS<Noesis::Shader::Vertex::Pos, NoesisColorSpace::sRGB, true> FNoesisPosStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColor, NoesisColorSpace::sRGB, true> FNoesisPosColorStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0, NoesisColorSpace::sRGB, true> FNoesisPosTex0StereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0Rect, NoesisColorSpace::sRGB, true> FNoesisPosTex0RectStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0RectTile, NoesisColorSpace::sRGB, true> FNoesisPosTex0RectTileStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorCoverage, NoesisColorSpace::sRGB, true> FNoesisPosColorCoverageStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0Coverage, NoesisColorSpace::sRGB, true> FNoesisPosTex0CoverageStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0CoverageRect, NoesisColorSpace::sRGB, true> FNoesisPosTex0CoverageRectStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0CoverageRectTile, NoesisColorSpace::sRGB, true> FNoesisPosTex0CoverageRectTileStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex1_SDF, NoesisColorSpace::sRGB, true> FNoesisPosColorTex1SDFStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0Tex1_SDF, NoesisColorSpace::sRGB, true> FNoesisPosTex0Tex1SDFStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0Tex1Rect_SDF, NoesisColorSpace::sRGB, true> FNoesisPosTex0Tex1RectSDFStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0Tex1RectTile_SDF, NoesisColorSpace::sRGB, true> FNoesisPosTex0Tex1RectTileSDFStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex1, NoesisColorSpace::sRGB, true> FNoesisPosColorTex1StereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0Tex1, NoesisColorSpace::sRGB, true> FNoesisPosTex0Tex1StereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0Tex1Rect, NoesisColorSpace::sRGB, true> FNoesisPosTex0Tex1RectStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0Tex1RectTile, NoesisColorSpace::sRGB, true> FNoesisPosTex0Tex1RectTileStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex0Tex1, NoesisColorSpace::sRGB, true> FNoesisPosColorTex0Tex1StereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosTex0Tex1_Downsample, NoesisColorSpace::sRGB, true> FNoesisPosTex0Tex1DownsampleStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex1Rect, NoesisColorSpace::sRGB, true> FNoesisPosColorTex1RectStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex0RectImagePos, NoesisColorSpace::sRGB, true> FNoesisPosColorTex0RectImagePosStereoVS;

typedef FNoesisVS<Noesis::Shader::Vertex::PosColor, NoesisColorSpace::Linear, true> FNoesisPosLinearColorStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorCoverage, NoesisColorSpace::Linear, true> FNoesisPosLinearColorCoverageStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex1_SDF, NoesisColorSpace::Linear, true> FNoesisPosLinearColorTex1SDFStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex1, NoesisColorSpace::Linear, true> FNoesisPosLinearColorTex1StereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex0Tex1, NoesisColorSpace::Linear, true> FNoesisPosLinearColorTex0Tex1StereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex1Rect, NoesisColorSpace::Linear, true> FNoesisPosLinearColorTex1RectStereoVS;
typedef FNoesisVS<Noesis::Shader::Vertex::PosColorTex0RectImagePos, NoesisColorSpace::Linear, true> FNoesisPosLinearColorTex0RectImagePosStereoVS;

class FNoesisPSBase : public FGlobalShader
{
	DECLARE_INLINE_TYPE_LAYOUT(FNoesisPSBase, NonVirtual);

public:
	FNoesisPSBase(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
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

	FNoesisPSBase()
	{
	}

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters) { return true; }

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

enum class NoesisPatternTextureAction : uint8
{
	NoAction = 0,
	PatternSRGB = 1,
	PatternLinear = 2,
	PatternIgnoreAlpha = 4,
	PatternSRGBIgnoreAlpha = PatternSRGB | PatternIgnoreAlpha,
	PatternLinearIgnoreAlpha = PatternLinear | PatternIgnoreAlpha
};

static constexpr bool HasFlag(NoesisPatternTextureAction value, NoesisPatternTextureAction flag)
{
	return ((uint8)value & (uint8)flag) != 0;
}

template<Noesis::Shader::Enum Effect, NoesisPatternTextureAction PatternTextureAction = NoesisPatternTextureAction::NoAction, bool GammaCorrection = false>
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
		FNoesisPSBase::ModifyCompilationEnvironment(Parameters, OutEnvironment);
		OutEnvironment.SetDefine(TEXT("EFFECT"), Effect);

		// MediaTextures don't work correctly if they are not rendered to SRGB textures.
		// We need to convert them on the shaders.
		// MediaTextures are sampled from the pattern textures.
		// The shaders that need to do this conversion are more expensive, so we are still
		// setting SRGB to false when we import textures. But at least this means that
		// user textures should work regardless.
		OutEnvironment.SetDefine(TEXT("PATTERN_SRGB"), HasFlag(PatternTextureAction, NoesisPatternTextureAction::PatternSRGB));

		// TODO: Add comment
		OutEnvironment.SetDefine(TEXT("PATTERN_LINEAR"), HasFlag(PatternTextureAction, NoesisPatternTextureAction::PatternLinear));
		OutEnvironment.SetDefine(TEXT("PATTERN_IGNORE_ALPHA"), HasFlag(PatternTextureAction, NoesisPatternTextureAction::PatternIgnoreAlpha));

		OutEnvironment.SetDefine(TEXT("GAMMA_CORRECTION"), GammaCorrection);
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
typedef FNoesisPS<Noesis::Shader::Path_Pattern, NoesisPatternTextureAction::PatternSRGB> FNoesisPathPatternSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGB> FNoesisPathPatternClampSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGB> FNoesisPathPatternRepeatSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGB> FNoesisPathPatternMirrorUSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGB> FNoesisPathPatternMirrorVSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGB> FNoesisPathPatternMirrorSRGBPS;

typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern, NoesisPatternTextureAction::PatternSRGB> FNoesisPathAAPatternSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGB> FNoesisPathAAPatternClampSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGB> FNoesisPathAAPatternRepeatSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGB> FNoesisPathAAPatternMirrorUSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGB> FNoesisPathAAPatternMirrorVSRGBPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGB> FNoesisPathAAPatternMirrorSRGBPS;

typedef FNoesisPS<Noesis::Shader::SDF_Pattern, NoesisPatternTextureAction::PatternSRGB> FNoesisSDFPatternSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGB> FNoesisSDFPatternClampSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGB> FNoesisSDFPatternRepeatSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGB> FNoesisSDFPatternMirrorUSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGB> FNoesisSDFPatternMirrorVSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGB> FNoesisSDFPatternMirrorSRGBPS;

typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern, NoesisPatternTextureAction::PatternSRGB> FNoesisSDFLCDPatternSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGB> FNoesisSDFLCDPatternClampSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGB> FNoesisSDFLCDPatternRepeatSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGB> FNoesisSDFLCDPatternMirrorUSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGB> FNoesisSDFLCDPatternMirrorVSRGBPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGB> FNoesisSDFLCDPatternMirrorSRGBPS;

typedef FNoesisPS<Noesis::Shader::Opacity_Pattern, NoesisPatternTextureAction::PatternSRGB> FNoesisOpacityPatternSRGBPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGB> FNoesisOpacityPatternClampSRGBPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGB> FNoesisOpacityPatternRepeatSRGBPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGB> FNoesisOpacityPatternMirrorUSRGBPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGB> FNoesisOpacityPatternMirrorVSRGBPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGB> FNoesisOpacityPatternMirrorSRGBPS;

// Read the comment next to PATTERN_LINEAR in FNoesisPS::ModifyCompilationEnvironment
typedef FNoesisPS<Noesis::Shader::Path_Pattern, NoesisPatternTextureAction::PatternLinear> FNoesisPathPatternLinearPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Clamp, NoesisPatternTextureAction::PatternLinear> FNoesisPathPatternClampLinearPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Repeat, NoesisPatternTextureAction::PatternLinear> FNoesisPathPatternRepeatLinearPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorU, NoesisPatternTextureAction::PatternLinear> FNoesisPathPatternMirrorULinearPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorV, NoesisPatternTextureAction::PatternLinear> FNoesisPathPatternMirrorVLinearPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Mirror, NoesisPatternTextureAction::PatternLinear> FNoesisPathPatternMirrorLinearPS;

typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern, NoesisPatternTextureAction::PatternLinear> FNoesisPathAAPatternLinearPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Clamp, NoesisPatternTextureAction::PatternLinear> FNoesisPathAAPatternClampLinearPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Repeat, NoesisPatternTextureAction::PatternLinear> FNoesisPathAAPatternRepeatLinearPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorU, NoesisPatternTextureAction::PatternLinear> FNoesisPathAAPatternMirrorULinearPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorV, NoesisPatternTextureAction::PatternLinear> FNoesisPathAAPatternMirrorVLinearPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Mirror, NoesisPatternTextureAction::PatternLinear> FNoesisPathAAPatternMirrorLinearPS;

typedef FNoesisPS<Noesis::Shader::SDF_Pattern, NoesisPatternTextureAction::PatternLinear> FNoesisSDFPatternLinearPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Clamp, NoesisPatternTextureAction::PatternLinear> FNoesisSDFPatternClampLinearPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Repeat, NoesisPatternTextureAction::PatternLinear> FNoesisSDFPatternRepeatLinearPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorU, NoesisPatternTextureAction::PatternLinear> FNoesisSDFPatternMirrorULinearPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorV, NoesisPatternTextureAction::PatternLinear> FNoesisSDFPatternMirrorVLinearPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Mirror, NoesisPatternTextureAction::PatternLinear> FNoesisSDFPatternMirrorLinearPS;

typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern, NoesisPatternTextureAction::PatternLinear> FNoesisSDFLCDPatternLinearPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Clamp, NoesisPatternTextureAction::PatternLinear> FNoesisSDFLCDPatternClampLinearPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Repeat, NoesisPatternTextureAction::PatternLinear> FNoesisSDFLCDPatternRepeatLinearPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorU, NoesisPatternTextureAction::PatternLinear> FNoesisSDFLCDPatternMirrorULinearPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorV, NoesisPatternTextureAction::PatternLinear> FNoesisSDFLCDPatternMirrorVLinearPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Mirror, NoesisPatternTextureAction::PatternLinear> FNoesisSDFLCDPatternMirrorLinearPS;

typedef FNoesisPS<Noesis::Shader::Opacity_Pattern, NoesisPatternTextureAction::PatternLinear> FNoesisOpacityPatternLinearPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Clamp, NoesisPatternTextureAction::PatternLinear> FNoesisOpacityPatternClampLinearPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Repeat, NoesisPatternTextureAction::PatternLinear> FNoesisOpacityPatternRepeatLinearPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorU, NoesisPatternTextureAction::PatternLinear> FNoesisOpacityPatternMirrorULinearPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorV, NoesisPatternTextureAction::PatternLinear> FNoesisOpacityPatternMirrorVLinearPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Mirror, NoesisPatternTextureAction::PatternLinear> FNoesisOpacityPatternMirrorLinearPS;

// The commas in the template parameter list break the IMPLEMENT_SHADER_TYPE macro, so we need typedefs.
typedef FNoesisPS<Noesis::Shader::RGBA, NoesisPatternTextureAction::NoAction, true> FNoesisRgbaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Mask, NoesisPatternTextureAction::NoAction, true> FNoesisMaskGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Clear, NoesisPatternTextureAction::NoAction, true> FNoesisClearGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::Path_Solid, NoesisPatternTextureAction::NoAction, true> FNoesisPathSolidGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Linear, NoesisPatternTextureAction::NoAction, true> FNoesisPathLinearGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Radial, NoesisPatternTextureAction::NoAction, true> FNoesisPathRadialGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern, NoesisPatternTextureAction::NoAction, true> FNoesisPathPatternGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Clamp, NoesisPatternTextureAction::NoAction, true> FNoesisPathPatternClampGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Repeat, NoesisPatternTextureAction::NoAction, true> FNoesisPathPatternRepeatGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorU, NoesisPatternTextureAction::NoAction, true> FNoesisPathPatternMirrorUGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorV, NoesisPatternTextureAction::NoAction, true> FNoesisPathPatternMirrorVGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Mirror, NoesisPatternTextureAction::NoAction, true> FNoesisPathPatternMirrorGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::Path_AA_Solid, NoesisPatternTextureAction::NoAction, true> FNoesisPathAASolidGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Linear, NoesisPatternTextureAction::NoAction, true> FNoesisPathAALinearGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Radial, NoesisPatternTextureAction::NoAction, true> FNoesisPathAARadialGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern, NoesisPatternTextureAction::NoAction, true> FNoesisPathAAPatternGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Clamp, NoesisPatternTextureAction::NoAction, true> FNoesisPathAAPatternClampGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Repeat, NoesisPatternTextureAction::NoAction, true> FNoesisPathAAPatternRepeatGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorU, NoesisPatternTextureAction::NoAction, true> FNoesisPathAAPatternMirrorUGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorV, NoesisPatternTextureAction::NoAction, true> FNoesisPathAAPatternMirrorVGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Mirror, NoesisPatternTextureAction::NoAction, true> FNoesisPathAAPatternMirrorGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::SDF_Solid, NoesisPatternTextureAction::NoAction, true> FNoesisSDFSolidGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Linear, NoesisPatternTextureAction::NoAction, true> FNoesisSDFLinearGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Radial, NoesisPatternTextureAction::NoAction, true> FNoesisSDFRadialGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern, NoesisPatternTextureAction::NoAction, true> FNoesisSDFPatternGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Clamp, NoesisPatternTextureAction::NoAction, true> FNoesisSDFPatternClampGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Repeat, NoesisPatternTextureAction::NoAction, true> FNoesisSDFPatternRepeatGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorU, NoesisPatternTextureAction::NoAction, true> FNoesisSDFPatternMirrorUGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorV, NoesisPatternTextureAction::NoAction, true> FNoesisSDFPatternMirrorVGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Mirror, NoesisPatternTextureAction::NoAction, true> FNoesisSDFPatternMirrorGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::SDF_LCD_Solid, NoesisPatternTextureAction::NoAction, true> FNoesisSDFLCDSolidGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Linear, NoesisPatternTextureAction::NoAction, true> FNoesisSDFLCDLinearGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Radial, NoesisPatternTextureAction::NoAction, true> FNoesisSDFLCDRadialGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern, NoesisPatternTextureAction::NoAction, true> FNoesisSDFLCDPatternGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Clamp, NoesisPatternTextureAction::NoAction, true> FNoesisSDFLCDPatternClampGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Repeat, NoesisPatternTextureAction::NoAction, true> FNoesisSDFLCDPatternRepeatGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorU, NoesisPatternTextureAction::NoAction, true> FNoesisSDFLCDPatternMirrorUGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorV, NoesisPatternTextureAction::NoAction, true> FNoesisSDFLCDPatternMirrorVGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Mirror, NoesisPatternTextureAction::NoAction, true> FNoesisSDFLCDPatternMirrorGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::Opacity_Solid, NoesisPatternTextureAction::NoAction, true> FNoesisOpacitySolidGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Linear, NoesisPatternTextureAction::NoAction, true> FNoesisOpacityLinearGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Radial, NoesisPatternTextureAction::NoAction, true> FNoesisOpacityRadialGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern, NoesisPatternTextureAction::NoAction, true> FNoesisOpacityPatternGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Clamp, NoesisPatternTextureAction::NoAction, true> FNoesisOpacityPatternClampGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Repeat, NoesisPatternTextureAction::NoAction, true> FNoesisOpacityPatternRepeatGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorU, NoesisPatternTextureAction::NoAction, true> FNoesisOpacityPatternMirrorUGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorV, NoesisPatternTextureAction::NoAction, true> FNoesisOpacityPatternMirrorVGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Mirror, NoesisPatternTextureAction::NoAction, true> FNoesisOpacityPatternMirrorGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::Upsample, NoesisPatternTextureAction::NoAction, true> FNoesisUpsampleGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Downsample, NoesisPatternTextureAction::NoAction, true> FNoesisDownsampleGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::Shadow, NoesisPatternTextureAction::NoAction, true> FNoesisShadowGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Blur, NoesisPatternTextureAction::NoAction, true> FNoesisBlurGammaCorrectionPS;

// Read the comment next to PATTERN_SRGB in FNoesisPS::ModifyCompilationEnvironment
typedef FNoesisPS<Noesis::Shader::Path_Pattern, NoesisPatternTextureAction::PatternSRGB, true> FNoesisPathPatternSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGB, true> FNoesisPathPatternClampSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGB, true> FNoesisPathPatternRepeatSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGB, true> FNoesisPathPatternMirrorUSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGB, true> FNoesisPathPatternMirrorVSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGB, true> FNoesisPathPatternMirrorSRGBGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern, NoesisPatternTextureAction::PatternSRGB, true> FNoesisPathAAPatternSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGB, true> FNoesisPathAAPatternClampSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGB, true> FNoesisPathAAPatternRepeatSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGB, true> FNoesisPathAAPatternMirrorUSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGB, true> FNoesisPathAAPatternMirrorVSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGB, true> FNoesisPathAAPatternMirrorSRGBGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::SDF_Pattern, NoesisPatternTextureAction::PatternSRGB, true> FNoesisSDFPatternSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGB, true> FNoesisSDFPatternClampSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGB, true> FNoesisSDFPatternRepeatSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGB, true> FNoesisSDFPatternMirrorUSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGB, true> FNoesisSDFPatternMirrorVSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGB, true> FNoesisSDFPatternMirrorSRGBGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern, NoesisPatternTextureAction::PatternSRGB, true> FNoesisSDFLCDPatternSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGB, true> FNoesisSDFLCDPatternClampSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGB, true> FNoesisSDFLCDPatternRepeatSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGB, true> FNoesisSDFLCDPatternMirrorUSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGB, true> FNoesisSDFLCDPatternMirrorVSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGB, true> FNoesisSDFLCDPatternMirrorSRGBGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::Opacity_Pattern, NoesisPatternTextureAction::PatternSRGB, true> FNoesisOpacityPatternSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGB, true> FNoesisOpacityPatternClampSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGB, true> FNoesisOpacityPatternRepeatSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGB, true> FNoesisOpacityPatternMirrorUSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGB, true> FNoesisOpacityPatternMirrorVSRGBGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGB, true> FNoesisOpacityPatternMirrorSRGBGammaCorrectionPS;

// 
typedef FNoesisPS<Noesis::Shader::Path_Pattern, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisPathPatternIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Clamp, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisPathPatternClampIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Repeat, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisPathPatternRepeatIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorU, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisPathPatternMirrorUIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorV, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisPathPatternMirrorVIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Mirror, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisPathPatternMirrorIgnoreAlphaPS;

typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisPathAAPatternIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Clamp, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisPathAAPatternClampIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Repeat, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisPathAAPatternRepeatIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorU, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisPathAAPatternMirrorUIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorV, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisPathAAPatternMirrorVIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Mirror, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisPathAAPatternMirrorIgnoreAlphaPS;

typedef FNoesisPS<Noesis::Shader::SDF_Pattern, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisSDFPatternIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Clamp, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisSDFPatternClampIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Repeat, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisSDFPatternRepeatIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorU, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisSDFPatternMirrorUIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorV, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisSDFPatternMirrorVIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Mirror, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisSDFPatternMirrorIgnoreAlphaPS;

typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisSDFLCDPatternIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Clamp, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisSDFLCDPatternClampIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Repeat, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisSDFLCDPatternRepeatIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorU, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisSDFLCDPatternMirrorUIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorV, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisSDFLCDPatternMirrorVIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Mirror, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisSDFLCDPatternMirrorIgnoreAlphaPS;

typedef FNoesisPS<Noesis::Shader::Opacity_Pattern, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisOpacityPatternIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Clamp, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisOpacityPatternClampIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Repeat, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisOpacityPatternRepeatIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorU, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisOpacityPatternMirrorUIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorV, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisOpacityPatternMirrorVIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Mirror, NoesisPatternTextureAction::PatternIgnoreAlpha, false> FNoesisOpacityPatternMirrorIgnoreAlphaPS;

//
typedef FNoesisPS<Noesis::Shader::Path_Pattern, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisPathPatternSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisPathPatternClampSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisPathPatternRepeatSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisPathPatternMirrorUSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisPathPatternMirrorVSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisPathPatternMirrorSRGBIgnoreAlphaPS;

typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisPathAAPatternSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisPathAAPatternClampSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisPathAAPatternRepeatSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisPathAAPatternMirrorUSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisPathAAPatternMirrorVSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisPathAAPatternMirrorSRGBIgnoreAlphaPS;

typedef FNoesisPS<Noesis::Shader::SDF_Pattern, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisSDFPatternSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisSDFPatternClampSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisSDFPatternRepeatSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisSDFPatternMirrorUSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisSDFPatternMirrorVSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisSDFPatternMirrorSRGBIgnoreAlphaPS;

typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisSDFLCDPatternSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisSDFLCDPatternClampSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisSDFLCDPatternRepeatSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisSDFLCDPatternMirrorUSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisSDFLCDPatternMirrorVSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisSDFLCDPatternMirrorSRGBIgnoreAlphaPS;

typedef FNoesisPS<Noesis::Shader::Opacity_Pattern, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisOpacityPatternSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisOpacityPatternClampSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisOpacityPatternRepeatSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisOpacityPatternMirrorUSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisOpacityPatternMirrorVSRGBIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, false> FNoesisOpacityPatternMirrorSRGBIgnoreAlphaPS;

// Read the comment next to PATTERN_LINEAR in FNoesisPS::ModifyCompilationEnvironment
typedef FNoesisPS<Noesis::Shader::Path_Pattern, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisPathPatternLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Clamp, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisPathPatternClampLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Repeat, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisPathPatternRepeatLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorU, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisPathPatternMirrorULinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorV, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisPathPatternMirrorVLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Mirror, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisPathPatternMirrorLinearIgnoreAlphaPS;

typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisPathAAPatternLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Clamp, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisPathAAPatternClampLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Repeat, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisPathAAPatternRepeatLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorU, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisPathAAPatternMirrorULinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorV, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisPathAAPatternMirrorVLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Mirror, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisPathAAPatternMirrorLinearIgnoreAlphaPS;

typedef FNoesisPS<Noesis::Shader::SDF_Pattern, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisSDFPatternLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Clamp, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisSDFPatternClampLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Repeat, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisSDFPatternRepeatLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorU, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisSDFPatternMirrorULinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorV, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisSDFPatternMirrorVLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Mirror, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisSDFPatternMirrorLinearIgnoreAlphaPS;

typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisSDFLCDPatternLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Clamp, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisSDFLCDPatternClampLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Repeat, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisSDFLCDPatternRepeatLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorU, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisSDFLCDPatternMirrorULinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorV, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisSDFLCDPatternMirrorVLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Mirror, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisSDFLCDPatternMirrorLinearIgnoreAlphaPS;

typedef FNoesisPS<Noesis::Shader::Opacity_Pattern, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisOpacityPatternLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Clamp, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisOpacityPatternClampLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Repeat, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisOpacityPatternRepeatLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorU, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisOpacityPatternMirrorULinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorV, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisOpacityPatternMirrorVLinearIgnoreAlphaPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Mirror, NoesisPatternTextureAction::PatternLinearIgnoreAlpha, false> FNoesisOpacityPatternMirrorLinearIgnoreAlphaPS;

// The commas in the template parameter list break the IMPLEMENT_SHADER_TYPE macro, so we need typedefs.
typedef FNoesisPS<Noesis::Shader::Path_Pattern, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisPathPatternIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Clamp, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisPathPatternClampIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Repeat, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisPathPatternRepeatIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorU, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisPathPatternMirrorUIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorV, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisPathPatternMirrorVIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Mirror, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisPathPatternMirrorIgnoreAlphaGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisPathAAPatternIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Clamp, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisPathAAPatternClampIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Repeat, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisPathAAPatternRepeatIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorU, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisPathAAPatternMirrorUIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorV, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisPathAAPatternMirrorVIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Mirror, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisPathAAPatternMirrorIgnoreAlphaGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::SDF_Pattern, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisSDFPatternIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Clamp, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisSDFPatternClampIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Repeat, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisSDFPatternRepeatIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorU, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisSDFPatternMirrorUIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorV, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisSDFPatternMirrorVIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Mirror, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisSDFPatternMirrorIgnoreAlphaGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisSDFLCDPatternIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Clamp, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisSDFLCDPatternClampIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Repeat, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisSDFLCDPatternRepeatIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorU, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisSDFLCDPatternMirrorUIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorV, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisSDFLCDPatternMirrorVIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Mirror, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisSDFLCDPatternMirrorIgnoreAlphaGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::Opacity_Pattern, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisOpacityPatternIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Clamp, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisOpacityPatternClampIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Repeat, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisOpacityPatternRepeatIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorU, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisOpacityPatternMirrorUIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorV, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisOpacityPatternMirrorVIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Mirror, NoesisPatternTextureAction::PatternIgnoreAlpha, true> FNoesisOpacityPatternMirrorIgnoreAlphaGammaCorrectionPS;

// Read the comment next to PATTERN_SRGB in FNoesisPS::ModifyCompilationEnvironment
typedef FNoesisPS<Noesis::Shader::Path_Pattern, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisPathPatternSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisPathPatternClampSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisPathPatternRepeatSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisPathPatternMirrorUSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisPathPatternMirrorVSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisPathPatternMirrorSRGBIgnoreAlphaGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisPathAAPatternSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisPathAAPatternClampSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisPathAAPatternRepeatSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisPathAAPatternMirrorUSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisPathAAPatternMirrorVSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Path_AA_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisPathAAPatternMirrorSRGBIgnoreAlphaGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::SDF_Pattern, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisSDFPatternSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisSDFPatternClampSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisSDFPatternRepeatSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisSDFPatternMirrorUSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisSDFPatternMirrorVSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisSDFPatternMirrorSRGBIgnoreAlphaGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisSDFLCDPatternSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisSDFLCDPatternClampSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisSDFLCDPatternRepeatSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisSDFLCDPatternMirrorUSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisSDFLCDPatternMirrorVSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::SDF_LCD_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisSDFLCDPatternMirrorSRGBIgnoreAlphaGammaCorrectionPS;

typedef FNoesisPS<Noesis::Shader::Opacity_Pattern, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisOpacityPatternSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Clamp, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisOpacityPatternClampSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Repeat, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisOpacityPatternRepeatSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorU, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisOpacityPatternMirrorUSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_MirrorV, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisOpacityPatternMirrorVSRGBIgnoreAlphaGammaCorrectionPS;
typedef FNoesisPS<Noesis::Shader::Opacity_Pattern_Mirror, NoesisPatternTextureAction::PatternSRGBIgnoreAlpha, true> FNoesisOpacityPatternMirrorSRGBIgnoreAlphaGammaCorrectionPS;


class FNoesisMaterialPSBase : public FMaterialShader
{
	DECLARE_INLINE_TYPE_LAYOUT(FNoesisMaterialPSBase, NonVirtual);

public:
	FNoesisMaterialPSBase(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
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

template<Noesis::Shader::Enum Effect, NoesisColorSpace ColorSpace = NoesisColorSpace::sRGB, bool GammaCorrection = false>
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
		FNoesisMaterialPSBase::ModifyCompilationEnvironment(Parameters, OutEnvironment);
		OutEnvironment.SetDefine(TEXT("EFFECT"), Effect);

		OutEnvironment.SetDefine(TEXT("LINEAR_COLOR"), ColorSpace == NoesisColorSpace::Linear);

		OutEnvironment.SetDefine(TEXT("GAMMA_CORRECTION"), GammaCorrection);
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

// The commas in the template parameter list break the IMPLEMENT_SHADER_TYPE macro, so we need typedefs.
typedef FNoesisMaterialPS<Noesis::Shader::Path_Pattern, NoesisColorSpace::Linear> FNoesisPathMaterialLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_Pattern_Clamp, NoesisColorSpace::Linear> FNoesisPathMaterialClampLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_Pattern_Repeat, NoesisColorSpace::Linear> FNoesisPathMaterialRepeatLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_Pattern_MirrorU, NoesisColorSpace::Linear> FNoesisPathMaterialMirrorULinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_Pattern_MirrorV, NoesisColorSpace::Linear> FNoesisPathMaterialMirrorVLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_Pattern_Mirror, NoesisColorSpace::Linear> FNoesisPathMaterialMirrorLinearColorPS;

typedef FNoesisMaterialPS<Noesis::Shader::Path_AA_Pattern, NoesisColorSpace::Linear> FNoesisPathAAMaterialLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_AA_Pattern_Clamp, NoesisColorSpace::Linear> FNoesisPathAAMaterialClampLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_AA_Pattern_Repeat, NoesisColorSpace::Linear> FNoesisPathAAMaterialRepeatLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_AA_Pattern_MirrorU, NoesisColorSpace::Linear> FNoesisPathAAMaterialMirrorULinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_AA_Pattern_MirrorV, NoesisColorSpace::Linear> FNoesisPathAAMaterialMirrorVLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_AA_Pattern_Mirror, NoesisColorSpace::Linear> FNoesisPathAAMaterialMirrorLinearColorPS;

typedef FNoesisMaterialPS<Noesis::Shader::SDF_Pattern, NoesisColorSpace::Linear> FNoesisSDFMaterialLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_Pattern_Clamp, NoesisColorSpace::Linear> FNoesisSDFMaterialClampLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_Pattern_Repeat, NoesisColorSpace::Linear> FNoesisSDFMaterialRepeatLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_Pattern_MirrorU, NoesisColorSpace::Linear> FNoesisSDFMaterialMirrorULinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_Pattern_MirrorV, NoesisColorSpace::Linear> FNoesisSDFMaterialMirrorVLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_Pattern_Mirror, NoesisColorSpace::Linear> FNoesisSDFMaterialMirrorLinearColorPS;

typedef FNoesisMaterialPS<Noesis::Shader::SDF_LCD_Pattern, NoesisColorSpace::Linear> FNoesisSDFLCDMaterialLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_LCD_Pattern_Clamp, NoesisColorSpace::Linear> FNoesisSDFLCDMaterialClampLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_LCD_Pattern_Repeat, NoesisColorSpace::Linear> FNoesisSDFLCDMaterialRepeatLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_LCD_Pattern_MirrorU, NoesisColorSpace::Linear> FNoesisSDFLCDMaterialMirrorULinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_LCD_Pattern_MirrorV, NoesisColorSpace::Linear> FNoesisSDFLCDMaterialMirrorVLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_LCD_Pattern_Mirror, NoesisColorSpace::Linear> FNoesisSDFLCDMaterialMirrorLinearColorPS;

typedef FNoesisMaterialPS<Noesis::Shader::Opacity_Pattern, NoesisColorSpace::Linear> FNoesisOpacityMaterialLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::Opacity_Pattern_Clamp, NoesisColorSpace::Linear> FNoesisOpacityMaterialClampLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::Opacity_Pattern_Repeat, NoesisColorSpace::Linear> FNoesisOpacityMaterialRepeatLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::Opacity_Pattern_MirrorU, NoesisColorSpace::Linear> FNoesisOpacityMaterialMirrorULinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::Opacity_Pattern_MirrorV, NoesisColorSpace::Linear> FNoesisOpacityMaterialMirrorVLinearColorPS;
typedef FNoesisMaterialPS<Noesis::Shader::Opacity_Pattern_Mirror, NoesisColorSpace::Linear> FNoesisOpacityMaterialMirrorLinearColorPS;

// The commas in the template parameter list break the IMPLEMENT_SHADER_TYPE macro, so we need typedefs.
typedef FNoesisMaterialPS<Noesis::Shader::Path_Pattern, NoesisColorSpace::sRGB, true> FNoesisPathMaterialGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_Pattern_Clamp, NoesisColorSpace::sRGB, true> FNoesisPathMaterialClampGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_Pattern_Repeat, NoesisColorSpace::sRGB, true> FNoesisPathMaterialRepeatGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_Pattern_MirrorU, NoesisColorSpace::sRGB, true> FNoesisPathMaterialMirrorUGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_Pattern_MirrorV, NoesisColorSpace::sRGB, true> FNoesisPathMaterialMirrorVGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_Pattern_Mirror, NoesisColorSpace::sRGB, true> FNoesisPathMaterialMirrorGammaCorrectionPS;

typedef FNoesisMaterialPS<Noesis::Shader::Path_AA_Pattern, NoesisColorSpace::sRGB, true> FNoesisPathAAMaterialGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_AA_Pattern_Clamp, NoesisColorSpace::sRGB, true> FNoesisPathAAMaterialClampGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_AA_Pattern_Repeat, NoesisColorSpace::sRGB, true> FNoesisPathAAMaterialRepeatGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_AA_Pattern_MirrorU, NoesisColorSpace::sRGB, true> FNoesisPathAAMaterialMirrorUGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_AA_Pattern_MirrorV, NoesisColorSpace::sRGB, true> FNoesisPathAAMaterialMirrorVGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::Path_AA_Pattern_Mirror, NoesisColorSpace::sRGB, true> FNoesisPathAAMaterialMirrorGammaCorrectionPS;

typedef FNoesisMaterialPS<Noesis::Shader::SDF_Pattern, NoesisColorSpace::sRGB, true> FNoesisSDFMaterialGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_Pattern_Clamp, NoesisColorSpace::sRGB, true> FNoesisSDFMaterialClampGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_Pattern_Repeat, NoesisColorSpace::sRGB, true> FNoesisSDFMaterialRepeatGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_Pattern_MirrorU, NoesisColorSpace::sRGB, true> FNoesisSDFMaterialMirrorUGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_Pattern_MirrorV, NoesisColorSpace::sRGB, true> FNoesisSDFMaterialMirrorVGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_Pattern_Mirror, NoesisColorSpace::sRGB, true> FNoesisSDFMaterialMirrorGammaCorrectionPS;

typedef FNoesisMaterialPS<Noesis::Shader::SDF_LCD_Pattern, NoesisColorSpace::sRGB, true> FNoesisSDFLCDMaterialGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_LCD_Pattern_Clamp, NoesisColorSpace::sRGB, true> FNoesisSDFLCDMaterialClampGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_LCD_Pattern_Repeat, NoesisColorSpace::sRGB, true> FNoesisSDFLCDMaterialRepeatGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_LCD_Pattern_MirrorU, NoesisColorSpace::sRGB, true> FNoesisSDFLCDMaterialMirrorUGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_LCD_Pattern_MirrorV, NoesisColorSpace::sRGB, true> FNoesisSDFLCDMaterialMirrorVGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::SDF_LCD_Pattern_Mirror, NoesisColorSpace::sRGB, true> FNoesisSDFLCDMaterialMirrorGammaCorrectionPS;

typedef FNoesisMaterialPS<Noesis::Shader::Opacity_Pattern, NoesisColorSpace::sRGB, true> FNoesisOpacityMaterialGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::Opacity_Pattern_Clamp, NoesisColorSpace::sRGB, true> FNoesisOpacityMaterialClampGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::Opacity_Pattern_Repeat, NoesisColorSpace::sRGB, true> FNoesisOpacityMaterialRepeatGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::Opacity_Pattern_MirrorU, NoesisColorSpace::sRGB, true> FNoesisOpacityMaterialMirrorUGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::Opacity_Pattern_MirrorV, NoesisColorSpace::sRGB, true> FNoesisOpacityMaterialMirrorVGammaCorrectionPS;
typedef FNoesisMaterialPS<Noesis::Shader::Opacity_Pattern_Mirror, NoesisColorSpace::sRGB, true> FNoesisOpacityMaterialMirrorGammaCorrectionPS;

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

	FNoesisCustomEffectPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FMaterialShader(Initializer)
	{
		BindForLegacyShaderParameters<FParameters>(this, Initializer.PermutationId, Initializer.ParameterMap, false);

		GammaAndAlphaValues.Bind(Initializer.ParameterMap, TEXT("gammaAndAlphaValues"));
	}

	FNoesisCustomEffectPS()
	{
	}

	static bool ShouldCompilePermutation(const FMaterialShaderPermutationParameters& Parameters)
	{
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

	static void SetParameters(FRHICommandList& RHICmdList, const TShaderRef<FNoesisCustomEffectPS>& Shader, const FSceneView& View, const FMaterialRenderProxy* Proxy, const FParameters& Parameters)
	{
		FMaterialShader* MaterialShader = Shader.GetShader();
		FRHIPixelShader* ShaderRHI = Shader.GetPixelShader();
#if UE_VERSION_OLDER_THAN(4, 27, 0)
		const FMaterial* Material = Proxy->GetMaterial(View.GetFeatureLevel());
#else
		const FMaterial* Material = &Proxy->GetIncompleteMaterialWithFallback(View.GetFeatureLevel());
#endif
		MaterialShader->SetParameters(RHICmdList, ShaderRHI, Proxy, *Material, View);
		SetShaderParameters(RHICmdList, Shader, ShaderRHI, Parameters);
	}

	LAYOUT_FIELD(FShaderParameter, GammaAndAlphaValues)
};

class FNoesisCustomEffectGammaCorrectionPS : public FNoesisCustomEffectPS
{
public:
	DECLARE_SHADER_TYPE(FNoesisCustomEffectGammaCorrectionPS, Material);

	FNoesisCustomEffectGammaCorrectionPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FNoesisCustomEffectPS(Initializer)
	{
	}

	FNoesisCustomEffectGammaCorrectionPS()
	{
	}

	static void ModifyCompilationEnvironment(const FMaterialShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FNoesisCustomEffectPS::ModifyCompilationEnvironment(Parameters, OutEnvironment);
		OutEnvironment.SetDefine(TEXT("GAMMA_CORRECTION"), true);
	}
};
