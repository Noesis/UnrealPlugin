////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// RenderCore includes
#include "RenderResource.h"
#include "GlobalShader.h"
#include "ShaderParameterUtils.h"

// These have to match the defines in Noesis.usf
enum NoesisShaderEffect
{
	EFFECT_RGBA = 0,
	EFFECT_MASK = 1,
	EFFECT_PATH = 2,
	EFFECT_PATH_AA = 3,
	EFFECT_IMAGE_PAINT_OPACITY = 4,
	EFFECT_TEXT = 5
};

enum NoesisShaderPaint
{
	PAINT_SOLID = 0,
	PAINT_LINEAR = 1,
	PAINT_RADIAL = 2,
	PAINT_PATTERN = 3,
	PAINT_NONE = 4,
};

template<bool HasColor, bool HasUv0, bool HasUv1, bool HasCoverage>
class FNoesisVertexDeclaration : public FRenderResource
{
public:

	FVertexDeclarationRHIRef VertexDeclarationRHI;

	typedef FVector2D FNoesisVertexPosition;
	typedef FColor FNoesisVertexColor;
	typedef FVector2D FNoesisVertexUv;
	typedef float FNoesisVertexCoverage;

	static const uint16 Stride = sizeof(FNoesisVertexPosition) + (HasColor ? sizeof(FNoesisVertexColor) : 0) + (HasUv0 ? sizeof(FNoesisVertexUv) : 0) + (HasUv1 ? sizeof(FNoesisVertexUv) : 0) + (HasCoverage ? sizeof(FNoesisVertexCoverage) : 0);

	virtual ~FNoesisVertexDeclaration()
	{
	}

	virtual void InitRHI() override
	{
		FVertexDeclarationElementList Elements;
		uint8 Offset = 0;
		Elements.Add(FVertexElement(0, Offset, VET_Float2, 0, Stride));
		Offset += sizeof(FNoesisVertexPosition);
		if (HasColor)
		{
			Elements.Add(FVertexElement(0, Offset, VET_Color, 1, Stride));
			Offset += sizeof(FNoesisVertexColor);
		}
		if (HasUv0)
		{
			Elements.Add(FVertexElement(0, Offset, VET_Float2, 2, Stride));
			Offset += sizeof(FNoesisVertexUv);
		}
		if (HasUv1)
		{
			Elements.Add(FVertexElement(0, Offset, VET_Float2, 3, Stride));
			Offset += sizeof(FNoesisVertexUv);
		}
		if (HasCoverage)
		{
			Elements.Add(FVertexElement(0, Offset, VET_Float1, 4, Stride));
			Offset += sizeof(FNoesisVertexCoverage);
		}
		check(Offset == Stride);
		VertexDeclarationRHI = RHICreateVertexDeclaration(Elements);
	}

	virtual void ReleaseRHI() override
	{
		VertexDeclarationRHI.SafeRelease();
	}
};

typedef FNoesisVertexDeclaration<false, false, false, false> FNoesisPosVertexDeclaration;
typedef FNoesisVertexDeclaration<true, false, false, false> FNoesisPosColorVertexDeclaration;
typedef FNoesisVertexDeclaration<false, true, false, false> FNoesisPosTex0VertexDeclaration;
typedef FNoesisVertexDeclaration<true, false, false, true> FNoesisPosColorCoverageVertexDeclaration;
typedef FNoesisVertexDeclaration<false, true, false, true> FNoesisPosTex0CoverageVertexDeclaration;
typedef FNoesisVertexDeclaration<true, false, true, false> FNoesisPosColorTex1VertexDeclaration;
typedef FNoesisVertexDeclaration<false, true, true, false> FNoesisPosTex0Tex1VertexDeclaration;

extern TGlobalResource<FNoesisPosVertexDeclaration> GNoesisPosVertexDeclaration;
extern TGlobalResource<FNoesisPosColorVertexDeclaration> GNoesisPosColorVertexDeclaration;
extern TGlobalResource<FNoesisPosTex0VertexDeclaration> GNoesisPosTex0VertexDeclaration;
extern TGlobalResource<FNoesisPosColorCoverageVertexDeclaration> GNoesisPosColorCoverageVertexDeclaration;
extern TGlobalResource<FNoesisPosTex0CoverageVertexDeclaration> GNoesisPosTex0CoverageVertexDeclaration;
extern TGlobalResource<FNoesisPosColorTex1VertexDeclaration> GNoesisPosColorTex1VertexDeclaration;
extern TGlobalResource<FNoesisPosTex0Tex1VertexDeclaration> GNoesisPosTex0Tex1VertexDeclaration;

class FNoesisVSBase : public FGlobalShader
{
public:
	FNoesisVSBase(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FGlobalShader(Initializer)
	{
		ProjectionMtx.Bind(Initializer.ParameterMap, TEXT("projectionMtx"));
	}

	FNoesisVSBase()
	{
	}

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters) { return true; }

	virtual bool Serialize(FArchive& Ar) override
	{
		bool bShaderHasOutdatedParameters = FGlobalShader::Serialize(Ar);
		Ar << ProjectionMtx;
		return bShaderHasOutdatedParameters || true;
	}

	void SetParameters(FRHICommandList& RHICmdList, const FMatrix& ProjectionMtxValue)
	{
		const FVertexShaderRHIParamRef ShaderRHI = GetVertexShader();

		SetShaderValue(RHICmdList, ShaderRHI, ProjectionMtx, ProjectionMtxValue);
	}

	FShaderParameter ProjectionMtx;
};

template<bool HasColor, bool HasUv0, bool HasUv1, bool HasCoverage>
class FNoesisVS : public FNoesisVSBase
{
	DECLARE_SHADER_TYPE(FNoesisVS, Global);

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
		OutEnvironment.SetDefine(TEXT("HAS_UV0"), HasUv0);
		OutEnvironment.SetDefine(TEXT("HAS_UV1"), HasUv1);
		OutEnvironment.SetDefine(TEXT("HAS_COVERAGE"), HasCoverage);
	}
};

// The commas in the template parameter list break the IMPLEMENT_SHADER_TYPE macro, so we need typedefs.
typedef FNoesisVS<false, false, false, false> FNoesisPosVS;
typedef FNoesisVS<true, false, false, false> FNoesisPosColorVS;
typedef FNoesisVS<false, true, false, false> FNoesisPosTex0VS;
typedef FNoesisVS<true, false, false, true> FNoesisPosColorCoverageVS;
typedef FNoesisVS<false, true, false, true> FNoesisPosTex0CoverageVS;
typedef FNoesisVS<true, false, true, false> FNoesisPosColorTex1VS;
typedef FNoesisVS<false, true, true, false> FNoesisPosTex0Tex1VS;

class FNoesisPSBase : public FGlobalShader
{
public:
	FNoesisPSBase(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FGlobalShader(Initializer)
	{
		Rgba.Bind(Initializer.ParameterMap, TEXT("rgba"));
		RadialGrad.Bind(Initializer.ParameterMap, TEXT("radialGrad"));
		Opacity.Bind(Initializer.ParameterMap, TEXT("opacity"));
		PatternTexture.Bind(Initializer.ParameterMap, TEXT("patternTex"));
		PatternSampler.Bind(Initializer.ParameterMap, TEXT("patternSampler"));
		RampsTexture.Bind(Initializer.ParameterMap, TEXT("rampsTex"));
		RampsSampler.Bind(Initializer.ParameterMap, TEXT("rampsSampler"));
		ImageTexture.Bind(Initializer.ParameterMap, TEXT("imageTex"));
		ImageSampler.Bind(Initializer.ParameterMap, TEXT("imageSampler"));
		GlyphsTexture.Bind(Initializer.ParameterMap, TEXT("glyphsTex"));
		GlyphsSampler.Bind(Initializer.ParameterMap, TEXT("glyphsSampler"));
	}

	FNoesisPSBase()
	{
	}

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters) { return true; }

	virtual bool Serialize(FArchive& Ar) override
	{
		bool bShaderHasOutdatedParameters = FGlobalShader::Serialize(Ar);
		Ar << Rgba;
		Ar << RadialGrad;
		Ar << Opacity;
		Ar << PatternTexture;
		Ar << PatternSampler;
		Ar << RampsTexture;
		Ar << RampsSampler;
		Ar << ImageTexture;
		Ar << ImageSampler;
		Ar << GlyphsTexture;
		Ar << GlyphsSampler;
		return bShaderHasOutdatedParameters || true;
	}

	void SetParameters(FRHICommandList& RHICmdList, const FVector4* RgbaValue, const FVector4 (*RadialGradValue)[2], const float* OpacityValue)
	{
		const FPixelShaderRHIParamRef ShaderRHI = GetPixelShader();

		if (RgbaValue)
		{
			check(Rgba.IsBound());
			SetShaderValue(RHICmdList, ShaderRHI, Rgba, *RgbaValue);
		}

		if (RadialGradValue)
		{
			check(RadialGrad.IsBound());
			SetShaderValueArray(RHICmdList, ShaderRHI, RadialGrad, *RadialGradValue, 2);
		}

		if (OpacityValue)
		{
			check(Opacity.IsBound());
			SetShaderValue(RHICmdList, ShaderRHI, Opacity, *OpacityValue);
		}
	}

	void SetPatternTexture(FRHICommandList& RHICmdList, FTextureRHIParamRef PatternTextureResource, FSamplerStateRHIParamRef PatternSamplerResource)
	{
		const FPixelShaderRHIParamRef ShaderRHI = GetPixelShader();

		SetTextureParameter(RHICmdList, ShaderRHI, PatternTexture, PatternSampler, PatternSamplerResource, PatternTextureResource);
	}

	void SetRampsTexture(FRHICommandList& RHICmdList, FTextureRHIParamRef RampsTextureResource, FSamplerStateRHIParamRef RampsSamplerResource)
	{
		const FPixelShaderRHIParamRef ShaderRHI = GetPixelShader();

		SetTextureParameter(RHICmdList, ShaderRHI, RampsTexture, RampsSampler, RampsSamplerResource, RampsTextureResource);
	}

	void SetImageTexture(FRHICommandList& RHICmdList, FTextureRHIParamRef ImageTextureResource, FSamplerStateRHIParamRef ImageSamplerResource)
	{
		const FPixelShaderRHIParamRef ShaderRHI = GetPixelShader();

		SetTextureParameter(RHICmdList, ShaderRHI, ImageTexture, ImageSampler, ImageSamplerResource, ImageTextureResource);
	}

	void SetGlyphsTexture(FRHICommandList& RHICmdList, FTextureRHIParamRef GlyphsTextureResource, FSamplerStateRHIParamRef GlyphsSamplerResource)
	{
		const FPixelShaderRHIParamRef ShaderRHI = GetPixelShader();

		SetTextureParameter(RHICmdList, ShaderRHI, GlyphsTexture, GlyphsSampler, GlyphsSamplerResource, GlyphsTextureResource);
	}

	FShaderParameter Rgba;
	FShaderParameter RadialGrad;
	FShaderParameter Opacity;
	FShaderResourceParameter PatternTexture;
	FShaderResourceParameter PatternSampler;
	FShaderResourceParameter RampsTexture;
	FShaderResourceParameter RampsSampler;
	FShaderResourceParameter ImageTexture;
	FShaderResourceParameter ImageSampler;
	FShaderResourceParameter GlyphsTexture;
	FShaderResourceParameter GlyphsSampler;
};

template<NoesisShaderEffect Effect, NoesisShaderPaint Paint>
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
		OutEnvironment.SetDefine(TEXT("PAINT"), Paint);
	}
};

// The commas in the template parameter list break the IMPLEMENT_SHADER_TYPE macro, so we need typedefs.
typedef FNoesisPS<EFFECT_RGBA, PAINT_NONE> FNoesisRgbaPS;
typedef FNoesisPS<EFFECT_MASK, PAINT_NONE> FNoesisMaskPS;

typedef FNoesisPS<EFFECT_PATH, PAINT_SOLID> FNoesisPathSolidPS;
typedef FNoesisPS<EFFECT_PATH, PAINT_LINEAR> FNoesisPathLinearPS;
typedef FNoesisPS<EFFECT_PATH, PAINT_RADIAL> FNoesisPathRadialPS;
typedef FNoesisPS<EFFECT_PATH, PAINT_PATTERN> FNoesisPathPatternPS;

typedef FNoesisPS<EFFECT_PATH_AA, PAINT_SOLID> FNoesisPathAaSolidPS;
typedef FNoesisPS<EFFECT_PATH_AA, PAINT_LINEAR> FNoesisPathAaLinearPS;
typedef FNoesisPS<EFFECT_PATH_AA, PAINT_RADIAL> FNoesisPathAaRadialPS;
typedef FNoesisPS<EFFECT_PATH_AA, PAINT_PATTERN> FNoesisPathAaPatternPS;

typedef FNoesisPS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_SOLID> FNoesisImagePaintOpacitySolidPS;
typedef FNoesisPS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_LINEAR> FNoesisImagePaintOpacityLinearPS;
typedef FNoesisPS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_RADIAL> FNoesisImagePaintOpacityRadialPS;
typedef FNoesisPS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_PATTERN> FNoesisImagePaintOpacityPatternPS;

typedef FNoesisPS<EFFECT_TEXT, PAINT_SOLID> FNoesisTextSolidPS;
typedef FNoesisPS<EFFECT_TEXT, PAINT_LINEAR> FNoesisTextLinearPS;
typedef FNoesisPS<EFFECT_TEXT, PAINT_RADIAL> FNoesisTextRadialPS;
typedef FNoesisPS<EFFECT_TEXT, PAINT_PATTERN> FNoesisTextPatternPS;
