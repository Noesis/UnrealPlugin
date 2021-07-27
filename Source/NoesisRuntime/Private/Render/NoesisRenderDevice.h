////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// RHI includes
#include "RHI.h"
#include "RHIResources.h"

// NoesisRuntime includes
#include "NoesisShaders.h"

// Noesis includes
#include "NoesisSDK.h"

// RenderCore includes
#include "ProfilingDebugging/RealtimeGPUProfiler.h"

class FNoesisRenderDevice : public Noesis::RenderDevice
{
#if ENGINE_MAJOR_VERSION >= 5
	FBufferRHIRef DynamicVertexBuffer;
	FBufferRHIRef DynamicIndexBuffer;
#else
	FVertexBufferRHIRef DynamicVertexBuffer;
	FIndexBufferRHIRef DynamicIndexBuffer;
#endif
	FUniformBufferRHIRef VSConstantBuffer;
	FUniformBufferRHIRef TextureSizeBuffer;
	FUniformBufferRHIRef PSRgbaConstantBuffer;
	FUniformBufferRHIRef PSOpacityConstantBuffer;
	FUniformBufferRHIRef PSRadialGradConstantBuffer;
	FUniformBufferRHIRef BlurConstantsBuffer;
	FUniformBufferRHIRef ShadowConstantsBuffer;
	TUniformBufferRef<FViewUniformShaderParameters> ViewBuffer;
	uint32 VSConstantsHash;
	uint32 TextureSizeHash;
	uint32 PSConstantsHash;
	uint32 EffectsHash;
	uint32 ViewHash;

#if WANTS_DRAW_MESH_EVENTS
	FDrawEvent* SetRenderTargetEvent;
	FDrawEvent* TileEvent;
#endif

	FNoesisRenderDevice();
	virtual ~FNoesisRenderDevice();

public:
	float WorldTimeSeconds;
	float WorldDeltaSeconds;
	float WorldRealTimeSeconds;
	FRHICommandList* RHICmdList;
	FSceneView* View;
	uint32 ViewLeft, ViewTop, ViewRight, ViewBottom;
	FVertexDeclarationRHIRef VertexDeclarations[Noesis::Shader::Count];
	TShaderRef<FNoesisVSBase> VertexShaders[Noesis::Shader::Count];
	TShaderRef<FNoesisPSBase> PixelShaders[Noesis::Shader::Count];
	TShaderRef<FNoesisPSBase> PixelShadersPatternSRGB[Noesis::Shader::Count];
	FUniformBufferRHIRef* PixelShaderConstantBuffer0[Noesis::Shader::Count];
	FUniformBufferRHIRef* PixelShaderConstantBuffer1[Noesis::Shader::Count];
	FRHIDepthStencilState* DepthStencilStates[Noesis::StencilMode::Count];
	FRHIBlendState* BlendStates[Noesis::BlendMode::Count];
	//FRHISamplerState* SamplerStates[Noesis::WrapMode::Count * Noesis::MinMagFilter::Count * Noesis::MipFilter::Count];
	FRHISamplerState* SamplerStates[64];

	static FNoesisRenderDevice* Get();
	static void Destroy();

	static Noesis::Ptr<Noesis::Texture> CreateTexture(class UTexture* Texture);
	static void* CreateMaterial(class UMaterialInterface* Material);
	static void DestroyMaterial(void* Material);

	void SetRHICmdList(class FRHICommandList* RHICmdList);
	void SetWorldTimes(float InWorldTimeSeconds, float InWorldDeltaSeconds, float InWorldRealTimeSeconds);

	void CreateView(uint32 Left, uint32 Top, uint32 Right, uint32 Bottom);
	void DestroyView();

	template<class PixelShaderClass>
	void SetPatternMaterialParameters(const Noesis::Batch& Batch, TShaderRef<PixelShaderClass>& PixelShader);

	template<class PixelShaderClass>
	void SetPixelShaderParameters(const Noesis::Batch& Batch, TShaderRef<PixelShaderClass>& BasePixelShader, FUniformBufferRHIRef& PSUniformBuffer0, FUniformBufferRHIRef& PSUniformBuffer1);

	// RenderDevice interface
	virtual const Noesis::DeviceCaps& GetCaps() const override;
	virtual Noesis::Ptr<Noesis::RenderTarget> CreateRenderTarget(const char* Label, uint32 Width, uint32 Height, uint32 SampleCount, bool NeedsStencil) override;
	virtual Noesis::Ptr<Noesis::RenderTarget> CloneRenderTarget(const char* Label, Noesis::RenderTarget* SharedRenderTarget) override;
	virtual Noesis::Ptr<Noesis::Texture> CreateTexture(const char* Label, uint32 Width, uint32 Height, uint32 NumLevels, Noesis::TextureFormat::Enum TextureFormat, const void** Data) override;
	virtual void UpdateTexture(Noesis::Texture* Texture, uint32 Level, uint32 X, uint32 Y, uint32 Width, uint32 Height, const void* Data) override;
	virtual void BeginOffscreenRender() override;
	virtual void EndOffscreenRender() override;
	virtual void BeginOnscreenRender() override;
	virtual void EndOnscreenRender() override;
	virtual void SetRenderTarget(Noesis::RenderTarget* Surface) override;
	virtual void ResolveRenderTarget(Noesis::RenderTarget* Surface, const Noesis::Tile* Tiles, uint32 NumTiles) override;
	virtual void* MapVertices(uint32 Bytes) override;
	virtual void UnmapVertices() override;
	virtual void* MapIndices(uint32 Bytes) override;
	virtual void UnmapIndices() override;
	virtual void DrawBatch(const Noesis::Batch& Batch) override;
	// End of RenderDevice interface
};
