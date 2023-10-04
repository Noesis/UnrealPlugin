////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// Engine includes
#include "Engine/Blueprint.h"

// Generated header include
#include "NoesisBlueprint.generated.h"

UENUM()
enum class ENoesisTessellationQuality : uint8
{
	Low,
	Medium,
	High,
};

UCLASS()
class NOESISRUNTIME_API UNoesisBlueprint : public UBlueprint
{
	GENERATED_UCLASS_BODY()

public:
	// UBlueprint interface
#if WITH_EDITOR
	virtual UClass* GetBlueprintClass() const override;
	virtual bool SupportedByDefaultBlueprintFactory() const override;
#endif // WITH_EDITOR
	// End of UBlueprint interface

	/** Xaml file that defines the user interface. */
	UPROPERTY(EditAnywhere, Category = "Noesis View", meta = (DisplayName = "XAML"))
	class UNoesisXaml* BaseXaml;

	/** Per-Primitive Antialiasing extrudes the contours of the geometry and smooths them. Useful when GPU MSAA is not enabled. */
	UPROPERTY(EditAnywhere, Category = "Noesis View")
	bool EnablePPAA;

	/** Specifies tessellation quality. */
	UPROPERTY(EditAnywhere, Category = "Noesis View")
	ENoesisTessellationQuality TessellationQuality;

	UPROPERTY(EditAnywhere, Category = "Noesis View")
	bool EnableKeyboard;

	UPROPERTY(EditAnywhere, Category = "Noesis View")
	bool EnableMouse;

	UPROPERTY(EditAnywhere, Category = "Noesis View", meta = (EditCondition = "EnableMouse"))
	bool EmulateTouch;

	UPROPERTY(EditAnywhere, Category = "Noesis View")
	bool EnableTouch;

	UPROPERTY(EditAnywhere, Category = "Noesis View")
	bool EnableActions;

	/** Set to a positive value, this property is added to the values returned by the PixelDepth node in a Material. */
	UPROPERTY(EditAnywhere, Category = "Noesis View", meta = (DisplayName = "Material PixelDepth Bias"))
	float PixelDepthBias;
};
