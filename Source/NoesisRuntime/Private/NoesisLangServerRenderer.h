////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#if WITH_EDITOR

// Core includes
#include "CoreMinimal.h"

// Noesis includes
#include "NoesisSDK.h"

namespace Noesis
{
namespace NoesisLangServerRenderer
{
    void Capture(Noesis::UIElement* Content, uint32 Width, uint32 Height, float RenderTime, const char* savePath);
}
}


#endif
