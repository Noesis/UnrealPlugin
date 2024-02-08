////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#if WITH_EDITOR

// UnrealEd includes
#include "NoesisThumbnailRenderer.h"

// UtilityShaders includes
#include "ClearQuad.h"

// NoesisRuntime includes
#include "Render/NoesisRenderDevice.h"

// NoesisGUI includes
#include "NsGui/IntegrationAPI.h"
#include "NsGui/IView.h"
#include "NsGui/IRenderer.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
Noesis::Ptr<Noesis::IView> FNoesisThumbnailRenderer::CreateView(Noesis::FrameworkElement* Content)
{
	Noesis::Ptr<Noesis::IView> View = Noesis::GUI::CreateView(Content);
	Noesis::Ptr<Noesis::IRenderer> Renderer(View->GetRenderer());

	ENQUEUE_RENDER_COMMAND(FNoesisThumbnail_InitRenderer)
	(
		[Renderer](FRHICommandListImmediate& RHICmdList)
		{
			Renderer->Init(FNoesisRenderDevice::Get());
		}
	);

	return View;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void FNoesisThumbnailRenderer::RenderView(Noesis::IView* View, UWorld* World, FIntRect ViewportRect,
    const FTexture2DRHIRef& BackBuffer)
{
	if (View == nullptr || World == nullptr || BackBuffer == nullptr) return;

	// Update size
	int32 Width = ViewportRect.Max.X - ViewportRect.Min.X;
	int32 Height = ViewportRect.Max.Y - ViewportRect.Min.Y;
	View->SetSize((uint32_t)Width, (uint32_t)Height);

	// Update view
#if UE_VERSION_OLDER_THAN(5, 0, 0)
	FGameTime WorldTime = FGameTime::CreateDilated(World->GetRealTimeSeconds(), 0.0f,
		World->GetTimeSeconds(), World->GetDeltaSeconds());
#else
	FGameTime WorldTime = World->GetTime();
#endif
	FSceneInterface* Scene = World->Scene;

	float Time = World->GetTimeSeconds();
	View->Update(Time);

	// Enqueue render
	Noesis::Ptr<Noesis::IRenderer> Renderer(View->GetRenderer());
	ENQUEUE_RENDER_COMMAND(FNoesisThumbnail_Render)
	(
		[Renderer, WorldTime, Scene, BackBuffer](FRHICommandListImmediate& RHICmdList)
		{
			// Make sure dynamic material cached uniform expressions are up to date before doing any rendering
			FMaterialRenderProxy::UpdateDeferredCachedUniformExpressions();

			FNoesisRenderDevice* RenderDevice = FNoesisRenderDevice::Get();
			RenderDevice->SetRHICmdList(&RHICmdList);
			RenderDevice->SetWorldTime(WorldTime);
			RenderDevice->SetScene(Scene);
			Renderer->UpdateRenderTree();
			Renderer->RenderOffscreen();

			uint32 SizeX = BackBuffer->GetSizeX();
			uint32 SizeY = BackBuffer->GetSizeY();
			EPixelFormat Format = PF_DepthStencil;
			uint32 NumMips = BackBuffer->GetNumMips();
			uint32 NumSamples = BackBuffer->GetNumSamples();
			ETextureCreateFlags TargetableTextureFlags = TexCreate_DepthStencilTargetable | TexCreate_Memoryless;
			ERHIAccess Access = ERHIAccess::DSVWrite;
			FClearValueBinding ClearValue(0.f, 0);
			FTexture2DRHIRef ColorTarget = BackBuffer;
			const TCHAR* Name = TEXT("Noesis.RenderTarget.Thumbnail_DS");
	#if UE_VERSION_OLDER_THAN(5, 1, 0)
			FRHIResourceCreateInfo CreateInfo(Name);
			CreateInfo.ClearValueBinding = ClearValue;
			FTexture2DRHIRef DepthStencilTarget = RHICreateTexture2D(SizeX, SizeY,
				(uint8)Format, NumMips, NumSamples, TargetableTextureFlags, Access, CreateInfo);
	#else
			auto DepthStencilTargetDesc = FRHITextureCreateDesc::Create2D(Name)
				.SetExtent(SizeX, SizeY)
				.SetFormat(Format)
				.SetNumMips(NumMips)
				.SetNumSamples(NumSamples)
				.SetFlags(TargetableTextureFlags)
				.SetInitialState(Access)
				.SetClearValue(ClearValue);
			FTexture2DRHIRef DepthStencilTarget = RHICreateTexture(DepthStencilTargetDesc);
	#endif
			NOESIS_BIND_DEBUG_TEXTURE_LABEL(DepthStencilTarget, Name);

			FRHIRenderPassInfo RPInfo(ColorTarget, ERenderTargetActions::DontLoad_Store, DepthStencilTarget,
				MakeDepthStencilTargetActions(ERenderTargetActions::DontLoad_DontStore, ERenderTargetActions::Clear_Store), FExclusiveDepthStencil::DepthNop_StencilWrite);

			check(RHICmdList.IsOutsideRenderPass());
			RHICmdList.BeginRenderPass(RPInfo, TEXT("NoesisThumbnail"));

			DrawClearQuad(RHICmdList, true, FLinearColor(0.0f, 0.0f, 0.0f, 0.0f), false, 0.f, false, 0);

			RenderDevice->CreateView(0, 0, SizeX, SizeY, FIntRect(0, 0, SizeX, SizeY), FMatrix::Identity);
			Renderer->Render();
			RenderDevice->DestroyView();
			RenderDevice->SetRHICmdList(nullptr);

			RHICmdList.EndRenderPass();
		}
	);
}

#endif
