////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// RHI includes
#include "RHI.h"
#include "RHIResources.h"

// Noesis includes
#include "NoesisSDK.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
class NOESISRUNTIME_API BackgroundImage : public Noesis::DynamicTextureSource
{
public:
	BackgroundImage();
	~BackgroundImage();

	static void SetBackgroundImageTexture(FRHITexture2D* Texture);
	static void SetBackgroundImageSize(const FIntPoint& Size);

private:
	void OnViewportResized(class FViewport* Viewport, uint32);

	FDelegateHandle mViewportResizedDelegateHandle;

	NS_DECLARE_REFLECTION(BackgroundImage, Noesis::DynamicTextureSource)
};
