////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisGuiRenderDevice.h"

// RHI includes
#include "RHIStaticStates.h"

// NoesisGui includes
#include "Render/NoesisGuiShaders.h"

class FNoesisGuiTexture : public Noesis::Render::Texture
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
};

class FNoesisGuiRenderTarget : public Noesis::Render::RenderTarget
{
public:

	// RenderTarget interface
	virtual Noesis::Render::Texture* GetTexture() override
	{
		return NoesisGuiTexture.GetPtr();
	}
	// End of RenderTarget interface

	Noesis::Ptr<FNoesisGuiTexture> NoesisGuiTexture;
	FTexture2DRHIRef ColorTarget;
	FTexture2DRHIRef DepthStencilTarget;
};

FNoesisGuiRenderDevice::FNoesisGuiRenderDevice()
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
	FMemory::Memzero(BoundShaderStates);

	VertexDeclarations[0] = GNoesisGuiRgbaNoneVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[0] = FNoesisGuiRgbaNoneVertexDeclaration::Stride;
	VertexShaders[0] = (FNoesisGuiVSBase*)ShaderMap->GetShader<FNoesisGuiRgbaNoneVS>();
	PixelShaders[0] = (FNoesisGuiPSBase*)ShaderMap->GetShader<FNoesisGuiRgbaNonePS>();

	VertexDeclarations[16] = GNoesisGuiMaskNoneVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[16] = FNoesisGuiMaskNoneVertexDeclaration::Stride;
	VertexShaders[16] = (FNoesisGuiVSBase*)ShaderMap->GetShader<FNoesisGuiMaskNoneVS>();
	PixelShaders[16] = (FNoesisGuiPSBase*)ShaderMap->GetShader<FNoesisGuiMaskNonePS>();
	
	VertexDeclarations[32] = GNoesisGuiPathSolidVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[32] = FNoesisGuiPathSolidVertexDeclaration::Stride;
	VertexShaders[32] = (FNoesisGuiVSBase*)ShaderMap->GetShader<FNoesisGuiPathSolidVS>();
	PixelShaders[32] = (FNoesisGuiPSBase*)ShaderMap->GetShader<FNoesisGuiPathSolidPS>();

	VertexDeclarations[33] = GNoesisGuiPathLinearVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[33] = FNoesisGuiPathLinearVertexDeclaration::Stride;
	VertexShaders[33] = (FNoesisGuiVSBase*)ShaderMap->GetShader<FNoesisGuiPathLinearVS>();
	PixelShaders[33] = (FNoesisGuiPSBase*)ShaderMap->GetShader<FNoesisGuiPathLinearPS>();

	VertexDeclarations[34] = GNoesisGuiPathRadialVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[34] = FNoesisGuiPathRadialVertexDeclaration::Stride;
	VertexShaders[34] = (FNoesisGuiVSBase*)ShaderMap->GetShader<FNoesisGuiPathRadialVS>();
	PixelShaders[34] = (FNoesisGuiPSBase*)ShaderMap->GetShader<FNoesisGuiPathRadialPS>();

	VertexDeclarations[35] = GNoesisGuiPathPatternVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[35] = FNoesisGuiPathPatternVertexDeclaration::Stride;
	VertexShaders[35] = (FNoesisGuiVSBase*)ShaderMap->GetShader<FNoesisGuiPathPatternVS>();
	PixelShaders[35] = (FNoesisGuiPSBase*)ShaderMap->GetShader<FNoesisGuiPathPatternPS>();

	VertexDeclarations[48] = GNoesisGuiPathAaSolidVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[48] = FNoesisGuiPathAaSolidVertexDeclaration::Stride;
	VertexShaders[48] = (FNoesisGuiVSBase*)ShaderMap->GetShader<FNoesisGuiPathAaSolidVS>();
	PixelShaders[48] = (FNoesisGuiPSBase*)ShaderMap->GetShader<FNoesisGuiPathAaSolidPS>();

	VertexDeclarations[49] = GNoesisGuiPathAaLinearVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[49] = FNoesisGuiPathAaLinearVertexDeclaration::Stride;
	VertexShaders[49] = (FNoesisGuiVSBase*)ShaderMap->GetShader<FNoesisGuiPathAaLinearVS>();
	PixelShaders[49] = (FNoesisGuiPSBase*)ShaderMap->GetShader<FNoesisGuiPathAaLinearPS>();

	VertexDeclarations[50] = GNoesisGuiPathAaRadialVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[50] = FNoesisGuiPathAaRadialVertexDeclaration::Stride;
	VertexShaders[50] = (FNoesisGuiVSBase*)ShaderMap->GetShader<FNoesisGuiPathAaRadialVS>();
	PixelShaders[50] = (FNoesisGuiPSBase*)ShaderMap->GetShader<FNoesisGuiPathAaRadialPS>();

	VertexDeclarations[51] = GNoesisGuiPathAaPatternVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[51] = FNoesisGuiPathAaPatternVertexDeclaration::Stride;
	VertexShaders[51] = (FNoesisGuiVSBase*)ShaderMap->GetShader<FNoesisGuiPathAaPatternVS>();
	PixelShaders[51] = (FNoesisGuiPSBase*)ShaderMap->GetShader<FNoesisGuiPathAaPatternPS>();

	VertexDeclarations[64] = GNoesisGuiImagePaintOpacitySolidVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[64] = FNoesisGuiImagePaintOpacitySolidVertexDeclaration::Stride;
	VertexShaders[64] = (FNoesisGuiVSBase*)ShaderMap->GetShader<FNoesisGuiImagePaintOpacitySolidVS>();
	PixelShaders[64] = (FNoesisGuiPSBase*)ShaderMap->GetShader<FNoesisGuiImagePaintOpacitySolidPS>();

	VertexDeclarations[65] = GNoesisGuiImagePaintOpacityLinearVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[65] = FNoesisGuiImagePaintOpacityLinearVertexDeclaration::Stride;
	VertexShaders[65] = (FNoesisGuiVSBase*)ShaderMap->GetShader<FNoesisGuiImagePaintOpacityLinearVS>();
	PixelShaders[65] = (FNoesisGuiPSBase*)ShaderMap->GetShader<FNoesisGuiImagePaintOpacityLinearPS>();

	VertexDeclarations[66] = GNoesisGuiImagePaintOpacityRadialVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[66] = FNoesisGuiImagePaintOpacityRadialVertexDeclaration::Stride;
	VertexShaders[66] = (FNoesisGuiVSBase*)ShaderMap->GetShader<FNoesisGuiImagePaintOpacityRadialVS>();
	PixelShaders[66] = (FNoesisGuiPSBase*)ShaderMap->GetShader<FNoesisGuiImagePaintOpacityRadialPS>();

	VertexDeclarations[67] = GNoesisGuiImagePaintOpacityPatternVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[67] = FNoesisGuiImagePaintOpacityPatternVertexDeclaration::Stride;
	VertexShaders[67] = (FNoesisGuiVSBase*)ShaderMap->GetShader<FNoesisGuiImagePaintOpacityPatternVS>();
	PixelShaders[67] = (FNoesisGuiPSBase*)ShaderMap->GetShader<FNoesisGuiImagePaintOpacityPatternPS>();

	VertexDeclarations[80] = GNoesisGuiTextSolidVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[80] = FNoesisGuiTextSolidVertexDeclaration::Stride;
	VertexShaders[80] = (FNoesisGuiVSBase*)ShaderMap->GetShader<FNoesisGuiTextSolidVS>();
	PixelShaders[80] = (FNoesisGuiPSBase*)ShaderMap->GetShader<FNoesisGuiTextSolidPS>();

	VertexDeclarations[81] = GNoesisGuiTextLinearVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[81] = FNoesisGuiTextLinearVertexDeclaration::Stride;
	VertexShaders[81] = (FNoesisGuiVSBase*)ShaderMap->GetShader<FNoesisGuiTextLinearVS>();
	PixelShaders[81] = (FNoesisGuiPSBase*)ShaderMap->GetShader<FNoesisGuiTextLinearPS>();

	VertexDeclarations[82] = GNoesisGuiTextRadialVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[82] = FNoesisGuiTextRadialVertexDeclaration::Stride;
	VertexShaders[82] = (FNoesisGuiVSBase*)ShaderMap->GetShader<FNoesisGuiTextRadialVS>();
	PixelShaders[82] = (FNoesisGuiPSBase*)ShaderMap->GetShader<FNoesisGuiTextRadialPS>();

	VertexDeclarations[83] = GNoesisGuiTextPatternVertexDeclaration.VertexDeclarationRHI;
	VertexStrides[83] = FNoesisGuiTextPatternVertexDeclaration::Stride;
	VertexShaders[83] = (FNoesisGuiVSBase*)ShaderMap->GetShader<FNoesisGuiTextPatternVS>();
	PixelShaders[83] = (FNoesisGuiPSBase*)ShaderMap->GetShader<FNoesisGuiTextPatternPS>();
}

FNoesisGuiRenderDevice::~FNoesisGuiRenderDevice()
{
}

Noesis::Ptr<Noesis::Render::Texture> FNoesisGuiRenderDevice::CreateTexture(UTexture2D* Texture)
{
	FNoesisGuiTexture* NoesisGuiTexture = new FNoesisGuiTexture();
	NoesisGuiTexture->ShaderResourceTexture = ((FTexture2DResource*)Texture->Resource)->GetTexture2DRHI();

	return Noesis::Ptr<Noesis::Render::Texture>(*NoesisGuiTexture);
}

const Noesis::Render::DeviceCaps& FNoesisGuiRenderDevice::GetCaps() const
{
	static Noesis::Render::DeviceCaps Caps = { 0.f, VertexBufferSize, IndexBufferSize, true, 1, { true, true } };
	return Caps;
}

Noesis::Ptr<Noesis::Render::RenderTarget> FNoesisGuiRenderDevice::CreateRenderTarget(const NsChar* Label, NsSize Width, NsSize Height, NsSize SampleCount)
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

	FNoesisGuiRenderTarget* NoesisGuiRenderTarget = new FNoesisGuiRenderTarget();
	NoesisGuiRenderTarget->NoesisGuiTexture = *new FNoesisGuiTexture();
	NoesisGuiRenderTarget->ColorTarget = ColorTarget;
	NoesisGuiRenderTarget->NoesisGuiTexture->ShaderResourceTexture = ShaderResourceTexture;
	NoesisGuiRenderTarget->DepthStencilTarget = DepthStencilTarget;

	FName TextureName = FName(Label);
	ColorTarget->SetName(TextureName);
	ShaderResourceTexture->SetName(TextureName);
	DepthStencilTarget->SetName(TextureName);

	return Noesis::Ptr<Noesis::Render::RenderTarget>(*NoesisGuiRenderTarget);
}

Noesis::Ptr<Noesis::Render::RenderTarget> FNoesisGuiRenderDevice::CloneRenderTarget(const NsChar* Label, Noesis::Render::RenderTarget* SharedRenderTarget)
{
	FNoesisGuiRenderTarget* SharedNoesisGuiRenderTarget = (FNoesisGuiRenderTarget*)SharedRenderTarget;
	FNoesisGuiRenderTarget* NoesisGuiRenderTarget = new FNoesisGuiRenderTarget();
	NoesisGuiRenderTarget->NoesisGuiTexture = *new FNoesisGuiTexture();
	NoesisGuiRenderTarget->ColorTarget = SharedNoesisGuiRenderTarget->ColorTarget;
	NoesisGuiRenderTarget->NoesisGuiTexture->ShaderResourceTexture = SharedNoesisGuiRenderTarget->NoesisGuiTexture->ShaderResourceTexture;
	NoesisGuiRenderTarget->DepthStencilTarget = SharedNoesisGuiRenderTarget->DepthStencilTarget;

	return Noesis::Ptr<Noesis::Render::RenderTarget>(*NoesisGuiRenderTarget);
}

Noesis::Ptr<Noesis::Render::Texture> FNoesisGuiRenderDevice::CreateTexture(const NsChar* Label, NsSize Width, NsSize Height, NsSize NumLevels, Noesis::Render::TextureFormat::Enum TextureFormat)
{
	uint32 SizeX = (uint32)Width;
	uint32 SizeY = (uint32)Height;
	EPixelFormat Formats[Noesis::Render::TextureFormat::Count] = { PF_B8G8R8A8, PF_G8 };
	uint8 Format = (uint8)Formats[TextureFormat];
	uint32 NumMips = (uint32)NumLevels;
	uint32 NumSamples = 1;
	uint32 Flags = 0;
	FRHIResourceCreateInfo CreateInfo;
	FTexture2DRHIRef ShaderResourceTexture = RHICreateTexture2D(SizeX, SizeY, Format, NumMips, NumSamples, Flags, CreateInfo);

	FNoesisGuiTexture* NoesisGuiTexture = new FNoesisGuiTexture();
	NoesisGuiTexture->ShaderResourceTexture = ShaderResourceTexture;

	FName TextureName = FName(Label);
	ShaderResourceTexture->SetName(TextureName);

	return Noesis::Ptr<Noesis::Render::Texture>(*NoesisGuiTexture);
}

void FNoesisGuiRenderDevice::UpdateTexture(Noesis::Render::Texture* Texture, NsSize Level, NsSize X, NsSize Y, NsSize Width, NsSize Height, const void* Data)
{
	FNoesisGuiTexture* NoesisGuiTexture = (FNoesisGuiTexture*)Texture;

	int32 MipIndex = (int32)Level;
	FUpdateTextureRegion2D UpdateRegion;
	UpdateRegion.SrcX = 0;
	UpdateRegion.SrcY = 0;
	UpdateRegion.DestX = (uint32)X;
	UpdateRegion.DestY = (uint32)Y;
	UpdateRegion.Width = (uint32)Width;
	UpdateRegion.Height = (uint32)Height;
	uint32 SourcePitch = (uint32)Width * ((NoesisGuiTexture->ShaderResourceTexture->GetFormat() == PF_B8G8R8A8) ? 4 : 1);
	const uint8* SourceData = (const uint8*)Data;

	GDynamicRHI->RHIUpdateTexture2D(NoesisGuiTexture->ShaderResourceTexture, MipIndex, UpdateRegion, SourcePitch, SourceData);
}

void FNoesisGuiRenderDevice::BeginRender(NsBool Offscreen)
{
}

void FNoesisGuiRenderDevice::SetRenderTarget(Noesis::Render::RenderTarget* Surface)
{
	if (RHICmdList)
	{
		check(Surface);
		FNoesisGuiRenderTarget* NoesisGuiRenderTarget = (FNoesisGuiRenderTarget*)Surface;
		::SetRenderTarget(*RHICmdList, NoesisGuiRenderTarget->ColorTarget, NoesisGuiRenderTarget->DepthStencilTarget);
		RHICmdList->SetViewport(0, 0, 0.0f, NoesisGuiRenderTarget->ColorTarget->GetSizeX(), NoesisGuiRenderTarget->ColorTarget->GetSizeY(), 1.0f);
		CurrentRenderTarget = NoesisGuiRenderTarget;
	}
}

void FNoesisGuiRenderDevice::BeginTile(const Noesis::Render::Tile& Tile)
{
	if (RHICmdList)
	{
		uint32 ScissorMinX = Tile.x;
		uint32 ScissorMinY = CurrentRenderTarget->NoesisGuiTexture->ShaderResourceTexture->GetSizeY() - (Tile.y + Tile.height);
		uint32 ScissorMaxX = Tile.x + Tile.width;
		uint32 ScissorMaxY = CurrentRenderTarget->NoesisGuiTexture->ShaderResourceTexture->GetSizeY() - Tile.y;
		RHICmdList->SetScissorRect(true, ScissorMinX, ScissorMinY, ScissorMaxX, ScissorMaxY);

		bool bClearColor = true;
		FLinearColor Color = FLinearColor::Transparent;
		bool bClearDepth = false;
		float Depth = 0.f;
		bool bClearStencil = true;
		uint32 Stencil = (uint32)0;
		FIntRect ExcludeRect;
		RHICmdList->Clear(bClearColor, Color, bClearDepth, Depth, bClearStencil, Stencil, ExcludeRect);
	}
}

void FNoesisGuiRenderDevice::EndTile()
{
	RHICmdList->SetScissorRect(false, 0, 0, 0, 0);
}

void FNoesisGuiRenderDevice::ResolveRenderTarget(Noesis::Render::RenderTarget* Surface, const Noesis::Render::Tile* Tiles, NsSize NumTiles)
{
	for (uint32 TileIndex = 0; TileIndex != (uint32)NumTiles; ++TileIndex)
	{
		const Noesis::Render::Tile& Tile = Tiles[TileIndex];

		uint32 ResolveMinX = Tile.x;
		uint32 ResolveMinY = CurrentRenderTarget->NoesisGuiTexture->ShaderResourceTexture->GetSizeY() - (Tile.y + Tile.height);
		uint32 ResolveMaxX = Tile.x + Tile.width;
		uint32 ResolveMaxY = CurrentRenderTarget->NoesisGuiTexture->ShaderResourceTexture->GetSizeY() - Tile.y;

		bool PreserveRenderTargetContents = false;
		FResolveParams ResolveParams;
		ResolveParams.Rect.X1 = ResolveMinX;
		ResolveParams.Rect.Y1 = ResolveMinY;
		ResolveParams.Rect.X2 = ResolveMaxX;
		ResolveParams.Rect.Y2 = ResolveMaxY;
		RHICmdList->CopyToResolveTarget(CurrentRenderTarget->ColorTarget, CurrentRenderTarget->NoesisGuiTexture->ShaderResourceTexture, PreserveRenderTargetContents, ResolveParams);
	}
}

void FNoesisGuiRenderDevice::EndRender()
{
}

void* FNoesisGuiRenderDevice::MapVertices(NsSize Bytes)
{
	void* Result = RHILockVertexBuffer(DynamicVertexBuffer, 0, Bytes, RLM_WriteOnly);
	return Result;
}

void FNoesisGuiRenderDevice::UnmapVertices()
{
	RHIUnlockVertexBuffer(DynamicVertexBuffer);
}

void* FNoesisGuiRenderDevice::MapIndices(NsSize Bytes)
{
	void* Result = RHILockIndexBuffer(DynamicIndexBuffer, 0, Bytes, RLM_WriteOnly);
	return Result;
}

void FNoesisGuiRenderDevice::UnmapIndices()
{
	RHIUnlockIndexBuffer(DynamicIndexBuffer);
}

static FSamplerStateRHIParamRef GetSamplerState(uint32 SamplerCode)
{
	switch (SamplerCode & 63)
	{
		case 0:  return TStaticSamplerState<SF_Point, AM_Wrap, AM_Wrap>::GetRHI();
		case 1:  return TStaticSamplerState<SF_Point, AM_Mirror, AM_Wrap>::GetRHI();
		case 2:  return TStaticSamplerState<SF_Point, AM_Clamp, AM_Wrap>::GetRHI();
		case 3:  return TStaticSamplerState<SF_Point, AM_Border, AM_Wrap>::GetRHI();
		case 4:  return TStaticSamplerState<SF_Point, AM_Wrap, AM_Mirror>::GetRHI();
		case 5:  return TStaticSamplerState<SF_Point, AM_Mirror, AM_Mirror>::GetRHI();
		case 6:  return TStaticSamplerState<SF_Point, AM_Clamp, AM_Mirror>::GetRHI();
		case 7:  return TStaticSamplerState<SF_Point, AM_Border, AM_Mirror>::GetRHI();
		case 8:  return TStaticSamplerState<SF_Point, AM_Wrap, AM_Clamp>::GetRHI();
		case 9:  return TStaticSamplerState<SF_Point, AM_Mirror, AM_Clamp>::GetRHI();
		case 10: return TStaticSamplerState<SF_Point, AM_Clamp, AM_Clamp>::GetRHI();
		case 11: return TStaticSamplerState<SF_Point, AM_Border, AM_Clamp>::GetRHI();
		case 12: return TStaticSamplerState<SF_Point, AM_Wrap, AM_Border>::GetRHI();
		case 13: return TStaticSamplerState<SF_Point, AM_Mirror, AM_Border>::GetRHI();
		case 14: return TStaticSamplerState<SF_Point, AM_Clamp, AM_Border>::GetRHI();
		case 15: return TStaticSamplerState<SF_Point, AM_Border, AM_Border>::GetRHI();

		case 16: return TStaticSamplerState<SF_Bilinear, AM_Wrap, AM_Wrap>::GetRHI();
		case 17: return TStaticSamplerState<SF_Bilinear, AM_Mirror, AM_Wrap>::GetRHI();
		case 18: return TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Wrap>::GetRHI();
		case 19: return TStaticSamplerState<SF_Bilinear, AM_Border, AM_Wrap>::GetRHI();
		case 20: return TStaticSamplerState<SF_Bilinear, AM_Wrap, AM_Mirror>::GetRHI();
		case 21: return TStaticSamplerState<SF_Bilinear, AM_Mirror, AM_Mirror>::GetRHI();
		case 22: return TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Mirror>::GetRHI();
		case 23: return TStaticSamplerState<SF_Bilinear, AM_Border, AM_Mirror>::GetRHI();
		case 24: return TStaticSamplerState<SF_Bilinear, AM_Wrap, AM_Clamp>::GetRHI();
		case 25: return TStaticSamplerState<SF_Bilinear, AM_Mirror, AM_Clamp>::GetRHI();
		case 26: return TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Clamp>::GetRHI();
		case 27: return TStaticSamplerState<SF_Bilinear, AM_Border, AM_Clamp>::GetRHI();
		case 28: return TStaticSamplerState<SF_Bilinear, AM_Wrap, AM_Border>::GetRHI();
		case 29: return TStaticSamplerState<SF_Bilinear, AM_Mirror, AM_Border>::GetRHI();
		case 30: return TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Border>::GetRHI();
		case 31: return TStaticSamplerState<SF_Bilinear, AM_Border, AM_Border>::GetRHI();

		case 32: return TStaticSamplerState<SF_Trilinear, AM_Wrap, AM_Wrap>::GetRHI();
		case 33: return TStaticSamplerState<SF_Trilinear, AM_Mirror, AM_Wrap>::GetRHI();
		case 34: return TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Wrap>::GetRHI();
		case 35: return TStaticSamplerState<SF_Trilinear, AM_Border, AM_Wrap>::GetRHI();
		case 36: return TStaticSamplerState<SF_Trilinear, AM_Wrap, AM_Mirror>::GetRHI();
		case 37: return TStaticSamplerState<SF_Trilinear, AM_Mirror, AM_Mirror>::GetRHI();
		case 38: return TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Mirror>::GetRHI();
		case 39: return TStaticSamplerState<SF_Trilinear, AM_Border, AM_Mirror>::GetRHI();
		case 40: return TStaticSamplerState<SF_Trilinear, AM_Wrap, AM_Clamp>::GetRHI();
		case 41: return TStaticSamplerState<SF_Trilinear, AM_Mirror, AM_Clamp>::GetRHI();
		case 42: return TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Clamp>::GetRHI();
		case 43: return TStaticSamplerState<SF_Trilinear, AM_Border, AM_Clamp>::GetRHI();
		case 44: return TStaticSamplerState<SF_Trilinear, AM_Wrap, AM_Border>::GetRHI();
		case 45: return TStaticSamplerState<SF_Trilinear, AM_Mirror, AM_Border>::GetRHI();
		case 46: return TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Border>::GetRHI();
		case 47: return TStaticSamplerState<SF_Trilinear, AM_Border, AM_Border>::GetRHI();

		case 48: return TStaticSamplerState<SF_Trilinear, AM_Wrap, AM_Wrap>::GetRHI();
		case 49: return TStaticSamplerState<SF_Trilinear, AM_Mirror, AM_Wrap>::GetRHI();
		case 50: return TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Wrap>::GetRHI();
		case 51: return TStaticSamplerState<SF_Trilinear, AM_Border, AM_Wrap>::GetRHI();
		case 52: return TStaticSamplerState<SF_Trilinear, AM_Wrap, AM_Mirror>::GetRHI();
		case 53: return TStaticSamplerState<SF_Trilinear, AM_Mirror, AM_Mirror>::GetRHI();
		case 54: return TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Mirror>::GetRHI();
		case 55: return TStaticSamplerState<SF_Trilinear, AM_Border, AM_Mirror>::GetRHI();
		case 56: return TStaticSamplerState<SF_Trilinear, AM_Wrap, AM_Clamp>::GetRHI();
		case 57: return TStaticSamplerState<SF_Trilinear, AM_Mirror, AM_Clamp>::GetRHI();
		case 58: return TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Clamp>::GetRHI();
		case 59: return TStaticSamplerState<SF_Trilinear, AM_Border, AM_Clamp>::GetRHI();
		case 60: return TStaticSamplerState<SF_Trilinear, AM_Wrap, AM_Border>::GetRHI();
		case 61: return TStaticSamplerState<SF_Trilinear, AM_Mirror, AM_Border>::GetRHI();
		case 62: return TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Border>::GetRHI();
		case 63: return TStaticSamplerState<SF_Trilinear, AM_Border, AM_Border>::GetRHI();
	}

	return 0;
}

void FNoesisGuiRenderDevice::DrawBatch(const Noesis::Render::Batch& Batch)
{
	if (RHICmdList)
	{
		switch (Batch.renderState.f.stencilMode)
		{
			case Noesis::Render::StencilMode::Disabled:
			{
				RHICmdList->SetDepthStencilState(TStaticDepthStencilState<false, CF_Always>::GetRHI(), 0);
			} break;
			case Noesis::Render::StencilMode::Equal_Keep:
			{
				RHICmdList->SetDepthStencilState(TStaticDepthStencilState<false, CF_Always, true, CF_Equal>::GetRHI(), Batch.stencilRef);
			} break;
			case Noesis::Render::StencilMode::Equal_Incr:
			{
				RHICmdList->SetDepthStencilState(TStaticDepthStencilState<false, CF_Always, true, CF_Equal, SO_Keep, SO_Keep, SO_Increment>::GetRHI(), Batch.stencilRef);
			} break;
			case Noesis::Render::StencilMode::Equal_Decr:
			{
				RHICmdList->SetDepthStencilState(TStaticDepthStencilState<false, CF_Always, true, CF_Equal, SO_Keep, SO_Keep, SO_Decrement>::GetRHI(), Batch.stencilRef);
			} break;
			default:
			{
			} break;
		}

		FTextureRHIParamRef PatternTexture = 0;
		FSamplerStateRHIParamRef PatternSamplerState = 0;
		if (Batch.pattern)
		{
			FNoesisGuiTexture* Texture = (FNoesisGuiTexture*)(Batch.pattern);
			PatternTexture = Texture->ShaderResourceTexture;
			PatternSamplerState = GetSamplerState((uint32)*(uint8*)&Batch.patternSampler);
		}

		FTextureRHIParamRef RampsTexture = 0;
		FSamplerStateRHIParamRef RampsSamplerState = 0;
		if (Batch.ramps)
		{
			FNoesisGuiTexture* Texture = (FNoesisGuiTexture*)(Batch.ramps);
			RampsTexture = Texture->ShaderResourceTexture;
			RampsSamplerState = GetSamplerState((uint32)*(uint8*)&Batch.rampsSampler);
		}

		FTextureRHIParamRef ImageTexture = 0;
		FSamplerStateRHIParamRef ImageSamplerState = 0;
		if (Batch.image)
		{
			FNoesisGuiTexture* Texture = (FNoesisGuiTexture*)(Batch.image);
			ImageTexture = Texture->ShaderResourceTexture;
			ImageSamplerState = GetSamplerState((uint32)*(uint8*)&Batch.imageSampler);
		}

		FTextureRHIParamRef GlyphsTexture = 0;
		FSamplerStateRHIParamRef GlyphsSamplerState = 0;
		if (Batch.glyphs)
		{
			FNoesisGuiTexture* Texture = (FNoesisGuiTexture*)(Batch.glyphs);
			GlyphsTexture = Texture->ShaderResourceTexture;
			GlyphsSamplerState = GetSamplerState((uint32)*(uint8*)&Batch.glyphsSampler);
		}

		const auto FeatureLevel = GMaxRHIFeatureLevel;

		uint32 ShaderCode = (uint32)Batch.shader.v;

		FVertexDeclarationRHIRef& VertexDeclaration = VertexDeclarations[ShaderCode];
		uint16 VertexStride = VertexStrides[ShaderCode];
		FNoesisGuiVSBase* VertexShader = VertexShaders[ShaderCode];
		FNoesisGuiPSBase* PixelShader = PixelShaders[ShaderCode];
		FGlobalBoundShaderState& BoundShaderState = BoundShaderStates[ShaderCode];
		SetGlobalBoundShaderState(*RHICmdList, FeatureLevel, BoundShaderState, VertexDeclaration, VertexShader, PixelShader);

		FMatrix ProjectionMtxValue = (const FMatrix&)(*Batch.projMtx);
		VertexShader->SetParameters(*RHICmdList, ProjectionMtxValue.GetTransposed());

		float OpacityValue = Batch.opacity;
		const FVector4 RgbaValue = (const FVector4&)(*Batch.rgba);
		const FVector4* RadialGradValue = (const FVector4*)Batch.radialGrad;
		PixelShader->SetParameters(*RHICmdList, OpacityValue, RgbaValue, RadialGradValue);

		RHICmdList->SetStreamSource(0, DynamicVertexBuffer, VertexStride, Batch.vertexOffset);

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

		if (Batch.renderState.f.colorEnable)
		{
			if (Batch.renderState.f.blendMode == Noesis::Render::BlendMode::SrcOver)
			{
				RHICmdList->SetBlendState(TStaticBlendState<CW_RGBA, BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI());
			}
			else
			{
				RHICmdList->SetBlendState(TStaticBlendState<CW_RGBA>::GetRHI());
			}
		}
		else
		{
			if (Batch.renderState.f.blendMode == Noesis::Render::BlendMode::SrcOver)
			{
				RHICmdList->SetBlendState(TStaticBlendState<CW_NONE, BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI());
			}
			else
			{
				RHICmdList->SetBlendState(TStaticBlendState<CW_NONE>::GetRHI());
			}
		}

		RHICmdList->DrawIndexedPrimitive(DynamicIndexBuffer, PT_TriangleList, 0, 0, VertexBufferSize, Batch.startIndex, Batch.numIndices / 3, 1);
	}
}
