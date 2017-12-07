////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

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

template<NoesisShaderEffect Effect>
struct HasCoverage
{
	static const int32 Value = 0;
};

template<>
struct HasCoverage<EFFECT_PATH_AA>
{
	static const int32 Value = 1;
};

template<NoesisShaderEffect Effect>
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

enum NoesisShaderPaint
{
	PAINT_SOLID = 0,
	PAINT_LINEAR = 1,
	PAINT_RADIAL = 2,
	PAINT_PATTERN = 3,
	PAINT_NONE = 4,
};

template<NoesisShaderPaint Paint>
struct HasColor
{
	static const int32 Value = 0;
};

template<>
struct HasColor<PAINT_SOLID>
{
	static const int32 Value = 1;
};

template<NoesisShaderPaint Paint>
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

template<NoesisShaderEffect Effect, NoesisShaderPaint Paint>
class FNoesisVertexDeclaration : public FRenderResource
{
public:

	FVertexDeclarationRHIRef VertexDeclarationRHI;

	static const int32 HasColor = ::HasColor<Paint>::Value;
	static const int32 HasUv0 = ::HasUv0<Paint>::Value;
	static const int32 HasUv1 = ::HasUv1<Effect>::Value;
	static const int32 HasCoverage = ::HasCoverage<Effect>::Value;

	typedef FVector2D FNoesisVertexPosition;
	typedef FColor FNoesisVertexColor;
	typedef FVector2DHalf FNoesisVertexUv;
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
			Elements.Add(FVertexElement(0, Offset, VET_Half2, 2, Stride));
			Offset += sizeof(FNoesisVertexUv);
		}
		if (HasUv1)
		{
			Elements.Add(FVertexElement(0, Offset, VET_Half2, 3, Stride));
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

typedef FNoesisVertexDeclaration<EFFECT_RGBA, PAINT_SOLID> FNoesisRgbaSolidVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_MASK, PAINT_SOLID> FNoesisMaskSolidVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_PATH, PAINT_SOLID> FNoesisPathSolidVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_PATH_AA, PAINT_SOLID> FNoesisPathAaSolidVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_IMAGE_PAINT_OPACITY, PAINT_SOLID> FNoesisImagePaintOpacitySolidVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_TEXT, PAINT_SOLID> FNoesisTextSolidVertexDeclaration;

typedef FNoesisVertexDeclaration<EFFECT_RGBA, PAINT_LINEAR> FNoesisRgbaLinearVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_MASK, PAINT_LINEAR> FNoesisMaskLinearVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_PATH, PAINT_LINEAR> FNoesisPathLinearVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_PATH_AA, PAINT_LINEAR> FNoesisPathAaLinearVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_IMAGE_PAINT_OPACITY, PAINT_LINEAR> FNoesisImagePaintOpacityLinearVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_TEXT, PAINT_LINEAR> FNoesisTextLinearVertexDeclaration;

typedef FNoesisVertexDeclaration<EFFECT_RGBA, PAINT_RADIAL> FNoesisRgbaRadialVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_MASK, PAINT_RADIAL> FNoesisMaskRadialVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_PATH, PAINT_RADIAL> FNoesisPathRadialVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_PATH_AA, PAINT_RADIAL> FNoesisPathAaRadialVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_IMAGE_PAINT_OPACITY, PAINT_RADIAL> FNoesisImagePaintOpacityRadialVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_TEXT, PAINT_RADIAL> FNoesisTextRadialVertexDeclaration;

typedef FNoesisVertexDeclaration<EFFECT_RGBA, PAINT_PATTERN> FNoesisRgbaPatternVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_MASK, PAINT_PATTERN> FNoesisMaskPatternVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_PATH, PAINT_PATTERN> FNoesisPathPatternVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_PATH_AA, PAINT_PATTERN> FNoesisPathAaPatternVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_IMAGE_PAINT_OPACITY, PAINT_PATTERN> FNoesisImagePaintOpacityPatternVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_TEXT, PAINT_PATTERN> FNoesisTextPatternVertexDeclaration;

typedef FNoesisVertexDeclaration<EFFECT_RGBA, PAINT_NONE> FNoesisRgbaNoneVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_MASK, PAINT_NONE> FNoesisMaskNoneVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_PATH, PAINT_NONE> FNoesisPathNoneVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_PATH_AA, PAINT_NONE> FNoesisPathAaNoneVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_IMAGE_PAINT_OPACITY, PAINT_NONE> FNoesisImagePaintOpacityNoneVertexDeclaration;
typedef FNoesisVertexDeclaration<EFFECT_TEXT, PAINT_NONE> FNoesisTextNoneVertexDeclaration;

extern TGlobalResource<FNoesisRgbaSolidVertexDeclaration> GNoesisRgbaSolidVertexDeclaration;
extern TGlobalResource<FNoesisMaskSolidVertexDeclaration> GNoesisMaskSolidVertexDeclaration;
extern TGlobalResource<FNoesisPathSolidVertexDeclaration> GNoesisPathSolidVertexDeclaration;
extern TGlobalResource<FNoesisPathAaSolidVertexDeclaration> GNoesisPathAaSolidVertexDeclaration;
extern TGlobalResource<FNoesisImagePaintOpacitySolidVertexDeclaration> GNoesisImagePaintOpacitySolidVertexDeclaration;
extern TGlobalResource<FNoesisTextSolidVertexDeclaration> GNoesisTextSolidVertexDeclaration;

extern TGlobalResource<FNoesisRgbaLinearVertexDeclaration> GNoesisRgbaLinearVertexDeclaration;
extern TGlobalResource<FNoesisMaskLinearVertexDeclaration> GNoesisMaskLinearVertexDeclaration;
extern TGlobalResource<FNoesisPathLinearVertexDeclaration> GNoesisPathLinearVertexDeclaration;
extern TGlobalResource<FNoesisPathAaLinearVertexDeclaration> GNoesisPathAaLinearVertexDeclaration;
extern TGlobalResource<FNoesisImagePaintOpacityLinearVertexDeclaration> GNoesisImagePaintOpacityLinearVertexDeclaration;
extern TGlobalResource<FNoesisTextLinearVertexDeclaration> GNoesisTextLinearVertexDeclaration;

extern TGlobalResource<FNoesisRgbaRadialVertexDeclaration> GNoesisRgbaRadialVertexDeclaration;
extern TGlobalResource<FNoesisMaskRadialVertexDeclaration> GNoesisMaskRadialVertexDeclaration;
extern TGlobalResource<FNoesisPathRadialVertexDeclaration> GNoesisPathRadialVertexDeclaration;
extern TGlobalResource<FNoesisPathAaRadialVertexDeclaration> GNoesisPathAaRadialVertexDeclaration;
extern TGlobalResource<FNoesisImagePaintOpacityRadialVertexDeclaration> GNoesisImagePaintOpacityRadialVertexDeclaration;
extern TGlobalResource<FNoesisTextRadialVertexDeclaration> GNoesisTextRadialVertexDeclaration;

extern TGlobalResource<FNoesisRgbaPatternVertexDeclaration> GNoesisRgbaPatternVertexDeclaration;
extern TGlobalResource<FNoesisMaskPatternVertexDeclaration> GNoesisMaskPatternVertexDeclaration;
extern TGlobalResource<FNoesisPathPatternVertexDeclaration> GNoesisPathPatternVertexDeclaration;
extern TGlobalResource<FNoesisPathAaPatternVertexDeclaration> GNoesisPathAaPatternVertexDeclaration;
extern TGlobalResource<FNoesisImagePaintOpacityPatternVertexDeclaration> GNoesisImagePaintOpacityPatternVertexDeclaration;
extern TGlobalResource<FNoesisTextPatternVertexDeclaration> GNoesisTextPatternVertexDeclaration;

extern TGlobalResource<FNoesisRgbaNoneVertexDeclaration> GNoesisRgbaNoneVertexDeclaration;
extern TGlobalResource<FNoesisMaskNoneVertexDeclaration> GNoesisMaskNoneVertexDeclaration;
extern TGlobalResource<FNoesisPathNoneVertexDeclaration> GNoesisPathNoneVertexDeclaration;
extern TGlobalResource<FNoesisPathAaNoneVertexDeclaration> GNoesisPathAaNoneVertexDeclaration;
extern TGlobalResource<FNoesisImagePaintOpacityNoneVertexDeclaration> GNoesisImagePaintOpacityNoneVertexDeclaration;
extern TGlobalResource<FNoesisTextNoneVertexDeclaration> GNoesisTextNoneVertexDeclaration;

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

template<NoesisShaderEffect Effect, NoesisShaderPaint Paint>
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

	static void ModifyCompilationEnvironment(EShaderPlatform Platform, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Platform, OutEnvironment);
		OutEnvironment.SetDefine(TEXT("EFFECT"), Effect);
		OutEnvironment.SetDefine(TEXT("PAINT"), Paint);
	}
};

// The commas in the template parameter list break the IMPLEMENT_SHADER_TYPE macro, so we need typedefs.
typedef FNoesisVS<EFFECT_RGBA, PAINT_SOLID> FNoesisRgbaSolidVS;
typedef FNoesisVS<EFFECT_MASK, PAINT_SOLID> FNoesisMaskSolidVS;
typedef FNoesisVS<EFFECT_PATH, PAINT_SOLID> FNoesisPathSolidVS;
typedef FNoesisVS<EFFECT_PATH_AA, PAINT_SOLID> FNoesisPathAaSolidVS;
typedef FNoesisVS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_SOLID> FNoesisImagePaintOpacitySolidVS;
typedef FNoesisVS<EFFECT_TEXT, PAINT_SOLID> FNoesisTextSolidVS;

typedef FNoesisVS<EFFECT_RGBA, PAINT_LINEAR> FNoesisRgbaLinearVS;
typedef FNoesisVS<EFFECT_MASK, PAINT_LINEAR> FNoesisMaskLinearVS;
typedef FNoesisVS<EFFECT_PATH, PAINT_LINEAR> FNoesisPathLinearVS;
typedef FNoesisVS<EFFECT_PATH_AA, PAINT_LINEAR> FNoesisPathAaLinearVS;
typedef FNoesisVS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_LINEAR> FNoesisImagePaintOpacityLinearVS;
typedef FNoesisVS<EFFECT_TEXT, PAINT_LINEAR> FNoesisTextLinearVS;

typedef FNoesisVS<EFFECT_RGBA, PAINT_RADIAL> FNoesisRgbaRadialVS;
typedef FNoesisVS<EFFECT_MASK, PAINT_RADIAL> FNoesisMaskRadialVS;
typedef FNoesisVS<EFFECT_PATH, PAINT_RADIAL> FNoesisPathRadialVS;
typedef FNoesisVS<EFFECT_PATH_AA, PAINT_RADIAL> FNoesisPathAaRadialVS;
typedef FNoesisVS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_RADIAL> FNoesisImagePaintOpacityRadialVS;
typedef FNoesisVS<EFFECT_TEXT, PAINT_RADIAL> FNoesisTextRadialVS;

typedef FNoesisVS<EFFECT_RGBA, PAINT_PATTERN> FNoesisRgbaPatternVS;
typedef FNoesisVS<EFFECT_MASK, PAINT_PATTERN> FNoesisMaskPatternVS;
typedef FNoesisVS<EFFECT_PATH, PAINT_PATTERN> FNoesisPathPatternVS;
typedef FNoesisVS<EFFECT_PATH_AA, PAINT_PATTERN> FNoesisPathAaPatternVS;
typedef FNoesisVS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_PATTERN> FNoesisImagePaintOpacityPatternVS;
typedef FNoesisVS<EFFECT_TEXT, PAINT_PATTERN> FNoesisTextPatternVS;

typedef FNoesisVS<EFFECT_RGBA, PAINT_NONE> FNoesisRgbaNoneVS;
typedef FNoesisVS<EFFECT_MASK, PAINT_NONE> FNoesisMaskNoneVS;
typedef FNoesisVS<EFFECT_PATH, PAINT_NONE> FNoesisPathNoneVS;
typedef FNoesisVS<EFFECT_PATH_AA, PAINT_NONE> FNoesisPathAaNoneVS;
typedef FNoesisVS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_NONE> FNoesisImagePaintOpacityNoneVS;
typedef FNoesisVS<EFFECT_TEXT, PAINT_NONE> FNoesisTextNoneVS;

class FNoesisPSBase : public FGlobalShader
{
public:
	FNoesisPSBase(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
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

	FNoesisPSBase()
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

	static void ModifyCompilationEnvironment(EShaderPlatform Platform, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Platform, OutEnvironment);
		OutEnvironment.SetDefine(TEXT("EFFECT"), Effect);
		OutEnvironment.SetDefine(TEXT("PAINT"), Paint);
	}
};

// The commas in the template parameter list break the IMPLEMENT_SHADER_TYPE macro, so we need typedefs.
typedef FNoesisPS<EFFECT_RGBA, PAINT_SOLID> FNoesisRgbaSolidPS;
typedef FNoesisPS<EFFECT_MASK, PAINT_SOLID> FNoesisMaskSolidPS;
typedef FNoesisPS<EFFECT_PATH, PAINT_SOLID> FNoesisPathSolidPS;
typedef FNoesisPS<EFFECT_PATH_AA, PAINT_SOLID> FNoesisPathAaSolidPS;
typedef FNoesisPS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_SOLID> FNoesisImagePaintOpacitySolidPS;
typedef FNoesisPS<EFFECT_TEXT, PAINT_SOLID> FNoesisTextSolidPS;

typedef FNoesisPS<EFFECT_RGBA, PAINT_LINEAR> FNoesisRgbaLinearPS;
typedef FNoesisPS<EFFECT_MASK, PAINT_LINEAR> FNoesisMaskLinearPS;
typedef FNoesisPS<EFFECT_PATH, PAINT_LINEAR> FNoesisPathLinearPS;
typedef FNoesisPS<EFFECT_PATH_AA, PAINT_LINEAR> FNoesisPathAaLinearPS;
typedef FNoesisPS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_LINEAR> FNoesisImagePaintOpacityLinearPS;
typedef FNoesisPS<EFFECT_TEXT, PAINT_LINEAR> FNoesisTextLinearPS;

typedef FNoesisPS<EFFECT_RGBA, PAINT_RADIAL> FNoesisRgbaRadialPS;
typedef FNoesisPS<EFFECT_MASK, PAINT_RADIAL> FNoesisMaskRadialPS;
typedef FNoesisPS<EFFECT_PATH, PAINT_RADIAL> FNoesisPathRadialPS;
typedef FNoesisPS<EFFECT_PATH_AA, PAINT_RADIAL> FNoesisPathAaRadialPS;
typedef FNoesisPS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_RADIAL> FNoesisImagePaintOpacityRadialPS;
typedef FNoesisPS<EFFECT_TEXT, PAINT_RADIAL> FNoesisTextRadialPS;

typedef FNoesisPS<EFFECT_RGBA, PAINT_PATTERN> FNoesisRgbaPatternPS;
typedef FNoesisPS<EFFECT_MASK, PAINT_PATTERN> FNoesisMaskPatternPS;
typedef FNoesisPS<EFFECT_PATH, PAINT_PATTERN> FNoesisPathPatternPS;
typedef FNoesisPS<EFFECT_PATH_AA, PAINT_PATTERN> FNoesisPathAaPatternPS;
typedef FNoesisPS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_PATTERN> FNoesisImagePaintOpacityPatternPS;
typedef FNoesisPS<EFFECT_TEXT, PAINT_PATTERN> FNoesisTextPatternPS;

typedef FNoesisPS<EFFECT_RGBA, PAINT_NONE> FNoesisRgbaNonePS;
typedef FNoesisPS<EFFECT_MASK, PAINT_NONE> FNoesisMaskNonePS;
typedef FNoesisPS<EFFECT_PATH, PAINT_NONE> FNoesisPathNonePS;
typedef FNoesisPS<EFFECT_PATH_AA, PAINT_NONE> FNoesisPathAaNonePS;
typedef FNoesisPS<EFFECT_IMAGE_PAINT_OPACITY, PAINT_NONE> FNoesisImagePaintOpacityNonePS;
typedef FNoesisPS<EFFECT_TEXT, PAINT_NONE> FNoesisTextNonePS;
