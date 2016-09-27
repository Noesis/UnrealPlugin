////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Engine includes
#include "GlobalShader.h"

// ShaderCore includes
#include "ShaderParameterUtils.h"

// These have to match the defines in NoesisGui.usf
enum NoesisGuiShaderEffect
{
	EFFECT_RGBA = 0,
	EFFECT_MASK = 1,
	EFFECT_PATH = 2,
	EFFECT_PATH_AA = 3,
	EFFECT_IMAGE_PAINT_OPACITY = 4,
	EFFECT_TEXT = 5
};

template<NoesisGuiShaderEffect Effect>
struct HasCoverage
{
	static const int32 Value = 0;
};

template<>
struct HasCoverage<EFFECT_PATH_AA>
{
	static const int32 Value = 1;
};

template<NoesisGuiShaderEffect Effect>
struct HasUv1
{
	static const int32 Value = 0;
};

template<>
struct HasUv1<EFFECT_IMAGE_PAINT_OPACITY>
{
	static const int32 Value = 1;
};

template<>
struct HasUv1<EFFECT_TEXT>
{
	static const int32 Value = 1;
};

enum NoesisGuiShaderPaint
{
	PAINT_SOLID = 0,
	PAINT_LINEAR = 1,
	PAINT_RADIAL = 2,
	PAINT_PATTERN = 3,
	PAINT_NONE = 4,
};

template<NoesisGuiShaderPaint Paint>
struct HasColor
{
	static const int32 Value = 0;
};

template<>
struct HasColor<PAINT_SOLID>
{
	static const int32 Value = 1;
};

template<NoesisGuiShaderPaint Paint>
struct HasUv0
{
	static const int32 Value = 0;
};

template<>
struct HasUv0<PAINT_LINEAR>
{
	static const int32 Value = 1;
};

template<>
struct HasUv0<PAINT_RADIAL>
{
	static const int32 Value = 1;
};

template<>
struct HasUv0<PAINT_PATTERN>
{
	static const int32 Value = 1;
};

template<NoesisGuiShaderEffect Effect, NoesisGuiShaderPaint Paint>
class FNoesisGuiVertexDeclaration : public FRenderResource
{
public:

	FVertexDeclarationRHIRef VertexDeclarationRHI;

	static const int32 HasColor = HasColor<Paint>::Value;
	static const int32 HasUv0 = HasUv0<Paint>::Value;
	static const int32 HasUv1 = HasUv1<Effect>::Value;
	static const int32 HasCoverage = HasCoverage<Effect>::Value;

	typedef FVector2D FNoesisGuiVertexPosition;
	typedef FColor FNoesisGuiVertexColor;
	typedef FVector2DHalf FNoesisGuiVertexUv;
	typedef float FNoesisGuiVertexCoverage;

	static const uint16 Stride = sizeof(FNoesisGuiVertexPosition) + (HasColor ? sizeof(FNoesisGuiVertexColor) : 0) + (HasUv0 ? sizeof(FNoesisGuiVertexUv) : 0) + (HasUv1 ? sizeof(FNoesisGuiVertexUv) : 0) + (HasCoverage ? sizeof(FNoesisGuiVertexCoverage) : 0);

	virtual ~FNoesisGuiVertexDeclaration()
	{
	}

	virtual void InitRHI() override
	{
		FVertexDeclarationElementList Elements;
		uint8 Offset = 0;
		Elements.Add(FVertexElement(0, Offset, VET_Float2, 0, Stride));
		Offset += sizeof(FNoesisGuiVertexPosition);
		if (HasColor)
		{
			Elements.Add(FVertexElement(0, Offset, VET_Color, 1, Stride));
			Offset += sizeof(FNoesisGuiVertexColor);
		}
		if (HasUv0)
		{
			Elements.Add(FVertexElement(0, Offset, VET_Half2, 2, Stride));
			Offset += sizeof(FNoesisGuiVertexUv);
		}
		if (HasUv1)
		{
			Elements.Add(FVertexElement(0, Offset, VET_Half2, 3, Stride));
			Offset += sizeof(FNoesisGuiVertexUv);
		}
		if (HasCoverage)
		{
			Elements.Add(FVertexElement(0, Offset, VET_Float1, 4, Stride));
			Offset += sizeof(FNoesisGuiVertexCoverage);
		}
		check(Offset == Stride);
		VertexDeclarationRHI = RHICreateVertexDeclaration(Elements);
	}

	virtual void ReleaseRHI() override
	{
		VertexDeclarationRHI.SafeRelease();
	}
};

typedef FNoesisGuiVertexDeclaration<EFFECT_RGBA, PAINT_SOLID> FNoesisGuiRgbaSolidVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_MASK, PAINT_SOLID> FNoesisGuiMaskSolidVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_PATH, PAINT_SOLID> FNoesisGuiPathSolidVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_PATH_AA, PAINT_SOLID> FNoesisGuiPathAaSolidVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_IMAGE_PAINT_OPACITY, PAINT_SOLID> FNoesisGuiImagePaintOpacitySolidVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_TEXT, PAINT_SOLID> FNoesisGuiTextSolidVertexDeclaration;

typedef FNoesisGuiVertexDeclaration<EFFECT_RGBA, PAINT_LINEAR> FNoesisGuiRgbaLinearVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_MASK, PAINT_LINEAR> FNoesisGuiMaskLinearVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_PATH, PAINT_LINEAR> FNoesisGuiPathLinearVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_PATH_AA, PAINT_LINEAR> FNoesisGuiPathAaLinearVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_IMAGE_PAINT_OPACITY, PAINT_LINEAR> FNoesisGuiImagePaintOpacityLinearVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_TEXT, PAINT_LINEAR> FNoesisGuiTextLinearVertexDeclaration;

typedef FNoesisGuiVertexDeclaration<EFFECT_RGBA, PAINT_RADIAL> FNoesisGuiRgbaRadialVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_MASK, PAINT_RADIAL> FNoesisGuiMaskRadialVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_PATH, PAINT_RADIAL> FNoesisGuiPathRadialVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_PATH_AA, PAINT_RADIAL> FNoesisGuiPathAaRadialVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_IMAGE_PAINT_OPACITY, PAINT_RADIAL> FNoesisGuiImagePaintOpacityRadialVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_TEXT, PAINT_RADIAL> FNoesisGuiTextRadialVertexDeclaration;

typedef FNoesisGuiVertexDeclaration<EFFECT_RGBA, PAINT_PATTERN> FNoesisGuiRgbaPatternVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_MASK, PAINT_PATTERN> FNoesisGuiMaskPatternVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_PATH, PAINT_PATTERN> FNoesisGuiPathPatternVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_PATH_AA, PAINT_PATTERN> FNoesisGuiPathAaPatternVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_IMAGE_PAINT_OPACITY, PAINT_PATTERN> FNoesisGuiImagePaintOpacityPatternVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_TEXT, PAINT_PATTERN> FNoesisGuiTextPatternVertexDeclaration;

typedef FNoesisGuiVertexDeclaration<EFFECT_RGBA, PAINT_NONE> FNoesisGuiRgbaNoneVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_MASK, PAINT_NONE> FNoesisGuiMaskNoneVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_PATH, PAINT_NONE> FNoesisGuiPathNoneVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_PATH_AA, PAINT_NONE> FNoesisGuiPathAaNoneVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_IMAGE_PAINT_OPACITY, PAINT_NONE> FNoesisGuiImagePaintOpacityNoneVertexDeclaration;
typedef FNoesisGuiVertexDeclaration<EFFECT_TEXT, PAINT_NONE> FNoesisGuiTextNoneVertexDeclaration;

extern TGlobalResource<FNoesisGuiRgbaSolidVertexDeclaration> GNoesisGuiRgbaSolidVertexDeclaration;
extern TGlobalResource<FNoesisGuiMaskSolidVertexDeclaration> GNoesisGuiMaskSolidVertexDeclaration;
extern TGlobalResource<FNoesisGuiPathSolidVertexDeclaration> GNoesisGuiPathSolidVertexDeclaration;
extern TGlobalResource<FNoesisGuiPathAaSolidVertexDeclaration> GNoesisGuiPathAaSolidVertexDeclaration;
extern TGlobalResource<FNoesisGuiImagePaintOpacitySolidVertexDeclaration> GNoesisGuiImagePaintOpacitySolidVertexDeclaration;
extern TGlobalResource<FNoesisGuiTextSolidVertexDeclaration> GNoesisGuiTextSolidVertexDeclaration;

extern TGlobalResource<FNoesisGuiRgbaLinearVertexDeclaration> GNoesisGuiRgbaLinearVertexDeclaration;
extern TGlobalResource<FNoesisGuiMaskLinearVertexDeclaration> GNoesisGuiMaskLinearVertexDeclaration;
extern TGlobalResource<FNoesisGuiPathLinearVertexDeclaration> GNoesisGuiPathLinearVertexDeclaration;
extern TGlobalResource<FNoesisGuiPathAaLinearVertexDeclaration> GNoesisGuiPathAaLinearVertexDeclaration;
extern TGlobalResource<FNoesisGuiImagePaintOpacityLinearVertexDeclaration> GNoesisGuiImagePaintOpacityLinearVertexDeclaration;
extern TGlobalResource<FNoesisGuiTextLinearVertexDeclaration> GNoesisGuiTextLinearVertexDeclaration;

extern TGlobalResource<FNoesisGuiRgbaRadialVertexDeclaration> GNoesisGuiRgbaRadialVertexDeclaration;
extern TGlobalResource<FNoesisGuiMaskRadialVertexDeclaration> GNoesisGuiMaskRadialVertexDeclaration;
extern TGlobalResource<FNoesisGuiPathRadialVertexDeclaration> GNoesisGuiPathRadialVertexDeclaration;
extern TGlobalResource<FNoesisGuiPathAaRadialVertexDeclaration> GNoesisGuiPathAaRadialVertexDeclaration;
extern TGlobalResource<FNoesisGuiImagePaintOpacityRadialVertexDeclaration> GNoesisGuiImagePaintOpacityRadialVertexDeclaration;
extern TGlobalResource<FNoesisGuiTextRadialVertexDeclaration> GNoesisGuiTextRadialVertexDeclaration;

extern TGlobalResource<FNoesisGuiRgbaPatternVertexDeclaration> GNoesisGuiRgbaPatternVertexDeclaration;
extern TGlobalResource<FNoesisGuiMaskPatternVertexDeclaration> GNoesisGuiMaskPatternVertexDeclaration;
extern TGlobalResource<FNoesisGuiPathPatternVertexDeclaration> GNoesisGuiPathPatternVertexDeclaration;
extern TGlobalResource<FNoesisGuiPathAaPatternVertexDeclaration> GNoesisGuiPathAaPatternVertexDeclaration;
extern TGlobalResource<FNoesisGuiImagePaintOpacityPatternVertexDeclaration> GNoesisGuiImagePaintOpacityPatternVertexDeclaration;
extern TGlobalResource<FNoesisGuiTextPatternVertexDeclaration> GNoesisGuiTextPatternVertexDeclaration;

extern TGlobalResource<FNoesisGuiRgbaNoneVertexDeclaration> GNoesisGuiRgbaNoneVertexDeclaration;
extern TGlobalResource<FNoesisGuiMaskNoneVertexDeclaration> GNoesisGuiMaskNoneVertexDeclaration;
extern TGlobalResource<FNoesisGuiPathNoneVertexDeclaration> GNoesisGuiPathNoneVertexDeclaration;
extern TGlobalResource<FNoesisGuiPathAaNoneVertexDeclaration> GNoesisGuiPathAaNoneVertexDeclaration;
extern TGlobalResource<FNoesisGuiImagePaintOpacityNoneVertexDeclaration> GNoesisGuiImagePaintOpacityNoneVertexDeclaration;
extern TGlobalResource<FNoesisGuiTextNoneVertexDeclaration> GNoesisGuiTextNoneVertexDeclaration;

class FNoesisGuiVSBase : public FGlobalShader
{
public:
	FNoesisGuiVSBase(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FGlobalShader(Initializer)
	{
		ProjectionMtx.Bind(Initializer.ParameterMap, TEXT("projectionMtx"));
	}

	FNoesisGuiVSBase()
	{
	}

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

template<NoesisGuiShaderEffect Effect, NoesisGuiShaderPaint Paint>
class FNoesisGuiVS : public FNoesisGuiVSBase
{
	DECLARE_SHADER_TYPE(FNoesisGuiVS, Global);

	FNoesisGuiVS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FNoesisGuiVSBase(Initializer)
	{
	}

	FNoesisGuiVS()
	{
	}

	static bool ShouldCache(EShaderPlatform Platform)
	{
		return true;
	}

	static void ModifyCompilationEnvironment(EShaderPlatform Platform, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Platform, OutEnvironment);
		OutEnvironment.SetDefine(TEXT("EFFECT"), Effect);
		OutEnvironment.SetDefine(TEXT("PAINT"), Paint);
	}
};

// The commas in the template parameter list break the IMPLEMENT_SHADER_TYPE macro, so we need typedefs.
typedef FNoesisGuiVS<EFFECT_RGBA, PAINT_SOLID> FNoesisGuiRgbaSolidVS;
typedef FNoesisGuiVS<EFFECT_MASK, PAINT_SOLID> FNoesisGuiMaskSolidVS;
typedef FNoesisGuiVS<EFFECT_PATH, PAINT_SOLID> FNoesisGuiPathSolidVS;
typedef FNoesisGuiVS<EFFECT_PATH_AA, PAINT_SOLID> FNoesisGuiPathAaSolidVS;
typedef FNoesisGuiVS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_SOLID> FNoesisGuiImagePaintOpacitySolidVS;
typedef FNoesisGuiVS<EFFECT_TEXT, PAINT_SOLID> FNoesisGuiTextSolidVS;

typedef FNoesisGuiVS<EFFECT_RGBA, PAINT_LINEAR> FNoesisGuiRgbaLinearVS;
typedef FNoesisGuiVS<EFFECT_MASK, PAINT_LINEAR> FNoesisGuiMaskLinearVS;
typedef FNoesisGuiVS<EFFECT_PATH, PAINT_LINEAR> FNoesisGuiPathLinearVS;
typedef FNoesisGuiVS<EFFECT_PATH_AA, PAINT_LINEAR> FNoesisGuiPathAaLinearVS;
typedef FNoesisGuiVS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_LINEAR> FNoesisGuiImagePaintOpacityLinearVS;
typedef FNoesisGuiVS<EFFECT_TEXT, PAINT_LINEAR> FNoesisGuiTextLinearVS;

typedef FNoesisGuiVS<EFFECT_RGBA, PAINT_RADIAL> FNoesisGuiRgbaRadialVS;
typedef FNoesisGuiVS<EFFECT_MASK, PAINT_RADIAL> FNoesisGuiMaskRadialVS;
typedef FNoesisGuiVS<EFFECT_PATH, PAINT_RADIAL> FNoesisGuiPathRadialVS;
typedef FNoesisGuiVS<EFFECT_PATH_AA, PAINT_RADIAL> FNoesisGuiPathAaRadialVS;
typedef FNoesisGuiVS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_RADIAL> FNoesisGuiImagePaintOpacityRadialVS;
typedef FNoesisGuiVS<EFFECT_TEXT, PAINT_RADIAL> FNoesisGuiTextRadialVS;

typedef FNoesisGuiVS<EFFECT_RGBA, PAINT_PATTERN> FNoesisGuiRgbaPatternVS;
typedef FNoesisGuiVS<EFFECT_MASK, PAINT_PATTERN> FNoesisGuiMaskPatternVS;
typedef FNoesisGuiVS<EFFECT_PATH, PAINT_PATTERN> FNoesisGuiPathPatternVS;
typedef FNoesisGuiVS<EFFECT_PATH_AA, PAINT_PATTERN> FNoesisGuiPathAaPatternVS;
typedef FNoesisGuiVS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_PATTERN> FNoesisGuiImagePaintOpacityPatternVS;
typedef FNoesisGuiVS<EFFECT_TEXT, PAINT_PATTERN> FNoesisGuiTextPatternVS;

typedef FNoesisGuiVS<EFFECT_RGBA, PAINT_NONE> FNoesisGuiRgbaNoneVS;
typedef FNoesisGuiVS<EFFECT_MASK, PAINT_NONE> FNoesisGuiMaskNoneVS;
typedef FNoesisGuiVS<EFFECT_PATH, PAINT_NONE> FNoesisGuiPathNoneVS;
typedef FNoesisGuiVS<EFFECT_PATH_AA, PAINT_NONE> FNoesisGuiPathAaNoneVS;
typedef FNoesisGuiVS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_NONE> FNoesisGuiImagePaintOpacityNoneVS;
typedef FNoesisGuiVS<EFFECT_TEXT, PAINT_NONE> FNoesisGuiTextNoneVS;

class FNoesisGuiPSBase : public FGlobalShader
{
public:
	FNoesisGuiPSBase(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FGlobalShader(Initializer)
	{
		Opacity.Bind(Initializer.ParameterMap, TEXT("opacity"));
		Rgba.Bind(Initializer.ParameterMap, TEXT("rgba"));
		RadialGrad.Bind(Initializer.ParameterMap, TEXT("radialGrad"));
		PatternTexture.Bind(Initializer.ParameterMap, TEXT("patternTex"));
		PatternSampler.Bind(Initializer.ParameterMap, TEXT("patternSampler"));
		RampsTexture.Bind(Initializer.ParameterMap, TEXT("rampsTex"));
		RampsSampler.Bind(Initializer.ParameterMap, TEXT("rampsSampler"));
		ImageTexture.Bind(Initializer.ParameterMap, TEXT("imageTex"));
		ImageSampler.Bind(Initializer.ParameterMap, TEXT("imageSampler"));
		GlyphsTexture.Bind(Initializer.ParameterMap, TEXT("glyphsTex"));
		GlyphsSampler.Bind(Initializer.ParameterMap, TEXT("glyphsSampler"));
	}

	FNoesisGuiPSBase()
	{
	}

	virtual bool Serialize(FArchive& Ar) override
	{
		bool bShaderHasOutdatedParameters = FGlobalShader::Serialize(Ar);
		Ar << Opacity;
		Ar << Rgba;
		Ar << RadialGrad;
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

	void SetParameters(FRHICommandList& RHICmdList, float OpacityValue, const FVector4& RgbaValue, const FVector4* RadialGradValue)
	{
		const FPixelShaderRHIParamRef ShaderRHI = GetPixelShader();

		SetShaderValue(RHICmdList, ShaderRHI, Opacity, OpacityValue);
		SetShaderValue(RHICmdList, ShaderRHI, Rgba, RgbaValue);
		SetShaderValueArray(RHICmdList, ShaderRHI, RadialGrad, RadialGradValue, 2);
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

	FShaderParameter Opacity;
	FShaderParameter Rgba;
	FShaderParameter RadialGrad;
	FShaderResourceParameter PatternTexture;
	FShaderResourceParameter PatternSampler;
	FShaderResourceParameter RampsTexture;
	FShaderResourceParameter RampsSampler;
	FShaderResourceParameter ImageTexture;
	FShaderResourceParameter ImageSampler;
	FShaderResourceParameter GlyphsTexture;
	FShaderResourceParameter GlyphsSampler;
};

template<NoesisGuiShaderEffect Effect, NoesisGuiShaderPaint Paint>
class FNoesisGuiPS : public FNoesisGuiPSBase
{
	DECLARE_SHADER_TYPE(FNoesisGuiPS, Global);

	FNoesisGuiPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FNoesisGuiPSBase(Initializer)
	{
	}

	FNoesisGuiPS()
	{
	}

	static bool ShouldCache(EShaderPlatform Platform)
	{
		return true;
	}

	static void ModifyCompilationEnvironment(EShaderPlatform Platform, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Platform, OutEnvironment);
		OutEnvironment.SetDefine(TEXT("EFFECT"), Effect);
		OutEnvironment.SetDefine(TEXT("PAINT"), Paint);
	}
};

// The commas in the template parameter list break the IMPLEMENT_SHADER_TYPE macro, so we need typedefs.
typedef FNoesisGuiPS<EFFECT_RGBA, PAINT_SOLID> FNoesisGuiRgbaSolidPS;
typedef FNoesisGuiPS<EFFECT_MASK, PAINT_SOLID> FNoesisGuiMaskSolidPS;
typedef FNoesisGuiPS<EFFECT_PATH, PAINT_SOLID> FNoesisGuiPathSolidPS;
typedef FNoesisGuiPS<EFFECT_PATH_AA, PAINT_SOLID> FNoesisGuiPathAaSolidPS;
typedef FNoesisGuiPS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_SOLID> FNoesisGuiImagePaintOpacitySolidPS;
typedef FNoesisGuiPS<EFFECT_TEXT, PAINT_SOLID> FNoesisGuiTextSolidPS;

typedef FNoesisGuiPS<EFFECT_RGBA, PAINT_LINEAR> FNoesisGuiRgbaLinearPS;
typedef FNoesisGuiPS<EFFECT_MASK, PAINT_LINEAR> FNoesisGuiMaskLinearPS;
typedef FNoesisGuiPS<EFFECT_PATH, PAINT_LINEAR> FNoesisGuiPathLinearPS;
typedef FNoesisGuiPS<EFFECT_PATH_AA, PAINT_LINEAR> FNoesisGuiPathAaLinearPS;
typedef FNoesisGuiPS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_LINEAR> FNoesisGuiImagePaintOpacityLinearPS;
typedef FNoesisGuiPS<EFFECT_TEXT, PAINT_LINEAR> FNoesisGuiTextLinearPS;

typedef FNoesisGuiPS<EFFECT_RGBA, PAINT_RADIAL> FNoesisGuiRgbaRadialPS;
typedef FNoesisGuiPS<EFFECT_MASK, PAINT_RADIAL> FNoesisGuiMaskRadialPS;
typedef FNoesisGuiPS<EFFECT_PATH, PAINT_RADIAL> FNoesisGuiPathRadialPS;
typedef FNoesisGuiPS<EFFECT_PATH_AA, PAINT_RADIAL> FNoesisGuiPathAaRadialPS;
typedef FNoesisGuiPS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_RADIAL> FNoesisGuiImagePaintOpacityRadialPS;
typedef FNoesisGuiPS<EFFECT_TEXT, PAINT_RADIAL> FNoesisGuiTextRadialPS;

typedef FNoesisGuiPS<EFFECT_RGBA, PAINT_PATTERN> FNoesisGuiRgbaPatternPS;
typedef FNoesisGuiPS<EFFECT_MASK, PAINT_PATTERN> FNoesisGuiMaskPatternPS;
typedef FNoesisGuiPS<EFFECT_PATH, PAINT_PATTERN> FNoesisGuiPathPatternPS;
typedef FNoesisGuiPS<EFFECT_PATH_AA, PAINT_PATTERN> FNoesisGuiPathAaPatternPS;
typedef FNoesisGuiPS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_PATTERN> FNoesisGuiImagePaintOpacityPatternPS;
typedef FNoesisGuiPS<EFFECT_TEXT, PAINT_PATTERN> FNoesisGuiTextPatternPS;

typedef FNoesisGuiPS<EFFECT_RGBA, PAINT_NONE> FNoesisGuiRgbaNonePS;
typedef FNoesisGuiPS<EFFECT_MASK, PAINT_NONE> FNoesisGuiMaskNonePS;
typedef FNoesisGuiPS<EFFECT_PATH, PAINT_NONE> FNoesisGuiPathNonePS;
typedef FNoesisGuiPS<EFFECT_PATH_AA, PAINT_NONE> FNoesisGuiPathAaNonePS;
typedef FNoesisGuiPS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_NONE> FNoesisGuiImagePaintOpacityNonePS;
typedef FNoesisGuiPS<EFFECT_TEXT, PAINT_NONE> FNoesisGuiTextNonePS;
