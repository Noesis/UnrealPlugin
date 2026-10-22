////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Extensions/BackgroundImage.h"

// Engine includes
#include "UnrealClient.h"

// NoesisRuntime includes
#include "Render/NoesisRenderDevice.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
static Noesis::Ptr<Noesis::Texture> NoesisBackgroundImageTexture;
static FIntPoint NoesisBackgroundImageSize;

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace
{
class BackgroundImageRenderer: public Noesis::DynamicTextureSource::Renderer
{
public:
	void Init(Noesis::RenderDevice* device) override { }

	Noesis::Texture* Render(uint32_t width, uint32_t height)
	{
		return NoesisBackgroundImageTexture;
	}

	void Shutdown() { }
};
}

////////////////////////////////////////////////////////////////////////////////////////////////////
BackgroundImage::BackgroundImage():
	Noesis::DynamicTextureSource(NoesisBackgroundImageSize.X, NoesisBackgroundImageSize.Y,
		Noesis::MakePtr<BackgroundImageRenderer>())
{
	mViewportResizedDelegateHandle = FViewport::ViewportResizedEvent.AddRaw(this,
		&BackgroundImage::OnViewportResized);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
BackgroundImage::~BackgroundImage()
{
	FViewport::ViewportResizedEvent.Remove(mViewportResizedDelegateHandle);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void BackgroundImage::SetBackgroundImageTexture(FRHITexture* Texture)
{
	if (!NoesisBackgroundImageTexture)
	{
		NoesisBackgroundImageTexture = FNoesisRenderDevice::CreateTexture(Texture, true);
	}
	else
	{
		FNoesisRenderDevice::SetRHITexture(NoesisBackgroundImageTexture, Texture);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void BackgroundImage::Destroy()
{
	NoesisBackgroundImageTexture.Reset();
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
