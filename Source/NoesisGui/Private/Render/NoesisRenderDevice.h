////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Engine includes
#include "StaticBoundShaderState.h"

class FNoesisRenderDevice : public Noesis::Render::RenderDevice
{
	static const uint32 VertexBufferSize = 256 * 1024;
	static const uint32 IndexBufferSize = 256 * 1024;

	FVertexBufferRHIRef DynamicVertexBuffer;
	FIndexBufferRHIRef DynamicIndexBuffer;
	uint32 VertexBufferOffset;
	uint32 IndexBufferOffset;

public:
	static const int32 NUM_SHADERS = 84;
	FRHICommandList* RHICmdList;
	FVertexDeclarationRHIRef VertexDeclarations[NUM_SHADERS];
	uint16 VertexStrides[NUM_SHADERS];
	class FNoesisVSBase* VertexShaders[NUM_SHADERS];
	class FNoesisPSBase* PixelShaders[NUM_SHADERS];
	FGlobalBoundShaderState BoundShaderStates[NUM_SHADERS];

	class FNoesisRenderTarget* CurrentRenderTarget;

	FNoesisRenderDevice();
	virtual ~FNoesisRenderDevice();

	static Noesis::Ptr<Noesis::Render::Texture> CreateTexture(UTexture2D* Texture);

	// RenderDevice interface
	virtual const Noesis::Render::DeviceCaps& GetCaps() const override;
	virtual Noesis::Ptr<Noesis::Render::RenderTarget> CreateRenderTarget(const NsChar* Label, NsSize Width, NsSize Height, NsSize SampleCount) override;
	virtual Noesis::Ptr<Noesis::Render::RenderTarget> CloneRenderTarget(const NsChar* Label, Noesis::Render::RenderTarget* SharedRenderTarget) override;
	virtual Noesis::Ptr<Noesis::Render::Texture> CreateTexture(const NsChar* Label, NsSize Width, NsSize Height, NsSize NumLevels, Noesis::Render::TextureFormat::Enum TextureFormat) override;
	virtual void UpdateTexture(Noesis::Render::Texture* Texture, NsSize Level, NsSize X, NsSize Y, NsSize Width, NsSize Height, const void* Data) override;
	virtual void BeginRender(NsBool Offscreen) override;
	virtual void SetRenderTarget(Noesis::Render::RenderTarget* Surface) override;
	virtual void BeginTile(const Noesis::Render::Tile& Tile, NsSize SurfaceWidth, NsSize SurfaceHeight) override;
	virtual void EndTile() override;
	virtual void ResolveRenderTarget(Noesis::Render::RenderTarget* Surface, const Noesis::Render::Tile* Tiles, NsSize NumTiles) override;
	virtual void EndRender() override;
	virtual void* MapVertices(NsSize Bytes) override;
	virtual void UnmapVertices() override;
	virtual void* MapIndices(NsSize Bytes) override;
	virtual void UnmapIndices() override;
	virtual void DrawBatch(const Noesis::Render::Batch& Batch) override;
	// End of RenderDevice interface
};
