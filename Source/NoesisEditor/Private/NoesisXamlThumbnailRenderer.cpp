////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisXamlThumbnailRenderer.h"

// RHI includes
#include "RHI.h"

// Engine includes
#include "UnrealClient.h"

// NoesisRuntime includes
#include "NoesisXaml.h"

UNoesisXamlThumbnailRenderer::UNoesisXamlThumbnailRenderer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UNoesisXamlThumbnailRenderer::CanVisualizeAsset(UObject* Object)
{
	UNoesisXaml* Xaml = Cast<UNoesisXaml>(Object);
	return Xaml != nullptr;
}

void UNoesisXamlThumbnailRenderer::Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height,
	FRenderTarget* Viewport, FCanvas* Canvas, bool bAdditionalViewFamily)
{
	UNoesisXaml* Xaml = Cast<UNoesisXaml>(Object);
	if (Xaml != nullptr)
	{
		FIntRect ViewportRect(X, Y, X + Width, Y + Height);
		const FTexture2DRHIRef& BackBuffer = Viewport->GetRenderTargetTexture();
		Xaml->RenderThumbnail(ViewportRect, BackBuffer);
	}
}
