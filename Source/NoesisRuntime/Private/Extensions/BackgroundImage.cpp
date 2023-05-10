////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Extensions/BackgroundImage.h"

// Engine includes
#include "UnrealClient.h"

// NoesisRuntime includes
#include "Render/NoesisRenderDevice.h"

FTexture2DRHIRef BackgroundImage::BackgroundColorTexture;
FIntPoint BackgroundImage::BackgroundViewportSize;
Noesis::Ptr<Noesis::Texture> BackgroundImage::NoesisBackgroundTexture;

////////////////////////////////////////////////////////////////////////////////////////////////////
static Noesis::Texture* UpdateTextureRenderCallback(Noesis::RenderDevice* device, void* user)
{
	if (BackgroundImage::BackgroundColorTexture == nullptr)
		return nullptr;

	if (BackgroundImage::NoesisBackgroundTexture == nullptr || BackgroundImage::NoesisBackgroundTexture->GetWidth() != BackgroundImage::BackgroundColorTexture->GetSizeX() || BackgroundImage::NoesisBackgroundTexture->GetHeight() != BackgroundImage::BackgroundColorTexture->GetSizeY())
	{
		BackgroundImage::NoesisBackgroundTexture = FNoesisRenderDevice::CreateTexture(BackgroundImage::BackgroundColorTexture->GetSizeX(), BackgroundImage::BackgroundColorTexture->GetSizeY(), 1, false);
	}

	FNoesisRenderDevice::SetRHITexture(BackgroundImage::NoesisBackgroundTexture, BackgroundImage::BackgroundColorTexture);

	return BackgroundImage::NoesisBackgroundTexture;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
BackgroundImage::BackgroundImage()
	: Noesis::DynamicTextureSource(BackgroundImage::BackgroundViewportSize.X, BackgroundImage::BackgroundViewportSize.Y, &UpdateTextureRenderCallback, nullptr)
{
	mViewportResizedDelegateHandle = FViewport::ViewportResizedEvent.AddRaw(this, &BackgroundImage::OnViewportResized);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
BackgroundImage::~BackgroundImage()
{
	FViewport::ViewportResizedEvent.Remove(mViewportResizedDelegateHandle);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void BackgroundImage::OnViewportResized(FViewport* Viewport, uint32)
{
	if (Viewport != nullptr)
	{
		const FIntPoint ViewportSize = Viewport->GetSizeXY();
		Resize(ViewportSize.X, ViewportSize.Y);
	}
}

NS_IMPLEMENT_REFLECTION(BackgroundImage, "NoesisGUIExtensions.BackgroundImage")
{
}
