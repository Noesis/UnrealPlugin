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
#include "RHIResources.h"

// NoesisRuntime includes
#include "NoesisInstance.h"
#include "NoesisShaders.h"

// Noesis includes
#include "NoesisSDK.h"

// RenderCore includes
#include "ProfilingDebugging/RealtimeGPUProfiler.h"

#if !UE_BUILD_SHIPPING
	#define NOESIS_BIND_DEBUG_LABEL(Resource, Name) \
		RHIBindDebugLabelName(Resource, Name); \
		Resource->SetName(Name);
#else
	#define NOESIS_BIND_DEBUG_LABEL(Resource, Name)
#endif

#define NOESIS_BIND_DEBUG_TEXTURE_LABEL(Texture, Name) NOESIS_BIND_DEBUG_LABEL(Texture, Name)

#if UE_VERSION_OLDER_THAN(5, 0, 0)
	// RHIBindDebugLabelName and SetName are not implemented for FVertexBufferRHIRef or FIndexBufferRHIRef
	#define NOESIS_BIND_DEBUG_BUFFER_LABEL(Buffer, Name)
#else
	#define NOESIS_BIND_DEBUG_BUFFER_LABEL(Buffer, Name) NOESIS_BIND_DEBUG_LABEL(Buffer, Name)
#endif

class FNoesisRenderDevice : public Noesis::RenderDevice
{
#if UE_VERSION_OLDER_THAN(5, 0, 0)
	FVertexBufferRHIRef DynamicVertexBuffer;
	FIndexBufferRHIRef DynamicIndexBuffer;
#else
	FBufferRHIRef DynamicVertexBuffer;
	FBufferRHIRef DynamicIndexBuffer;
#endif
	FUniformBufferRHIRef VSConstantBuffer;
	FUniformBufferRHIRef TextureSizeBuffer;
	FUniformBufferRHIRef PSRgbaConstantBuffer;
	FUniformBufferRHIRef PSOpacityConstantBuffer;
	FUniformBufferRHIRef PSRadialGradConstantBuffer;
	FUniformBufferRHIRef BlurConstantsBuffer;
	FUniformBufferRHIRef ShadowConstantsBuffer;
	uint32 VSConstantsHash;
	uint32 TextureSizeHash;
	uint32 PSConstantsHash;
	uint32 EffectsHash;

#if WANTS_DRAW_MESH_EVENTS
	FDrawEvent* SetRenderTargetEvent;
	FDrawEvent* TileEvent;
#endif

	FNoesisRenderDevice();
	virtual ~FNoesisRenderDevice();

public:
	FGameTime WorldTime;
	FRHICommandListImmediate* RHICmdList;
	FSceneViewFamily* ViewFamily;
	FViewInfo* View;
	FSceneInterface* Scene;
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

	void SetRHICmdList(class FRHICommandListImmediate* RHICmdList);
	void SetWorldTime(FGameTime InWorldTime);
	void SetScene(FSceneInterface* InScene);

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
