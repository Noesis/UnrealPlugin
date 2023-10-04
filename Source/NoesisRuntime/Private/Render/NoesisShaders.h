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

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisVSConstantsRightEye, )
SHADER_PARAMETER(FMatrix44f, projectionMtx)
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
		VSConstantsBufferRightEye.Bind(Initializer.ParameterMap, FNoesisVSConstantsRightEye::StaticStructMetadata.GetShaderVariableName());
		TextureSizeBuffer.Bind(Initializer.ParameterMap, FNoesisTextureSize::StaticStructMetadata.GetShaderVariableName());
#else
		VSConstantsBuffer.Bind(Initializer.ParameterMap, FNoesisVSConstants::GetStructMetadata()->GetShaderVariableName());
		VSConstantsBufferRightEye.Bind(Initializer.ParameterMap, FNoesisVSConstantsRightEye::GetStructMetadata()->GetShaderVariableName());
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

	void SetVSConstantsRightEye(FRHICommandList& RHICmdList, const FUniformBufferRHIRef& VSConstantsRightEye)
	{
		FRHIVertexShader* ShaderRHI = RHICmdList.GetBoundVertexShader();

		check(VSConstantsBufferRightEye.IsBound());
#if UE_VERSION_OLDER_THAN(5, 3, 0)
		SetUniformBufferParameter(RHICmdList, ShaderRHI, VSConstantsBufferRightEye, VSConstantsRightEye);
#else
		FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
		BatchedParameters.SetShaderUniformBuffer(VSConstantsBufferRightEye.GetBaseIndex(), VSConstantsRightEye);
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
	LAYOUT_FIELD(FShaderUniformBufferParameter, VSConstantsBufferRightEye);
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

template<Noesis::Shader::Enum Effect>
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
		OutEnvironment.SetDefine(TEXT("PATTERN_SRGB"), false);

		// TODO: Add comment
		OutEnvironment.SetDefine(TEXT("PATTERN_LINEAR"), false);
	}
};

template<Noesis::Shader::Enum Effect>
class FNoesisPatternSRGBPS : public FNoesisPSBase
{
	DECLARE_SHADER_TYPE(FNoesisPatternSRGBPS, Global);

	FNoesisPatternSRGBPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FNoesisPSBase(Initializer)
	{
	}

	FNoesisPatternSRGBPS()
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

		// Read the comment next to PATTERN_SRGB in FNoesisPS::ModifyCompilationEnvironment
		OutEnvironment.SetDefine(TEXT("PATTERN_SRGB"), true);

		// Read the comment next to PATTERN_LINEAR in FNoesisPS::ModifyCompilationEnvironment
		OutEnvironment.SetDefine(TEXT("PATTERN_LINEAR"), false);
	}
};

template<Noesis::Shader::Enum Effect>
class FNoesisPatternLinearPS : public FNoesisPSBase
{
	DECLARE_SHADER_TYPE(FNoesisPatternLinearPS, Global);

	FNoesisPatternLinearPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FNoesisPSBase(Initializer)
	{
	}

	FNoesisPatternLinearPS()
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

		// Read the comment next to PATTERN_SRGB in FNoesisPS::ModifyCompilationEnvironment
		OutEnvironment.SetDefine(TEXT("PATTERN_SRGB"), false);

		// Read the comment next to PATTERN_LINEAR in FNoesisPS::ModifyCompilationEnvironment
		OutEnvironment.SetDefine(TEXT("PATTERN_LINEAR"), true);
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
typedef FNoesisPatternSRGBPS<Noesis::Shader::Path_Pattern> FNoesisPathPatternSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::Path_Pattern_Clamp> FNoesisPathPatternClampSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::Path_Pattern_Repeat> FNoesisPathPatternRepeatSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::Path_Pattern_MirrorU> FNoesisPathPatternMirrorUSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::Path_Pattern_MirrorV> FNoesisPathPatternMirrorVSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::Path_Pattern_Mirror> FNoesisPathPatternMirrorSRGBPS;

typedef FNoesisPatternSRGBPS<Noesis::Shader::Path_AA_Pattern> FNoesisPathAAPatternSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::Path_AA_Pattern_Clamp> FNoesisPathAAPatternClampSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::Path_AA_Pattern_Repeat> FNoesisPathAAPatternRepeatSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::Path_AA_Pattern_MirrorU> FNoesisPathAAPatternMirrorUSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::Path_AA_Pattern_MirrorV> FNoesisPathAAPatternMirrorVSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::Path_AA_Pattern_Mirror> FNoesisPathAAPatternMirrorSRGBPS;

typedef FNoesisPatternSRGBPS<Noesis::Shader::SDF_Pattern> FNoesisSDFPatternSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::SDF_Pattern_Clamp> FNoesisSDFPatternClampSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::SDF_Pattern_Repeat> FNoesisSDFPatternRepeatSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::SDF_Pattern_MirrorU> FNoesisSDFPatternMirrorUSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::SDF_Pattern_MirrorV> FNoesisSDFPatternMirrorVSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::SDF_Pattern_Mirror> FNoesisSDFPatternMirrorSRGBPS;

typedef FNoesisPatternSRGBPS<Noesis::Shader::SDF_LCD_Pattern> FNoesisSDFLCDPatternSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::SDF_LCD_Pattern_Clamp> FNoesisSDFLCDPatternClampSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::SDF_LCD_Pattern_Repeat> FNoesisSDFLCDPatternRepeatSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::SDF_LCD_Pattern_MirrorU> FNoesisSDFLCDPatternMirrorUSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::SDF_LCD_Pattern_MirrorV> FNoesisSDFLCDPatternMirrorVSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::SDF_LCD_Pattern_Mirror> FNoesisSDFLCDPatternMirrorSRGBPS;

typedef FNoesisPatternSRGBPS<Noesis::Shader::Opacity_Pattern> FNoesisOpacityPatternSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::Opacity_Pattern_Clamp> FNoesisOpacityPatternClampSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::Opacity_Pattern_Repeat> FNoesisOpacityPatternRepeatSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::Opacity_Pattern_MirrorU> FNoesisOpacityPatternMirrorUSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::Opacity_Pattern_MirrorV> FNoesisOpacityPatternMirrorVSRGBPS;
typedef FNoesisPatternSRGBPS<Noesis::Shader::Opacity_Pattern_Mirror> FNoesisOpacityPatternMirrorSRGBPS;

// Read the comment next to PATTERN_LINEAR in FNoesisPS::ModifyCompilationEnvironment
typedef FNoesisPatternLinearPS<Noesis::Shader::Path_Pattern> FNoesisPathPatternLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::Path_Pattern_Clamp> FNoesisPathPatternClampLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::Path_Pattern_Repeat> FNoesisPathPatternRepeatLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::Path_Pattern_MirrorU> FNoesisPathPatternMirrorULinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::Path_Pattern_MirrorV> FNoesisPathPatternMirrorVLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::Path_Pattern_Mirror> FNoesisPathPatternMirrorLinearPS;

typedef FNoesisPatternLinearPS<Noesis::Shader::Path_AA_Pattern> FNoesisPathAAPatternLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::Path_AA_Pattern_Clamp> FNoesisPathAAPatternClampLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::Path_AA_Pattern_Repeat> FNoesisPathAAPatternRepeatLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::Path_AA_Pattern_MirrorU> FNoesisPathAAPatternMirrorULinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::Path_AA_Pattern_MirrorV> FNoesisPathAAPatternMirrorVLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::Path_AA_Pattern_Mirror> FNoesisPathAAPatternMirrorLinearPS;

typedef FNoesisPatternLinearPS<Noesis::Shader::SDF_Pattern> FNoesisSDFPatternLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::SDF_Pattern_Clamp> FNoesisSDFPatternClampLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::SDF_Pattern_Repeat> FNoesisSDFPatternRepeatLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::SDF_Pattern_MirrorU> FNoesisSDFPatternMirrorULinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::SDF_Pattern_MirrorV> FNoesisSDFPatternMirrorVLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::SDF_Pattern_Mirror> FNoesisSDFPatternMirrorLinearPS;

typedef FNoesisPatternLinearPS<Noesis::Shader::SDF_LCD_Pattern> FNoesisSDFLCDPatternLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::SDF_LCD_Pattern_Clamp> FNoesisSDFLCDPatternClampLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::SDF_LCD_Pattern_Repeat> FNoesisSDFLCDPatternRepeatLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::SDF_LCD_Pattern_MirrorU> FNoesisSDFLCDPatternMirrorULinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::SDF_LCD_Pattern_MirrorV> FNoesisSDFLCDPatternMirrorVLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::SDF_LCD_Pattern_Mirror> FNoesisSDFLCDPatternMirrorLinearPS;

typedef FNoesisPatternLinearPS<Noesis::Shader::Opacity_Pattern> FNoesisOpacityPatternLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::Opacity_Pattern_Clamp> FNoesisOpacityPatternClampLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::Opacity_Pattern_Repeat> FNoesisOpacityPatternRepeatLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::Opacity_Pattern_MirrorU> FNoesisOpacityPatternMirrorULinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::Opacity_Pattern_MirrorV> FNoesisOpacityPatternMirrorVLinearPS;
typedef FNoesisPatternLinearPS<Noesis::Shader::Opacity_Pattern_Mirror> FNoesisOpacityPatternMirrorLinearPS;

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

template<Noesis::Shader::Enum Effect>
class FNoesisMaterialLinearColorPS : public FNoesisMaterialPSBase
{
	DECLARE_SHADER_TYPE(FNoesisMaterialLinearColorPS, Material);

	FNoesisMaterialLinearColorPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FNoesisMaterialPSBase(Initializer)
	{
	}

	FNoesisMaterialLinearColorPS()
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

		OutEnvironment.SetDefine(TEXT("PATTERN_LINEAR"), true);
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
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::Path_Pattern> FNoesisPathMaterialLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::Path_Pattern_Clamp> FNoesisPathMaterialClampLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::Path_Pattern_Repeat> FNoesisPathMaterialRepeatLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::Path_Pattern_MirrorU> FNoesisPathMaterialMirrorULinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::Path_Pattern_MirrorV> FNoesisPathMaterialMirrorVLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::Path_Pattern_Mirror> FNoesisPathMaterialMirrorLinearColorPS;

typedef FNoesisMaterialLinearColorPS<Noesis::Shader::Path_AA_Pattern> FNoesisPathAAMaterialLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::Path_AA_Pattern_Clamp> FNoesisPathAAMaterialClampLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::Path_AA_Pattern_Repeat> FNoesisPathAAMaterialRepeatLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::Path_AA_Pattern_MirrorU> FNoesisPathAAMaterialMirrorULinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::Path_AA_Pattern_MirrorV> FNoesisPathAAMaterialMirrorVLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::Path_AA_Pattern_Mirror> FNoesisPathAAMaterialMirrorLinearColorPS;

typedef FNoesisMaterialLinearColorPS<Noesis::Shader::SDF_Pattern> FNoesisSDFMaterialLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::SDF_Pattern_Clamp> FNoesisSDFMaterialClampLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::SDF_Pattern_Repeat> FNoesisSDFMaterialRepeatLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::SDF_Pattern_MirrorU> FNoesisSDFMaterialMirrorULinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::SDF_Pattern_MirrorV> FNoesisSDFMaterialMirrorVLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::SDF_Pattern_Mirror> FNoesisSDFMaterialMirrorLinearColorPS;

typedef FNoesisMaterialLinearColorPS<Noesis::Shader::SDF_LCD_Pattern> FNoesisSDFLCDMaterialLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::SDF_LCD_Pattern_Clamp> FNoesisSDFLCDMaterialClampLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::SDF_LCD_Pattern_Repeat> FNoesisSDFLCDMaterialRepeatLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::SDF_LCD_Pattern_MirrorU> FNoesisSDFLCDMaterialMirrorULinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::SDF_LCD_Pattern_MirrorV> FNoesisSDFLCDMaterialMirrorVLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::SDF_LCD_Pattern_Mirror> FNoesisSDFLCDMaterialMirrorLinearColorPS;

typedef FNoesisMaterialLinearColorPS<Noesis::Shader::Opacity_Pattern> FNoesisOpacityMaterialLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::Opacity_Pattern_Clamp> FNoesisOpacityMaterialClampLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::Opacity_Pattern_Repeat> FNoesisOpacityMaterialRepeatLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::Opacity_Pattern_MirrorU> FNoesisOpacityMaterialMirrorULinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::Opacity_Pattern_MirrorV> FNoesisOpacityMaterialMirrorVLinearColorPS;
typedef FNoesisMaterialLinearColorPS<Noesis::Shader::Opacity_Pattern_Mirror> FNoesisOpacityMaterialMirrorLinearColorPS;

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
#if UE_VERSION_OLDER_THAN(4, 27, 0)
		const FMaterial* Material = Proxy->GetMaterial(View.GetFeatureLevel());
#else
		const FMaterial* Material = &Proxy->GetIncompleteMaterialWithFallback(View.GetFeatureLevel());
#endif
		MaterialShader->SetParameters(RHICmdList, ShaderRHI, Proxy, *Material, View);
		SetShaderParameters(RHICmdList, Shader, ShaderRHI, Parameters);
	}
};
