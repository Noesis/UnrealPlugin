////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Generated header include
#include "NoesisSettings.generated.h"

UENUM()
enum class ENoesisOffscreenSampleCount : uint8
{
	One = 1 UMETA(DisplayName = "1x"),
	Two = 2 UMETA(DisplayName = "2x"),
	Four = 4 UMETA(DisplayName = "4x")
};

UENUM()
enum class ENoesisGlyphCacheDimensions : uint8
{
	x256 UMETA(DisplayName = "256x256"),
	x512 UMETA(DisplayName = "512x512"),
	x1024 UMETA(DisplayName = "1024x1024"),
	x2048 UMETA(DisplayName = "2048x2048"),
	x4096 UMETA(DisplayName = "4096x4096")
};

UENUM()
enum class ENoesisLoggingSettings : uint8
{
	Quiet,
	Normal,
	Bindings
};

UCLASS()
class NOESISRUNTIME_API UNoesisSettings : public UObject
{
	GENERATED_UCLASS_BODY()

	/** Sets a collection of application-scope resources, such as styles and brushes. Provides a simple way to support a consistent theme across your application */
	UPROPERTY(EditAnywhere, Category = "Noesis Settings")
	class UNoesisXaml* ApplicationResources;

	/** Dimensions of texture used to cache glyphs. */
	UPROPERTY(EditAnywhere, Category = "Text Rendering", meta = (ConfigRestartRequired = true))
	ENoesisGlyphCacheDimensions GlyphTextureSize;

	/** Glyphs with size above this are rendered using triangles. */
	UPROPERTY(EditAnywhere, Category = "Text Rendering", meta = (ConfigRestartRequired = true, ClampMin = 32, ClampMax = 256, UIMin = 32, UIMax = 256))
	int32 GlyphMeshThreshold;

	/** Width of offscreen textures (0 = automatic). */
	UPROPERTY(EditAnywhere, Category = "Offscreen", meta = (ConfigRestartRequired = true, ClampMin = 0, UIMin = 0))
	int32 OffscreenTextureWidth;

	/** Height of offscreen textures (0 = automatic). */
	UPROPERTY(EditAnywhere, Category = "Offscreen", meta = (ConfigRestartRequired = true, ClampMin = 0, UIMin = 0))
	int32 OffscreenTextureHeight;

	/** Multisampling of offscreen textures. */
	UPROPERTY(EditAnywhere, Category = "Offscreen", meta = (ConfigRestartRequired = true))
	ENoesisOffscreenSampleCount OffscreenTextureSampleCount;

	/** Number of offscreen textures created at startup. */
	UPROPERTY(EditAnywhere, Category = "Offscreen", meta = (ConfigRestartRequired = true, ClampMin = 0, UIMin = 0))
	int32 OffscreenInitSurfaces;

	/** Maximum number of offscreen textures (0 = unlimited). */
	UPROPERTY(EditAnywhere, Category = "Offscreen", meta = (ConfigRestartRequired = true, ClampMin = 0, UIMin = 0))
	int32 OffscreenMaxSurfaces;

	/** Maximum number of offscreen textures (0 = unlimited). */
	UPROPERTY(EditAnywhere, Category = "Editor Settings")
	ENoesisLoggingSettings LogVerbosity;
};
