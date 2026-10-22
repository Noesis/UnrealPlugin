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
#if UE_VERSION_OLDER_THAN(5, 0, 0)
	#define NOESIS_BIND_DEBUG_LABEL(RHICmdList, Resource, Name) \
		RHIBindDebugLabelName(Resource, Name); \
		Resource->SetName(Name);
#else
#define NOESIS_BIND_DEBUG_LABEL(RHICmdList, Resource, Name) \
		RHICmdList.BindDebugLabelName(Resource, Name); \
		Resource->SetName(Name);
#endif
#else
	#define NOESIS_BIND_DEBUG_LABEL(RHICmdList, Resource, Name)
#endif

#define NOESIS_BIND_DEBUG_TEXTURE_LABEL(RHICmdList, Texture, Name) NOESIS_BIND_DEBUG_LABEL(RHICmdList, Texture, Name)

#if UE_VERSION_OLDER_THAN(5, 0, 0)
	// RHIBindDebugLabelName and SetName are not implemented for FVertexBufferRHIRef or FIndexBufferRHIRef
	#define NOESIS_BIND_DEBUG_BUFFER_LABEL(RHICmdList, Buffer, Name)
#else
	#define NOESIS_BIND_DEBUG_BUFFER_LABEL(RHICmdList, Buffer, Name) NOESIS_BIND_DEBUG_LABEL(RHICmdList, Buffer, Name)
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
	FUniformBufferRHIRef VSConstantBufferStereo;
	FUniformBufferRHIRef TextureSizeBuffer;
	FUniformBufferRHIRef PSRgbaConstantBuffer;
	FUniformBufferRHIRef PSOpacityConstantBuffer;
	FUniformBufferRHIRef PSRadialGradConstantBuffer;
	FUniformBufferRHIRef BlurConstantsBuffer;
	FUniformBufferRHIRef ShadowConstantsBuffer;
	uint32 VSConstantsHash = 0;
	uint32 TextureSizeHash = 0;
	uint32 PSRgbaConstantsHash = 0;
	uint32 PSOpacityConstantsHash = 0;
	uint32 PSRadialGradConstantsHash = 0;
	uint32 BlurConstantsHash = 0;
	uint32 ShadowConstantsHash = 0;

#if UE_VERSION_OLDER_THAN(5, 5, 0)
#if WANTS_DRAW_MESH_EVENTS
	FDrawEvent SetRenderTargetEvent;
#endif
#else
#if WITH_RHI_BREADCRUMBS
	TOptional<FRHIBreadcrumbEventManual> SetRenderTargetBreadcrumb;
#endif
#endif

	FNoesisRenderDevice(bool LinearColor);
	virtual ~FNoesisRenderDevice();

public:
	FGameTime WorldTime;
	FRHICommandList* RHICmdList = nullptr;
	FSceneViewFamily* ViewFamily = nullptr;
	FViewInfo* View = nullptr;
	FSceneInterface* Scene = nullptr;
	uint32 ViewLeft, ViewTop, ViewRight, ViewBottom;
	bool IsWorldUI = false;
	bool IsLinearColor = false;
	bool AlphaMask = false;
	float Gamma = 2.2f;
	float Contrast = 1.0f;
	FUniformBufferRHIRef* PixelShaderConstantBuffer0[Noesis::Shader::Count];
	FUniformBufferRHIRef* PixelShaderConstantBuffer1[Noesis::Shader::Count];
	uint32* PixelShaderConstantBuffer0Hash[Noesis::Shader::Count];
	uint32* PixelShaderConstantBuffer1Hash[Noesis::Shader::Count];
	TUniformBufferRef<FSceneTextureUniformParameters> SceneTexturesUniformBuffer;
	TUniformBufferRef<FMobileSceneTextureUniformParameters> MobileSceneTexturesUniformBuffer;
	TUniformBufferRef<FViewUniformShaderParameters> ViewUniformBuffer;

	void SetSceneTexturesUniformBuffer(const TUniformBufferRef<FSceneTextureUniformParameters>& Params) { SceneTexturesUniformBuffer = Params; }
	void SetMobileSceneTexturesUniformBuffer(const TUniformBufferRef<FMobileSceneTextureUniformParameters>& Params) { MobileSceneTexturesUniformBuffer = Params; }

	static FNoesisRenderDevice* Get();
	static FNoesisRenderDevice* GetLinear();
	static void Destroy();

	static Noesis::Ptr<Noesis::Texture> CreateTexture(FRHITexture* RHITexture, bool IgnoreAlpha);
	static void SetRHITexture(Noesis::Texture* Texture, FRHITexture* RHITexture);
	static Noesis::Ptr<Noesis::Texture> CreateTexture(class UTexture* Texture);
	static FRHITexture* GetRHITexture(Noesis::Texture* Texture); // You need to add a reference if you want to keep the object.
	static void* CreateMaterial(class UMaterialInterface* Material);
	static void DestroyMaterial(void* Material);

	void SetRHICmdList(class FRHICommandList* RHICmdList);
	void SetWorldTime(FGameTime InWorldTime);
	void SetScene(FSceneInterface* InScene);
	void SetGammaAndContrast(float InGamma, float InContrast) { Gamma = InGamma; Contrast = InContrast; }

	void CreateView(uint32 Left, uint32 Top, uint32 Right, uint32 Bottom, const FIntRect& ViewRect, const FMatrix& ViewProjectionMatrix);
	void DestroyView();

	template<class PixelShaderClass>
	bool SetPatternMaterialParameters(const Noesis::Batch& Batch, const FMaterialRenderProxy* MaterialProxy, const FMaterial* Material, const TShaderRef<PixelShaderClass>& PixelShader);

	template<class PixelShaderClass>
	bool SetPixelShaderParameters(const Noesis::Batch& Batch, const FMaterialRenderProxy* MaterialProxy, const FMaterial* Material, const TShaderRef<PixelShaderClass>& BasePixelShader, const FUniformBufferRHIRef& PSUniformBuffer0, const FUniformBufferRHIRef& PSUniformBuffer1);

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
	virtual void BeginTile(Noesis::RenderTarget* Surface, const Noesis::Tile& Tile) override;
	virtual void EndTile(Noesis::RenderTarget* Surface) override;
	virtual void ResolveRenderTarget(Noesis::RenderTarget* Surface, const Noesis::Tile* Tiles, uint32 NumTiles) override;
	virtual void* MapVertices(uint32 Bytes) override;
	virtual void UnmapVertices() override;
	virtual void* MapIndices(uint32 Bytes) override;
	virtual void UnmapIndices() override;
	virtual void DrawBatch(const Noesis::Batch& Batch) override;
	// End of RenderDevice interface
};
