////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisRiveThumbnailRenderer.h"

// RHI include
#include "RHI.h"

// Engine includes
#include "UnrealClient.h"

// NoesisRuntime includes
#include "NoesisRive.h"
#include "NoesisXaml.h"

UNoesisRiveThumbnailRenderer::UNoesisRiveThumbnailRenderer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UNoesisRiveThumbnailRenderer::CanVisualizeAsset(UObject* Object)
{
	UNoesisRive* Rive = Cast<UNoesisRive>(Object);
	return Rive != nullptr;
}

void UNoesisRiveThumbnailRenderer::Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height,
	FRenderTarget* Viewport, FCanvas* Canvas, bool bAdditionalViewFamily)
{
	UNoesisRive* Rive = Cast<UNoesisRive>(Object);
	if (Rive != nullptr)
	{
		FIntRect ViewportRect(X, Y, X + Width, Y + Height);
		const FTexture2DRHIRef& BackBuffer = Viewport->GetRenderTargetTexture();
		Rive->RenderThumbnail(ViewportRect, BackBuffer);
	}
}
