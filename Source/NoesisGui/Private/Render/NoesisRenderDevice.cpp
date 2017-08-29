////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisRenderDevice.h"

// RHI includes
#include "RHIStaticStates.h"
#include "PipelineStateCache.h"

// NoesisGui includes
#include "Render/NoesisShaders.h"

class FNoesisTexture : public Noesis::Render::Texture
{
public:

	// Texture interface
	virtual NsSize GetWidth() const override
	{
		return (NsSize)ShaderResourceTexture->GetSizeX();
	}

	virtual NsSize GetHeight() const override
	{
		return (NsSize)ShaderResourceTexture->GetSizeY();
	}

	virtual Noesis::Render::TextureFormat::Enum GetFormat() const override
	{
		EPixelFormat PixelFormat = ShaderResourceTexture->GetFormat();
		check(PixelFormat == PF_B8G8R8A8 || PixelFormat == PF_B8G8R8A8 || PixelFormat == PF_G8 || PixelFormat == PF_DXT1 || PixelFormat == PF_DXT3 || PixelFormat == PF_DXT5);
		return Format;
	}

	virtual NsBool HasMipMaps() const override
	{
		return (NsBool)(ShaderResourceTexture->GetNumMips() > 1);
	}

	virtual NsBool IsInverted() const override
	{
		return (NsBool)false;
	}
	// End of Texture interface

	FTexture2DRHIRef ShaderResourceTexture;
	Noesis::Render::TextureFormat::Enum Format;
};

class FNoesisRenderTarget : public Noesis::Render::RenderTarget
{
public:

	// RenderTarget interface
	virtual Noesis::Render::Texture* GetTexture() override
	{
		return Texture.GetPtr();
	}
	// End of RenderTarget interface

	Noesis::Ptr<FNoesisTexture> Texture;
	FTexture2DRHIRef ColorTarget;
	FTexture2DRHIRef DepthStencilTarget;
};

FNoesisRenderDevice::FNoesisRenderDevice()
	: VertexBufferOffset(0), IndexBufferOffset(0), CurrentRenderTarget(0)
{
	FRHIResourceCreateInfo CreateInfo;
	DynamicVertexBuffer = GDynamicRHI->RHICreateVertexBuffer(VertexBufferSize, BUF_Dynamic, CreateInfo);
	DynamicIndexBuffer = GDynamicRHI->RHICreateIndexBuffer(sizeof(int16), IndexBufferSize, BUF_Dynamic, CreateInfo);

	const auto FeatureLevel = GMaxRHIFeatureLevel;
	auto ShaderMap = GetGlobalShaderMap(FeatureLevel);

	FMemory::Memzero(VertexDeclarations);
	FMemory::Memzero(VertexStrides);
	FMemory::Memzero(VertexShaders);
	FMemory::Memzero(PixelShaders);

	VertexDeclarations[0] = GNoesisRgbaNoneVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[0] = FNoesisRgbaNoneVertexDeclaration::Stride;
	VertexShaders[0] = (FNoesisVSBase*)ShaderMap->GetShader<FNoesisRgbaNoneVS>();
	PixelShaders[0] = (FNoesisPSBase*)ShaderMap->GetShader<FNoesisRgbaNonePS>();

	VertexDeclarations[16] = GNoesisMaskNoneVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[16] = FNoesisMaskNoneVertexDeclaration::Stride;
	VertexShaders[16] = (FNoesisVSBase*)ShaderMap->GetShader<FNoesisMaskNoneVS>();
	PixelShaders[16] = (FNoesisPSBase*)ShaderMap->GetShader<FNoesisMaskNonePS>();

	VertexDeclarations[32] = GNoesisPathSolidVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[32] = FNoesisPathSolidVertexDeclaration::Stride;
	VertexShaders[32] = (FNoesisVSBase*)ShaderMap->GetShader<FNoesisPathSolidVS>();
	PixelShaders[32] = (FNoesisPSBase*)ShaderMap->GetShader<FNoesisPathSolidPS>();

	VertexDeclarations[33] = GNoesisPathLinearVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[33] = FNoesisPathLinearVertexDeclaration::Stride;
	VertexShaders[33] = (FNoesisVSBase*)ShaderMap->GetShader<FNoesisPathLinearVS>();
	PixelShaders[33] = (FNoesisPSBase*)ShaderMap->GetShader<FNoesisPathLinearPS>();

	VertexDeclarations[34] = GNoesisPathRadialVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[34] = FNoesisPathRadialVertexDeclaration::Stride;
	VertexShaders[34] = (FNoesisVSBase*)ShaderMap->GetShader<FNoesisPathRadialVS>();
	PixelShaders[34] = (FNoesisPSBase*)ShaderMap->GetShader<FNoesisPathRadialPS>();

	VertexDeclarations[35] = GNoesisPathPatternVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[35] = FNoesisPathPatternVertexDeclaration::Stride;
	VertexShaders[35] = (FNoesisVSBase*)ShaderMap->GetShader<FNoesisPathPatternVS>();
	PixelShaders[35] = (FNoesisPSBase*)ShaderMap->GetShader<FNoesisPathPatternPS>();

	VertexDeclarations[48] = GNoesisPathAaSolidVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[48] = FNoesisPathAaSolidVertexDeclaration::Stride;
	VertexShaders[48] = (FNoesisVSBase*)ShaderMap->GetShader<FNoesisPathAaSolidVS>();
	PixelShaders[48] = (FNoesisPSBase*)ShaderMap->GetShader<FNoesisPathAaSolidPS>();

	VertexDeclarations[49] = GNoesisPathAaLinearVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[49] = FNoesisPathAaLinearVertexDeclaration::Stride;
	VertexShaders[49] = (FNoesisVSBase*)ShaderMap->GetShader<FNoesisPathAaLinearVS>();
	PixelShaders[49] = (FNoesisPSBase*)ShaderMap->GetShader<FNoesisPathAaLinearPS>();

	VertexDeclarations[50] = GNoesisPathAaRadialVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[50] = FNoesisPathAaRadialVertexDeclaration::Stride;
	VertexShaders[50] = (FNoesisVSBase*)ShaderMap->GetShader<FNoesisPathAaRadialVS>();
	PixelShaders[50] = (FNoesisPSBase*)ShaderMap->GetShader<FNoesisPathAaRadialPS>();

	VertexDeclarations[51] = GNoesisPathAaPatternVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[51] = FNoesisPathAaPatternVertexDeclaration::Stride;
	VertexShaders[51] = (FNoesisVSBase*)ShaderMap->GetShader<FNoesisPathAaPatternVS>();
	PixelShaders[51] = (FNoesisPSBase*)ShaderMap->GetShader<FNoesisPathAaPatternPS>();

	VertexDeclarations[64] = GNoesisImagePaintOpacitySolidVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[64] = FNoesisImagePaintOpacitySolidVertexDeclaration::Stride;
	VertexShaders[64] = (FNoesisVSBase*)ShaderMap->GetShader<FNoesisImagePaintOpacitySolidVS>();
	PixelShaders[64] = (FNoesisPSBase*)ShaderMap->GetShader<FNoesisImagePaintOpacitySolidPS>();

	VertexDeclarations[65] = GNoesisImagePaintOpacityLinearVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[65] = FNoesisImagePaintOpacityLinearVertexDeclaration::Stride;
	VertexShaders[65] = (FNoesisVSBase*)ShaderMap->GetShader<FNoesisImagePaintOpacityLinearVS>();
	PixelShaders[65] = (FNoesisPSBase*)ShaderMap->GetShader<FNoesisImagePaintOpacityLinearPS>();

	VertexDeclarations[66] = GNoesisImagePaintOpacityRadialVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[66] = FNoesisImagePaintOpacityRadialVertexDeclaration::Stride;
	VertexShaders[66] = (FNoesisVSBase*)ShaderMap->GetShader<FNoesisImagePaintOpacityRadialVS>();
	PixelShaders[66] = (FNoesisPSBase*)ShaderMap->GetShader<FNoesisImagePaintOpacityRadialPS>();

	VertexDeclarations[67] = GNoesisImagePaintOpacityPatternVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[67] = FNoesisImagePaintOpacityPatternVertexDeclaration::Stride;
	VertexShaders[67] = (FNoesisVSBase*)ShaderMap->GetShader<FNoesisImagePaintOpacityPatternVS>();
	PixelShaders[67] = (FNoesisPSBase*)ShaderMap->GetShader<FNoesisImagePaintOpacityPatternPS>();

	VertexDeclarations[80] = GNoesisTextSolidVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[80] = FNoesisTextSolidVertexDeclaration::Stride;
	VertexShaders[80] = (FNoesisVSBase*)ShaderMap->GetShader<FNoesisTextSolidVS>();
	PixelShaders[80] = (FNoesisPSBase*)ShaderMap->GetShader<FNoesisTextSolidPS>();

	VertexDeclarations[81] = GNoesisTextLinearVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[81] = FNoesisTextLinearVertexDeclaration::Stride;
	VertexShaders[81] = (FNoesisVSBase*)ShaderMap->GetShader<FNoesisTextLinearVS>();
	PixelShaders[81] = (FNoesisPSBase*)ShaderMap->GetShader<FNoesisTextLinearPS>();

	VertexDeclarations[82] = GNoesisTextRadialVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[82] = FNoesisTextRadialVertexDeclaration::Stride;
	VertexShaders[82] = (FNoesisVSBase*)ShaderMap->GetShader<FNoesisTextRadialVS>();
	PixelShaders[82] = (FNoesisPSBase*)ShaderMap->GetShader<FNoesisTextRadialPS>();

	VertexDeclarations[83] = GNoesisTextPatternVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[83] = FNoesisTextPatternVertexDeclaration::Stride;
	VertexShaders[83] = (FNoesisVSBase*)ShaderMap->GetShader<FNoesisTextPatternVS>();
	PixelShaders[83] = (FNoesisPSBase*)ShaderMap->GetShader<FNoesisTextPatternPS>();
}

FNoesisRenderDevice::~FNoesisRenderDevice()
{
}

Noesis::Ptr<Noesis::Render::Texture> FNoesisRenderDevice::CreateTexture(UTexture2D* InTexture)
{
	FNoesisTexture* Texture = new FNoesisTexture();
	Texture->ShaderResourceTexture = ((FTexture2DResource*)InTexture->Resource)->GetTexture2DRHI();
	switch (Texture->ShaderResourceTexture->GetFormat())
	{
	case PF_B8G8R8A8:
		Texture->Format = Noesis::Render::TextureFormat::BGRA8;
		break;
	case PF_G8:
		Texture->Format = Noesis::Render::TextureFormat::R8;
		break;
	case PF_DXT1:
		Texture->Format = Noesis::Render::TextureFormat::BC1;
		break;
	case PF_DXT3:
		Texture->Format = Noesis::Render::TextureFormat::BC2;
		break;
	case PF_DXT5:
		Texture->Format = Noesis::Render::TextureFormat::BC3;
		break;
	}

	return Noesis::Ptr<Noesis::Render::Texture>(*Texture);
}

const Noesis::Render::DeviceCaps& FNoesisRenderDevice::GetCaps() const
{
	static Noesis::Render::DeviceCaps Caps = { 0.f, VertexBufferSize, IndexBufferSize, true, false, { true, true, true, true, true, true } };
	return Caps;
}

Noesis::Ptr<Noesis::Render::RenderTarget> FNoesisRenderDevice::CreateRenderTarget(const NsChar* Label, NsSize Width, NsSize Height, NsSize SampleCount)
{
	uint32 SizeX = (uint32)Width;
	uint32 SizeY = (uint32)Height;
	uint8 Format = (uint8)PF_B8G8R8A8;
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
	FTexture2DRHIRef DepthStencilTarget = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, NumSamples, TargetableTextureFlags, CreateInfo);

	FNoesisRenderTarget* RenderTarget = new FNoesisRenderTarget();
	RenderTarget->Texture = *new FNoesisTexture();
	RenderTarget->ColorTarget = ColorTarget;
	RenderTarget->Texture->ShaderResourceTexture = ShaderResourceTexture;
	RenderTarget->Texture->Format = Noesis::Render::TextureFormat::BGRA8;
	RenderTarget->DepthStencilTarget = DepthStencilTarget;

	FName TextureName = FName(Label);
	ColorTarget->SetName(TextureName);
	ShaderResourceTexture->SetName(TextureName);
	DepthStencilTarget->SetName(TextureName);

	return Noesis::Ptr<Noesis::Render::RenderTarget>(*RenderTarget);
}

Noesis::Ptr<Noesis::Render::RenderTarget> FNoesisRenderDevice::CloneRenderTarget(const NsChar* Label, Noesis::Render::RenderTarget* InSharedRenderTarget)
{
	FNoesisRenderTarget* SharedRenderTarget = (FNoesisRenderTarget*)InSharedRenderTarget;
	FNoesisRenderTarget* RenderTarget = new FNoesisRenderTarget();
	RenderTarget->Texture = *new FNoesisTexture();
	RenderTarget->ColorTarget = SharedRenderTarget->ColorTarget;
	RenderTarget->Texture->ShaderResourceTexture = SharedRenderTarget->Texture->ShaderResourceTexture;
	RenderTarget->Texture->Format = SharedRenderTarget->Texture->Format;
	RenderTarget->DepthStencilTarget = SharedRenderTarget->DepthStencilTarget;

	return Noesis::Ptr<Noesis::Render::RenderTarget>(*RenderTarget);
}

Noesis::Ptr<Noesis::Render::Texture> FNoesisRenderDevice::CreateTexture(const NsChar* Label, NsSize Width, NsSize Height, NsSize NumLevels, Noesis::Render::TextureFormat::Enum TextureFormat)
{
	uint32 SizeX = (uint32)Width;
	uint32 SizeY = (uint32)Height;
	EPixelFormat Formats[Noesis::Render::TextureFormat::Count] = { PF_B8G8R8A8, PF_B8G8R8A8, PF_G8, PF_DXT1, PF_DXT3, PF_DXT5 };
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

	return Noesis::Ptr<Noesis::Render::Texture>(*Texture);
}

void FNoesisRenderDevice::UpdateTexture(Noesis::Render::Texture* InTexture, NsSize Level, NsSize X, NsSize Y, NsSize Width, NsSize Height, const void* Data)
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
	uint32 SourcePitch = (uint32)Width * ((Texture->ShaderResourceTexture->GetFormat() == PF_B8G8R8A8) ? 4 : 1);
	const uint8* SourceData = (const uint8*)Data;

	GDynamicRHI->RHIUpdateTexture2D(Texture->ShaderResourceTexture, MipIndex, UpdateRegion, SourcePitch, SourceData);
}

void FNoesisRenderDevice::BeginRender(NsBool Offscreen)
{
}

void FNoesisRenderDevice::SetRenderTarget(Noesis::Render::RenderTarget* Surface)
{
	if (RHICmdList)
	{
		check(Surface);
		FNoesisRenderTarget* RenderTarget = (FNoesisRenderTarget*)Surface;
		FRHIRenderTargetView ColorTarget(RenderTarget->ColorTarget, ERenderTargetLoadAction::EClear);
		FRHIDepthRenderTargetView DepthStencilTarget(RenderTarget->DepthStencilTarget, ERenderTargetLoadAction::ENoAction, ERenderTargetStoreAction::ENoAction, ERenderTargetLoadAction::EClear, ERenderTargetStoreAction::ENoAction);
		FRHISetRenderTargetsInfo RenderTargetsInfo(1, &ColorTarget, DepthStencilTarget);
		RHICmdList->SetRenderTargetsAndClear(RenderTargetsInfo);
		RHICmdList->SetViewport(0, 0, 0.0f, RenderTarget->ColorTarget->GetSizeX(), RenderTarget->ColorTarget->GetSizeY(), 1.0f);
		CurrentRenderTarget = RenderTarget;
	}
}

void FNoesisRenderDevice::BeginTile(const Noesis::Render::Tile& Tile, NsSize SurfaceWidth, NsSize SurfaceHeight)
{
	if (RHICmdList)
	{
		check(SurfaceHeight == CurrentRenderTarget->Texture->ShaderResourceTexture->GetSizeY());
		uint32 ScissorMinX = Tile.x;
		uint32 ScissorMinY = SurfaceHeight - (Tile.y + Tile.height);
		uint32 ScissorMaxX = Tile.x + Tile.width;
		uint32 ScissorMaxY = SurfaceHeight - Tile.y;
		RHICmdList->SetScissorRect(true, ScissorMinX, ScissorMinY, ScissorMaxX, ScissorMaxY);
	}
}

void FNoesisRenderDevice::EndTile()
{
	RHICmdList->SetScissorRect(false, 0, 0, 0, 0);
}

void FNoesisRenderDevice::ResolveRenderTarget(Noesis::Render::RenderTarget* Surface, const Noesis::Render::Tile* Tiles, NsSize NumTiles)
{
	for (uint32 TileIndex = 0; TileIndex != (uint32)NumTiles; ++TileIndex)
	{
		const Noesis::Render::Tile& Tile = Tiles[TileIndex];

		uint32 ResolveMinX = Tile.x;
		uint32 ResolveMinY = CurrentRenderTarget->Texture->ShaderResourceTexture->GetSizeY() - (Tile.y + Tile.height);
		uint32 ResolveMaxX = Tile.x + Tile.width;
		uint32 ResolveMaxY = CurrentRenderTarget->Texture->ShaderResourceTexture->GetSizeY() - Tile.y;

		bool PreserveRenderTargetContents = false;
		FResolveParams ResolveParams;
		ResolveParams.Rect.X1 = ResolveMinX;
		ResolveParams.Rect.Y1 = ResolveMinY;
		ResolveParams.Rect.X2 = ResolveMaxX;
		ResolveParams.Rect.Y2 = ResolveMaxY;
		RHICmdList->CopyToResolveTarget(CurrentRenderTarget->ColorTarget, CurrentRenderTarget->Texture->ShaderResourceTexture, PreserveRenderTargetContents, ResolveParams);
	}
}

void FNoesisRenderDevice::EndRender()
{
}

void* FNoesisRenderDevice::MapVertices(NsSize Bytes)
{
	void* Result = RHILockVertexBuffer(DynamicVertexBuffer, 0, Bytes, RLM_WriteOnly);
	return Result;
}

void FNoesisRenderDevice::UnmapVertices()
{
	RHIUnlockVertexBuffer(DynamicVertexBuffer);
}

void* FNoesisRenderDevice::MapIndices(NsSize Bytes)
{
	void* Result = RHILockIndexBuffer(DynamicIndexBuffer, 0, Bytes, RLM_WriteOnly);
	return Result;
}

void FNoesisRenderDevice::UnmapIndices()
{
	RHIUnlockIndexBuffer(DynamicIndexBuffer);
}

static FSamplerStateRHIParamRef GetSamplerState(uint32 SamplerCode)
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

void FNoesisRenderDevice::DrawBatch(const Noesis::Render::Batch& Batch)
{
	if (RHICmdList)
	{
		FGraphicsPipelineStateInitializer GraphicsPSOInit;
		RHICmdList->ApplyCachedRenderTargets(GraphicsPSOInit);

		switch (Batch.renderState.f.stencilMode)
		{
			case Noesis::Render::StencilMode::Disabled:
			{
				GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
			} break;
			case Noesis::Render::StencilMode::Equal_Keep:
			{
				GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always, true, CF_Equal>::GetRHI();
			} break;
			case Noesis::Render::StencilMode::Equal_Incr:
			{
				GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always, true, CF_Equal, SO_Keep, SO_Keep, SO_Increment>::GetRHI();
			} break;
			case Noesis::Render::StencilMode::Equal_Decr:
			{
				GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always, true, CF_Equal, SO_Keep, SO_Keep, SO_Decrement>::GetRHI();
			} break;
			default:
			{
			} break;
		}

		if (Batch.renderState.f.colorEnable)
		{
			if (Batch.renderState.f.blendMode == Noesis::Render::BlendMode::SrcOver)
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
			if (Batch.renderState.f.blendMode == Noesis::Render::BlendMode::SrcOver)
			{
				GraphicsPSOInit.BlendState = TStaticBlendState<CW_NONE, BO_Add, BF_One, BF_InverseSourceAlpha, BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI();
			}
			else
			{
				GraphicsPSOInit.BlendState = TStaticBlendState<CW_NONE>::GetRHI();
			}
		}

		GraphicsPSOInit.RasterizerState = TStaticRasterizerState<FM_Solid, CM_None>::GetRHI();

		FTextureRHIParamRef PatternTexture = 0;
		FSamplerStateRHIParamRef PatternSamplerState = 0;
		if (Batch.pattern)
		{
			FNoesisTexture* Texture = (FNoesisTexture*)(Batch.pattern);
			PatternTexture = Texture->ShaderResourceTexture;
			PatternSamplerState = GetSamplerState((uint32)*(uint8*)&Batch.patternSampler);
		}

		FTextureRHIParamRef RampsTexture = 0;
		FSamplerStateRHIParamRef RampsSamplerState = 0;
		if (Batch.ramps)
		{
			FNoesisTexture* Texture = (FNoesisTexture*)(Batch.ramps);
			RampsTexture = Texture->ShaderResourceTexture;
			RampsSamplerState = GetSamplerState((uint32)*(uint8*)&Batch.rampsSampler);
		}

		FTextureRHIParamRef ImageTexture = 0;
		FSamplerStateRHIParamRef ImageSamplerState = 0;
		if (Batch.image)
		{
			FNoesisTexture* Texture = (FNoesisTexture*)(Batch.image);
			ImageTexture = Texture->ShaderResourceTexture;
			ImageSamplerState = GetSamplerState((uint32)*(uint8*)&Batch.imageSampler);
		}

		FTextureRHIParamRef GlyphsTexture = 0;
		FSamplerStateRHIParamRef GlyphsSamplerState = 0;
		if (Batch.glyphs)
		{
			FNoesisTexture* Texture = (FNoesisTexture*)(Batch.glyphs);
			GlyphsTexture = Texture->ShaderResourceTexture;
			GlyphsSamplerState = GetSamplerState((uint32)*(uint8*)&Batch.glyphsSampler);
		}

		const auto FeatureLevel = GMaxRHIFeatureLevel;

		uint32 ShaderCode = (uint32)Batch.shader.v;

		FVertexDeclarationRHIRef& VertexDeclaration = VertexDeclarations[ShaderCode];
		uint16 VertexStride = VertexStrides[ShaderCode];
		FNoesisVSBase* VertexShader = VertexShaders[ShaderCode];
		FNoesisPSBase* PixelShader = PixelShaders[ShaderCode];
		GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = VertexDeclaration;
		GraphicsPSOInit.BoundShaderState.VertexShaderRHI = GETSAFERHISHADER_VERTEX(VertexShader);
		GraphicsPSOInit.BoundShaderState.PixelShaderRHI = GETSAFERHISHADER_PIXEL(PixelShader);
		GraphicsPSOInit.PrimitiveType = PT_TriangleList;

		SetGraphicsPipelineState(*RHICmdList, GraphicsPSOInit);

		FMatrix ProjectionMtxValue = (const FMatrix&)(*Batch.projMtx);
		VertexShader->SetParameters(*RHICmdList, ProjectionMtxValue.GetTransposed());

		float OpacityValue = Batch.opacity ? *Batch.opacity : 0.0f;
		const FVector4 RgbaValue = Batch.rgba ? (const FVector4&)(*Batch.rgba) : FVector4();
		const FVector4* RadialGradValue = (const FVector4*)Batch.radialGrad;
		PixelShader->SetParameters(*RHICmdList, OpacityValue, RgbaValue, RadialGradValue);

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

		RHICmdList->SetStencilRef(Batch.stencilRef);
		RHICmdList->SetStreamSource(0, DynamicVertexBuffer, VertexStride, Batch.vertexOffset);

		RHICmdList->DrawIndexedPrimitive(DynamicIndexBuffer, PT_TriangleList, 0, 0, VertexBufferSize, Batch.startIndex, Batch.numIndices / 3, 1);
	}
}
