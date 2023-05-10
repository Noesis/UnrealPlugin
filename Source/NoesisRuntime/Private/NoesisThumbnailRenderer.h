////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#if WITH_EDITOR

// RHI includes
#include "RHI.h"

// Engine includes
#include "Engine/World.h"

#include "NoesisSDK.h"

struct FNoesisThumbnailRenderer
{
    static Noesis::Ptr<Noesis::IView> CreateView(Noesis::FrameworkElement* Content);
    static void RenderView(Noesis::IView* View, UWorld* World, FIntRect ViewportRect,
        const FTexture2DRHIRef& BackBuffer);
};


#endif
