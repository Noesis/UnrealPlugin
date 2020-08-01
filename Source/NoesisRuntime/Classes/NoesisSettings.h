////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// NoesisRuntime includes
#include "NoesisEnums.h"

// Noesis includes
#include "NoesisSDK.h"

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

UCLASS(Config = Engine, DefaultConfig)
class NOESISRUNTIME_API UNoesisSettings : public UObject
{
	GENERATED_UCLASS_BODY()

	/** Fill with the Name value your were given when purchasing your Noesis license */
	UPROPERTY(EditAnywhere, Config, Category = "License", meta = (ConfigRestartRequired = true))
	FString LicenseName;

	/** Fill with the Key value your were given when purchasing your Noesis license */
	UPROPERTY(EditAnywhere, Config, Category = "License", meta = (ConfigRestartRequired = true))
	FString LicenseKey;

	/** Sets a collection of application-scope resources, such as styles and brushes. Provides a simple way to support a consistent theme across your application */
	UPROPERTY(EditAnywhere, Config, Category = "XAML", meta = (AllowedClasses = "NoesisXaml"))
	FSoftObjectPath ApplicationResources;

	/** Default value for FontFamily when it is not specified in a control or text element */
	UPROPERTY(EditAnywhere, Config, Category = "XAML", meta = (AllowedClasses = "FontFace"))
	TArray<FSoftObjectPath> DefaultFonts;

	/** Default value for FontSize when it is not specified in a control or text element */
	UPROPERTY(EditAnywhere, Config, Category = "XAML", meta = (ClampMin = 0, UIMin = 0))
	float DefaultFontSize;

	/** Default value for FontWeight when it is not specified in a control or text element */
	UPROPERTY(EditAnywhere, Config, Category = "XAML")
	ENoesisFontWeight DefaultFontWeight;

	/** Default value for FontStretch when it is not specified in a control or text element */
	UPROPERTY(EditAnywhere, Config, Category = "XAML")
	ENoesisFontStretch DefaultFontStretch;

	/** Default value for FontStyle when it is not specified in a control or text element */
	UPROPERTY(EditAnywhere, Config, Category = "XAML")
	ENoesisFontStyle DefaultFontStyle;

	/** Dimensions of texture used to cache glyphs. */
	UPROPERTY(EditAnywhere, Config, Category = "Rendering", meta = (ConfigRestartRequired = true))
	ENoesisGlyphCacheDimensions GlyphTextureSize;

	/** Multisampling of offscreen textures. */
	UPROPERTY(EditAnywhere, Config, Category = "Rendering", DisplayName="Offscreen Sample Count", meta = (ConfigRestartRequired = true))
	ENoesisOffscreenSampleCount OffscreenTextureSampleCount;

	/** Number of offscreen textures created at startup. */
	UPROPERTY(EditAnywhere, Config, Category = "Rendering", meta = (ConfigRestartRequired = true, ClampMin = 0, UIMin = 0))
	int32 OffscreenInitSurfaces;

	/** Maximum number of offscreen textures (0 = unlimited). */
	UPROPERTY(EditAnywhere, Config, Category = "Rendering", meta = (ConfigRestartRequired = true, ClampMin = 0, UIMin = 0))
	int32 OffscreenMaxSurfaces;

	/** Width of offscreen textures (0 = automatic). */
	UPROPERTY(EditAnywhere, Config, Category = "Rendering", meta = (ConfigRestartRequired = true, ClampMin = 0, UIMin = 0))
	int32 OffscreenTextureWidth;

	/** Height of offscreen textures (0 = automatic). */
	UPROPERTY(EditAnywhere, Config, Category = "Rendering", meta = (ConfigRestartRequired = true, ClampMin = 0, UIMin = 0))
	int32 OffscreenTextureHeight;

	/** Maximum number of offscreen textures (0 = unlimited). */
	UPROPERTY(EditAnywhere, Config, Category = "Editor Settings")
	ENoesisLoggingSettings LogVerbosity;

	/** Restores the color of UI PNG texture texels with an alpha value of zero. */
	UPROPERTY(EditAnywhere, Config, Category = "Editor Settings", DisplayName = "Fix for premultiplied alpha UI textures")
	bool RestoreUITexturePNGPremultipliedAlpha;

	/** Premultiplies the color channels of UI textures with the value of the alpha channel. */
	UPROPERTY(EditAnywhere, Config, Category = "Editor Settings")
	bool PremultiplyAlpha;

	void SetLicense() const;
	void SetApplicationResources() const;
	void SetFontFallbacks() const;
	void SetFontDefaultProperties() const;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};
