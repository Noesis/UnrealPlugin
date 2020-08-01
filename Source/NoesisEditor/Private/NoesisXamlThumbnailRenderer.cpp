////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisXamlThumbnailRenderer.h"

UNoesisXamlThumbnailRenderer::UNoesisXamlThumbnailRenderer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UNoesisXamlThumbnailRenderer::CanVisualizeAsset(UObject* Object)
{
	UNoesisXaml* NoesisXaml = Cast<UNoesisXaml>(Object);
	return NoesisXaml && NoesisXaml->CanRenderThumbnail();
}

void UNoesisXamlThumbnailRenderer::Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* Viewport, FCanvas* Canvas, bool bAdditionalViewFamily)
{
	UNoesisXaml* NoesisXaml = Cast<UNoesisXaml>(Object);
	if (!NoesisXaml)
		return;

	FIntRect ViewportRect(X, Y, X + Width, Y + Height);
	const FTexture2DRHIRef& BackBuffer = Viewport->GetRenderTargetTexture();
	NoesisXaml->RenderThumbnail(ViewportRect, BackBuffer);
}
