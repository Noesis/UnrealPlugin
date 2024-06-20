////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Extensions/BackgroundImage.h"

// Engine includes
#include "UnrealClient.h"

// NoesisRuntime includes
#include "Render/NoesisRenderDevice.h"

static Noesis::Ptr<Noesis::Texture> NoesisBackgroundImageTexture;
static FIntPoint NoesisBackgroundImageSize;

////////////////////////////////////////////////////////////////////////////////////////////////////
static Noesis::Texture* UpdateTextureRenderCallback(Noesis::RenderDevice* device, void* user)
{
	return NoesisBackgroundImageTexture;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
BackgroundImage::BackgroundImage()
	: Noesis::DynamicTextureSource(NoesisBackgroundImageSize.X, NoesisBackgroundImageSize.Y, &UpdateTextureRenderCallback, nullptr)
{
	mViewportResizedDelegateHandle = FViewport::ViewportResizedEvent.AddRaw(this, &BackgroundImage::OnViewportResized);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
BackgroundImage::~BackgroundImage()
{
	FViewport::ViewportResizedEvent.Remove(mViewportResizedDelegateHandle);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void BackgroundImage::SetBackgroundImageTexture(FRHITexture2D* Texture)
{
	if (!NoesisBackgroundImageTexture || FNoesisRenderDevice::GetRHITexture(NoesisBackgroundImageTexture) != Texture)
	{
		NoesisBackgroundImageTexture = FNoesisRenderDevice::CreateTexture(Texture, true);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void BackgroundImage::SetBackgroundImageSize(const FIntPoint& Size)
{
	NoesisBackgroundImageSize = Size;
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
