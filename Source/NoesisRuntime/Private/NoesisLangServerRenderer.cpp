////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#if WITH_EDITOR

// UnrealEd includes
#include "NoesisLangServerRenderer.h"

// UtilityShaders includes
#include "ClearQuad.h"

// NoesisRuntime includes
#include "Render/NoesisRenderDevice.h"

// NoesisGUI includes
#include "NsGui/IntegrationAPI.h"
#include "NsGui/IView.h"
#include "NsGui/IRenderer.h"

NS_WARNING_PUSH

#ifdef _PREFAST_
#include <codeanalysis/warnings.h>
NS_MSVC_WARNING_DISABLE(ALL_CODE_ANALYSIS_WARNINGS)
#endif

NS_MSVC_WARNING_DISABLE(4242 4244 4100 4996)
NS_GCC_CLANG_WARNING_DISABLE("-Wconversion")
NS_GCC_CLANG_WARNING_DISABLE("-Wunused-function")
NS_GCC_CLANG_WARNING_DISABLE("-Wdeprecated-declarations")
NS_CLANG_WARNING_DISABLE("-Wunknown-warning-option")
NS_CLANG_WARNING_DISABLE("-Wcomma")

#define STBIW_MALLOC(sz) Noesis::Alloc(sz)
#define STBIW_REALLOC(p,sz) Noesis::Realloc(p, sz)
#define STBIW_FREE(p) Noesis::Dealloc(p)
#define STBIW_ASSERT(x) NS_ASSERT(x)
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

NS_WARNING_POP

static void Save(TArray<uint8>& Contents, int Width, int Height, const char* Path)
{
	NS_ASSERT(Contents.Num() == Width * Height * 4);
    Noesis::Vector<uint8_t> Data;
	Data.Resize(Contents.Num());

	// Convert to BGRA and unpremultiply the alpha
	for (int i = 0; i < Width * Height; i++)
	{
		Data[4 * i] = Contents[4 * i];
		Data[4 * i + 1] = Contents[4 * i + 1];
		Data[4 * i + 2] = Contents[4 * i + 2];
		Data[4 * i + 3] = Contents[4 * i + 3];
	}

	int err = stbi_write_png(Path, Width, Height, 4, Data.Begin(), Width * 4);
	NS_ASSERT(err == 1);
}

void Noesis::NoesisLangServerRenderer::Capture(Noesis::UIElement* Content, uint32 Width, uint32 Height, float RenderTime, const char* FilePath)
{
	NS_ASSERT(Width != 0);
	NS_ASSERT(Height != 0);
	
	const Noesis::Ptr<Noesis::Border> Root = Noesis::MakePtr<Noesis::Border>();
	Root->SetChild(Content);

	const Noesis::Ptr<Noesis::IView> View = Noesis::GUI::CreateView(Root);
	View->SetSize(Width, Height);
	View->SetFlags(Noesis::RenderFlags_PPAA);
	View->SetTessellationMaxPixelError(Noesis::TessellationMaxPixelError::HighQuality());

	Noesis::Ptr<Noesis::IRenderer> Renderer(View->GetRenderer());

	FGameTime WorldTime = FGameTime::CreateDilated(RenderTime, 0.0f,
		RenderTime, 0.0f);
	FSceneInterface* Scene = GWorld->Scene;

	TArray<uint8> Contents;

	ENQUEUE_RENDER_COMMAND(FNoesisInstance_InitRenderer)
	(
		[Renderer, View, Width, Height, RenderTime, WorldTime, Scene, &Contents](FRHICommandListImmediate& RHICmdList)
		{
			// Make sure dynamic material cached uniform expressions are up to date before doing any rendering
			FMaterialRenderProxy::UpdateDeferredCachedUniformExpressions();

			FNoesisRenderDevice* RenderDevice = FNoesisRenderDevice::Get();
			RenderDevice->SetRHICmdList(&RHICmdList);
			RenderDevice->SetWorldTime(WorldTime);
			RenderDevice->SetScene(Scene);

			Renderer->Init(RenderDevice);
			View->Update(0.0);
			Renderer->UpdateRenderTree();
			View->Update(RenderTime);
			Renderer->UpdateRenderTree();
			Renderer->RenderOffscreen();

			const Noesis::Ptr<Noesis::RenderTarget> RenderTarget = RenderDevice->CreateRenderTarget("Preview", Width,
				Height, 1, true);

			const Noesis::Tile Tile = { 0, 0, Width, Height };

			RenderDevice->SetRenderTarget(RenderTarget);
			RenderDevice->BeginTile(RenderTarget, Tile);
			RenderDevice->CreateView(0, 0, Width, Height, FIntRect(0, 0, Width, Height), FMatrix::Identity);
			Renderer->Render();
			RenderDevice->DestroyView();
			RenderDevice->EndTile(RenderTarget);

			RenderDevice->ResolveRenderTarget(RenderTarget, &Tile, 1);

			Noesis::Texture* Texture = RenderTarget->GetTexture();
			FTexture2DRHIRef ColorTarget = FNoesisRenderDevice::GetRHITexture(Texture);
			uint32 DstStride = Width * 4;
			Contents.AddUninitialized(Height * DstStride);
			uint8* DstPixels = Contents.GetData();
			uint32 SrcStride = 0;
			uint8* SrcPixels = (uint8*)RHILockTexture2D(ColorTarget, 0, EResourceLockMode::RLM_ReadOnly, SrcStride, false);
			for (uint32 Line = 0; Line < Height; ++Line)
			{
				FMemory::Memcpy(DstPixels, SrcPixels, DstStride);
				DstPixels += DstStride;
				SrcPixels += SrcStride;
			}
			RHIUnlockTexture2D(ColorTarget, 0, false);

			Renderer->Shutdown();
		}
	);

	FlushRenderingCommands();

	Save(Contents, Width, Height, FilePath);
}

#endif
