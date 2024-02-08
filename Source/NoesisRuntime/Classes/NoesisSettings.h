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
	Off,
	Error,
	Warning,
	Information,
	Debug
};

UCLASS(Config = Engine, DefaultConfig)
class NOESISRUNTIME_API UNoesisSettings : public UObject
{
	GENERATED_UCLASS_BODY()

	/** Fill with the Name value your were given when purchasing your Noesis license or get a trial from https://www.noesisengine.com/trial */
	UPROPERTY(EditAnywhere, Config, Category = "License")
	FString LicenseName;

	/** Fill with the Key value your were given when purchasing your Noesis license or get a trial from https://www.noesisengine.com/trial */
	UPROPERTY(EditAnywhere, Config, Category = "License")
	FString LicenseKey;

	/** Sets a collection of application-scope resources, such as styles and brushes. Provides a simple way to support a consistent theme across your application */
	UPROPERTY(EditAnywhere, Config, Category = "XAML", meta = (AllowedClasses = "/Script/NoesisRuntime.NoesisXaml"))
	FSoftObjectPath ApplicationResources;

	/** Default value for FontFamily when it is not specified in a control or text element */
	UPROPERTY(EditAnywhere, Config, Category = "XAML", meta = (AllowedClasses = "/Script/Engine.FontFace"))
	TArray<FSoftObjectPath> DefaultFonts;

	/** Loads platform specific font fallbacks to be able to render a wide range of unicode characters like chinese, korean, japanese or emojis */
	UPROPERTY(EditAnywhere, Config, Category = "XAML")
	bool LoadPlatformFonts;

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

	/** Dimensions of texture used to cache glyphs */
	UPROPERTY(EditAnywhere, Config, Category = "Rendering", meta = (ConfigRestartRequired = true))
	ENoesisGlyphCacheDimensions GlyphTextureSize;

	/** Multisampling of offscreen textures */
	UPROPERTY(EditAnywhere, Config, Category = "Rendering", DisplayName="Offscreen Sample Count", meta = (ConfigRestartRequired = true))
	ENoesisOffscreenSampleCount OffscreenTextureSampleCount;

	/** Number of offscreen textures created at startup */
	UPROPERTY(EditAnywhere, Config, Category = "Rendering", meta = (ConfigRestartRequired = true, ClampMin = 0, UIMin = 0))
	int32 OffscreenInitSurfaces;

	/** Maximum number of offscreen textures (0 = unlimited) */
	UPROPERTY(EditAnywhere, Config, Category = "Rendering", meta = (ConfigRestartRequired = true, ClampMin = 0, UIMin = 0))
	int32 OffscreenMaxSurfaces;

	/** Width of offscreen textures (0 = automatic) */
	UPROPERTY(EditAnywhere, Config, Category = "Rendering", meta = (ConfigRestartRequired = true, ClampMin = 0, UIMin = 0))
	int32 OffscreenTextureWidth;

	/** Height of offscreen textures (0 = automatic) */
	UPROPERTY(EditAnywhere, Config, Category = "Rendering", meta = (ConfigRestartRequired = true, ClampMin = 0, UIMin = 0))
	int32 OffscreenTextureHeight;

	/** Sets the logging level for general messages */
	UPROPERTY(EditAnywhere, Config, Category = "Editor Settings")
	ENoesisLoggingSettings GeneralLogLevel;

	/** Sets the logging level for data binding */
	UPROPERTY(EditAnywhere, Config, Category = "Editor Settings")
	ENoesisLoggingSettings BindingLogLevel;

	/** Enables hot-reloading of XAMLs and Textures while in Play mode */
	UPROPERTY(EditAnywhere, Config, Category = "Editor Settings")
	bool ReloadEnabled;

	/** Premultiplies the color channels of UI textures with the value of the alpha channel */
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
