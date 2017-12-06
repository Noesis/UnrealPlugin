////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisSettings.h"

UNoesisSettings::UNoesisSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	OffscreenTextureSampleCount = ENoesisOffscreenSampleCount::One;
	GlyphTextureSize = ENoesisGlyphCacheDimensions::x1024;
	GlyphMeshThreshold = 96;
}
