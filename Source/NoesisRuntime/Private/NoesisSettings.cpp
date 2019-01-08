////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisSettings.h"

#include "NoesisResourceResolver.h"

UNoesisSettings::UNoesisSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	OffscreenTextureSampleCount = ENoesisOffscreenSampleCount::One;
	GlyphTextureSize = ENoesisGlyphCacheDimensions::x1024;
	GlyphMeshThreshold = 96;

	ResourceResolverClass = UNoesisResourceResolver::StaticClass();
}

UNoesisResourceResolver* UNoesisSettings::GetResourceResolver()
{
	if (ResourceResolverInstance != nullptr)
		return ResourceResolverInstance;

	if (ResourceResolverClass == nullptr)
		ResourceResolverClass = UNoesisResourceResolver::StaticClass();

	ResourceResolverInstance = NewObject<UNoesisResourceResolver>(this, ResourceResolverClass.Get());
	check(ResourceResolverInstance);

	return ResourceResolverInstance;
}
